#pragma once
#include <iostream>
#include <cstddef>

template <typename T>

class MyDynamicArray {
private:
    size_t Size;
    size_t Capacity;
    T* myArray;
public:
    MyDynamicArray() : Size(0), Capacity(0), myArray(nullptr) {}

    MyDynamicArray(size_t capacit) : Size(0), Capacity(capacit){
        myArray = new T[capacit];
    }

    ~MyDynamicArray() {
        delete[] myArray;
    }

    // Methods
    void push_back(const T& value);
    T& operator[](size_t index);
    void pop_back();
    size_t size() const;
    bool empty() const;


};




template <typename T>
inline void MyDynamicArray<T>::push_back(const T &value)
{
    if(Size != Capacity){
        myArray[Size++] = value;
        return;
    }

    T* temp = myArray;

    Capacity = (Capacity == 0) ? 1 :  Capacity * 2;

    myArray = new T[Capacity];
    // myArray = temp;
    for (size_t i = 0; i < Size; i++)
    {
        myArray[i] = temp[i];
    }
    
    delete [] temp;
    myArray[Size++] = value;
}



template <typename T>
inline T &MyDynamicArray<T>::operator[](size_t index)
{
    if(index >= Size){
        throw std::out_of_range("Index out of bounds!");
    }

    return myArray[index];
}

template <typename T>
inline void MyDynamicArray<T>::pop_back()
{

    if(Size == 0) return;
    Size--;
}

template <typename T>
inline size_t MyDynamicArray<T>::size() const
{
    return Size;
}

template <typename T>
inline bool MyDynamicArray<T>::empty() const
{
    return Size == 0;
}
