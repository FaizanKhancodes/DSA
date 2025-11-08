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
        p ->next= temp;
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

int main(){

    vector<int> v1= {1, 5, 9, 13, 19};
    vector<int> v2= {3, 4, 8, 15, 17, 22};

    Node* head1= createList(v1);
    Node* head2= createList(v2);

    Node* headMerged= mergeLists(head1, head2);
    printList(headMerged);

    return 0;
}