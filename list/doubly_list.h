#ifndef DOUBLY_LIST_H_INCLUDED
#define DOUBLY_LIST_H_INCLUDED

class List{
public:
    List* next_;
    List* prev_;
    int key_;
    List(int key):key_(key){
        next_=prev_=NULL;
    }
    ~List(){}
};
//
class ListHead{
public:
    List* head_;
    ListHead():head_(NULL){}
    ~ListHead(){}
    //O(n)
    List* Search(int key);
    //O(n)
    int Length();
    //Insert() and Delete should be the method of ListHead
    //O(1)
    void Insert(List& element);
    //O(n)
    void Delete(int key);
};

//bring in sentinels
//! A sentinel is a dummy object that allows us to simplify boundary conditions
class List2{
public:
    List2* next_;
    List2* prev_;
    int key_;
    List2(int key):key_(key){
        next_=prev_=NULL;
    }
    virtual ~List2(){}
};

class ListNil:public List2{
public:
    ListNil():List2(-1){
        next_=prev_=this;
    }
    ~ListNil(){}
    //O(n)
    List2* Search(int key);
    //O(n)
    int Length();
    //O(1)
    void Insert(List2& element);
    //O(n)
    void Delete(int key);
};


#endif // DOUBLY_LIST_H_INCLUDED
