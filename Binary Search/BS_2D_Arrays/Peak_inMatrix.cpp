#include<bits/stdc++.h>
using namespace std;

// This will give the row no. of maximum element in the given column
int findRow(vector<vector<int>> v, int n1, int col){

    int maxElem= INT_MIN;
    int index= -1;

    for(int row=0; row<n1; row++){

        if(v[row][col] > maxElem){

            maxElem= v[row][col];
            index= row;
        }
    }

    return index;
}

pair<int, int> peak(vector<vector<int>> v, int n1, int n2){

    // Range of searching: [first col, last col]
    int left= 0;
    int right= n2 - 1;

    while(left <= right){

        // Col no. mid
        int mid= (left + right)/2;

        // Row no. of the maximum element in col no. mid
        int index= findRow(v, n1, mid);

        // Maximum element of col no. mid is possible peak element
        int peak= v[index][mid];

        // Element on the left of possible peak
        int before= mid-1 >= 0? v[index][mid-1]: -1;

        // Element on the right of possible peak
        int after= mid+1 < n2? v[index][mid+1]: -1;

        // Possible peak is actual peak
        if(before < peak && peak > after)
            return {index, mid};

        // Possible peak is present in the columns after the col no. mid
        // so eliminate the columns before the col no. mid
        if(peak < after)
            left= mid+1;

        // Possible peak is present in the columns before the col no. mid
        // so eliminate the columns after the col no. mid
        else
            right= mid-1;
    }

    return {-1, -1};
}

int main(){

    // n1 x n2 matrix 
    int n1, n2;
    cin>>n1>>n2;

    // No two adjacent elements are equal in the Matrix
    vector<vector<int>> v(n1, vector<int> (n2));
    for(int i=0; i<n1; i++){
        for(int j=0; j<n2; j++)
            cin>>v[i][j];
    }

    // row no. and col no. of peak element
    pair <int, int> ans= peak(v, n1, n2);
    cout<<ans.first<<" "<<ans.second;
    return 0;
}