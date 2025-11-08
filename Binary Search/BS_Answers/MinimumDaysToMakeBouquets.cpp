#include<bits/stdc++.h>
using namespace std;

int getBouquets(vector<int> v, int n, int waitDays, int k){

    int bouquetCnt= 0;
    int cnt= 0;

    for(int i=0; i<n; i++){

        if(v[i] <= waitDays)
            cnt++;
            
        else    
            cnt= 0;

        if(cnt == k){

            bouquetCnt++;
            cnt= 0;
        }
    }

    return bouquetCnt;
}

int minimumDays(vector<int> v, int n, int m, int k){

    if(n < (long long)m*k)  return -1;
    
    int left= *min_element(v.begin(), v.end());         // Range of searching [min blooming day - max blooming day]
    int right= *max_element(v.begin(), v.end());
    int minDays= right;

    while(left <= right){

        long long mid= (left + right)/2;                // No. of days to wait; waitDays
        int bouquetCnt= getBouquets(v, n, mid, k);      // No. of Bouquets that can be made within mid waitDays 

        if(bouquetCnt >= m){

            minDays= mid;
            right= mid-1;
        }

        else    
            left= mid+1;
    }

    return minDays;
}

int main(){

    int n;                          // No. of flowers
    cin>>n;
    vector<int> v(n);               // iᵗʰ element is the blooming day flower i

    for(int i=0; i<n; i++)
        cin>>v[i];

    int m;                          // No. bouquets to make
    cin>>m;

    int k;                          // No. of adjacent flowers required for each Bouquet
    cin>>k;                         // k <= n

    cout<<minimumDays(v, n, m, k);     // Minimum no. of days to wait so that all the flowers 
    return 0;                       // required for m Bouquets are bloomed
}