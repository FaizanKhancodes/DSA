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

Node* findKthNode(Node* temp, int k){

    k--;
    while(temp && k){

        k--;
        temp= temp -> next;
    }

    return temp;
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

Node* reverseKgroups(Node* head, int k){

    Node* temp= head;
    Node* nextNode= nullptr;
    Node* prevNode= nullptr;
    Node* KthNode= nullptr;

    while(temp){

        KthNode= findKthNode(temp, k);

        if(KthNode == nullptr){

            if(prevNode)    prevNode -> next= temp;
            break;
        }

        nextNode= KthNode -> next;
        KthNode -> next= nullptr;
        KthNode= reverseList(temp);

        if(temp == head)    
            head= KthNode;

        else
            prevNode -> next= KthNode;
        
        prevNode= temp;
        temp= nextNode;
    }

    return head;
}

int main(){

    vector<int> v= {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
    int k;
    cin>>k;

    Node* head= createList(v);

    head= reverseKgroups(head, k);
    printList(head);

    return 0;
}