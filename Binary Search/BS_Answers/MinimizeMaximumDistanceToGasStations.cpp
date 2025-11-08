#include<bits/stdc++.h>
using namespace std;

long double brute(vector<int> v, int n, int k){

    vector<int> stationsPlaced(n-1, 0);
    long double ans= -1;

    for(int i=1; i<=k; i++){

        long double sectionLength= -1;
        int index;
        for(int j=1; j<n; j++){
            
            long double diff= (long double)(v[j] - v[j-1])/(stationsPlaced[j-1]+1);
            if(diff > sectionLength){

                sectionLength= diff;
                index= j-1;
            }

        }        
        stationsPlaced[index]++;
    }

    for(int i=1; i<n; i++){

        long double diff= (long double)(v[i] - v[i-1])/(stationsPlaced[i-1]+1);
        ans= max(ans, diff);
    }

    return ans;
}

long double better(vector<int> v, int n, int k){

    vector<int> placed(n-1, 0);

    priority_queue<pair<long double, int>> pq;
    for(int i=1; i<n; i++)
        pq.push({(long double)(v[i] - v[i-1]), i-1});

    for(int i=1; i<=k; i++){

        auto elem= pq.top();
        pq.pop();
        
        int index= elem.second;
        placed[index]++;

        long double secLength= (long double)(v[index+1] - v[index])/(placed[index]+1);
        pq.push({secLength, index});

    }

    return pq.top().first;
    
}

int stationsNeeded(vector<int> v, int n, long double distance){

    int cnt= 0;
    for(int i=1; i<n; i++)
        cnt += ceil(((long double)(v[i] - v[i-1])/distance)-1);

    return cnt;
}

long double optimal(vector<int> v, int n, int k){

    long double left= 0;
    long double right= 0;
    for(int i=1; i<n; i++)
        right= max(right, (long double)v[i] - v[i-1]);

    while(right - left > 1e-6){

        long double mid= (left + right)/2.0;

        if(stationsNeeded(v, n, mid) > k)
            left= mid;

        else    
            right= mid;
    }

    return right;

}

int main(){

    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0; i<n; i++)
        cin>>v[i];

    int k;
    cin>>k;

    cout<<brute(v, n, k)<<endl;
    cout<<better(v, n, k)<<endl;
    cout<<optimal(v, n, k)<<endl;
    return 0;
}