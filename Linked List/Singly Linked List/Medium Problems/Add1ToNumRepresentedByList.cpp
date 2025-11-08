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

        cout<<p -> data;
        p= p -> next;
    }
    cout<<endl;
}

Node* reverseList(Node* head){

    if(head == nullptr || head -> next == nullptr)
        return head;

    Node* newHead= reverseList(head -> next);

    Node* front= head -> next;
    front -> next= head;
    head -> next= nullptr;

    return newHead;
}

Node* add1ToListData(Node* head){

    head= reverseList(head);
    int carry= 1;

    Node* temp= head;
    while(temp){

        temp -> data= temp -> data + carry;

        if(temp -> data < 10){

            carry= 0;
            break;
        }

        else{

            carry= 1;
            temp -> data= 0;
        }

        temp= temp -> next;
    }

    head= reverseList(head);

    if(carry){

        Node* newHead= new Node(carry, head);
        head= newHead;
    }

    return head;
}

int helper(Node* temp){

    if(temp == nullptr)
        return 1;

    int carry= helper(temp -> next);

    if(carry == 0)
        return carry;

    int x= temp -> data + carry;

    if(x < 10){

        temp -> data= x;
        carry= 0;
    }

    else{

        temp -> data= 0;
        carry= 1;
    }

    return carry;
}

Node* add1ToListDataRecursive(Node* head){

    int carry= helper(head);

    if(carry){

        Node* newHead= new Node(carry, head);
        head= newHead;
    }

    return head;
}

int main(){

    vector<int> v= {9, 9, 8};

    Node* head= createList(v);

    head= add1ToListData(head);
    printList(head);

    head= add1ToListDataRecursive(head);
    printList(head);

    return 0;
}