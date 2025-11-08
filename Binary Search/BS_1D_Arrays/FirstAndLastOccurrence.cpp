#include<bits/stdc++.h>
using namespace std;

int firstOccur(vector<int> v, int n, int x){

    int left=0, right= n-1;
    int ans= -1;

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

    int left=0, right= n-1;
    int ans= -1;

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

int main(){

    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0; i<n; i++)
        cin>>v[i];

    int target;
    cin>>target;

    cout<<firstOccur(v, n, target)<<" "<<lastOccur(v, n, target);
    return 0;
}