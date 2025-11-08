#include<bits/stdc++.h>
using namespace std;

int getTime(vector<int> v, int k, int h){

    int reqTIme= 0;

    for(auto i: v){

        reqTIme+= ceil((double)i/k);

        if(reqTIme > h)     return reqTIme;
    }

    return reqTIme;
}

// Learn to do this without ans varible(k in this case) using 
// concept of opposite polarity     [Timestamp => 15:50]

int minSpeed(vector<int> v, int h){

    int left= 1;                                    // The min. speed is in the range [left - right] 
    int right= *max_element(v.begin(), v.end());
    int k= right;                                   // min. speed

    while(left <= right){

        long long mid= (left + right)/2;
        int reqTime= getTime(v, mid, h);            // Time taken to eat at current speed mid

        if(reqTime <= h){

            k= mid;                                 // Potential speed
            right= mid-1;
        }

        else    
            left= mid+1;
    }

    return k;
}

int main(){

    int n;                          // The number of piles of Bananas
    cin>>n;
    vector<int> piles(n);           // piles[i] is the no. of bananas in ith pile
    for(int i=0; i<n; i++)
        cin>>piles[i];

    int h;                          // Max. time to eat the Bananas; n <= h
    cin>>h;

    cout<<minSpeed(piles, h);       // Min speed to eat all the Bananas within h hours
    return 0;
}