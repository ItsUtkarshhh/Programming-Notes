// ------------------------------------------------------- Stack Questions ------------------------------------------------------------------------>
// ------------------------------------------------------- Problem 1 : Implement a stack using arrays ------------------------------------------------------------------------>
// Pattern Recognition : "Array based Implementation"
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
// Pattern Recognition : "Linked List based Implementation"
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
// Pattern Recognition : "Array based Implementation"
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
// Pattern Recognition : "Linked List based Implementation"
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
// Pattern Recognition : "Recursive Stack"
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

// ------------------------------------------------------- Problem 7 : Push at bottom of the stack ------------------------------------------------------------------------>
// Pattern Recognition : "Recursive Stack"
// Difficulty : "Easy"
// Problem Statement : Delete the middle element of a stack while preserving the order of remaining elements. Understand the Problem : A stack follows LIFO and does not allow direct access to the bottom element.
//                   : To insert at the bottom, we must either : Use an auxiliary data structure (iterative approach) & Or use recursion to reach the bottom (implicit stack)
// Approach 1 (Iterative Approach) : Use an auxiliary stack to temporarily reverse the stack.
//                                 : Steps : Pop all elements from original stack and push them into a temp stack, push the new element into the now-empty original stack (this becomes the bottom).
//                                         : Push back all elements from temp stack to original stack, this restores original order with the new element at the bottom.
//                                 : TC = O(n) && SC = O(n)
// Approach 2 (Recursive Force) : Use recursion to reach the bottom of the stack without extra data structure.
//                              : Steps : Pop the top element and store it, recursively call the function until the stack becomes empty, when stack is empty, insert the new element (this is the bottom).
//                                      : During backtracking, push all stored elements back in order. This restores original order with the new element at the bottom.
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
// Pattern Recognition : ""Recursive Stack"
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
// Pattern Recognition : "Recursive Stack"
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
// Pattern Recognition : "Parenthesis Pattern"
// Difficulty : Easy
// Problem Statement : We are given a string containing only opening and closing brackets : () (Round Brackets), {} (Curly Braces) and [] (Square Brackets).
//                   : Our task is to check whether the given string has valid parentheses or not. A set of parentheses is considered valid if : Every opening bracket has a corresponding closing bracket and the brackets are closed in the correct order.
//                   : Examples of Valid Parentheses : "()" → Valid, as opening ( is closed by ). "{}[]" → Valid, as {} and [] are correctly closed. "{[()]}" → Valid, as {} contains [], which contains (), and all are closed in the correct order.
//                   : Examples of Invalid Parentheses : "({)" → Invalid, because { is not closed before ). "{[}" → Invalid, because { is opened but not properly closed. "(" → Invalid, because an opening bracket is not closed.
// Understand the problem : This is NOT just counting brackets. Order matters → e.g., "({)}" is invalid even though counts match.
//                        : We need to ensure : Correct type matching, Correct order (inner closes before outer)
//                        : Key observation : The most recently opened bracket must be closed first → LIFO behavior → Stack.
// Appoach 1 (Brute Force) : Idea - Repeatedly remove valid pairs "()", "{}", "[]" from the string.
//                         : Continue until no more changes can be made, if the string becomes empty → valid. Else → invalid.
//                         : Steps : Loop while changes are happening : Find "()", remove it. Find "{}", remove it. Find "[]", remove it.
//                                 : Repeat - Check if string is empty.
//                         : Drawbacks : Inefficient for large inputs & Not scalable
//                         : TC = O(n^2) && SC = O(1)
// Approach 2 (Optimal) : Idea : Use a stack to track opening brackets. For every closing bracket, check if it matches the last opening bracket.
//                      : Steps : Traverse the string. If opening bracket → push to stack. If closing bracket : If stack is empty → invalid.
//                                                                                                            : Else check top : If matching → pop or else → invalid
//                              : At the end : If stack is empty → valid & else → invalid
//                      : Advantages : Efficient, Clean logic & Industry-standard approach
//                      : TC = O(n) && SC = O(n)

// Approach 1 :
bool isValidParantheses(string str) {
    if(str.empty()) return true; // or false as per the logic needs.

    bool changed = true;
    while(changed) {
        changed = false;

        if(str.find("()") != string::npos) {
            str.erase(str.find("()"), 2);
            changed = true;
        }
        else if(str.find("{}") != string::npos) {
            str.erase(str.find("{}"), 2);
            changed = true;
        }
        else if(str.find("[]") != string::npos) {
            str.erase(str.find("[]"), 2);
            changed = true;
        }
    }
    return str.empty();
}

// Approach 2 :
bool isValidParantheses(string str) {
    if(str.empty()) return true; // or false as per the logic needs.

    stack<char> temp;
    for(int i = 0; i < str.length(); i++) {
        if(str[i] == '{' || str[i] == '[' || str[i] == '(') {
            temp.push(str[i]);
        }
        else {
            if(temp.empty()) return false;
            if((str[i] == '}' && temp.top() == '{') || (str[i] == ']' && temp.top() == '[') || (str[i] == ')' && temp.top() == '(')) { // Safe to use extra parenthesis for extra logic safety, you can remove too, but just better code readability and logic safety.
                temp.pop();
            }
            else {
                return false;
            }
        }
    }
    
    return temp.empty();
}

// ------------------------------------------------------- Problem 11 : Detect redudant brackets ------------------------------------------------------------------------>
// Pattern Recognition : "Expression Evaluation"
// Difficulty : Medium
// Problem Statement : Given a valid expression string containing brackets and operators (+, -, *, /), determine if the expression contains any redundant brackets.
//                   : Redundant brackets are those which do not affect the expression. Example : ((a+b)) → redundant, (a) → redundant, (a+b) → NOT redundant & (a+(b)/c) → redundant around b
// Understand the problem : Not about validity → expression is already valid. We need to detect "useless" brackets.
//                        : A bracket is redundant if : There is NO operator inside it.
//                        : Key idea : If inside a pair of brackets there is only a single variable or nothing meaningful → redundant.
// Appoach 1 (Brute Force) : Idea : For every pair of brackets : Extract substring inside it, check if it contains any operator (+, -, *, /), if not → redundant.
//                         : Steps : Iterate over string
//                                 : For each '(' : Find its matching ')' & Check substring between them
//                                                : If no operator found → return true (redundant exists)
//                         : Drawbacks : Repeated scans & inefficient for nested expressions
//                         : TC = O(n^2) && SC = O(1)
// Approach 2 (Optimal) : Idea : Use stack to track characters. When we encounter ')', we check what’s inside the corresponding '('.
//                      : Steps : Traverse string, Push everything except ')'
//                              : When ')' is found : Pop elements until '(' is found.
//                                                  : Track if any operator was present, if NO operator found → redundant → return true
//                                                  : Pop '(' & if traversal completes → no redundancy
//                      : Advantages : Efficient & Handles nested expressions naturally
//                      : TC = O(n) && SC = O(n)

// Approach 1 :
string hasRedudantBrackets(string str) {
    if(str.empty()) return true;

    for(int i = 0; i < str.length(); i++) {
        if(str[i] == '(') {
            int count = 0;
            int j = i;
            while(j < str.length()) {
                if(str[j] == '(') count++;
                if(str[j] == ')') count--;
                if(count == 0) break;
                j++;
            }

            bool hasOperator = false;
            for(int k = i + 1; k < j; k++) {
                if(str[k] == '*' || str[k] == '+' ||
                str[k] == '/' || str[k] == '-') {
                    hasOperator = true;
                    break;
                }
            }

            if(!hasOperator) return true;

            if(i > 0 && j < str.length() - 1) {
                if(str[i - 1] == '(' && str[j + 1] == ')') return true;
            }
        }
    }

    return false;
}

// Approach 2 :
string hasRedudantBrackets(string str) {
    if(str.empty()) return true;

    stack<char> store;

    for(int i = 0; i < str.length(); i++) {
        if(str[i] != ')') {
            store.push(str[i]);
        }
        else {
            bool hasOperator = false;
            while(!store.empty() && store.top() != '(') {
                char top = store.top();
                store.pop();

                if(top == '*' || top == '/' || top == '+' || top == '-') {
                    hasOperator = true;
                }
            }
            if(!store.empty()) store.pop();
            if(!hasOperator) return true;
        }
    }

    return false;
}

// ------------------------------------------------------- Problem 12 : Remove redudant brackets ------------------------------------------------------------------------>
// Pattern Recognition : "Expression Evaluation"
// Difficulty : Hard
// Problem Statement : Given a valid mathematical expression as a string, remove all redundant brackets, without changing the value or meaning of the expression.
//                   : A bracket pair is redundant if removing it does not change the expression's result.
//                   : Expression contains operators: +, -, *, /
//                   : Example : "((a+b))" → "(a+b)" & "(a+(b)/c)" → "(a+b/c)"  [inner (b) is redundant]
// Understand the problem : Input : A valid balanced expression string (no spaces)
//                        : Output : Same expression with redundant brackets removed
//                        : Redundant Case 1 : Single variable inside brackets → (b) remove to b
//                        : Redundant Case 2 : Already wrapped expression → ((a+b)) remove outer
//                        : NOT Redundant : Brackets that group an operation → (a+b) keep as it is
//                        : NOT Redundant : Brackets that change precedence → (a+b)*c keep as it is
//                        : Key Insight : A bracket pair is NEEDED only if it & contains an operator at its own level.
// Appoach 1 (Brute Force) : Traverse the string -> For every '(', find its matching ')' -> Extract the inner substring ( ... )
//                         : Decide : Remove OR Keep -> If removed → restart traversal -> Repeat until no changes possible.
//                         : TC = O(n^2) && SC = O(1)
//                         : Limitations : Associativity Issues - a-(b-c) ≠ a-b-c
//                                       : Division Cases - a/(b*c) ≠ a/b*c
//                                       : Complex Nesting - Cannot handle deep dependencies reliably
// Approach 2 (Optimal) : The core idea : Brackets are NOT always redundant just because they contain an operator. The question is whether they actually change the result given operator precedence rules.
//                      : The three pass strategy : For each character, record which bracket pair it belongs to using v[] array (nesting level / bracket ID)
//                                                : For each high-priority operator (* - /), scan adjacent brackets and decide which ones are necessary → store in st2
//                                                : Build output — include a bracket only if it's in st2 (i.e. it was marked as necessary)
//                      : The data structures used : Bracket Ownership Vector/Array - Size = length of string. v[i] stores the index of the opening bracket that currently owns character i. So every character inside a pair of brackets shares the same value — the index where that ( appeared.
//                                                                                  - This lets us ask : "what bracket group does this character belong to?"
//                                                 : A Stack - Stack of bracket indices (helper) & used only during Pass 1 to track the current open bracket. st.top() always gives the index of the nearest unclosed (.
//                                                 : Some unordered sets - st1 : Set of bracket IDs that contain + or -. When we see a + or - inside any open bracket, we store that bracket's opening index into st1. This tells us later: "this bracket group has a low-precedence operator inside it."
//                                                                       - st2 : Set of bracket indices that are NECESSARY — the final answer. This is the core output of Pass 2. A bracket index ends up in st2 only if we determine it actually changes the expression's value. In Pass 3 we only include brackets whose v[i] is in st2.
//                                                                       - st3 : Set of bracket IDs that contain * or /. Same idea as st1 but for high-precedence operators. Used specifically to handle the a/(b*c) case — if a bracket group has * or / and appears after a /, it must be kept.
//                      : Pass 1 : Build the bracket ownership map v[]
//                               : Goal : Tag every character with the index of the opening bracket it belongs to.
//                               : Scan left to right. For each character : If ( → push its index onto stack. Set v[i] = i (it owns itself).
//                                                                        : If ) → set v[i] = st.top() (matches its opening bracket). Then pop the stack.
//                                                                        : If + or - and stack is non-empty → set v[i] = st.top(). Insert st.top() into st1 (this bracket group contains a low-precedence operator).
//                                                                        : If * or / and stack is non-empty → set v[i] = st.top(). Insert st.top() into st3 (this bracket group contains a high-precedence operator).
//                                                                        : If any other character (operand) and stack non-empty → set v[i] = st.top().
//                               : What you have after Pass 1 : v[] is a full map — every character knows which bracket owns it. st1 knows which bracket groups contain +/-. st3 knows which contain *//.
//                      : Pass 2 : Decide which brackets are necessary → populate st2
//                               : Goal : For each strong operator sitting outside all brackets, check its neighboring bracket groups. If removing those brackets would change the math, mark them in st2 as necessary.
//                               : Scan left to right. Skip any character that is not *, /, or - (because + can never make brackets necessary).
//                               : For each - or * found : Scan rightward — walk through consecutive ( characters after the operator. For each such (, check if v[j] is in st1. If yes → insert v[j] into st2 (a bracket containing +/- after - or * must be kept).
//                                                       : Scan leftward — walk through consecutive ) characters before the operator. For each such ), check if v[j] is in st1. If yes → insert v[j] into st2.
//                               : For each / found (additionally, on top of the above) : Scan rightward through consecutive ( characters. For each, also check if v[j] is in st3. If yes → insert v[j] into st2 (a bracket containing *// after / must be kept because a/(b*c) ≠ a/b*c).
//                               : Reasoning behind each case : a-(b+c) → without brackets becomes a-b+c. Sign flips. Must keep.
//                                                            : a*(b+c) → without brackets becomes a*b+c. Precedence breaks. Must keep.
//                                                            : (a+b)*c → without brackets becomes a+b*c. Must keep.
//                                                            : a/(b*c) → without brackets becomes a/b*c. Left-associativity changes the result. Must keep.
//                                                            : a+(b+c) → + is skipped entirely. Brackets never enter st2. Safe to remove.
//                      : Pass 3 : Build the output string
//                               : Goal : Reconstruct the expression, including only the brackets that were marked necessary.
//                               : Scan left to right. For each character : If it is not a bracket → always append to ans.
//                                                                        : If it is ( or ) → check if v[i] exists in st2. If yes → append it. If no → silently skip it.
//                               : Why this works cleanly : Both ( and ) of any pair share the same v[i] value (the opening index). So a single set lookup in st2 decides both halves of the pair together — you never have a dangling bracket because they're always dropped or kept as a unit.
//                      : TC = O(n) && SC = O(n)

// Approach 1 :
#include <bits/stdc++.h>
using namespace std;

bool hasOperator(string s) {
    for(char c : s) {
        if(c == '+' || c == '-' || c == '*' || c == '/')
            return true;
    }
    return false;
}

int precedence(char c) {
    if(c == '+' || c == '-') return 1;
    if(c == '*' || c == '/') return 2;
    return 0;
}

string removeRedundant(string s) {
    int n = s.length();

    for(int i = 0; i < n; i++) {
        if(s[i] == '(') {
            int count = 1;
            int j = i + 1;

            while(j < n && count > 0) {
                if(s[j] == '(') count++;
                else if(s[j] == ')') count--;
                j++;
            }

            int end = j - 1;

            string inside = s.substr(i+1, end-i-1);

            if(!hasOperator(inside)) {
                s.erase(end, 1);
                s.erase(i, 1);
                i = -1;
                n = s.length();
                continue;
            }

            char leftOp = (i-1 >= 0) ? s[i-1] : '#';
            char rightOp = (end+1 < n) ? s[end+1] : '#';

            bool safe = true;

            for(char c : inside) {
                if((c == '+' || c == '-') &&
                   (leftOp == '*' || leftOp == '/' ||
                    rightOp == '*' || rightOp == '/' || leftOp == '-' || rightOp == '-')) {
                    safe = false;
                    break;
                }
            }

            if(safe) {
                s.erase(end, 1);
                s.erase(i, 1);
                i = -1;
                n = s.length();
            }
        }
    }

    return s;
}

// Approach 2 (Optimal) :
string removeBrackets(string s){    
    //code here
    string ans = "";
    int f=0;
    vector<int> v(s.size());
    stack<int> st;
    unordered_set<int> st1,st2,st3;
    for(int i=0;i<s.size();i++){
        if(s[i]=='('){
            st.push(i);
            v[i] = st.top();
        }
        else if(s[i]==')'){
            v[i] = st.top();
            st.pop();
        }
        else if((s[i]=='+' || s[i]=='-') && st.size()>0){
            
            v[i] = st.top();
            st1.insert(st.top());   
        }
        else if((s[i]=='*' || s[i]=='/') && st.size()>0){
            
            v[i] = st.top();
            st3.insert(st.top());   
        }
        else if(st.size()>0){
            v[i] = st.top();
        }
        
    }
    for(int i=0;i<s.size();i++){
        if(s[i]!='*' && s[i]!='/' && s[i]!='-') continue;
        int j=i+1;
        if(s[i]=='-'){
            while(j<s.size()  && s[j]=='('){
                if(st1.find(v[j])!=st1.end())
                st2.insert(j);
                j++;
            }
            continue;
        }
        j = i+1;
        while(j<s.size() && s[j]=='('){
            if(st1.find(v[j])!=st1.end())
                st2.insert(j);
                j++;
        }
        if(s[i]=='/'){
            j = i+1;
            while(j<s.size() && s[j]=='('){
                if(st3.find(v[j])!=st3.end())
                    st2.insert(j);
                    j++;
            }
        }
        
        j = i-1;
        while(j>=0  && s[j]==')'){
            if(st1.find(v[j])!=st1.end())
                st2.insert(j);
                j--;
        }
    }
    for(int i=0;i<s.size();i++){
        if(s[i]!=')' && s[i]!='('){
            ans+=s[i];
        }
        else{
            if(st2.find(v[i])!=st2.end()){
                ans+=s[i];
            }
        }
    }
    
    return ans;
}

// ------------------------------------------------------- Problem 13 : Minimum Cost to Make a String Valid (Bracket Reversal Problem) ------------------------------------------------------------------------>
// Pattern Recognition : "Parenthesis Pattern"
// Difficulty : Medium
// Problem Statement : We are given a string consisting of only curly brackets { and }. The string is called valid if : Every opening bracket { has a corresponding closing bracket } after it.
//                   : Examples of Valid Strings : "{}{}", "{ { } }" and "{ { }{ } }".
//                   : Examples of Invalid Strings : "}{" (Closing bracket appears before opening), "{ }{ }{ }}" (Extra closing bracket at the end), "{{ }{ }}{" (Extra opening bracket { at the end).
//                   : Goal : We need to convert the given invalid string into a valid one with the minimum cost.
//                          : Allowed operation : We can reverse any bracket { ↔ } at a cost of 1 unit per reversal and find the minimum cost needed to make the string valid.
// Understand the problem : You are given a string of only {, } brackets
//                        : A string is valid if : Every { has a matching } also when the order is correct, not like - }{
//                        : Invalid Examples : }{ → wrong order, {{} → one extra { & {}} → one extra }
//                        : Allowed operation is flip the bracket, but every flip cost = 1. And our goal is to make the string valid with minimum cost
//                        : First important observation : If the brackets are odd, its impossible to make the string valid.
//                        : Instead of trying all possibilities, think like this : “Remove already valid pairs first… then deal with the leftovers.”
//                        : How to calculate the cost : Method 1 : m - length of the remaining string, hence, Minimum Reversal : cost = m/2 ​+ (number of opening brackets in first half mod 2)
//                                                    : Method 2 : Count number of open & close brackets, then cost = (open/2) + (close/2) 
// Appoach 1 (Brute Force) : Try all ways of flipping brackets and check validity.
//                         : Steps : Generate all possible combinations (flip or not flip each bracket)
//                                 : For each : Check if valid & track minimum cost
//                         : TC : O(2^n) - TLE Guaranteed && SC = O(n)
//                         : Why it's bad : Completely impractical for n > 20 & just for understanding, not implementation.
// Approach 2 (Optimal) : Core idea : Remove valid pairs → Solve only invalid leftovers
//                      : Steps : Check for odd or even length of string, if odd then impossible
//                              : Use Stack to Remove Valid Pairs - If character is "{" push it, if "}" then check the top if stack is not empty and if top is "{" pop it, else push that character.
//                              : Count remaining brackets.
//                              : Calculate the cost = (open/2) + (close/2) 
//                      : TC = O(n) && SC = O(n)

// Approach 2 :
int minimumCostStringValid(string str) {
    if(str.length() % 2 != 0) return -1;

    stack<char> st;
    for(char ch : str) {
        if(ch == '{') {
            st.push(ch);
        }
        else {
            if(!st.empty() && st.top() == '{') {
                st.pop();
            }
            else {
                st.push(ch);
            }
        }
    }

    int open = 0;
    int close = 0;
    while(!st.empty()) {
        if(st.top() == '{') open++;
        else close++;
        st.pop();
    }

    return ((open+1)/2) + ((close+1)/2);
}

// ------------------------------------------------------- Problem 14 : Next smaller element & variations ------------------------------------------------------------------------>
// Pattern Recognition : "Monotonic Stack"
// Difficulty : Medium
// Problem Statement : For each element in the array, find the next smaller element to its right & If none exists → return -1.
// Understand the problem : Take an element → look to the right → stop at the first smaller number.
//                        : They do not mean : Smallest in the whole array, or any smaller. They are specific about "first smaller encountered"
// Appoach 1 (Brute Force) : For each element, scan right side and find first smaller.
//                         : TC = O(n^2) && SC = O(n)
// Approach 2 (Optimal) : Build & maintain a stack such that it is monotonically increasing.
//                      : Step : Traverse from right to left, maintain stack of “useful candidates”, pop all elements ≥ current, Top of stack = answer & finally push current element
//                      : TC = O(n) && SC = O(n)

// Approach 1 :
vector<int> nextSmallerElement(vector<int> arr) {
    if(arr.size() == 0) return {};

    vector<int> ans(arr.size(), -1);

    for(int i = 0; i < arr.size(); i++) {
        for(int j = i + 1; j < arr.size(); j++) {
            if(arr[j] < arr[i]) {
                ans[i] = arr[j];
                break;
            }
        }
    }
    return ans;
}

// Approach 2 :
vector<int> nextSmallerElement(vector<int> arr) {
    if(arr.size() == 0) return {};

    int n = arr.size();
    vector<int> ans(n, -1);
    stack<int> temp;

    for(int i = n-1; i >= 0; i--) {
        while(!temp.empty() && temp.top() >= arr[i]) {
            temp.pop();
        }

        if(!temp.empty()) {
            ans[i] = temp.top();
        }

        temp.push(arr[i]);
    }
}

// Variation 2 : Next Greater Element, Previous Smaller Element & Previous Greater Element
// Note : Core Problem statement is same, core problem understanding is same & and core approach is same, just need to adjust as per the situation.
vector<int> nextGreaterElement(vector<int> arr) {
    if(arr.size() == 0) return {};

    int n = arr.size();
    vector<int> ans(n, -1);
    stack<int> temp;

    for(int i = n-1; i >= 0; i--) {
        while(!temp.empty() && temp.top() <= arr[i]) {
            temp.pop();
        }

        if(!temp.empty()) {
            ans[i] = temp.top();
        }

        temp.push(arr[i]);
    }

    return ans;
    
}

vector<int> previousGreaterElement(vector<int> arr) {
    if(arr.size() == 0) return {};
    
    int n = arr.size();
    vector<int> ans(n, -1);
    stack<int> temp;

    for(int i = 0; i < n; i++) {
        while(!temp.empty() && temp.top() <= arr[i]) {
            temp.pop();
        }

        if(!temp.empty()) {
            ans[i] = temp.top();
        }

        temp.push(arr[i]);
    }
    
    return ans;
}

vector<int> previousSmallerElement(vector<int> arr) {
    if(arr.size() == 0) return {};
    
    int n = arr.size();
    vector<int> ans(n, -1);
    stack<int> temp;

    for(int i = 0; i < n; i++) {
        while(!temp.empty() && temp.top() >= arr[i]) {
            temp.pop();
        }

        if(!temp.empty()) {
            ans[i] = temp.top();
        }

        temp.push(arr[i]);
    }
    
    return ans;
}

// ------------------------------------------------------- Problem 15 : Largest Rectangular Area in Histogram ------------------------------------------------------------------------>
// Pattern Recognition : "Monotonic Stack"
// Difficulty : Hard
// Problem Statement : You’re given heights of bars example : [2, 1, 5, 6, 2, 3]. Each bar has width = 1 & height = given value.
//                   : We need to find the maximum rectangular area that can be formed.
// Understand the problem : For each bar, think : “If this bar is the smallest height in a rectangle, how far can I expand left and right?”
//                        : Expand a bar until you hit a smaller element, not a greater one.
// Appoach 1 (Brute Force) : For each index : Expand left until smaller element, Expand right until smaller element & Compute area.
//                         : TC = O(n^2) && SC = O(1);
// Approach 2 (Optimal) : Instead of expanding for every element : lets just pre-store there previous and next smaller element's indexes (not value this time).
//                      : Core Idea : “How far can I extend left and right such that : I remain the smallest bar?”
//                      : Use the indexes found through previous and next smaller element method, as left and right to find the width of the current rectangle.
//                      : TC = O(n) && SC = O(n)

// Approach 1 :
int maxAreaOfHistogram(vector<int> arr) {
    if(arr.empty()) return -1;

    int maxArea = INT_MIN;
    for(int i = 0; i < arr.size(); i++) {
        int left = i; int right = i;

        while(left >= 0 && arr[left] >= arr[i]) {
            left--;
        }

        while(right < arr.size() && arr[right] >= arr[i]) {
            right++;
        }

        int width = right - left - 1;
        int area = width * arr[i];

        maxArea = max(maxArea, area);
    }
    return maxArea;
}

// Approach 2 :
vector<int> nextSmallerElement(vector<int> v) {
    if(v.empty()) return {};

    int n = v.size();
    vector<int> ans(n, n);
    stack<int> temp;

    for(int i = n-1; i >= 0; i--) {
        while(!temp.empty() && v[temp.top()] >= v[i]) {
            temp.pop();
        }

        if(!temp.empty()) ans[i] = temp.top();
        temp.push(i);
    }
    return ans;
}

vector<int> previousSmallerElement(vector<int> v) {
    if(v.empty()) return {};

    int n = v.size();
    vector<int> ans(n, -1);
    stack<int> temp;

    for(int i = 0; i < n; i++) {
        while(!temp.empty() && v[temp.top()] >= v[i]) {
            temp.pop();
        }

        if(!temp.empty()) ans[i] = temp.top();
        temp.push(i);
    }
    return ans;
}

int maxAreaOfHistogram(vector<int> arr) {
    if(arr.empty()) return -1;

    vector<int> pse = previousSmallerElement(arr);
    vector<int> nse = nseSmallerElement(arr);
    int maxArea = INT_MIN;

    for(int i = 0; i < arr.size(); i++) {
        int width = nse[i] - pse[i] - 1;
        int height = arr[i];

        int area = width * height;
        maxArea = max(maxArea, area);
    }
    return maxArea;
}

// ------------------------------------------------------- Problem 16 : Celebrity Problem ------------------------------------------------------------------------>


// ------------------------------------------------------- Problem 17 : Maximum area of the formed by all the 1's in a binary matrix ------------------------------------------------------------------------>
// ------------------------------------------------------- Problem 18 : N Stacks in an array ------------------------------------------------------------------------>
// ------------------------------------------------------- Problem 19 : Design Special Stack Problem ------------------------------------------------------------------------>