template <class T>
class Node
{
private:
        T Informacion;
        Node <T> *Next;
public:
        //constructores
        Node();
        Node(T d);
        T &informacion();
        Node<T> *&next();
};

template <class T>
Node<T>::Node()
{
        Next = NULL;
}

template<class T>
Node<T>::Node(T d)
{
        Informacion = d;
        Next = NULL;
}

template <class T>
T &Node<T>::informacion()
{
        return Informacion;
}

template <class T>
Node<T> *&Node<T>::next()
{
        return Next;
}
