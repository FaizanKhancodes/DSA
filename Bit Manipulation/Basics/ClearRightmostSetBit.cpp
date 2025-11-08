#include<bits/stdc++.h>
using namespace std;

void ClearRightmostSetBit(int num){

    // eg: 40= 00...0101000, 3rd bit is first set bit from the right
    // after clear 3rd bit, 32= 00...0100000
    // In 40 all bits right to the 3rd bit are 0s and 40 - 1= 39 is 00...0100111
    // In 39 all bits left to the 3rd bit are same as in 40
    // Now, 40 & 39 i.e., 00...0101000 & 00...0100111 is 00...0100000

    num= num & (num - 1);
    cout<<num;
}

int main(){

    int num;
    cin>>num;

    ClearRightmostSetBit(num);

    return 0;
}