#include<bits/stdc++.h>
using namespace std;

int searchPosition(vector<int> v, int n, int target){

    int left=0, right=n-1;                      // Search the index to store the target element such that array remains
    int ans=n;                                  // sorted. The elements in array are distinct.

    while(left <= right){

        int mid= (left + right)/2;

        if(v[mid] == target)
            return mid;

        else if(v[mid] > target){

            ans= mid;
            right= mid-1;
        }

        else
            left= mid+1;
    }

    return ans;
}

int main(){

    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0; i<n; i++)
        cin>>v[i];

    int target;
    cin>>target;

    cout<<searchPosition(v, n, target);
    return 0;
}