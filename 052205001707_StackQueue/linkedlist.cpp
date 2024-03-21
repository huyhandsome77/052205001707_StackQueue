#include "linkedlist.h"
#include <iostream>
#include<math.h>
using namespace std;
linkedlist::linkedlist()
{
    //ctor
    this->head = nullptr;
    this->tail = nullptr;
    this->nNum = 0;
}

linkedlist::~linkedlist()
{
    //dtor
}
void linkedlist::InsertFirst(element* e) {
    if (this->head == nullptr)
        this->head = this->tail = e;
    else {
        e->Setpointer(this->head); // Setpointer mui ten
        this->head = e;
    }
    this->nNum++;

}

// 4. InsertTail

void linkedlist::InsertTail(element* e) {
    if (this->head == nullptr)
        this->head = this->tail = e;
    else {
        this->tail->Setpointer(e);// step 1
        this->tail = e;    // step 2
    }
    this->nNum++;
}


void linkedlist::Travel() {
    element* p = this->head;
    while (p != nullptr) {
        cout << p->Getdata() << "\t";
        p = p->Getpointer();
    }
}
bool linkedlist::DeleteFirst() {
    if (this->head == nullptr) return false;
    else {
        element* p = this->head;
        this->head = this->head->Getpointer(); // Getpointer tro sang phan tu tiep the
        delete p;
        return true;
    }
}

bool linkedlist::DeleteLast() {
    if (this->tail == nullptr) return false;
    else if (this->head->Getpointer() == nullptr) {
        delete this->head;
        this->head = this->tail = nullptr;
    }
    else {
        element* current = this->head;
        while (current->Getpointer()->Getpointer() != nullptr) {
            current = current->Getpointer();
        }
        delete current->Getpointer();
        current->Setpointer(nullptr);
        this->tail = current;
    }
    this->nNum--;
    return true;
}


#include "linkedlist.h"

bool linkedlist::RemoveAll() {
    if (this->head == nullptr) {
        return true;
    }

    while (this->head != nullptr) {
        element* p = this->head;
        this->head = this->head->Getpointer();
        delete p;
    }

    this->tail = nullptr;
    this->nNum = 0;

    return true;
}

// 1. SumList
int linkedlist::SumList() {
    int sum = 0;
    element* p = this->head;
    while (p != nullptr) {
        sum += p->Getdata();
        p = p->Getpointer();
    }
    return sum;
}



// 2. MaxList

int linkedlist::MaxList() {
    int max = this->head->Getdata();
    element* p = this->head->Getpointer();
    while (p != nullptr)
    {

        if (p->Getdata() > max) {
            max = p->Getdata();
        }
        p = p->Getpointer();
    }
    return max;
}






// 3.CountPrime
bool linkedlist::snt(element* p) {
    int value = p->Getdata();
    for (int i = 2; i <= sqrt(value); i++)
    {
        if (value % i == 0)
        {
            return false;
        }
    }
    return true;
}

int linkedlist::CountPrime() {
    int count = 0;
    element* p = this->head;
    while (p != nullptr) {
        if (snt(p))
        {
            count++;
        }
        p = p->Getpointer();
    }
    return count;
}


// 5. InsertAfter

void linkedlist::InsertAfter(element* a, int b)
{
    if (a == nullptr) {
        cout << "Eror";
        return;
    }
    element* newE = new element(b);
    newE->Setpointer(a->Getpointer());
    a->Setpointer(newE);
    this->nNum++;
    if (this->tail == a) {
        this->tail = newE;
    }
}

// DeleteAfter
void linkedlist::DeleteAfter(element* current) {
    if (current == nullptr || current == this->tail)
    {
        cout << "Fail. Khong the xoa phan tu phia sau";
        return;
    }
    element* p = current->Getpointer();
    if (p == this->tail)
    {
        delete p;
        this->tail = current;
    }
    else {
        current->Setpointer(p->Getpointer());
        delete p;
    }
    this->nNum--;
}



// 9.
int linkedlist::Count_x(int x)
{
    int count = 0;
    element* p = this->head;
    while (p != nullptr)
    {
        if (p->Getdata() == x)
        {
            count++;
        }
        p = p->Getpointer();
    }
    return count;
}
// 10. Bổ sung chương trình mẫu cho phép tạo một danh sách liên kết đơn gồm các phần tử mang giá trị nguyên trong đó không có cặp phần tử nào mang giá trị giống nhau. 
// Gợi ý : sử dụng hàm InsertFirst hoặc InsertTail có bổ sung thao tác kiểm tra phần tử giống nhau.
bool linkedlist::kiemtratontai(int x) {
    element* p = this->head;
    while (p != nullptr)
    {
        if (p->Getdata() == x)
            return true;
        p = p->Getpointer();
    }

    return false;
}

void linkedlist::TaoDs(int x)
{
    if (linkedlist::kiemtratontai(x))
    {
        return;
    }
    element* new_x = new element(x);
    linkedlist::InsertTail(new_x);
}


//9 Tach danh sach

void linkedlist::TachDS(linkedlist* list1, linkedlist* list2, int x)
{
    if (this->head == nullptr || this->head->Getpointer() == nullptr)
    {
        cout << "Fail. Danh sach rong hoac co 1 phan tu !";
        return;
    }
    element* current = this->head;
    while (current != nullptr)
    {
        if (current->Getdata() < x)
        {
            list1->InsertTail(new element(current->Getdata())); // Thêm một bản sao của phần tử hiện tại vào list1
        }
        else if (current->Getdata() > x)
        {
            list2->InsertTail(new element(current->Getdata())); // Thêm một bản sao của phần tử hiện tại vào list2
        }
        current = current->Getpointer();
    }
    cout << "2 list sau khi tach voi x = " << x << endl;
    cout << "Danh sach 1 ( < " << x << " ) : ";
    list1->Travel();
    cout << endl;
    cout << "Danh sach 2 ( > " << x << " ) : ";
    list2->Travel();
}