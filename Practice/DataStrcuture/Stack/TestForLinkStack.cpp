#include "LinkStack.cpp"
#include <ctime>
#include <random>

int main()
{
    LinkStack<int> stack;
    int temp;
    std::default_random_engine e;
    std::uniform_int_distribution u(1,100);
    e.seed(time(0));

    for (int i = 0; i < 10; i++) {
        stack.Push(u(e));
    }
    stack.Print();
    while (!stack.IsEmpty()) {
        stack.Pop(temp);
        std::cout << temp << ' ';
    }
    std::cout << std::endl;
    for (int i = 0; i < 10; i++) {
        stack.Push(i);
    }
    stack.Print();
    stack.Clear();
    stack.Print();
}