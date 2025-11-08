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

Node* MergeKListsBrute(vector<Node*> lists){

    vector<int> v;
    for(int i=0; i<lists.size(); i++){

        Node* temp= lists[i];

        while(temp){

            v.push_back(temp -> data);
            temp= temp -> next;
        }
    }

    sort(v.begin(), v.end());
    Node* head= createList(v);

    return head;
}

Node* merge(Node* list1, Node* list2){

    Node* dummy= new Node(-1);
    Node* temp= dummy;

    while(list1 && list2){

        if(list1 -> data < list2 -> data){

            temp -> next= list1;
            temp= list1; 
            list1= list1 -> next;
        }

        else{

            temp -> next= list2;
            temp= list2;
            list2= list2 -> next;
        }
    }

    if(list1)
        temp -> next= list1;
    else
        temp -> next= list2;

    return dummy -> next;
}

Node* MergeKListsBetter(vector<Node*> lists){

    Node* list1= lists[0];

    for(int i=1; i<lists.size(); i++){

        Node* list2= lists[i];
        list1= merge(list1, list2);
    }

    return list1;
}

Node* MergeKListsOptimal(vector<Node*> lists){

    priority_queue<pair<int, Node*>, vector<pair<int, Node*>>, greater<pair<int, Node*>>> pq;

    for(int i=0; i<lists.size(); i++)
        pq.push({lists[i] -> data, lists[i]});

    Node* dummy= new Node(-1);
    Node* temp= dummy;

    while(!pq.empty()){

        auto it= pq.top();
        pq.pop();

        temp ->next= it.second;
        temp= temp -> next;

        if(temp -> next)
            pq.push({temp -> next -> data, temp ->next});
    }

    return dummy -> next;
}

int main(){

    vector<int> v1= {3, 6, 10, 14};
    vector<int> v2= {2, 6, 9, 13, 18};
    vector<int> v3= {7, 11};
    vector<int> v4= {5, 7, 8, 14};
    vector<int> v5= {1, 10, 15};

    Node* head1= createList(v1);
    Node* head2= createList(v2);
    Node* head3= createList(v3);
    Node* head4= createList(v4);
    Node* head5= createList(v5);

    vector<Node*> lists= {head1, head2, head3, head4, head5};

    // Node* head= MergeKListsBrute(lists);

    // Node* head= MergeKListsBetter(lists);

    Node* head= MergeKListsOptimal(lists);
    printList(head);
    
    return 0;
}