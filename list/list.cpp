#include <iostream>
#include "singly_list.h"
#include "doubly_list.h"
using namespace std;

int main(){
/*
    ListHead list_head;
    List l1(1);
    List l2(2);
    List l3(3);
    List l4(4);
    list_head.Insert(l1);
    list_head.Insert(l2);
    list_head.Insert(l3);
    list_head.Insert(l4);
    //list_head.Delete(2);
    cout<<list_head.Search(2)<<endl;
    cout<<list_head.Length()<<endl;
*/
/*
    ListNil list_nil;
    List2 l1(1);
    List2 l2(2);
    List2 l3(3);
    list_nil.Insert(l1);
    list_nil.Insert(l2);
    list_nil.Insert(l3);
    list_nil.Delete(1);
    cout<<list_nil.Search(1)->key_<<endl;
    cout<<list_nil.Length()<<endl;
*/

    SinglyListHead singly_list_head;
    SinglyList l1(1);
    SinglyList l2(2);
    SinglyList l3(3);
    singly_list_head.Insert(l1);
    singly_list_head.Insert(l2);
    singly_list_head.Insert(l3);
//    singly_list_head.Delete(2);
//    singly_list_head.Delete(1);
//    cout<<singly_list_head.Length()<<endl;
    singly_list_head.PrintList();
    singly_list_head.Reverse();
    singly_list_head.PrintList();
    return 0;
}



