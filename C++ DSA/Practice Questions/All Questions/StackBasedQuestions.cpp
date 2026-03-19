// ------------------------------------------------------------- Lecture Notes Questions ---------------------------------------------------------------------->
// Problem 1 : Implement Stack using Arrays!
// Approach : We needed - Parameterized Constructor : For Stack building
//                      - Copy Constructor : So that we do not perform certain operations on the same stack, like while printing we need to pop, and if we do not use copy constructor, it will be shallow copy while passing the stack as argument in the print function, which maybe dangerous
//                      - Destructor : To destroy the stack after use.
//                      - General Operations like : push, pop, peek, isEmpty, isFull, stackSize.
//                      - Kept size, array and top private, so that no one access these things, and the stack structure will remain intact. You can never create a literal stack in the memory, you can only use certain data structures to make it behave like stacks and these data structures can be more or less only two Arrays & LinkedLists.
#include<iostream>
using namespace std;

class Stack {
    private:
    int size;
    int* arr; // You can also do this "int* arr = NULL", when only when there is some constructor which is not init the arr, but as of now there is no constructor which is not init the array! So you dont need it here!
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

    Stack& operator=(const Stack& other) { // Deep copy using assignment operator, otherwise assignment operator would be doing deep copy!
        if(this == &other) return *this;

        delete[] arr;

        size = other.size;
        top = other.top;

        arr = new int[size];

        for(int i = 0; i <= top; i++) {
            arr[i] = other.arr[i];
        }

        return *this;
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
            Node* newNode = new Node(currOther->data);
            currThis->next = newNode;
            currThis = newNode;
            currOther = currOther->next;
        }
    }

    Stack& operator=(const Stack &other) {
        if(this == &other) return *this;

        while(top != NULL) {
            Node* temp = top;
            top = top->next;
            delete temp;
        }

        if(other.top == NULL) {
            top = NULL;
            return *this;
        }

        top = new Node(other.top->data);
        Node* currThis = top;
        Node* currOther = other.top->next;

        while(currOther != NULL) {
            Node* newNode = new Node(currOther->data);
            currThis->next = newNode;
            currThis = newNode;
            currOther = currOther->next;
        }
        return *this;
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

    // Stack temp = st; // It will make 3 copies of the same stack, one is the original stack, one st and one temp.
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
// Approach : Implemented two stacks using a single dynamic array to optimize space utilization.
//          : Maintained two pointers : top1 → grows from left to right for Stack A & top2 → grows from right to left for Stack B.
//          : Ensured no overflow by checking : top2 - top1 > 1 → guarantees at least one free space between stacks.
//          : Primary operations : push, pop, peek, size
//          : Memory Management : Implemented deep copy using - Copy constructor & Copy assignment operator
//                              : Ensured strong exception safety in assignment : Allocate new memory first → then delete old memory
//                              : Destructor properly releases allocated memory using delete[].
//                              : Followed Rule of 3 to avoid memory leaks and double deletion : Rule of 3 : Parameterized Constructor, Copy Constructor & Operator Overloading.
//          : Additionally : Added "const" correctness for read-only methods
//                         : Handled edge cases : Stack underflow, Stack overflow
//                         : Provided utility methods : isEmpty, isFull, stackSize
//          : TC : O(1) for all operations & SC : O(n) for shared memory space
//          : Catch : In the array version, you can't really separate the two stacks as they share the same same memory within the same data structure.
//                  : But in the Linked List version (if you implement someday), you can actually separate the two lists, as they will not share the same memory, just the same ownership which is of TwoStack class.
//                  : In the linked list implementation, TwoStacks maintains pointers to two independent linked lists stored on heap. These lists are logically grouped within the class but are physically independent in memory and can operate independently.
#include<iostream>
using namespace std;

class TwoStacks {
    private:
    int size;
    int* arr;
    int top1;
    int top2;

    public:
    TwoStacks(int size) {
        this->size = size;
        arr = new int[size];
        top1 = -1;
        top2 = size;
    }

    TwoStacks(const TwoStacks& other) { // Copy constructor to deep copy both the stacks into a new memory space!
        if(other.isEmpty()) {
            size = other.size;
            top1 = -1;
            top2 = size;
            arr = new int[size];
            return;
        }

        size = other.size;
        top1 = other.top1;
        top2 = other.top2;

        arr = new int[size];
        for(int i = 0; i <= top1; i++) {
            arr[i] = other.arr[i];
        }
        for(int i = top2; i < other.size; i++) {
            arr[i] = other.arr[i];
        }
    }

    TwoStacks& operator=(const TwoStacks& other) { // Overloading "=" to deep copy both the stacks into a new memory space.
        if(this == &other) {
            return *this;
        }

        int* newArray = new int[other.size];
        // Better approach because : Allocate new memory first, If allocation fails (throws bad_alloc), original array remains intact, Prevents object from going into invalid state
        // Overall, Provides strong exception safety - You can follow the same path in other places also, so that you learn to write safe programs.

        for(int i = 0; i <= other.top1; i++) {
            newArray[i] = other.arr[i];
        }
        for(int i = other.top2; i < other.size; i++) {
            newArray[i] = other.arr[i];
        }

        delete []arr;

        arr = newArray;
        size = other.size;
        top1 = other.top1;
        top2 = other.top2;

        return *this;
    }

    ~TwoStacks() {
        delete []arr;
    }

    void pushA(int data) {
        if(top2 - top1 > 1) {
            top1++;
            arr[top1] = data;
        }
        else {
            cout<<"Stack Overflow!";
            return;
        }
    }

    void pushB(int data) {
        if(top2 - top1 > 1) {
            top2--;
            arr[top2] = data;
        }
        else {
            cout<<"Stack Overflow!";
            return;
        }
    }

    void popA() {
        if(top1 == -1) {
            cout<<"Stack Underflow";
            return;
        }
        top1--;
    }

    void popB() {
        if(top2 == size) {
            cout<<"Stack Underflow";
            return;
        }
        top2++;
    }

    int peekA() const {
        if(top1 == -1) {
            cout<<"Stack Underflow!";
            return -1;
        }
        return arr[top1];
    }

    int peekB() const {
        if(top2 == size) {
            cout<<"Stack Underflow!";
            return -1;
        }
        return arr[top2];
    }

    bool isFullA() const { // Adding "const" as because it becomes more safe for these methods to be used with objects which are of const type. As const type objects or variables work with const type methods.
        return top1 == top2 - 1;
    }

    bool isFullB() const {
        return top2 == top1 + 1;
    }

    bool isEmpty() const {
        return top1 == -1 && top2 == size;
    }

    bool isEmptyA() const {
        return top1 == -1;
    }

    bool isEmptyB() const {
        return top2 == size;
    }

    int stackSizeA() const {
        return top1 + 1;
    }

    int stackSizeB() const {
        return size - top2;
    }
};

void printTwoStacks(TwoStacks st) { // Similarly you can create function which can print individual stack too!
    if(!st.isEmptyA()) {
        cout<<"Stack A : ";
        while(!st.isEmptyA()) {
            cout<<st.peekA()<<" ";
            st.popA();
        }
        cout<<endl;
    }
    else {
        cout<<"A Stack is Empty!";
        return;
    }

    if(!st.isEmptyB()) {
        cout<<"Stack B : ";
        while(!st.isEmptyB()) {
            cout<<st.peekB()<<" ";
            st.popB();
        }
        cout<<endl;
    }
    else {
        cout<<"B Stack is Empty!";
        return;
    }
}

int main() {
    TwoStacks st1(10);

    st1.pushA(1);
    st1.pushA(2);
    st1.pushA(3);
    st1.pushA(4);
    st1.pushA(5);
    st1.pushA(6);

    st1.pushB(10);
    st1.pushB(9);
    st1.pushB(8);
    st1.pushB(7);

    cout<<"Two Stack 1 : ";
    printTwoStacks(st1);
    cout<<endl;
    
    cout<<"Two Stack 2 : ";
    TwoStacks st2 = st1; // Copy constructor will be called.
    printTwoStacks(st2);
    cout<<endl;
    
    TwoStacks st3(4);
    st3.pushA(1);
    st3.pushA(2);
    st3.pushA(3);
    st3.pushB(4);
    
    TwoStacks st4(4);
    st4.pushA(10);
    st4.pushA(20);
    st4.pushA(30);
    st4.pushB(40);
    
    st4 = st3; // Assignment operator, hence operator overloading will work.
    cout<<"Two Stack 3 : ";
    printTwoStacks(st4);
    cout<<endl;
}

// Problem 4 : Reverse a String using Stack!
// Approach : Simple input in the stack & then output and store in the same string.
#include<iostream>
#include<stack>
#include<string>
using namespace std;

string reverseStringUsingStack(string str) {
    if(str.empty()) {
        return "";
    }

    stack<char> st;
    int i = 0;
    while(i < str.length()) {
        st.push(str[i]);
        i++;
    }

    i = 0;
    while(i < str.length()) {
        str[i] = st.top();
        st.pop();
        i++;
    }
    return str;
}

int main() {
    string str;
    cin>>str; // If want to take a line with whitespaces as input, use : getline(cin, str);

    cout<<reverseStringUsingStack(str);
}

// Problem 5 : Delete the middle node using Stack!
// Approach : Iterative Way : Pop items above the stack, until you reach middle element, and then restore them back using an additional data structure, array, linkedlist, stack or another data structure of your choice.
//          : Recursive Way : Pop items recursively and then call for recursion and then establish a base case for when you reach the middle & then pop the middle element and then return and restore the above elements.
// Note : We oftenly say, that Anything solvable with loops can be solved with recursion & Anything solvable with loops can be solved with recursion
//      : But its slight theortical, as because they are NOT always interchangeable easily.
//      : As of this question, you can solve it easily with recursion, but cannot without using any extra space & loops - because implicitly this question needs some data structure to store the popped items from the stack, so that they can be restored and there is no otherway to reach to the middle element without popping the ones above it.
//      : Hence, the correct statement is : "Anything done with recursion can be done with loops — if you allow equivalent extra space" - As internally recursion uses some extra spaces in form of function call stack.
#include<iostream>
#include<stack>
using namespace std;

void removeMiddle(stack<int> &st) {
    if(st.empty()) {
        cout<<"Empty Stack!";
        return;
    }
    
    int mid = st.size() / 2;
    stack<int> temp;

    for(int i = 0; i < mid; i++) {
        temp.push(st.top());
        st.pop();
    }

    st.pop();

    while(!temp.empty()) {
        st.push(temp.top());
        temp.pop();
    }
}

void removeMiddle2Helper(stack<int> &st, int count, int size) {
    if(count == size / 2) {
        st.pop();
        return;
    }

    int val = st.top();
    st.pop();
    removeMiddle2Helper(st, count + 1, size);
    st.push(val);
}

void removeMiddle2(stack<int> &st) {
    if(st.empty()) {
        cout<<"Empty Stack!";
        return;
    }
    int count = 0;
    int size = st.size();
    removeMiddle2Helper(st, count, size);
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

    removeMiddle2(st);
    printStack(st);
}

// Problem 6 : Add an element at bottom of the Stack!
// Approach : Similar approach as of the previous middle node deletion logic.
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

// Problem 7 : Reverse a Stack!
// Problem 8 : Sort a Stack! - Without using Loop!
// Problem 9 : Valid Parentheses!
// Problem 10 : Remove redudant brackets!
// Problem 11 : Minimum Cost to Make a String Valid (Bracket Reversal Problem)
// Problem 12 : Next smaller element! Next greater element!
// Problem 13 : Next previous element! Next previous element!
// Problem 14 : You are given a histogram where each bar represents a rectangle of the same width but with different heights. Your task is to find the largest rectangular area that can be formed using one or more consecutive bars.

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