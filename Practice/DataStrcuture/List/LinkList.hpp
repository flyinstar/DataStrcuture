#pragma once
#include <iostream>

using datatype = int;

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

    bool IsEmpty();
    int Lenth();

    void Insert(int position, datatype data);
    void InsertAtHead(datatype data);
    void InsertAtTail(datatype data);

    void Append(datatype data) {InsertAtTail(data);}
    void Delete(int position);
    void Clear();
    void Search(datatype data) const;
    bool GetData(int position, datatype& result) const;
    void Print() const;
    void ReWrite(int position, datatype data);
};
