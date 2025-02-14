#include "LinkList.hpp"

template <typename datatype>
LinkList<datatype>::LinkList(const LinkList& other) : head(nullptr), tail(nullptr), length(0) {
    Node* current = other.head;
    while (current) {
        InsertAtTail(current->data);
        current = current->next;
    }
}

template <typename datatype>
LinkList<datatype>& LinkList<datatype>::operator=(const LinkList<datatype>& other) {
    if (this == &other) {
        return *this;
    }
    Clear();
    Node* current = other.head;
    while (current) {
        InsertAtTail(current->data);
        current = current->next;
    }
    return *this;
}

template <typename datatype>
void LinkList<datatype>::Insert(int position, datatype value) {
    if (position < 1 || position > length + 1) {
        std::cout << "illegal position" << std::endl;
        return;
    }
    Node* newNode = new Node{value,nullptr};
    if (position == 1) {
        newNode->next = head;
        head = newNode;
        if (!tail) tail = newNode;
    } else {
        Node* prev = head;
        for (int i = 1; i < position - 1; i++) {
            prev = prev->next;
        }
        newNode->next = prev->next;
        prev->next = newNode;
        if (newNode->next == nullptr) {
            tail = newNode;
        }
    }
    length++;
}

template <typename datatype>
void LinkList<datatype>::InsertAtHead(datatype value) {
    Node* newNode = new Node{value, head};
    if (head == nullptr) {
        tail = newNode;
    }
    head = newNode;
    length++;
}

template <typename datatype>
void LinkList<datatype>::InsertAtTail(datatype value) {
    Node* newNode = new Node{value, nullptr};
    if(head == nullptr) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
    length++;
}

template <typename datatype>
void LinkList<datatype>::Delete(int position) {
    if (position < 1 || position > length) {
        std::cout << "illegal argument" << std::endl;
        return;
    }
    if (position == 1) {
        Node* toDelete = head;
        head = head->next;
        delete toDelete;
    } else {
        Node* prev = head;
        for (int i = 1; i < position - 1 && prev->next; i++) {
            prev = prev->next;
        }
        Node* toDelete = prev->next;
        prev->next = toDelete->next;
        if (toDelete == tail) {
            tail = prev;
        }
        delete toDelete;
    }
    length--;
}

template <typename datatype>
void LinkList<datatype>::Clear() {
    while (head) {
        Node* toDelete = head;
        head = head->next;
        delete toDelete;
    }
    tail = nullptr;
    length = 0;
}

template <typename datatype>
void LinkList<datatype>::ReWrite(int position, datatype value) {
    if (head == nullptr) {
        std::cout << "List is empty" << std::endl;
        return;
    }
    if (position < 1 || position > length) {
        std::cout << "illegal argument" << std::endl;
        return;
    }
    Node* prev = head;
    for (int i = 1; i < position; i++) {
        prev = prev->next;
    }
    prev->data = value;
}

template <typename datatype>
void LinkList<datatype>::Search(datatype value) const{
    bool find = false;
    int i = 0;
    Node* prev = head;
    while (prev) {
        i++;
        if(prev->data == value) {
            std::cout << "Find at position " << i << ": " << prev->data << std::endl;
            if(!find) {
                find = true;
            }
        }
        prev = prev->next;
    }
    if (!find) {
        std::cout << "Data not find" << std::endl;
    }
}

template <typename datatype>
bool LinkList<datatype>::GetData(int position, datatype& result) const {
    if (head == nullptr) {
        std::cout << "List is empty" << std::endl;
        return false;
    }

    if (position < 1 || position > length) {
        std::cout << "illegal position" << std::endl;
        return false;
    }
    
    Node* prev = head;
    for (int i = 1; i < position; i++) {
        prev = prev->next;
    }
    result = prev->data;
    return true;
}

template <typename datatype>
void LinkList<datatype>::Print() const {
    if (head == nullptr) {
        std::cout << "List is empty" << std::endl;
        return;
    }
    Node* current = head;
    while (current != nullptr) {
        std::cout << current->data;
        if (current->next != nullptr) {
            std::cout << "->";
        }
        current = current->next;
    }
    std::cout << std::endl;
}
