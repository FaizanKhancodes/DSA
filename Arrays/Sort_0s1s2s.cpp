#include<bits/stdc++.h>
using namespace std;

void brute(vector<int>& v, int n){

    int cnt0=0, cnt1=0, cnt2=0;
    for(int i=0; i<n; i++){
        if(v[i] == 0)
            cnt0++;

        else if(v[i] == 1)
            cnt1++;

        else    
            cnt2++;
    }

    for(int i=0; i<n; i++){
        if(cnt0 != 0){
            cnt0--;
            v[i]= 0;
        }

        else if(cnt1 != 0){
            cnt1--;
            v[i]= 1;
        }

        else
            v[i]= 2;
    }
}

void optimal(vector<int>& v, int n){
    int low=0, mid=0, high= n-1;
    while(mid < high){
        if(v[mid] == 0){
            swap(v[low], v[mid]);
            mid++;
            low++;
        }

        else if(v[mid] == 1){
            mid++;
        }

        else{
            swap(v[mid], v[high]);
            high--;
        }

    }
}

int main(){

    int n;
    cin>>n;
    vector<int> v1;
    vector<int> v2;
    for(int i=0; i<n; i++){
        int a;
        cin>>a;
        v1.push_back(a);
        v2.push_back(a);
    }

    brute(v1, n);
    for(auto i: v1){
        cout<<i<<" ";
    }
    cout<<endl;

    optimal(v2, n);
    for(auto i: v2){
        cout<<i<<" ";
    }

    return 0;
}