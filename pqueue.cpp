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

void PriorityQueue::enqueue(std::string data, std::string priority)
{
    Node *newNode = new Node(data, priority);

    if (length < capacity)
    {
        if (front == nullptr || std::stoi(priority) < std::stoi(front->priority))
        {
            newNode->next = front;
            front = newNode;
        }
        else
        {
            Node *current = front;
            while (current->next != nullptr && std::stoi(current->next->priority) <= std::stoi(priority))
            {
                current = current->next;
            }

            newNode->next = current->next;
            current->next = newNode;
        }
        std::cout << "New element enqueued.\n";
    }
    else
    {
        std::cout << "The queue is full.\n";
    }
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
    else
    {
        std::cout << "The queue is empty.\n";
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
        std::cout << "The queue is empty \n";
        return;
    }

    Node *current = front;
    while (current != nullptr)
    {
        std::cout << "Priority: " << current->priority << ", Data: " << current->data << std::endl;
        current = current->next;
    }
}