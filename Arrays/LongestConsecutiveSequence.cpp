#include<bits/stdc++.h>
using namespace std;

int Ls(vector<int> v, int n, int k){
    
    for(int i=0; i<n; i++){

        if(v[i] == k)
            return i;
    }
    
    return -1;
}

void brute(vector<int> v, int n){

    int length= 1;
    for(int i=0; i<n; i++){

        int elem= v[i];
        int count= 1;
        while(Ls(v, n, elem+1) != -1){          // Searching for the next consecutive element in the sequence

            elem++;
            count++;
        }

        length= max(count, length);
    }

    cout<<length<<endl;
}

void better(vector<int> v, int n){

    sort(v.begin(), v.end());                   // Sort the List

    int length= 1;
    int count= 1;
    for(int i=0; i<n-1; i++){

        int currElem= v[i];
        int nextElem= v[i+1];
        if(nextElem-1 == currElem)              // Next consecutive element in sequence is present
            count++;
        
        else if(nextElem-1 > currElem){         // Next consecutive element in sequence is absent

            length= max(count, length);
            count= 1;
        }                                       // We'll ignore multiple occurrences of same element in a sequence
    }

    length= max(count, length);
    cout<<length<<endl;
}

void optimal(vector<int> v, int n){

    unordered_set<int> st;
    for(auto i: v)
        st.insert(i);

    int length= 1;
    for(auto i: st){

        int count= 1;
        int currElem= i;
        if(st.find(currElem-1) != st.end())             // Current element is not 1st element of sequence, so do nothing
            continue;
        
        int nextElem= currElem + 1;                     // Current element is 1st element of sequence, so start finding next consecutive elements
        while(st.find(nextElem) != st.end()){           // Next consecutive element of sequence is found, so increase the count
            nextElem++;
            count++;
        }

        length= max(count, length);                     // Update the maximum length
    }
    
    cout<<length;
}
int main(){

    int n;                  // Size of the input List
    cin>>n;
    vector<int> v;          // Input List
    for(int i=0; i<n; i++){
        int a;
        cin>>a;
        v.push_back(a);
    }

    brute(v, n);            // Brute solution
    better(v, n);           // Better solution
    optimal(v, n);          // Optimal solution
    return 0;
}