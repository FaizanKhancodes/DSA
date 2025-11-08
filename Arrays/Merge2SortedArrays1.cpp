#include<bits/stdc++.h>
using namespace std;

void printVec(vector<int> v){

    for(auto i: v)
        cout<<i<<" ";
    cout<<endl;
}

void merge(vector<int> A, vector<int> B, int m, int n){

    int i=m-1, j=0;

    while(i>=0 && j<n){

        if(A[i]>B[j]){

            swap(A[i], B[j]);
            i--;
            j++;
        }

        else
            break;
    }

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    printVec(A);
    printVec(B);
}

int main(){

    int m, n;
    cin>>m>>n;
    vector<int> A(m);
    vector<int> B(n);

    for(int i=0; i<m; i++)
        cin>>A[i];

    for(int i=0; i<n; i++)
        cin>>B[i];

    merge(A,B, m, n);
    return 0;
}