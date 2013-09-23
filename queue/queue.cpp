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

// Abstract queue class
template <typename E> class Queue {
private:
    // Protect assignment
    void operator =(const Queue&) {}
    // Protect copy constructor
    Queue(const Queue&) {}
public:
    // Default
    Queue() {}
    // Base destructor
    virtual  ~Queue() {}
    // Reinitialize the queue. The user is responsible for
    // reclaiming the storage used by the queue elements.
    virtual void Clear() = 0;
    // Place an element at the rear of the queue.
    // it: The element being enqueued.
    virtual void EnQueue(const E&) = 0;
    // Remove and return element at the front of the queue.
    // Return: The element at the front of the queue.
    virtual E DeQueue() = 0;
    // Return: A copy of the front element.
    virtual const E& FrontValue() const = 0;
    // Return: The number of elements in the queue.
    virtual int Length() const = 0;
};

// Array-based queue implementation
template <typename E> class AQueue: public Queue<E> {
private:
    // Maximum size of queue
    int max_size_;
    // Index of front element
    int front_;
    // Index of rear element
    int rear_;
    // Array holding queue elements
    E *list_array_;
public:
    // Constructor
    AQueue(int size =3) {
        //! Make list array one position larger for empty slot
        //! to distinguish the full state and empty state;
        max_size_ = size+1;
        rear_ = 0; front_ = 1;
        list_array_ = new E[max_size_];
    }
    ~AQueue() { delete [] list_array_; } // Destructor
    void Clear() { rear_ = 0; front_ = 1; } // Reinitialize
    void EnQueue(const E& it) {
         // Put "it" in queue
        Assert(((rear_+2) % max_size_) != front_, "Queue is full");
        rear_ = (rear_+1) % max_size_;
         // Circular increment
        list_array_[rear_] = it;
    }
     // Take element out
    E DeQueue() {
        Assert(Length() != 0, "Queue is empty");
        E it = list_array_[front_];
        // Circular increment
        front_ = (front_+1) % max_size_;
        return it;
    }
    // Get front value
    const E& FrontValue() const {
        Assert(Length() != 0, "Queue is empty");
        return list_array_[front_];
    }
    // Return length
    virtual int Length() const{
        return ((rear_+max_size_) - front_ + 1) % max_size_;
    }
};

//my version
template<typename T> class MyQueue{
private:
    int array_size_;
    int head_;
    int tail_;
    T* array_;
public:
    MyQueue(int queue_max_size){
        array_size_=queue_max_size+1;
        head_=tail_=0;
        array_=new T[array_size_];
    }
    ~MyQueue(){delete [] array_;}
    //if you change the argument type to T& x,the compiler will report error
    //"no matching function for call to ‘MyQueue<int>::EnQueue(int)’";
    //if you use code:
    //MyQueue<int> a_queue(3);
    //a_queue.EnQueue(1);
    //because number 1 is constant value, so the argument type should be const T& x;
    void EnQueue(const T& x){
        Assert(head_!=tail_+1,"Queue is full");
        array_[tail_]=x;
        // Circular increment
        if(tail_==array_size_-1)
            tail_=0;
        else tail_++;
    }
    T DeQueue(){
        Assert(head_!=tail_,"Queue is empty");
        T x=array_[head_];
        // Circular increment
        if(head_==array_size_-1)
            head_=0;
        else head_++;
        return x;
    }
    int Length(){return (tail_+array_size_-head_)%array_size_;}
};
int main()
{
    MyQueue<int> a_queue(3);
    a_queue.EnQueue(1);
    a_queue.EnQueue(2);
    a_queue.EnQueue(3);
    //cout<<a_queue.Length()<<endl;
    int len = a_queue.Length();
    for(int i=0;i<len;i++)
        cout<<a_queue.DeQueue()<<endl;
    return 0;
}
