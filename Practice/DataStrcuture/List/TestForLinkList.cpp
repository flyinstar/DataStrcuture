#include "LinkList.hpp"
#include "LinkList.cpp"
#include <ctime>
#include <random>

int main() 
{
    LinkList list;
    std::default_random_engine e;
    std::uniform_int_distribution<int> u(1,100);   
    e.seed(time(0));

    // list.InsertAtHead(37);
    // list.Insert(1,1);
    for (int i = 0; i < 20; i++) {
        list.InsertAtTail(u(e));
        // list.PrintLinkList();
    }
    for (int i = 0; i < 20 + 1; i++) {
        list.Insert(2*i-1, 2*i-1);
    }
    // list.ClearLinkList();
    // std::cout << list.Lenth() << std::endl;
    // list.Search(37);
    list.PrintLinkList();
    std::cout << list.Lenth() << std::endl;
}