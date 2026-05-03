#include<iostream>
#include<stack>
using namespace std;

vector<int> nextSmallerElement(vector<int> arr) {
    if(arr.empty()) return {};

    stack<int> temp;
    vector<int> ans(arr.size(), -1);

    for(int i = arr.size() - 1; i >= 0; i--) {
        if(!temp.empty() && temp.top() < arr[i]) {
            ans[i] = temp.top();
        }
        else {
            while(!temp.empty() && temp.top() >= arr[i]) {
                temp.pop();
            }
            if(!temp.empty()) ans[i] = temp.top();
        }
        temp.push(arr[i]);
    }
    return ans;
}

int main() {
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);

    deleteMiddleElement(st, 0, st.size());
}