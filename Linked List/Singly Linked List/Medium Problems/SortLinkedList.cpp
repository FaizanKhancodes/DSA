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

Node* middleNode(Node* head){

    if(head == nullptr || head -> next == nullptr)
        return head;

    Node* slow= head;
    Node* fast= head;

    while(fast -> next && fast -> next -> next){

        fast= fast -> next -> next;
        slow= slow -> next;
    }

    return slow;
}

Node* mergeLists(Node* list1, Node* list2){

    Node* dummy= new Node(-1);
    Node* p= dummy;

    while(list1 && list2){

        if(list1 -> data < list2 -> data){

            p -> next= list1;
            p= list1;
            list1= list1 -> next;
        }

        else{

            p -> next= list2;
            p= list2;
            list2= list2 -> next;
        }
    }

    if(list1)
        p -> next= list1;
    else    
        p -> next= list2;

    return dummy -> next;
}

Node* sort(Node* head){

    if(head == nullptr || head -> next == nullptr)
        return head;

    Node* left= head;
    Node* middle= middleNode(head);
    Node* right= middle -> next;
    middle -> next= nullptr;

    left= sort(left);
    right= sort(right);

    return mergeLists(left, right);
}

int main(){

    vector<int> v= {5, 2, 8, 10, 3};

    Node* head= createList(v);
    printList(head);
    
    head= sort(head);
    printList(head);

    return 0;
}