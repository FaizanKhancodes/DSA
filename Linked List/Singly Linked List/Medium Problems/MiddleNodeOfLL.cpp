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
        
        Node(int x, Node* n){

            data= x;
            next= n;
        }
};

Node* createList(vector<int> v){

    Node* head= new Node(v[0]);
    int n= v.size();
    Node* p= head;

    for(int i=1; i<n; i++){

        Node* temp= new Node(v[i]);
        p -> next= temp;
        p= p -> next;
    }

    return head;
}

int middleNode(Node* head){

    Node* fast= head;
    Node* slow= head;

    while(fast != nullptr  &&  fast -> next != nullptr){

        fast= fast -> next -> next;
        slow= slow -> next;
    }

    return slow -> data;
}
int main(){

    vector<int> v= {4, 9, 5, 8, 2, 6};

    Node* head= createList(v);
    cout<<middleNode(head);

    return 0;
}