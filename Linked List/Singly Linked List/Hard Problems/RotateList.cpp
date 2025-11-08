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

        data=x;
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

Node* rotateList(Node* head, int k){

    if (head == nullptr || k == 0)
        return head;
        
    Node* tail= head;
    int length= 1;

    while(tail -> next){

        tail= tail -> next;
        length++;
    }

    k= k % length;

    if(k == 0)    return head;
    
    Node* temp= head;
    int cnt= 1;

    while(cnt != (length - k)){

        cnt++;
        temp= temp -> next;
    }

    tail -> next= head;
    head= temp -> next;
    temp -> next= nullptr;

    return head;
}

int main(){

    vector<int> v= {1, 2, 3, 4, 5};

    Node* head= createList(v);

    int k;
    cin>>k;

    head= rotateList(head, k);
    printList(head);

    return 0;
}