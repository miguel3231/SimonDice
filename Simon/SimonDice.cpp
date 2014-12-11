//INCOMPLETO
#include <iostream>
#include <random>
#include "Stack.h"
#include "Queue.h"
using namespace std;

void juego1(int n);
void mostrar(Stack &storeRandom, int n)
bool comprobar(Stack &storeRandom, int n)
void juego2();

int main()
{
	int x;
	do
	{
		cout << "1) 2x2" << endl;
		cout << "2) 4x4" << endl;
		cout << "3) simon Reversa 2x2" << endl;
		cout << "4) simon Reversa 4x4" << endl;
		cout << "5) salir" << endl;
		cin >> x;
		switch(x)
		{
			case 1: juego1(4);
					break;
			case 2: juego1(16);
					break;
			case 3:
					juego2(4);
					break;
			case 4: 
					juego2(16);
					break;
			case 5:
					cout << "adios" << endl;
			default:
					cout << "valor erroneo" << endl;
		}

	}while(x != 5);
}


void juego1(int n)
{
	int comenzar; //esto es nadamas para simular un boton de comenzar
	Stack storeRandom; //Stack donde se guardaran los numeros
	std::random_device rd; //falta comprobar que el random number funcione bien 
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, n); //genera un numero random de entre 1 y n 
    for(int i = 0; i < n; i++)
    	storeRandom.push(dis(gen)); //guarda los numeros random dentro de el Stack NO ESTOY DEL TODO SEGURO QUE SI SE PUEDA HACER ESTO LOL
    cout << "presione un numero para comensar" << endl;
    cin >> comenzar; //simula el boton de comenzar
    mostrar(storeRandom,n); 
    storeRandom.startStack();
}

void juego2(int n)
{
	int comenzar;
	Queue storeRandom;
	std::random_device rd; //falta comprobar que el random number funcione bien 
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, n); //genera un numero random de entre 1 y n 
	for(int i = 0; i < n; i++)
    	storeRandom.enQueue(dis(gen)); //guarda los numeros random dentro de el Stack NO ESTOY DEL TODO SEGURO QUE SI SE PUEDA HACER ESTO LOL
    cout << "presione un numero para comenzar" << endl;
    cin >> comenzar;
    mostrar2(storeRandom,n);
    storeRandom.startQueue();
}

//este metodo imprime los numeros que estan en orden pero manda los datos al revez para que la persona le de click al revez
void mostrar2(Queue &storeRandom, int n)
{
	Stack temp;
	Queue temp2; //en realidad todo se puede hacer con dos stacks pero tienen que usarse queues so wtv

	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j <= i; j++)
		{
			cout << storeRandom.Front();
			temp.push(storeRandom.Front());
			temp2.enQueue(storeRandom.deQueue());
		}

		if(comprobar(temp,(i + 1)))
			cout << "muy bien" << endl;
		else
		{
			cout << "perdiste" << endl;
			return;
		}

		temp.startStack();

		while(!storeRandom.isEmpty())
		{
			temp2.enQueue(storeRandom.deQueue());
		}
		while(!temp2.isEmpty())
		{
			storeRandom.enQueue(temp2.deQueue());
		}
	}
}

//este metodo imprime los numeros que estan en orden (con GUI deberia prender los botones)
void mostrar(Stack &storeRandom, int n)
{	
	Stack temp;
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j <= i; j++)
		{
    		cout << storeRandom.peek(); //aqui iria el metodo que se relacionaria con el gui en vez de imprimir se mandaria a prender un boton
    		temp.push(storeRandom.pop());
		}
		while(!temp.isEmpty())
		{
			storeRandom.push(temp.pop());
		}
       	cout << "tu turno pon los numeros que son en el orden correcto" << endl;
    	if (comprobar(storeRandom,(i +1))) // mandar a pedir los numeros o en el caso ya con gui que la persona haga click a las cosas
	   		cout << "muy bien" << endl; 
    	else
    	{
    		cout << "perdiste" << endl;
    		return;
    	}
	}
}


//aqui es donde se reciviria el input de parte del GUI y se comprobaria si esta bien o mal
bool comprobar(Stack &storeRandom, int n)
{
	Stack temp
	int x;
	for(int i = 0; i < n; i++)
	{
		cin >> x; // aqui iria la relacion del click con un numero, este metodo regresaria un numero que se guardaria en equis algo asi x = metodocongui(); 
		if(x != storeRandom.peek())
		{
			while(!temp.isEmpty())
			{
				storeRandom.push(temp.pop());
			}
			return false; //esto haria que en cuanto se equivoke la persona perderia 
		}
		temp.push(storeRandom.pop());
	}
	while(!temp.isEmpty())
	{
		storeRandom.push(temp.pop());
	}
	return true;
}

