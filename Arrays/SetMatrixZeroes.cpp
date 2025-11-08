#include<bits/stdc++.h>
using namespace std;

void markRow(vector<vector<int>>& v, int i, int cols){
    for(int j=0; j<cols; j++){
        if(v[i][j] != 0)
            v[i][j]= -1;                        // Set each element to -1 of the marked row except the 0 element
    }
}
void markCol(vector<vector<int>>& v, int j, int rows){
    for(int i=0; i<rows; i++){
        if(v[i][j] != 0)
            v[i][j]= -1;                        // Set each element to -1 of the marked col except the 0 element
    }
}

void brute(vector<vector<int>> v){

    int rows= v.size();
    int cols= v[0].size();

    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            if(v[i][j] == 0){                  
                markRow(v, i, cols);            // Marking row which has 0 as an element
                markCol(v, j, rows);            // Marking col which has 0 as an element
            }
        }
    }

    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            if(v[i][j] == -1)
                v[i][j]= 0;                     // Set each -1 element to 0 in the matrix
        }
    }

    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }
}

void better(vector<vector<int>> v){

    int rows= v.size();
    int cols= v[0].size();

    vector<int> row(rows, 0);                   // Hash array to mark rows consisting 0
    vector<int> col(cols, 0);                   // Hash array to mark cols consisting 0

    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){

            if(v[i][j] == 0){                   // Mark the rows and cols in hash arrays which consist 0
                row[i]= 1;
                col[j]= 1;
            }
        }
    }

    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){

            if(row[i] || col[j])                // Check if the current element is in marked row or column then set it to 0
                v[i][j]= 0;
        }
    }

    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }
}

void optimal(vector<vector<int>> v){                // 0th row and 0th col will be used to mark the rows and cols consisting 0

    int rows= v.size();
    int cols= v[0].size();
    int col0= 1;                                    // Variable to mark 0th column if it consists 0 as elem(0,0) is common for 0th row and 0th column
    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){

            if(v[i][j] == 0 && j == 0)              // Check if 0th column has any 0 then set col0 to 0 to mark the 0th column
                col0= 0;

            else if(v[i][j] == 0){                  // Check if other rows and columns have any 0 then 
                v[i][0]= 0;                         // mark its row by updating the first element of the same row as 0 and
                v[0][j]= 0;                         // mark its col by updating the first element of the same col as 0
            }
        }
    }

    for(int i=1; i<rows; i++){
        for(int j=1; j<cols; j++){

            if(v[i][0] == 0 || v[0][j] == 0)         // Update the elements of marked rows and cols to 0 apart from elements of hash row and col 
                v[i][j]= 0;
        }
    }

    if(v[0][0] == 0){
        for(int j=1; j<cols; j++)                   // Update elements of hash col (0th row) if ele(0,0) is marked
            v[0][j]= 0;
    }

    if(col0 == 0){
        for(int i=0; i<rows; i++)                   // Update elements of hash row (0th col) if col0 is marked
            v[i][0]= 0;
    }

    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
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

    brute(v);
    cout<<endl;
    better(v);
    cout<<endl;
    optimal(v);
    return 0;
}