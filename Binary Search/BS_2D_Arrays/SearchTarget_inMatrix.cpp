#include<bits/stdc++.h>
using namespace std;

// We'll hypothetically flatten the matrix into a 1D array such that the array 
// is sorted. Then we can apply binary search on the 1D array by finding mid
// but we have to convert mid from 1D index to its equivalent 2D index
bool searchInMatrix(vector<vector<int>> v, int n1, int n2, int target){

    // Range of searching: [0, totalElements -1]
    int left= 0;
    int right= (n1*n2) - 1;

    while(left <= right){

        // Mid is index of 1D array
        int mid= (left + right)/2;

        int row= mid/n2;        // This is row no. of the element at index mid
        int col= mid%n2;        // This is col no. of the element at index mid

        if(v[row][col] == target)
            return true;

        if(v[row][col] < target)
            left= mid+1;

        else
            right= mid-1;
    }

    return false;
}

int main(){

    // n1 x n2 matrix having elements in a row in sorted order
    int n1, n2;
    cin>>n1>>n2;

    // The first element of each row is greater than 
    // the last element of the previous row
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