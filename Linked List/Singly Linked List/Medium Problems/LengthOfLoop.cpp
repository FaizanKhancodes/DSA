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
            next= nullptr;
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

Node* createListWithLoop(vector<int> v){

    int n= v.size();

    Node* head= new Node(v[0]);
    Node* p= head;

    for(int i=1; i<n; i++){

        Node* temp= new Node(v[i]);
        p -> next= temp;
        p= temp;
    }

    p -> next= head -> next -> next;
    
    return head;
}

int loopLengthBrute(Node* head){

    unordered_map<Node*, int> mp;

    Node* p= head;
    while(p){

        if(mp.find(p) != mp.end()){

            Node* q= p -> next;
            int count= 1;
            while(q != p){

                count++;
                q= q -> next;
            }

            return count;
        }

        mp[p]= 1;
        p= p -> next;
    }
    
    return 0;
}

int loopLengthOptimal(Node* head){

    Node* slow= head;
    Node* fast= head;

    while(fast != nullptr && fast -> next != nullptr){

        slow= slow -> next;
        fast= fast -> next -> next;

        if(fast == slow){

            int count= 1;
            slow= slow -> next;
            while(slow != fast){

                slow= slow -> next;
                count++;
            }

            return count;
        }
    }

    return 0;
}

int main(){

    vector<int> v= {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    Node* head1= createListWithLoop(v);
    Node* head2= createList(v);

    cout<<loopLengthBrute(head2)<<" "<<loopLengthOptimal(head1);

    return 0;
}