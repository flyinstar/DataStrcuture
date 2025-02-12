#pragma once
#include <iostream>
using datatype = int;

struct StackNode
{
    datatype data;
    StackNode* next;
};

class LinkStack
{
private:
    StackNode* top;
public:
    LinkStack();
    bool IsEmpty();
    void Push(datatype data);
    void Pop(datatype& result);
    datatype Pop();
    void ClearLinkStack();
    void PrintLinkStack();
    ~LinkStack();
};
