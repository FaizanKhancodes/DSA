// Find the pair of elements such that A[i] > 2*A[j] where i < j

#include<bits/stdc++.h>
using namespace std;

void Brute(vector<int> v, int n){

    int count=0;

    for(int i=0; i<n; i++){

        int elem= v[i];
        for(int j=i+1; j<n; j++){

            if(elem > (long long)v[j] * 2)    count++;
        }
    }

    cout<<count;
}

void merge(vector<int> v, int start, int mid, int end){

    int i=start, j=mid+1, k=0;
    vector<int> temp(end - start + 1);

    while(i<=mid && j<=end){

        if(v[i] <= v[j])
            temp[k++]= v[i++];
        
        else    
            temp[k++]= v[j++];
    }

    while(i <= mid)
        temp[k++]= v[i++];

    while(j <= end)
        temp[k++]= v[j++];

    int p=0;
    for(int i=start; i<=end; i++)
        v[i]= temp[p++];
    
}

void countInversions(vector<int> v, int start, int mid, int end, int& count){

    int i= start, j= mid+1;

    while(i<=mid && j<=end){

        if(v[i]<=(long long)v[j] * 2)
            i++;

        else{

            j++;
            count+= mid-i+1;
        }
    }
}

void mergeSort(vector<int> v, int start, int end, int& count){

    if(start >= end)    return;
    int mid= (start + end)/2;

    mergeSort(v, start, mid, count);
    mergeSort(v, mid+1, end, count);
    countInversions(v, start, mid, end, count);
    merge(v, start, mid, end);
}

void Optimal(vector<int> v, int n){

    int count= 0;
    mergeSort(v, 0, n-1, count);
    cout<<count;
}
int main(){

    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0; i<n; i++){
        cin>>v[i];
    }

    Brute(v,n);
    cout<<endl;
    Optimal(v,n);
    return 0;
}