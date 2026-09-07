// ------------------------------------------------------------- Sliding Window & Two Pointers ---------------------------------------------------------------------------------------------------------------->
// ----------------------------------------------------------------------- Problem 1 ---------------------------------------------------------------------------------------------------------------->
// Problem : Find the maximum sum in an array with the window of size K - Constant Window Size
// Approach : For constant window problems, generally compute the value for the first window and then move forward with the expansion and shrnking of the window maintaining the size K.

#include<iostream>
#include<vector>
using namespace std;

int maxSumSubarray(vector<int> &v, int k) {
    if(v.empty()) return 0;
    if(k <= 0 || k > v.size()) return 0;
    
    int left = 0;
    int right = k-1;
    int sum = 0;
    int maxSum = INT_MIN;
    
    for(int i = left; i <= right; i++) {
        sum += v[i];
    }
    
    maxSum = max(maxSum, sum);
    
    right = k;
    while(right < v.size()) {
        sum -= v[left];
        left++;
        sum += v[right];
        right++;
        
        maxSum = max(maxSum, sum);
    }
    
    return maxSum;
}

int main() {
    int size;
    cin>>size;
    
    vector<int> v(size);
    for(int i = 0; i < size; i++) {
        cin>>v[i];
    }
    
    int k;
    cin>>k;
    
    cout<<maxSumSubarray(v, k);
}

// ----------------------------------------------------------------------- Problem 2 ---------------------------------------------------------------------------------------------------------------->
// Problem : Longest Subarray with the sum <= K
// Brute Force : Generate all the subarrays using nested loops and compute the longest subarrays among those.
// Better : Use two pointers, as the two ends of the window, and expand and shrink based on the conditions, and updates the maxLen.
// Optimal : We don't need to shrink continously below the maxLen, so we replaced the "while" with "if"

#include<iostream>
#include<vector>
using namespace std;

// Better
int LongestSubarrayWithSumK(vector<int> v, int k) {
    if(v.empty()) return 0;
    
    int left = 0;
    int right = left;
    int sum = 0;
    int maxLen = 0;
    
    while(right < v.size()) {
        sum += v[right];
        while(left <= right && sum > k) {
            sum -= v[left];
            left++;
        }
        if(sum <= k) {
            maxLen = max(maxLen, right - left + 1);
        }
        right++;
    }
    return maxLen;
}

// Optimal
int LongestSubarrayWithSumK2(vector<int> v, int k) {
    if(v.empty()) return 0;
    
    int left = 0;
    int right = left;
    int sum = 0;
    int maxLen = 0;
    
    while(right < v.size()) {
        sum += v[right];
        if(left <= right && sum > k) {
            sum -= v[left];
            left++;
        }
        if(sum <= k) {
            maxLen = max(maxLen, right - left + 1);
        }
        right++;
    }
    return maxLen;
}

int main() {
    int size;
    cin>>size;
    
    vector<int> v(size);
    for(int i = 0; i < size; i++) {
        cin>>v[i];
    }
    
    int k;
    cin>>k;
    
    cout<<LongestSubarrayWithSumK2(v, k);
}

// ----------------------------------------------------------------------- Problem 3 ---------------------------------------------------------------------------------------------------------------->
// Problem : Maximum Points you can obtain from N cards.
// Approach : Its a constant window problem, so first we will calculate the sum of the first window, and then will move forward, by subtracting one from the left side subarray and adding one from the right side subarray.

int maxPointsFromCards(vector<int> &v, int k) {
    if(v.empty()) return 0;
    
    int sum = 0;
    int maxSum = INT_MIN;
    
    for(int i = 0; i <= k-1; i++) {
        sum += v[i];
    }
    
    maxSum = max(maxSum, sum);
    int rightIndex = v.size() - 1;
    
    for(int i = k-1; i >= 0; i--) {
        sum = sum - v[i] + v[rightIndex];
        maxSum = max(maxSum, sum);
        rightIndex--;
    }
    return maxSum;
}

// ----------------------------------------------------------------------- Problem 4 ---------------------------------------------------------------------------------------------------------------->
// Problem : 