#pragma once
#include <iostream>
#include <cstddef>

template <typename T>

class MyDynamicArray {
private:
    size_t size;
    size_t capacity;
    T* myArray;
public:
    MyDynamicArray() : size(0), capacity(0), myArray(nullptr) {}

    MyDynamicArray(size_t capacit) : size(0), capacity(capacit){
        myArray = new T[capacit];
    }

    ~MyDynamicArray() {
        delete[] myArray;
    }

    // Methods
    void push_back(const T& value);
    T& operator[](size_t index);



};




template <typename T>
inline void MyDynamicArray<T>::push_back(const T &value)
{
    if(size != capacity){
        myArray[size++] = value;
        return;
    }

    T* temp = myArray;

    capacity = (capacity == 0) ? 1 :  capacity * 2;

    myArray = new T[capacity];
    // myArray = temp;
    for (size_t i = 0; i < size; i++)
    {
        myArray[i] = temp[i];
    }
    
    delete [] temp;
    myArray[size++] = value;
}



template <typename T>
inline T &MyDynamicArray<T>::operator[](size_t index)
{
    if(index >= size){
        throw std::out_of_range("Index out of bounds!");
    }

    return myArray[index];
}
