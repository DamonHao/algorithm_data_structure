#include <iostream>

using namespace std;
//Counting sort assumes that each of the n input elements is an integer in
//the range 0 to max_value, for some integer max_value. When max_value=O(n),the sort runs in 0(n) time;
//Counting sort is stable T(n)=0(max_value+n);
void CountingSort(int source[],int target[],const int length,const int max_value){
    //this will be costly in space when max_value is big enough
    int* auxiliary=new int[max_value+1];
    for(int i=0;i<max_value+1;i++){
        auxiliary[i]=0;
    }
    for(int j=0;j<length;j++){
        auxiliary[source[j]]++;
    }
    //auxiliary[i] now contains the numbers of elements equal to i
    for(int i=1;i<=max_value;i++){
        auxiliary[i]+=auxiliary[i-1];
    }
    //auxiliary[i] now contains the number of elements less than or equal to i
    for(int j=length-1;j>=0;j--){
        target[auxiliary[source[j]]-1]=source[j];
        auxiliary[source[j]]--;
    }
    delete [] auxiliary;
}

void PrintArray(int array[],int length){
    for(int i=0;i<length;i++){
        cout<<array[i]<<" ";
    }
    cout<<endl;
}
int main()
{
    int source[]={1,3,4,5,6,1,2,3};
    int length=sizeof(source)/sizeof(int);
    int* target=new int[length];
    CountingSort(source,target,length,6);
    PrintArray(source,length);
    PrintArray(target,length);
    return 0;
}
