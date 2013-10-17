#include <iostream>
#include <algorithm>
using namespace std;
//Impalment full permutation by stl algorithm function next_permutation.
//Note that next_permutation rearranges the elements in the range [first,last) 
//into the next lexicographically greater permutation, which mean a,b,c...in ascending 
//order have the minimun lexicographcall value,while z,y,x...,c,b,a in descending order has 
//maximun value. So before we use next_permutation(), we must sort the elements in ascending order
void permutation(char* str,int length){
    sort(str,str+length);
    do
    {
        for(int i=0;i<length;i++)
            cout<<str[i];
        cout<<endl;
    }while(next_permutation(str,str+length));

}
int main(void){
    char str[] = "cba";
    cout<<str<<" and its full permutation is:"<<endl;
    permutation(str,3);
    return 0;
}
