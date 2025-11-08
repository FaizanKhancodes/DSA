#include<bits/stdc++.h>
using namespace std;

// This will give the no. of elements <= mid i.e, target in given row
int upperBound(vector<int> v, int n, int target){

    int left= 0;
    int right= n-1;

    while(left <= right){

        int mid= (left + right)/2;

        if(v[mid] <= target)
            left= mid+1;

        else
            right= mid-1;
    }

    return left;
}

int median(vector<vector<int>> v, int n1, int n2){

    // Range of searching: [min of Matrix, max of Matrix]
    int left= INT_MAX;
    int right= INT_MIN;
    for(int row=0; row<n1; row++){

        // As each row is sorted, so min of Matrix will be in 
        // first column and max of Matrix will be in last column
        left= min(left, v[row][0]);
        right= max(right, v[row][n2-1]);
    }

    // No. of elements before the median position
    int reqCnt= (n1*n2)/2;

    while(left <= right){

        // Mid is possible median element
        int mid= (left + right)/2;

        // Cnt stores the no. of elements in the Matrix which are <= mid
        int cnt= 0;
        for(int row=0; row<n1; row++)
            cnt+= upperBound(v[row], n2, mid);

        // No. of elements <= mid are not enough, so median will be on the right of mid
        if(cnt <= reqCnt)
            left= mid+1;

        // No. of elements <= mid are enough, so median might be on the left of mid
        else
            right= mid-1;
    }

    return left;
}

int main(){

    // n1 x n2 matrix 
    int n1, n2;
    cin>>n1>>n2;

    // Each row of the Matrix is sorted and total no.
    // elements in the Matrix is always odd
    vector<vector<int>> v(n1, vector<int> (n2));
    for(int i=0; i<n1; i++){
        for(int j=0; j<n2; j++)
            cin>>v[i][j];
    }

    // The median of the Matrix
    cout<<median(v, n1, n2);
    return 0;
}