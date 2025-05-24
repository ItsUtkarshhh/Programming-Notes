// Sliding Window Pattern!
// Sliding Window is a technique for iterating through contiguous parts of an array or string using two pointers (start and end), instead of creating new subarrays or substrings every time.
// There are particularly two types of Sliding windows : Fixed and Dynamic!
// Fixed Sliding Window : When the window size is predefined (say, size = k), and you slide the window one element at a time, while maintaining some calculation (like sum, max, etc.).
//                      : Behaviour : Expand the window till it reaches size k, After that, for each step : Add the new element at the right -> Remove the old element at the left -> Move both start and end by 1.
// Dynamic Sliding Window : When the window size is not fixed, and it needs to expand or shrink based on some given condition (e.g., sum ≤ K, distinct characters ≤ 2, etc.)
//                        : Behaviour : Start with both pointers at 0 -> Expand end till the condition is valid -> If condition breaks, shrink from the start pointer -> Keep updating the result based on current valid window size.
// Overall, these are the core standard variations of sliding window! there are some more variations to it! based on the problem, the core will be more or less same!

// Problem Statement 1 : Given an array of integers arr[]  and a number k. Return the maximum sum of a subarray of size k.
//                     : Constraints : 1 <= arr.size() <= 10^6 (Means we cannot use any method with TC : O(n^2) otherwise it will give TLE)
//                                   : 1 <= arr[i]<= 106 (Also means we cannot use any method with SC : O(n^2) otherwise it will give SLE)
//                                   : 1 <= k<= arr.size()
//                     : Hence, we will be solving this problem keeping in mind it should not exceed the Time and Space limit!
//                     : So overall, we can come up with 2 ways to solve it, one is the Brute force approach and another is sliding window approach!
// Approach 1 : Brute Force!
#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int maxSumSubArrayBF(vector<int> v, int k) {
    int maxVal = INT_MIN;
    for(int i = 0; i<=v.size() - k; i++) {
        int sum = 0;
        for(int j = i; j<i+k; j++) {
            sum += v[j];
        }
        maxVal = max(maxVal, sum);
    }
    return maxVal;
}

int main() {
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i = 0; i<n; i++) {
        cin>>v[i];
    }
    int windowSize;
    cin>>windowSize;
    cout<<maxSumSubArrayBF(v, windowSize);
} // TC : O(n^2) and SC : O(1). Hence, even tho it takes no space, the TC is large enuf to give TLE. So that is why this is not a good approach!

// Approach 2 : Sliding Window!
#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int maxSumSubArraySW(vector<int> v, int k) {
    int windowSum = 0;

    // First window
    for(int start = 0; start < k; start++) {
        windowSum += v[start];
    }

    // Sliding window towards the end
    int start = 0;
    int maxSum = INT_MIN;
    maxSum = max(maxSum, windowSum);
    for(int end = start + k; end < v.size(); end++) {
        windowSum = windowSum + v[end] - v[end - k];
        maxSum = max(maxSum, windowSum);
    }
    return maxSum;
}

int main() {
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i = 0; i<n; i++) {
        cin>>v[i];
    }
    int windowSize;
    cin>>windowSize;
    cout<<maxSumSubArraySW(v, windowSize);
} // TC : O(n) and SC : O(1). Hence, its giving the best TC as per our constraints using the Sliding Window problem! Hence, optimal solution!

// Problem Statement 2 : Given an integer array arr[] and a number k. Find the count of distinct elements in every window of size k in the array.
//                     : Constraints : 1 <= k <= arr.size() <= 10^5 (Means we cannot use any method with TC : O(n^2) otherwise it will give TLE)
//                                   : 1 <= arr[i] <= 10^5 (Also means we cannot use any method with SC : O(n^2) otherwise it will give SLE)
//                     : Hence, we will be solving this problem keeping in mind it should not exceed the Time and Space limit!
//                     : Again, we can see that we have an array and we are asked about sub-arrays and count distinct elements in each sub-arrays of a given size! Hence we can simply use Sliding window! First lets start with Brute Force Approach!
// Approach 1 : Brute Force 1
#include<iostream>
#include<vector>
using namespace std;

vector<int> countDistinctBF(vector<int> arr, int k) {
    vector<int> countDistinct;
    int n = arr.size();

    for (int i = 0; i <= n - k; i++) {
        int count = 0;
        for (int j = i; j < i + k; j++) {
            bool isDuplicate = false;
            for (int l = i; l < j; l++) { // Check if arr[j] already appeared in the current window
                if (arr[j] == arr[l]) {
                    isDuplicate = true;
                    break;
                }
            }
            if (isDuplicate == false) {
                count++;
            }
        }
        countDistinct.push_back(count);
    }
    return countDistinct;
}

int main() {
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i = 0; i<n; i++) {
        cin>>v[i];
    }
    int windowSize;
    cin>>windowSize;
    vector<int> res = countDistinctBF(v, windowSize);
    for(int i = 0; i < res.size(); i++) {
        cout<<res[i]<<" ";
    }
} // TC : O(n^3) and SC : O(n-(k-1)). Hence, its very poor specially in terms of TC, so we need better approaches!

// Approach 2 : Better Brute Force using Set data structure! : As it has a property that it will only contain distinct numbers and even if you try to insert duplicate it will not include it!
#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

vector<int> countDistinctBF2(vector<int> arr, int k) {
    vector<int> countDistinct;
    for(int i = 0; i <= arr.size() - k; i++) {
        unordered_set<int> s;
        for(int j = i; j < i + k; j++) {
            s.insert(arr[j]);
        }
        countDistinct.push_back(s.size());
    }
    return countDistinct;
}

int main() {
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i = 0; i<n; i++) {
        cin>>v[i];
    }
    int windowSize;
    cin>>windowSize;
    vector<int> res = countDistinctBF2(v, windowSize);
    for(int i = 0; i < res.size(); i++) {
        cout<<res[i]<<" ";
    }
} // TC : O(n*k) and SC : O(k). Way better brute force approach than previous one in terms of time and space!
// Reasoning : Why used unordered_set and not ordered? : Because firstly here we are not concerned about the order of the distinct elements, we are just concerned about how many of them are in a particular window!
//                                                     : the time taken in unordered_set is O(1) in most cases and O(n) in worst! but in case of ordered_set the TC is O(log n) for all cases... and as we are using nested loops, we need something which takes lesser time as loops will already take lot of time! that's why unordered_set is used!
//                                                     : The one advantage of using ordered set over unordered_set is in terms of memory usage. as ordered set uses BST and unordered_set uses Hashmaps which takes more memory but in terms of time complexity unordered set are more useful because of this factor! Also that rare worst case TC of O(n) is due to collisions!

// Optimal Approach : Sliding Window using Map data structure!
//                  : Reasoning : Using unordered maps have the reason as we have discussed above! But as per our problem statement, if you used set here instead of maps, then few things would happen...
//                              : While using set, you can insert the new element easily, but when you try to remove the outgoing element, you don’t know if it appeared multiple times in the window.
//                              : Which may lead to problems like : suppose arr = [1, 2, 1, 3], k = 3, Window: [1, 2, 1] Set: {1, 2}, Now slide → [2, 1, 3] Element going out: 1, but 1 appears **twice**, so removing it **completely** from the set is wrong.
//                              : So you’d under-count or over-count distinct elements if you used a set. That's why using maps through sliding window is more optimal!
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

vector<int> countDistinctSW(vector<int>& arr, int k) {
    unordered_map<int, int> freq;
    vector<int> res;

    // First window
    for (int i = 0; i < k; i++) {
        freq[arr[i]]++;
    }
    res.push_back(freq.size()); // It counts the keys not values, that's why it best to push the size!

    // Slide the window
    for (int i = k; i < arr.size(); i++) {
        // Remove element going out
        freq[arr[i - k]]--;
        if (freq[arr[i - k]] == 0) {
            freq.erase(arr[i - k]);
        }
        // Add new element coming in
        freq[arr[i]]++;
        res.push_back(freq.size());
    }

    return res;
}

int main() {
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i = 0; i<n; i++) {
        cin>>v[i];
    }
    int windowSize;
    cin>>windowSize;
    vector<int> res = countDistinctSW(v, windowSize);
    for(int i = 0; i < res.size(); i++) {
        cout<<res[i]<<" ";
    }
} // TC : O(n) and SC : O(k). Hence this is the most optimal approach!
// From this solution, we can observe one thing that sliding is not about using two pointer, its about using the core idea of sliding window concept! Means, Sliding window is not about syntax, it’s about behavior.
// Core Idea is : Maintaining a "window" (range) over your data, Moving it in one direction (usually left → right) and Updating some summary or property of the window efficiently as it slides.

// Problem Statement 4 : Given an array arr[] and a positive integer k, find the first negative integer for each and every window(contiguous subarray) of size k.
//                     : Constraints : 1 <= arr.size() <= 10^6 (Means we cannot use any method with TC : O(n^2) otherwise it will give TLE)
//                                   : -10^5 <= arr[i] <= 10^5 (Also means we cannot use any method with SC : O(n^2) otherwise it will give SLE)
//                                   : 1 <= k <= arr.size()
// Approach 1 : Brute Force!
#include<iostream>
#include<vector>
#include<unordered_set>
#include<climits>
using namespace std;
// -8 2 3 -6 11
vector<int> firstNegativeBF(vector<int> arr, int k) {
    vector<int> ans;
    for(int i = 0; i <= arr.size() - k; i++) {
        int index = INT_MAX;
        int found = false;
        for(int j = i; j < i + k; j++) {
            if(arr[j] < 0) {
                index = j;
                found = true;
                ans.push_back(arr[index]);
                break;
            }
        }
        if(found == false) {
            ans.push_back(0);
        }
    }
    return ans;
}

int main() {
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i = 0; i<n; i++) {
        cin>>v[i];
    }
    int windowSize;
    cin>>windowSize;
    vector<int> res = firstNegativeBF(v, windowSize);
    for(int i = 0; i < res.size(); i++) {
        cout<<res[i]<<" ";
    }
} // TC : O(nk) and SC : O(k). Hence again this brute force solution is not optimal! as it takes too much time! Now as here again we are concerned about a sub-array where we are given a condition and on based on that we are asked to print output! so we will again use sliding window!

// Optimal Approach : Sliding window using doubly ended queue data structure!
