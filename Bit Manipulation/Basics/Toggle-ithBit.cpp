#include<bits/stdc++.h>
using namespace std;

void Toggle_ithBit(int num, int i){

    num= num ^ (1 << i);
    cout<<num;
}

int main(){

    int num;
    cin>>num;

    // 0 <= i <= 30
    int i;
    cin>>i;

    Toggle_ithBit(num, i);

    return 0;
}