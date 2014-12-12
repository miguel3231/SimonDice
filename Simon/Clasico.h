#pragma once
#include <iostream>
#include "Stack.h"
#include "Queue.h"
#include <random>
#include <chrono>
#include <thread>


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
						 std::this_thread::sleep_for( dura );
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
		bool comprobar(Queue<int> &storeRandom); // ya esta
		
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
	private: System::Windows::Forms::Button^  rojo;
	private: System::Windows::Forms::Button^  verde;
	private: System::Windows::Forms::Button^  amarillo;
	private: System::Windows::Forms::Button^  azul;
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
			this->rojo = (gcnew System::Windows::Forms::Button());
			this->verde = (gcnew System::Windows::Forms::Button());
			this->amarillo = (gcnew System::Windows::Forms::Button());
			this->azul = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::Transparent;
			this->label1->Font = (gcnew System::Drawing::Font(L"Copperplate Gothic Bold", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(114, 39);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(235, 24);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Simon Dice Cl�sico";
			// 
			// rojo
			// 
			this->rojo->BackColor = System::Drawing::Color::Red;
			this->rojo->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			this->rojo->Location = System::Drawing::Point(163, 109);
			this->rojo->Name = L"rojo";
			this->rojo->Size = System::Drawing::Size(63, 56);
			this->rojo->TabIndex = 1;
			this->rojo->UseVisualStyleBackColor = false;
			this->rojo->Click += gcnew System::EventHandler(this, &Clasico::button1_Click);
			// 
			// verde
			// 
			this->verde->BackColor = System::Drawing::Color::Lime;
			this->verde->Location = System::Drawing::Point(232, 109);
			this->verde->Name = L"verde";
			this->verde->Size = System::Drawing::Size(63, 56);
			this->verde->TabIndex = 1;
			this->verde->UseVisualStyleBackColor = false;
			// 
			// amarillo
			// 
			this->amarillo->BackColor = System::Drawing::Color::Yellow;
			this->amarillo->Location = System::Drawing::Point(163, 171);
			this->amarillo->Name = L"amarillo";
			this->amarillo->Size = System::Drawing::Size(63, 56);
			this->amarillo->TabIndex = 1;
			this->amarillo->UseVisualStyleBackColor = false;
			// 
			// azul
			// 
			this->azul->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->azul->Cursor = System::Windows::Forms::Cursors::Default;
			this->azul->Location = System::Drawing::Point(232, 171);
			this->azul->Name = L"azul";
			this->azul->Size = System::Drawing::Size(63, 56);
			this->azul->TabIndex = 1;
			this->azul->UseVisualStyleBackColor = false;
			// 
			// Clasico
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::WhiteSmoke;
			this->ClientSize = System::Drawing::Size(477, 292);
			this->Controls->Add(this->verde);
			this->Controls->Add(this->azul);
			this->Controls->Add(this->amarillo);
			this->Controls->Add(this->rojo);
			this->Controls->Add(this->label1);
			this->Name = L"Clasico";
			this->Text = L"Clasico - B�sico";
			this->Load += gcnew System::EventHandler(this, &Clasico::Clasico_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
<<<<<<< HEAD
#pragma endregion
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
				 rojo->Location = System::Drawing::Point(202, 151);
	}
private: System::Void Clasico_Load(System::Object^  sender, System::EventArgs^  e) {
}
};
=======
	#pragma endregion
		private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
					 button4->Location = System::Drawing::Point(202, 151);
		}
		private: System::Void Clasico_Load(System::Object^  sender, System::EventArgs^  e) {
		}
		
		
	};

>>>>>>> origin/master
}
