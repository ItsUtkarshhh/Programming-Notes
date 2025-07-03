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