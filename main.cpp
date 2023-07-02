#include <iostream>
#include "pqueue.hpp"

int main()
{
    PriorityQueue priorityQueue = PriorityQueue();
    int option;
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
            
        case 2:
            // Lógica para a opção 2
            std::cout << "Opção 2 selecionada.\n";
            break;
        case 3:
            // Lógica para a opção 3
            std::cout << "Opção 3 selecionada.\n";
            break;
        }
    } while (option != 0);
    return 0;
}