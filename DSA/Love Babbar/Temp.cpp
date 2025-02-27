// Implementation of Stack (Using Arrays)! [DONE]
// Implementation of Stack (Using Linked Lists)! [DONE]
// Implementation of 2 Stacks in an array! [DONE]
// Reverse a string using a Stack! [DONE]
// Delete middle element of the Stack!
// Check whether a valid parenthesis or not!
// Add an element at the bottom of the Stack!
// Reverse a Stack!
// Sort a Stack!
// Remove redundant brackets!
// Minimum Cost to Make a String Valid (Bracket Reversal Problem)!
// Find next smaller element!

// Delete middle element of the Stack!
#include<iostream>
#include<iostream>
using namespace std;

class Stack {
    private:
    int size;
    int* arr;
    int top;

    public:
    Stack(int size) {
        this->size = size;
        arr = new int[this->size];
        top = -1;
    }

    void push(int data) {
        if(size - top > 1) {
            top++;
            arr[top] = data;
        }
        else {
            cout<<"Stack Overflow!";
            return;
        }
    }

    void pop() {
        if(top == -1) {
            cout<<"Stack Underflow!"<<endl;
            return;
        }
        top--;
    }

    int peek() {
        if(top == -1) {
            cout<<"Stack Underflow!"<<endl;
            return -1;
        }
        return arr[top];
    }

    bool empty() {
        return (top == -1);
    }

    int getLen() {
        int len = 0;
        while(top != -1) {
            len++;
            top--;
        }
        return len;
    }
};

int solve(Stack& stk, int count, int size) {
    if(count == size/2) {
        
        return
    }
}

int getMiddleNode(Stack stk, int size) {
    int count = 0;
    solve(stk, count, size);
}

int main() {
    Stack stk(5);
    stk.push(1);
    stk.push(2);
    stk.push(3);
    stk.push(4);
    stk.push(5);
    int size = stk.getLen();
    getMiddle(stk, size);
}