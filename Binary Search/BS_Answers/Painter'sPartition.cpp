// Similar to the problem 'Allocate books'

#include<bits/stdc++.h>
using namespace std;

int paintersNeeded(vector<int> v, int n, int maxArea){

    int painterCnt= 1;
    int areaAllocated= 0;

    for(int i=0; i<n; i++){

        if(areaAllocated + v[i] <= maxArea)
            areaAllocated+= v[i];

        else{

            painterCnt++;
            areaAllocated= v[i];
        }
    }

    return painterCnt;
}

int minPossibleTime(vector<int> v, int n, int k){

    if(n < k)   return -1;
    if(n == k)  return *max_element(v.begin(), v.end());
    if(k == 1)  return accumulate(v.begin(), v.end(), 0);

    int left= *max_element(v.begin(), v.end());
    int right= accumulate(v.begin(), v.end(), 0);

    while(left <= right){

        int mid= (left + right)/2;

        if(paintersNeeded(v, n, mid) > k)
            left= mid+1;

        else    
            right= mid-1;
    }

    return left;
}

int main(){

    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0; i<n; i++)
        cin>>v[i];

    int k;
    cin>>k;

    cout<<minPossibleTime(v, n, k);
    return 0;
}