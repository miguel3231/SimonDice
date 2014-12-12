using namespace std;


//******************Clase TIPO Stack********************

template <class Type>
class Queue
{
    public:
            //precondition: nothing
            //postcondition: creates a construct of an empty queue
            Queue();

            //precondition: another queue currently in existance
            //postcondition: a copy construct of another queue
            Queue(const Queue<Type> &other);

            //precondition: a previously created queue
            //postcondition: deletes de stack
            ~Queue();

            //precondition: a previously created queue
            //postcondition: checks if the queue is empty
            bool isEmpty() const;

            //precondition: a Queue has been previously instanciated
            //postcondition: delete all the elements of the Queue
            void startQueue();

            //precondition: a queue exists and its not full (it can't be full)
            //postcondition: adds a value to the queue (on the back)
            void enQueue(const Type &data);

            //precondition: a queue exists and it has values
            //postcondition: returns the value of the front element and removes it
            Type deQueue();

            //precondition: a queue exists and it has values
            //postcondition: returns the value of the front element
            Type Front() const;

            //precondition: a queue exists and has at least one value
            //postcondition: returns the number of nodes in the queue
            int Size();

    private:
            Node<Type> *head; // the front this is what's gonna get removed
            Node<Type> *tail; // the back this is where new items will be added
};

template <class Type>
Queue<Type>::Queue()
{
    head = NULL;
    tail = NULL;
}

template <class Type>
bool Queue<Type>::isEmpty() const
{
    return (head == NULL);
}

template <class Type>
Queue<Type>::~Queue()
{
    startQueue();
}

template <class Type>
void Queue<Type>::startQueue()
{
    Node<Type> *temp;
    if (head == NULL)
        return;
    while(head != tail)
    {
        temp = head;
        head = head->next();
        delete temp;
    }
    temp = head;
    head = NULL;
    tail = NULL;
    delete temp;
}

template <class Type>
void Queue<Type>::enQueue(const Type &data)
{
    Node<Type> *toplace = new Node<Type>;
    if(toplace != NULL)
    {
        if(head == NULL)
        {
            toplace->informacion() = data;
            head = toplace;
            tail = toplace;
        }
        else
        {
            toplace->informacion() = data;
            tail->next() = toplace;
            tail = tail->next();
        }
    }
}

template <class Type>
Type Queue<Type>::deQueue()
{
    Type x;
    x = Front();
    head = head->next();
    return x;
}

template <class Type>
Type Queue<Type>::Front() const
{
    return head->informacion();
}

template <class Type>
int Queue<Type>::Size()
{
    int x = 1;
    Node<Type> *temp;
    temp = head;
    if(temp == NULL)
        return 0;
    while(temp->next() != NULL)
    {
        x++;
        temp = temp->next();
    }
    return x;
}

