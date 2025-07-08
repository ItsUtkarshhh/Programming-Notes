// --------------------------------------------------------- Part 1 : Binary Search Questions! ----------------------------------------------------------------->
// Question 1 : Finding a key in an array!
// Thinking : Approach 1 (Linear Search) : The linear search approach has a time complexity of O(n), as it may need to traverse the entire array to find the target element.
//          : Approach 2 (Binary Search) : In contrast, using binary search is a more efficient alternative for sorted arrays, as it reduces the time complexity to O(log n) by repeatedly dividing the search interval in half.
// Approach 2 :
#include<iostream>
#include<vector>
using namespace std;

int BinarySearch(vector<int> v, int key) {
    int start = 0;
    int end = v.size() - 1;
    int mid = start + (end - start)/2;
    while(start <= end) {
        if(key == arr[mid]) {
            return mid;
        }
        if(key > arr[mid]) {
            start = mid+1;
        }
        else {
            end = mid-1;
        }
        mid = start + (end - start)/2;
    }
    return -1;
}

int main() {
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i = 0; i < n; i++) {
        cin>>v[i];
    }
    int key;
    cin>>key;
    cout<<"Key is at index : "<<BinarySearch(v, key);
}

// Question 2 : Find the first and last position of an element in a sorted array!
// Thinking : Approach 1 (Linear Search) : The linear search approach has a time complexity of O(n), as it may need to traverse the entire array to find the first or last occurrence of the target element.
//          : Approach 2 (Binary Search) : In contrast, using binary search is a more efficient alternative for sorted arrays, as it reduces the time complexity to O(log n) by repeatedly dividing the search interval in half.
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int firstOccurence(vector<int> v, int key) {
    int start = 0;
    int end = v.size() - 1;
    int mid = start + (end - start)/2;
    int index = -1;
    while(start <= end) {
        if(key == v[mid]) {
            index = mid;
            end = mid - 1;
        }
        else if(key > v[mid]) {
            start = mid + 1;
        }
        else {
            end = mid - 1;
        }
        mid = start + (end - start)/2;
    }
    return index;
}

int lastOccurence(vector<int> v, int key) {
    int start = 0;
    int end = v.size() - 1;
    int mid = start + (end - start)/2;
    int index = -1;
    while(start <= end) {
        if(key == v[mid]) {
            index = mid;
            start = mid + 1;
        }
        else if(key > v[mid]) {
            start = mid + 1;
        }
        else {
            end = mid - 1;
        }
        mid = start + (end - start)/2;
    }
    return index;
}

int main() {
    int size;
    cin >> size;
    vector<int> v(size);
    
    for(int i = 0; i < size; i++) {
        cin >> v[i];
    }

    sort(v.begin(), v.end());

    int key;
    cin >> key;

    int first = firstOccurrence(v, key);
    int last = lastOccurrence(v, key);

    if (first != -1) {
        cout << "First occurrence at index: " << first << endl;
        cout << "Last occurrence at index: " << last << endl;
        cout << "Total occurrences: " << (last - first + 1) << endl;
    } else {
        cout << "Key not found!" << endl;
    }

    return 0;
}

// Question 3 : Find any one peak in a multiple mountains array!
// Problem Statment : You are given an array arr that is strictly increasing up to a certain index i, and then strictly decreasing after that. Find the index i — the peak index of the mountain array (any peak).
// Approach & Thinking : We can use binary search here! we will simply calculate the mid and check the right and left side of it! then will follow some conditions!
//                     : If arr[mid - 1] < arr[mid] > arr[mid + 1] : return mid (peak)
//                     : If arr[mid - 1] > arr[mid] > arr[mid + 1] : end = mid - 1 (negative slope)
//                     : If arr[mid - 1] < arr[mid] < arr[mid + 1] : start = mid + 1 (positive slope)
//                     : If arr[mid - 1] > arr[mid] < arr[mid + 1] : start = mid + 1 (valley condition)
//                     : If size == 0 : return -1
//                     : If size == 1 : return 0
//                     : If arr[0] > arr[1] : return 0
//                     : If arr[size - 2] < arr[size - 1] : return size - 1
//                     : Currently the solution below is not for handling duplicates, binary search method becomes complex to hamdle duplicates! If the array contains duplicates then the worst case time complexity becomes O(n) even for binary search!
#include<iostream>
#include<vector>
using namespace std;

int peak(vector<int> v) {
    if(v.size() == 0) return -1;
    if(v.size() == 1) return 0;
    if(v[0] > v[1]) return 0;
    if(v[v.size() - 2] < v[v.size() - 1]) return v.size() - 1;
    
    int start = 1;
    int end = v.size() - 2;
    int mid = start + (end - start)/2;

    while(start <= end) {
        if(v[mid - 1] < v[mid] && v[mid] > v[mid + 1]) {
            return mid;
        }
        else if(v[mid - 1] > v[mid] && v[mid] > v[mid + 1]) {
            end = mid - 1;
        }
        else if(v[mid - 1] < v[mid] && v[mid] < v[mid + 1]) {
            start = mid + 1;
        }
        else {
            start = mid + 1;
        }
        mid = start + (end - start)/2;
    }
    return -1;
}

int main() {
    int size;
    cin>>size;
    vector<int> v(size);
    for(int i = 0; i < size; i++) {
        cin>>v[i];
    }
    cout<<"Peak of the array : "<<peak(v);
}

// Question 4 : Find the pivot element!
//            : Pivot element can mean different things in different contexts! But we are going to deal with the rotated & sorted array context!
//            : Which says : The pivot element is the smallest element in a sorted and rotated array. It is the index where the rotation happened.
//                         : Some people consider largest element as pivot (before the array "breaks") & some smallest element as pivot (where the rotation happens)
// Approach & Thinking : We take advantage of the two sorted parts! As binary search can't be used in it full potential if the array is not sorted!
//                     : If arr[mid] >= arr[0] : This means you're in the first (left) sorted portion, so the pivot must lie on the right side. start = mid + 1
//                     : Else : You're in the second (right) sorted portion, possibly at or after the pivot. end = mid
//                     : We stop when start == end, because then the smallest (pivot) is found.
#include<iostream>
#include<vector>
using namespace std;

int pivot(vector<int> v) {
    int start = 0;
    int end = v.size() - 1;

    while(start < end) {
        int mid = start + (end - start)/2;
        if(v[mid] > v[0]) {
            start = mid + 1;
        }
        else {
            end = mid;
        }
    }
    return end; // Can also return start. As loop will end at start = end!
}

int main() {
    int size;
    cin>>size;
    vector<int> v(size);
    for(int i = 0; i < size; i++) {
        cin>>v[i];
    }
    int pivotIndex = pivot(v);
    cout<<"Pivot element of the array : "<<pivotIndex;
}

// Question 5 : Search a key in a rotated sorted array!
// Approach & Thinking : We use the concept of binary search, but with a twist — since the array is rotated, it is not fully sorted, but instead split into two sorted parts.
//                     : Find the Pivot Element : The pivot is the index of the smallest element (i.e., the rotation point). and it splits the array into two sorted subarrays.
//                     : Determine Where to Search : Based on the pivot and the target key, decide in which sorted half the key may lie.
//                     : Apply Binary Search : Use regular binary search on the chosen subarray to find the key.
#include<iostream>
#include<vector>
using namespace std;

int pivot(vector<int> v) {
    int start = 0;
    int end = v.size() - 1;

    while(start < end) {
        int mid = start + (end - start)/2;
        if(v[mid] > v[0]) {
            start = mid + 1;
        }
        else {
            end = mid;
        }
    }
    return end;
}

int BinarySearch(vector<int> v, int start, int end, int key) {
    while(start <= end) {
        int mid = start + (end - start)/2;
        if(key == v[mid]) {
            return mid;
        }
        if(key > v[mid]) {
            start = mid+1;
        }
        else {
            end = mid-1;
        }
    }
    return -1;
}

int findKeyBS(vector<int> v, int key) {
    int pivotIndex = pivot(v);
    int n = v.size();
    if(key >= v[pivotIndex] && key <= v[n - 1]) {
        return BinarySearch(v, pivotIndex, n - 1, key);
    }
    else {
        return BinarySearch(v, 0, pivotIndex - 1, key);
    }
}

int main() {
    int size;
    cin>>size;
    vector<int> v(size);
    for(int i = 0; i < size; i++) {
        cin>>v[i];
    }
    int key;
    cin>>key;
    int keyIndex = findKeyBS(v, key);
    cout<<"Position of the key in array : "<<keyIndex;
}

// Question 6 : Finding Square root using Binary Search!
// Thinking & Approach : We are looking for the square root of a number X (Lets say 36). Hence, the search space is from 0 to x, so the range is [0, x].
//                     : Binary Search Process : Set the start pointer to 0 and the end pointer to X.
//                                             : Calculate mid = (start + end) / 2.
//                                             : Check if mid * mid == x : If yes, return mid as the square root.
//                                             : If mid * mid > x, it means we need to search for smaller numbers, so we set end = mid - 1.
//                                             : If mid * mid < x, it means we need to search for larger numbers, so we save mid as the potential answer and set start = mid + 1.
//                                             : Repeat these steps until start exceeds end.
//                     : Final Answer : The largest value of mid that satisfies mid * mid < x will be saved in ans.
#include<iostream>
using namespace std;

int squareRoot(int n) {
    int start = 0;
    int end = n;
    int ans = 0;
    while(start <= end) {
        int mid = start + (end - start)/2;
        int square = mid*mid;
        if(square == n) {
            return mid;
        }
        if(square < n) {
            ans = mid;
            start = mid + 1;
        }
        else {
            end = mid - 1;
        }
    }
    return ans;
}

int main() {
    int n;
    cin>>n;
    int sqrt = squareRoot(n);    
    cout<<sqrt;
}

// Upgrading value using the long & long long data types!
#include<iostream>
using namespace std;

int squareRoot(int n) {
    int start = 0;
    int end = n;
    int ans = 0;
    while(start <= end) {
        int mid = start + (end - start)/2;
        long long int square = mid * mid;
        if(square == n) {
            return mid;
        }
        if(square < n) {
            ans = mid;
            start = mid + 1;
        }
        else {
            end = mid - 1;
        }
    }
    return ans;
}

int main() {
    int n;
    cin>>n;
    int sqrt = squareRoot(n);    
    cout<<sqrt;
}

// Question 6.2 : Finding Square root using Binary Search with decimals!
// Thinking & Thought process : Start with the integer part found in step 1.
//                            : Use a small factor (0.1, 0.01, ...) to refine the answer. And keep adding the factor to the current answer as long as (ans + factor)² <= n.
//                            : Repeat this for the number of digits of precision needed.
//                            : This helps us accurately reach closer to the real square root, digit by digit.
#include<iostream>
using namespace std;

int squareRoot(int n) {
    int start = 0;
    int end = n;
    int ans = 0;
    while(start <= end) {
        int mid = start + (end - start)/2;
        long long int square = mid * mid;
        if(square == n) {
            return mid;
        }
        if(square < n) {
            ans = mid;
            start = mid + 1;
        }
        else {
            end = mid - 1;
        }
    }
    return ans;
}

double squareRootAcc(int n, int precision) {
    int IntegerVal = squareRoot(n);

    double factor = 1.0;
    double ans = IntegerVal;
    for(int i = 0; i < precision; i++) {
        factor = factor / 10;
        for(double root = ans; root * root < n; root = root + factor) {
            ans = root;
        }
    }
    return ans;
}

int main() {
    int n;
    cin>>n;
    int precision;
    cin>>precision;
    double sqrt = squareRootAcc(n, precision);    
    cout<<sqrt;
}