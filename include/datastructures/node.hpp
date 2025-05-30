#ifndef NODE
#define NODE

template<class T>
class Node {
    public:
        Node(T data);
        // ~Node();
        void setNext(Node<T>* node);
        void setPrev(Node<T>* node);
        Node<T>* getNext();
        Node<T>* getPrev();
        T getData();
    private:
        T data;
        Node<T>* next;
        Node<T>* prev;
};

template<class T>
Node<T>::Node(T data)
{
    this->data = data;
    this->next = nullptr;
    this->prev = nullptr;
}

// template<class T>
// Node<T>::~Node()
// {
//     delete next;
//     delete prev;
// }

template<class T>
void Node<T>::setNext(Node<T>* node)
{
    this->next = node;
};

template<class T>
void Node<T>::setPrev(Node<T>* node)
{
    this->prev = node;
};

template<class T>
Node<T>* Node<T>::getNext()
{
    return this->next;
}

template<class T>
Node<T>* Node<T>::getPrev()
{
    return this->prev;
}

template<class T>
T Node<T>::getData()
{
    return this->data;
}

#endif