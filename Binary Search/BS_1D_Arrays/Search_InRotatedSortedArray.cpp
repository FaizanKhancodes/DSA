#include<bits/stdc++.h>
using namespace std;

int Search(vector<int> v, int n, int x){

    int left=0, right=n-1;                      // We can't elminate left or right part directly as the array is rotated
    while(left <= right){                       // so we'll first find the sorted part then check for target in that part

        int mid= (left + right)/2;

        if(v[mid] == x)                       
            return mid;                       

        else if(v[left] <= v[mid]){             // Checking if left part is sorted

            if(v[left] <= x && x <=  v[mid])    // Checking if target is in left part i.e., A[left]<= x <=A[mid]
                right= mid-1;
            
            else
                left= mid+1;
        }

        else                                    // Right part is sorted

            if(v[mid] <= x && x <= v[right])    // Checking if target is in right part i.e., A[mid]<= x <=A[right]
                left= mid+1;

            else
                right= mid-1;
    }

    return -1;
}

int main(){

    int n;
    cin>>n;
    vector<int> v(n);                           // The array contains distinct elements in sorted fashion
    for(int i=0; i<n; i++)                      // but the array is rotated at a particular index
        cin>>v[i];

    int target;
    cin>>target;

    cout<<Search(v, n, target);
    return 0;
}