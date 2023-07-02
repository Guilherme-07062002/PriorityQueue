#!/bin/bash

g++ -c main.cpp
g++ -c pqueue.cpp

g++ main.o pqueue.o -o program

./program
