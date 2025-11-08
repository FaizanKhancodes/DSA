#include<bits/stdc++.h>
using namespace std;

vector<int> union_vec(vector<int>& x, vector<int>& y){
    vector<int> ans;
    int n=x.size();
    int m=y.size();
    int i=0,j=0;

    while(i<n && j<m){
        if(x[i]<y[j]) ans.push_back(x[i++]);

        else if(x[i]>y[j]) ans.push_back(y[j++]);

        else{
            ans.push_back(x[i++]);
            j++;
        }
    }
    while(i<n) ans.push_back(x[i++]);

    while(j<m) ans.push_back(y[j++]);

    ans.erase(unique(ans.begin(),ans.end()),ans.end());
    return ans;
}

int main(){

    int n,m;
    cin>>n>>m;

    vector<int> x(n),y(m);
    for(int i=0;i<n;i++){
        cin>>x[i];
    }
    for(int i=0;i<m;i++){
        cin>>y[i];
    }

    vector<int> z=union_vec(x,y);
    for(int i:z){
        cout<<i<<" ";
    }
    return 0;
}