#include <iostream>
#include "linkedlist.h"
#include "stack.h"
#include "queue.h"
using namespace std;

int main()
{
    cout << "Stack : ";
    Stack* s = new Stack();
    s->push(7);
    s->push(10);
    s->push(18);
    s->push(20);
    s->printStack();
    s->pop();
    cout << "\n";
    s->printStack();

    cout << endl;
    cout << "Queue : ";
    Queue* Q = new Queue();
    Q->push(7);
    Q->push(10);
    Q->push(18);
    Q->push(20);
    Q->printQueue();
    Q->pop();
    cout << "\n";
    Q->printQueue();

    cout << endl;
    Stack* z = new Stack();
    int n;
    cout << "Nhap so can chuyen doi: ";
    cin >> n;
    z->convert_2(n);
    return 0;

}

