#include<bits/stdc++.h>
using namespace std;

void sort1(int *a,int n){       //selection sort

    for(int i=0;i<n-1;i++){
        int min=i;
        for(int j=i+1;j<n;j++){
            if(a[j]<a[min]) min=j;
        }
        if(min!=i) swap(a[i],a[min]);
    }
}

void sort2(int *a,int n){       //bubble sort

    for(int i=0;i<n-1;i++){
        int s=0;
        for(int j=0;j<n-i;j++){
            if(a[j]>a[j+1]){
                swap(a[j],a[j+1]);
                s=1;
            } 
        }
        if(!s) break;
    }
}

void sort3(int *a,int n){       //insertion sort

    for(int i=0;i<n;i++){
        int temp=a[i];
        int j=i;
        for(;j>0;j--){
            if(temp<a[j-1]){
                a[j]=a[j-1];
            } 
            else{
                a[j]=temp;
                break;
            }
        }
        if(j==0) a[j]=temp;
        
    }
}

void merge(int *a, int l, int m, int h){
    
    int i=l, j=m+1, temp[h-l+1], k=0;

    while(i<=m && j<=h){
        if(a[i]<=a[j]) temp[k++]=a[i++];
        else temp[k++]=a[j++];
    }
    while(i<=m) temp[k++]=a[i++];
    while(j<=h) temp[k++]=a[j++];

    for(int i=l;i<=h;i++) a[i]=temp[i-l];
}

void sort4(int *a,int l,int h){    //merge sort
    if(l>=h) return;
    int m= l+(h-l)/2;
    sort4(a,l,m);
    sort4(a,m+1,h);
    merge(a,l,m,h);
}

int partition(int *a,int l,int h){
    int m=a[h], i=l, j=h;
    while(l<h){
        while(a[i]<m &&  i<h) i++;
        while(a[j]>=m && j>l) j--;
        if(i<j) swap(a[i],a[j]);
    }
    swap(m,a[i]);
    return i;
}

void sort5(int *a,int i,int j){   //quick sort
    if(i=j) return;

    int pivot=partition(a,i,j);
    sort5(a,i,pivot-1);
    sort5(a,pivot+1,j);
}

int main(){
   int n;
   cin>>n;
   int a[n];
   for(int i=0;i<n;i++) cin>>a[i];
   sort3(a,n);
   for(int i=0;i<n;i++) cout<<a[i]<<" ";
   return 0;
}