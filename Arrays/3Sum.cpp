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

                long long sum= v[i] + v[j];
                sum+= v[k];

                if(sum == 0){

                    vector<int> temp= {v[i], v[j], v[k]};
                    sort(temp.begin(), temp.end());
                    st.insert(temp);
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

        unordered_set<int> mp;

        for(int j=i+1; j<n; j++){

            long long sum= v[i] + v[j];
            long long rem= -sum;

            if(mp.find(rem) != mp.end()){

                vector<int> temp= {v[i], v[j], (int)rem};
                sort(temp.begin(), temp.end());
                st.insert(temp);
            }

            mp.insert(v[j]);
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

        int j= i+1;
        int k= n-1;

        while(j<k){

            long long sum= v[i] + v[j];
            sum+= v[k];

            if(sum == 0){

                ans.push_back({v[i], v[j], v[k]});
                j++;
                k--;
                while(j<k && v[j]==v[j-1])  j++;
                while(j<k && v[k]==v[k+1])  k--;
            }

            else if(sum>0)  k--;

            else    j++;
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