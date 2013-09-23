#include <iostream>
#include "doubly_list.h"
using namespace std;

List* ListHead::Search(int key){
    List* x= this->head_;
    while(x!=NULL&&x->key_!=key)
        x=x->next_;
    return x;
}

int ListHead::Length(){
    int length=0;
    List* x = this->head_;
    while(x!=NULL){
      length++;
       x=x->next_;
    }
    return length;
}

void ListHead::Insert(List& element){
    element.next_=head_;
    if(head_!=NULL)
        head_->prev_= &element;
    head_=&element;
    element.prev_=NULL;
}

void ListHead::Delete(int key){
    List* selected_element = Search(key);
    if(selected_element==NULL){
        cout<<"this value is not in the list"<<endl;
        return;
    }
    //frist handle the "prev relationship" of current element,
    //then handle the "next relationship" of current element;
    //check whether selected_element is at list tail
    if(selected_element->next_!=NULL)
     selected_element->next_->prev_=selected_element->prev_;
    //check whether current element is list head
    if(selected_element->prev_!=NULL)
     selected_element->prev_->next_=selected_element->next_;
    else head_=selected_element->next_;
}

//
List2* ListNil::Search(int key){
    List2* x = next_;
    while(x!=this&&x->key_!=key)
        x=x->next_;
    return x;
}

int ListNil::Length(){
    int length=0;
    List2* x = next_;
    while(x!=this){
      length++;
       x=x->next_;
    }
    return length;
}

void ListNil::Insert(List2& element){
    //first handle the rear relationship of current elment
    element.next_=next_;
    next_->prev_=&element;
    //handle the front relationship of current elment
    next_=&element;
    element.prev_= this;
}

void ListNil::Delete(int key){
    //check whether the current element is in the list
    List2* selected_element = Search(key);
    if(!selected_element){
        cout<<"this value is not in the list"<<endl;
        return;
    }
    selected_element->next_->prev_=selected_element->prev_;
    selected_element->prev_->next_=selected_element->next_;
}
