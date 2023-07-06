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
    for (int i = 0; i < 3; ++i)
    {
        count[i] = -1;
    }
}

PriorityQueue::~PriorityQueue()
{
    std::cout << "Destroying object...\n";
}

void PriorityQueue::enqueue(std::string data, std::string priority)
{
    int index;
    switch (data[1])
    {
    case 'S':
        count[0] += 1;
        index = 0;
        break;
    case 'D':
        count[1] += 1;
        index = 1;
        break;
    case 'F':
        count[2] += 1;
        index = 2;
        break;
    }

    if (length >= 0 && length <= 9)
    {
        priority[2] = static_cast<char>((count[index]) + '0');
    }
    else if (length >= 10 && length <= 99)
    {
        priority[1] = static_cast<char>(((count[index]) / 10) + '0');
        priority[2] = static_cast<char>(((count[index]) % 10) + '0');
    }
    else if (length >= 100 && length <= 999)
    {
        priority[0] = static_cast<char>(((count[index]) / 100) + '0');
        priority[1] = static_cast<char>(((count[index]) / 10) % 10 + '0');
        priority[2] = static_cast<char>(((count[index]) % 10) + '0');
    }

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
        length++;
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
        std::cout << current->data << current->priority << std::endl;
        current = current->next;
    }
}