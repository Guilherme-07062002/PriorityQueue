#include <iostream>
#include "pqueue.hpp"

int main()
{
    PriorityQueue priorityQueue = PriorityQueue();
    int option;
    std::string operation;
    std::string preferential;
    std::string data;
    std::string priority;
    do
    {
        std::cout << "----------------------\n";
        std::cout << "       MENU\n";
        std::cout << "----------------------\n";
        std::cout << "1. Call password\n";
        std::cout << "2. Remove password\n";
        std::cout << "3. Show panel\n";
        std::cout << "0. Exit\n";
        std::cout << "Choose a option: ";
        std::cin >> option;
        std::cout << "----------------------\n";

        switch (option)
        {
        case 1:
            do
            {
                std::cout << "Type your preferential [P / N]: ";
                std::cin >> preferential;
            } while (preferential != "N" && preferential != "P");
            do
            {
                std::cout << "Operation: [ S / D / F / E]: ";
                std::cin >> operation;
            } while (operation != "S" && operation != "D" && operation != "F" && operation != "E");
            data = preferential + operation;
            priorityQueue.enqueue(data, "000");
            break;
        case 2:
            priorityQueue.dequeue();
            break;
        case 3:
            priorityQueue.print();
            break;
        }
    } while (option != 0);
    std::cout << "Bye." << std::endl;
    return 0;
}