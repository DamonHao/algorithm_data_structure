#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
using namespace std;
void SwapElement(int array[],int i,int j){
    if(i!=j){
        int temp=array[i];
        array[i]=array[j];
        array[j]=temp;
    }
}
//precondition:all the value of elements are distinct
//T(n)=0(n)
int Partition(int array[],int low,int high){
    int x=array[high];
    int i=low-1;
    for(int j=low;j<=high-1;j++){
        if(array[j]<=x){
            i++;
            SwapElement(array,i,j);
        }
    }
    SwapElement(array,i+1,high);
    return i+1;
}

//precondition:all the value of elements are distinct
//equal element will reduce its performance
int RandomizePartition(int array[],int low,int high){
    srand (time(NULL));
    int rand_num=rand()%(high-low)+low;
    SwapElement(array,rand_num,high);
    return Partition(array,low,high);
}

class EqualElement{
public:
    int low_;
    int high_;
    EqualElement(int x,int y):low_(x),high_(y){}
    EqualElement(const EqualElement& equal_element)
    :low_(equal_element.low_),high_(equal_element.high_){}
};

//partition with equal elements
EqualElement EnhancedPartition(int array[],int low,int high){
    int x=array[high];
    int i=low-1;
    for(int j=low;j<high;j++){
        if(array[j]<x){
            i++;
            SwapElement(array,i,j);
        }
    }
    i++;
    SwapElement(array,i,high);
    int k=i;
    for(int j=i+1;j<=high;j++){
        if(array[j]==array[i]){
            k++;
            SwapElement(array,k,j);
        }
    }
    return EqualElement(i,k);
}

//The performance of QuickSort mostly depend on Partition function;
//Average-case T(n)=O(nlog(n))
//Worest-case T(n)=0(n^2)
void QuickSort(int array[],int low,int high){
    if(low<high){
        //int q=Partition(array,low,high);
        int q=RandomizePartition(array,low,high);
        QuickSort(array,low,q-1);
        QuickSort(array,q+1,high);
    }
}
void EnhancedQuickSort(int array[],int low, int high){
    if(low<high){
        EqualElement equal_element = EnhancedPartition(array,low,high);
        EnhancedQuickSort(array,low,equal_element.low_-1);
        EnhancedQuickSort(array,equal_element.high_+1,high);
    }
}

void PrintArray(int array[],int length){
    for(int i=0;i<length;i++){
        cout<<array[i]<<" ";
    }
}

int main(){
    int array[]={1,4,5,6,3,2};
    //QuickSort(array,0,sizeof(array)/sizeof(int)-1);
    EnhancedQuickSort(array,0,sizeof(array)/sizeof(int)-1);
    PrintArray(array,sizeof(array)/sizeof(int));
    return 0;
}
