#include<bits/stdc++.h>
using namespace std;

void printVec(vector<vector<int>> v){

    for(auto& i: v){
        for(auto j: i)
            cout<<j<<" ";
        cout<<endl;
    }

}

void brute(vector<int> v, int n){

    set<vector<int>> st;

    for(int i=0; i<n; i++){

        for(int j=i+1; j<n; j++){

            for(int k=j+1; k<n; k++){

                for(int l=k+1; l<n; l++){

                    long long sum= v[i] + v[j];
                    sum+= v[k] + v[l];

                    if(sum == 0){

                        vector<int> temp= {v[i], v[j], v[k], v[l]};
                        sort(temp.begin(), temp.end());
                        st.insert(temp);
                    }
                }
            }
        }
    }

    vector<vector<int>> ans(st.begin(), st.end());
    printVec(ans);

}

void better(vector<int> v, int n){

    set<vector<int>> st;

    for(int i=0; i<n; i++){

        for(int j=i+1; j<n; j++){

            unordered_set<int> s;

            for(int k=j+1; k<n; k++){

                long long sum= v[i] + v[j] + v[k];
                long long rem= -sum;

                if(s.find(rem) != s.end()){

                    vector<int> temp= {v[i], v[j], v[k], (int)rem};
                    sort(temp.begin(), temp.end());
                    st.insert(temp);
                }

                s.insert(v[k]);
            }
        }
    }

    vector<vector<int>> ans(st.begin(), st.end());
    printVec(ans);

}

void optimal(vector<int> v, int n){

    sort(v.begin(), v.end());
    vector<vector<int>> ans;

    for(int i=0; i<n; i++){

        if(i > 0  &&  v[i-1] == v[i])
            continue;

        for(int j=i+1; j<n; j++){

            if(j > i+1  &&  v[j-1] == v[j])
                continue;

            int k= j+1;
            int l= n-1;

            while(k<l){

                long long sum= v[i] + v[j];
                sum+= v[k] + v[l];

                if(sum == 0){

                    ans.push_back({v[i], v[j], v[k], v[l]});
                    k++;
                    l--;
                    while(k<l && v[k]==v[k-1])  k++;
                    while(k<l && v[l]==v[l+1])  l--;
                }

                else if(sum>0)  l--;

                else    k++;
            }
        }
    }

    printVec(ans);
}

int main(){

    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0; i<n; i++)
        cin>>v[i];
    
    brute(v,n);
    cout<<endl;
    better(v,n);
    cout<<endl;
    optimal(v,n);
    return 0;
}