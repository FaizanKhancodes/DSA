#include<bits/stdc++.h>
using namespace std;

long long nCr(int n, int r){

    long long result= 1;
    for(int i=0; i< min(r, n-r); i++){
        result*= n - i;
        result/= i + 1;
    }
    return result;
}

void func(int n){

    for(int i=1; i<=n; i++){
        int k=i;
        int m= n-i+1;
        int r= 1;
        for(int j=1; j<2*n; j++){

            if(j <= n - i)
                cout<<"  ";
            
            else if(j == m && k != 0){
                if(k == i || k == 1){
                    cout<<"1 ";
                    k--;
                    m+= 2;
                }
                else{
                    cout<<nCr(i-1, r)<<" ";
                    r++;
                    k--;
                    m+= 2;
                }
            }

            else
                cout<<"  ";
        }
        cout<<endl;
    }
}

void func2(int n){                  // Using DP
    vector<vector<int>> ans;
    for(int i=0; i<n; i++){
        ans.emplace_back();
        for(int j=0; j<=i; j++){
            if(j==0 || j==i)
                ans[i].push_back(1);
            else
                ans[i].push_back(ans[i-1][j-1] + ans[i-1][j]);
        }
    }

    for(auto &row: ans){
        for(auto col: row)
            cout<<col<<" ";
        cout<<endl;
    }
}

vector<int> getRows(int n){
    vector<int> temp;
    long long result=1;             
    temp.push_back(result);
    for(int r=0; r<n; r++){         //  nCr, where 0 <= r <= n
        result*= n-r;               //  nCr= (n/r) * n-1Cr-1 
        result/= r+1;
        temp.push_back(result);
    }
    return temp;
}
void func3(int n){

    vector<vector<int>> ans;
    for(int i=0; i<n; i++)
        ans.push_back(getRows(i));

    for(auto &row: ans){
        for(auto col: row)
            cout<<col<<" ";
        cout<<endl;
    }
}
int main(){

    int n;          // No. of rows of Pascal Triangle
    cin>>n;
    func(n);
    cout<<endl;
    func2(n);
    cout<<endl;
    func3(n);
    return 0;
}