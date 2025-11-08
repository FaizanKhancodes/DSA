#include<bits/stdc++.h>
using namespace std;

int singleNumBrute(vector<int> v, int n){

    unordered_map<int, int> mp;

    for(int i: v)
        mp[i]++;

    for(auto itr: mp){

        if(itr.second == 1)
            return itr.first;
    }

    return -1;
}

int singleNumBetter(vector<int> v, int n){

    int ans= 0;

    for(int bitPosn=0; bitPosn<32; bitPosn++){

        int cntBit1= 0;
        int bitCheck= 1 << bitPosn;

        for(int i=0; i<n; i++){

            if(v[i] & bitCheck)
                cntBit1++;
        }

        if(cntBit1 % 3 == 1)
            ans= ans | bitCheck;
    }

    return ans;
}

int singleNumBetter2(vector<int> v, int n){

    sort(v.begin(), v.end());

    for(int i=1; i<n; i= i+3){

        if(v[i] != v[i-1])
            return v[i-1];
    }

    return v[n-1];
}

int singleNumOptimal(vector<int> v, int n){

    int b1= 0;
    int b2= 0;

    for(int i=0; i<n; i++){

        b1= (b1 ^ v[i]) & (~b2);
        b2= (b2 ^ v[i]) & (~b1);
    }

    return b1;
}

int main(){

    int n;
    cin>>n;

    vector<int> v(n);

    for(int i=0; i<n; i++)
        cin>>v[i];

    cout<<singleNumOptimal(v, n);
    
    return 0;
}