#include<bits/stdc++.h>
using namespace std;

void printvec(vector<vector<int>> v){

    int n= v.size();
    for(int i=0; i<n; i++)
        cout<<v[i][0]<<" "<<v[i][1]<<" | ";
}

void optimal(vector<vector<int>>& v, int n){

    sort(v.begin(), v.end());
    int last= 0;

    for(int i=1; i<n; i++){

        if(v[last][1] >= v[i][0])
            v[last][1]= max(v[last][1], v[i][1]);

        else{
            last++;
            v[last]= v[i];
        }
    }

    v.erase(v.begin()+last+1, v.end());
    printvec(v);
}
void brute(vector<vector<int>> v, int n){

    vector<vector<int>> ans;
    sort(v.begin(), v.end());

    for(int i=0; i<n; i++){

        int start= v[i][0];
        int end= v[i][1];
        if(!ans.empty() && ans.back()[1] >= start)  continue;

        for(int j=i+1; j<n; j++){

            if(v[j][0] <= end)
                end= max(end, v[j][1]);
            
            else    
                break;
        }

        ans.push_back({start, end});
    }

    printvec(ans);
}

int main(){

    int n;
    cin>>n;
    vector<vector<int>> v(n, vector<int> (2));
    for(int i=0; i<n; i++){
        cin>>v[i][0]>>v[i][1];
    }

    brute(v, n);
    cout<<endl;
    optimal(v, n);
    return 0;
}