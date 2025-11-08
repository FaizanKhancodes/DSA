#include<bits/stdc++.h>
using namespace std;

int stock(vector<int> v, int n){
    int maxProfit= 0;
    int buy= v[0];                  // minimum buying cost day
    for(int i=1; i<n; i++){
        int sell= v[i];             // selling day
        int profit= sell - buy;
        maxProfit= max(profit, maxProfit);
        buy= min(buy, sell);        // buying day will be minimum of present day and 
                                    // previous buying day
    }

    return maxProfit;
}
int main(){

    int n;      //size
    cin>>n;
    vector<int> v;
    for(int i=0; i<n; i++){
        int a;
        cin>>a;
        v.push_back(a);
    }

    int maxProfit= stock(v, n);
    cout<<"Maximum profit earned by buying and selling stocks: "<<maxProfit;
    return 0;
}