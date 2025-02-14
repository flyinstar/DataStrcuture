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
        // std::cout << list.Lenth() << ':';
        list.InsertAtTail(u(e));
        // std::cout << list.Lenth() << ' ';
        // list.Print();
    }
    for (int i = 0; i < 20 + 1; i++) {
        list.Insert(2*i-1, 2*i-1);
        // std::cout << list.Lenth() << ' ';
    }
    // std::cout << std::endl;
    // list.Clear();
    // std::cout << list.Lenth() << std::endl;
    // list.Search(37);
    list.Print();
    std::cout << list.Lenth() << std::endl;
}