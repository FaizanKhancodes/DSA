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
    Node*  p= head;

    for(int i=1; i<n; i++){

        Node* temp= new Node(v[i]);
        p -> next= temp;
        p= temp;
    }

    return head;
}

Node* createListWithLoop(vector<int> v){

    int n= v.size();
    Node* head= new Node(v[0]);
    Node*  p= head;

    for(int i=1; i<n; i++){

        Node* temp= new Node(v[i]);
        p -> next= temp;
        p= temp;
    }
    p -> next= head -> next -> next;
    return head;
}

bool detectLoopBrute(Node* head){

    unordered_map<Node*, bool> mp;
    Node* p= head;

    while(p){

        if(mp.find(p) != mp.end())
            return true;

        mp[p]= 1;
        p= p -> next;
    }

    return false;
}

bool detectLoopOptimal(Node* head){

    Node* fast= head;
    Node* slow= head;

    while(fast != nullptr  &&  fast -> next != nullptr){

        fast= fast -> next -> next;
        slow= slow -> next;

        if(fast == slow)
            return true;
    }

    return false;
}

int main(){

    vector<int> v= {3, 5, 9, 4, 10, 2, 17, 6, 8, 12};

    Node* head1= createList(v);
    Node* head2= createListWithLoop(v);

    cout<<detectLoopBrute(head1)<<" "<<detectLoopOptimal(head2);

    return 0;
}