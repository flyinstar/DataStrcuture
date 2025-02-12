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
public:
    LinkList();
    bool IsEmpty();
    int Lenth();
    void Insert(int position, datatype data);
    void InsertAtHead(datatype data);
    void InsertAtTail(datatype data);
    void Delete(int position);
    void ReWrite(int position, datatype data);
    void ClearLinkList();
    void PrintTailNode();
    void Search(datatype data);
    void GetData(int position, datatype& result);
    datatype GetData(int position);
    void PrintLinkList();
    ~LinkList();
};
