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