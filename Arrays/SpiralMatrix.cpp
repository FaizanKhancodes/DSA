#include<bits/stdc++.h>
using namespace std;

void spiral(vector<vector<int>> v){

    int m= v.size();            // No.of rows in matrix
    int n= v[0].size();         // No.of cols in matrix

    int top= 0, bottom= m-1;    // first and last row
    int left= 0, right= n-1;    // first and last col

    while(top <= bottom && left <= right){  // Checking for valid row and col 

        for(int i=left; i<=right; i++)      // Traversing in row pointed by top; left --> right
            cout<<v[top][i]<<" ";
        top++;                              // Changing row pointed by top; moving 1 row down

        for(int i=top; i<=bottom; i++)      // Traversing in col pointed by right; top --> bottom
            cout<<v[i][right]<<" ";
        right--;                            // Changing col pointed by right; moving 1 col back


        if(top <= bottom){                  // Checking for valid row before traversing it as we've changed row before by " top++ "

            for(int i=right; i>=left; i--)  // Traversing in row pointed by bottom; right --> left
                cout<<v[bottom][i]<<" ";
            bottom--;                       // Changing row pointed by bottom; moving 1 row up
        }


        if(left <= right){                  // Checking for valid col before traversing it as we've changed col before by " right-- "

            for(int i=bottom; i>=top; i--)  // Traversing in col pointed by left; bottom --> top
                cout<<v[i][left]<<" ";
            left++;                         // Changing col pointed by left; moving 1 col forward
        }

        // We'll check for valid row and col in while loop condition before the next iteration as we've changed row and col 
        // before by " bottom-- " and " left++ "
    }
}

int main(){

    int rows, cols;
    cin>>rows>>cols;
    vector<vector<int>> v;
    for(int i=0; i<rows; i++){
        v.emplace_back();
        for(int j=0; j<cols; j++){
            int a;
            cin>>a;
            v[i].push_back(a);
        }
    }

    spiral(v);
    return 0;
}