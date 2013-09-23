#include <iostream>
#include <math.h>
using namespace std;

int GetDigitValue(int target,int digit){
    if(digit==1)
        return target%10;
    else
        return (target/static_cast<int>(pow(10,digit-1)))%10;
}

void CountingSort(int* source,int* target,const int length,const int k,int digit){
    //this will be costly in space when k is big enough
    int* auxiliary=new int[k+1];
    for(int i=0;i<k+1;i++){
        auxiliary[i]=0;
    }
    for(int j=0;j<length;j++){
        auxiliary[GetDigitValue(source[j],digit)]++;
    }
    //auxiliary[i] now contains the numbers of elements equal to i
    for(int i=1;i<=k;i++){
        auxiliary[i]+=auxiliary[i-1];
    }
    //auxiliary[i] now contains the number of elements less than or equal to i
    for(int j=length-1;j>=0;j--){
        target[auxiliary[GetDigitValue(source[j],digit)]-1]=source[j];
        auxiliary[GetDigitValue(source[j],digit)]--;
    }
    delete [] auxiliary;
}

void CopyArray(int* source,int* target,int length){
    for(int i=0;i<length;i++)
        target[i]=source[i];
}

void SwapPointer(int**source,int** target){
    int* temp= *source;
    *source=*target;
    *target=temp;
}
//RadixSort is a good algorithm without good data structure
//T(n)=0(digit(n+k)) if the stable sort it uses takes 0(n+k) time
void RadixSort(int array [],int length,int digit){
    int* temp_source=new int[length];
    int* temp_target=new int[length];
    CopyArray(array,temp_source,length);
    for(int i=1;i<=digit;i++){
        //use a stable sort to sort array on digit i
        CountingSort(temp_source,temp_target,length,9,i);
        SwapPointer(&temp_source,&temp_target);
    }
    CopyArray(temp_source,array,length);
    delete[] temp_source;
    delete[] temp_target;
}

void PrintArray(int array[],int length){
    for(int i=0;i<length;i++){
        cout<<array[i]<<" ";
    }
    cout<<endl;
}

int main()
{
    int array[]={123,789,456,127,33,7};
    RadixSort(array,sizeof(array)/sizeof(int),3);
    PrintArray(array,sizeof(array)/sizeof(int));
    return 0;
}
