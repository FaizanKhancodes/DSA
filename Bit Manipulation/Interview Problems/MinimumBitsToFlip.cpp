#include<bits/stdc++.h>
using namespace std;

int minimumBitsToFlip(int start, int goal){

    int ans= start ^ goal;
    int count= 0;

    while(ans){

        count++;
        ans= ans & (ans - 1);
    }
    
    return count;
}

int main(){

    int start, goal;
    cin>>start>>goal;

    cout<<minimumBitsToFlip(start, goal);

    return 0;
}