#include<bits/stdc++.h>
using namespace std;

pair<int, int> singleNum(vector<int> v, int n){
    
    int b0= 0;
    int b1= 0;
    int XOR= 0;

    for(int num: v)
        XOR= XOR ^ num;
    
    XOR= (XOR & (XOR - 1)) ^ XOR;

    for(int num: v){

        if(num & XOR)
            b1= b1 ^ num;

        else
            b0= b0 ^ num;
    }

    return {b0, b1};
}

int main(){

    int n;
    cin>>n;

    vector<int> v(n);

    for(int i=0; i<n; i++)
        cin>>v[i];

    pair<int, int> ans= singleNum(v, n);

    cout<<ans.first<<" "<<ans.second;

    return 0;
}