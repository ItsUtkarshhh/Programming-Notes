#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int maxSubarraySum(vector<int> v, int k) {
    int i = 0; int j = 0;
    int n = v.size();
    int maxSum = INT_MIN;
    while(i <= n - k) {
        int sum = 0;
        while(j < i + k) {
            sum += v[j];
            j++;
        }
        maxSum = max(maxSum, sum);
        i++;
        j = i;
    }
    return maxSum;
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
    cout<<maxSubarraySum(v, k);
}