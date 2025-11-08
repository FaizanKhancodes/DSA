#include<bits/stdc++.h>
using namespace std;

int Rotation(vector<int> v, int n){

    int left=0;                             // The index of the minimum element in the rotated array 
    int right=n-1;                          // is same as the no. of times it is rotated
    int ans=INT_MAX;
    int index=0;

    while(left <= right){

        int mid= (left + right)/2;

        if(v[left] == v[right]){  
            
            if(v[left] < ans){

                ans= v[left];
                index= left;
            }

            else if(v[left] == ans)
                index= min(left, index);
            

            left++;                         // For the cases when we'll not be able to identify 
            right--;                        // the sorted part, so we'll shrink the search space
            continue;
        }

        if(v[left] < v[right]){

            if(v[left] < ans){

                ans= v[left];
                index= left;
            }

            else if(v[left] == ans)
                index= min(left, index);

            break;
        }

        if(v[left] <= v[mid]){

            if(v[left] < ans){

                ans= v[left];
                index= left;
            }

            else if(v[left] == ans)
                index= min(left, index);

            left= mid+1;
        }

        else{

            if(v[mid] < ans){

                ans= v[mid];
                index= mid;
            }

            else if(v[mid] == ans)
                index= min(mid, index);

            right= mid-1;
        }
    }

    return index;
}

int main(){

    int n;
    cin>>n;
    vector<int> v(n);                       // Array contains duplicate elements in sorted fashion but it is rotated
    for(int i=0; i<n; i++)                  // at an index. We'll find out how many times it is rotated
        cin>>v[i];

    cout<<Rotation(v, n);
    return 0;
}