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

int RandomizedSelect(int array[],int begin,int end,int ith_smallest){
    if(ith_smallest>end+1){
            cout<<"please input valid num"<<endl;
            return -1;
    }
    if(begin==end)
        return array[begin];
    int q=RandomizePartition(array,begin,end);
    int kth_smallest=q-begin+1;
    if(ith_smallest==kth_smallest)// the pivot value is the answer
        return array[q];
    else if(ith_smallest<kth_smallest)
        return RandomizedSelect(array,begin,q-1,ith_smallest);
    else return RandomizedSelect(array,q+1,end,ith_smallest-kth_smallest);
}

int RandomizedSelectIterative(int array[],int begin,int end,int ith_small){
    while(begin<end){
        int q=RandomizePartition(array,begin,end);
        int kth_small=q-begin+1;
        if(ith_small==kth_small)
            return array[begin];
        else if(ith_small<kth_small)
            end=q-1;
        else{
            begin=q+1;
            ith_small=ith_small-kth_small;
        }
    }
    //when begin==end
    return array[begin];
}
int main()
{
    int array[]={1,2,4,5,3};
    //cout<<RandomizedSelect(array,0,sizeof(array)/sizeof(int)-1,6)<<endl;
    cout<<RandomizedSelectIterative(array,0,sizeof(array)/sizeof(int)-1,4)<<endl;
    return 0;
}
