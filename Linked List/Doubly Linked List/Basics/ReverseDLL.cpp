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

    Node* head= new Node(v[0]);
    Node* p= head;

    for(int i=1; i<n; i++){

        Node* temp= new Node(v[i], nullptr, p);
        p -> next= temp;
        p= temp;
    }

    return head;
}

void printList(Node* p){

    while(p){

        cout<<p -> data<<" ";
        p= p -> next;
    }
}

Node* reverseDLL(Node* head){

    if(head == nullptr  ||  head -> next == nullptr)
        return head;

    Node* p= head;
    Node* q= head -> prev;

    while(p){

        q= p -> prev;
        p -> prev= p -> next;
        p -> next= q;
        p= p -> prev;
    }

    head= q -> prev;
    return head;
}

int main(){

    vector<int> v= {4, 3, 10, 6};

    Node* head= createList(v);

    head= reverseDLL(head);
    printList(head);

    return 0;
}