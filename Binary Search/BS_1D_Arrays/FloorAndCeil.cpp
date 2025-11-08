#include<bits/stdc++.h>
using namespace std;

int findCeil(vector<int> v, int n, int target){

    int left=0, right=n-1;              // Ceil(x): Largest no m such that m <= x
    int ans= -1;

    while(left <= right){

        int mid= (left + right)/2;

        if(v[mid] == target)
            return v[mid];

        else if(v[mid] < target)
            left= mid+1;

        else{

            ans= v[mid];
            right= mid-1;
        }
    }

    return ans;
}

int findFloor(vector<int> v, int n, int target){

    int left= 0, right= n-1;              // Floor(x): Smallest no m such that m >= x
    int ans= -1;

    while(left <= right){

        int mid= (left + right)/2;

        if(v[mid] == target)
            return v[mid];

        else if(v[mid] > target)
            right= mid-1;

        else{

            ans= v[mid];
            left= mid+1;
        }
    }

    return ans;
}

int main(){

    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0; i<n; i++)
        cin>>v[i];

    int target;
    cin>>target;

    int floor= findFloor(v, n, target);
    int ceil= findCeil(v, n, target);

    cout<<floor<<" ";
    cout<<ceil;
    return 0;
}