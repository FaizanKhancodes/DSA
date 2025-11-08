#include<bits/stdc++.h>
using namespace std;

void longest_Subarray1(vector<int>& v, int n, int k){               // Brute method
    int max_length=0;
    int count= 0;
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            int subarray_sum=0;
            int subarray_length=0;
            for(int m=i;m<=j;m++){
                subarray_sum+=v[m];
                subarray_length++;
            }
            if(subarray_sum==k){
                max_length=max(subarray_length, max_length);
                count++;
            }
        }
    }
    cout<<"Max_length: "<<max_length<<endl;
    cout<<"Total subarrays with sum K: "<<count<<endl;
}

void longest_Subarray2(vector<int>& v, int n, int k){               // Optimal method
    unordered_map<int, int> mp;
    int max_length=0;
    int sum=0;
    for(int i=0; i<n; i++){
        sum += v[i];
        if(sum == k){
            max_length = i+1;
        }    

        int prefix_sum= sum - k;
        
        if(mp.find(prefix_sum) != mp.end()){                        //checking if prefix_sum is in map
            int length = i - mp[prefix_sum];
            max_length = max(max_length, length);
        }
        if(mp.find(sum)==mp.end())  mp[sum]=i;                      //store the position of prefix sum in the list
    }

    cout<<"Max_length: "<<max_length<<endl;
}

void total_subarrays(vector<int>& v, int n, int k){
    int sum=0;
    int count=0;
    unordered_map<int, int> mp;
    mp[0]=1;                        //for the case when prefix_sum comes out as 0 first time

    for(int i=0; i<n; i++){

        sum+= v[i];

        int prefixSum= sum-k;
        count+= mp[prefixSum];      // Adding to count the number of subarrays with desired prefixSum 

        mp[sum]++;                  //store the frequency of prefix sum instead of its position in the list
    }

    cout<<"Total subarrays with sum K: "<<count<<endl;
}

void longest_Subarray3(vector<int>& v, int n, int k){   //works only with non-negative
    int left = 0, right = 0;                            //elements i.e., >0 but is Optimal method
    int sum= 0;
    int max_length= 0;
    int length= 0;
    int count= 0;
    while(right <= n){
        if(sum == k){
            length= right - left;
            max_length= max(length, max_length);
            count++;
        }
        if(right == n) break;
        sum+= v[right++];

        while(sum > k)    sum-= v[left++];

        
    }
    
    cout<<"Max_length: "<<max_length<<endl;
    cout<<"Total subarrays with sum K: "<<count;
}

int main(){

    int n;
    cin>>n;
    vector<int> v;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        v.push_back(a);
    }

    int k;
    cin>>k;

    longest_Subarray1(v,n,k);
    longest_Subarray2(v,n,k);
    total_subarrays(v,n,k);
    longest_Subarray3(v,n,k);
    
    return 0;
}