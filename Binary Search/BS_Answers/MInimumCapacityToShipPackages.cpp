#include<bits/stdc++.h>
using namespace std;

int getDays(vector<int> v, int n, int capacity){

    int reqDays= 0;
    int weightSum= 0;
    
    for(int i=0; i<n; i++){

        weightSum+= v[i];

        if(weightSum > capacity){

            reqDays++;
            weightSum= v[i];
        }
    }
    reqDays++;

    return reqDays;
}

int CapacityToShip(vector<int> v, int n, int days){
    
    int left= *max_element(v.begin(), v.end());         // Range of searching [max. weight of package - sum of weights of packages]
    int right= accumulate(v.begin(), v.end(), 0);       
    int minCapacity= right;

    while(left <= right){

        long long mid= (left + right)/2;                // Selected Capacity 
        int reqDays= getDays(v, n, mid);                // Days required to ship packages with Capacity mid

        if(reqDays <= days){

            minCapacity= mid;
            right= mid-1;
        }

        else    
            left= mid+1;
    }

    return minCapacity;
}

int main(){

    int n;                                      // No. of packages
    cin>>n;
    vector<int> v(n);                           // v[i] is the weight of iᵗʰ package
    for(int i=0; i<n; i++)
        cin>>v[i];

    int days;                                   // days <= n
    cin>>days;

    cout<<CapacityToShip(v, n, days);           // We need to find min. capacity of a belt to ship packages in given days 
    return 0;                               
}