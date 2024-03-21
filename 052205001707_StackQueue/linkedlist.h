#pragma once
#include "element.h"

class linkedlist
{
private:
    element* head;
    element* tail;
    int nNum;
public:
    linkedlist();
    virtual ~linkedlist();
    element* Gethead() { return head; }
    void Sethead(element* val) { head = val; }
    element* Gettail() { return tail; }
    void Settail(element* val) { tail = val; }
    void InsertFirst(element*);
    void InsertTail(element*);
    bool DeleteFirst();
    void Travel();
    bool RemoveAll();
    int SumList();
    int MaxList();
    bool snt(element*);
    int CountPrime();
    bool DeleteLast();
    void InsertAfter(element*, int);
    void DeleteAfter(element*);
    int Count_x(int);
    bool kiemtratontai(int x);
    void TaoDs(int x);
    void TachDS(linkedlist*, linkedlist*, int);
protected:


};

