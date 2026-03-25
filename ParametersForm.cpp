#include "ParametersForm.h"

// Обработчик нажатия кнопки "Применить" - закрывает форму с результатом OK
System::Void PerimeterAnimator::ParametersForm::button1_Click(System::Object^ sender, System::EventArgs^ e)
{
	DialogResult = System::Windows::Forms::DialogResult::OK;
}

// Обработчик изменения времени обновления (numericUpDown3)
System::Void PerimeterAnimator::ParametersForm::numericUpDown3_ValueChanged(System::Object^ sender, System::EventArgs^ e)
{
	intervalMs = Convert::ToInt32(numericUpDown3->Value);
}

// Обработчик клика по PictureBox для выбора цвета
// Открывает ColorDialog и устанавливает выбранный цвет
System::Void PerimeterAnimator::ParametersForm::pictureBox1_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (colorDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
	{
		// Белый цвет не виден на белом фоне, заменяем на черный
		if (colorDialog1->Color == Color::White)
		{
			lineColor = Color::Black;
		}
		else
		{
			lineColor = colorDialog1->Color;
		}
		pictureBox1->BackColor = lineColor;
	}
}

// Обработчик изменения длины линии (numericUpDown1)
System::Void PerimeterAnimator::ParametersForm::numericUpDown1_ValueChanged(System::Object^ sender, System::EventArgs^ e)
{
	lineLength = Convert::ToInt32(numericUpDown1->Value);
}

// Обработчик изменения размера квадрата (numericUpDown2)
// Также обновляет максимальную длину линии в зависимости от размера квадрата
System::Void PerimeterAnimator::ParametersForm::numericUpDown2_ValueChanged(System::Object^ sender, System::EventArgs^ e)
{
	squareSize = Convert::ToInt32(numericUpDown2->Value);
	// Максимальная длина линии = периметр квадрата - 1 (чтобы линия не замкнулась полностью)
	numericUpDown1->Maximum = (int)numericUpDown2->Value * 4 - 4 - 1;
}
