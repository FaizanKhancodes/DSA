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

void createListIntersection(Node* head1, Node* head2, int n){

    if(head1 == nullptr || head2 == nullptr)    
        return;
        
    Node* temp1= head1;
    Node* temp2= head2;

    while(n-1){

        n--;
        temp1= temp1 -> next;
    }

    while(temp2 -> next)
        temp2= temp2 -> next;

    temp2 -> next= temp1;
}

int listSize(Node* p){

    int len= 0;
    while(p){

        len++;
        p= p -> next;
    }

    return len;
}

Node* findPosition(Node* temp, int n){

    while(n){

        n--;
        temp= temp -> next;
    }

    return temp;
}

Node* intersectionPoint(Node* head1, Node* head2){

    int len1= listSize(head1), len2= listSize(head2);
    Node* temp1= head1;
    Node* temp2= head2;

    int n= abs(len1 - len2);

    if(len1 >= len2)    
        temp1= findPosition(head1, n);
    else   
        temp2= findPosition(head2, n); 

    while(temp1 && temp2){

        if(temp1 == temp2)
            return temp1;

        temp1= temp1 -> next;
        temp2= temp2 -> next;
    }

    return nullptr;
}

Node* intersectionPointOptimal(Node* head1, Node* head2){

    if(head1 == nullptr ||  head2 == nullptr)
        return nullptr;

    Node* temp1= head1;
    Node* temp2= head2;

    while(temp1 != temp2){

        temp1= temp1 -> next;
        temp2= temp2 -> next;

        if(temp1 == temp2)
            return temp1;

        if(temp1 == nullptr)
            temp1= head2;
        
        else if(temp2 == nullptr)
            temp2= head1;
    }

    return temp1;
}

int main(){

    vector<int> v1= {1, 5, 4, 9, 2, 7, 3, 5};
    vector<int> v2= {4, 1, 13};

    int n;
    cin>>n;     // n <= v1.size()

    Node* head1= createList(v1);
    Node* head2= createList(v2);

    if(n <= v1.size())
        createListIntersection(head1, head2, n);

    Node* p= intersectionPoint(head1, head2);
    if(p)   cout<<p -> data<<" ";

    Node* q= intersectionPointOptimal(head1, head2);
    if(q)   cout<<q -> data;

    return 0;
}