#include <iostream>
#include "pqueue.hpp"
#include "node.hpp"

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

void PriorityQueue::enqueue(int priority, string data)
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
        cout << "New password enqueued.\n";
    }
}

void PriorityQueue::dequeue()
{
    if (!isEmpty())
    {
        Node *nodeToDelete = front;
        front = front->next;
        delete nodeToDelete;
        cout << "Password removed from queue.\n";
    }
}

bool PriorityQueue::empty()
{
    return front == nullptr;
}

void print()
{
    if (is_empty)
    {
        cout << "Queue is empty \n";
        return;
    }

    Node *current = front;
    while (current != nullptr)
    {
        std::cout << "Priority: " << current->priority << ", Data: " << current->data << std::endl;
        current = current->next;
    }
}