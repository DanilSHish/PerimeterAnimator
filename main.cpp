#include "MainForm.h"
using namespace PerimeterAnimator;

[STAThread]
int main(array<System::String^>^ arg) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	MainForm form;
	Application::Run(% form);
}