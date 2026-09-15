#pragma once
#include <iostream>
#include <cstddef>



namespace dsa{

template <typename T>


class MyDynamicStack {
private:
    size_t Size;
    size_t Capacity;
    T* myStack;
public:
    MyDynamicStack() : Size(0), Capacity(0), myStack(nullptr) {}
    MyDynamicStack(size_t capacit) : Size(0), Capacity(capacit) 
    {
        myStack = new T[Capacity];
    }
    ~MyDynamicStack(){
        delete[] myStack;
    }

    void push(const T& value);
    void pop();
    T& top();
    size_t size() const;
    bool empty() const;
};

template <typename T>
inline void MyDynamicStack<T>::push(const T &value)
{
    if(Size != Capacity){
        myStack[Size++] = value;
        return;
    }

    T* temp = myStack;

    Capacity = (Capacity == 0) ? 1 : Capacity * 2;

    myStack = new T[Capacity];

    for (size_t i = 0; i < Size; i++)
    {
        myStack[i] = temp[i];
    }

    delete[] temp;
    myStack[Size++] = value;
    
}

template <typename T>
inline void MyDynamicStack<T>::pop()
{
    if(Size == 0) return;
    Size--;
}

template <typename T>
inline T &MyDynamicStack<T>::top()
{
    if(Size == 0) throw std::out_of_range("top() on empty stack");
    return myStack[Size - 1];
}

template <typename T>
inline size_t MyDynamicStack<T>::size() const
{
    return Size;
}
template <typename T>
inline bool MyDynamicStack<T>::empty() const
{
    return Size == 0;
}



}