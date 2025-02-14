#include "LinkQueue.cpp"
#include <ctime>
#include <random>

int main() 
{
    LinkQueue<int> queue;
    std::default_random_engine e;
    std::uniform_int_distribution<int> u(1,100);
    e.seed(time(0));

    for (int i = 0; i < 10; i++) {
        queue.EnQueue(u(e));
    }
    queue.Print();
    queue.DeQueue();
    queue.Print();
    queue.Clear();
    queue.Print();
}