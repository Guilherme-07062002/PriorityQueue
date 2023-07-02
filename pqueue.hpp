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
     *Priority queue node element
     *@param priority Node priority level
     *@param data Information about the node
     */
    struct Node
    {
        int priority;
        std::string data;
        Node *next;

        Node(int priority, const std::string &data) : priority(priority), data(data), next(nullptr) {}
    };

    /*
     *Add element in Priority Queue
     *@param Node Element to be added
     */
    void enqueue(Node);
    void dequeue();
    bool empty();
    void print();

private:
    Node next;
    int index_start;
    bool is_empty;
    int size;

    Node arrayNode[capacity];
};

#endif;