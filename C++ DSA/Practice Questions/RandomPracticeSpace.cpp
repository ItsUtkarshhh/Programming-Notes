#include<iostream>
using namespace std;

class Stack {
    public:
    int* arr;
    int size;
    int top;

    Stack(int size) {
        this->size = size;
        this->arr = new int[size];
        top = -1;
    }

    ~Stack() {
        delete[] arr;
    }

    void push(int data) {
        if(top == size - 1) {
            cout<<"Stack Overflow!";
            return;
        }
        top++;
        arr[top] = data;
    }

    int pop() {
        if(top == -1) {
            cout<<"Stack Underflow!";
            return -1;
        }
        int poppedVal = arr[top];
        top--;
        return poppedVal;
    }

    int peek() {
        if(top == -1) {
            cout << "Stack Empty!";
            return -1;
        }
        return arr[top];
    }

    bool isEmpty() {
        return top == -1;
    }

    bool isFull() {
        return top == size - 1;
    }

    int stackSize() {
        return size;
    }
};

class Stack {
    public:
    int* arr;
    int size;
    int top;

    Stack(int size) {
        this->size = size;
        this->arr = new int[size];
        top = -1;
    }

    ~Stack() {
        delete[] arr;
    }

    void push(int data) {
        if(top == size - 1) {
            cout<<"Stack Overflow!";
            return;
        }
        top++;
        arr[top] = data;
    }

    int pop() {
        if(top == -1) {
            cout<<"Stack Underflow!";
            return -1;
        }
        int poppedVal = arr[top];
        top--;
        return poppedVal;
    }

    int peek() {
        if(top == -1) {
            cout << "Stack Empty!";
            return -1;
        }
        return arr[top];
    }

    bool isEmpty() {
        return top == -1;
    }

    bool isFull() {
        return top == size - 1;
    }

    int stackSize() {
        return size;
    }
};

void printStack(Stack st) {
    if(st.stackSize() == 0) {
        cout<<"Empty Stack!";
        return;
    }

    while(!st.isEmpty()) {
        cout<<st.peek()<<" ";
        st.pop();
    }
}

int main() {
    Stack st(5);
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);

    printStack(st);
}