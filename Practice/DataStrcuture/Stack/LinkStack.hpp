#pragma once
#include <iostream>

using datatype = int;

template <typename T>
class LinkStack
{
private:
    struct StackNode {
        T data;
        StackNode* next;
    };
    StackNode* top;
public:
    LinkStack() : top(nullptr) {}
    LinkStack(const LinkStack& other) = delete;
    LinkStack& operator=(const LinkStack& other) = delete;
    ~LinkStack() { Clear(); }

    bool IsEmpty() const;

    void Push(T data);
    void Pop(T& result);
    bool GetTop(T& result) const;
    void Clear();
    void Print() const;
};
