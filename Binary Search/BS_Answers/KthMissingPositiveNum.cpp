#include<bits/stdc++.h>
using namespace std;

int KthMissingNum(vector<int> v, int n, int k){

    int left= 0;
    int right= n-1;

    while (left <= right){

        int mid= (left + right)/2;
        int missing= v[mid] - (mid+1);

        if(missing < k)
            left= mid+1;

        else    
            right= mid-1;
    }

    return k + left;
    
}

int main(){

    int n;                      // No. of elements
    cin>>n;
    vector<int> v(n);           // Sorted array of distinct +ve integers
    for(int i=0; i<n; i++)
        cin>>v[i];

    int k;                      // Position of Missing integer; 1 2 3 4 ....
    cin>>k;

    cout<<KthMissingNum(v, n, k);       
    return 0;
}