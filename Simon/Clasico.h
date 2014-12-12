#pragma once
#include <iostream>
#include "Stack.h"
#include "Queue.h"
#include <random>
#include <chrono>
//#include <thread>


namespace Simon {

	using namespace System;
	using namespace System::ComponentModel;
	//using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;


	/// <summary>
	/// Summary for Clasico
	/// </summary>
	public ref class Clasico : public System::Windows::Forms::Form
	{
	public:
		Clasico(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}
		void juego1(int n)
		{
			int score;
			Queue<int> storeRandom; //Stack donde se guardaran los numeros
			score = mostrar(storeRandom,n); 
			storeRandom.startQueue();
		}//ya esta
		int mostrar(Queue<int> &storeRandom, int n)
		{	
			int score = 0;
			bool win = true;
			std::random_device rd; //falta comprobar que el random number funcione bien 
			std::mt19937 gen(rd());
			std::uniform_int_distribution<> dis(1, n); //genera un numero random de entre 1 y n 
			Queue<int> temp;
			while(win)
			{
				storeRandom.enQueue(dis(gen)); //guarda los numeros random dentro de el Stack NO ESTOY DEL TODO SEGURO QUE SI SE PUEDA HACER ESTO LOL
				while(!storeRandom.isEmpty())
				{
    				
					switch(storeRandom.Front()){
					case 1:
						 this->button1->BackColor = System::Drawing::Color::Black;
						 std::chrono::milliseconds dura( 2000 );
						// std::this_thread::sleep_for( dura );
						  this->button1->BackColor = System::Drawing::Color::Red;

						break;
					
					}//aqui iria el metodo que se relacionaria con el gui en vez de imprimir se mandaria a prender un boton
    				temp.enQueue(storeRandom.deQueue());
				}
				while(!temp.isEmpty())
				{
					storeRandom.enQueue(temp.deQueue());
				}
       			cout << "tu turno pon los numeros que son en el orden correcto" << endl;
    			if (comprobar(storeRandom)) // mandar a pedir los numeros o en el caso ya con gui que la persona haga click a las cosas
	   				score++;
    			else
    			{
    				cout << "perdiste" << endl;
    				win = false;
    			}
			}
			return score;
		} //ya esta
		void blinkRed()
		{
			this->Rojo1->Start();
		}
		
		bool comprobar(Queue<int> &storeRandom) // ya esta
		{
			Queue<int> temp;
			int x;
			while (!storeRandom.isEmpty())
			{
				cin >> x; // aqui iria la relacion del click con un numero, este metodo regresaria un numero que se guardaria en equis algo asi x = metodocongui(); 
				if (x != storeRandom.Front())
					return false; //esto haria que en cuanto se equivoke la persona perderia 
				temp.enQueue(storeRandom.deQueue());
			}
			while (!temp.isEmpty())
			{
				storeRandom.enQueue(temp.deQueue());
			}
			return true;
		}
		
	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Clasico()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  label1;
	protected:
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::Button^  button4;
	private: System::Windows::Forms::Timer^  Rojo1;
	private: System::Windows::Forms::Timer^  Rojo2;
	private: System::Windows::Forms::Timer^  Verde1;
	private: System::Windows::Forms::Timer^  Verde2;
	private: System::Windows::Forms::Timer^  Amarillo1;
	private: System::Windows::Forms::Timer^  Amarillo2;
	private: System::Windows::Forms::Timer^  Azul1;
	private: System::Windows::Forms::Timer^  Azul2;

	private: System::ComponentModel::IContainer^  components;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->Rojo1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->Rojo2 = (gcnew System::Windows::Forms::Timer(this->components));
			this->Verde1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->Verde2 = (gcnew System::Windows::Forms::Timer(this->components));
			this->Amarillo1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->Amarillo2 = (gcnew System::Windows::Forms::Timer(this->components));
			this->Azul1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->Azul2 = (gcnew System::Windows::Forms::Timer(this->components));
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Tahoma", 15.75F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(135, 27);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(188, 25);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Simon Dice Clásico";
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::Red;
			this->button1->Location = System::Drawing::Point(163, 109);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(63, 56);
			this->button1->TabIndex = 1;
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &Clasico::button1_Click);
			// 
			// button2
			// 
			this->button2->BackColor = System::Drawing::Color::Lime;
			this->button2->Location = System::Drawing::Point(232, 109);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(63, 56);
			this->button2->TabIndex = 1;
			this->button2->UseVisualStyleBackColor = false;
			// 
			// button3
			// 
			this->button3->BackColor = System::Drawing::Color::Yellow;
			this->button3->Location = System::Drawing::Point(163, 171);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(63, 56);
			this->button3->TabIndex = 1;
			this->button3->UseVisualStyleBackColor = false;
			// 
			// button4
			// 
			this->button4->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->button4->Location = System::Drawing::Point(232, 171);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(63, 56);
			this->button4->TabIndex = 1;
			this->button4->UseVisualStyleBackColor = false;
			// 
			// Rojo1
			// 
			this->Rojo1->Interval = 1000;
			this->Rojo1->Tick += gcnew System::EventHandler(this, &Clasico::timer1_Tick);
			// 
			// Rojo2
			// 
			this->Rojo2->Tick += gcnew System::EventHandler(this, &Clasico::Rojo2_Tick);
			// 
			// Clasico
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(477, 292);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label1);
			this->Name = L"Clasico";
			this->Text = L"Clasico";
			this->Load += gcnew System::EventHandler(this, &Clasico::Clasico_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}

	#pragma endregion
		private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
					 button4->Location = System::Drawing::Point(202, 151);
		}
		private: System::Void Clasico_Load(System::Object^  sender, System::EventArgs^  e) {
					 blinkRed();
					 
					 
					
		}
		
		
	private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
				 this->button1->BackColor = System::Drawing::Color::MistyRose;
				 this->Rojo2->Start();
	}
private: System::Void Rojo2_Tick(System::Object^  sender, System::EventArgs^  e) {
			 this->button1->BackColor = System::Drawing::Color::Red;
			 this->Rojo1->Stop();
			 this->Rojo2->Stop();
}
};


}
