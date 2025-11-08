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

Node* sortList(Node* head){

    if(head == nullptr || head -> next == nullptr)
        return head;

    Node* head0= new Node(-1);
    Node* temp0= head0;

    Node* head1= new Node(-1);
    Node* temp1= head1;

    Node* head2= new Node(-1);
    Node* temp2= head2;

    Node* p= head;

    while(p){

        if(p -> data == 0){

            temp0 -> next= p;
            temp0= temp0 -> next;
        }

        else if(p -> data == 1){

            temp1 -> next= p;
            temp1= temp1 -> next;
        }

        else{

            temp2 -> next= p;
            temp2= temp2 -> next;
        }

        p= p -> next;
    }

    temp0 -> next= (head1 -> next)? head1 -> next: head2 -> next;
    temp1 -> next= head2 -> next;
    temp2 -> next= nullptr;

    Node* newHead= head0 -> next;

    delete head0;
    delete head1;
    delete head2;

    return newHead;
}

int main(){

    vector<int> v= {2, 0, 0, 1, 2, 1, 1, 2, 1, 0};

    Node* head= createList(v);

    head= sortList(head);
    printList(head);

    return 0;
}