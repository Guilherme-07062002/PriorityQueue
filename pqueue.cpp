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
    // Caso especial: se a fila estiver vazia ou o novo nó tem prioridade maior que a frente
    if (front == nullptr || priority < front->priority)
    {
        newNode->next = front;
        front = newNode;
    }
    else
    {
        Node *current = front;
        // Procura a posição correta para inserir o novo nó
        while (current->next != nullptr && current->next->priority <= priority)
        {
            current = current->next;
        }

        newNode->next = current->next;
        current->next = newNode;
    }
}
