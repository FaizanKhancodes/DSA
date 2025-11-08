#include<bits/stdc++.h>
using namespace std;

int Single(vector<int> v, int n){

    if(n == 1)
        return v[0];
    if(v[0] != v[1])                    // First element is single element
        return v[0];
    if(v[n-1] != v[n-2])                // Second element is single element
        return v[n-1];  
        
    int left=1, right=n-2;              // Start form these indices to avoid Out-Of-Bound access

    while(left <= right){

        int mid= (left + right)/2;

        if(v[mid-1] != v[mid] && v[mid] != v[mid+1])        // Single element
            return v[mid];

        if(((mid % 2 == 1) && (v[mid-1] == v[mid])) || ((mid % 2 == 0) && (v[mid] == v[mid+1])))
            left= mid+1;

        else    
            right= mid-1;
    }

    return -1;
}

int main(){

    int n;
    cin>>n;
    vector<int> v(n);                   // Array contains elements in sorted fashion with every element
    for(int i=0; i<n; i++)              // present twice except for one element which is present only once
        cin>>v[i];                      // Find that single element

    cout<<Single(v, n);
    return 0;
}