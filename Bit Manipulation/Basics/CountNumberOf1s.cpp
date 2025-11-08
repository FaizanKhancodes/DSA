#include<bits/stdc++.h>
using namespace std;

void countNumberOf1s(int num){

    int count= 0;

    while(num){

        count++;
        num= num & (num - 1);
    }

    cout<<count;
}

int main(){

    int num;
    cin>>num;

    countNumberOf1s(num);

    return 0;
}