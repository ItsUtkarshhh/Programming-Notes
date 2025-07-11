#include<iostream>
#include<climits>
using namespace std;

int maxSumSubarray(int* arr, int n) {
    int maxSum = INT_MIN;
    int start = 0;
    int end = 0;
    for(int i = 0; i < n; i++) {
        int sum = 0;
        for(int j = i; j < n; j++) {
            sum += arr[j];
            if(sum > maxSum) {
                maxSum= sum;
                start = i;
                end = j;
            }
        }
    }
    for(int i = start; i <= end; i++) {
        cout<<arr[i]<<" ";
    }
    return maxSum;
}

int main() {
    int n;
    cin>>n;
    int* arr = new int[n]; // Modern and correct in C++
    // vector<int> arr(n); // Best for simplicity
    for(int i = 0; i < n; i++) {
        cin>>arr[i];
    }
    int ans = maxSumSubarray(arr, n);
    cout<<ans;
    delete[] arr;
}