#include<bits/stdc++.h>
using namespace std;

// This will give the index of first occurrence of 1 in given row of matrix
int upperBound(vector<int> v, int n, int target){

    int left= 0, right= n-1;

    while(left <= right){

        int mid= (left + right)/2;

        if(v[mid] <= target)
            left= mid+1;

        else    
            right= mid-1;
    }

    return left;
}

int Max1sRow(vector<vector<int>> v, int n1, int n2){

    int cnt= 0;         // No. of 1s in a given row
    int maxCnt= 0;      // Maximum no. of 1s in the matrix
    int index= -1;      // Row no. with maximum no. of 1s

    for(int i=0; i<n1; i++){

        // Accessing each row and finding the no. of 1s in it
        cnt= n2 - upperBound(v[i], n2, 0);

        if(cnt > maxCnt){

            maxCnt= cnt;
            index= i;
        }
    }

    return index;
}

int main(){

    // n1 x n2 matrix having only 0s and 1s
    int n1, n2;
    cin>>n1>>n2;

    // Each row of the matrix is sorted
    vector<vector<int>> v(n1, vector<int> (n2));
    for(int i=0; i<n1; i++){
        for(int j=0; j<n2; j++)
            cin>>v[i][j];
    }

    // The row no. with maximum no. of 1s
    cout<<Max1sRow(v, n1, n2);
    return 0;
}