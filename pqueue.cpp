#include <iostream>
#include "pqueue.hpp"

using namespace std;

PriorityQueue::PriorityQueue()
{
    cout << "Building object...\n";
    length = -1;
    is_empty = true;
    index_start = 0;
    front = nullptr;
}

PriorityQueue::~PriorityQueue()
{
    cout << "Destroying object...\n";
}

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