#include<bits/stdc++.h>
using namespace std;

class Node{

    public:

        int data;
        Node* next;
        Node* prev;

        Node(int x){

            data= x;
            next= nullptr;
            prev= nullptr;
        }

        Node(int x, Node* n, Node* p){

            data= x;
            next= n;
            prev= p;
        }
};

Node* createList(vector<int> v){

    int n= v.size();
    if(n == 0)    return nullptr;

    Node* head= new Node(v[0]);
    Node* p= head;

    for(int i=1; i<n; i++){

        Node* temp= new Node(v[i]);
        p -> next= temp;
        temp -> prev= p;
        p= temp;
    }

    return head;
}

Node* findTail(Node* head){

    Node* temp= head;
    while(temp -> next)
        temp= temp -> next;
    
    return temp; 
}

vector<pair<int, int>> pairSum(Node* head, int key){

    vector<pair<int, int>> ans;

    Node* left= head;
    Node* right= findTail(head);

    while(left -> data < right -> data){

        if(left -> data + right -> data == key){

            ans.push_back({left -> data, right -> data});
            left= left -> next;
            right= right -> prev;
        }

        else if(left -> data + right -> data < key)
            left= left -> next;

        else
            right= right -> prev;
    }

    return ans;
}

void print(vector<pair<int, int>> ans){

    for(auto i: ans)
        cout<<i.first<<" "<<i.second<<endl;
    
}

int main(){

    vector<int> v= {1, 2, 3, 4, 9};

    Node* head= createList(v);
    
    int key;
    cin>>key;

    vector<pair<int, int>> ans= pairSum(head, key);
    print(ans);

    return 0;
}