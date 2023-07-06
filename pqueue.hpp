#include <iostream>
#include "node.hpp"
#ifndef PQUEUE_HPP
#define PQUEUE_HPP

const int capacity = 5;

class PriorityQueue
{
public:
    PriorityQueue();
    ~PriorityQueue();

    /*
     *Add element in Priority queue
     *@param data Information about the element
     *@param counter Counter of password
     */
    void enqueue(std::string data, std::string counter);
    void dequeue();
    bool empty();
    void print();

private:
    Node *front;
    int index_start;
    bool is_empty;
    int length;
    int count[4];

    Node arrayNode[capacity];
};

#endif