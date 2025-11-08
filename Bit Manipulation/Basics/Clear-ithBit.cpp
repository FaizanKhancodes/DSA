#include<bits/stdc++.h>
using namespace std;

void Clear_ithBit(int num, int i){

    num= num & (~(1 << i));
    cout<<num;
}

int main(){

    int num;
    cin>>num;

    // 0 <= i <= 30
    int i;
    cin>>i;

    // Unset ith Bit
    Clear_ithBit(num, i);

    return 0;
}