#include<bits/stdc++.h>
using namespace std;

bool check1(vector<int>& v,int n){              // Brute Method
    vector<int> a=v;
    sort(a.begin(),a.end());
    for(int i=0;i<n;i++){
        int flag=0;
        for(int j=0;j<n;j++){
            if(a[j]!=v[(j+i)%n]){
                flag=1;
                break;
            }
        }
        if(!flag) return true;
    }
    return false;
}

vector<int> getm(vector<int>& v,int n){         // get indices of min. element
    vector<int> ans;
    ans.push_back(0);
    int min=v[0];
    for(int i=1;i<n;i++){
        if(v[i]<min){
            min=v[i];
            ans.clear();
            ans.push_back(i);
        }
        else if(v[i]==min){
            ans.push_back(i);
        }
    }
    return ans;

}

bool check2(vector<int>& v,int n){              // Better Method
    vector<int> a=v;
    sort(a.begin(),a.end());
    vector<int> m=getm(v,n);
    for(auto i:m){
        int flag=0;
        for(int j=0;j<n;j++){
            if(a[j]!=v[(j+i)%n]){
                flag=1;
                break;
            }
        }
        if(!flag) return true;
    }
    return false;
}

bool check3(vector<int>& v,int n){              // Optimal Method
    int i=0;
    for(;i<n-1;i++){
        if(v[i]<=v[i+1]) continue;
        else{
            if(v[0]<v[n-1]) return false;
            break;
        }
    }
    i++;
    for(;i<n-1;i++){
        if(v[i]<=v[i+1]) continue;
        return false;
    }
    return true;
}

bool check4(vector<int>& v,int n){              // Optimal Method
    int ct=0;
    for(int i=0;i<n-1;i++){
        if(v[i]>v[i+1]) ct++;
    }
    if(v[n-1]>v[0]) ct++;

    if(ct>1) return false;
    return true;
}

bool srtd_rtatd(vector<int>& v){
    int n=v.size();
    bool a=check1(v,n);
    a=check2(v,n);
    a=check3(v,n);
    a=check4(v,n);
    return a;
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
    cout<<srtd_rtatd(v);
    return 0;
}