#include "MainForm.h"
#include "ParametersForm.h"

// Обработчик отрисовки панели - рисует "бегущую" линию по периметру квадрата
// Линия движется по часовой стрелке: верх -> право -> низ -> лево -> верх
System::Void PerimeterAnimator::MainForm::panel1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e)
{
	// Если позиция < 0, анимация не запущена - ничего не рисуем
	if (currentPosition < 0)
		return;

	// Определяем сторону квадрата (0-3) и позицию на текущей стороне
	int direction;
	int sidePosition = currentPosition;
	const int minCoord = 0;
	const int maxCoord = squareSize - 1;

	// Вычисляем на какой стороне квадрата находится текущая позиция
	// Сторона 0: верх (0..squareSize-1)
	// Сторона 1: право (squareSize..2*squareSize-1)
	// Сторона 2: низ (2*squareSize..3*squareSize-1)
	// Сторона 3: лево (3*squareSize..4*squareSize-1)
	if (currentPosition < maxCoord)
	{
		direction = 0; // Верхняя сторона
	}
	else if (currentPosition < 2 * maxCoord)
	{
		direction = 1; // Правая сторона
		sidePosition %= maxCoord;
	}
	else if (currentPosition < 3 * maxCoord)
	{
		direction = 2; // Нижняя сторона
		sidePosition %= maxCoord;
	}
	else
	{
		direction = 3; // Левая сторона
		sidePosition %= maxCoord;
	}

	// Рисуем линию, которая может переходить через несколько сторон
	int remainingLength = lineLength;
	bool isFirstSegment = true;

	while (remainingLength > 0)
	{
		// Вычисляем длину отрезка на текущей стороне
		int segmentLength;
		if (remainingLength >= maxCoord)
		{
			segmentLength = maxCoord - 1;
		}
		else
		{
			segmentLength = remainingLength - 1;
		}

		remainingLength = remainingLength - segmentLength - 1;

		// Для первого сегмента учитываем текущую позицию на стороне
		if (isFirstSegment)
		{
			remainingLength += sidePosition;
			isFirstSegment = false;
		}
		else
		{
			sidePosition = minCoord;
		}

		// Рисуем отрезок на текущей стороне и переходим к следующей
		switch (direction)
		{
		case 0: // Верх: движемся слева направо
			e->Graphics->DrawLine(gcnew Pen(lineColor), sidePosition, minCoord, segmentLength, minCoord);
			direction++;
			break;
		case 1: // Право: движемся сверху вниз
			e->Graphics->DrawLine(gcnew Pen(lineColor), maxCoord, sidePosition, maxCoord, segmentLength);
			direction++;
			break;
		case 2: // Низ: движемся справа налево
			e->Graphics->DrawLine(gcnew Pen(lineColor), maxCoord - sidePosition, maxCoord, maxCoord - segmentLength, maxCoord);
			direction++;
			break;
		case 3: // Лево: движемся снизу вверх
		default:
			e->Graphics->DrawLine(gcnew Pen(lineColor), minCoord, maxCoord - sidePosition, minCoord, maxCoord - segmentLength);
			direction = 0;
			break;
		}
	}
}

// Обработчик открытия формы настроек
System::Void PerimeterAnimator::MainForm::���������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	ParametersForm parametersForm(panel1->Width, panel1->Height);
	if (parametersForm.ShowDialog() == System::Windows::Forms::DialogResult::OK)
	{
		// Получаем параметры из формы настроек
		lineLength = parametersForm.GetLineLength();
		squareSize = parametersForm.GetSquareSize();
		lineColor = parametersForm.GetLineColor();
		intervalMs = parametersForm.GetIntervalMs();
		// Вычисляем периметр квадрата (без учета углов, чтобы не дублировать)
		maxPosition = squareSize * 4 - 4;
		// Включаем пункт меню "Старт"
		������ToolStripMenuItem->Enabled = true;
	}
}

// Обработчик запуска анимации
System::Void PerimeterAnimator::MainForm::������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	timer1->Interval = intervalMs;
	currentPosition = 0;
	StartStop(true);
}

// Обработчик "О программе"
System::Void PerimeterAnimator::MainForm::����������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	String^ info = gcnew String(
		L"Приложение: " + this->Text + L"\n" +
		L"Версия: " + Application::ProductVersion + L"\n" +
		L"Год: 2020\n" +
		L"Разработчик: Студент группы ИВБО-13-01"
	);
	MessageBox::Show(this, info, L"О программе", MessageBoxButtons::OK, MessageBoxIcon::Information);
	delete info;
}

// Обработчик справки
System::Void PerimeterAnimator::MainForm::������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	String^ info = gcnew String(
		L"Для запуска анимации необходимо задать параметры через меню \"Настройки\".\n" +
		L"Для управления анимацией используйте пункты меню \"Старт\" и \"Стоп\"."
	);
	MessageBox::Show(this, info, L"Справка", MessageBoxButtons::OK, MessageBoxIcon::Information);
	delete info;
}

// Обработчик остановки анимации
System::Void PerimeterAnimator::MainForm::���������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	currentPosition = -1;
	StartStop(false);
}

// Таймер анимации - обновляет позицию и перерисовывает панель
System::Void PerimeterAnimator::MainForm::timer1_Tick(System::Object^ sender, System::EventArgs^ e)
{
	currentPosition++;
	if (currentPosition >= maxPosition)
	{
		currentPosition = 0;
	}
	panel1->Invalidate();
}

// Метод управления состоянием анимации
// start = true - запуск, false - остановка
void RunningLine::MainForm::StartStop(bool start)
{
	panel1->Invalidate();
	timer1->Enabled = start;
	// Переключаем видимость пунктов меню
	������ToolStripMenuItem->Visible = !start;
	���������ToolStripMenuItem->Visible = start;
	���������ToolStripMenuItem->Enabled = !start;
}
