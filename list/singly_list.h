#ifndef SINGLY_LIST_H_INCLUDED
#define SINGLY_LIST_H_INCLUDED
#include <iostream>
//namesapce polluted;
//using namespace std;
class SinglyList{
public:
    int key_;
    SinglyList* next_;
    SinglyList(int key):key_(key),next_(NULL){}
    virtual ~SinglyList(){}
};

class SinglyListHead:public SinglyList{
private:
    SinglyList* SearchPrev(int key);
public:
    //SinglyList* head_;
    SinglyListHead():SinglyList(0){}
    ~SinglyListHead(){}
    SinglyList* Search(int key);
    int Length();
    void Insert(SinglyList& element);
    void Delete(int key);
    void Reverse();
    void PrintList();
};
#endif // SINGLY_LIST_H_INCLUDED
