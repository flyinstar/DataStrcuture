#include "LinkStack.hpp"

template <typename T>
bool LinkStack<T>::IsEmpty() const {
    return top == nullptr;
}

template <typename T>
void LinkStack<T>::Push(T data) {
    top = new StackNode{data,top};
}

template <typename T>
void LinkStack<T>::Pop(T& result) {
    if (top == nullptr) {
        std::cout << "Stack is empty" << std::endl;
        return;
    }
    result = top->data;
    StackNode* temp = top;
    top = top->next;
    delete temp;
}

template <typename T>
bool LinkStack<T>::GetTop(T& result) const {
    if (top == nullptr) {
        std::cout << "Stack is empty" << std::endl;
        return false;
    }
    result = top->data;
    return true;
}

template <typename T>
void LinkStack<T>::Clear() {
    StackNode* current = top;
    while (current) {
        StackNode* temp = current;
        current = current->next;
        delete temp;
    }
    top = nullptr;
}

template <typename T>
void LinkStack<T>::Print() const {
    std::cout << "top";
    if (top == nullptr) {
        std::cout << "->empty";
    }
    for (StackNode* prev = top; prev; prev = prev->next) {
        std::cout << "->" << prev->data;
    }
    std::cout << std::endl;
}
