#include <iostream>
#include "pqueue.hpp"
#include "node.hpp"

PriorityQueue::PriorityQueue()
{
    std::cout << "Building object...\n";
    length = -1;
    is_empty = true;
    index_start = 0;
    front = nullptr;
}

PriorityQueue::~PriorityQueue()
{
    std::cout << "Destroying object...\n";
}

void PriorityQueue::enqueue(int priority, std::string data)
{
    Node *newNode = new Node(priority, data);

    if (front == nullptr || priority < front->priority)
    {
        newNode->next = front;
        front = newNode;
    }
    else
    {
        Node *current = front;
        while (current->next != nullptr && current->next->priority <= priority)
        {
            current = current->next;
        }

        newNode->next = current->next;
        current->next = newNode;
    }
    std::cout << "New element enqueued.\n";
}

void PriorityQueue::dequeue()
{
    if (!empty())
    {
        Node *nodeToDelete = front;
        front = front->next;
        delete nodeToDelete;
        std::cout << "Element removed from queue.\n";
    }
}

bool PriorityQueue::empty()
{
    return front == nullptr;
}

void PriorityQueue::print()
{
    if (empty())
    {
        std::cout << "Queue is empty \n";
        return;
    }

    Node *current = front;
    while (current != nullptr)
    {
        std::cout << "Priority: " << current->priority << ", Data: " << current->data << std::endl;
        current = current->next;
    }
}