#include<bits/stdc++.h>
using namespace std;

int lowerBound(vector<int> v, int n, int target){       

    int left=0, right=n-1;                  // LowerBound(target): smallest index i such that arr[i] >= target
    int ans=n;

    while(left <= right){

        int mid=(left + right)/2;

        if(v[mid] >= target){

            ans= mid;
            right= mid-1;
        }

        else
            left= mid+1;
    }

    return ans;
}

int upperBound(vector<int> v, int n, int target){       

    int left=0, right=n-1;                  // UpperBound(target): smallest index i such that arr[i] > target
    int ans=n;

    while(left <= right){

        int mid=(left + right)/2;

        if(v[mid] > target){

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

    cout<<lowerBound(v, n, target)<<endl;
    cout<<upperBound(v, n, target);
    return 0;
}