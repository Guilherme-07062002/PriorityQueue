#include <iostream>
#include "pqueue.hpp"

int main()
{
    PriorityQueue priorityQueue = PriorityQueue();

    // priorityQueue.enqueue(1, "Data 1");
    priorityQueue.enqueue(1, "Data 2");
    // priorityQueue.dequeue();
    // std::cout << "The queue is " << (priorityQueue.empty() == 1 ? "empty" : "not empty")
    //           << std::endl;

    priorityQueue.print();

    return 0;
}