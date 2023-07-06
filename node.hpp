#include <iostream>
#ifndef NODE_HPP
#define NODE_HPP

/*
 *Priority queue node element
 *@param counter Node counter
 *@param data Information about the node
 */
struct Node
{
    std::string counter;
    std::string data;
    int priority;
    Node *next;

    Node() : data(""), counter(""), priority(0), next(nullptr) {}

    Node(const std::string &data, const std::string &counter, int priority) : data(data), counter(counter), priority(priority), next(nullptr) {}
};

#endif