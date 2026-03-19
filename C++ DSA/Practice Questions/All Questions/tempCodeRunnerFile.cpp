#include<iostream>
#include<stack>
using namespace std;

void addBottomOfStack(stack<int> &st, int value) {
    if(st.empty()) {
        cout<<"Empty stack!";
        return;
    }

    stack<int> temp;
    while(!st.empty()) {
        temp.push(st.top());
        st.pop();
    }

    st.push(value);

    while(!temp.empty()) {
        st.push(temp.top());
        temp.pop();
    }
}

void addBottomOfStack2Helper(stack<int> &st, int value) {
    if(st.empty()) {
        st.push(value);
        return;
    }
    int val = st.top();
    st.pop();
    addBottomOfStack2Helper(st, value);
    st.push(val);
}

void addBottomOfStack2(stack<int> &st, int value) {
    if(st.empty()) {
        cout<<"Empty stack!";
        return;
    }
    addBottomOfStack2Helper(st, value);
}

void printStack(stack<int> st) {
    if(st.empty()) {
        cout<<"Empty Stack!";
        return;
    }

    while(!st.empty()) {
        cout<<st.top()<<" ";
        st.pop();
    }
}

int main() {
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);

    int val;
    cin>>val;

    addBottomOfStack2(st, val);
    printStack(st);
}