// ------------------------------------------------------------ Lec 1 : Easy ---------------------------------------------------------------------------------------------->
// Question 1 : Find the largest element in the array!
#include<iostream>
#include<climits>
using namespace std;

int main() {
    int n;
    cin>>n;
    int* arr = new int[n];
    for(int i = 0; i<n; i++) {
        cin>>arr[i];
    }
    int maxVal = INT_MIN;
    for(int i = 0; i<n; i++) {
        if(arr[i] > maxVal) {
            maxVal = arr[i];
        }
    }
    cout<<"Max value of the array : "<<maxVal;
} // TC : O(n) and SC : O(1) rest all methods will be overkill.

// Question 2 : Find the second largest element in the array!
#include<iostream>
#include<climits>
using namespace std;

int main() {
    int n;
    cin>>n;
    int* arr = new int[n];
    for(int i = 0; i<n; i++) {
        cin>>arr[i];
    }
    int max1 = arr[0];
    int max2 = INT_MIN;
    for(int i = 0; i<n; i++) {
        if(arr[i] > max1) {
            max2 = max1;
            max1 = arr[i];
        }
        else if(arr[i] < max1 && arr[i] > max2) {
            max2 = arr[i];
        }
    }
    if(max2 == INT_MIN) {
        cout<<-1;
    }
    else {
        cout<<"Second largest element of the array : "<<max2;
    }
}

// Question 3 : Check if an array is sorted or not!
#include<iostream>
using namespace std;

int main() {
    int n;
    cin>>n;
    int* arr = new int[n];
    for(int i = 0; i<n; i++) {
        cin>>arr[i];
    }
    bool sorted = true;
    for(int i = 0; i<n-1; i++) {
        if(arr[i] > arr[i+1]) {
            sorted = false;
            break;
        }
    }
    if(sorted) {
        cout<<"Array is sorted!";
    }
    else {
        cout<<"Not sorted!";
    }
}

// Generalise it for ascending and descending order!
#include<iostream>
using namespace std;

int main() {
    int n;
    cin>>n;
    int* arr = new int[n];
    for(int i = 0; i<n; i++) {
        cin>>arr[i];
    }
    bool ascending = true;
    bool descending = true;
    for(int i = 0; i<n-1; i++) {
        if(arr[i] > arr[i+1]) {
            ascending = false;
        }
        if(arr[i] < arr[i+1]) {
            descending = false;
        }
    }
    if(ascending) cout<<"Array is sorted in ascending order!";
    else if(descending) cout<<"Array is sorted in ascending order!";
    else cout<<"Not sorted at all!";
}

// Question 4 : Remove Duplicates in-place from Sorted Array!
#include<iostream>
#include<vector>
using namespace std;

vector<int> removeDuplicates(vector<int> v) {
    vector<int> ans;
    vector<bool> dupExist(v.size(), true);
    for(int i = 0; i<v.size(); i++) {
        int val = v[i];
        for(int j = i+1; j<v.size(); j++) {
            if(val == v[j] && i != j) {
                dupExist[j] = false;
            }
        }
    }
    for(int i = 0; i<dupExist.size(); i++) {
        if(dupExist[i]) {
            ans.push_back(v[i]);
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
    vector<int> res = removeDuplicates(v);
    for(int i = 0; i<res.size(); i++) {
        cout<<res[i]<<" ";
    }
} // Not optimal solution! as TC : O(n^2) and as here two vectors are created hence the SC : O(n)! and primarily it is not in-place!

// Better solution : As the array is sorted! we can do the in-place sorting!
//                 : Actually what we wanted to do is : Remove duplicates in-place such that each element appears only once and return the new length. It does not matter what you leave beyond the new length.
//                                                    : Means, as per our constraints, we just need to return a new length of the sorted array where there is no duplicates also it must be in-place means no extra space should be used! 
#include<iostream>
#include<vector>
using namespace std;

int removeDuplicates(vector<int> &v) {
    int i = 0;
    for(int j = 1; j<v.size(); j++) {
        if(v[i] != v[j]) {
            i++;
            v[i] = v[j];
        }
    }
    return i+1; // Returning the new size!
}

int main() {
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i = 0; i<n; i++) {
        cin>>v[i];
    }
    int newSize = removeDuplicates(v);
    for(int i = 0; i<newSize; i++) { // The duplicates are still there in the array! its just that we have combined the unique elements together and returned the size accordingly so that we dont encounter duplicates anymore!
        cout<<v[i]<<" ";
    }
}

// Question 5 : Left rotate an array by one place!
// Approach 1 : Using reverse trick!
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void leftRotate(vector<int> &v) {
    reverse(v.begin(), v.end());
    reverse(v.begin(), v.end()-1);
}

int main() {
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i = 0; i<n; i++) {
        cin>>v[i];
    }
    leftRotate(v);
    for(int i = 0; i<n; i++) {
        cout<<v[i]<<" ";
    }
}

// Approach 2 : Using simple logic or shifting!
#include<iostream>
#include<vector>
using namespace std;

void leftRotate(vector<int> &v) {
    int temp = v[0];
    for(int i = 0; i<v.size()-1; i++) {
        v[i] = v[i+1];
    }
    v[v.size()-1] = temp;
}

int main() {
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i = 0; i<n; i++) {
        cin>>v[i];
    }
    leftRotate(v);
    for(int i = 0; i<n; i++) {
        cout<<v[i]<<" ";
    }
}

// Question 6 : Rotate array by K elements left or right!
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void rotateArray(vector<int>& v, char side, int k) {
    int n = v.size();
    if(n == 0) return;
    k = k % n; // Handle large k

    if(side == 'L') {
        reverse(v.begin(), v.begin() + k);
        reverse(v.begin() + k, v.end());
        reverse(v.begin(), v.end());
    }
    else if(side == 'R') {
        reverse(v.begin(), v.end());
        reverse(v.begin(), v.begin() + k);
        reverse(v.begin() + k, v.end());
    }
    else {
        cout << "Enter valid side!" << endl;
        return;
    }
    for(int i = 0; i < n; i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}

int main() {
    int n;
    cout << "Enter the size: ";
    cin >> n;
    vector<int> v(n);
    cout << "Enter array elements: ";
    for(int i = 0; i < n; i++) {
        cin >> v[i];
    }
    
    int places;
    cout << "How many places? : ";
    cin >> places;
    char side;
    cout << "Which side? (L/R): ";
    cin >> side;
    
    rotateArray(v, side, places);
}

// Question 7 : Move zeroes to the end!
#include<iostream>
#include<vector>
using namespace std;

void moveZeroes(vector<int> &v) {
    int i = 0;
    int j = v.size() - 1;
    while(i < j) {
        if(v[i] == 0 && v[j] == 0) {
            j--;
        }
        else if(v[i] != 0 && v[j] != 0) {
            i++;
        }
        else if(v[i] == 0 && v[j] != 0) {
            swap(v[i], v[j]);
            i++; j--;
        }
        else {
            i++; j--;
        }
    }
    for(int i = 0; i<v.size(); i++) {
        cout<<v[i]<<" ";
    }
    return;
}

int main() {
    int n;
    cout << "Enter the size: ";
    cin >> n;
    vector<int> v(n);
    cout << "Enter array elements: ";
    for(int i = 0; i < n; i++) {
        cin >> v[i];
    }
    moveZeroes(v);
} // Problem with it is that it disrupts the relative order of elements!

// Better approach :
#include<iostream>
#include<vector>
using namespace std;

void moveZeroes(vector<int>& v) {
    int lastNonZeroIndex = 0;
    for(int i = 0; i < v.size(); i++) {
        if(v[i] != 0) {
            swap(v[i], v[lastNonZeroIndex]);
            lastNonZeroIndex++;
        }
    }
    for(int i = 0; i<v.size(); i++) {
        cout<<v[i]<<" ";
    }
    return;
}

int main() {
    int n;
    cout << "Enter the size: ";
    cin >> n;
    vector<int> v(n);
    cout << "Enter array elements: ";
    for(int i = 0; i < n; i++) {
        cin >> v[i];
    }
    moveZeroes(v);
}

// Question 8 : Linear Search in C
#include<iostream>
#include<vector>
using namespace std;

void linearSearch(vector<int> v, int key) {
    for(int i = 0; i<v.size(); i++) {
        if(key == v[i]) {
            cout<<"Key present at "<<i<<endl;
            return;
        }
    }
    cout<<"Key not found!";
    return;
}

int main() {
    int n;
    cout << "Enter the size: ";
    cin >> n;
    vector<int> v(n);
    cout << "Enter array elements: ";
    for(int i = 0; i < n; i++) {
        cin >> v[i];
    }
    int key;
    cout<<"Enter key : ";
    cin>>key;
    linearSearch(v, key);
}

// Question 9 : You're given two arrays arr1 and arr2. You need to return a union of the two arrays!
//            : The final array should contain : One instance of each element of both arrays in the final array!
//                                             : If there is a common element in both array, then one of the instance will be in the final array!
//                                             : Example : If array1 = [1,2,3,3,4] & array2 = [1,2,3,3,4,5,6]. Then final array should contain array3 = [1,2,3,3,4,5,6]
// Thinking & Approach : Goals of a Good Solution : It should cover most of the common use-cases/test-cases!
//                                                : It should take less time!
//                                                : It should take less space!
//                     : Some most common use-cases could be : Both Unsorted arrays! - (Handling 'contains duplicates' and 'doesn't contains duplicates' cases!) - (Want sorted/unsorted output)
//                                                           : One Sorted + Another Unsorted arrays! - (Handling 'contains duplicates' and 'doesn't contains duplicates' cases!) - (Want sorted/unsorted output)
//                                                           : Both Sorted arrays! - (Handling 'contains duplicates' and 'doesn't contains duplicates' cases!) - (Want sorted/unsorted output)
//                                                           : This case is mixture of any of the above! But no duplicates allowed in output! - (Want sorted/unsorted output)
//                     : And based on that, some solutions are proposed below!
// Approach 1 (Brute Force Approach) : Working : Traverse the first array and push all elements to final.
//                                             : For every element in v1, look in v2 for a match. If found, mark that in v2 as INT_MIN to avoid repeating it.
//                                             : Finally, push remaining unmarked (!= INT_MIN) elements from v2.
//                                             : Sort the final array before returning.
//                                   : Time Complexity : Worst case : O(n × m + (n + m) log(n + m))
//                                   : Pros : Simple to understand & Works for all types of inputs
//                                   : Cons : Not efficient, Mutates input (by marking INT_MIN) & Not scalable for large input
// Approach 2 (Frequency Map with Max Count Approach) : Working : Create two frequency maps: freq1, freq2.
//                                                              : Traverse both arrays and count frequencies of each element.
//                                                              : Merge the maps, keeping the max frequency for each element.
//                                                              : Reconstruct the final array from the combined frequency map.
//                                                   : Time Complexity : Worst case : O((n + m) log(n + m)) due to map operations
//                                                   : Pros : Clean and very flexible, Retains maximum frequency of each element & Great for interview use-cases
//                                                   : Cons : Slightly higher space usage (due to maps)
// Approach 3 (Using Set for Unique Union Approach) : Working : Insert all elements from both arrays into a set
//                                                            : Since sets store unique values only, all duplicates are removed
//                                                            : Convert the set into a vector and return
//                                                  : Time Complexity : Worst case : O((n + m) log(n + m)) — insertion in set
//                                                  : Pros : Very concise, Automatically removes duplicates & Sorted output if using std::set
//                                                  : Cons : Doesn’t retain duplicate frequency, Output not in input order
// Approach 4 (Two-Pointer Merge – Keep All Duplicates Approach) : Working : Works only when both arrays are sorted
//                                                               : Use two pointers and traverse both arrays : If v1[i] < v2[j], add v1[i], move i
//                                                                                                           : If v2[j] < v1[i], add v2[j], move j
//                                                                                                           : If equal, add one and move both. Then add remaining elements.
//                                                               : Time Complexity : Worst case : O(n + m) — best performance among all
//                                                               : Pros : Fastest approach, Keeps duplicates & Maintains sorted order
//                                                               : Cons : Requires sorted input
// Approach 5 (Two-Pointer Merge – Unique Output Approach) : Working : Same two-pointer logic as above, but with an extra check : Before adding any element to ans, ensure ans.back() != element
//                                                                   : This removes adjacent duplicates during merge
//                                   : Time Complexity : Worst case : O(n + m) — linear
//                                   : Pros : Simple, efficient, Avoids duplicates & Doesn’t use extra map/set.
//                                   : Cons : Only works on sorted arrays & Doesn’t keep multiple instances of same element.
#include<iostream>
#include<vector>
#include<climits>
#include<set>
#include<map>
#include<algorithm>
using namespace std;

// Approach 1 :
vector<int> findUnion1(vector<int> v1, vector<int> v2) {
    vector<int> final;
    for(int i = 0; i < v1.size(); i++) {
        int element = v1[i];
        final.push_back(element);
        for(int j = 0; j < v2.size(); j++) {
            if(element == v2[j]) {
                v2[j] = INT_MIN;
                break;
            }
        }
    }
    for(int i = 0; i < v2.size(); i++) {
        if(v2[i] != INT_MIN) {
            final.push_back(v2[i]);
        }
    }
    sort(final.begin(), final.end());
    return final;
}

// Approach 2 :
vector<int> findUnion2(vector<int> v1, vector<int> v2) {
    vector<int> finalVec;
    map<int, int> freq1;
    for(int i = 0; i < v1.size(); i++) {
        freq1[v1[i]]++;
    }
    
    map<int, int> freq2;
    for(int i = 0; i < v2.size(); i++) {
        freq2[v2[i]]++;
    }
    
    for(auto it: freq2) {
        int element = it.first;
        freq1[element] = max(it.second, freq1[it.first]);
    }
    
    for(auto it : freq1) {
        for(int i = 0; i < it.second; i++) {
            finalVec.push_back(it.first);
        }
    }
    return finalVec;
}

// Approach 3 :
vector<int> findUnion3(vector<int> v1, vector<int> v2) {
    set<int> finalSet;
    for(int i = 0; i < v1.size(); i++) finalSet.insert(v1[i]);
    for(int i = 0; i < v2.size(); i++) finalSet.insert(v2[i]);
    return vector<int>(finalSet.begin(), finalSet.end());
}

// Approach 4 :
vector<int> findUnion4(vector<int> v1, vector<int> v2) {
    int i = 0; int j = 0;
    vector<int> finalVec;
    while(i < v1.size() && j < v2.size()) {
        if(v1[i] < v2[j]) {
            finalVec.push_back(v1[i]);
            i++;
        }
        else if(v2[j] < v1[i]) {
            finalVec.push_back(v2[j]);
            j++;
        }
        else {
            finalVec.push_back(v1[i]);
            i++;
            j++;
        }
    }
    while(i < v1.size()) {
        finalVec.push_back(v1[i]);
        i++;
    }
    while(j < v2.size()) {
        finalVec.push_back(v2[j]);
        j++;
    }
    return finalVec;
}

// Approach 5 :
vector<int> findUnion5(vector<int> v1, vector<int> v2) {
    int i = 0, j = 0;
    vector<int> ans;
    while(i < v1.size() && j < v2.size()) {
        if(v1[i] < v2[j]) {
            if(ans.empty() || ans.back() != v1[i]) 
                ans.push_back(v1[i]);
            i++;
        }
        else if(v2[j] < v1[i]) {
            if(ans.empty() || ans.back() != v2[j]) 
                ans.push_back(v2[j]);
            j++;
        }
        else { // Equal elements
            if(ans.empty() || ans.back() != v1[i]) 
                ans.push_back(v1[i]);
            i++;
            j++;
        }
    }
    while(i < v1.size()) {
        if(ans.empty() || ans.back() != v1[i]) 
            ans.push_back(v1[i]);
        i++;
    }
    while(j < v2.size()) {
        if(ans.empty() || ans.back() != v2[j]) 
            ans.push_back(v2[j]);
        j++;
    }
    return ans;
}

int main() {
    int n1, n2;
    cin>>n1>>n2;
    vector<int> v1(n1);
    vector<int> v2(n2);
    for(int i = 0; i < n1; i++) {
        cin>>v1[i];
    }
    for(int i = 0; i < n2; i++) {
        cin>>v2[i];
    }
    vector<int> result = findUnion1(v1, v2);
    // vector<int> result = findUnion2(v1, v2);
    // vector<int> result = findUnion3(v1, v2);
    // vector<int> result = findUnion4(v1, v2);
    // vector<int> result = findUnion5(v1, v2);
    for(int i = 0; i < result.size(); i++) {
        cout<<result[i]<<" ";
    }
}

// Question 9.2 : Intersection of Two Sorted Arrays!
#include<iostream>
#include<vector>
using namespace std;

vector<int> intersectionOfArrays(vector<int> v1, vector<int> v2) {
    int i = 0; int j = 0;
    vector<int> ans;
    while(i < v1.size() && j < v2.size()) {
        if(v1[i] == v2[j]) {
            if(ans.empty() || ans.back() != v1[i]) {
                ans.push_back(v1[i]);
            }
            i++; j++;
        }
        else if(v1[i] > v2[j]) {
            j++;
        }
        else {
            i++;
        }
    }
    return ans;
}

int main() {
    int n1, n2;
    cout << "Enter the size 1 : ";
    cin >> n1;
    cout << "Enter the size 2 : ";
    cin >> n2;

    vector<int> v1(n1), v2(n2);
    
    cout << "Enter array elements of array 1 : ";
    for(int i = 0; i < n1; i++) {
        cin >> v1[i];
    }
    
    cout << "Enter array elements of array 2 : ";
    for(int i = 0; i < n2; i++) {
        cin >> v2[i];
    }
    
    vector<int> res = intersectionOfArrays(v1, v2);
    
    cout << "Union of arrays: ";
    for(int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }
    return 0;
}

// Question 10 : Given an array nums containing n distinct numbers in the range [0, n], return the only number in the range that is missing from the array.
#include<iostream>
#include<vector>
using namespace std;

int missingNumber(vector<int> v) {
    for(int i = 1; i<=v.size(); i++) {
        bool flag = 0;
        for(int j = 0; j<v.size(); j++) {
            if(v[j] == i) {
                flag = 1;
                break;
            }
        }
        if(flag == 0) return i;
    }
    return -1;
}

int main() {
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i = 0; i<n; i++) {
        cin>>v[i];
    }
    cout<<missingNumber(v);
}

// Better Method : By storing frequency of each element! and the one with 0 frequency that is the missing element!
#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int missingNumber(vector<int> v) {
    int n = v.size();
    vector<bool> exist(n + 1, false);

    for(int i = 0; i<n; i++) {
        exist[v[i]] = true;
    }
    for(int i = 0; i<exist.size(); i++) {
        if(exist[i] == false) {
            return i;
        }
    }
    return -1;
}

int main() {
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i = 0; i<n; i++) {
        cin>>v[i];
    }
    cout<<missingNumber(v);
}

// Best Optimal Approach :
#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int missingNumber(vector<int> v) {
    int n = v.size();
    int actualSum = n*(n+1)/2;
    int vectorSum = 0;
    for(int i = 0; i<n; i++) {
        vectorSum += v[i];
    }
    return actualSum - vectorSum;
}

int main() {
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i = 0; i<n; i++) {
        cin>>v[i];
    }
    cout<<missingNumber(v);
}

// Question 11 : Given a binary array nums, return the maximum number of consecutive 1's in the array.
#include<iostream>
#include<vector>
using namespace std;

int consecOnes(vector<int> v) {
    int count1 = 0; int maxCount1 = 0;
    for(int i = 0; i<v.size(); i++) {
        if(v[i] == 1) {
            count1++;
            maxCount1 = max(count1, maxCount1);
        }
        else {
            count1 = 0;
        }
    }
    return maxCount1;
}

int main() {
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i = 0; i<n; i++) {
        cin>>v[i];
    }
    cout<<consecOnes(v);
}

// Question 12 : Given a non-empty array of integers nums, every element appears twice except for one. Find that single one. You must implement a solution with a linear runtime complexity and use only constant extra space.
#include<iostream>
#include<vector>
using namespace std;

int singleOne(vector<int> v) {
    int val = 0;
    for(int i = 0; i<v.size(); i++) {
        val = val ^ v[i];
    }
    return val;
}

int main() {
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i = 0; i<n; i++) {
        cin>>v[i];
    }
    cout<<singleOne(v);
} // TC : O(n) and SC : O(1)
// There are more approaches like : Using hashing using arrays, hashing using maps and brute force approach!

// Question 13 : A) Given an array and a sum k, we need to print the length of the longest subarray that sums to k! (Only +ve numbers)
//             : B) Given an array and a sum k, we need to print the length of the longest subarray that sums to k! (Both +ve/-ve numbers)
//             : C) Given an array and a sum k, we need to print the length of the longest subarray that sums <= k! (Only +ve numbers)
//             : D) Given an array and a sum k, we need to print the length of the longest subarray that sums <= k! (Both +ve/-ve numbers)
// A) Given an array and a sum k, we need to print the length of the longest subarray that sums to k! (Only +ve numbers)
// Approach (Brute Force) : Since the array consists of only positive numbers and zeros!
//                        : We can safely : Iterate through every possible subarray using a nested loop.
//                                        : Maintain a running sum (sum) while expanding the subarray.
//                                        : If sum < k, continue expanding (i.e., add next element).
//                                        : If sum == k, update the maxLen and continue to check for longer valid subarrays.
//                                        : If sum > k, no need to continue — break the inner loop, as the sum will only grow further with more positive numbers.
//                       : Important Edge Cases to Consider : Single Element Equal to k : e.g., arr = [1, 3, 7, 5, 5], k = 7 → subarray [7] must be considered valid. So subarrays of length 1 should not be ignored.
//                                                          : Zeros in the Array : Zero doesn't affect the sum, but it can increase the length of a subarray whose sum is already equal to k. For example: arr = [1, 1, 1, 1, 1, 1, 0], k = 3 → subarray [1, 1, 1, 0] has sum 3 and length 4.
//                       : Time Complexity : O(n^2) in the worst case, where n is the size of the array. Early termination using break helps optimize slightly when sum > k.
//                       : Even all other cases A, B, C & D, will give O(n^2) time complexity! So we need to optimize this solution!
#include<iostream>
#include<vector>
using namespace std;

int longestSubarrayA1(vector<int> v, int k) {
    int n = v.size();
    int maxLen = 0;
    for(int i = 0; i < n; i++) {
        int sum = 0;
        for(int j = i; j < n; j++) {
            sum += v[j];
            if(sum == k) {
                maxLen = max(maxLen, j - i + 1);
            }
            if(sum > k) {
                break;
            }
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

// Approach (Prefix Sum & Two Pointers) : To solve this efficiently, we use two main tools : Prefix Sum Array & Two Pointers (Sliding Window)
//                                      : Prefix Sum Array : pref[i] = sum of elements from v[0] to v[i-1].
//                                                         : Why is this useful? Because once we have the prefix sum array, we can quickly find the sum of any subarray v[s] to v[e-1] using : sum = pref[e] - pref[s]
//                                                         : This trick helps us avoid summing elements repeatedly. It reduces our time complexity.
//                                      : Two Pointers : We use two pointers s (start) and e (end) to slide through the prefix sum array and find a subarray with sum = k.
//                                                     : We initialize : s = 0, e = 0.
//                                                     : Then we run a loop : while (e < pref.size())
//                                                     : At each step, we calculate : diff = pref[e] - pref[s], Which is actually the sum of subarray v[s] to v[e-1].
//                                      : How the loop works : If diff == k, we’ve found a valid subarray. Update maxLen = max(maxLen, e - s) (as e-s is the length), and move e forward to find a possibly longer one.
//                                                           : If diff < k, the current subarray sum is too small. So we increase e to include more elements and increase the sum.
//                                                           : If diff > k, the subarray is too big. So we increase s to remove elements from the front and reduce the sum.
//                                                           : We continue this until e reaches the end.
//                                      : Why We Keep Prefix Sum Array of Size n + 1 and Initialize pref[0] = 0 : Let’s say you have an array : v = [1, 2, 3, 4]
//                                                                                                              : If you create a prefix sum array of same size n = 4, it would look like : pref = [1, 3, 6, 10].
//                                                                                                              : Now, the general idea behind prefix sums is that : The difference between two prefix sums gives us the sum of a subarray between the two corresponding positions.
//                                                                                                              : To get the sum of subarray from index 1 to 3 (i.e., [2, 3, 4]) : sum = pref[3] - pref[0] = 10 - 1 = 9 (Correct)
//                                                                                                              : That works fine because the difference gives : Includes the element at index 3, Excludes the element just before index 1 (i.e., at 0), So it correctly gives you the sum of v[1] + v[2] + v[3].
//                                                                                                              : Now let’s say you want the sum of subarray from index 0 to 3 (i.e., [1, 2, 3, 4]) : If you follow the same logic, you would try to do : sum = pref[3] - pref[-1] Invalid! Index -1 doesn't exist!
//                                                                                                              : So here the standard formula breaks when the subarray starts at index 0.
//                                      : The Fix : Extra 0 at the Start : To handle this case cleanly, we create a prefix sum array of size n + 1, and set : pref[0] = 0
//                                                : Then build the prefix sum as : pref[i + 1] = pref[i] + v[i]
//                                                : This gives us : v = [1,2,3,4]. prefsum = [0, 1, 3, 6, 10]
//                                                : To get the sum of subarray from l to r (inclusive) : sum = pref[r + 1] - pref[l]. This works perfectly even if l = 0, because pref[0] = 0 exists.
//                                      : Why does this subtraction logic work? : Because subtraction naturally behaves as : Include the upper bound & Exclude the lower bound.
#include<iostream>
#include<vector>
using namespace std;

int longestSubarrayA2(vector<int> v, int k) {
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
    cout<<longestSubarrayA2(arr, sum);
}

// Approach (Two Pointers) : Now here's the intuition : Since all elements are non-negative, the sum of a window increases when you add more elements (move right).
//                                                    : Similarly, the sum decreases when you remove elements from the front (move left).
//                                                    : So, we can apply the sliding window (two pointers) technique.
//                         : How it works : We maintain a window defined by two pointers : i (start of the window) & j (end of the window). We keep track of the sum of elements between i and j.
//                                        : At every step : Add v[j] to the current sum.
//                                                        : While the sum > k, shrink the window from the left by increasing i and subtracting v[i] from sum.
//                                                        : If sum == k, update maxLen to j - i + 1.
//                                                        : Move j forward to continue checking the next window. 
#include<iostream>
#include<vector>
using namespace std;

int longestSubarrayA3(vector<int> v, int k) {
    int i = 0; int j = 0;
    int sum = 0;
    int maxLen = 0;
    while(j < v.size()) {
        sum += v[j];
        while(sum > k) {
            sum -= v[i];
            i++;
        }
        if(sum == k) {
            maxLen = max(maxLen, j - i + 1);
            j++;
        }
        else {
            j++;
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
    cout<<longestSubarrayA3(arr, sum);
}

// B) Given an array and a sum k, we need to print the length of the longest subarray that sums to k! (Both +ve/-ve numbers)
// Approach (Brute Force) : The brute force idea remains similar to the approach used for arrays with only positive numbers.
//                        : For every possible starting index i, we calculate the subarray sum by expanding up to every j ≥ i
//                        : Whenever we find a subarray whose sum equals k, we update the maximum length.
//                        : However, the critical difference here is that we cannot break the inner loop early when sum > k — unlike in the positive-only case — because the presence of negative numbers means the sum can still decrease later.
//                        : Therefore, we must continue checking all possible subarrays starting from every index i.
#include<iostream>
#include<vector>
using namespace std;

int longestSubarrayB1(vector<int> v, int k) {
    int n = v.size();
    int maxLen = 0;
    for(int i = 0; i < n; i++) {
        int sum = 0;
        for(int j = i; j < n; j++) {
            sum += v[j];
            if(sum == k) {
                maxLen = max(maxLen, j - i + 1);
            }
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
    cout<<longestSubarrayB1(arr, sum);
}

// Approach (Prefix Sum + Hashing) : We use the concept of prefix sum to track the cumulative sum of elements as we move through the array.
//                                 : Let : sum = prefix sum till current index i.
//                                       : We want to check if there’s any earlier prefix sum such that : prev_sum = sum - k
//                                       : That means : The subarray from just after that earlier prefix to the current index i will have sum = k
//                                       : So we store all prefix sums with their first occurrence index in a map preSumMap.
//                                 : Works for : Only positive numbers, including zeroes. But with negatives, is where this approach shines! where other methods fails!
//                                 : Why Two Pointers Approach Fails for Negatives : Two pointers (sliding window) only works if elements are non-negative because, Increasing j increases sum & Increasing i reduces sum
//                                                                                 : But if negative numbers exist, the sum can increase/decrease unexpectedly. So you can't greedily slide the window — it will miss valid subarrays.
//                                 : This Prefix Sum + Map approach solves that : It doesn’t rely on window shrinking/expanding. It tracks all prefix sums and finds any previous sum such that : current_sum - previous_sum = k
//                                 : So it covers all valid subarrays, even when the array has Negative numbers, Zeros & Mixture of everything.
//                                 : TC : O(n * logn) & SC : O(n)
//                                 : This TC can be optimized if you use unordered_map, then the average case TC will become O(n) and worst case will have a risk of O(n^2).
#include<iostream>
#include<vector>
#include<map>
using namespace std;

int longestSubarrayB2(vector<int> v, int k) {
    int n = v.size();
    int maxLen = 0;
    int sum = 0;
    map<int, int> preSumMap;
    for(int i = 0; i < n; i++) {
        sum += v[i];
        if(sum == k) {
            maxLen = max(maxLen, i + 1);
        }
        int rem = sum - k;
        if(preSumMap.find(rem) != preSumMap.end()) {
            int len = i - preSumMap[rem];
            maxLen = max(maxLen, len);
        }
        if(preSumMap.find(sum) == preSumMap.end()) {
            preSumMap[sum] = i;
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
    cout<<longestSubarrayB2(arr, sum);
}

// C) Given an array and a sum k, we need to print the length of the longest subarray that sums <= k! (Only +ve numbers)
// Approach (Brute Force) : Since the array contains only positive numbers, the brute force logic is almost identical to the case where we check for subarrays with sum exactly equal to k.
//                        : The only change is that, instead of checking only sum == k, we now check for sum ≤ k.
//                        : For every subarray starting at index i, we extend it forward while updating the sum, and whenever the sum is less than or equal to k, we update the maximum length.
//                        : All other logic and conditions remain the same — including the early break when sum > k, since the sum can only increase in an array with only positive values.
#include<iostream>
#include<vector>
using namespace std;

int longestSubarrayC1(vector<int> v, int k) {
    int n = v.size();
    int maxLen = 0;
    for(int i = 0; i < n; i++) {
        int sum = 0;
        for(int j = i; j < n; j++) {
            sum += v[j];
            if(sum <= k) {
                maxLen = max(maxLen, j - i + 1);
            }
            if(sum > k) {
                break;
            }
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
    cout<<longestSubarrayC1(arr, sum);
}

// Approach (Sliding Window) : Use two pointers i and j to form a window.
//                           : Expand the window by adding v[j] to the sum.
//                           : If sum > k, shrink the window from the left (i++) until sum ≤ k.
//                           : If sum ≤ k, update max length of the valid window.
//                           : Move j to explore the next element.
#include<iostream>
#include<vector>
using namespace std;

int longestSubarrayC2(vector<int> v, int k) {
    int n = v.size();
    int maxLen = 0;
    int i = 0; int j = 0;
    int sum = 0;
    while(j < n) {
        sum += v[j];
        while(sum > k) {
            sum -= v[i];
            i++;
        }
        if(sum <= k) {
            maxLen = max(maxLen, j - i + 1);
            j++;
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
    cout<<longestSubarrayC2(arr, sum);
}

// Approach (Sliding Window - Little Optimisation) : We can slightly improve the basic sliding window approach by realizing one key point : Since the question only asks for the length of the longest subarray with sum ≤ k, we don’t need to check or shrink the window once we already found a longer valid one.
//                                                 : In the normal sliding window, we keep shrinking the window (using a while loop) every time the sum goes above k.
//                                                 : But here, once we find a valid subarray of some length (say maxLen), we don’t need to shrink the window below that size anymore — because smaller windows won’t help in increasing the max length.
//                                                 : So we avoid unnecessary shrinking, and in doing so, we can eliminate the inner while loop.
//                                                 : The earlier approach had a time complexity of O(2n) due to frequent shrinking (i++ in a loop). With this optimization, we bring the time complexity down to a clean O(n).
//                                                 : This trick only works when : You're asked for maximum length, not the actual subarrays. The array contains only positive integers (since shrinking guarantees sum reduces). If you're asked to find all valid subarrays, this won’t work — because it skips over many possibilities.
#include<iostream>
#include<vector>
using namespace std;

int longestSubarrayC3(vector<int> v, int k) {
    int n = v.size();
    int maxLen = 0;
    int i = 0; int j = 0;
    int sum = 0;
    while(j < n) {
        sum += v[j];
        if(sum > k) {
            sum -= v[i];
            i++;
        }
        if(sum <= k) {
            maxLen = max(maxLen, j - i + 1);
            j++;
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
    cout<<longestSubarrayC3(arr, sum);
}

// D) Given an array and a sum k, we need to print the length of the longest subarray that sums <= k! (Both +ve/-ve numbers)
// Approach (Brute Force) : Since the array may contain both positive and negative numbers (and possibly zeros), we cannot rely on early termination strategies.
//                        : The brute-force logic involves evaluating every possible subarray by fixing a starting index i and extending to all possible ending indices j ≥ i. For each subarray [i...j], we maintain a running sum.
//                        : If at any point the subarray sum is less than or equal to k, we consider it valid and update the maximum subarray length.
//                        : Unlike the case with only positive numbers, we must not break the inner loop even when sum > k, because future elements (being negative) may reduce the sum and still lead to a valid subarray later.
//                        : Thus, we explore all subarrays thoroughly to ensure correctness.
// Apprpach (Prefix Sum + Hashing) : We use, Prefix Sum (prefixSum) : To calculate sum of any subarray as (subarraySum = prefixSum[i] - prefixSum[j])
//                                 : Key Logic : To satisfy prefixSum[i] - prefixSum[j] <= k. Then, => prefixSum[j] >= prefixSum[i] - k
//                                 : Map (mp) : Key = prefix sum value & Value = first index where that prefix sum occurred
//                                 : C++ map.lower_bound() : Used to find the smallest prefix sum ≥ (prefixSum - k)
//                                 : Thought Process : At each index i : Keep calculating the cumulative prefixSum. We want to find any earlier prefix sum prefixSum[j] such that : prefixSum[j] >= prefixSum[i] - k (Which means the subarray (j+1 to i) has sum ≤ k.)
//                                                   : So we do : auto it = mp.lower_bound(prefixSum - k);
//                                                   : If we find such j, we calculate : maxLength = max(maxLength, i - j);
//                                                   : Then store the current prefixSum with index i in mp if it’s not already present (to retain earliest occurrence).
//                                 : mp[0] = -1; : Pretend prefix sum = 0 occurred before the array. & Helps detect subarrays starting from index 0.
//                                 : prefixSum += arr[i]; : Running prefix sum till current index.
//                                 : Time Complexity : O(n log n) (map operations)
//                                 : Space Complexity : O(n) (prefix sums stored)
// Approach 1 :
#include<iostream>
#include<vector>
using namespace std;

int longestSubarrayD1(vector<int> v, int k) {
    int n = v.size();
    int maxLen = 0;
    for(int i = 0; i < n; i++) {
        int sum = 0;
        for(int j = i; j < n; j++) {
            sum += v[j];
            if(sum <= k) {
                maxLen = max(maxLen, j - i + 1);
            }
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
    cout<<longestSubarrayD1(arr, sum);
}

// Approach 2 : 
#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int longestSubarrayD2(vector<int> v, int k) {
    int n = v.size();
    map<int, int> mp;
    int sum = 0, maxLen = 0;

    mp[0] = -1;
    for(int i = 0; i < n; i++) {
        sum += v[i];

        auto it = mp.lower_bound(sum - k);
        if(it != mp.end()) {
            int j = it->second;
            maxLen = max(maxLen, i - j);
        }

        if(mp.find(sum) == mp.end()) {
            mp[sum] = i;
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
    cout<<longestSubarrayD2(arr, sum);
}