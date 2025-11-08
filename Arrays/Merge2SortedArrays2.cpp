#include<bits/stdc++.h>
using namespace std;

void printVec(vector<int> v){

    for(auto i: v)
        cout<<i<<" ";
}

void merge(vector<int> A, vector<int> B, int m, int n){

    int i=m-1, j=n-1, k=m+n-1;

    while(i>=0 && j>=0){

        if(A[i]>=B[j])
            A[k--]=A[i--];
        
        else    
            A[k--]=B[j--];
    }

    while(i>=0)
        A[k--]=A[i--];

    while(j>=0)
        A[k--]=B[j--];

    printVec(A);
}

int main(){

    int m, n;
    cin>>m>>n;
    vector<int> A(m+n);
    vector<int> B(n);

    for(int i=0; i<m; i++)
        cin>>A[i];

    for(int i=0; i<n; i++)
        cin>>B[i];

    merge(A, B, m, n);
    return 0;

}