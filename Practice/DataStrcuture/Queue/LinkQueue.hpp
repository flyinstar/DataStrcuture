#pragma once
#include <iostream>

using datatype = int;

template <typename T>
class LinkQueue
{
private:
    struct QueueNode {
        T data;
        QueueNode* next;
    };
    QueueNode* head;
    QueueNode* tail;
    int length;
public:
    LinkQueue() : head(nullptr), tail(nullptr), length(0) {}
    LinkQueue(const LinkQueue& other) = delete;
    LinkQueue& operator=(const LinkQueue& other) = delete;
    ~LinkQueue() { Clear(); }

    bool IsEmpty() const { return length == 0; }
    int Length() const { return length; }

    void EnQueue(T data);
    void DeQueue();
    void GetHead(T& data) const;
    void Print() const;
    void Clear();
};