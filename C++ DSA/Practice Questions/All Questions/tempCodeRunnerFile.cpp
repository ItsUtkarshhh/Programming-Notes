#include<iostream>
using namespace std;

class Node {
    public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

class Stack {
    private:
    Node* top;

    public:
    Stack() {
        top = NULL;
    }

    Stack(const Stack& other) {
        if(other.top == NULL) {
            top = NULL;
            return;
        }

        // copy first node
        top = new Node(other.top->data);

        Node* currOther = other.top->next;
        Node* currThis = top;

        while(currOther != NULL) {
            currThis->next = new Node(currOther->data);
            currThis = currThis->next;
            currOther = currOther->next;
        }
    }

    ~Stack() {
        while(top != NULL) {
            Node* temp = top;
            top = top->next;
            temp->next = NULL;
            delete temp;
        }
    }

    void push(int data) {
        Node* newNode = new Node(data);
        newNode->next = top;
        top = newNode;
    }

    void pop() {
        if(top == NULL) {
            cout<<"Stack Underflow!";
            return;
        }
        Node* temp = top;
        top = top->next;
        temp->next = NULL;
        delete temp;
    }

    int peek() {
        if(top == NULL) {
            cout<<"Stack Underflow!";
            return -1;
        }
        return top->data;
    }

    int stackSize() { // Not Optimized, as it takes O(n) TC. Whereas in array implementation it was O(1) due to "top" variable, we can do that also here by simply using size istance variable and incrementing/decrementing it with push pop methods.
        if(top == NULL) {
            cout<<"Stack Underflow!";
            return -1;
        }
        Node* temp = top;
        int count = 0;
        while(temp != NULL) {
            count++;
            temp = temp->next;
        }
        return count;
    }

    bool isEmpty() {
        return top == NULL;
    }
};

void printStack(Stack st) {
    if(st.isEmpty()) {
        cout<<"Stack is Empty!";
        return;
    }

    Stack temp = st;
    while(!st.isEmpty()) {
        cout<<st.peek()<<" ";
        st.pop();
    }
}

int main() {
    Stack st1;
    st1.push(1);
    st1.push(2);
    st1.push(3);
    st1.push(4);
    st1.push(5);

    printStack(st1);
}