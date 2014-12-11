#pragma once

namespace Simon {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Surprise
	/// </summary>
	public ref class Surprise : public System::Windows::Forms::Form
	{
	public:
		Surprise(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Surprise()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  button2;
	protected:
	private: System::Windows::Forms::Button^  button4;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Label^  label1;

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
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// button2
			// 
			this->button2->BackColor = System::Drawing::Color::Fuchsia;
			this->button2->Location = System::Drawing::Point(244, 114);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(63, 56);
			this->button2->TabIndex = 3;
			this->button2->UseVisualStyleBackColor = false;
			// 
			// button4
			// 
			this->button4->BackColor = System::Drawing::Color::Fuchsia;
			this->button4->Location = System::Drawing::Point(244, 176);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(63, 56);
			this->button4->TabIndex = 4;
			this->button4->UseVisualStyleBackColor = false;
			// 
			// button3
			// 
			this->button3->BackColor = System::Drawing::Color::Fuchsia;
			this->button3->Location = System::Drawing::Point(175, 176);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(63, 56);
			this->button3->TabIndex = 5;
			this->button3->UseVisualStyleBackColor = false;
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::Fuchsia;
			this->button1->Location = System::Drawing::Point(175, 114);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(63, 56);
			this->button1->TabIndex = 6;
			this->button1->UseVisualStyleBackColor = false;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Tahoma", 15.75F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(162, 37);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(159, 25);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Simon Sorpresa";
			// 
			// Surprise
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(484, 292);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label1);
			this->Name = L"Surprise";
			this->Text = L"Surprise";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	};
}
