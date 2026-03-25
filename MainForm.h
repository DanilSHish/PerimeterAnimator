#pragma once

namespace PerimeterAnimator {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Collections::Generic;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// ������ ��� MainForm
	/// </summary>
	public ref class MainForm : public System::Windows::Forms::Form
	{
	private:
		int lineLength;		// Длина отображаемой линии
		int squareSize;		// Размер стороны квадрата
		int currentPosition;	// Текущая позиция линии (0..maxPosition)
		int intervalMs;		// Интервал обновления таймера в мс
		Color lineColor;	// Цвет линии
		int maxPosition;	// Максимальная позиция (perimeter = squareSize * 4 - 4)
		void StartStop(bool start);

	public:
		MainForm(void)
		{
			InitializeComponent();
			currentPosition = -1; // -1 означает, что анимация не запущена
		}

	protected:
		/// <summary>
		/// ���������� ��� ������������ �������.
		/// </summary>
		~MainForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::ToolStripMenuItem^ ���������ToolStripMenuItem;
	private: System::Windows::Forms::Timer^ timer1;
	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	protected:
	private: System::Windows::Forms::ToolStripMenuItem^ ������ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ ���������ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ ����������ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ ������ToolStripMenuItem;


	private: System::Windows::Forms::Panel^ panel1;
	private: System::ComponentModel::IContainer^ components;



#pragma region Windows Form Designer generated code
		   /// <summary>
		   /// ��������� ����� ��� ��������� ������������ � �� ��������� 
		   /// ���������� ����� ������ � ������� ��������� ����.
		   /// </summary>
		   void InitializeComponent(void)
		   {
			   this->components = (gcnew System::ComponentModel::Container());
			   this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			   this->������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			   this->���������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			   this->���������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			   this->����������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			   this->������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			   this->panel1 = (gcnew System::Windows::Forms::Panel());
			   this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			   this->menuStrip1->SuspendLayout();
			   this->SuspendLayout();
			   // 
			   // menuStrip1
			   // 
			   this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(5) {
				   this->������ToolStripMenuItem,
					   this->���������ToolStripMenuItem, this->���������ToolStripMenuItem, this->����������ToolStripMenuItem, this->������ToolStripMenuItem
			   });
			   this->menuStrip1->Location = System::Drawing::Point(0, 0);
			   this->menuStrip1->Name = L"menuStrip1";
			   this->menuStrip1->Size = System::Drawing::Size(624, 24);
			   this->menuStrip1->TabIndex = 0;
			   this->menuStrip1->Text = L"menuStrip1";
			   // 
			   // ������ToolStripMenuItem
			   // 
			   this->������ToolStripMenuItem->Enabled = false;
			   this->������ToolStripMenuItem->Name = L"������ToolStripMenuItem";
			   this->������ToolStripMenuItem->Size = System::Drawing::Size(57, 20);
			   this->������ToolStripMenuItem->Text = L"������";
			   this->������ToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::������ToolStripMenuItem_Click);
			   // 
			   // ���������ToolStripMenuItem
			   // 
			   this->���������ToolStripMenuItem->Name = L"���������ToolStripMenuItem";
			   this->���������ToolStripMenuItem->Size = System::Drawing::Size(77, 20);
			   this->���������ToolStripMenuItem->Text = L"���������";
			   this->���������ToolStripMenuItem->Visible = false;
			   this->���������ToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::���������ToolStripMenuItem_Click);
			   // 
			   // ���������ToolStripMenuItem
			   // 
			   this->���������ToolStripMenuItem->Name = L"���������ToolStripMenuItem";
			   this->���������ToolStripMenuItem->Size = System::Drawing::Size(83, 20);
			   this->���������ToolStripMenuItem->Text = L"���������";
			   this->���������ToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::���������ToolStripMenuItem_Click);
			   // 
			   // ����������ToolStripMenuItem
			   // 
			   this->����������ToolStripMenuItem->Name = L"����������ToolStripMenuItem";
			   this->����������ToolStripMenuItem->Size = System::Drawing::Size(94, 20);
			   this->����������ToolStripMenuItem->Text = L"� ���������";
			   this->����������ToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::����������ToolStripMenuItem_Click);
			   // 
			   // ������ToolStripMenuItem
			   // 
			   this->������ToolStripMenuItem->Name = L"������ToolStripMenuItem";
			   this->������ToolStripMenuItem->Size = System::Drawing::Size(68, 20);
			   this->������ToolStripMenuItem->Text = L"������";
			   this->������ToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::������ToolStripMenuItem_Click);
			   // 
			   // panel1
			   // 
			   this->panel1->BackColor = System::Drawing::Color::White;
			   this->panel1->Location = System::Drawing::Point(12, 27);
			   this->panel1->Name = L"panel1";
			   this->panel1->Size = System::Drawing::Size(600, 402);
			   this->panel1->TabIndex = 2;
			   this->panel1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MainForm::panel1_Paint);
			   // 
			   // timer1
			   // 
			   this->timer1->Tick += gcnew System::EventHandler(this, &MainForm::timer1_Tick);
			   // 
			   // MainForm
			   // 
			   this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			   this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			   this->ClientSize = System::Drawing::Size(624, 441);
			   this->Controls->Add(this->panel1);
			   this->Controls->Add(this->menuStrip1);
			   this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			   this->MainMenuStrip = this->menuStrip1;
			   this->MaximizeBox = false;
			   this->Name = L"MainForm";
			   this->Text = L"������������";
			   this->menuStrip1->ResumeLayout(false);
			   this->menuStrip1->PerformLayout();
			   this->ResumeLayout(false);
			   this->PerformLayout();

		   }
#pragma endregion
	private: System::Void panel1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e);
	private: System::Void ���������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void ������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void ����������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void ������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void ���������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e);
	};
}
