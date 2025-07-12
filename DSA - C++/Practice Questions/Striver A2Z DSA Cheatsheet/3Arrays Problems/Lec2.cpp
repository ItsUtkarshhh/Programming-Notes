// ------------------------------------------------------------ Lec 2 : Medium ---------------------------------------------------------------------------------------------->
// Question 1 : Two Sum!
//            : Variant 1 : Return YES if there exist two numbers such that their sum is equal to the target. Otherwise, return NO.
//            : Variant 2 : Return indices of the two numbers such that their sum is equal to the target. Otherwise, we will return {-1, -1}.
//            : Conditions : You are not allowed to use the same element twice. Example: If the target is equal to 6 and num[1] = 3, then nums[1] + nums[1] = target is not a solution.
// Approach (Brute Force) for V1 : Try every valid pair (i, j) and check if v[i] + v[j] == k.
//                               : Time : O(n²) → Slow for large arrays
//                               : Space : O(1)
#include<iostream>
#include<vector>
using namespace std;

bool twoSum1_V1(vector<int> v, int k) {
    int n = v.size();
    for(int i = 0; i < n - 1; i++) {
        for(int j = i + 1; j < n; j++) {
            if(v[i] + v[j] == k) {
                return true;
            }
        }
    }
    return false;
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
    if(twoSum1_V1(v, k)) cout<<"Yes exist!";
    else cout<<"No!";
}

// Approach (Better Approach) for V1 : Store frequency of each element in a map. (ordered/unordered) - better if unordered!
//                                   : For each number, check if k - num exists in the map.
//                                   : Time : O(n) average (with unordered_map)
//                                   : Space : O(n)
#include<iostream>
#include<vector>
#include<map>
#include<unordered_map>
using namespace std;

bool twoSum2_V1(vector<int> v, int k) {
    int n = v.size();
    map<int, int> mp;
    for(int i = 0; i < n; i++) {
        mp[v[i]]++;
    }
    
    for(int i = 0; i < n; i++) {
        int complement = k - v[i];
        if(mp.count(complement)) {
            if(complement != v[i] || mp[v[i]] > 1) {
                return true;
            }
        }
    }
    return false;
}

bool twoSum3_V1(vector<int> v, int k) { // Faster due to unordered_map!
    int n = v.size();
    unordered_map<int, int> mp;
    for(int i = 0; i < n; i++) {
        mp[v[i]]++;
    }

    for(int i = 0; i < n; i++) {
        int complement = k - v[i];
        if(mp.count(complement)) {
            if(complement != v[i] || mp[v[i]] > 1) {
                return true;
            }
        }
    }
    return false;
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
    if(twoSum2_V1(v, k)) cout<<"Yes exist!";
    else cout<<"No!";

    if(twoSum3_V1(v, k)) cout<<"Yes exist!";
    else cout<<"No!";
}

// Approach (Optimal Approach) for V1 : While traversing, check if k - num is already seen.
//                                    : Time : O(n) average
//                                    : Space : O(n)
#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

bool twoSum4_V1(vector<int> v, int k) {
    unordered_set<int> seen;
    for (int num : v) {
        if (seen.count(k - num)) return true;
        seen.insert(num);
    }
    return false;
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
    if(twoSum4_V1(v, k)) cout<<"Yes exist!";
    else cout<<"No!";
}

// Approach (Optimal Solution) for V1 when array is sorted! : Two pointers!
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool twoSum5_V1(vector<int> v, int k) {
    sort(v.begin(), v.end());
    int n = v.size();
    int i = 0; int j = n - 1;
    int sum = 0;
    while(i < j) {
        sum = v[i] + v[j];
        if(sum == k) return true;
        if(sum > k) j--;
        else i++;
    }
    return false;
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
    if(twoSum5_V1(v, k)) cout<<"Yes exist!";
    else cout<<"No!";
}

// Approach (Brute Force) for V2 : Try every valid pair (i, j) and check if v[i] + v[j] == k.
//                               : Time : O(n²) → Slow for large arrays
//                               : Space : O(1)
#include<iostream>
#include<vector>
using namespace std;

pair<int, int> twoSum1_V2(vector<int> v, int k) {
    int n = v.size();
    pair<int, int> valPair;
    for(int i = 0; i < n - 1; i++) {
        for(int j = i + 1; j < n; j++) {
            if(v[i] + v[j] == k) {
                valPair.first = i;
                valPair.second = j;
                return valPair;
            }
        }
    }
    return {-1, -1};
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
    pair<int, int> ans = twoSum1_V2(v, k);
    cout<<"["<<ans.first<<", "<<ans.second<<"]"<<endl;
}

// Approach (Better Solution) for V2 : Traverse the array, and keep checking whether its complement exists! if no then insert it with its index!
//                                   : Otherwise, if the complement exists, then simply return the pair!
//                                   : Time Complexity : O(n)
//                                   : Space Complexity : O(n)
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

pair<int, int> twoSum2_V2(vector<int> v, int k) {
    unordered_map<int, int> seen;
    for(int i = 0; i < v.size(); i++) {
        if(seen.find(k - v[i]) != seen.end()) return {seen[k - v[i]], i};
        seen[v[i]] = i;
    }
    return {-1, -1};
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
    pair<int, int> ans = twoSum2_V2(v, k);
    cout<<"["<<ans.first<<", "<<ans.second<<"]"<<endl;
}

// // Approach (Optimal Solution) for V2 when array is sorted! : Two pointers!
#include<iostream>
#include<vector>
using namespace std;

pair<int, int> twoSum2_V2(vector<int> v, int k) {
    int n = v.size();
    vector<pair<int, int>> arr;  // {value, original index}
    for (int i = 0; i < n; i++) {
        arr.push_back({v[i], i});
    }

    sort(arr.begin(), arr.end());

    int i = 0; int j = n - 1;
    while(i < j) {
        int sum = arr[i].first + arr[j].first;
        if (sum == k) return {arr[i].second, arr[j].second}; // return indices of original array!
        if(sum > k) j--;
        else i++;
    }
    return {-1, -1};
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
    pair<int, int> ans = twoSum2_V2(v, k);
    cout<<"["<<ans.first<<", "<<ans.second<<"]"<<endl;
}

// Question 2 : Sort 0s, 1s, 2s!
//            : Given an array consisting of only 0s, 1s, and 2s. Write a program to in-place sort the array without using inbuilt sort functions. ( Expected: Single pass-O(N) and constant space)
// Approach 1 (Brute Force) : Simply use any sorting algorithm! But those algorithms we know as of now are either slow or takes an extra space!
// Approach 2 (Dutch National Flag Algorithm) : It’s called the Dutch National Flag algorithm because : The Dutch flag has three bands: red, white, blue. Similarly, we want to sort 3 types of elements into 3 separate "bands" or regions.
//                                            : In this classic problem : 0 → First color (e.g., red). 1 → Middle color (e.g., white). 2 → Last color (e.g., blue)
//                                            : We maintain 3 regions in the array using 3 pointers : low  |    Left region for 0s    | All elements left of low are 0s
//                                                                                                  : mid  |  Current element pointer | To check and decide where current element goes
//                                                                                                  : high |    Right region for 2s   | All elements right of high are 2s
//                                            : We process the array from left to right, and at each step : If arr[mid] == 0 : This belongs on the left side, Swap with arr[low], and move low and mid forward, Because you’ve handled one more 0
//                                                                                                        : If arr[mid] == 1 : This is already in the middle zone, Just move mid++
//                                                                                                        : If arr[mid] == 2 : This belongs on the right side, Swap with arr[high], and only move high--. mid is not moved, because the new value at mid still needs to be processed.
#include<iostream>
#include<vector>
using namespace std;

void sort012(vector<int> &v) {
    int low = 0;
    int mid = 0;
    int high = v.size() - 1;
    while(mid <= high) {
        if(v[mid] == 0) {
            swap(v[low], v[mid]);
            mid++; low++;
        }
        else if(v[mid] == 1) {
            mid++;
        }
        else if(v[mid] == 2) {
            swap(v[high], v[mid]);
            high--;
        }
    }
}

int main() {
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i = 0; i < n; i++) {
        cin>>v[i];
    }
    sort012(v);
    for(int i = 0; i < n; i++) {
        cout<<v[i]<<" ";
    }
}

// Question 3 : Find the Majority Element that occurs more than N/2 times!
//            : Given an array of N integers, write a program to return an element that occurs more than N/2 times in the given array. You may consider that such an element always exists in the array.
// Approach 1 (Brute Force) : Iterate in a nested loop and count occurences! and if it gets > n/2, then it is majority element! TC : O(n^2) & SC : O(1)
// Approach 2 (Maps) : Iterate the arrays once, and store count of every element! and if it gets > n/2, then it is majority element! TC : O(n logn) & SC : O(n)
// Approach 2.2 (Unordered Maps) : Iterate the arrays once, and store count of every element! and if it gets > n/2, then it is majority element! TC : O(n) for avg & best case & SC : O(n)
// Approach 3 (Moore's Voting Algorithm) : Imagine you're in a room full of people, and you're conducting a vote to decide who the most popular person is.
//                                       : Let’s say : Every person either votes for a candidate (say A) or votes against them. When someone supports A, A gains +1. When someone opposes A, it’s like A loses -1.
//                                       : If you keep doing this : If A is truly supported by more than half, then after all ups and downs, they'll still stand strong. Anyone who isn’t backed by a majority will get “eliminated” over time.
//                                       : This is exactly what Moore’s Voting Algorithm simulates!
//                                       : Phase 1 : Finding a Candidate : We use count = 0 & element = -1 (or any default)
//                                                 : What is this doing? : If count == 0: we "reset" our candidate — like electing a new leader.
//                                                                       : If current value == current candidate → support received → count++
//                                                                       : If different value → opposition → count--
//                                                                       : So candidate’s strength goes up or down, depending on match/mismatch
//                                                 : But wait — what if this candidate is not majority? That's why we have...
//                                       : Phase 2 : Verifying the Candidate : We now count how many times the candidate actually appears in the array
//                                                 : Why This Works : Let’s assume that there is a majority element.
//                                                                  : Let’s say M is that element, and it appears more than n/2 times.
//                                                                  : Every time we see M, count++
//                                                                  : Every time we see a non-M, count--
//                                                                  : Since M appears more than the rest combined, the net count will be positive and M will survive the elimination battle.
//                                                                  : Hence, at the end of Phase 1, we are guaranteed to get the majority element (if it exists). If it doesn’t exist, Phase 1 may still give a candidate, but Phase 2 will catch the mistake.
//                                       : Time Complexity : O(n) & Space Complexity : O(1)
#include<iostream>
using namespace std;

void findMajorityElement(int* arr, int n) {
    int count = 0;
    int element = 0;
    for(int i = 0; i < n; i++) {
        if(count == 0) {
            count = 1;
            element = arr[i];
        }
        else if(arr[i] == element) {
            count++;
        }
        else {
            count--;
        }
    }
    int countFinal = 0;
    for(int i = 0; i < n; i++) {
        if(arr[i] == element) {
            countFinal++;
        }
    }
    (countFinal > n/2) ? cout << element : cout << "No Majority Element!";
}

int main() {
    int n;
    cin>>n;
    int* arr = (int*)malloc(n * sizeof(int));
    // int* arr = new int[n]; // Modern and correct in C++
    // vector<int> arr(n); // Best for simplicity
    for(int i = 0; i < n; i++) {
        cin>>arr[i];
    }
    findMajorityElement(arr, n);
}

// Question 4 : Maximum Subarray Sum in an Array (Kadane's Algorithm)
//            : Variation 1 : Given an integer array arr, find the contiguous subarray (containing at least one number) which has the largest sum and returns its sum!
//            : Variation 2 : Given an integer array arr, find the contiguous subarray (containing at least one number) which has the largest sum and returns its sum and prints the subarray!
// Approach 1 (Brute Force) : Iterate over the nested loop! and simply update maxSum & start & end variables! and lastly print the subarray and return the maxSum!
// Approach 2 (Kadane's Algorithm) : Imagine going through the array from left to right.
//                                 : You keep track of a current sum of the subarray (currentSum)
//                                 : If at any point, this currentSum becomes less than 0, it is useless to continue with this subarray — it’ll only bring down any future sum.
//                                 : So, reset the current sum to 0 and start fresh from the next index.
//                                 : This is where the main greedy idea lies : "If the running sum is negative, drop it. It won’t help in getting a larger sum later."
// Approach 1 : Solving both V1 & V2.
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

// Approach 2 : Solving both V1.
#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int maxSumSubarray(vector<int> v) {
    int currentSum = 0;
    int maxSum = INT_MIN;
    for(int i = 0; i < v.size(); i++) {
        currentSum += v[i];
        maxSum = max(currentSum, maxSum);
        if(currentSum < 0) {
            currentSum = 0;
        }
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
    int ans = maxSumSubarray(v);
    cout<<ans;
}

// Approach 2 (Kadane's Algorithm) : Same approach, just few steps of assigning indices to start & end! to mark the subarray and later printing it! Solving both V1 & V2.
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

// Question 5 : Stock Buy And Sell : You are given an array of prices where prices[i] is the price of a given stock on an ith day.
//            : You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock. Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.
// Approach 1 (Brute Force) : Simply iterate in a nested loop and keep tracking maxProfit. And at the end of both the loops, you will get the maxProfit! TC : O(n^2) & SC : O(1)
// Approach 2 (Better) : Rather, first find the minPrice & minPriceDay for a stock to buy! And then start checking the maximum profit possible after that day by traversing the array again! TC : O(n) & SC : O(1)
// Approach 3 (Optimal) : Approach 2 privides good time complexity! but it traverses the loop two times! So better put this whole logic into one! Track minimum stock price & maximum prfit simultaneously!
// Approach 1 :
#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int maxProfitStock(vector<int> v) {
    int maxProfit = 0;
    int profit = 0;
    for(int i = 0; i < v.size(); i++) {
        for(int j = i + 1; j < v.size(); j++) {
            profit = v[j] - v[i];
            maxProfit = max(profit, maxProfit);
        }
    }
    return maxProfit;
}

int main() {
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i = 0; i < n; i++) {
        cin>>v[i];
    }
    int ans = maxProfitStock(v);
    cout<<ans;
}

// Approach 2 :
#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int maxProfitStock(vector<int> v) {
    int maxProfit = 0;
    int minPrice = INT_MAX;
    int minPriceDay = -1;
    for(int i = 0; i < v.size(); i++) {
        if(v[i] < minPrice) {
            minPrice = v[i];
            minPriceDay = i;
        }
    }
    for(int i = minPriceDay + 1; i < v.size(); i++) {
        maxProfit = max(v[i] - v[minPriceDay], maxProfit);
    }
    return maxProfit;
}

int main() {
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i = 0; i < n; i++) {
        cin>>v[i];
    }
    int ans = maxProfitStock(v);
    cout<<ans;
}

// Approach 3 :
#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int maxProfitStock(vector<int> v) {
    int maxProfit = 0;
    int minPrice = INT_MAX;
    for(int i = 0; i < v.size(); i++) {
        minPrice = min(v[i], minPrice);
        maxProfit = max(v[i] - minPrice, maxProfit);
    }
    return maxProfit;
}

int main() {
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i = 0; i < n; i++) {
        cin>>v[i];
    }
    int ans = maxProfitStock(v);
    cout<<ans;
}