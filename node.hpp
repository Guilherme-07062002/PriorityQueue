#include <iostream>
#ifndef NODE_HPP
#define NODE_HPP

/*
 *Priority queue node element
 *@param priority Node priority level
 *@param data Information about the node
 */
struct Node
{
    int priority;
    std::string data;
    Node *next;

    Node() : priority(0), data(""), next(nullptr) {}

    Node(int priority, const std::string &data) : priority(priority), data(data), next(nullptr) {}
};

#endif