// Majority Element in an unsorted array; Element which appears more than n/3 times
// Maximum 2 majority elements can be there in any array

#include<bits/stdc++.h>
using namespace std;

void brute(vector<int> v, int n){

    set<int> st;
    for(int i=0; i<n; i++){
        int elem= v[i];
        int cnt= 0;
        for(int j=0; j<n; j++){
            if(elem == v[j])
                cnt++;
        }
        if(cnt > n/3)
            st.insert(elem);
    }
    for(auto i: st)
        cout<<i<<" ";
}

void better(vector<int> v, int n){

    map<int, int> mp;
    for(int i=0; i<n; i++)
        mp[v[i]]++;
    
    for(auto i:mp){
        if(i.second > n/3)
            cout<<i.first<<" ";
    }
    
}

void optimal(vector<int> v, int n){

    int elem1=0, elem2=0;
    int cnt1=0, cnt2=0;

    for(int i=0; i<n; i++){

        if(cnt1==0 && v[i]!=elem2){

            elem1=v[i];
            cnt1+=1;
        }

        else if(cnt2==0 && v[i]!=elem1){

            elem2=v[i];
            cnt2+=1;
        }

        else if(elem1==v[i])
            cnt1++;

        else if(elem2==v[i])
            cnt2++;

        else{

            cnt1--;
            cnt2--;
        }
    }

    cnt1=0, cnt2=0;
    for(int i=0; i<n; i++){

        if(v[i]==elem1)
            cnt1++;
        
        else if(v[i]==elem2)
            cnt2++;
    }

    if(cnt1 > n/3)
        cout<<elem1<<" ";
    if(cnt2 > n/3)
        cout<<elem2;
}
int main(){

    int n;          //  Size of the input array
    cin>>n;
    vector<int> v(n);
    for(int i=0; i<n; i++)
        cin>>v[i];

    brute(v,n);
    cout<<endl;
    better(v,n);
    cout<<endl;
    optimal(v,n);
    return 0;
}