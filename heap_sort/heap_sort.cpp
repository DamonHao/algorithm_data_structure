#include <iostream>

using namespace std;

void printArray(int* array, int length) {
    for (int i = 0; i < length; i++) {
        cout << array[i] << " ";
    }
}
//int Parent(int i){
//    return (i-1)/2;
//}
//

int LeftChildPosition(int i) {
    return 2*i+1;
}

int RightChildPosition(int i) {
    return 2*i+2;
}
void SwapElement(int* array,int i,int j) {
    int temp=array[i];
    array[i]=array[j];
    array[j]=temp;
}
//T(n)=O(log(n))
void MaxHeapify(int* array,int i,int length) {
    int l=LeftChildPosition(i);
    int r=RightChildPosition(i);
    int largest=i;
    if(l<length && array[l]>array[i])
        largest=l;
    if(r<length && array[r]>array[largest])
        largest=r;
    if(largest!=i) {
        SwapElement(array,i,largest);
        MaxHeapify(array,largest,length);
    }
}
//T(n)=O(n)
void BuildMaxHeap(int* array,int length) {
    for(int i=length/2-1; i>=0; i--) {
        MaxHeapify(array,i,length);
    }
}

// by increasement order,T(n)=O(nlog(n))
void HeapSort(int* array,int length) {
    BuildMaxHeap(array,length);
    cout<<endl;
    int heap_size=length;
    for(int i=length; i>=2; i--) {
        SwapElement(array,0,i-1);
        heap_size--;
        MaxHeapify(array,0,heap_size);
    }
}

int main() {
    int array[]= {1,2,3,4,8,7,6,5};
    HeapSort(array,sizeof(array)/sizeof(int));
    printArray(array,sizeof(array)/sizeof(int));
    return 0;
}
