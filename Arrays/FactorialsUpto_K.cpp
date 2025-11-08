#include<bits/stdc++.h>
using namespace std;

void fa(vector<long long>& v, long long k, long long curr_num, long long prev_fact_num){
    long long curr_fact_num = prev_fact_num * curr_num;
    if(curr_fact_num > k) return;
    v.push_back(curr_fact_num);
    fa(v, k, curr_num + 1, curr_fact_num);
}
vector<long long> factorialNumbers(long long k) {
    // Write Your Code here
    vector<long long> ans;
    ans.push_back(1);
    long long curr_num= 2;
    fa(ans, k, curr_num, 1);
    return ans;
    
}
int main(){

    int k;              // Number upto which factorials are to find
    cin>>k;
    vector<long long> ans = factorialNumbers(k);
    for(auto it: ans){
        cout<<it<<" ";
    }
    return 0;
}