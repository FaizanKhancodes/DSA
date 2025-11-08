#include<bits/stdc++.h>
using namespace std;

int Minimum(vector<int> v, int n){

    int left=0;                         // We'll find the sorted part of the array and 
    int right=n-1;                      // then store the minimum of ans and first element of sorted 
    int ans=INT_MAX;                    // part in ans, then eliminate the sorted part

    while(left <= right){

        int mid= (left + right)/2;

        if(v[left] <= v[right]){        // Whole array is sorted

            ans= min(ans, v[left]);     // Store minimum of ans and smallest element of  
            break;                      // array( A[left] ) in ans
        }

        if(v[left] <= v[mid]){          // Left part is sorted( A[left] to A[mid] )

            ans= min(ans, v[left]);     // Store minimum of ans and smallest element of left part 
            left= mid+1;                // of array( A[left] ) in ans and eliminate the left part
        }

        else{                           // Right part is sorted( A[mid] to A[right] ) 

            ans= min(ans, v[mid]);      // Store minimum of ans and smallest element of right part
            right= mid-1;               // of array( A[mid] ) in ans and eliminate the right part
        }

    }

    return ans;
}

int main(){

    int n;
    cin>>n;
    vector<int> v(n);                   // Array contains unique elements in sorted fashion 
    for(int i=0; i<n; i++)              // but rotated at an index
        cin>>v[i];

    cout<<Minimum(v, n);
    return 0;
}