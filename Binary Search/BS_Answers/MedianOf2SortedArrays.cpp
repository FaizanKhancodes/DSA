#include<bits/stdc++.h>
using namespace std;

double Median(vector<int> v1, vector<int> v2, int n1, int n2){

    // we need array1 to be smaller always
    if(n1 > n2)
        return Median(v2, v1, n2, n1);

    // Total elements
    int n= n1 + n2;

    // No. of elements before the median partition
    int totalPick= (n1 + n2 + 1)/2;

    // [0, n1] => Range of no. of elements to be selected from array1 before the partition
    int left= 0;
    int right= n1;
    

    while(left <= right){

        // no. of elements to be selected from array1 and array2
        int mid1= (left +right)/2;
        int mid2= totalPick - mid1;

        int l1= INT_MIN, l2= INT_MIN;
        int r1= INT_MAX, r2= INT_MAX;

        // l1 is Last element to be selected out of mid1 no. of elements from array1 
        if(mid1-1 >= 0)   l1= v1[mid1-1];

        // l2 is Last element to be selected out of mid2 no. of elements from array2 
        if(mid2-1 >= 0)   l2= v2[mid2-1];

        // r1 is first element from the array1 after partition
        if(mid1 < n1)     r1= v1[mid1];

        // r2 is first element from the array2 after partitioin
        if(mid2 < n2)     r2= v2[mid2];

        // The partition is correct
        if(l1 <= r2 && l2 <= r1){

            if(n%2 == 1)    return max(l1, l2);

            return (double)(max(l1,l2) + min(r1, r2))/2.0;
        }

        // More elements have been selected from array1, so we need less from array1
        else if(l1 > r2)    
            right= mid1-1;

        // More elements have been selected from array2, so we need more from array1
        else    
            left= mid1+1;
    }

    return 1;
}

int main(){

    // no. of elements in array1 and array2
    int n1, n2;
    cin>>n1>>n2;

    // both arrays contain +ve integers in sorted order
    vector<int> v1(n1);
    vector<int> v2(n2);
    for(int i=0; i<n1; i++)
        cin>>v1[i];
    for(int i=0; i<n2; i++)
        cin>>v2[i];

    // Median of elements after combining and sorting the 2 arrays
    cout<<Median(v1, v2, n1, n2);
    
    return 0;
}