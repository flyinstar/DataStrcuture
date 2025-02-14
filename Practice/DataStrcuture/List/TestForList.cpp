#include "List.cpp"
#include <ctime>
#include <random>

int main() 
{
    List<int> list(20), list2(40);
    std::default_random_engine e;
    std::uniform_int_distribution<int> u(1,100);
    e.seed(time(0));

    for (int i = 0; i < 20 + 1; i++) {
        list.Insert(i, u(e));
    }
    list.Insert(7, 37);
    list.Clear();
    list.Print();
    for (int i = 1; i < 40 + 1; i++) {
        list2.Insert(i, u(e));
    }
    list2.Print();
    list = list2;
    list.Delete(1);
    list.ReWrite(1, -1);
    list.Search(-1);
    list.Print();
    std::cout << list.Length() << std::endl;
}