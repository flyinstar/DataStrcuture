#pragma once
#include <iostream>

template <typename datatype>
class LinkList
{
private:
    struct Node {
        datatype data;
        Node* next;
    };
    Node* head;
    Node* tail;
    int length;
public:
    LinkList(): head(nullptr), tail(nullptr), length(0) {}
    LinkList(const LinkList& other);
    LinkList& operator=(const LinkList& other);
    ~LinkList() {Clear();}

    bool IsEmpty() const {return head == nullptr;}
    int Lenth() const {return length;}

    void Insert(int position, datatype value);
    void InsertAtHead(datatype value);
    void InsertAtTail(datatype value);

    void Append(datatype value) {InsertAtTail(value);}
    void Delete(int position);
    void Clear();
    void Search(datatype value) const;
    bool GetData(int position, datatype& result) const;
    void Print() const;
    void ReWrite(int position, datatype value);
};
