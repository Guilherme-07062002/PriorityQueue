#include <iostream>
#include <chrono>
#include <thread>
#include "pqueue.hpp"
#include "node.hpp"

PriorityQueue::PriorityQueue()
{
    std::cout << "Building object...\n";
    length = 0;
    is_empty = true;
    index_start = 0;
    front = nullptr;
    for (int i = 0; i < 4; ++i)
    {
        count[i] = -1;
    }
    std::chrono::seconds duration(1);
    std::this_thread::sleep_for(duration);
}

PriorityQueue::~PriorityQueue()
{
    std::cout << "Destroying object...\n";
    std::chrono::seconds duration(1);
    std::this_thread::sleep_for(duration);
}

void PriorityQueue::enqueue(std::string data, std::string counter)
{
    int index;
    int priority;
    switch (data[0])
    {
    case 'P':
        priority = 0;
        break;
    case 'N':
        priority = 1;
        break;
    }
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
    case 'E':
        count[3] += 1;
        index = 3;
        break;
    }

    if (length >= 0 && length <= 9)
    {
        counter[2] = static_cast<char>((count[index]) + '0');
    }
    else if (length >= 10 && length <= 99)
    {
        counter[1] = static_cast<char>(((count[index]) / 10) + '0');
        counter[2] = static_cast<char>(((count[index]) % 10) + '0');
    }
    else if (length >= 100 && length <= 999)
    {
        counter[0] = static_cast<char>(((count[index]) / 100) + '0');
        counter[1] = static_cast<char>(((count[index]) / 10) % 10 + '0');
        counter[2] = static_cast<char>(((count[index]) % 10) + '0');
    }

    Node *newNode = new Node(data, counter, priority);

    if (length < capacity)
    {
        if (front == nullptr || priority < front->priority)
        {
            newNode->next = front;
            front = newNode;
        }
        else
        {
            Node *current = front;
            while (current->next != nullptr && current->next->priority < priority)
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
    std::chrono::seconds duration(2);
    std::this_thread::sleep_for(duration);
}

void PriorityQueue::dequeue()
{
    if (!empty())
    {
        if (length == capacity)
        {
            Node *nodeToDelete = front;
            front = front->next;
            delete nodeToDelete;
            length--;
            std::cout << "Element removed from queue.\n";
        }
        else
        {
            std::cout << "The element only can dequeued if the queue is full.\n";
        }
    }
    else
    {
        std::cout << "The queue is empty.\n";
    }
    std::chrono::seconds duration(2);
    std::this_thread::sleep_for(duration);
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
        std::cout << current->data << current->counter << std::endl;
        current = current->next;
    }
    std::chrono::seconds duration(2);
    std::this_thread::sleep_for(duration);
}