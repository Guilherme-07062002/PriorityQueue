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
    Node *next;

    Node() : data(""), counter(""), next(nullptr) {}

    Node(const std::string &data, const std::string &counter) : data(data), counter(counter), next(nullptr) {}
};

#endif