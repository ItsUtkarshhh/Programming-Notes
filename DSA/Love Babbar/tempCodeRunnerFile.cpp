#include<iostream>
// #include<stack>
using namespace std;

class Stack {
    private:
    int top;
    int* arr;
    int size;
    
    public:
    Stack(int size) {
        this->size = size;
        arr = new int[this->size];
        top = -1;
    }

    void push(int data) {
        if(size - top > 1) {
            arr[top] = data;
            top++;
        }
        else {
            cout<<"Stack Overflow";
        }
    }

    void pop() {
        if(top >= 0) {
            top--;
        }
        else {
            cout<<"Stack Underflow";
        }
    }

    void peek() {
        if(top >= 0) {
            cout<<arr[top];
        }
        else {
            cout<<"Stack Underflow";
        }
    }

    bool empty() {
        return top == -1;
    }
};

int main() {
    Stack st1(4);
    st1.push(1);
    st1.push(2);
    st1.push(3);
    st1.push(4);
    st1.push(5);

    cout<<endl;
    
    st1.pop();
    st1.pop();
    st1.pop();
    st1.pop();
    st1.pop();
}