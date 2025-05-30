#ifndef STACK
#define STACK

#include "node.hpp"

template<class T>
class Queue {
    private:
        Node<T>* base;
        Node<T>* top;
        int size;
    public:
        Queue();
        ~Queue();
        void push(T data);
        T pop();
        T peek();
        bool exists(T data);
        int getSize();
        bool isEmpty();
};

template<class T>
Queue<T>::Queue()
{
    this->base = nullptr;
    this->top = nullptr;
    this->size = 0;
}

template<class T>
Queue<T>::~Queue()
{
    Node<T>* current = this->top;
    if(this->size == 0)
    {
        return;
    }
    while (current != nullptr)
    {
        Node<T>* next = current->getPrev();
        delete current;
        current = next;
    }
}

template<class T>
void Queue<T>::push(T data)
{
    Node<T>* node = new Node(data);
    if (this->top == nullptr)
    {
        node->setPrev(nullptr);
        this->base = node;
    } else {
        node->setPrev(this->top);
        this->top->setNext(node);
    }
    this->top = node;
    size++;
}

template<class T>
T Queue<T>::pop()
{
    Node<T>* node = this->base;
    this->base = node->getNext();
    T data = node->getData();
    delete node;
    size--;
    return data;
}

template<class T>
bool Queue<T>::exists(T data)
{
    Node<T>* node = this->base;
    while(node->getNext() != nullptr)
    {
        if(node->getData() == data)
        {
            return true;
        }
        node = node->getNext();
    }
    return false;
}

template<class T>
int Queue<T>::getSize()
{
    return size;
}

template<class T>
T Queue<T>::peek()
{
    return this->top->getData();
}

template<class T>
bool Queue<T>::isEmpty()
{
    return size <= 0;
}

#endif