//INCOMPLETO
#include <iostream>
#include <random>
#include "Stack.h"
#include "Queue.h"
using namespace std;

//funciones
void juego1(int n); //ya esta
void juego2(int n);
void mostrar(Queue<int> &storeRandom, int n); //ya esta
void mostrar2(Queue<int> &storeRandom, int n);
bool comprobar(Queue<int> &storeRandom); // ya esta

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
	int score;
	int comenzar; //esto es nadamas para simular un boton de comenzar
	Queue<int> storeRandom; //Stack donde se guardaran los numeros
    cout << "presione un numero para comensar" << endl;
    cin >> comenzar; //simula el boton de comenzar
    score = mostrar(storeRandom,n); 
    storeRandom.startQueue();
    cout << "tu score es de:" << score << endl;
}

void juego2(int n)
{
	int score;
	int comenzar;
	Stack<int> storeRandom;
	cout << "presione un numero para comenzar" << endl;
	cin >> comenzar;
	score = mostrar2(storeRandom,n);
	storeRandom.startStack();
	cout << "tu score es de: " << score << endl;

}


//este metodo imprime los numeros que estan en orden (con GUI deberia prender los botones)
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
    		cout << storeRandom.Front(); //aqui iria el metodo que se relacionaria con el gui en vez de imprimir se mandaria a prender un boton
    		temp.enQueue(storeRandom.deQueue());
		}
		while(!temp.isEmpty())
		{
			storeRandom.enQueue(temp.deQueue());
		}
       	cout << "tu turno pon los numeros que son en el orden correcto" << endl;
    	if (comprobar(storeRandom) // mandar a pedir los numeros o en el caso ya con gui que la persona haga click a las cosas
	   		score++;
    	else
    	{
    		cout << "perdiste" << endl;
    		win = false;
    	}
	}
	return score;
}

int mostrar2(Stack<int> &storeRandom, int n)
{
	int score = 0;
	bool win = true;
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dis(1, n);
	Stack<int> temp;
	while(win)
	{
		storeRandom.push(dis(gen));
		while(!storeRandom.isEmpty())
		{
			cout << storeRandom.peek();
			temp.push(storeRandom.pop());
		}
		cout << "tu turno pon los numeros al revez" << endl;
		if(comprobar2(temp))
			score++;
		else
		{
			cout << "perdiste" << endl;
			win = false;
		}
		while(!temp.isEmpty())
		{
			storeRandom.push(temp.pop());
		}
	}
	return score;
}

//aqui es donde se reciviria el input de parte del GUI y se comprobaria si esta bien o mal
bool comprobar(Queue<int> &storeRandom)
{
	Queue<int> temp;
	int x;
	while(!storeRandom.isEmpty())
	{
		cin >> x; // aqui iria la relacion del click con un numero, este metodo regresaria un numero que se guardaria en equis algo asi x = metodocongui(); 
		if(x != storeRandom.Front())
			return false; //esto haria que en cuanto se equivoke la persona perderia 
		temp.enQueue(storeRandom.deQueue());
	}
	while(!temp.isEmpty())
	{
		storeRandom.enQueue(temp.deQueue());
	}
	return true;
}

bool comprobar2(Stack<int> &storeRandom)
{
	Stack<int> temp;
	int x;
	while(!storeRandom.isEmpty)
	{
		cin >> x; 
		if(x !- storeRandom.peek())
			return false;
		temp.push(storeRandom.pop());
	}
	while(!temp.isEmpty())
	{
		storeRandom.push(temp.pop());
	}
	return true;
}
