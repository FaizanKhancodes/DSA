#include<bits/stdc++.h>
using namespace std;

int bs(vector<int> v, int n, int target){

    int left=0, right=n-1;

    while(left <= right){

        int mid= (left + right)/2;

        if(v[mid] == target)
            return mid;

        else if(v[mid] < target)
            left= mid+1;

        else    
            right= mid-1;
    }

    return -1;
}

int main(){
    
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0; i<n; i++)
        cin>>v[i];

    int target;
    cin>>target;

    cout<<bs(v, n, target);
    return 0;
}