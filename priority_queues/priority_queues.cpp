#include <iostream>
#include <vector>
using namespace std;
//Heap is good data structure for priority queue,
//and vector is good implement of heap considering priority queue;
int ParentPosition(int cur_position){
    return (cur_position-1)/2;
}

int LeftChildPosition(int cur_position) {
    return 2*cur_position+1;
}

int RightChildPosition(int cur_position) {
    return 2*cur_position+2;
}
void SwapElement(vector<int>& array,unsigned i,unsigned j) {
    int temp=array[i];
    array[i]=array[j];
    array[j]=temp;
}
//T(n)=O(log(n))
void MaxHeapify(vector<int>& array,unsigned cur_position) {
    unsigned l=LeftChildPosition(cur_position);
    unsigned r=RightChildPosition(cur_position);
    unsigned largest=cur_position;
    if(l<array.size() && array[l]>array[cur_position])
        largest=l;
    if(r<array.size() && array[r]>array[largest])
        largest=r;
    if(largest!=cur_position) {
        SwapElement(array,cur_position,largest);
        MaxHeapify(array,largest);
    }
}
//T(n)=O(n)
void BuildMaxHeap(vector<int>& array) {
    //type int is enough to hold unsigned/2-1
    for(int i=array.size()/2-1; i>=0; i--) {
        MaxHeapify(array,i);
    }
}
//T(n)=O(1)
int HeapMax(vector<int>& heap){
    return heap[0];
}
//T(n)=O(log(n))
int HeapExtractMax(vector<int>& heap){
    if(heap.size()<1){
        cout<<"heap underflow"<<endl;
        return 0;
    }
    int max=heap[0];
    heap[0]=heap[heap.size()-1];
    heap.pop_back();
    MaxHeapify(heap,0);
    return max;
}
//T(n)=O(log(n))
void HeapIncreaseKey(vector<int>& heap,unsigned cur_position,int key){
    if(key<heap[cur_position]){
    cout<<"new key is smaller than current key"<<endl;
    return;
    }
    heap[cur_position]=key;
    while(cur_position>=0&&heap[ParentPosition(cur_position)]<heap[cur_position]){
        SwapElement(heap,cur_position,ParentPosition(cur_position));
        cur_position=ParentPosition(cur_position);
    }
}
//T(n)=O(log(n))
void MaxHeapInsert(vector<int>& heap,int key){
    heap.push_back(key-1);
    HeapIncreaseKey(heap,heap.size()-1,key);
}
void printHeap(vector<int>& heap){
    for(unsigned i=0;i<heap.size();i++){
        cout<<heap[i]<<" ";
    }
    cout<<endl;
}
int main(){
    vector<int> heap;
    heap.push_back(1);
    heap.push_back(2);
    heap.push_back(3);
    heap.push_back(6);
    heap.push_back(5);
    heap.push_back(4);
    printHeap(heap);
    BuildMaxHeap(heap);
    //printHeap(heap);
    //cout<<HeapExtractMax(heap)<<endl;
    //HeapIncreaseKey(heap,heap.size()-1,10);
    MaxHeapInsert(heap,10);
    printHeap(heap);
    return 0;
}
