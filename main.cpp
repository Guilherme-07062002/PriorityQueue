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
        std::cout << "       MENU\n";

        std::cout << "1. Add password\n";
        std::cout << "2. Remove password\n";
        std::cout << "3. Show\n";
        std::cout << "0. Exit\n";
        std::cout << "Choose a option: ";
        std::cin >> option;

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
                std::cout << "Operation: [E / S / D / E]: ";
                std::cin >> operation;
            } while (operation != "S" && operation != "D" && operation != "F" && operation != "E");
            data = preferential + operation;
            priorityQueue.enqueue(data, "000");
            break;
        case 2:
            // Lógica para a opção 2
            std::cout << "Opção 2 selecionada.\n";
            break;
        case 3:
            // Lógica para a opção 3
            priorityQueue.print();
            break;
        }
    } while (option != 0);
    return 0;
}