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
// Thinking & Approach : Solution will be applied based on various factors, conditions & test cases like...
//                     : Conditions like : Both sorted! (contains duplicates or not)
//                                       : Both unsorted! (contains duplicates or not)
//                                       : One sorted & one unsorted! (contains duplicates or not)
//                     : Goals of a Good Solution : It should cover most of the common use-cases/test-cases!
//                                                : It should take less time!
//                                                : It should take less space!
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

// Question 13 : Given an array and a sum k, we need to print the length of the longest subarray that sums to k.
