#include<bits/stdc++.h>
using namespace std;

class Node{

    public:

        int data;
        Node* next;
        Node* random;

        Node(int x){

            data= x;
            next= nullptr;
            random= nullptr;
        }
};

Node* createList(vector<int> v){

    int n= v.size();
    if(n == 0)
        return nullptr;

    unordered_map<int, Node*> mp;

    Node* head= new Node(v[0]);
    Node* p= head;
    mp[v[0]]= p;

    for(int i=1; i<n; i++){

        Node* temp= new Node(v[i]);
        p -> next= temp;
        p =temp;
        mp[v[i]]= p;
    }

    p= head;
    while(p){

        int i;
        cin>>i;
        if(i == n)
            p -> random= nullptr;

        else
            p -> random= mp[v[i]];

        p= p -> next;
    }
    
    return head;
}

void printList(Node* p){

    while(p){
        cout<<p -> data<<" "<<(p -> random? p -> random -> data: -1)<<endl;
        p= p -> next;
    }
    
}

Node* cloneListBrute(Node* head){

    unordered_map<Node*, Node*> mp;
    Node* temp= head;

    while(temp){

        Node* copyNode= new Node(temp -> data);
        mp[temp]= copyNode;
        temp= temp -> next;
    }

    temp= head;
    Node* dummy= new Node(-1);
    Node* curr= dummy;

    while(temp){

        Node* copyNode= mp[temp];
        curr -> next= copyNode;
        curr= copyNode;
        curr -> random= mp[temp -> random];
        temp= temp -> next;
    }

    delete dummy;
    return mp[head];
}

Node* cloneListOptimal(Node* head){

    Node* temp= head;
    
    while(temp){

        Node* copyNode= new Node(temp -> data);
        copyNode -> next= temp -> next;
        temp -> next= copyNode;
        temp= temp -> next -> next;
    }

    temp= head;

    while(temp){

        Node* copyNode= temp -> next;
        copyNode -> random= (temp -> random? temp -> random -> next: nullptr);
        temp= temp -> next -> next;
    }

    temp= head;
    Node* dummy= new Node(-1);
    Node* curr= dummy;

    while(temp){

        curr -> next= temp -> next;
        curr= curr -> next;
        temp -> next= temp -> next -> next;
        temp= temp -> next;
    }
    
    Node* cloneHead= dummy -> next;
    delete dummy;

    return cloneHead;
}

int main(){

    vector<int> v= {4, 8, 1, 9, 3, 5};

    Node* head= createList(v);
    
    Node* cloneHeadBrute= cloneListBrute(head);
    printList(cloneHeadBrute);

    cout<<endl;

    Node* cloneHeadOptimal= cloneListOptimal(head);
    printList(cloneHeadOptimal);

    return 0;
}