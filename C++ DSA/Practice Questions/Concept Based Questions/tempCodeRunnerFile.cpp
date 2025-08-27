#include<iostream>
#include<vector>
#include<deque>
using namespace std;

vector<int> maxofSubarrayK(vector<int> v, int k) {
    deque<int> dq;
    vector<int> result;
    int i = 0;
    for(int i = 0; i < v.size(); i++) {
        if(!dq.empty() && dq.front() <= i - k) {
            dq.pop_front();
        }
        while(!dq.empty() && v[i] > v[dq.back()]) {
            dq.pop_back();
        }
        dq.push_back(i);
        if(i >= k - 1) {
            result.push_back(v[dq.front()]);
        }
    }
    return result;
}

vector<int> minofSubarrayK(vector<int> v, int k) {
    deque<int> dq;
    vector<int> result;
    int i = 0;
    for(int i = 0; i < v.size(); i++) {
        if(!dq.empty() && dq.front() <= i - k) {
            dq.pop_front();
        }
        while(!dq.empty() && v[i] < v[dq.back()]) {
            dq.pop_back();
        }
        dq.push_back(i);
        if(i >= k - 1) {
            result.push_back(v[dq.front()]);
        }
    }
    return result;
}

int main() {
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i = 0; i < n; i++) {
        cin>>v[i];
    }
    int k;
    cin>>k;
    vector<int> ans1 = maxofSubarrayK(v, k);
    vector<int> ans2 = minofSubarrayK(v, k);
    vector<pair<int,int>> maxminPair(ans1.size());
    for(int i = 0; i < maxminPair.size(); i++) {
        maxminPair[i].first = ans2[i];
        maxminPair[i].second = ans1[i];
    }
    for(auto it : maxminPair) {
        cout<<"["<<it.first<<", "<<it.second<<"]"<<" ";
    }
}