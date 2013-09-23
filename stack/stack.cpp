#include <iostream>
#include <assert.h>
#include <string>
using namespace std;
// put a expression in argument expression
void Assert(int expression,string message){
    if(!expression)
        cout<<message<<endl;
    assert(expression);
}

// Array-based Stack
/*
template <typename E> class Stack{
private:
    E * array_;
    int array_size_;
    int top_;
public:
    Stack(int size = 5):array_size_(size),top_(-1){
        array_ = new E [size];
    }
    ~Stack(){
        delete []array_;
    }
    bool StackEmpty(){
        if(top_==-1) return true;
        else return false;
    }
    void Push(E element){
        if(top_ >= array_size_-1){
          cout<<"Stack has been full"<<endl;
          return;
        }
        top_++;
        array_[top_]=element;
    }
    E Pop(){
        if(StackEmpty()){
            cout<<"underflow"<<endl;
            return NULL;
        }else{
            top_--;
            return array_[top_+1];
        }
    }
};
*/

// Stack abtract class
template <typename E> class Stack {
private:
    void operator =(const Stack&) {} // Protect assignment
    Stack(const Stack&) {}// Protect copy constructor
public:
    Stack() {} // Default constructor
    virtual ~Stack() {} // Base destructor
    // Reinitialize the stack. The user is responsible for
    // reclaiming the storage used by the stack elements.
    virtual void Clear() = 0;
    // Push an element onto the top of the stack.
    // it: The element being pushed onto the stack.
    virtual void Push(const E& it) = 0;
    // Remove the element at the top of the stack.
    // Return: The element at the top of the stack.
    virtual E Pop() = 0;
    virtual const E& TopValue() const = 0; // Return: A copy of the top element.
    virtual int Length() const = 0;// Return: The number of elements in the stack.
};

// Array-based stack implementation
template <typename E> class AStack: public Stack<E> {
private:
    int maxSize;// Maximum size of stack
    int top;// Index for top element
    E *listArray;// Array holding stack elements
public:
    // Constructor
    AStack(int size = 5){
        maxSize = size;
        top = 0;
        listArray = new E[size];
    }
    // Destructor
    ~AStack() { delete [] listArray; }
     // Reinitialize
    void Clear() { top = 0; }
     // Put the reference of "it" on stack,
     // in case that you put use-defined object on stack
    void Push(const E& it) {
        //Assert(top != maxSize, "Stack is full");
        if(top == maxSize){
            cout<<"Stack is full"<<endl;
            return;
        }
        listArray[top++] = it;
    }
    // Pop top element
    E Pop() {
        Assert(top != 0, "Stack is empty");
        return listArray[--top];
    }
     // Return top element
    const E& TopValue() const {
        Assert(top != 0, "Stack is empty");
        return listArray[top-1];
    }
    // Return length
    int Length() const { return top; }

};

//
template <typename E> class Link{
public:
    const E & element_;
    Link<E> * next_;
    //Constructor
    //const variable must be initialized in initialized list
    Link(const E & element, Link<E>* next):
    element_(element),next_(next){}
    //Destructor
    ~Link(){}
};

// Linked stack implementation
template <typename E> class LStack: public Stack<E> {
private:
    Link<E>* top_;// Pointer to first element
    int size_;// Number of elements
public:
    // Constructor,set sz for unify the constructor interface of AStack
    LStack(int sz =3){ top_ = NULL; size_ = 0; }
    // Destructor
    LStack() { Clear(); }
    // Reinitialize
    void Clear() {
        while (top_ != NULL) {
            Link<E>* temp = top_;
            top_ = top_->next_;
            delete temp;
        }
        size_ = 0;
    }
    // Delete link nodes
    void Push(const E& it) { // Put "it" on stack
        top_ = new Link<E>(it, top_);
        size_++;
    }
    E Pop() {
         // Remove "it" from stack
        Assert(top_ != NULL, "Stack is empty");
        E it = top_->element_;
        Link<E>* ltemp = top_->next_;
        delete top_;
        top_ = ltemp;
        size_--;
        return it;
    }
    const E& TopValue() const { // Return top value
        Assert(top_ != 0, "Stack is empty");
        return top_->element_;
    }
    int Length() const { return size_; } // Return length
};

int main()
{
    AStack<int> i_stack(3);
    i_stack.Push(1);
    i_stack.Push(2);
    i_stack.Push(3);
    i_stack.Push(4);
    for(int i=5;i>=0;i--){
        cout<<i_stack.Pop()<<endl;
    }
    return 0;
}
