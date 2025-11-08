#include<bits/stdc++.h>
using namespace std;

vector<int> brute(vector<int> v, int n){

    int pos[n/2];                               // Array for positive numbers
    int neg[n/2];                               // Array for negative numbers
    int PosIndex=0, NegIndex=0;                 // Pointer for both arrays

    for(auto i: v){
        if(i > 0)
            pos[PosIndex++]= i;

        else
            neg[NegIndex++]= i;
    }

    for(int i=0; i<n/2; i++){
        v[2*i]= pos[i];
        v[2*i+1]= neg[i];
    }

    return v;
}

vector<int> optimal(vector<int> v, int n){

    vector<int> ans(n);                     // List to store elements after rearranging
    int PosIndex=0;                         // Pointer for positive elements
    int NegIndex=1;                         // Pointer for negative elements

    for(int i=0; i<n; i++){
        if(v[i] > 0){
            ans[PosIndex]= v[i];
            PosIndex+=2;
        }

        else{
            ans[NegIndex]= v[i];
            NegIndex+=2;
        }
    }

    return ans;
}

int main(){

    int n;              // size of input array
    cin>>n;
    vector<int> v;
    for(int i=0; i<n; i++){
        int a;
        cin>>a;
        v.push_back(a);
    }

    vector<int> ans1= brute(v, n);
    for(auto i: ans1)
        cout<<i<<" ";
    cout<<endl;

    vector<int> ans2= optimal(v, n);
    for(auto i: ans2)
        cout<<i<<" ";

    return 0;
}