#include<bits/stdc++.h>
using namespace std;

void rev_arr(vector<int>& v,int i, int j){
    while(i<j){
        swap(v[i++],v[j--]);
    }
}

void rotate_arr_right1(vector<int>& v,int n, int x){
    rev_arr(v,0,n-1);   //reverse the whole array
    rev_arr(v,0,x-1);   //reverse the first x elements
    rev_arr(v,x,n-1);   //reverse the rest of the elements
}

void rotate_arr_right2(vector<int>& v,int n, int x){
    vector<int> temp;
    for(int i=n-x;i<n;i++){
        temp.push_back(v[i]);
    }

    for(int i=n-x-1;i>=0;i--){
        v[i+x]=v[i];
    }

    for(int i=0;i<x;i++){
        v[i]=temp[i];
    }
}


void rotate_arr_left1(vector<int>& v,int n,int x){
    rev_arr(v,0,x-1);   //reverse the first x elements
    rev_arr(v,x,n-1);   //reverse the rest of the elements
    rev_arr(v,0,n-1);   //reverse the whole array
}

void rotate_arr_left2(vector<int>& v,int n, int x){
    vector<int> temp;
    for(int i=0;i<x;i++){
        temp.push_back(v[i]);
    }

    for(int i=x;i<n;i++){
        v[i-x]=v[i];
    }

    for(int i=n-x;i<n;i++){
        v[i]=temp[i-n+x];
    }
}

int main(){

    int n;
    cin>>n;
    vector<int> v;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        v.push_back(a);
    }

    int x;  //number of steps to be rotated
    cin>>x;

    rotate_arr_right2(v,n,x);
    for(auto i:v){
        cout<<i<<" ";
    }
    cout<<endl;

    sort(v.begin(),v.end());

    rotate_arr_left2(v,n,x);
    for(int i:v){
        cout<<i<<" ";
    }
    return 0;
}