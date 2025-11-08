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

Node* deleteNodeBrute(Node* head, int k){

    int n= 0;
    Node* p= head;

    while(p){

        n++;
        p= p -> next;
    }

    if(k == n){

        Node* temp= head -> next;
        delete head;
        return temp;
    }

    int cnt= n - k;
    p= head;

    while(cnt != 1){

        cnt--;
        p= p -> next;
    }

    Node* q= p -> next;
    p -> next= p -> next -> next;
    delete q;

    return head;
}

Node* deleteNodeOptimal(Node* head, int k){

    Node* fast= head;

    for(int i=0; i<k; i++)
        fast= fast -> next;

    if(fast == nullptr){

        Node* temp= head -> next;
        delete head;
        return temp;
    }

    Node* slow= head;

    while(fast -> next != nullptr){

        slow= slow -> next;
        fast= fast -> next;
    }

    Node* temp= slow -> next;
    slow -> next= slow -> next -> next;
    delete temp;

    return head;
}

int main(){

    vector<int> v= {1, 2, 3, 4, 5, 6, 7};

    Node* head= createList(v);
    printList(head);

    int k;
    cin>>k;

    head= deleteNodeBrute(head, k);
    printList(head);

    cin>>k;

    head= deleteNodeOptimal(head, k);
    printList(head);
    
    return 0;
}