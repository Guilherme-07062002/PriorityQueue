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
     *@param priority Priority level of the element
     *@param data Information about the element
     */
    void enqueue(std::string data, std::string priority);
    void dequeue();
    bool empty();
    void print();

private:
    Node *front;
    int index_start;
    bool is_empty;
    int length;
    int count[3];

    Node arrayNode[capacity];
};

#endif