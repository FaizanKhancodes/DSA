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

Node* deleteHead(Node* head){

    if(head == nullptr)    
        return head;

    if(head -> next == nullptr){

        delete head;
        return nullptr;
    }

    Node* p= head;
    head= p -> next;
    p -> next= nullptr;
    head -> prev= nullptr;
    delete p;
    
    return head;
}

Node* deleteTail(Node* head){

    if(head == nullptr)
        return head;

    if(head -> next == nullptr){

        delete head;
        return nullptr;
    }

    Node* p= head;
    while(p -> next)
        p= p -> next;

    p -> prev -> next= nullptr;
    p -> prev= nullptr;
    delete p;

    return head;
}

int sizeOfDLL(Node* p){

    int length= 0;
    while(p){

        length++;
        p= p -> next;
    }

    return length;
}

Node* delete_kth(Node* head, int k){

    if(head == nullptr)
        return head;

    if(k == 1)
        return deleteHead(head);

    if(k == sizeOfDLL(head))
        return deleteTail(head);

    int cnt= 1;
    Node* p= head -> next;

    while(p){

        cnt++;
        if(cnt == k){

            p -> prev -> next= p -> next;
            p -> next -> prev= p -> prev;
            p -> next= nullptr;
            p -> prev= nullptr;
            delete p;
            break;
        }

        p= p -> next;
    }

    return head;
}

Node* deleteTarget(Node* head, int target){

    if(head == nullptr)
        return head;

    Node* p= head;
    bool flag= 0;
    while(p){

        if(p -> data == target){
            flag= 1;
            break;
        }

        p= p ->next;
    }
    
    if(flag){

        if(p -> next == nullptr  &&  p -> prev == nullptr){

            delete p;
            return nullptr;
        }

        if(p -> prev == nullptr)
            return deleteHead(head);

        if(p -> next == nullptr)
            return deleteTail(head);

        
        p -> prev -> next= p -> next;
        p -> next -> prev= p -> prev;
        p -> next= nullptr;
        p -> prev= nullptr;
        delete p;

        return head;
    }

    return head;
}

int main(){

    vector<int> v= {4, 9, 2, 3, 10, 7};

    Node* head= createList(v);
    
    head= deleteHead(head);
    printList(head);

    head= deleteTail(head);
    printList(head);

    int k;
    cin>>k;
    head= delete_kth(head, k);
    printList(head);

    int target;
    cin>>target;
    head= deleteTarget(head, target);
    printList(head);

    return 0;
}