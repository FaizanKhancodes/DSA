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

Node* createList(vector<int> v){

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
    
    Node* p= head;

    while(p){

        cout<<p -> data<<" ";
        p= p -> next;
    }
    cout<<endl;
}

Node* insertHead(Node* head, int x){

    Node* temp= new Node(x);
    temp -> next= head;
    head= temp;

    return head;
}

Node* insertTail(Node* head, int x){

    Node* temp= new Node(x);
    if(head == nullptr)    return temp;

    Node* p= head;
    while(p -> next)
        p= p -> next;

    p -> next= temp;

    return head;
}

Node* insert_at_k(Node* head, int x, int k){

    if(k == 1)    return insertHead(head, x);

    if(head == nullptr)    return head;

    Node* p= head;
    int cnt= 1;

    while(p){

        if(cnt == k-1){

            Node* temp= new Node(x);
            temp -> next= p -> next;
            p -> next= temp;
            break;
        }

        cnt++;
        p= p -> next;
    }

    return head;
}

Node* insertBeforeTarget(Node* head, int x, int target){

    if(head == nullptr)    return head;

    if(head -> data == target)    return insertHead(head, x);

    Node* p= head;
    while(p -> next){

        if(p -> next -> data == target){

            Node* temp= new Node(x);
            temp -> next= p -> next;
            p -> next= temp;
            break;
        }

        p= p -> next;
    }
    return head;
}

int main(){

    vector<int> v= {4, 1, 9, 14, 3, 10};
    Node* head= createList(v);
    printList(head);

    head= insertHead(head, 13);
    printList(head);

    head= insertTail(head, 7);
    printList(head);

    int k;
    cin>>k;
    head= insert_at_k(head, 26, k);
    printList(head);

    int target;
    cin>>target;
    head= insertBeforeTarget(head, 5, target);
    printList(head);

    return 0;
}