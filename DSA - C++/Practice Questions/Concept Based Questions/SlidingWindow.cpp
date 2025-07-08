// ------------------------------------------------------------ Sliding Window Concept ----------------------------------------------------------------------->
// Question 1 : Given an array of both positive and negative integers, the task is to compute the maximum subarray sum possible with window size k.
// Approach (Brute Force) : We use two loops to check every possible subarray of size k.
//                        : The outer loop picks the starting index of each subarray.
//                        : The inner loop calculates the sum of k elements starting from that index.
//                        : We keep track of the maximum sum found so far.
//                        : Time Complexity : O(n * k)
#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int maxSubarraySum(vector<int> v, int k) {
    int maxSum = INT_MIN;
    int n = v.size();
    if (n < k) return -1;
    for(int i = 0; i <= n - k; i++) {
        int sum = 0;
        for(int j = i; j < i + k; j++) {
            sum += v[j];
        }
        maxSum = max(maxSum, sum);
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
    int maxSum = maxSubarraySum(v);
}

// Approach (Sliding Window) : First, calculate the sum of the first k elements (initial window).
//                           : Then, slide the window by one element at a time:
//                           : Remove the first element of the previous window.
//                           : Add the next element in the array.
//                           : Update the maximum sum after each slide.
//                           : Time Complexity : O(n) – efficient!
#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int maxSubarraySum(vector<int> v, int k) {
    int i = 0; int j = i + k;
    int n = v.size();
    int maxSum = INT_MIN;

    int sum = 0;
    for(int i = 0; i < k; i++) {
        sum += v[i];
    }
    maxSum = max(maxSum, sum);

    for(int i = k; i < n; i++) {
        sum = sum - v[i - k] + v[i];
        maxSum = max(maxSum, sum);
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

// Question 1 : Given an array of both positive and negative integers, the task is to compute the minimum and maximum elements of all sub-array of size k.
// Thinking : Here, the array provided can be sorted or unsorted + contains duplicates/ or not!
//          : If sorted, then it becomes pretty simple! As first value of every window will the "min" element for that window! and every "k-1" index of every window will be the "max" value for that window! And it doesn't matter that array contains duplicates or not!
//          : But, if the array is unsorted! Then simply use these following methods!
// Approach 1 (Brute Force) : First, check if the given value of k is valid.
//                          : If k is greater than the size of the array (n), it's not possible to form any subarray of size k. In that case, we should return -1 or display an appropriate message.
//                          : If k is less than or equal to n, we proceed with the brute-force approach : Using two nested loops : The outer loop runs from i = 0 to i <= n - k, which helps us move the window of size k across the array.
//                                                                                                                               : For each position i, the inner loop runs from j = i to j < i + k to traverse that particular sub-array of size k.
//                          : Within the inner loop : We calculate the maximum and minimum values of the current window manually.
//                          : After finding min and max for that window : We either print them or store them (e.g., in a vector of pairs or 2D vector) if needed for later use.
//                          : Time Complexity : O(n*k)
//                          : Space Complexity : O(n - k + 1) = O(n)
// Approach 2 (Deque with Sliding Window) : 

// Approach 1 :
#include<iostream>
#include<vector>
#include<climits>
using namespace std;

vector<vector<int>> maxminPairs(vector<int> v, int k) {
    if(k > v.size()) {
        cout << "Window size k is greater than array size. Not possible!" << endl;
        return -1;
    }
    vector<vector<int>> result;
    for(int i = 0; i <= v.size() - k; i++) {
        int maxi = INT_MIN;
        int mini = INT_MAX;
        for(int j = i; j < i + k; j++) {
            maxi = max(maxi, v[j]);
            mini = min(mini, v[j]);
        }
        vector<int> temp;
        temp.push_back(mini);
        temp.push_back(maxi);
        result.push_back(temp);
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
    vector<vector<int>> result = maxminPairs(v, k);
    for(int i = 0; i < result.size(); i++) {
        for(int j = 0; j < result[i].size(); j++) {
            cout<<result[i][j]<<" ";
        }
        cout<<endl;
    }
}

// Question 1 : Given an array of both positive and negative integers, the task is to compute sum of minimum and maximum elements of all sub-array of size k.
// Approach 1 (Brute Force) : Check if k > n : If yes, it's not possible to form any window of size k, so we return -1 or print "Not possible".
//                          : Initialize a variable (e.g., maxSum) to store the maximum of all min+max sums.
//                          : Traverse all sub-arrays of size k using two nested loops : The outer loop picks the starting index of each window
//                                                                                     : The inner loop traverses k elements starting from that index to find the min and max in that window
//                          : For each window : Compute sum = min + max & Update maxSum = max(maxSum, sum)
//                          : Time Complexity: O(n * k)
//                          : Space Complexity: O(1)
#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int maxOfMinPlusMaxInSubarrays(vector<int> v, int k) {
    if(k > v.size()) return -1;
    int sum = INT_MIN;
    for(int i = 0; i <= v.size() - k; i++) {
        int maxi = INT_MIN;
        int mini = INT_MAX;
        for(int j = i; j < i + k; j++) {
            maxi = max(maxi, v[j]);
            mini = min(mini, v[j]);
        }
        sum = max(sum, maxi + mini);
    }
    return sum;
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
    cout<<maxOfMinPlusMaxInSubarrays(v, k);
}