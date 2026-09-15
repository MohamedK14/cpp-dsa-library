
#pragma once
#include <iostream>
#include <cstddef>



namespace dsa{

template <typename T>

class MyDynamicQueue {
private:
    size_t Size;
    size_t Capacity;
    T* myQueue;
public:
    MyDynamicQueue() : Size(0), Capacity(0), myQueue(nullptr) {}
    
    MyDynamicQueue(size_t capacit) : Size(0), Capacity(capacit) 
    {
        myQueue = new T[Capacity];
    }

    ~MyDynamicQueue(){
        delete[] myQueue;
    }
    


    void enqueue(const T& value);  // add to back
    void dequeue();                // remove from front
    T& front();
    T& back();
    size_t size() const;
    bool empty() const;
};

template <typename T>
inline void MyDynamicQueue<T>::enqueue(const T &value)
{
    if(Size != Capacity){
        myQueue[Size++] = value;
        return;
    }

    T* temp = myQueue;
    Capacity = (Capacity == 0) ? 1 : Capacity * 2;

    myQueue = new T[Capacity];

    for(size_t i = 0; i < Size; i++){
        myQueue[i] = temp[i];
    }

    delete[] temp;

    myQueue[Size++] = value;
}

template <typename T>
inline void MyDynamicQueue<T>::dequeue()
{
    if(Size == 0) throw std::out_of_range("dequeue() on empty queue");

    for(size_t i = 0; i < Size -1; i++){
        myQueue[i] = myQueue[i+1];
    }
    Size--;
}

template <typename T>
inline T &MyDynamicQueue<T>::front()
{
    if(Size == 0) throw std::out_of_range("front() on empty queue");

    return myQueue[0];
}

template <typename T>
inline T &MyDynamicQueue<T>::back()
{
    if(Size == 0) throw std::out_of_range("back() on empty queue");
    return myQueue[Size -1];
}

template <typename T>
inline size_t MyDynamicQueue<T>::size() const
{
    return Size;
}

template <typename T>
inline bool MyDynamicQueue<T>::empty() const
{
    return Size == 0;
}
}