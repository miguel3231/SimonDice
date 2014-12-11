#pragma once
#include "Clasico.h"
#include "Clasico2.h"
#include "Bounce.h"
#include "Bounce2.h"
#include "Surprise.h"
#include "Surprise2.h"
#include "Rewind.h"
#include "Rewind2.h"

namespace Simon {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Tamano
	/// </summary>
	public ref class Tamano : public System::Windows::Forms::Form
	{
	public:
		int opcion;
		Tamano(int n)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			opcion = n;
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Tamano()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  button2;
	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(51, 36);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(191, 30);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Tamaño de Simon";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(38, 116);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(60, 52);
			this->button1->TabIndex = 1;
			this->button1->Text = L"2x2";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Tamano::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(131, 95);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(132, 117);
			this->button2->TabIndex = 1;
			this->button2->Text = L"4 x 4";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Tamano::button2_Click);
			// 
			// Tamano
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 262);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label1);
			this->Name = L"Tamano";
			this->Text = L"Tamano";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
				 Clasico^ clasico = gcnew Clasico();
				 Bounce^ bounce = gcnew Bounce();
				 Surprise^ surprise = gcnew Surprise();
				 Rewind^ rewind = gcnew Rewind();
				 switch (opcion)
				 {
				 case 1:
					 clasico->Show();
					 break;
				 case 2:
					 bounce->Show();
					 break;
				 case 3:
					 surprise->Show();
					 break;
				 case 4:
					 rewind->Show();
					 break;

				 }
	}
	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
				 Clasico2^ clasico = gcnew Clasico2();
				 Bounce2^ bounce = gcnew Bounce2();
				 Surprise2^ surprise = gcnew Surprise2();
				 Rewind2^ rewind = gcnew Rewind2();
				 switch (opcion)
				 {
				 case 1:
					 clasico->Show();
					 break;
				 case 2:
					 bounce->Show();
					 break;
				 case 3:
					 surprise->Show();
					 break;
				 case 4:
					 rewind->Show();
					 break;

				 }
	}
};
}
