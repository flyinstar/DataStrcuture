#include "LinkStack.hpp"

LinkStack::LinkStack() : top(nullptr) {}

bool LinkStack::IsEmpty() {
    return top == nullptr;
}

void LinkStack::Push(datatype data) {
    StackNode* newNode = new StackNode{data,top};
    top = newNode;
}

void LinkStack::Pop(datatype& result) {
    if (top == nullptr) {
        std::cout << "Stack is empty" << std::endl;
        return;
    }
    result = top->data;
    StackNode* temp = top;
    top = top->next;
    delete temp;
}

datatype LinkStack::Pop() {
    if (top == nullptr) {
        std::cout << "Stack is empty(return with value -1)" << std::endl;
        return -1;
    }
    datatype result = top->data;
    StackNode* temp = top;
    top = top->next;
    delete temp;
    return result;
}

void LinkStack::ClearLinkStack() {
    StackNode* current = top;
    while (current) {
        StackNode* temp = current;
        current = current->next;
        delete temp;
    }
    top = nullptr;
}

void LinkStack::PrintLinkStack() {
    std::cout << "top";
    if (top == nullptr) {
        std::cout << "->empty";
    }
    for (StackNode* prev = top; prev; prev = prev->next) {
        std::cout << "->" << prev->data;
    }
    std::cout << std::endl;
}

LinkStack::~LinkStack() {
    ClearLinkStack();
}