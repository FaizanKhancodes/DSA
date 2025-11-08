#include<bits/stdc++.h>
using namespace std;

class Node{

    public:

        int data;
        Node* next;
        Node* child;

        Node(int x){

            data= x;
            next= nullptr;
            child= nullptr;
        }

        Node(int x, Node* n, Node* c){

            data= x;
            next= n;
            child= c;
        }
};

Node* createFlattenedList(vector<int> v){

    int n= v.size();
    if(n == 0)
        return nullptr;

    Node* head= new Node(v[0]);
    Node* p= head;

    for(int i=1; i<n; i++){

        Node* temp= new Node(v[i]);
        p -> child= temp;
        p= p -> child;
    }

    return head;
}

void printFlattenedList(Node* p){

    while(p){

        cout<<p -> data<<" ";
        p= p -> child;
    }
    cout<<endl;
}

Node* create2DList(vector<vector<int>> v){

    int n1= v.size();
    int n2= v[0].size();

    Node* head= new Node(-1);
    Node* p= head;
    Node* q= head;

    for(int j=0; j<n2; j++){

         if(j == 0)
                head -> data= v[0][0];

        else{
            Node* temp= new Node(v[0][j]);
            p -> next= temp;
            p= temp;
            q= p;
        }

        for(int i=1; i<n1; i++){

            if(v[i][j] == -1)
                break;

            Node* temp= new Node(v[i][j]);
            q -> child= temp;
            q= temp;
        }
    }

    return head;
}

void print2DList(Node* head){

    Node* p= head;
    Node* q= head;

    while(p){

        q= p;
        while(q){

            cout<<q -> data<<" ";
            q= q -> child;
        }

        cout<<endl;
        p= p -> next;
    }
}

Node* flatten2DListBrute(Node* head){

    vector<int> v;
    Node* p= head;
    Node* q= head;

    while(p){

        q= p;
        while(q){

            v.push_back(q -> data);
            q= q -> child;
        }
        p= p -> next;
    }

    sort(v.begin(), v.end());
    Node* newHead= createFlattenedList(v);

    return newHead;
}

Node* merge2Lists(Node* List1, Node* List2){

    Node* dummy= new Node(-1);
    Node* curr= dummy;

    while(List1 && List2){

        if(List1 -> data < List2 -> data){

            curr -> child= List1;
            curr= curr -> child;
            List1= List1 -> child;
        }

        else{

            curr -> child= List2;
            curr= curr -> child;
            List2= List2 -> child;
        }
    }

    if(List1)
        curr -> child= List1;       
    
    else
        curr -> child= List2;

    Node* headMerged= dummy -> child;
    delete dummy;

    return headMerged;
}

Node* flatten2DListBetter(Node* head){

    Node* temp= head -> next;
    head -> next= nullptr;

    while(temp){

        head= merge2Lists(head, temp);
        Node* p= temp -> next;
        temp -> next= nullptr;
        temp= p;
    }

    return head;
}

Node* flatten2DListOptimal(Node* head){

    priority_queue<pair<int, Node*>, vector<pair<int, Node*>>, greater<pair<int, Node*>>> pq;
    Node* temp= head;

    Node* dummy= new Node(-1);
    Node* curr= dummy;

    while(temp){

        pq.push({temp -> data, temp});
        temp= temp -> next;
    }

    while(!pq.empty()){

        temp= pq.top().second;
        pq.pop();

        if(temp -> child)
            pq.push({temp -> child -> data, temp -> child});

        curr -> child= temp;
        curr= curr -> child;
    }

    head= dummy -> child;
    delete dummy;

    return head;
}

int main(){

    vector<vector<int>> v= {{ 3,  2,  1,  4,  5},       //   3 -> 2 -> 1 -> 4 -> 5 -> X
                            { 6, 10, 13,  7,  9},       //   |    |    |    |    |
                            { 8, 12, 16, 11, -1},       //   6    10   13   7    9
                            {-1, 20, 19, -1, -1},       //   |    |    |    |    |
                            {-1, -1, 22, -1, -1}};      //   8    12   16   11   X
                                                        //   |    |    |    |
                                                        //   X    20   19   X
                                                        //        |    |    
                                                        //        X    22
                                                        //             |
                                                        //             X
                                                        // The above is a 2D list

    Node* head1= create2DList(v);
    Node* head2= create2DList(v);

    Node* headBrute= flatten2DListBrute(head1);
    printFlattenedList(headBrute);

    Node* headBetter= flatten2DListBetter(head1);
    printFlattenedList(headBrute);

    Node* headOptimal= flatten2DListBetter(head2);
    printFlattenedList(headOptimal);

    return 0;
}