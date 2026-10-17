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

// Question 2 : Maximum Sum Subarray of Size K! Return the index!
//            : You are given an array of integers v of size n, and an integer k. Your task is to find the starting and ending indices (0-based) of the contiguous subarray of size k that has the maximum sum.
// Approach (Sliding Window) : Start with the first k elements → calculate their sum.
//                           : This is your initial window → store it as maxSum.
//                           : Now, slide the window one step at a time : Subtract the element going out (left side) & Add the element coming in (right side)
//                           : At each step, compare the new sum with maxSum : If it's greater, update maxSum and store the new start & end indices.
//                           : After checking all windows, return the indices of the window with the max sum.
//                           : Time Complexity : O(n) – efficient!
#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int maxSumSubarray(vector<int> v, int k) {
    int n = v.size();
    int sum = 0;
    int i;
    for(i = 0; i < k; i++) {
        sum += v[i];
    }

    int maxSum = sum;
    while(i < n) {
        sum = sum - v[i-k] + v[i];
        maxSum = max(sum, maxSum);
        i++;
    }
    return maxSum;
}

pair<int, int> maxSumSubarrayIndices(vector<int> v, int k) {
    int n = v.size();
    int sum = 0;
    int i;
    for(i = 0; i < k; i++) {
        sum += v[i];
    }

    int maxSum = sum;
    int winStart = 0;
    int WinEnd = k - 1;
    while(i < n) {
        sum = sum - v[i-k] + v[i];
        if(sum > maxSum) {
            maxSum = sum;
            winStart = i - k + 1;
            WinEnd = i;
        }
        i++;
    }
    return {winStart, WinEnd};
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
    int maxSum = maxSumSubarray(v, k);
    cout<<"Max sum : "<<maxSum<<endl;
    pair<int,int> window = maxSumSubarrayIndices(v, k);
    cout<<"Indices : "<<"["<<window.first<<", "<<window.second<<"]";
}

// Question 3 : Given an array of both positive and negative integers, the task is to compute the minimum and maximum elements of all sub-array of size k.
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
// Approach 2 (Deque with Sliding Window) : A deque allows us to push/pop from both front and back, which helps us : Maintain a monotonic structure (For max: decreasing deque (front has largest), For min: increasing deque (front has smallest))
//                                                                                                                 : Efficiently update the window as it slides.
//                                        : Function 1 : maxofSubarrayK(vector<int> v, int k) : We find maximum of each window using a monotonic decreasing deque.
//                                                     : For each element v[i] : Remove Out-of-Window Indices : Front of deque has index of max so far! But if it's outside the current window, we remove it
//                                                     : Maintain Decreasing Order : If current value is greater, remove all smaller values from back! Because they can never be max again
//                                                     : Push Current Index : dq.push_back(i);
//                                                     : Collect Result Once First Window Ends : The front holds the index of the max element in the current window
//                                        : Function 2 : Similarly for minofSubarrayK(vector<int> v, int k)
//                                                     : Change comparison to < to maintain increasing order! Front will now always give minimum
//                                        : Once we have : ans1 = max of every window & ans2 = min of every window! We combine them using the pair data structure!
//                                        : Time Complexity : O(n) for both min and max
//                                        : Space Complexity : O(k) per deque
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

// Approach 2 :
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
} // You can also merge the both functions, if you want!

// Question 4 : Given an array of both positive and negative integers, the task is to compute sum of minimum and maximum elements of all sub-array of size k.
// Approach 1 (Brute Force) : Check if k > n : If yes, it's not possible to form any window of size k, so we return -1 or print "Not possible".
//                          : Initialize a variable (e.g., maxSum) to store the maximum of all min+max sums.
//                          : Traverse all sub-arrays of size k using two nested loops : The outer loop picks the starting index of each window
//                                                                                     : The inner loop traverses k elements starting from that index to find the min and max in that window
//                          : For each window : push the sum into the result vector : result.push_back(maxi + mini);
//                          : Time Complexity: O(n * k)
//                          : Space Complexity: O(1)
// Approach 2 (Sliding Window + Deque) : The approach is the same as in the previous questions! the only difference is that we've combined both functions into one.
//                                     : And, instead of storing the individual maximum and minimum values, we're directly pushing the sum of the maximum and minimum for each window into the result vector.
#include<iostream>
#include<vector>
#include<climits>
using namespace std;

vector<int> maxminSumofSubarrayK(vector<int> v, int k) {
    if(k > v.size()) return {-1};
    int sum = 0;
    vector<int> result;
    for(int i = 0; i <= v.size() - k; i++) {
        int maxi = INT_MIN;
        int mini = INT_MAX;
        for(int j = i; j < i + k; j++) {
            maxi = max(maxi, v[j]);
            mini = min(mini, v[j]);
        }
        result.push_back(maxi + mini);
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
    vector<int> ans = maxminSumofSubarrayK(v, k);
    for(int val : ans) {
        cout<<val<<" ";
    }
}

// Approach 2 : 
#include<iostream>
#include<vector>
#include<deque>
using namespace std;

vector<int> sumOfMaxMinInWindowK(vector<int>& v, int k) {
    deque<int> maxDq, minDq;
    vector<int> result;

    for(int i = 0; i < v.size(); i++) {
        if(!maxDq.empty() && maxDq.front() <= i - k) maxDq.pop_front();
        if(!minDq.empty() && minDq.front() <= i - k) minDq.pop_front();

        while(!maxDq.empty() && v[i] > v[maxDq.back()]) maxDq.pop_back();
        maxDq.push_back(i);

        while(!minDq.empty() && v[i] < v[minDq.back()]) minDq.pop_back();
        minDq.push_back(i);

        if(i >= k - 1) {
            int sum = v[maxDq.front()] + v[minDq.front()];
            result.push_back(sum);
        }
    }
    return result;
}

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];
    int k;
    cin >> k;
    vector<int> result = sumOfMaxMinInWindowK(v, k);
    for(int val : result) {
        cout << val << " ";
    }
}