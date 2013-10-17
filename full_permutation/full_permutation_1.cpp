#include <iostream>
using namespace std;
//Implement full permutation by recursion
void FullPermutation(char* characters,int begin,int end){
    if(begin == end){
        for(int i = 0; i < end; i++)
            cout<<characters[i];
        cout<<endl;
    }else{
        for(int j = begin; j < end; j++){
            //swap two element position
            swap(characters[j],characters[begin]);
            FullPermutation(characters,begin+1,end);
            //restore the two swapped element 
            swap(characters[j],characters[begin]);
        }
    }
}
int main(){
    char characters[] = "abc";
    cout<<characters<<" and its full permutation:"<<endl;
    FullPermutation(characters,0,sizeof(characters)/sizeof(char)-1);
    return 0;
}

