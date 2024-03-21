#include "Stack.h"
#include <iostream>


void Stack::push(int x) {
    element* p = new element(x);
    this->List->InsertFirst(p);
}
int Stack::pop() {
    int p = this->List->Gethead()->Getdata();
    this->List->DeleteFirst();
    return p;

}
void Stack::printStack() {
    List->Travel();
}
Stack::Stack()
{
    //ctor
    this->nNum = 0;
    List = new linkedlist();
}
Stack::~Stack()
{
    //dtor
}

void Stack::convert_2(int n) {
    Stack s;
    int m = n;
    while (n > 0) {
        s.push(n % 2);
        n /= 2;
    }
    std::cout << "So " << m << " trong he 2 la: ";
    s.printStack();
}