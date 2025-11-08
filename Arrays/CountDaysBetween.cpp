#include<bits/stdc++.h>
using namespace std;

void mergeIntervals(vector<vector<int>>& meetings){

    sort(meetings.begin(), meetings.end());
    int last= 0;
    for(int i=1; i<meetings.size(); i++){
    
        int& curr_start= meetings[i][0];
        int& curr_end= meetings[i][1];
        int& prev_end= meetings[last][1];
        
        if(prev_end >= curr_start)
            prev_end= max(prev_end, curr_end);
        
        else{
            last++;
            meetings[last]= meetings[i];
        }
            
    }
    meetings.erase(meetings.begin()+last+1, meetings.end());
}

int main(){

    vector<vector<int>> meetings={{3, 49}, {23, 44}, {21, 56}, {26, 55}, {23, 52}, {2, 9}, {1, 48}, {3, 31}};

    mergeIntervals(meetings);
    
    int count=0;
    int k=57;
    count+= meetings[0][0]-1;

    for(int i= 1; i<meetings.size(); i++)
        count+= meetings[i][0] - meetings[i-1][1] - 1;
    

    count+= k - meetings[meetings.size()-1][1];

    for(int i= 0; i<meetings.size(); i++){
            cout<<meetings[i][0]<<" "<<meetings[i][1];
        cout<<endl;
    }
    cout<<count;
    return 0;
}