#include<bits/stdc++.h>
using namespace std;

int squareRoot(int n){

    if(n == 0 || n == 1)    return n;
    
    int left= 1, right= n/2;
    int ans= 0;

    while(left <= right){

        int mid= (left + right)/2;

        if(mid * mid == n){

            ans= mid;
            break;
        }

        if(mid * mid < n){

            ans= mid;
            left= mid+1;
        }

        else    
            right= mid-1;
    } 

    return ans;
}

int main(){

    int num;                // We need to find Floor(sqrt(num)) in O(log₂n)
    cin>>num;

    cout<<squareRoot(num);
    return 0;
}