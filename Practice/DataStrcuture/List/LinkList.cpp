#include "LinkList.hpp"

LinkList::LinkList(): head(nullptr),tail(nullptr) {}

bool LinkList::IsEmpty() {
    return head == nullptr;
}

int LinkList::Lenth() {
    int len = 0;
    Node* prev = head;
    while (prev) {
        len++;
        prev = prev->next;
    }
    return len;
}

void LinkList::Insert(int position, datatype data) {
    if (position < 1 || position > Lenth() + 1) {
        std::cout << "illegal argument" << std::endl;
        return;
    }
    Node* newNode = new Node{data,nullptr};
    if (position == 1) {
        if (head == nullptr) {
            tail = newNode;
        }
        newNode->next = head;
        head = newNode;
        return;
    }
    Node* prev = head;
    for (int i = 1; i < position - 1; i++) {
        prev = prev->next;
    }
    newNode->next = prev->next;
    prev->next = newNode;
}

void LinkList::InsertAtHead(datatype data) {
    Node* newNode = new Node{data, head};
    if (head == nullptr) {
        tail = newNode;
    }
    head = newNode;
}

void LinkList::InsertAtTail(datatype data) {
    Node* newNode = new Node{data, nullptr};
    if(head == nullptr) {
        head = tail = newNode;
        return;
    }
    tail->next = newNode;
    tail = newNode;
}

void LinkList::Delete(int position) {
    if (head == nullptr) {
        std::cout << "List is empty" << std::endl;
        return;
    }
    if (position < 1 || position > Lenth()) {
        std::cout << "illegal argument" << std::endl;
        return;
    }
    if (position == 1) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }
    Node* prev = head;
    for (int i = 1; i < position - 1 && prev->next; i++) {
        prev = prev->next;
    }
    if (prev->next == nullptr) {
        std::cout << "Not find" << std::endl;
        return;
    }
    Node* toDelete = prev->next;
    prev->next = toDelete->next;
    delete toDelete;
}

void LinkList::ClearLinkList() {
    while (head) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    tail = nullptr;
}

void LinkList::PrintTailNode() {
    if (tail) {
        std::cout << "Tail is " << tail->data << std::endl;
    } else {
        std::cout << "Tail is nullptr" << std::endl;
    }
}

void LinkList::Search(datatype data) {
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

void LinkList::ReWrite(int position, datatype data) {
    if (head == nullptr) {
        std::cout << "List is empty" << std::endl;
        return;
    }
    if (position < 1 || position > Lenth() + 1) {
        std::cout << "illegal argument" << std::endl;
        return;
    }
    Node* prev = head;
    for (int i = 1; i < position; i++) {
        prev = prev->next;
    }
    prev->data = data;
}

void LinkList::GetData(int position, datatype& result) {
    result = GetData(position);
}

datatype LinkList::GetData(int position) {
    if (head == nullptr) {
        std::cout << "List is empty" << std::endl;
        return -1;
    }
    if (position < 1 || position > Lenth() + 1) {
        std::cout << "illegal argument" << std::endl;
        return -1;
    }
    Node* prev = head;
    for (int i = 1; i < position; i++) {
        prev = prev->next;
    }
    return prev->data;
}

void LinkList::PrintLinkList() {
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

LinkList::~LinkList() {
    ClearLinkList();
}