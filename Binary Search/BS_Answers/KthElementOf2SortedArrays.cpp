#include<bits/stdc++.h>
using namespace std;

// Total no. of elements before the partition are k, so after findind the correct partition 
// we can find the max element on the left of partition and that will be the kth element 

int KthElement(vector<int> v1, vector<int> v2, int n1, int n2, int k){

    if(n1 > n2)    return KthElement(v2, v1, n2, n1, k);

    // [max(0, k-n2), min(k, n1)] => Range of no. of elements to be selected from array1 before the partition
    int left= max(0, k-n2);
    int right= min(k, n1);

    while(left<= right){

        // no. of elements to be selected from array1 and array2
        int mid1= (left + right)/2;
        int mid2= k - mid1;

        // l1 and l2 are the Last elements to be selected out of mid1 and mid2 
        // no. of elements from array1 and array2 respectively 
        int l1= (mid1==0 ? INT_MIN : l1= v1[mid1-1]);
        int l2= (mid2==0 ? INT_MIN : l2= v2[mid2-1]);

        // r1 and r2 are the first elements from the array1 
        // and array2 respectively after partition
        int r1= (mid1>=n1 ? INT_MAX : r1= v1[mid1]);
        int r2= (mid2>=n2 ? INT_MAX : r2= v2[mid2]);

        // The partition is corrrect
        if(l1 <= r2 && l2 <= r1)
            return max(l1, l2);

        // More elements have been selected from array1, so we need less from array1
        if(l1 > r2)
            right= mid1-1;

        // More elements have been selected from array2, so we need more from array1
        else
            left= mid1+1;
    }

    return 0;
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

    int k;
    cin>>k;

    // kth element after combining and sorting the 2 arrays
    cout<<KthElement(v1, v2, n1, n2, k);
    
    return 0;
}