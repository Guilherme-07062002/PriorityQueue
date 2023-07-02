#include <iostream>
#include "node.hpp"
#ifndef PQUEUE_HPP
#define PQUEUE_HPP

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
    void enqueue(int priority, string data);
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