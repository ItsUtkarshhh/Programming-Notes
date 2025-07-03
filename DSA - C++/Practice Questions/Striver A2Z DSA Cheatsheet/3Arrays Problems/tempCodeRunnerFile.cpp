#include<iostream>
#include<climits>
#include<vector>
using namespace std;

int largestSum(vector<int> v, int k) {
    int n = v.size();

    // Prepare Prefix sum array!
    vector<int> pref(n + 1);
    pref[0] = 0;
    for(int i = 0; i < n + 1; i++) {
        pref[i] = pref[i - 1] + v[i-1];
    }

    int s = 0;
    int e = 0;
    int maxLen = INT_MIN;
    int sum = INT_MIN;
    while(e < n) {
        sum = pref[e + 1] + pref[s];
        if(sum <= k) {
            maxLen = max(maxLen, e - s + 1);
            e++;
        }
        else {
            s++;
        }
    }
    return maxLen;
}

int main() {
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i = 0; i<n; i++) {
        cin>>v[i];
    }
    int sum;
    cin>>sum;
    cout<<largestSum(v, sum);
}