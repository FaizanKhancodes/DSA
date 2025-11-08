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

Node* insertNodes(vector<int> v){

    Node* head= new Node(v[0]);
    Node* p= head;

    int n= v.size();
    for(int i=1; i<n; i++){

        Node* temp= new Node(v[i]);
        p -> next= temp;
        p= temp;
    }

    return head;
}

void printList(Node* head){

    Node* temp= head;

    while(temp){

        cout<<temp->data<<" ";
        temp= temp->next;
    }
}

int main(){

    vector<int> v= {5, 2, 9, 4, 8};
    Node* head= insertNodes(v);

    printList(head);
    return 0;
}