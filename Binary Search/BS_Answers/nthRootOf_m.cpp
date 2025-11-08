#include<bits/stdc++.h>
using namespace std;

int power(long long mid, int n, int m){

    long long ans= 1;   

    while(n > 0){

        if(n % 2 == 1){

            ans*= mid;
            n-= 1;

            if(ans > m)     return 2;
        }

        else{

            mid*= mid;
            n/= 2;

            if(mid > m)     return 2;
        }
    }

    if(ans == m)    return 1;           // ans = pow(mid, n) 

    return 0;
}

int nthRoot(int n, int m){

    int left=0, right=m;

    while(left <= right){

        long long mid= (left + right)/2;
        int x= power(mid, n, m);         

        if(x == 1)  return mid;         // return 1 if pow(mid, n) == m that is, mid == ⁿ√m
        if(x == 0)  left= mid+1;        // return 0 if pow(mid, n) < m that is, mid < ⁿ√m
        else    right= mid-1;           // return 2 if pow(mid, m) > m that is, mid > ⁿ√m
    }

    return -1;
}

int main(){

    int n, m;           // We need to find ⁿ√m, otherwise print -1
    cin>>n>>m;

    cout<<nthRoot(n, m);
    return 0;
}