#include <iostream>
#ifndef QUEUE_HPP
#define QUEUE_HPP

const int capacity = 1000;

class PriorityQueue
{
public:
    PriorityQueue();
    ~PriorityQueue();

    /*
     *Add element in Priority Queue
     *@param Node Element to be added
     */
    void enqueue(Node);
    void dequeue();
    bool empty();
    void print();

private:
    Node *front;
    int index_start;
    bool is_empty;
    int length;

    Node arrayNode[capacity];
};

#endif;