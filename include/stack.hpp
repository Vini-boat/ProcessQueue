#ifndef STACK
#define STACK

#include "node.hpp"

template<class T>
class Stack {
    private:
        Node<T>* base;
        Node<T>* top;
        int size;
    public:
        Stack();
        ~Stack();
        void push(T data);
        T pop();
        T peek();
        bool exists(T data);
        int getSize();
};

template<class T>
Stack<T>::Stack()
{
    this->base = nullptr;
    this->top = nullptr;
    this->size = 0;
}

template<class T>
Stack<T>::~Stack()
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
void Stack<T>::push(T data)
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
T Stack<T>::pop()
{
    Node<T>* node = this->top;
    this->top = node->getPrev();
    T data = node->getData();
    delete node;
    size--;
    return data;
}

template<class T>
bool Stack<T>::exists(T data)
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
int Stack<T>::getSize()
{
    return size;
}

template<class T>
T Stack<T>::peek()
{
    return this->top->getData();
}

#endif