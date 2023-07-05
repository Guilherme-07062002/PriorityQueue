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
    std::string priority;
    std::string data;
    Node *next;

    Node() : data(""), priority(""), next(nullptr) {}

    Node(const std::string &data, const std::string &priority) : data(data), priority(priority), next(nullptr) {}
};

#endif