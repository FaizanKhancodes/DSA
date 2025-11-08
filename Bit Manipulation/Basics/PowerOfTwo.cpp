#include<bits/stdc++.h>
using namespace std;

void PowerOfTwo(int num){

    if(num < 0)
        num= -num;

    // if a num is a power of 2 then its binary representation has 
    // only a single a 1. So we can use clearRightmostSetBit method to check 
    // for num having single 1, e.g: 8= 00...01000 and 8-1= 7= 00...00111
    // 8 & 7= 00...01000 & 00...00111= 00...00000

    if(num & (num - 1))
        cout<<"NO";

    else
        cout<<"YES";
}

int main(){

    int num;
    cin>>num;

    // Check if given num is a power of 2
    PowerOfTwo(num);

    return 0;
}