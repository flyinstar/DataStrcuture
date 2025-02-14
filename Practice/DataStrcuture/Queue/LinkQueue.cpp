#include "LinkQueue.hpp"

template <typename T>
void LinkQueue<T>::EnQueue(T data) {
    QueueNode* newNode = new QueueNode{ data, nullptr };
    if (IsEmpty()) {
        head = tail = newNode;
    }
    else {
        tail->next = newNode;
        tail = newNode;
    }
    length++;
}

template <typename T>
void LinkQueue<T>::DeQueue() {
    if (IsEmpty()) {
        std::cout << "Queue is empty!" << std::endl;
        return;
    }
    QueueNode* temp = head;
    head = head->next;
    delete temp;
    length--;
}

template <typename T>
void LinkQueue<T>::GetHead(T& data) const {
    if (IsEmpty()) {
        std::cout << "Queue is empty!" << std::endl;
        return;
    }
    data = head->data;
}

template <typename T>
void LinkQueue<T>::Print() const {
    if (IsEmpty()) {
        std::cout << "Queue is empty!" << std::endl;
        return;
    }
    QueueNode* temp = head;
    while (temp != nullptr) {
        std::cout << temp->data << "<-";
        temp = temp->next;
    }
    std::cout << "tail" << std::endl;
}

template <typename T>
void LinkQueue<T>::Clear() {
    while (!IsEmpty()) {
        DeQueue();
    }
}