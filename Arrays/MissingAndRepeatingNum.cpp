#include<bits/stdc++.h>
using namespace std;

void brute(vector<int> v, int n){

    int R;                  // Repeating num

    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){

            if(v[i]==v[j]){

                R= v[i];
                break;
            }
        }
    }

    int s1= n*(n+1)/2;      // sum of first n natural num
    int s2= 0;              // sum of array elements
    for(auto i:v)
        s2+= i;

    int M= s1 - s2 + R;     // Missing num
    cout<<M<<" "<<R;
}

void better1(vector<int> v, int n){

    sort(v.begin(), v.end());
    int R;                  // Repeating num

    for(int i=0; i<n; i++){

        if(v[i]==v[i+1]){

            R=v[i];
            break;
        }
    }

    int s1= n*(n+1)/2;      // sum of first n natural num
    int s2= 0;              // sum of array elements
    for(auto i:v)
        s2+= i;

    int M= s1 - s2 + R;     // Missing num
    cout<<M<<" "<<R;    
}

void better2(vector<int> v, int n){

    int M, R;                       // Missing num and Repeating num
    vector<int> hs(n+1, 0);         // Hash array
    for(int i=0; i<n; i++)
        hs[v[i]]++;
    
    for(int i=1; i<=n; i++){
        if(hs[i]==0)
            M=i;

        else if(hs[i]==2)
            R=i;
    }
    cout<<M<<" "<<R;
}

void optimal1(vector<int> v, int n){

    int M, R;                       // Missing num and Repeating num
    for(int i=0; i<n; i++){

        int elem= abs(v[i]);

        if(v[elem-1]<0)
            R=elem;

        else
            v[elem-1]= -v[elem-1];
    }

    for(int i=0; i<n; i++){

        if(v[i]>0){

            M=i+1;
            break;
        }
    }

    cout<<M<<" "<<R;
}

void optimal2(vector<int> v, int n){

    int s1=n*(n+1)/2;               // sum of first n natural nums
    int s12=n*(n+1)*(2*n+1)/6;      // sum of square of first n natural nums
    int s2=0;                       // sum of array elements
    int s22=0;                      // sum of square of array elements

    int M, R;                       // Missing num and Repeating num

    for(auto i:v){

        s2+= i;
        s22+= i*i;
    }

    int p= s1 - s2;                 // M-R = s1-s2  =>  p = M-R
    int q= s12 - s22;               // M^2-R^2 = s1^2-s2^2  =>  q = M^2-R^2
    int r= q/p;                     // M^2-R^2 = (M+R)(M-R)  =>  (M+R)*p = q  =>  (M+R) = q/p  =>  r = (M+R)

    M= (p+r)/2;                     // M-R + M+R = p + r  =>  2*M = p+r  =>  M = (p+r)/2
    R= r - M;                       // M+R = r  =>  R = r - M

    cout<<M<<" "<<R;
}

void optimal3(vector<int> v, int n){

    int M, R;                       // Missing num and Repeating num
    int xr=0;                       // xr = M ^ R

    for(int i=0; i<n; i++){

        xr^= v[i];
        xr^= (i+1);
    }

    int setBit= xr & (~xr + 1);     // Rightmost set bit of xr

    int set=0, notSet=0;
    for(int i=0; i<n; i++){

        if(setBit&v[i])
            set^= v[i];             // XOR of array elements which have bit as 1 at the same position where setBit has bit as 1

        else    
            notSet^= v[i];          // XOR of array elements which have bit as 0 at the same position where setBit has bit as 1
    }

    for(int i=1; i<=n; i++){

        if(setBit&i)
            set^= i;                // XOR of elements in [1,n] which have bit as 1 at the same position where setBit has bit as 1

        else    
            notSet^= i;             // XOR of elements in [1,n] which have bit as 0 at the same position where setBit has bit as 1
    }

    for(auto i:v){                  // Check if set contains Repeating num or notSet contains Repeating num

        if(set==i){
            R= set;
            break;
        }

        else if(notSet==i){
            R=notSet;
            break;
        }
    }

    M= (R==set)?notSet:set;         // Check if set contains Missing num or notSet contains Missing num

    cout<<M<<" "<<R;
}

int main(){

    int n;
    cin>>n;
    vector<int> v(n);       // array has nums [1,n] with one num missing and one num repeating from range [1,n]

    for(int i=0; i<n; i++)
        cin>>v[i];

    brute(v, n);            // Loop 2 times to find Repeating num
    cout<<endl;
    better1(v, n);          // Sort the array to find Repeating num
    cout<<endl;
    better2(v, n);          // Using Hash array(additional)
    cout<<endl;
    optimal1(v, n);         // Utilize given array as hash array 
    cout<<endl;
    optimal2(v, n);         // Using Mathematics
    cout<<endl;
    optimal3(v, n);         // Using XOR method
    return 0;
}