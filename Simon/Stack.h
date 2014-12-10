#include "Node.h"
using namespace std;
//******************Clase TIPO Stack********************

template <class Type>
class Stack
{
    public:
            //precondition: none
            //postcondition: creates a stack
            Stack();

            //precondicition: another stack previously created
            //postcondition: creates a copy of the previous stack created
            Stack(Stack<Type> &otherstack);

            //precondition: a previously created stack
            //postcondition: deletes all the elements of the stack
            ~Stack();

            //precondition: a previously created stack and it can contain data
            //postcondition: overloads the = operator and creates makes that stack be the same as the one on the right
            const Stack<Type> operator=(Stack<Type> &otherstack);

            //precondition: the stack has been previously instanciated
            //postcondition: returns true if the stack is empty
            bool isEmpty() const;

            //precondition: a stack has been previously instanciated
            //postcondition: delete all the elements of the stack
            void startStack();

            //precondition: a stack exists and is not full (idk how it could even be full with a linked list but wtv
            //postcondition: adds a new member to the stack
            void push(const Type &data);

            //precondicion: a stack exists and is not empty
            //postcondition: if the stakc is empty, gives you an error message, if its not, it will let you peek at the top of the stack
            Type peek() const;

            //precondition: a stack already exists and its not empty
            //postcondition: the top element is removed and returned
            Type pop();

    private:
            mutable Node<Type> *top; //points to the start of the list or "the top of the stack"
};

template <class Type>
Stack<Type>::Stack()
{
    top = NULL;
}

template <class Type>
bool Stack<Type>::isEmpty() const
{
    return (top == NULL);
}

template <class Type>
Stack<Type>::Stack(Stack<Type> &otherstack)
{
    Stack <Type> other;
    while(!otherstack.isEmpty())
    {
        other.push(otherstack.pop());
    }
    while(!other.isEmpty())
    {
        otherstack.push(other.peek());
        push(other.pop());
    }
}

template <class Type>
Stack<Type>::~Stack()
{
    startStack();
}

template <class Type>
void Stack<Type>::push(const Type &data)
{
    Node<Type> *temp = new Node<Type>;
    if(temp != NULL)
    {
        temp->informacion() = data;
        temp->next() = top;
        top = temp;
    }
}

template <class Type>
Type Stack<Type>::peek() const
{
    return top->informacion();
}

template <class Type>
Type Stack<Type>::pop()
{
    Type x;
    x = peek();
    top = top->next();
    return x;
}

template <class Type>
void Stack<Type>::startStack()
{
    Node <Type> *temp;
    if (top == NULL)
        return;
    while (top != NULL)
    {
        temp = top;
        top = top->next();
        delete temp;
    }
}

template <class Type>
const Stack<Type> Stack<Type>::operator=(Stack<Type> &otherstack)
{
    top = otherstack.tope;
    return *this;

    /*
    Stack <Type> other;
    while(!otherstack.isEmpty())
    {
        other.push(otherstack.pop());
    }
    while(!other.isEmpty())
    {
        otherstack.push(other.peek());
        push(other.pop());
    }
    return *this;
    */
}

