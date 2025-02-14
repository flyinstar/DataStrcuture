#pragma once
#include <iostream>

template<typename datatype>
class List 
{
private:
    datatype* data;
    int size;
    int length;
public:
    List(int size) : size(size), length(0), data(new datatype[size]) {}
    List(const List& other);
    List& operator=(const List& other);
    ~List() { delete[] data; }

    bool isEmpty() const { return length == 0; }
    bool isFull() const { return length == size; }
    int Length() const { return length; }

    void Insert(int position, const datatype& value);
    void Delete(int position);
    bool Search(const datatype& value) const;
    bool Get(int position, datatype& result) const;
    void ReWrite(int position, const datatype& value);
    void Print() const;
    void Clear();
};