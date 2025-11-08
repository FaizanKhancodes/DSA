#include<bits/stdc++.h>
using namespace std;

class minStack{

    public:

        stack<long long> st;
        long long mini= INT_MAX;

        minStack(){}

        void push(int val){

            if(st.empty()){

                st.push(val);
                mini= val;
            }

            else{

                if(val < mini){

                    st.push((long long)val*2 - mini);
                    mini= val;
                }

                else
                    st.push(val);
            }
        }

        void pop(){

            if(st.empty())
                return;

            long long x= st.top();
            st.pop();

            if(x < mini)
                mini= 2*mini - x;
        }

        int top(){

            if(st.empty())
                return -1;

            if(st.top() < mini)
                return mini;
                
            return st.top();
        }

        int getMin(){

            return mini;
        }

};

int main(){

    minStack* st= new minStack();

    st->push(6);
    st->push(9);
    st->push(2);
    cout<<st->getMin()<<" ";
    st->pop();
    cout<<st->top()<<" ";
    st->push(11);
    cout<<st->getMin()<<" ";

    return 0;
}