#include<bits/stdc++.h>
using namespace std;

void brute(vector<vector<int>>& v, int n){

    vector<vector<int>> ans(n, vector<int>(n));

    for(int i=0; i<n; i++){                       // col(j) --> row(j) after rotation
        for(int j=0; j<n; j++)                    // row(i) --> col(n-i-1) after rotation
            ans[j][n-i-1]= v[i][j];               // v[2][3] --> ans[3][n-2-1] after rotation
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++)
            cout<<ans[i][j]<<" ";
        cout<<endl;
    }
}

void optimal(vector<vector<int>>& v, int n){

    for(int i=0; i<n; i++){
        for(int j=i; j<n; j++)                  // Transpose the matrix
            swap(v[i][j],  v[j][i]);
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n/2; j++)                // Reverse the elements of each row
            swap(v[i][j], v[i][n-j-1]);
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++)
            cout<<v[i][j]<<" ";
        cout<<endl;
    }
}
int main(){

    int n;
    cin>>n;
    vector<vector<int>> v;
    for(int i=0; i<n; i++){
        v.emplace_back();
        for(int j=0; j<n; j++){
            int a;
            cin>>a;
            v[i].push_back(a);
        }
    }

    brute(v, n);
    cout<<endl;
    optimal(v, n);
    return 0;
}