#include<bits/stdc++.h>
using namespace std;

int findXOR(int n){

    if(n % 4 == 0)
        return n;

    else if(n % 4 == 1)
        return 1;

    else if(n % 4 == 2)
        return n + 1;

    return 0;
}

int XORfromLtoR(int L, int R){

    int ans= findXOR(L - 1) ^ findXOR(R);
    return ans;
}

int main(){

    int L, R;
    cin>>L>>R;

    cout<<XORfromLtoR(L, R);

    return 0;
}