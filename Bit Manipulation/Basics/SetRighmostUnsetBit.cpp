#include<bits/stdc++.h>
using namespace std;

void SetRightmostUnsetBit(int num){

    // eg: 19= 00...010011, 2nd bit is first unset bit from the right 
    // after set 2nd bit, 23= 00...010111
    // In 19 all bits right to the 2nd bit are 1s and 19 + 1= 20 is 00...0100100
    // In 20 all bits left to the 2nd bit are same as in 19
    // Now, 19 | 20 i.e., 00...010011 & 00...010100 is 00...010111

    num= num | (num + 1);
    cout<<num;
}

int main(){

    int num;
    cin>>num;

    SetRightmostUnsetBit(num);

    return 0;
}