#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int maxSumSubarray(vector<int> v) {
    int currentSum = 0;
    int maxSum = INT_MIN;
    int start = -1, tempStart = 0, end = -1;
    for(int i = 0; i < v.size(); i++) {
        currentSum += v[i];
        if(currentSum > maxSum) {
            maxSum = currentSum;
            start = tempStart;
            end = i;
        }
        if(currentSum < 0) {
            currentSum = 0;
            tempStart = i + 1;
        }
    }
    cout<<"Subarray : "<<"[";
    for(int i = start; i <= end; i++) {
        if(i < end) cout<<v[i]<<", ";
        else cout<<v[i];
    }
    cout<<"]";
    return maxSum;
}

int main() {
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i = 0; i < n; i++) {
        cin>>v[i];
    }
    int ans = maxSumSubarray(v);
    cout<<endl;
    cout<<"Max sum : "<<ans;
}