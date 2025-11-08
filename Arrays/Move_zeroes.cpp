#include<bits/stdc++.h>
using namespace std;

void move_zeroes(vector<int>& v,int n){
    int i=0;
    for(int j=0;j<n;j++){
        if(v[j]!=0){
            swap(v[i],v[j]);
            i++;
        }
    }

}

int main(){

    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }

    move_zeroes(v, n);

    for(auto i:v){
        cout<<i<<" ";
    }

    return 0;
}