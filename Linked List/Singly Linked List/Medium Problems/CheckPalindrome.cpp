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

Node* reverseList(Node* head){

    Node* front= head;
    Node* curr= nullptr;
    Node* back= nullptr;

    while(front){

        curr= front;
        front= front -> next;
        curr -> next= back;
        back= curr;
    }

    return curr;
}

bool isPalindrome(Node* head){

    Node* slow= head;
    Node* fast= head;

    while(fast -> next != nullptr && fast -> next -> next != nullptr){

        slow= slow -> next;
        fast= fast -> next -> next;
    }

    Node* newHead= reverseList(slow -> next);

    Node* first= head;
    Node* second= newHead;

    while(second){

        if(first -> data != second -> data){
            
            newHead= reverseList(newHead);
            return false;
        }

        first= first -> next;
        second= second -> next;
    }

    newHead= reverseList(newHead);
    return true;
}

int main(){

    vector<int> v= {1, 2, 3, 3, 2, 3};

    Node* head= createList(v);
    cout<<isPalindrome(head);

    return 0;
}