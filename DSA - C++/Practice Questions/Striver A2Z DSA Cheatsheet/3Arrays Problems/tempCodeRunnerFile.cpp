#include<iostream>
#include<vector>
using namespace std;

int longestSubarrayA1(vector<int> v, int k) {
    int n = v.size();
    vector<int> pref(n + 1);
    pref[0] = 0;
    for(int i = 1; i < n + 1; i++) {
        pref[i] = pref[i - 1] + v[i - 1];
    }
    
    int s = 0; int e = 0;
    int diff = 0;
    int maxLen = 0;
    while(e < pref.size()) {
        diff = pref[e] - pref[s];
        if(diff == k) {
            maxLen = max(maxLen, e - s);
            e++;
        }
        else if(diff > k) {
            s++;
        }
        else {
            e++;
        }
    }
    return maxLen;
}

int main() {
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) {
        cin>>arr[i];
    }
    int sum;
    cin>>sum;
    cout<<longestSubarrayA1(arr, sum);
}