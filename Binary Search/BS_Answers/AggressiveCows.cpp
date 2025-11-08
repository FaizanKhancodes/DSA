#include<bits/stdc++.h>
using namespace std;

bool possible(vector<int> stalls, int n, int distance, int cows){

    int cowCnt= 1;                                  // To count the no. of cows placed so far
    int lastPlaced= stalls[0];                      // Stall position of newly placed cow

    for(int i=1; i<n; i++){

        if(stalls[i] - lastPlaced >= distance){     // Distance between 2 adjacent cows is not less than curr min. distance

            cowCnt++;                               // New cow placed at a stall
            lastPlaced= stalls[i];                  // Stall position on which the cow is placed
        }

        if(cowCnt == cows)  return true;            // All the cows are placed
    }

    return false;                                   // Can't place cows with curr min. distance
}

int getLeft(vector<int> v, int n){

    int left= v[1] - v[0];

    for(int i=2; i<n; i++)
        left= min(left, v[i]-v[i-1]);   

    return left;
}

int findDistance(vector<int> stalls, int n, int cows){

    sort(stalls.begin(), stalls.end());

    int left= getLeft(stalls, n);                       // min. distance between any 2 stalls
    int right= stalls[n-1] - stalls[0];                 // max. distance between any 2 stalls

    while(left <= right){

        int mid= (left + right)/2;                      // mid is curr min. distance to check

        if(possible(stalls, n, mid, cows) == true)      // cows can be placed with mid as curr min. distance
            left= mid+1;                                // eliminate left part as we need distance greater than mid

        else
            right= mid-1;                               // cows can't be placed, find distance smaller than mid
    }
}

int main(){

    int n;                              // 2 <= n
    cin>>n;
    vector<int> v(n);                   // v[i] is the position of iᵗʰ stall
    for(int i=0; i<n; i++)  
        cin>>v[i];

    int k;                              // 2 <= k <= n
    cin>>k;                             // k is no. of cows

    cout<<findDistance(v, n, k);        // We need to find the min. distance between any 2 placed cows such that it max. possible
    return 0;
}