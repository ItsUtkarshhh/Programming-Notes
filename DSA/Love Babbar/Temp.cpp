// Implementation of Stack (Using Arrays)! [DONE]
// Implementation of Stack (Using Linked Lists)! [DONE]
// Implementation of 2 Stacks in an array! [DONE]
// Reverse a string using a Stack! [DONE]
// Delete middle element of the Stack! [DONE]
// Check whether a valid parenthesis or not! [DONE]
// Add an element at the bottom of the Stack! [DONE]
// Reverse a Stack! [DONE]
// Sort a Stack! [DONE]
// Remove redundant brackets! [DONE]
// Minimum Cost to Make a String Valid (Bracket Reversal Problem)!
// Find next smaller element!

// Minimum Cost to Make a String Valid (Bracket Reversal Problem)!
#include<iostream>
#include<stack>
#include<vector>
using namespace std;

void nextSmallerElement(vector<int> v1) {
    int size = v1.size();
    vector<int> ans(size, -1);
    stack<int> stk;
    stk.push(-1);
    for(int i = size-1; i>=0; i--) {
        int curr = v1[i];
        while(stk.top() >= curr) {
            stk.pop();
        }
        ans[i] = stk.top();
        stk.push(curr);
    }

    for(int i = 0; i < size; i++) {
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}

int main() {
    int size;
    cout<<"Enter size of array : ";
    cin>>size;
    vector<int> v1(size);
    cout<<"Enter elements of the array : ";
    for(int i = 0; i<size; i++) {
        cin>>v1[i];
    }
    cout<<"Final answer : ";
    nextSmallerElement(v1);
}