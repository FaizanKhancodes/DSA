#include<bits/stdc++.h>
using namespace std;

int studentsNeeded(vector<int> v, int n, int maxPages){

    int studentCnt= 1;                              
    int pagesAllocated= 0;

    for(int i=0; i<n; i++){

        if(pagesAllocated + v[i] <= maxPages)       // Book can be allocated to current student
            pagesAllocated+= v[i];

        else{

            studentCnt++;                           // Book can't be allocated to current student
            pagesAllocated= v[i];                   // so allocate to next student
        }
    }

    return studentCnt;
}

int minPossiblePages(vector<int> v, int n, int k){

    // No allocation possible as some students can't get any book
    if(n < k)   return -1;      

    // Each student will get only 1 book, so book with max. pages is the answer
    if(n == k)  return *max_element(v.begin(), v.end());

    // All the books will be allocated to 1 student
    if(k == 1)  return accumulate(v.begin(), v.end(), 0);

    int left= *max_element(v.begin(), v.end());         // Range to search the maxPages [max(v), sum(v)]
    int right= accumulate(v.begin(), v.end(), 0);

    while(left <= right){

        int mid= (left + right)/2;                      // Mid is current maxPages to check

        if(studentsNeeded(v, n, mid) > k)               // Not possible to allocate books among k students such that no student is 
            left= mid+1;                                // allocated no. of pages more than current maxPages. So increase the maxPages

        else                                            // Possible to allocate among k students
            right= mid-1;                               // So search for minimum possible maxPages
    }

    return left;
}

int main(){

    int n;                          // No. of books
    cin>>n;
    vector<int> v(n);               // v[i] is the no. of pages in iᵗʰ book
    for(int i=0; i<n; i++)
        cin>>v[i];

    int k;                          // No. of students
    cin>>k;

    cout<<minPossiblePages(v, n, k);        // We need to find the max. pages that can be Allocated to any 
    return 0;                               // student such that it is minimum possible
}       