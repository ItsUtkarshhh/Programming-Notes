// ------------------------------------------------------- Stack Questions ------------------------------------------------------------------------>
// ------------------------------------------------------- Problem 1 : Implement a stack using arrays ------------------------------------------------------------------------>
// Pattern Recognition : "Stack Basics"
// Difficulty : "Easy"
// Problem Statement : Implement a stack data structure using arrays.
// Understand the problem : Implement a Last-In, First-Out (LIFO) data structure using a fixed-size array in C++.
//                        : The implementation must support basic stack operations while handling boundary conditions (overflow and underflow) to ensure memory safety.
//                        : Required : push, pop, peek, isEmpty & isFull methods.
//                        : Why we actually require stack : In a regular array, you can access any index at any time ($O(1)$ access). This sounds good, but in complex systems, this "freedom" can lead to bugs. A Stack says: "You are only allowed to care about the very last thing that happened."
//                        : Use cases : The "Undo" Button: When you press Ctrl+Z, the computer doesn't care what you did 10 minutes ago; it cares about the very last action you performed. That action is "popped" off the stack.
//                                    : Function Calls (The Call Stack): When a function calls another function, the CPU "pushes" the current address onto a stack. When the function finishes, it "pops" that address to remember where to return.
//                                    : Expression Evaluation: Compilers use stacks to parse math and logic, ensuring that parentheses are closed in the correct order.
//                        : TC = O(1) && SC = O(n) - n = max size of the stack.
class Stack {
    private:
    int* arr;
    int size;
    int top;
    
    public:
    Stack(int size) {
        this->top = -1;
        this->size = size;
        arr = new int[size];
    }
    
    void push(int data) {
        if(top == size - 1) {
            cout<<"Stack Overflow";
            return;
        }
        top++;
        arr[top] = data;
    }
    
    void pop() {
        if(top == -1) {
            cout<<"Stack Undeflow";
            return;
        }
        top--;
    }
    
    int peek() {
        if(top == -1) {
            cout<<"Empty stack!";
            return -1;
        }
        return arr[top];
    }
    
    bool isEmpty() {
        return top == -1;
    }
    
    bool isFull() {
        return top == size;
    }
};

// ------------------------------------------------------- Problem 2 : Implement a stack using Linked List ------------------------------------------------------------------------>
// Pattern Recognition : "Stack Basics"
// Difficulty : "Easy"
// Problem Statement : Implement a stack data structure using linked list.
// Understand the problem : Implement a Last-In, First-Out (LIFO) data structure using a singly linked list in C++.
//                        : The stack should dynamically grow/shrink (no fixed size). All operations must work in O(1) time.
//                        : Proper handling of underflow (empty stack) is required, overflow is not predefined but may occur due to memory exhaustion
//                        : TC = O(1) && SC = O(n) - n = max size of the stack.
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
        this->top = NULL; // Or can simply use top = NULL;
    }
    
    ~Stack() {
        while(top != NULL) {
            Node* temp = top;
            top = top->next;
            delete temp;
        }
    }
    
    void push(int data) {
        Node* newNode = new Node(data);
        if(top == NULL) { // We don't actually need this condition, as without this also the logic will work correctly. Can remove it.
            top = newNode;
            return;
        }
        newNode->next = top;
        top = newNode;
        return;
    }
    
    void pop() {
        if(top == NULL) {
            cout<<"Stack Underflow";
            return;
        }
        Node* temp = top;
        top = top->next;
        delete temp;
        return;
    }
    
    int peek() {
        if(top == NULL) return -1; // Can use ternary operator too!
        return top->data;
    }
    
    bool isEmpty() {
        return top == NULL;
    }
};

// Note : Stack using Arrays : Pros - Cache-friendly & faster in practice, Simple implementation & Less memory overhead
//                           : Cons - Fixed size (if static array), Resizing cost (if dynamic array) & Wasted memory
//      : Stack using Linked List : Prps : Dynamic size, No resizing cost & Efficient memory usage (on demand).
//                                : Cons : Extra memory per node, Slower in practice due to heap allocation & More complex
//      : The std:stack used in C++ STL is based on Deque data structure, where the std:stack is just the container adapter and the deque is the underlying data structure where stack imposes retrictions to the data access.

// ------------------------------------------------------- Problem 3 : Implement a two stacks using arrays ------------------------------------------------------------------------>
// Pattern Recognition : "Stack Basics"
// Difficulty : "Easy"
// Problem Statement : Implement two stacks in a single array such that both stacks utilize the array efficiently without wasting space.
// Understand the problem : You are given a fixed-size array of size n, Instead of creating two separate arrays (wasting space), you must : Use one array & Maintain two stacks growing toward each other.
//                        : One stack, Stack1 grows from left → right & another stack, Stack2 grows from right → left.
//                        : TC = O(1) && SC = O(n) - n = max size of the stack.
class TwoStack {
    private:
    int* arr;
    int top1;
    int top2;
    int size;
    
    public:
    TwoStack(int size) {
        this->size = size; // "this" keyword is important as it can cause ambiguity between the parameter "size" and private variable "size"
        arr = new int[size];
        top1 = -1;
        top2 = size;
    }
    
    ~TwoStack() {
        delete[] arr;
    }
    
    void push1(int data) {
        if(top2 - top1 == 1) {
            cout<<"Stack Overflow";
            return;
        }
        top1++;
        arr[top1] = data;
    }
    
    void push2(int data) {
        if(top2 - top1 == 1) {
            cout<<"Stack Overflow";
            return;
        }
        top2--;
        arr[top2] = data;        
    }
    
    void pop1() {
        if(top1 == -1) {
            cout<<"Stack Underflow";
            return;
        }
        top1--;
    }
    
    void pop2() {
        if(top2 == size) {
            cout<<"Stack Underflow";
            return;
        }
        top2++;
    }
    
    int peek1() {
        if(top1 == -1) return -1;
        return arr[top1];
    }
    
    int peek2() {
        if(top2 == size) return -1;
        return arr[top2];
    }
    
    bool isFull() {
        return top2 - top1 == 1;
    }
    
    bool isEmpty() { // To check if the whole stack is empty or not
        return top2 - top1 == size + 1;
    }
    
    bool isEmpty1() {
        return top1 == -1;
    }
    
    bool isEmpty2() {
        return top2 == size;
    }
};

// ------------------------------------------------------- Problem 4 : Implement a two stacks using Linked List ------------------------------------------------------------------------>
// Pattern Recognition : "Stack Basics"
// Difficulty : "Easy"
// Problem Statement : Implement two independent stacks using linked lists such that both stacks support standard stack operations efficiently.
// Understand the problem : You need to implement two stacks, Each stack follows LIFO (Last-In, First-Out).
//                        : Unlike arrays : No fixed size, No need to share memory manually & each stack will grow independently using dynamic memory
//                        : TC = O(1) && SC = O(n1 + n2)
class Node {
    public:
    int data;
    Node* next;
    
    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

class TwoStack {
    private:
    Node* top1;
    Node* top2;
    
    public:
    TwoStack() {
        top1 = NULL;
        top2 = NULL;
    }
    
    ~TwoStack() {
        while(top1 != NULL) {
            Node* temp = top1;
            top1 = top1->next;
            delete temp;
        }
        while(top2 != NULL) {
            Node* temp = top2;
            top2 = top2->next;
            delete temp;
        }
    }
    
    void push1(int data) {
        Node* newNode = new Node(data);
        newNode->next = top1;
        top1 = newNode;
    }
    
    void push2(int data) {
        Node* newNode = new Node(data);
        newNode->next = top2;
        top2 = newNode;
    }
    
    void pop1() {
        if(top1 == NULL) {
            cout<<"Stack Underflow";
            return;
        }
        Node* temp = top1;
        top1 = top1->next;
        delete temp;
        return;
    }
    
    void pop2() {
        if(top2 == NULL) {
            cout<<"Stack Underflow";
            return;
        }
        Node* temp = top2;
        top2 = top2->next;
        delete temp;
        return;
    }
    
    int peek1() {
        if(top1 == NULL) {
            cout<<"Stack Underflow";
            return -1;
        }
        return top1->data;
    }
    
    int peek2() {
        if(top2 == NULL) {
            cout<<"Stack Underflow";
            return -1;
        }
        return top2->data;
    }
    
    bool isEmpty1() {
        return top1 == NULL;
    }
    
    bool isEmpty2() {
        return top2 == NULL;
    }
};

// Note : Implementing two stacks using linked lists doesn’t add anything special, because it simply results in two independent stacks with their own top pointers.

// ------------------------------------------------------- Problem 5 : Reverse a String using Stack ------------------------------------------------------------------------>
// Pattern Recognition : "Stack Basics"
// Difficulty : "Easy"
// Problem Statement : Reverse a string using a stack
// Understand the Problem : Simply reverse the string which you get using a stack., as stack follows the LIFO principle, so this reverse logic simply fits with the stack.
// Approach : Push all characters of the string into the stack, pop characters one by one & build the reversed string.
//          : O(n) && O(n)
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

// ------------------------------------------------------- Problem 6 : Delete the middle node using Stack ------------------------------------------------------------------------>
// Pattern Recognition : "Stack Basics"
// Difficulty : "Easy"
// Problem Statement : Delete the middle element of a stack without disturbing the order of other elements.
// Understand the Problem : Given a stack of size n, remove the middle element by finding the middle index = n/2 (0-based from top OR bottom—be consistent).
//                        : Remaining elements must retain original order.
//                        : Hence, stack does not allow random access, we need to use some extra space. Hence either explicit extra space or implicit extra space using recursion.
// Approach 1 : Find size n, pop elements until reaching middle, skip middle element & store others temporarily & push back to original stack
//            : TC = O(n) && SC = O(n)
// Approach 2 : Use recursion to traverse the stack until the middle element is reached. At each step, store the top element and pop it to move deeper into the stack.
//            : When the recursion reaches the middle (count == size/2), remove that element. During the unwinding phase (backtracking), push the stored elements back onto the stack.
//            : This restores the original order except for the removed middle element.
//            : TC = O(n) && SC = O(n)

// Approach 1 :
void removeMiddle(stack<int> &st) {
    if(st.empty()) {
        cout<<"Empty Stack!";
        return;
    }

    int n = st.size();
    int mid = n/2;

    stack<int> temp;
    int count = 0;
    while(!st.empty()) {
        if(count == mid) {
            st.pop();
            count++;
            // continue; // Its not needed
        }
        temp.push(st.top());
        st.pop();
        count++;
    }

    while(!temp.empty()) {
        st.push(temp.top());
        temp.pop();
    }
}

// Approach 2 :
void removeMiddleHelper(stack<int> &st, int count, int size) {
    if(count == size / 2) {
        st.pop();
        return;
    }

    int value = st.top();
    st.pop();
    removeMiddleHelper(st, count + 1, size);
    st.push(value);
}

void removeMiddle(stack<int> &st) {
    if(st.empty()) {
        cout<<"Empty Stack!";
        return;
    }
    int n = st.size();
    int count = 0;
    removeMiddleHelper(st, count, n);
}

// ------------------------------------------------------- Problem 7 : Delete the middle node using Stack ------------------------------------------------------------------------>
// Pattern Recognition : "Stack Basics"
// Difficulty : "Easy"
// Problem Statement : Delete the middle element of a stack while preserving the order of remaining elements.
// Understand the Problem : A stack follows LIFO and does not support random access.
//                        : To delete the middle element, we must either : Traverse using another data structure (iterative) & Or simulate traversal using recursion (implicit stack)
// Approach 1 (Iterative Approach) : Use an auxiliary stack to temporarily hold elements.
//                                 : Steps : Find size n of stack and compute middle index (n/2) -> Pop elements one by one from original stack -> Skip the middle element while transferring others to temp stack -> Push elements back from temp to original stack.
//                                 : This preserves order except the removed middle element.
//                                 : TC = O(n) && SC = O(n)
// Approach 2 (Recursive Force) : Use recursion to simulate stack traversal without extra data structure.
//                              : Steps : Recursively pop elements until reaching the middle (count == size/2) -> Remove the middle element at base case -> During backtracking, push the stored elements back -> This restores original order except the middle element.
//                              : TC = O(n) && SC = O(n) (due to recursion call stack)

// Approach 1 :
void pushAtBottom(stack<int> &st, int data) {
    if(st.empty()) {
        st.push(data);
        return;
    }

    stack<int> temp;
    while(!st.empty()) {
        temp.push(st.top());
        st.pop();
    }
    
    st.push(data);

    while(!temp.empty()) {
        st.push(temp.top());
        temp.pop();
    }
}

// Approach 2 :
void pushAtBottom(stack<int> &st, int data) {
    if(st.empty()) {
        st.push(data);
        return;
    }
    
    int value = st.top();
    st.pop();
    pushAtBottom(st, data);
    st.push(value);
}

// ------------------------------------------------------- Problem 8 : Reverse a Stack ------------------------------------------------------------------------>
// Pattern Recognition : "Stack Basics"
// Difficulty : "Easy"
// Problem Statement : Reverse the elements of a stack such that the top becomes the bottom and vice versa, without using any extra data structure. 
// Understand the Problem : A stack follows LIFO and does not allow random access. To reverse it, we must either use another stack (extra space) or use recursion to simulate the stack behavior.
//                        : The order of elements must be completely reversed.
// Approach 1 (Iterative Approach) : Use an auxiliary stack. 
//                                 : Steps : Pop all elements from original stack and push them into a new stack & The new stack will contain elements in reversed order.
//                                 : TC = O(n) && SC = O(n)
// Approach 2 (Recursive Force) : Use recursion + helper function (pushAtBottom).
//                              : Steps : Pop the top element -> Recursively reverse the remaining stack -> Insert the popped element at the bottom using pushAtBottom -> Repeat until stack is fully reversed.
//                              : TC = O(n^2) && SC = O(n) (due to recursion stack)

// Approach 1 :
stack<int> reverseStack(stack<int> st) {
    if(st.empty()) {
        cout<<"Empty Stack!";
        return st;
    }

    stack<int> temp;
    while(!st.empty()) {
        temp.push(st.top());
        st.pop();
    }
    return temp;
}

// Approach 2 :
void pushAtBottom(stack<int> &st, int data) {
    if(st.empty()) {
        st.push(data);
        return;
    }

    int value = st.top();
    st.pop();
    pushAtBottom(st, data);
    st.push(value);
}

void reverseStack(stack<int> &st) {
    if(st.empty()) {
        return;
    }

    int value = st.top();
    st.pop();
    reverseStack(st);
    pushAtBottom(st, value);
}

// ------------------------------------------------------- Problem 9 : Sort a Stack ------------------------------------------------------------------------>
// Pattern Recognition : "Stack Basics"
// Difficulty : "Medium"
// Problem Statement : Sort a stack such that the elements are arranged in a specific order (e.g., largest at top).
// Understand the Problem : A stack does not allow random access, so we cannot directly sort it like an array. We must either use an auxiliary data structure or manipulate it using recursion.
//                        : The goal is to reorder elements while maintaining stack properties (LIFO).
// Approach 1 (Brute Force) : Use an auxiliary data structure (like vector/array).
//                          : Steps : Pop all elements from stack into a vector, sort the vector using built-in sort & push elements back into the stack.
//                          : Note : Uses extra space and does not utilize stack properties effectively.
//                          : TC = O(n + nlogn) ≈ O(nlogn) && SC = O(n + logn) ≈ O(n)
// Approach 2 (Recursive Force) : Use recursion to sort the stack without using any extra data structure.
//                              : Steps : Pop the top element, recursively sort the remaining stack, insert the popped element into the sorted stack at its correct position using a helper function (sortedInsert).
//                                      : Repeat until entire stack is sorted.
//                              : TC = O(n^2) && SC = O(n) (due to recursion call stack)

// Approach 2 :
void sortedInsert(stack<int> &st, int value) {
    if(st.empty() || !st.empty() && st.top() < value) {
        st.push(value);
        return;
    }

    int val = st.top();
    st.pop();
    sortedInsert(st, value);
    st.push(val);
}

void sortStack(stack<int> &st) {
    if(st.empty()) {
        return;
    }

    int value = st.top();
    st.pop();

    sortStack(st);
    sortedInsert(st, value);
}

// Important Insights : Why is recursive solution considered optimal even when brute force has better time complexity here?
// Understanding the Confusion : Brute force approach uses an external data structure (like vector) and sorting algorithm.
//                             : It gives better time complexity: TC = O(n log n), SC = O(n).
//                             : Recursive approach avoids extra data structure but has worse time complexity: TC = O(n^2), SC = O(n) 
// Important Realization : Optimal solution is NOT always the one with best time complexity & Optimal solution depends on the constraints of the problem.
//                       : Case 1 : No Constraints (Real-world / Industry) - We prefer better performance and simpler code.
//                                                                         - Brute force (vector + sort) is optimal.
//                                                                         - Reason : Faster, cleaner, maintainable, and practical.
//                       : Case 2 : Constraint → "No extra data structure allowed" - We cannot use vector/array & must use only stack operations
//                                                                                 - Then the recursive solution becomes optimal under this constraint.
//                                                                                 - Reason : It uses implicit call stack instead of explicit extra space.

// ------------------------------------------------------- Problem 10 : Valid Parentheses ------------------------------------------------------------------------>
// Problem 10 : Valid Parentheses!







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
