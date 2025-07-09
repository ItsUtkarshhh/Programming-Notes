#include<iostream>
#include<vector>
#include<climits>
using namespace std;

vector<int> maxOfMinPlusMaxInSubarrays(vector<int> v, int k) {
    if(k > v.size()) return {-1};
    int sum = INT_MIN;
    vector<int> result;
    for(int i = 0; i <= v.size() - k; i++) {
        int maxi = INT_MIN;
        int mini = INT_MAX;
        for(int j = i; j < i + k; j++) {
            maxi = max(maxi, v[j]);
            mini = min(mini, v[j]);
        }
        sum = max(sum, maxi + mini);
        result.push_back(sum);
    }
    return result;
}

int main() {
    int n;
    cin>>n;
    int k;
    cin>>k;
    vector<int> v(n);
    for(int i = 0; i < n; i++) {
        cin>>v[i];
    }
    vector<int> ans = maxOfMinPlusMaxInSubarrays(v, k);
    for(int val : ans) {
        cout<<val<<" ";
    }
}