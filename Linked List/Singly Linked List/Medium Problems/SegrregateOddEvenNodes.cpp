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

    int n= v.size();

    Node* head= new Node(v[0]);
    Node* p= head;

    for(int i=1; i<n; i++){

        Node* temp= new Node(v[i]);
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
    cout<<endl;
}

void segrregateNodes(Node* head){

    if(head == nullptr || head -> next == nullptr)
        return;

    Node* odd= head;
    Node* even= head -> next;
    Node* p= even;

    while(even != nullptr && even -> next != nullptr){

        odd -> next= odd -> next -> next;
        odd= odd -> next;

        even -> next= even -> next -> next;
        even= even -> next;
    }

    odd -> next= p;
}

int main(){

    vector<int> v= {1, 2, 3, 4, 5, 6};

    Node* head= createList(v);
    printList(head);

    segrregateNodes(head);
    printList(head);

    return 0;
}