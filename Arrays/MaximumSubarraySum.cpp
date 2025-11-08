#include<bits/stdc++.h>
using namespace std;

pair<int, int> brute(vector<int> v, int n){
    int max_sum=0;
    int start= -1;
    int end= -1;
    for(int i=0; i<n; i++){
        for(int j=i; j<n; j++){
            int sum=0;
            for(int k=i; k<=j; k++){
                sum+= v[k];
                if(sum > max_sum){
                    max_sum= sum;
                    start= i;
                    end= j;
                }
            }
        }
    }
    cout<<"Maximun Subarray Sum is: "<<max_sum<<endl;
    return {start, end};
}

pair<int, int> better(vector<int> v, int n){
    int max_sum=0;
    int start= -1;
    int end= -1;
    for(int i=0; i<n; i++){
        int sum= 0;
        for(int j=i; j<n; j++){
            sum+= v[j];
            if(sum > max_sum){
                max_sum= sum;
                start= i;
                end= j;
            }
            
        }
    }
    cout<<"\nMaximun Subarray Sum is: "<<max_sum<<endl;
    return {start, end};
}

pair<int, int> optimal(vector<int> v, int n){
    int max_sum=INT_MIN;
    int start= -1;
    int end= -1;                                //Kadane's Algorithm
    int sum= 0;
    int k= -1;
    for(int i=0; i<n; i++){
        if(sum == 0 && (v[i-1] != 0 || i == 0))
            k=i;

        sum+= v[i];

        if(sum < 0)
            sum= 0;
            
        if(sum > max_sum){
            max_sum= sum;
            start= k;
            end= i;
        }
        
    }
    cout<<"\nMaximun Subarray Sum is: "<<max_sum<<endl;
    return {start, end};
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

    
    
    pair<int, int> p1= brute(v, n);
    cout<<"The corresponding array is: ";
    for(int j=p1.first; j<=p1.second; j++){
        cout<<v[j]<<" ";
    }
    cout<<endl;

    
    pair<int, int> p2= better(v, n);
    cout<<"The corresponding array is: ";
    for(int j=p2.first; j<=p2.second; j++){
        cout<<v[j]<<" ";
    }
    cout<<endl;

    
    pair<int, int> p3= optimal(v, n);                          //Kadane's Algorithm
    cout<<"The corresponding array is: ";
    for(int j=p3.first; j<=p3.second; j++){
        cout<<v[j]<<" ";
    }
    
    return 0;
}