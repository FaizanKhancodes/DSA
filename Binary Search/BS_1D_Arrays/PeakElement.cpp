#include<bits/stdc++.h>
using namespace std;

int Peak(vector<int> v, int n){

    if(n == 1)    
        return 0;
    if(v[0] > v[1])                        // First element is Peak
        return 0;
    if(v[n-1] > v[n-2])                    // Last element is Peak
        return n-1;

    int left=1, right=n-2;                 // Start form these indices to avoid Out_Of_Bound access

    while(left <= right){

        int mid= (left + right)/2;

        if(v[mid-1] < v[mid] && v[mid] > v[mid+1])
            return mid;

        if(v[mid-1] < v[mid])              // Mid is in left part but Peak is in right
            left= mid+1;                   // So eliminate left part

        else                               // Mid is in right part but Peak is in left
            right= mid-1;                  // Eliminate right part
    }

    return -1;
}

int main(){

    int n;
    cin>>n;
    vector<int> v(n);                       // Array contains duplicate elements in sorted fashion
    for(int i=0;i <n; i++)                  // We need to find the Peak element
        cin>>v[i];                          // Peak element: A[i] such that A[i-1] < A[i] AND A[i] > A[i+1]

    cout<<Peak(v, n);
    return 0;
}