// ------------------------------------------------------------- Lecture Notes Questions ---------------------------------------------------------------------->
// Problem 1 : Implement Stack using Arrays!
// Approach : We needed - Parameterized Constructor : For Stack building
//                      - Copy Constructor : So that we do not perform certain operations on the same stack, like while printing we need to pop, and if we do not use copy constructor, it will be shallow copy while passing the stack as argument in the print function, which maybe dangerous
//                      - Destructor : To destroy the stack after use.
//                      - General Operations like : push, pop, peek, isEmpty, isFull, stackSize.
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
        arr = new int[size];
        top = -1;
    }

    Stack(const Stack& other) { // Deep copy constructor!
        size = other.size;
        top = other.top;
        arr = new int[size];

        for(int i = 0; i <= top; i++) {
            arr[i] = other.arr[i];
        }
    }

    ~Stack() {
        delete []arr;
    }

    void push(int data) {
        if(top < size - 1) {
            top++;
            arr[top] = data;
            return;
        }
        else {
            cout<<"Stack Overflow!";
            return;
        }
    }

    void pop() {
        if(top >= 0) {
            top--;
            return;
        }
        else {
            cout<<"Stack Undeflow!";
            return;
        }
    }

    int peek() {
        if(top >= 0) {
            return arr[top];
        }
        else {
            cout<<"Empty List!";
            return 0;
        }
    }

    int stackSize() {
        return top + 1;
    }

    bool isEmpty() {
        return top == -1;
    }

    bool isFull() {
        return top == size - 1;
    }
};

void printStack(Stack st) {
    if(st.isEmpty()) {
        cout<<"Empty Stack!";
        return;
    }

    Stack temp = Stack(st); // Deep copy
    while(!temp.isEmpty()) {
        cout<<temp.peek()<<" ";
        temp.pop();
    }
}

int main() {
    Stack st1(5);
    st1.push(1);
    st1.push(2);
    st1.push(3);
    st1.push(4);
    st1.push(5);

    printStack(st1);
}

// Problem 2 : Implement Stack using Linked Lists!
// Approach : We needed top variable which will be a pointer to the top, can also use another variable as size to achieve the O(1) TC to find stack size.
//          : Same components are used here too, just as above, just with a slightly different approach due to presence of Linked List Nodes.
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

// Problem 3 : Implement Two Stacks in an Array!
// Problem 4 : Reverse a String using Stack!
// Problem 5 : Delete the middle node using Stack!
// Problem 6 : Add an element at bottom of the Stack!
// Problem 7 : Reverse a Stack!
// Problem 8 : Sort a Stack! - Without using Loop!

// ------------------------------------------------------------ Monotonic Stack Concept ----------------------------------------------------------------------->
// Question 1 : Find the next greater element for each element in an array!
// Thinking : Although this questions is a most traditional question for Monotonic Stack, we will try to solve it using brute force first!
// Approach 1 (Brute Force) : We will simple use nexted loop! and traverse the inner loop to check whether a next greater element exist for this current element!
//                          : If it exists, we will assign that element's value for it! otherwise we will simple insert -1 for that element.
//                          : Also, when we mean greater, it means strictly greater! even though array contains duplicates, we do not care! we will simple check strictly decreasing!
// Approach 2 (Decreasing Monotonic Stack) : We traverse the array from right to left, because we want to know the next (i.e., future) greater element. While going from right to left, we maintain a stack of potential candidates for the next greater element.
//                                         : Stack Rules : Stack stores elements in decreasing order (from top to bottom).
//                                                       : That means the top of the stack is always the smallest "greater" candidate available for the current element.
//                                         : For Example : arr = [4, 5, 2, 10, 8]
//                                                       : We start from right to left, and for each element : Pop all elements from the stack that are less than or equal to the current element.
//                                                                                                           : If the stack is not empty, the top is the next greater.
//                                                                                                           : If the stack is empty, then there's no greater → push -1 in result.
//                                                                                                           : Push current element to stack (to help future elements).
// Approach 1 (Brute Force)
#include<iostream>
#include<stack>
#include<vector>
using namespace std;

vector<int> nextGreaterElem1(vector<int> v) {
    vector<int> result;
    for(int i = 0; i < v.size(); i++) {
        int nextGreater = -1;
        for(int j = i; j < v.size(); j++) {
            if(v[j] > v[i]) {
                nextGreater = max(nextGreater, v[j]);
                break;
            }
        }
        result.push_back(nextGreater);
    }
    return result;
}

// Approach 2 (Monotonic Stack) :
vector<int> nextGreaterElem2(vector<int> v) {
    stack<int> st;
    int n = v.size();
    vector<int> result(n);
    
    for(int i = n - 1; i >= 0; i--) {
        while(!st.empty() && st.top() <= v[i]) {
            st.pop();
        }
        result[i] = st.empty() ? -1 : st.top(); // Ternary Alternative!
        st.push(v[i]);
    }
    return result;
}

int main() {
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) {
        cin>>arr[i];
    }
    // vector<int> ans = nextGreaterElem1(arr);
    vector<int> ans = nextGreaterElem2(arr);
    for(int i = 0; i < ans.size(); i++) {
        cout<<ans[i]<<" ";
    }
}

// Question 2 : Find the prev greater element for each element in an array!
// Thinking : We won't be writing the brute force approach this time! You can think of it before starting to code! We will simply write the optimized solution for this!
// Approach (Decreasing Monotonic Stack) : Logic is same as previous one, we are just start to insert into the vector from the beginning!
#include<iostream>
#include<stack>
#include<vector>
using namespace std;

vector<int> prevGreaterElem(vector<int> v) {
    stack<int> st;
    int n = v.size();
    vector<int> result(n);
    
    for(int i = 0; i < n; i++) {
        while(!st.empty() && st.top() <= v[i]) {
            st.pop();
        }
        result[i] = st.empty() ? -1 : st.top(); // Ternary Alternative!
        st.push(v[i]);
    }
    return result;
}

int main() {
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) {
        cin>>arr[i];
    }
    // vector<int> ans = nextGreaterElem1(arr);
    vector<int> ans = prevGreaterElem(arr);
    for(int i = 0; i < ans.size(); i++) {
        cout<<ans[i]<<" ";
    }
}

// Question 3 : Find the next smaller element for each element in an array!
// Thinking : We will simple use the same previous methods, that is monotonic stack! and here we will simply reverse the comparisons!
// Approach (Monotonic Increasing Stack.) : There is only one key difference from previous questions, Unlike Previous Greater or Next Greater questions that use a monotonic decreasing stack, here we want the next smaller element, so we use a monotonic increasing stack.
//                                        : Traverse the array from right to left, because we're looking for the "next" element.
//                                        : Maintain a stack where elements are in increasing order (top to bottom).
//                                        : For each element : While the stack is not empty and the top element is greater than or equal to the current element, pop it.
//                                                           : If the stack becomes empty → no smaller element → assign -1
//                                                           : Otherwise → stack top is the next smaller element
//                                                           : Push the current element to the stack for future comparisons.
#include<iostream>
#include<stack>
#include<vector>
using namespace std;

vector<int> prevSmallerElem(vector<int> v) {
    stack<int> st;
    int n = v.size();
    vector<int> result(n);
    
    for(int i = 0; i < n; i++) {
        while(!st.empty() && st.top() >= v[i]) {
            st.pop();
        }
        result[i] = st.empty() ? -1 : st.top(); // Ternary Alternative!
        st.push(v[i]);
    }
    return result;
}

vector<int> nextSmallerElem(vector<int> v) {
    stack<int> st;
    int n = v.size();
    vector<int> result(n);
    
    for(int i = n - 1; i >= 0; i--) {
        while(!st.empty() && st.top() >= v[i]) {
            st.pop();
        }
        result[i] = st.empty() ? -1 : st.top(); // Ternary Alternative!
        st.push(v[i]);
    }
    return result;
}

int main() {
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) {
        cin>>arr[i];
    }
    vector<int> ans1 = prevSmallerElem(arr);
    for(int i = 0; i < ans1.size(); i++) {
        cout<<ans1[i]<<" ";
    }

    vector<int> ans2 = nextSmallerElem(arr);
    for(int i = 0; i < ans2.size(); i++) {
        cout<<ans2[i]<<" ";
    }
}