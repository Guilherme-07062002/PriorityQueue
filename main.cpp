#include <iostream>
#include "pqueue.hpp"

int main()
{
    PriorityQueue priorityQueue = PriorityQueue();

    priorityQueue.enqueue(1, "Data 1");
    priorityQueue.print();

    return 0;
}