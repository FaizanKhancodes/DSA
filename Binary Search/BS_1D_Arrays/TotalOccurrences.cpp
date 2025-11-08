#include<bits/stdc++.h>
using namespace std;

int firstOccur(vector<int> v, int n, int x){

    int left=0, right=n-1;
    int ans=-1;

    while(left <= right){

        int mid= (left + right)/2;

        if(v[mid] == x){

            ans= mid;
            right= mid-1;
        }

        else if(v[mid] < x)
            left= mid+1;

        else
            right= mid-1;
    }

    return ans;
}

int lastOccur(vector<int> v, int n, int x){

    int left=0, right=n-1;
    int ans=-1;

    while(left <= right){

        int mid= (left + right)/2;

        if(v[mid] == x){

            ans= mid;
            left= mid+1;
        }

        else if(v[mid] < x)
            left= mid+1;

        else
            right= mid-1;
    }

    return ans;
}

int totalOccur(vector<int> v, int n, int x){

    int f= firstOccur(v, n, x);
    if(f == -1) return 0;

    int l= lastOccur(v, n, x);

    return l - f + 1;
}

int main(){

    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0; i<n; i++)
        cin>>v[i];

    int target;
    cin>>target;

    cout<<totalOccur(v, n, target);
    return 0;
}