#include <iostream>
using namespace std;

void PrintArray(int* array, int length) {
	for (int i = 0; i < length; i++) {
		cout << array[i] << " ";
	}
}

// by increasement order, T(n)=O(n^2)
void InsertionSort(int* array, int length) {
	for (int j = 1; j < length; j++) {
		int key = array[j];
		int i = j - 1;
		while (i >= 0 && array[i] > key) {
			array[i + 1] = array[i];
			i--;
		}
		array[i + 1] = key;
	}
}

void SwapElement(int array[],int i,int j){
    int temp=array[i];
    array[i]=array[j];
    array[j]=temp;
}

//precondition:all the value of elements are distinct
//T(n)=0(n)
int Partition(int array[],int low,int high,int pivot){
    int i=low-1;
    for(int j=low;j<=high-1;j++){
        if(array[j]<pivot){
            i++;
            SwapElement(array,i,j);
        }else if(array[j]==pivot){
            SwapElement(array,j,high);
            j--;
        }
    }
    SwapElement(array,i+1,high);
    return i+1;
}

//select in worest-case linear time
int Select(int array[],int length,int kth_small){
    //the value 140 is figured out by the book;
    if(length<=140){
        InsertionSort(array,length);
        return array[kth_small-1];
    }
    //divide the n elements into ⌊n/5⌋ groups and sort each group
    int i=0;
    for(;i<length/5-1;i++){
        InsertionSort(array+i*5,5);
        //!move the median of each group to the front of the array
        SwapElement(array,i,i*5+2);
    }
    InsertionSort(array+i*5,length-i*5);
    SwapElement(array,i,i*5+(length-i*5)/2);
    //find the median of median group
    int median=Select(array,length/5,length/2);
    int median_index=Partition(array,0,length-1,median);
    if(kth_small==(median_index+1))
        return array[median_index];
    else if(kth_small<median_index+1)
        return Select(array,median_index,kth_small);
    else
        return Select(array+median_index+1,length-median_index-1,kth_small-median_index-1);
}

int main()
{
    int array[]={1,3,2,5,4,9,8,7,6,11,10};
    cout<<Select(array,sizeof(array)/sizeof(int),10)<<endl;
    PrintArray(array,sizeof(array)/sizeof(int));
    return 0;
}
