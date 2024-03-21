#include "queue.h"
#include <iostream>
using namespace std;

void Queue::push(int x) {
    element* p = new element(x);
    this->ListQ->InsertFirst(p);
}
int Queue::pop() {
    int p = this->ListQ->Gethead()->Getdata();
    this->ListQ->DeleteLast();
    return p;

}
void Queue::printQueue() {
    ListQ->Travel();
}
Queue::Queue()
{
    //ctor
    this->nNum = 0;
    this->ListQ = new linkedlist();
}
Queue::~Queue()
{
    //dtor
}
