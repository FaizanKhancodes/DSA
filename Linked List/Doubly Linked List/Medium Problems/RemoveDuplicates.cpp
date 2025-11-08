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

void printList(Node* p){

    while(p){

        cout<<p -> data<<" ";
        p= p -> next;
    }
    cout<<endl;
}

Node* removeDuplicates(Node* head){

    Node* temp= head;

    while(temp && temp -> next){

        Node* nextNode= temp -> next;
        
        while(nextNode && nextNode -> data == temp -> data){

            Node* duplicate= nextNode;
            nextNode= nextNode -> next;
            delete duplicate;
        }

        temp -> next= nextNode;
        if(nextNode)    nextNode -> prev= temp;

        temp= nextNode;
    }

    return head;
}

int main(){

    vector<int> v= {1, 1, 1, 2, 2, 3, 4, 4, 5};

    Node* head= createList(v);
    printList(head);

    head= removeDuplicates(head);
    printList(head);

    return 0;
}