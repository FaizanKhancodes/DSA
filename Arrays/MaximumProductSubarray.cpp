#include<bits/stdc++.h>
using namespace std;

void brute(vector<int> v, int n){

    int ans= INT_MIN;
    for(int i=0; i<n; i++){

        int product= 1;
        for(int j=i; j<n; j++){

            product*= v[j];
            ans= max(ans, product);
        }
    }

    cout<<ans;
}

void optimal(vector<int> v, int n){

    int ans= INT_MIN;
    int prefixProd= 1, suffixProd= 1;

    for(int i=0; i<n; i++){

        if(prefixProd==0)   prefixProd= 1;
        if(suffixProd==0)   suffixProd= 1;
        prefixProd*= v[i];
        suffixProd*= v[n - i - 1];
        ans= max(ans, max(prefixProd, suffixProd));
    }

    cout<<ans;
}

int main(){

    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0; i<n ; i++)
        cin>>v[i];

    brute(v, n);
    cout<<endl;
    optimal(v, n);
    return 0;
}