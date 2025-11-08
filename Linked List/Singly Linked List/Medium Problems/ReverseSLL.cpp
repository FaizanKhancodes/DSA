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

Node* reverseSLL(Node* head){

    if(head == nullptr  ||  head -> next == nullptr)
        return head;

    Node* front= head;
    Node* curr= nullptr;
    Node* back= nullptr;

    while(front){

        curr= front;
        front= front -> next;
        curr -> next= back;
        back= curr;
    }

    return curr;
}

Node* reverseSLL_recursive(Node* head){

    if(head == nullptr  ||  head -> next == nullptr)
        return head;

    Node* newHead= reverseSLL_recursive(head ->next);
    Node* front= head -> next;
    front -> next= head;
    head -> next= nullptr;

    return newHead;
}

int main(){

    vector<int> v= {4, 7, 2, 9, 13};

    Node* head= createList(v);

    head= reverseSLL(head);
    printList(head);

    head= reverseSLL_recursive(head);
    printList(head);

    return 0;
}