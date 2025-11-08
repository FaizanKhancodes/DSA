#include<bits/stdc++.h>
using namespace std;

void swap(int& a, int& b){

    a= a ^ b;
    b= a ^ b;       // b= a ^ b ==> b= (a^b) ^ b ==> b= a
    a= a ^ b;       // a= a ^ b ==> a= (a^b) ^ ((a^b) ^ b) ==> a= (a^b) ^ a ==> a= b
}

int main(){

    int a= 8;
    int b= 13;

    swap(a, b);

    cout<<a<<" "<<b;

    return 0;
}