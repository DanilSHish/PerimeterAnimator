# PerimeterAnimator

[![CI](https://github.com/username/PerimeterAnimator/actions/workflows/ci.yml/badge.svg)](../../actions)
[![C++](https://img.shields.io/badge/C++-CLI-blue.svg)](https://docs.microsoft.com/en-us/cpp/dotnet/dotnet-programming-with-cpp-cli-visual-cpp)
[![.NET](https://img.shields.io/badge/.NET-Framework%204.0-purple.svg)](https://dotnet.microsoft.com/)
[![License](https://img.shields.io/badge/License-MIT-green.svg)](LICENSE)
[![Platform](https://img.shields.io/badge/Platform-Windows-lightgrey.svg)]()

> A Windows Forms desktop application demonstrating animated line movement along a rectangular perimeter using GDI+ graphics.

[🇷🇺 Русская версия](README.ru.md)

## 📋 Overview

**PerimeterAnimator** is a C++/CLI Windows Forms application that demonstrates smooth animation of a line "running" along the perimeter of a rectangle. The project showcases object-oriented programming principles, separation of UI and logic, and GDI+ graphics rendering.

### Features

- 🎨 **Customizable line color** via ColorDialog
- 📏 **Adjustable line length** - control how long the animated line appears
- 🔲 **Configurable square size** - define the animation perimeter dimensions
- ⏱️ **Variable animation speed** - set update interval in milliseconds
- ▶️ **Playback controls** - Start/Stop functionality
- 🖥️ **Intuitive GUI** - clean Windows Forms interface

## 🚀 Quick Start

### Prerequisites

- Windows 7 or later
- Visual Studio 2019/2022 with C++/CLI support
- .NET Framework 4.0+

### Building

```bash
git clone https://github.com/username/PerimeterAnimator.git
cd PerimeterAnimator
```

Open `PerimeterAnimator.sln` in Visual Studio, select configuration (`Debug` or `Release`) and platform (`x86` or `x64`), then build with `Ctrl+Shift+B`.

### Usage

1. Launch the application
2. Click **"Settings"** to configure:
   - **Square Size** - dimensions of the animation area
   - **Line Length** - length of the animated line
   - **Time (ms)** - animation update interval
   - **Color** - line color
3. Click **"Start"** to begin animation
4. Use **"Stop"** to pause

## 📁 Project Structure

```
PerimeterAnimator/
├── src/
│   ├── main.cpp              # Application entry point
│   ├── MainForm.h/.cpp       # Main window (UI + logic)
│   └── ParametersForm.h/.cpp # Settings dialog
├── res/
│   ├── MainForm.resx         # Main form resources
│   └── ParametersForm.resx   # Settings form resources
├── .github/workflows/ci.yml  # GitHub Actions CI
├── docs/
│   ├── ARCHITECTURE.md       # Architecture documentation
│   └── ARCHITECTURE.ru.md    # Архитектура (рус.)
├── README.md                 # This file
├── README.ru.md              # Документация на русском
├── CONTRIBUTING.md           # Contribution guidelines
└── LICENSE                   # MIT License
```

## 🏗️ Architecture

See [ARCHITECTURE.md](docs/ARCHITECTURE.md) for detailed architecture documentation.

### Class Diagram

```
┌─────────────────┐         ┌─────────────────┐
│   MainForm      │◄───────►│ ParametersForm  │
│  (Controller)   │  params │   (Settings)    │
└────────┬────────┘         └─────────────────┘
         │
         │ GDI+ Rendering
         ▼
┌─────────────────┐
│   Panel/Canvas  │
│  (GDI+ Graphics)│
└─────────────────┘
```

## 🛠️ Technologies

- **C++/CLI** - Managed C++ for .NET integration
- **Windows Forms** - Native Windows UI framework
- **GDI+** - 2D graphics rendering (`System::Drawing`)
- **.NET Framework 4.0** - Runtime platform

## 🤝 Contributing

See [CONTRIBUTING.md](CONTRIBUTING.md) for guidelines.

## 📄 License

MIT License - see [LICENSE](LICENSE).

## 👤 Author

Developed in 2020 as an educational project demonstrating C++/CLI and Windows Forms.

---

<p align="center">
  <i>⭐ Star this repo if you found it useful!</i>
</p>
