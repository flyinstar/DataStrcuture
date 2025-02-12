#pragma once
#include <iostream>

using datatype = int;

struct QueueNode
{
    datatype data;
    QueueNode* next;
};

class LinkQueue
{
private:
    QueueNode* head;
    QueueNode* tail;
public:
    LinkQueue();
    void IsEmpty();
    void EnQueue(datatype data);
    void DeQueue();
    void GetHead(datatype& data);
    datatype GetHead();
    int Lenth();
    void PrintQueue();
    void ClearQueue();
    ~LinkQueue();
};