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
    cout<<endl;
}

Node* deleteHead(Node* head){

    if(head == nullptr)    return head;

    Node* p= head;
    head= p -> next;
    delete p;
    return head;
}

Node* deleteTail(Node* head){

    if(head == nullptr)    return head;
    if(head -> next == nullptr)    return nullptr;

    Node* p= head;
    Node* q= p;

    while(p -> next){

        q= p;
        p= p -> next;
    }

    q -> next= nullptr;
    delete p;

    return head;
}

int sizeOfLL(Node* head){

    int length= 0;
    Node* p= head;

    while(p){

        length++;
        p= p -> next;
    }

    delete p;
    return length;
}

Node* deleteKthElement(Node* head, int k){

    if(head == nullptr)    return head;

    if(k == 1)    return deleteHead(head);

    if(k == sizeOfLL(head))    return deleteTail(head);

    if(k > sizeOfLL(head))    return head;

    int cnt= 1;
    Node* p= head;
    Node* q= p;

    while(cnt != k){

        q= p;
        p= p -> next;
        cnt++;
    }

    q -> next= p ->next;
    p -> next= nullptr;
    delete p;

    return head;
}

Node* deleteTarget(Node* head, int target){

    if(head == nullptr)    return head;

    if(head -> data == target)    return deleteHead(head);

    Node* p= head -> next;
    Node* q= head;

    while(p){

        if(p -> data == target){

            q -> next= p -> next;
            p -> next= nullptr;
            delete p;
            break;
        }

        q=p;
        p= p -> next;
    }

    return head;
}

int main(){

    vector<int> v= {5, 2, 8, 4, 9, 6, 1, 7};
    Node* head= insertNodes(v);

    head= deleteHead(head);
    printList(head);

    head= deleteTail(head);
    printList(head);

    int k;      
    cin>>k;
    head= deleteKthElement(head, k);
    printList(head);

    int target;
    cin>>target;
    head= deleteTarget(head, target);
    printList(head);
    
    return 0;
}