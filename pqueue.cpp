#include <iostream>
#include <chrono>
#include <thread>
#include "pqueue.hpp"
#include "node.hpp"

PriorityQueue::PriorityQueue()
{
    std::cout << "Building object...\n";
    length = -1;
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

    Node *newNode = new Node(data, counter);

    if (length < capacity)
    {
        if (front == nullptr || std::stoi(counter) < std::stoi(front->counter))
        {
            newNode->next = front;
            front = newNode;
        }
        else
        {
            Node *current = front;
            while (current->next != nullptr && std::stoi(current->next->counter) <= std::stoi(counter))
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
        Node *nodeToDelete = front;
        front = front->next;
        delete nodeToDelete;
        std::cout << "Element removed from queue.\n";
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