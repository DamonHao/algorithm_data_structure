#include "singly_list.h"
#include <iostream>
using namespace std;

SinglyList* SinglyListHead::SearchPrev(int key){
    SinglyList* x_prev=this;
    SinglyList* x=next_->next_;
    if(x->key_==key)
        return x_prev;
    x=x->next_;
    while(x!=NULL&&x->key_!=key){
        x_prev=x;
        x=x->next_;
    }
    if(x!=NULL)
        return x_prev;
    else return NULL;
}

SinglyList* SinglyListHead::Search(int key){
    SinglyList* x=next_->next_;
    while(x!=NULL&&x->key_!=key)
        x=x->next_;
    return x;
}

int SinglyListHead::Length(){
    int length=0;
    SinglyList* x=next_;
    while(x!=NULL){
        length++;
        x=x->next_;
    }
    return length;
}

void SinglyListHead::Insert(SinglyList& element){
    element.next_=next_;
    next_=&element;
}

void SinglyListHead::Delete(int key){
    SinglyList* selected_element=SearchPrev(key);
    if(!selected_element){
        cout<<"this value is not in the list"<<endl;
        return;
    }
    selected_element->next_=selected_element->next_->next_;
}

void SinglyListHead::Reverse(){
    //check whether list contain none or one element
    if(next_==NULL||next_->next_==NULL)
        return;
    SinglyList* p_prev = next_;
    SinglyList* p_cur = next_->next_;
    SinglyList* p_next = p_cur->next_;
    p_prev->next_=NULL;
    p_cur->next_=p_prev;
    while(p_next!=NULL){
       p_prev=p_cur;
       p_cur=p_next;
       p_next=p_cur->next_;
       p_cur->next_=p_prev;
    }
    next_=p_cur;
    return;
}

void SinglyListHead::PrintList(){
    SinglyList* element = next_;
    while(element!=NULL){
        cout<<"->"<<element->key_;
        element=element->next_;
    }
    cout<<endl;
}
