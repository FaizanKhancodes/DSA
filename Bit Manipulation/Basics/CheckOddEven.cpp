#include<bits/stdc++.h>
using namespace std;

void checkOddEven(int num){

    if(num & 1)
        cout<<"odd";

    else    
        cout<<"even";
}

int main(){

    int num;
    cin>>num;

    checkOddEven(num);

    return 0;
}