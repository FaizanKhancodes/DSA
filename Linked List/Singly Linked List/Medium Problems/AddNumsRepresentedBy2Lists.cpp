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
        p =temp;
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

Node* addNums(Node* head1, Node* head2){

    Node* temp1= head1;
    Node* temp2= head2;

    Node* dummy= new Node(-1);
    Node* curr= dummy;

    int carry= 0;

    while((temp1 || temp2) || carry){

        int sum= 0;

        if(temp1){
            sum+= temp1 -> data;
            temp1= temp1 -> next;
        }

        if(temp2){
            sum+= temp2 -> data;
            temp2= temp2 -> next;
        }

        sum+= carry;
        carry= sum/10;

        Node* newNode= new Node(sum % 10);
        curr -> next= newNode;
        curr= curr -> next;

    }

    return dummy -> next;
}

int main(){

    vector<int> v1= {9, 4, 6, 9, 9};
    vector<int> v2= {8, 4, 5};

    Node* head1= createList(v1);
    Node* head2= createList(v2);

    Node* headSum= addNums(head1, head2);
    printList(headSum);

    return 0;
}