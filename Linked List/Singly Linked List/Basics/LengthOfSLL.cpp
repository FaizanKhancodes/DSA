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

Node* insertNodes(vector<int> v, int n){

    Node* head= new Node(v[0]);
    Node* p= head;

    for(int i=1; i<n; i++){

        Node* temp= new Node(v[i]);
        p -> next= temp;
        p= temp;
    }

    return head;
}

int length(Node* p){

    int cnt= 0;
    while(p){

        cnt++;
        p= p -> next;
    }

    return cnt;
}

int main(){

    vector<int> v= {4, 9, 3, 2, 5, 8};
    int n= v.size();

    Node* head= insertNodes(v, n);

    cout<<length(head);
    return 0;
}