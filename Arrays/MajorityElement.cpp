#include<bits/stdc++.h>
using namespace std;

int majority1(vector<int> v, int size){

    for(int i=0; i<size; i++){
        int count=0;
        for(int j=0; j<size; j++){
            if(v[i] == v[j])
                count++;
        }

        if(count > size/2)
            return v[i];
    }

    return -1;
}

int majority2(vector<int> v, int size){

    unordered_map<int, int> mp;
    for(auto i:v){
        mp[i]++;
        if(mp[i] > size/2)
            return i;
    }

    return -1;
}

int majority3(vector<int> v, int size){         // Moore's Voting Algoritm

    int frq= 0;
    int MajorityElement;
    for(int i=0; i<size; i++){
        if(frq == 0){
            MajorityElement= v[i];
            frq= 1;
        }

        else if(v[i] == MajorityElement)
            frq++;
        
        else
            frq--;
    }

    int count=0;
    for(int i=0; i<size; i++){
        if(MajorityElement == v[i])
            count++;
    }
    if(count > size/2)
        return MajorityElement;

    return -1;
}
int main(){

    int size;
    cin>>size;
    vector<int> v;

    for(int i=0; i<size; i++){
        int a;
        cin>>a;
        v.push_back(a);
    }

    int brute= majority1(v, size);
    cout<<brute<<endl;

    int better= majority2(v, size);
    cout<<better<<endl;

    int optimal= majority3(v, size);
    cout<<optimal;

    return 0;
}