#include<bits/stdc++.h>
using namespace std;

void Check_ithBit(int num, int i){

    if(num & (1 << i))
        cout<<"1";

    else
        cout<<"0";
}

int main(){

    int num;
    cin>>num;

    // 0 <= i <= 30
    int i;
    cin>>i;

    Check_ithBit(num, i);

    return 0;
}