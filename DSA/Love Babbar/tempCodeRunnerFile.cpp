#include<iostream>
#include<stack> // You can use Stack Implementation rather than using STL! Its your choice!
using namespace std;

void sortedInsert(stack<int> &inputStack, int num) {
    // Base case
    if(inputStack.empty() || (!inputStack.empty() && inputStack.top() < num)) {
        inputStack.push(num);
        return;
    }
    int n = inputStack.top();
    inputStack.pop();

    // recursive call
    sortedInsert(inputStack, num);
    inputStack.push(n);
}

void sortStack(stack<int> &inputStack) {
    // Base case
    if(inputStack.empty()) {
        return;
    }
    int num = inputStack.top();
    inputStack.pop();

    // recursive call
    sortStack(inputStack);
    sortedInsert(inputStack, num);
}

void printStack3(stack<int> stk) {
    while (!stk.empty()) {
        cout << stk.top() << " ";
        stk.pop();
    }
    cout << endl;
}

int main() {
    stack<int> stk;
    stk.push(1);
    stk.push(5);
    stk.push(3);
    stk.push(2);
    stk.push(4);

    cout << "Original stack st1 : ";
    printStack3(stk);

    sortStack(stk);

    cout << "After sorting the stack st1 : ";
    printStack3(stk);
}