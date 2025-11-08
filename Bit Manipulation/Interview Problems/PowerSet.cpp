#include<bits/stdc++.h>
using namespace std;

void print(vector<vector<int>> v){

    for(auto i: v){

        for(auto j: i)
            cout<<j<<" ";

        cout<<endl;
    }
}

vector<vector<int>> PowerSet(vector<int> v){

    vector<vector<int>> ans;

    int n= v.size();
    int subsets= 1 << n;

    for(int num=0; num<subsets; num++){

        vector<int> temp;

        for(int i=0; i<n; i++){

            if(num & (1 << i))
                temp.push_back(v[i]);
        }

        ans.push_back(temp);
    }

    return ans;
}

int main(){

    vector<int> v= {1, 2, 3};

    vector<vector<int>> pwrSet= PowerSet(v);

    print(pwrSet);

    return 0;
}