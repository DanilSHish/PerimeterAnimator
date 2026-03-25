# Architecture Documentation

[🇷🇺 Русская версия](ARCHITECTURE.ru.md)

This document describes the internal architecture and design decisions of PerimeterAnimator.

## Table of Contents

- [Overview](#overview)
- [Class Structure](#class-structure)
- [Animation Algorithm](#animation-algorithm)
- [Data Flow](#data-flow)
- [Design Patterns](#design-patterns)

## Overview

PerimeterAnimator follows a simple two-form architecture:

- **MainForm** - The primary window containing the animation canvas and playback controls
- **ParametersForm** - A modal dialog for configuring animation parameters

The application uses Windows Forms event-driven architecture with GDI+ for 2D graphics rendering.

## Class Structure

### MainForm

**Responsibilities:**
- Hosts the animation canvas (Panel control)
- Manages animation state (running/stopped)
- Handles rendering via `Paint` events
- Controls timer-based animation updates

**Key Members:**

```cpp
private:
    int lineLength;      // Length of the animated line
    int squareSize;      // Size of the animation perimeter
    int currentPosition; // Current head position along perimeter (0..maxPosition)
    int intervalMs;      // Timer interval in milliseconds
    Color lineColor;     // Line color for rendering
    int maxPosition;     // Maximum position (perimeter length)

    void StartStop(bool start); // Controls animation state
```

**Key Methods:**

| Method | Description |
|--------|-------------|
| `panel1_Paint()` | Renders the line using GDI+ Graphics::DrawLine |
| `timer1_Tick()` | Updates position and triggers repaint |
| `StartStop()` | Toggles animation state, updates UI visibility |

### ParametersForm

**Responsibilities:**
- Collects user input for animation parameters
- Validates input constraints
- Returns parameters to MainForm via getter methods

**Key Members:**

```cpp
private:
    int lineLength;   // Selected line length
    int squareSize;   // Selected square size
    int intervalMs;   // Selected timer interval
    Color lineColor;  // Selected line color
```

**Public Interface:**

```cpp
int GetLineLength()    { return lineLength; }
int GetSquareSize()    { return squareSize; }
int GetIntervalMs()    { return intervalMs; }
Color GetLineColor()   { return lineColor; }
```

## Animation Algorithm

The line moves clockwise along the square perimeter:

```
(0,0) ──────────────────► (size,0)
   │                        │
   │      PERIMETER         │
   │      (clockwise)       │
   ▼                        ▼
(0,size) ◄──────────────── (size,size)
```

### Direction Mapping

| Direction | Side | Coordinate Range |
|-----------|------|------------------|
| 0 | Top | x: 0 → size-1, y: 0 |
| 1 | Right | x: size-1, y: 0 → size-1 |
| 2 | Bottom | x: size-1 → 0, y: size-1 |
| 3 | Left | x: 0, y: size-1 → 0 |

### Position Calculation

```cpp
// Determine which side of the square the position falls on
if (currentPosition < maxCoord) {
    direction = 0; // Top side
} else if (currentPosition < 2 * maxCoord) {
    direction = 1; // Right side
    sidePosition %= maxCoord;
} else if (currentPosition < 3 * maxCoord) {
    direction = 2; // Bottom side
    sidePosition %= maxCoord;
} else {
    direction = 3; // Left side
    sidePosition %= maxCoord;
}
```

### Line Rendering

The line may wrap around multiple sides. The algorithm:

1. Start at `currentPosition`
2. Draw segment on current side up to corner or line end
3. If more length remains, continue to next side
4. Repeat until `lineLength` pixels drawn

## Data Flow

```
User Action              Form                 Logic                 Graphics
────────────────────────────────────────────────────────────────────────────
Click "Settings"  →  MainForm          →  Show ParametersForm
                                                       ↓
Click "Apply"     →  ParametersForm    →  DialogResult = OK
                                             (returns to MainForm)
                                                       ↓
Parameters        →  MainForm          →  Store: lineLength,
applied                                    squareSize, intervalMs,
                                           lineColor, maxPosition
                                                       ↓
Click "Start"     →  MainForm          →  StartStop(true)
                                             timer1->Enabled = true
                                             currentPosition = 0
                                                       ↓
Timer Tick        →  MainForm          →  currentPosition++
every N ms                                 if (>= maxPosition) reset
                                             panel1->Invalidate()
                                                       ↓
Paint Event       →  MainForm/Panel    →  Graphics::DrawLine()
(on Invalidate)                            (renders current frame)
```

## Design Patterns

### 1. Separation of Concerns

- **UI Layer**: Windows Forms handle user interaction
- **Logic Layer**: Form classes manage animation state
- **Rendering Layer**: GDI+ performs actual drawing

### 2. Modal Dialog Pattern

```cpp
// MainForm opens ParametersForm as modal dialog
ParametersForm parametersForm(panel1->Width, panel1->Height);
if (parametersForm.ShowDialog() == System::Windows::Forms::DialogResult::OK) {
    // Extract parameters only on OK
    lineLength = parametersForm.GetLineLength();
    // ... etc
}
```

### 3. State Machine (Implicit)

Animation states: `STOPPED` → `RUNNING` → `STOPPED`

State transitions managed by `StartStop(bool)` method.

### 4. Double Buffering

Windows Forms Panel control uses double buffering by default, preventing flickering during animation.

## Performance Considerations

1. **Invalidate() not Refresh()** - Uses WM_PAINT coalescing for smooth animation
2. **Minimal allocations** - Pen created each frame could be optimized
3. **Fixed-size buffer** - No dynamic memory during animation loop

## Future Improvements

- [ ] Optimize Pen allocation (reuse or use caching)
- [ ] Add anti-aliasing option for smoother lines
- [ ] Support non-square rectangles
- [ ] Add preset animation patterns
- [ ] Export animation as GIF/video
