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
    if(n == 0)  return nullptr;

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

Node* deleteAllOccurrences(Node* head, int key){

    Node* temp= head;

    while(temp){

        Node* curr= temp;
        temp= temp -> next;

        if(curr -> data == key){

            if(curr == head)
                head=  head -> next;

            if(curr -> next)    curr -> next -> prev= curr -> prev;
            if(curr -> prev)    curr -> prev -> next= curr -> next;
            
            curr -> next= nullptr;
            curr -> prev= nullptr;
            delete curr;
        }
    }

    return head;
}

int main(){

    vector<int> v= {3, 7, 3, 2, 9, 3, 3, 6, 3};

    Node* head= createList(v);
    printList(head);

    int key;
    cin>>key;

    head= deleteAllOccurrences(head, key);
    printList(head);

    return 0;
}