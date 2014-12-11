#include "MyForm.h"


using namespace System;
using namespace System::Windows::Forms;

[STAThread]
int main(array<String^>^ args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	Simon::MyForm form; // Nombre del proyecto::Nombre de forma
	Application::Run(%form);
	return 0;
}

