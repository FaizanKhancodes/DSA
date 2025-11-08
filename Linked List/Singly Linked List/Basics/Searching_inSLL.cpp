#include<bits/stdc++.h>
using namespace std;

class Node{

    public:

        int data;
        Node* next;

        Node(int x){

            data= x;
            next= nullptr;
        }

        Node(int x, Node* nextNode){

            data= x;
            next= nextNode;
        }
};

Node* inserNodes(vector<int> v, int n){

    Node* head= new Node(v[0]);
    Node* p= head;

    for(int i=1; i<n; i++){

        Node* temp= new Node(v[i]);
        p -> next= temp;
        p= temp;
    }

    return head;
}

bool search(Node* p, int target){

    while(p){

        if(p -> data == target)
            return true;
        
        p= p -> next;
    }

    return false;
}

int main(){

    vector<int> v= {5, 8, 13, 2, 9, 4};
    int n= v.size();

    Node* head= inserNodes(v, n);

    int target;
    cin>>target;

    cout<<search(head, target);
    return 0;
}