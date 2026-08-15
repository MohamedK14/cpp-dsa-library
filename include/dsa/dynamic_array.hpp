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

};
