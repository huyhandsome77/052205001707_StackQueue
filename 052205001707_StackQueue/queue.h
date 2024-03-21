#pragma once
#include "linkedlist.h"
class Queue
{
private:
	int nNum;
	linkedlist* ListQ;
public:
	Queue();
	virtual ~Queue();
	void push(int);
	int pop();
	void printQueue();
};

