#include<bits/stdc++.h>
using namespace std;

vector<int> TwoSum_1(vector<int> v, int target, int size){      

    for(int i=0; i<size-1; i++){
        for(int j=i+1; j<size; j++){
            if(v[i]+v[j]==target)
                return {i, j};
        }
    }

    return {-1, -1};
}

vector<int> TwoSum_2(vector<int> v, int target, int size){      // can give index of elements 
                                                                // if present in list
    unordered_map<int, int> mp;     //{elem, index}
    for(int i=0; i<size; i++){
        int num= v[i];
        int rem= target - num;
        if(mp.find(rem)!=mp.end())
            return {mp[rem], i};
        mp[num]= i;
    }

    return {-1, -1};
}

int TwoSum_3(vector<int> v, int target, int size){      // can only tell if elements are
                                                        // present in list or not
    sort(v.begin(), v.end());
    int left= 0, right= size-1;

    while (left< right){
        if(v[left] + v[right] == target)
            return 1;
        else if(v[left] + v[right] > target)
            right--;
        else
            left++;
    }


    return 0;   
}
int main(){

    int size;
    cin>>size;

    int target;
    cin>>target;

    vector<int> v;

    for(int i=0; i<size; i++){
        int element;
        cin>>element;
        v.push_back(element);
    }

    vector<int> ans= TwoSum_1(v, target, size);     // Brute method
    cout<<ans[0]<<" "<<ans[1]<<endl;
    ans.clear();

    ans= TwoSum_2(v, target, size);                 // Optimal method with extra space
    cout<<ans[0]<<" "<<ans[1]<<endl;
    ans.clear();

    int a= TwoSum_3(v, target, size);               // Optimal method without extra space
    cout<<a;

    return 0;
}