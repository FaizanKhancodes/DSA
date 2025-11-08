#include<bits/stdc++.h>
using namespace std;

string twosComplement(string s){

    int n= s.size() - 1;
    int i= n;

    while(i >= 0){

        if(s[i--] == '1')
            break;
    }

    while(i >= 0){

        if(s[i] == '1')
            s[i]= '0';

        else
            s[i]= '1';

        i--;
    }

    return s;
}

string decimalToBinary(int num, string ans){

    int sign= num;

    if(num < 0)
        num= -num;
    
    while(num){

        if(num & 1)
            ans+= '1';

        else    
            ans+= '0';

        num= num >> 1;
    }

    ans+= '0';
    reverse(ans.begin(), ans.end());

    if(sign < 0)
        ans= twosComplement(ans);

    return ans;
}

int binaryToDecimal(string s, int ans){

    int powOfTwo= 1;
    int i= s.size() - 1;

    while(i >= 1){

        if(s[i] == '1')
            ans+= powOfTwo;

        powOfTwo*= 2;
        i--;
    }

    if(s[i] == '1')
        ans-= powOfTwo;

    return ans;
}

int main(){

    int num;
    cin>>num;

    // MSB i.e., binary[0] represents sign and follows 2's complement 
    string binary= decimalToBinary(num, "");
    cout<<binary<<endl;

    // MSB i.e., s[0] represents sign and follows 2's complement
    string s;
    cin>>s;
    
    int decimal= binaryToDecimal(s, 0);
    cout<<decimal;

    return 0;
}