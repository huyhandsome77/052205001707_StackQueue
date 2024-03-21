#ifndef STACK_H
#define STACK_H
#include "LinkedList.h"

class Stack
{
private: int nNum;
       linkedlist* List;
public:
    Stack();
    virtual ~Stack();
    void push(int);
    int pop();
    void printStack();
    void convert_2(int);
};

#endif // STACK_H
