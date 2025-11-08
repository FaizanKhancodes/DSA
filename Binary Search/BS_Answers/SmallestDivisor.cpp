#include<bits/stdc++.h>
using namespace std;

int getSum(vector<int> v, int d){

    int divSum= 0;

    for(auto i: v)
        divSum+= ceil((double)i/d);

    return divSum;
}

int smallestDivisor(vector<int> v, int n, int threshold){
    
    int left= 1;                                        // Range of searching [1 - max Dividend]
    int right= *max_element(v.begin(), v.end());        // Σ(v[i]/a) = n where a is max Dividend
    int minDivisor= right;

    while(left <= right){

        long long mid= (left + right)/2;                // Selected Divisor d
        int divSum= getSum(v, mid);                     // Sum of Quotients; Σ(v[i]/d) 

        if(divSum <= threshold){

            minDivisor= mid;
            right= mid-1;
        }

        else    
            left= mid+1;
    }

    return minDivisor;
}

int main(){

    int n;                                      // No. of elements(Dividend)
    cin>>n;
    vector<int> v(n);                           // v[i] >= 1
    for(int i=0; i<n; i++)
        cin>>v[i];

    int threshold;                              // n <= threshold
    cin>>threshold;

    cout<<smallestDivisor(v, n, threshold);     // We need to find smallest +ve Divisor d such that Σ⌈ v[i]/d ⌉ <= threshold 
    return 0;                               
}