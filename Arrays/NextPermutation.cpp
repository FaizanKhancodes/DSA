#include<bits/stdc++.h>
using namespace std;

void func(vector<int>& v, int n){

    int i=n-1;
    for(; i>0; i--){                                // Start iterating from the end

        if(v[i] > v[i-1]){                          // Check for the break point, i.e. the index where the sorted sequence gets broken from the last
                                                    // 1 2 3 6 5 4    here 3 is the break point element                                     
        
            int breakPoint= i-1;                    // Break point
            reverse(v.begin()+i, v.end());          // Reverse the array after the Break point
            
    
            for(int j=i; j<n; j++){                 // Find the minimum element from the subList after the Break point in the array which is       
                                                    // greater than the break point element

                if(v[j] > v[breakPoint]){

                    swap(v[j], v[breakPoint]);      // Swap the the elements
                    return;
                }
            }                         
        }
    }

    if(i==0)                                        // Edge Case: No modification to array inside loop, i.e. Last permutation
        reverse(v.begin(), v.end());                // Reverse the whole array to get the 1st permutation
    
}

int main(){
    
    int n;
    cin>>n;
    vector<int> v;
    for(int i=0; i<n; i++){
        int a;
        cin>>a;
        v.push_back(a);
    }

    func(v, n);
    for(auto i: v)
        cout<<i<<" ";
    return 0;
}