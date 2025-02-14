#include "List.hpp"

template <typename datatype>
List<datatype>::List(const List<datatype>& other)
    : size(other.size), length(other.length), data(new datatype[size])
{
    for (int i = 0; i < length; i++) {
        data[i] = other.data[i];
    }
}

template <typename datatype>
List<datatype>& List<datatype>::operator=(const List<datatype>& other) {
    if (this == &other) {
        return *this;
    }
    delete[] data;
    size = other.size;
    length = other.length;
    data = new datatype[size];
    for (int i = 0; i < length; i++) {
        data[i] = other.data[i];
    }
    return *this;
}

template <typename datatype>
void List<datatype>::Insert(int position, const datatype& value) {
    if (position < 1 || position > length + 1) {
        std::cout << "Invalid position" << std::endl;
        return;
    }
    if (size == length) {
        std::cout << "List is full" << std::endl;
        return;
    }
    for(int i = length; i > position - 1; i--) {
        data[i] = data[i - 1];
    }
    data[position - 1] = value;
    length++;
}

template <typename datatype>
void List<datatype>::Delete(int position) {
    if (position < 1 || position > length) {
        std::cout << "Invalid position" << std::endl;
        return;
    }
    for (int i = position; i < length; i++) {
        data[i - 1] = data[i];
    }
    length--;
}

template <typename datatype>
bool List<datatype>::Search(const datatype& value) const {
    for (int i = 0; i < length; i++) {
        if (data[i] == value) {
            std::cout << "Value found at position " << i + 1 << std::endl;
            return true;
        }
    }
    std::cout << "Value not found" << std::endl;
    return false;
}

template <typename datatype>
bool List<datatype>::Get(int position, datatype& result) const {
    if (position < 1 || position > length) {
        std::cout << "Invalid position" << std::endl;
        return false;
    }
    result = data[position - 1];
    return true;
}

template <typename datatype>
void List<datatype>::ReWrite(int position, const datatype& value) {
    if (position < 1 || position > length) {
        std::cout << "Invalid position" << std::endl;
        return;
    }
    data[position - 1] = value;
}

template <typename datatype>
void List<datatype>::Print() const {
    std::cout << "List: ";
    for (int i = 0; i < length; i++) {
        std::cout << data[i] << " ";
    }
    std::cout << std::endl;
}

template <typename datatype>
void List<datatype>::Clear() {
    length = 0;
}