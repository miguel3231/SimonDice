#include "Inicio.h"
using namespace System;
using namespace System::Windows::Forms;

[STAThread]
void main(array<String^>^ args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

Simon::Inicio form; // Nombre del proyecto::Nombre de forma
	Application::Run(%form);
}


