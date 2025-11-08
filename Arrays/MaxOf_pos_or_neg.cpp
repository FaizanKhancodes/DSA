#include<bits/stdc++.h>
using namespace std;

int last_neg(vector<int>& v,int n){
    int i=0, j=n-1;
    int mid=i + (j-i)/2;
    while(i<=j){
        if(v[mid]<0 && v[mid+1]>=0) return mid;
        else if(v[mid]<0) i=mid+1;
        else j=mid-1;
        mid= i + (j-i)/2;
    }
    return -1;
}

int first_pos(vector<int>& v,int n){
    int i=0, j=n-1;
    int mid=i + (j-i)/2;
    while(i<=j){
        if(v[mid]>0 && v[mid-1]<=0) return mid;
        else if(v[mid]>0) j=mid-1;
        else i=mid+1;
        mid= i + (j-i)/2;
    }
    return n; 
}
int main(){

    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    
    // If all numbers are negative
    if (v[n-1] < 0) {
        cout << "count of negative numbers: " << n;
        return 0;
    }

    // If all numbers are positive
    if (v[0] > 0) {
        cout << "count of positive numbers: " << n;
        return 0;
    }

    //If all numbers are zero
    if(v[0]==0 && v[n-1]==0){
        cout<<"both are equal in count, i.e. "<<0;
        return 0;
    }

    // Find last negative number index and first positive number index
    int count_neg = last_neg(v, n) + 1;
    int count_pos = n - first_pos(v, n);

    if (count_neg > count_pos) {
        cout << "count of negative numbers: " << count_neg;
    } else if (count_neg < count_pos) {
        cout << "count of positive numbers: " << count_pos;
    } else {
        cout << "both are equal in count, i.e. " << count_neg;
    }

    return 0;
}