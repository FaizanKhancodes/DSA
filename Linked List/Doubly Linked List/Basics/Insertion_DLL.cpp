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
    cout<<endl;
}

Node* insertHead(Node* head, int x){

    Node* temp= new Node(x, head, nullptr);

    if(head)
        head -> prev= temp;

    return temp;
}

Node* insertTail(Node* head, int x){

    Node* temp= new Node(x);
    if(head == nullptr)    return temp;

    Node* p= head;
    while(p -> next)
        p= p ->next;

    p -> next= temp;
    temp -> prev= p;

    return head;
}

Node* insert_k(Node* head, int x, int k){

    if(k == 1)
        return insertHead(head, x);

    int cnt= 0;
    Node* p= head;

    while(p){

        cnt++;
        if(cnt == k){

            Node* temp= new Node(x, p, p -> prev);
            p -> prev -> next= temp;
            p -> prev= temp;
            break;
        }

        p= p -> next;
    }

    return head;
}

Node* insertBeforeTarget(Node* head, int x, int target){

    if(head == nullptr)
        return head;

    Node* p= head;
    bool flag= 0;

    while(p){

        if(p -> data == target){
            flag= 1;
            break;
        }

        p= p -> next;
    }

    if(flag){

        if(p -> prev == nullptr)
            return insertHead(head, x);

        Node* temp= new Node(x, p, p -> prev);
        p -> prev -> next= temp;
        p -> prev= temp;
    }

    return head;
}

int main(){

    vector<int> v= {5, 9, 2, 8};

    Node* head= createList(v);
    
    head= insertHead(head, 10);
    printList(head);

    head= insertTail(head, 3);
    printList(head);

    int k;
    cin>>k;
    head= insert_k(head, 7, k);
    printList(head);

    int target;
    cin>> target;
    head= insertBeforeTarget(head, 4, target);
    printList(head);

    return 0;
}