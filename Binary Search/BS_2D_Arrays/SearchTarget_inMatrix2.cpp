#include<bits/stdc++.h>
using namespace std;

bool searchInMatrix(vector<vector<int>> v, int n1, int n2, int target){

    // Start searching from top-right corner of the Matrix
    // The elements before the curr element in the row are sorted in decreasing order
    // The elements below the curr element in the col are sorted in increasing order
    int row= 0;
    int col= n2 - 1;

    while(row < n1 && col >= 0){

        if(v[row][col] == target)
            return 1;

        // Curr element is smaller than target so every element 
        // in the row will also be smaller than target as they are 
        // smaller than current element. Hence, eliminate the row 
        if(v[row][col] < target)
            row++;

        // Curr element is larger than target so every element 
        // in the col will also be larger than target as they are 
        // larger than current element. Hence, eliminate the col
        else    
            col--;
    }

    return false;
}

int main(){

    // n1 x n2 matrix 
    int n1, n2;
    cin>>n1>>n2;

    // Each row of the Matrix is sorted form left to right  
    // Each col of the Matrix is sorted form top to bottom
    vector<vector<int>> v(n1, vector<int> (n2));
    for(int i=0; i<n1; i++){
        for(int j=0; j<n2; j++)
            cin>>v[i][j];
    }

    // Element to be searched in the Matrix
    int target;
    cin>>target;

    // print 1 if target found and print 0 if not found
    cout<<searchInMatrix(v, n1, n2, target);
    return 0;
}