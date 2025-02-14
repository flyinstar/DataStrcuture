#include "LinkList.hpp"

LinkList::LinkList(const LinkList& other) : head(nullptr), tail(nullptr), length(0) {
    Node* current = other.head;
    while (current) {
        InsertAtTail(current->data);
        current = current->next;
    }
}

LinkList& LinkList::operator=(const LinkList& other) {
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

bool LinkList::IsEmpty() {
    return head == nullptr;
}

int LinkList::Lenth() {
    return length;
}

void LinkList::Insert(int position, datatype data) {
    if (position < 1 || position > length + 1) {
        std::cout << "illegal position" << std::endl;
        return;
    }
    Node* newNode = new Node{data,nullptr};
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

void LinkList::InsertAtHead(datatype data) {
    Node* newNode = new Node{data, head};
    if (head == nullptr) {
        tail = newNode;
    }
    head = newNode;
    length++;
}

void LinkList::InsertAtTail(datatype data) {
    Node* newNode = new Node{data, nullptr};
    if(head == nullptr) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
    length++;
}

void LinkList::Delete(int position) {
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

void LinkList::Clear() {
    while (head) {
        Node* toDelete = head;
        head = head->next;
        delete toDelete;
    }
    tail = nullptr;
    length = 0;
}

void LinkList::ReWrite(int position, datatype data) {
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
    prev->data = data;
}

void LinkList::Search(datatype data) const{
    bool find = false;
    int i = 0;
    Node* prev = head;
    while (prev) {
        i++;
        if(prev->data == data) {
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

bool LinkList::GetData(int position, datatype& result) const {
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

void LinkList::Print() const {
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
