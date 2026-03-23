// --------------------------------------------------------- Part 1 : Arrays Based Questions! ----------------------------------------------------------------->
// Question 1 : Finding maximum/minimum elements in an Array!
// Thinking : First, take input and store elements in the array. To find the maximum, initialize a variable with the smallest possible value (INT_MIN).Iterate over the array and update this variable whenever you find a larger value.
//          : By the end, this variable will hold the maximum value in the array.
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
    int max = INT_MIN;
    for(int i = 0; i < n; i++) {
        if(max < arr[i]) {
            max = arr[i];
        }
    }
    cout<<"Max value in the array : "<<max;
}

// Little Optimizations : Instead of using a separate loop, update the maximum while taking input using max() function. This reduces the need for an additional loop and makes the code more efficient.
// ChatGPT Remarks : The optimization is correct and slightly better in practice, but the performance benefit is minimal. It's mainly a style and readability choice unless you’re dealing with massive datasets.
#include<iostream>
#include<climits>
using namespace std;

int main() {
    int n;
    cin>>n;
    int* arr = new int[n];
    int maxi = INT_MIN;
    for(int i = 0; i<n; i++) {
        cin>>arr[i];
        maxi = max(maxi, arr[i]); // Also we can use simple if condition!
    }
    cout<<"Max value in the array : "<<maxi;
}

// For minimum value!
#include<iostream>
#include<climits>
using namespace std;

int main() {
    int n;
    cin>>n;
    int* arr = new int[n];
    int mini = INT_MAX;
    for(int i = 0; i<n; i++) {
        cin>>arr[i];
        mini = min(mini, arr[i]);
    }
    cout<<"Max value in the array : "<<mini;
}

// Not Recommended method, but just for exploring various methods : TC : O(n logn)
#include<iostream>
#include<vector>
#include<set>
using namespace std;

int maxVal(vector<int> v) {
    set<int> st;
    int maxi = INT_MIN;
    
    for(int i : v) {
        st.insert(i);
    }
    
    return *--st.end();
}

int main() {
    int n;
    cin>>n;
    vector<int> v1(n);

    for(int i = 0; i < n; i++) {
        cin>>v1[i];
    }

    cout<<"Maximum value of array : "<<maxVal(v1);
}

// Question 2 : Find the sum of all of its elements!
// Thinking : First, take input and store elements in the array. then initiate a sum variable with 0, and iterate over the array and add each element into this sum till the end of array! and then finally print sum!
#include<iostream>
using namespace std;

int main() {
    int n;
    cin>>n;
    int* arr = new int[n];
    int sum = 0;
    for(int i = 0; i<n; i++) {
        cin>>arr[i];
        sum += arr[i];
    }
    cout<<"Sum of all elements in the array : "<<sum;
}

// Another method (not recommended, but just for exploring other methods) :
#include<iostream>
#include<vector>
#include<map>
using namespace std;

int sumOfAll(vector<int> v) {
    map<int, int> mp;
    for(int i = 0; i < v.size(); i++) {
        mp[v[i]]++;
    }

    int sum = 0;
    for(auto i : mp) {
        sum += i.first * i.second;
    }

    return sum;
}

int main() {
    int n;
    cin>>n;
    vector<int> v(n);

    for(int i = 0; i < n; i++) {
        cin>>v[i];
    }

    cout<<"Sum of all elements : "<<sumOfAll(v);
}

// Question 3 : Linear Search in an array! and return the index of the key!
// Thinking : Linear search is the method where we iterate each element of the array to find the key and once we find the element then we simply return its index!
#include<iostream>
using namespace std;

void findKeyLS(int* arr, int n, int key) {
    for(int i = 0; i<n; i++) {
        if(arr[i] == key) {
            cout<<"Key is at "<<i<<" index!";
            return;
        }
    }
    cout<<"Key "<<key<<" not found!";
    return;
}

int main() {
    int n;
    cin>>n;
    int* arr = new int[n];
    for(int i = 0; i<n; i++) {
        cin>>arr[i];
    }
    int key;
    cin>>key;
    findKeyLS(arr, n, key);
}

// Exploring other methods :
// Method 1 : Using sets
#include<iostream>
#include<vector>
#include<set>
using namespace std;

bool findKeyLS2(vector<int> v, int key) {
    set<int> st;
    for(int i = 0; i < v.size(); i++) {
        st.insert(v[i]);
    }

    return st.count(key);
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

    cout<<"Does this element exist ? : "<<findKeyLS2(v, key);
}

// Method 2 : Using maps
#include<iostream>
#include<vector>
#include<map>
using namespace std;

int findKeyLS3(vector<int> v, int key) {
    map<int, int> mp;
    for(int i = 0; i < v.size(); i++) {
        if(!mp.count(v[i])) {
            mp[v[i]] = i;
        }
    }
    if(!mp.count(key)) return -1;
    return mp[key];
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

    cout<<"Index of the key (if exist) : "<<findKeyLS3(v, key);
}

// Question 4: Reverse an Array
// Thinking : Use two pointers : one at the start (i = 0) and one at the end (j = n-1). Swap the elements at these positions, then increment i and decrement j. Repeat until i >= j. This will reverse the array in-place.
//                             : You can either : Use a void function and pass the array by reference (it modifies the original array). Or return the array pointer (int*) if needed for further use.
#include<iostream>
using namespace std;

int* reverseArray(int* arr, int n) {
    int i = 0; int j = n-1;
    while(i < j) {
        swap(arr[i], arr[j]);
        i++;
        j--;
    }
    return arr;
}

int main() {
    int n;
    cin>>n;
    int* arr = new int[n];
    for(int i = 0; i<n; i++) {
        cin>>arr[i];
    }
    int *ans = reverseArray(arr, n); // By the way in this case we dont need to store the output, as it is pass by reference, the array is already got reversed in that case! Its just formality of probably can be helpful in some other usecases! but atleast not here!
    for(int i = 0; i<n; i++) {
        cout<<ans[i]<<" ";
    }
}

// Question 5 : Swap Alternatively in an Array!
// Thinking : Here we are asked to swap alternatively! so we will just iterate and swap the first element and next element and then normally we move i++, but to swap alternatively we will move the iterator "i + 2", but while doing this we need to keep in mind that this iterator should not go out of bounds, so we need to add a check for that too at every iteration!
#include<iostream>
using namespace std;

void swapAlternatively(int* arr, int n) {
    for(int i = 0; i<n; i = i+2) {
        if(i + 1 < n) {
            swap(arr[i], arr[i+1]);
        }
    }
}

int main() {
    int n;
    cin>>n;
    int* arr = new int[n];
    for(int i = 0; i<n; i++) {
        cin>>arr[i];
    }
    swapAlternatively(arr, n);
    for(int i = 0; i<n; i++) {
        cout<<arr[i]<<" ";
    }
}

// Question 6 : Check whether an array contains any unique element or not! and print that unique element!
// Thinking : First, find the maximum value in the original array, so we know the size needed for the countingArray (size = maxValue + 1 due to 0-based indexing).
//          : Create a countingArray where each index represents a value from the original array. Traverse the original array and increment the count at the corresponding index in the countingArray.
//          : After that, check which index has a count of 1 — that index (value) is the unique element. If no such count is found, then no unique element exists.
#include<iostream>
#include<climits>
using namespace std;

int main() {
    int n;
    cin>>n;
    int* arr = new int[n];
    int maxVal = INT_MIN;
    for(int i = 0; i<n; i++) {
        cin>>arr[i];
        maxVal = max(maxVal, arr[i]);
    }

    int* countArr = new int[maxVal + 1]();
    for(int i = 0; i<n; i++) {
        countArr[arr[i]]++;
    }
    int found = false;
    for(int i = 0; i <= maxVal; i++) {
        if(countArr[i] == 1) {
            cout<<"One unique element found : "<<i;
            found = true;
            break;
        }
    }
    if(found == false) {
        cout<<"No unique element found!";
    }
    delete[] arr;
    delete[] countArr;
}
// Drawbacks : This method is fine! but there are few drawbacks : Firstly, this method is only for natural numbers!
//                                                              : Secondly, this method is taking a lot of unneccessary space for even those element who does not exist in the original array!

// Optimized approach : Using of Hashmap!
// Thinking : This approach saves space by only storing counts for elements present.
//          : This will solve two major problems : This approach saves space by only storing counts for elements present. It also handles negative numbers and any range of values without extra memory overhead.
#include<iostream>
#include<map>
using namespace std;

int main() {
    int n;
    cin>>n;
    int* arr = new int[n];
    map<int, int> count;
    for(int i = 0; i<n; i++) {
        cin>>arr[i];
        count[arr[i]]++;
    }
    for(auto it : count) {
        cout<<it.first<<" has "<<it.second<<" occurence in the array!"<<endl;
    }
    cout<<endl;
    int countUnique = 0;
    for(auto it : count) {
        if(it.second == 1) {
            cout<<it.first<<" is the unique element of the array!"<<endl;
            countUnique++;
        }
    }
    cout<<"The array had total of "<<countUnique<<" unique elements!";
}

// Question 7 : Check whether an array contains 1 unique element or not, and print that unique element! or contains any odd duplicates (focus on 1 unique element)
// Thinking : In this question, we are given a special condition, the array either has one element that appears only once (unique), or one element that appears an odd number of times.
//          : We can solve this using our earlier brute-force method (using frequency counting), which takes O(n) time and space — and it’s totally valid. But here, we can apply a smarter approach based on the XOR operation because of the given condition.
//          : That is, We know how XOR works : XOR of two same numbers is 0 → a ^ a = 0 and XOR of any number with 0 is the number itself → 0 ^ a = a.
//                                           : So, if we XOR all elements in the array : All elements that occur an even number of times will cancel out to 0. If one element is unique or has an odd count, it will remain in the result.
//                                           : So by the end of the XOR process, we’ll be left with the required number, which is either : the unique element, or the element that occurred an odd number of times.
#include<iostream>
using namespace std;

int main() {
    int n;
    cin>>n;
    int* arr = new int[n];
    for(int i = 0; i<n; i++) {
        cin>>arr[i];
    }
    // Doing XOR of all elements with each other!
    int unique = 0;
    for(int i = 0; i<n; i++) {
        unique = unique ^ arr[i];
    }
    cout<<"Unique number is : "<<unique<<endl;
    delete[] arr;
}

// Question 8 : You are given an array, and it contains each element between 1 -> n-1 at least once, there is a single integer value that present in the array twice, Your task is to find the duplicate value integer value present in the array! (2 methods)
// Thinking : Now, this question is reversed of unique element questions, here we need to find the duplicate element in the array! We can use a basic brute-force method where we count the frequency of each element. If any number appears twice (i.e., count == 2), that’s our answer. However, this takes extra space — O(n) — for storing counts.
//          : But, we are also given a condition, We're told the numbers range from 1 to n-1. This is a key hint for an optimized solution using XOR. XOR Properties : x ^ x = 0 (XOR of two same numbers is 0), x ^ 0 = x (XOR with 0 gives the number itself)
//          : Logic : First, take XOR of all elements in the array. Let’s call it xorAll. Then, take XOR of all numbers from 1 to n-1. Call this xorRange. Now do: xorAll ^ xorRange. All the elements from 1 to n-1 cancel out, and you're left with the duplicate number.
//          : This approach is efficient with : Time Complexity: O(n) Space Complexity: O(1)
//          : Example : arr = [1,2,3,4,5,6,6,7], XORall = 1^2^3^4^5^6^6^7 and then iterating again from 1 to n-1, and doing the XOR of all those values with already stored one! ans = 1^2^3^4^5^6^6^7^1^2^3^4^5^6^7 = 6 (duplicate element)
#include<iostream>
using namespace std;

int main() {
    int n;
    cin>>n;
    int* arr = new int[n];
    for(int i = 0; i<n; i++) {
        cin>>arr[i];
    }
    int XORall = 0;
    for(int i = 0; i < n; i++) {
        XORall = XORall ^ arr[i];
    }
    for(int i = 1; i <= n-1; i++) {
        XORall = XORall ^ i;
    }
    cout<<"Only Duplicate element is : "<<XORall<<endl;
}

// Question 9 : Find intersection of two arrays!
// Pre-Thinking : Here we need to first consider some cases like : Case 1 : Both arrays are unsorted
//                                                               : Case 2 : Both arrays are sorted
//                                                               : Case 3 : One array is unsorted, the other is sorted — unsorted is the main reference
//                                                               : Case 4 : One array is unsorted, the other is sorted — sorted is the main reference
// Hence, there are multiple approaches to solve this based on different cases!
// Approach 1 : Basic Brute Force : Works for : All cases!
//                                : First we are asked about to find the intersection of two arrays! means we need to find the common of all elements from both arrays! like if arr1 = {1,2,3,3,4,5} and arr2 = {6,4,1,3,5,4} we need ans = {1,3,4,5}
//                                : Idea : For each element in arr1, check if it exists in arr2. If found, store it in the result and mark the matched element in arr2 (e.g., as INT_MIN) so it won’t match again (helps handle duplicates correctly). This ensures each element from one array is only counted once in the intersection, even if duplicates are present.
//                                : Time : O(n^2) — due to nested loops (for each element in arr1, we may traverse arr2). Space: O(n) — to store the intersection results (in worst case if all are common).
// Approach 2 : Optimized Brute Force 1 : Works for : Case 2 and Case 3!
//                                      : Idea : Its mostly same like the basic brute force! suppose that you have two arrays and one is unsorted (call it arr1) and one is sorted (call it arr2), Take each element from the first array (arr1).Compare it with each element of the second array (arr2), which is sorted.
//                                             : Use this sorted nature to skip unnecessary checks : If element < arr2[j] → break early because no match will be found afterward. and If element == arr2[j] → element is common, add to answer and mark arr2[j] = INT_MIN to avoid duplicates.
//                                             : Repeat for all elements in arr1.
//                                      : This approach is just slightly better than the basic brute force, but with that it comes with some restrictions that it works for only Case 2 and 3!
// Approach 3 : Best Optimized Brute Force Approach : Works for : Case 2 only!
//                                                  : Idea : As both the arrays are sorted, Use the Two Pointers Technique
//                                                         : Initialize two pointers : i = 0 for arr1 and j = 0 for arr2. While both pointers are within bounds : If arr1[i] < arr2[j] → move pointer i ahead. If arr1[i] > arr2[j] → move pointer j ahead.
//                                                                                   : If arr1[i] == arr2[j] → it's a common element : Add it to the result. Move both pointers forward.
//                                                         : This approach works because arrays are sorted, so we never miss any element and always move forward smartly.
//                                                  : This approach is best brute force, but with that it comes with some restrictions that it works for only for Case 2 also it provides way better time complexity O(n) and space complexity O(1)
// Approach 4 : Smart Approach (Using Hashmaps/Unordered_maps) : Work for : All cases!
//                                                             : Idea : First, store all the elements of one array as keys in a hashmap, along with their frequencies as values. Then, traverse the second array and for each element, check if it exists in the map and its frequency is greater than 0.
//                                                                    : If so, add that element to the result array and decrease its frequency in the map by 1. This way, we only traverse each array once, significantly reducing the time complexity. To optimize space, always create the map using the smaller array.
//                                                             : This is best general approach for all cases! even with better time complexity of O(n) and slightly higher space complexity of O(n), but even that can be minimized using smaller array to store elements in the map! Apart from this you can use unordered maps to reduce the time complexity to O(1) in best and average cases and worst case will be O(n).
// Approach 5 : Smart Approach 2 (Using sets) : Works for : When both the arrays contain only unique elements and no duplicate ones! And useful for all the cases mentioned above, just its efficiency varies based upon cases!
//                                            : Idea : Sets store unique elements. Sets support fast lookup and insertion (average time O(1) for unordered_set, O(log n) for set).
//                                                   : Hence, we can Store all elements of one array in a set. Traverse the second array and for each element : If it's present in the set → it's part of the intersection. Optional : Then remove it from the set (to handle duplicates properly).
//                                            : Hence this approach also is good within the uniqueness condition! and for all the cases!
// Final Note : All the approaches are valid for there specific cases and there efficiencies varies based upon the cases and conditions!
// Approach 1 : Implementation!
//            : Conditions : None!
#include<iostream>
#include<vector>
#include<climits>
using namespace std;

vector<int> intersectionOfArrays1(vector<int> v1, vector<int> v2) {
    vector<int> ans;
    for(int i = 0; i<v1.size(); i++) {
        for(int j = 0; j<v2.size(); j++) {
            if(v1[i] == v2[j]) {
                ans.push_back(v1[i]);
                v2[j] = INT_MIN;
                break;
            }
        }
    }
    return ans;
}

int main() {
    int n1, n2;
    cin>>n1>>n2;
    vector<int> v1(n1);
    vector<int> v2(n2);
    for(int i = 0; i<n1; i++) {
        cin>>v1[i];
    }
    for(int i = 0; i<n2; i++) {
        cin>>v2[i];
    }
    vector<int> ans = intersectionOfArrays1(v1, v2);
    for(int i = 0; i<ans.size(); i++) {
        cout<<ans[i]<<" ";
    }
}

// Note : We can put this logic into one single loop! So for that we can see that, we are using the arr1's loop as the guide or dictator (or wtvr the right word for it is) to traverse over the inner loop to compare the elements of the inner loop!
//      : Hence, the whole camparison is primarily depends on arr1's outer loop! hence, we can simply iterate over the arr1 and compare elements in the other array without adding it in the condition of iteration or loop!
//      : But it won't affect the time complexity it's just another way of doing the same thing! just that how you can try to think differently and play with it!
#include<iostream>
#include<vector>
#include<climits>
using namespace std;

vector<int> intersectionOfArrays2(vector<int> v1, vector<int> v2) {
    vector<int> ans;
    int i = 0; int j = 0;
    while(i < v1.size()) {
        if(v1[i] == v2[j]) {
            ans.push_back(v1[i]);
            v2[j] = INT_MIN;
            i++; j = 0;
        }
        else if(v1[i] != v2[j] && j < v2.size()) {
            j++;
        }
        else {
            i++; j = 0;
        }
    }
    return ans;
}

int main() {
    int n1, n2;
    cin>>n1>>n2;
    vector<int> v1(n1);
    vector<int> v2(n2);
    for(int i = 0; i<n1; i++) {
        cin>>v1[i];
    }
    for(int i = 0; i<n2; i++) {
        cin>>v2[i];
    }
    vector<int> ans = intersectionOfArrays2(v1, v2);
    for(int i = 0; i<ans.size(); i++) {
        cout<<ans[i]<<" ";
    }
}

// Approach 2 : Implementation!
//            : Conditions : Works for Case 2 and Case 3! and can have duplicates!
#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
using namespace std;

vector<int> intersectionOfArrays3(vector<int> v1, vector<int> v2) {
    sort(v2.begin(), v2.end());
    vector<int> intersect;
    for(int i = 0; i < v1.size(); i++) {
        int j = 0;
        while(j < v2.size()) {
            if(v1[i] == v2[j]) {
                intersect.push_back(v2[j]);
                v2[j] = INT_MIN;
                break;
            }
            else if(v1[i] > v2[j]) {
                j++;
            }
            else {
                break;
            }
        }
    }
    return intersect;
}

int main() {
    int n1, n2;
    cin>>n1>>n2;
    vector<int> v1(n1);
    vector<int> v2(n2);
    for(int i = 0; i<n1; i++) {
        cin>>v1[i];
    }
    for(int i = 0; i<n2; i++) {
        cin>>v2[i];
    }
    vector<int> ans = intersectionOfArrays3(v1, v2);
    for(int i = 0; i<ans.size(); i++) {
        cout<<ans[i]<<" ";
    }
}

// Approach 3 : Implementation!
//            : Conditions : Works for Case 2 only! and unique and duplicates both are eligible!
#include<iostream>
#include<vector>
#include<climits>
using namespace std;

vector<int> intersectionOfArrays4(vector<int> v1, vector<int> v2) {
    sort(v2.begin(), v2.end());
    sort(v1.begin(), v1.end());
    
    vector<int> intersect;
    bool commonPresent = false;

    int i = 0; int j = 0;
    while(i < v1.size() && j < v2.size()) {
        if(v1[i] == v2[j]) {
            commonPresent = true;
            intersect.push_back(v2[j]);
            i++; j++;
        }
        else if(v1[i] > v2[j]) {
            j++;
        }
        else {
            i++;
        }
    }
    if(commonPresent) {
        return intersect;
    }
    else {
        intersect.push_back(-1);
        return intersect;
    }
}

int main() {
    int n1, n2;
    cin>>n1>>n2;
    vector<int> v1(n1);
    vector<int> v2(n2);
    for(int i = 0; i<n1; i++) {
        cin>>v1[i];
    }
    for(int i = 0; i<n2; i++) {
        cin>>v2[i];
    }
    vector<int> ans = intersectionOfArrays4(v1, v2);
    for(int i = 0; i<ans.size(); i++) {
        cout<<ans[i]<<" ";
    }
}

// Approach 4 : Using Hashmaps/Unordered_maps!
//            : Conditions : Works for, all the cases and unique and duplicates both areas also!
#include<iostream>
#include<map>
#include<vector>
using namespace std;

vector<int> intersectionOfArrays5(vector<int> v1, vector<int> v2) {
    vector<int> ans;
    map<int, int> count;
    for(int i = 0; i<v1.size(); i++) {
        count[v1[i]]++;
    }
    for(int i = 0; i<v2.size(); i++) {
        if(count[v2[i]] > 0) {
            ans.push_back(v2[i]);
            count[v2[i]]--;
        }
    }
    return ans;
}

int main() {
    int n1, n2;
    cin>>n1>>n2;
    vector<int> v1(n1);
    vector<int> v2(n2);
    for(int i = 0; i<n1; i++) {
        cin>>v1[i];
    }
    for(int i = 0; i<n2; i++) {
        cin>>v2[i];
    }
    if(v1.size() <= v2.size()) {
        vector<int> ans = intersectionOfArrays5(v1, v2);
        for(int i = 0; i < ans.size(); i++) {
            cout<<ans[i]<<" ";
        }
    }
    else {
        vector<int> ans = intersectionOfArrays5(v2, v1);
        for(int i = 0; i < ans.size(); i++) {
            cout<<ans[i]<<" ";
        }
    }
}

// Approach 5 : Using sets!
//            : Conditions : Works for, all cases but only unique elements in both arrays!
#include<iostream>
#include<vector>
#include<set>
using namespace std;

vector<int> intersectionOfArrays6(vector<int> v1, vector<int> v2) {
    set<int> setV1(v1.begin(), v1.end());
    vector<int> ans;
    bool commonPresent = false;
    for(int x : v2) {
        if(setV1.count(x)) {
            ans.push_back(x);
            commonPresent = true;
            setV1.erase(x);
        }
    }
    if(commonPresent) {
        return ans;
    }
    else {
        ans.push_back(-1);
        return ans;
    }
}

int main() {
    int n1, n2;
    cin>>n1>>n2;
    vector<int> v1(n1);
    vector<int> v2(n2);
    for(int i = 0; i<n1; i++) {
        cin>>v1[i];
    }
    for(int i = 0; i<n2; i++) {
        cin>>v2[i];
    }
    if(v1.size() <= v2.size()) {
        vector<int> ans = intersectionOfArrays6(v1, v2);
        for(int i = 0; i < ans.size(); i++) {
            cout<<ans[i]<<" ";
        }
    }
    else {
        vector<int> ans = intersectionOfArrays6(v2, v1);
        for(int i = 0; i < ans.size(); i++) {
            cout<<ans[i]<<" ";
        }
    }
}

// Approach 6 : Using Maps - Exclusively for : Both arrays unsorted & no duplicates!
//            : Simply store the count of each element in both the arrays into the map, and keep adding those elements into the final array, who count in the map is 2.
#include<iostream>
#include<map>
#include<vector>
using namespace std;

vector<int> intersectionOfArrays7(vector<int> v1, vector<int> v2) {
    map<int, int> occurence;
    vector<int> ans;
    for(int i = 0; i < v1.size(); i++) {
        occurence[v1[i]]++;
    }
    
    for(int i = 0; i < v2.size(); i++) {
        occurence[v2[i]]++;
    }
    
    for(auto i : occurence) {
        if(i.second == 2) {
            ans.push_back(i.first);
        }
    }
    
    return ans;
}

int main() {
    int n1, n2;
    cin>>n1>>n2;
    vector<int> v1(n1);
    vector<int> v2(n2);
    for(int i = 0; i<n1; i++) {
        cin>>v1[i];
    }
    for(int i = 0; i<n2; i++) {
        cin>>v2[i];
    }
    vector<int> ans = intersectionOfArrays7(v1, v2);
    for(int i = 0; i<ans.size(); i++) {
        cout<<ans[i]<<" ";
    }
}

// Question 10 : Find all pairs of elements in an array such that the sum of each pair equals a given value S. The pairs should satisfy the following conditions :
//             : 1) Each pair should be sorted in ascending order.
//             : 2) The list of pairs should be sorted primarily by the first value of the pairs, and if two pairs have the same first value, they should be sorted by the second value.
//             : 3) Each unique valid pair should appear only once, even if duplicates exist in the array. For example, if S = 4 and the array is {2, 2}, the output should include the pair {2, 2} only once.
// Output Expected : The best expected output could when the we get all the unique pairs, but also with optimized time and space complexity!
// Thinking : We can think of multiple ways to solve this problem depending on the conditions and situation.
//          : Approach 1 : Brute force approach : First, we will create a 2D vector (or a vector of pairs) to store the result. Then we will run two nested loops to check all possible pairs in the array. For each pair, we will check if the sum is equal to the given value S.
//                                              : If the sum matches, we will : Store that pair in the result, But before storing, we will sort the pair in ascending order, like (min, max).
//                                              : After collecting all the valid pairs, we will sort the final 2D vector : First by the first element of each pair. If the first elements are the same, then by the second element.
//                                              : This approach will work in any case : Whether the array is sorted or unsorted or whether it has duplicate values or unique values. No extra data structures are required in this brute force method.
//                                              : It will even contain duplicate pairs too! So we need to optimize it in further attempts!
//                       : Time complexity : Checking all pairs → O(n²) and Sorting the result → O(k log k) (where k = number of valid pairs)
//                       : Space complexity : Space Complexity : O(k) for storing the result pairs.
//          : Approach 2 : Brute force optimized using sets : In this, approach first we need to know how sets actually work! and what are those features of sets we need to use to get to our solution as per this approach!
//                                                          : We need to use, Use a set<pair<int, int>> instead of vector<vector<int>>. Reason being, Set automatically removes duplicates, Set maintains sorted order by default (by first element, then second) and We can directly insert (min(a, b), max(a, b)) into the set without needing manual sorting later.
//                                                          : Step wise approach : Create a set<pair<int, int>> to store unique valid pairs.
//                                                                               : Use two nested loops (just like brute force).
//                                                                               : For each pair (i, j) such that arr[i] + arr[j] == sum : Insert min(arr[i], arr[j]), max(arr[i], arr[j]) into the set.
//                                                                               : Convert the final set into a 2D vector to match the required output format.
//                                                          : Time complexity : Looping: O(n²), Inserting into set: O(log k) per insert (where k = number of unique pairs) Total = O(n² log k) in worst case
//                                                          : Space Complexity: O(k), where k = number of unique valid pairs
//                                                          : Note : The log factor comes due to balanced BST structure of std::set.
//          : Approach 3 : Optimized Approach (Using maps) : In this optimized approach, we take advantage of a hash map to quickly check for the presence of required elements and a set to store unique pairs.
//                                                         : Main Idea : We traverse the array once to store the occurrence of each number in a map (can be a count or simply a bool). Then, we iterate again and for each number x, we check whether sum - x also exists in the map.
//                                                                     : If it does, we form a valid pair and insert it into a set (to automatically handle uniqueness). We also mark both numbers as used (e.g., set their map values to false) so we don’t process the same pair again in reverse (like (3, 7) and (7, 3)).
//                                                         : Process : Store Element Presence : Traverse the array and insert each element into a map with a bool flag or count to track its availability.
//                                                                                            : Iterate through the array again : For each element x, compute its complement y = S - x.
//                                                                                                                              : If x == y, make sure there are at least 2 occurrences of x (i.e., {2, 2} with sum 4).
//                                                                                                                              : If x != y, check if both exist in the map.
//                                                                                                                              : Insert {min(x, y), max(x, y)} into a set and mark both elements as used (e.g., set their count or flag to 0/false).
//                                                         : Why it's better : Reduces unnecessary checks using hashing. Guarantees unique pairs. Automatically handles the {2, 2} case only when both 2s are present.
//                                                         : Pros : Most optimized for time: O(n) on average. Correctly includes valid pairs like {2, 2} once only, and avoids {3, 7} and {7, 3} both showing up. Clean separation of logic using hashing and sets.
//                                                         : Cons : Slightly more logic to write and maintain.
//                                                         : Important note : If we use map<int, bool> instead of map<int, int> (i.e., tracking presence instead of frequency), it will fail for cases like {2} and sum = 4, because it will wrongly assume {2, 2} is valid.
//                                                                          : That’s why using frequency (map<int, int>) is important — it lets us confirm that a number appears at least twice before forming pairs like {2, 2}.
//                                                                          : If you want to use map<int, bool>, then you either somehow have to make sure either of the two things : 1) There should be no duplicate/repeating elements, or 2) The index of element != index of complement
//                                                         : Time Complexity: O(n) for scanning the array and checking pairs. and Space Complexity: O(n) for the map and set.
// Approach 1 : Basic Brute Force!
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<vector<int>> findPairSum(vector<int> v, int sum) {
    vector<vector<int>> valPair;
    for(int i = 0; i < v.size(); i++) {
        for(int j = i + 1; j < v.size(); j++) {
            if(v[i] + v[j] == sum) {
                vector<int> valSum;
                valSum.push_back(min(v[i], v[j]));
                valSum.push_back(max(v[i], v[j]));
                valPair.push_back(valSum);
            }
        }
    }
    sort(valPair.begin(), valPair.end());
    valPair.erase(unique(valPair.begin(), valPair.end()), valPair.end());
    if (valPair.empty()) {
        return {{-1}};
    }
    return valPair;
}

int main() {
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i = 0; i<n; i++) {
        cin>>v[i];
    }
    int sum;
    cin>>sum;
    vector<vector<int>> ans = findPairSum(v, sum);
    if (ans.size() == 1 && ans[0].size() == 1 && ans[0][0] == -1) {
        cout << "[-1]";
    }
    else {
        cout << "[";
        for (int i = 0; i < ans.size(); i++) {
            cout << "[";
            for (int j = 0; j < ans[i].size(); j++) {
                cout << ans[i][j];
                if (j != ans[i].size() - 1) cout << ", ";
            }
            cout << "]";
            if (i != ans.size() - 1) cout << ", ";
        }
        cout << "]";
    }
}

// Approach 2 : Brute Force but using Sets!
//            : Advantage : It atleast gives our desired results! which is unique pairs!
#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;

vector<vector<int>> findPairSum2(vector<int> v, int sum) {
    set<pair<int,int>> valPair;
    for(int i = 0; i < v.size(); i++) {
        for(int j = i + 1; j < v.size(); j++) {
            if(v[i] + v[j] == sum) {
                valPair.insert({min(v[i], v[j]), max(v[i], v[j])});
            }
        }
    }
    vector<vector<int>> result;
    for(auto &p : valPair) {
        result.push_back({p.first, p.second});
    }
    return result;
}

int main() {
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i = 0; i<n; i++) {
        cin>>v[i];
    }
    int sum;
    cin>>sum;
    vector<vector<int>> ans = findPairSum2(v, sum);
    if (ans.size() == 1 && ans[0].size() == 1 && ans[0][0] == -1) {
        cout << "[-1]";
    }
    else {
        cout << "[";
        for (int i = 0; i < ans.size(); i++) {
            cout << "[";
            for (int j = 0; j < ans[i].size(); j++) {
                cout << ans[i][j];
                if (j != ans[i].size() - 1) cout << ", ";
            }
            cout << "]";
            if (i != ans.size() - 1) cout << ", ";
        }
        cout << "]";
    }
}

// Approach 3 : Optimized Approach (using maps)
#include<iostream>
#include<map>
#include<set>
#include<vector>
using namespace std;

vector<vector<int>> findPairSum3(vector<int> v, int sum) {
    map<int, int> freq;
    set<pair<int, int>> valPair;

    for (int num : v) {
        freq[num]++;
    }

    for (int i = 0; i < v.size(); i++) {
        int complement = sum - v[i];

        // Case 1: Pair of same elements (like 2 + 2 = 4)
        if (v[i] == complement && freq[v[i]] >= 2) {
            valPair.insert({v[i], v[i]});
            freq[v[i]] = 0; // mark both used
        }

        // Case 2: Normal case with two different values
        else if (v[i] != complement && freq[v[i]] > 0 && freq[complement] > 0) { // You may remove : v[i] != complement
            valPair.insert({min(v[i], complement), max(v[i], complement)});
            freq[v[i]] = 0;
            freq[complement] = 0;
        }
    }

    vector<vector<int>> result;
    for (auto &i : valPair) {
        result.push_back({i.first, i.second});
    }

    return result.size() > 0 ? result : vector<vector<int>>{{-1}};
}

int main() {
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i = 0; i < n; i++) {
        cin>>v[i];
    }
    int sum;
    cin>>sum;
    vector<vector<int>> ans = findPairSum3(v, sum);
    if (ans.size() == 1 && ans[0].size() == 1 && ans[0][0] == -1) {
        cout << "[-1]";
    }
    else {
        cout << "[";
        for (int i = 0; i < ans.size(); i++) {
            cout << "[";
            for (int j = 0; j < ans[i].size(); j++) {
                cout << ans[i][j];
                if (j != ans[i].size() - 1) cout << ", ";
            }
            cout << "]";
            if (i != ans.size() - 1) cout << ", ";
        }
        cout << "]";
    }
}

// Question 11 : Sort 0, 1
// Thinking : Approach 1 : Brute Force : Just the sort the array using any optimized sorting algorithms like merge or quick sort and get the result! TC : O(nlogn) and SC : O(1) for in-place sort
//          : Approach 2 : Logical Approach : Just count the number of 0's and 1's and just re-write them in the original array only! TC : O(n) and SC : O(1)
//          : Approach 3 : Optimized Approach : Use two pointer approach! Where start a pointer at the start with 0 and one at the end with "size - 1".
//                                            : And keep moving start forward and end backward until start value = 0 and end value = 1. and whenever wherever both of them breaks, just swap the values at that point and then again move start forward and end backward!
//                                            : TC : O(n) and SC : O(1)
// Approach 3 : Optimized Approach using Two Pointer!
#include<iostream>
#include<vector>
using namespace std;

void sort01(vector<int> &v) {
    int start = 0; int end = v.size() - 1;
    while(start < end) {
        while(v[start] == 0 && start < end) {
            start++;
        }
        while(v[end] == 1 && start < end) {
            end--;
        }
        if(start < end) { // Better than to check v[start] == 1 && v[end] == 0, as it will be redundant
            swap(v[start], v[end]);
            start++; end--;
        }
    }
}

int main() {
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i = 0; i<n; i++) {
        cin>>v[i];
        if(v[i] != 0 && v[i] != 1) { // Just an extra check! (optional in practice, but can be important as in real world you can't rely on user to always put correct value! Same for other questions!)
            cout<<"Restart the program and enter value 0/1";
            exit(0);
        }
    }
    sort01(v);
    for(int i = 0; i<v.size(); i++) {
        cout<<v[i]<<" ";
    }
}

// Question 12 : Given an integer array nums, rotate the array to the right by k steps, where k is non-negative.
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void rotatebyK_F1(vector<int> &v, int steps) {
    steps = steps % v.size();
    reverse(v.begin(), v.end());
    reverse(v.begin(), v.begin() + steps);
    reverse(v.begin() + steps, v.end());
}

void rotatebyK_F2(vector<int> &v, int steps) {
    int n = v.size();
    steps = steps % n;
    for(int i = 0; i < steps; i++) {
        int lastVal = v[n-1];
        for(int j = n - 1; j > 0; j--) {
            v[j] = v[j-1];
        }
        v[0] = lastVal;
    }
}

int main() {
    int n;
    cin>>n;
    int steps;
    cin>>steps;
    vector<int> v(n);
    for(int i = 0; i < v.size(); i++) {
        cin>>v[i];
    }
    rotatebyK_F2(v, steps);
    for(int i = 0; i < v.size(); i++) {
        cout<<v[i]<<" ";
    }
}

// Question 13 : Reverse a array after a particular index!
// Thinking & Approach : We already know how to reverse an array! Where we used to start from index = 0. But this time we will just give start from where the reverse is intended!
#include<iostream>
#include<vector>
using namespace std;

vector<int> reverseAfterK(vector<int> &v, int k) {
    int start = k;
    int end = v.size() - 1;
    while(start <= end) {
        swap(v[start], v[end]);
        start++;
        end--;
    }
}

int main() {
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i = 0; i < n; i++) {
        cin>>v[i];
    }
    int index;
    cin>>index;
    reverseAfterK(v, index);
    for(int i = 0; i < n; i++) {
        cout<<v[i]<<" ";
    }
}

// Question 14 : Merge 2 sorted arrays!
// Thinking & Approach : Goals of a Good Solution : It should cover most of the common use-cases/test-cases!
//                                                : It should take less time!
//                                                : It should take less space!
//                     : Some most common use-cases could be : Both Unsorted arrays! - (Handling 'contains duplicates' and 'doesn't contains duplicates' cases!) - (Want sorted/unsorted output)
//                                                           : One Sorted + Another Unsorted arrays! - (Handling 'contains duplicates' and 'doesn't contains duplicates' cases!) - (Want sorted/unsorted output)
//                                                           : Both Sorted arrays! - (Handling 'contains duplicates' and 'doesn't contains duplicates' cases!) - (Want sorted/unsorted output)
//                                                           : This case is mixture of any of the above! But no duplicates allowed in output! - (Want sorted/unsorted output)
//                     : And based on that, some solutions are proposed below!
// Approach 1 : Merge both arrays and sort the final array using sort() function as it implements quick-sort and takesless time to sort!
//            : Conditions : Arrays can be sorted/unsorted - duplicates allowed/not-allowed - final merged array sorted/unsorted.
//            : Time : O((n + m) * log(n + m))
//            : Space : O(n + m) (for result)
//            : Works for all cases. Most versatile and safe approach.
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> mergeTheTwo(vector<int> v1, vector<int> v2) {
    if(v1.size() == 0) {
        sort(v2.begin(), v2.end());
        return v2;
    }
    else if(v2.size() == 0){
        sort(v1.begin(), v1.end());
        return v1;
    }

    vector<int> result;
    for(int val : v1) result.push_back(val);
    for(int val : v2) result.push_back(val);

    // OR DO THIS

    // vector<int> result = v1;
    // result.insert(result.end(), v2.begin(), v2.end());
    
    sort(result.begin(), result.end()); // Used here as it implements quick-sort! and takes less time! Otherwise you can use normal sorting algorithms like insertion, bubble and selection!
    return result;
}

int main() {
    int n1, n2;
    cin>>n1>>n2;
    vector<int> v1(n1);
    for(int i = 0; i < n1; i++) {
        cin>>v1[i];
    }
    vector<int> v2(n2);
    for(int i = 0; i < n2; i++) {
        cin>>v2[i];
    }
    vector<int> ans = mergeTheTwo(v1, v2);
    for(int i = 0; i < ans.size(); i++) {
        cout<<ans[i]<<" ";
    }
}

// Approach 2 : When both input arrays are already sorted, we can take advantage of their order to optimize the merging process. By using the two-pointer technique, we traverse both arrays simultaneously and build the merged result in a single pass.
//            : It avoids the overhead of sorting and is more efficient than merging followed by a sort. This approach works whether or not duplicates are present. 
//            : Time : O(n + m) — each element is visited exactly once
//            : Space : O(n + m) — to store the final merged array
//             Use case : For the specific scenario where both arrays are sorted, this is the most efficient approach possible. There are no better general-purpose methods unless you’re dealing with very specific constraints.
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> mergeTheTwo(vector<int> v1, vector<int> v2) {
    vector<int> ans;
    int i = 0;
    int j = 0;
    while(i < v1.size() && j < v2.size()) {
        if(v1[i] <= v2[j]) {
            ans.push_back(v1[i]);
            i++;
        }
        else {
            ans.push_back(v2[j]);
            j++;
        }
    }
    while(i < v1.size()) {
        ans.push_back(v1[i]);
        i++;
    }
    while(j < v2.size()) {
        ans.push_back(v2[i]);
        j++;
    }
    return ans;
}

int main() {
    int n1, n2;
    cin>>n1>>n2;
    vector<int> v1(n1);
    for(int i = 0; i < n1; i++) {
        cin>>v1[i];
    }
    vector<int> v2(n2);
    for(int i = 0; i < n2; i++) {
        cin>>v2[i];
    }
    vector<int> ans = mergeTheTwo(v1, v2);
    for(int i = 0; i < ans.size(); i++) {
        cout<<ans[i]<<" ";
    }
}

// Approach 3 : Simple Append Without Sorting
//            : This method is ideal when sorted order is not required in the final result. It works whether the input arrays are sorted or unsorted.
//            : Simply copy the first array to the result vector. Then, append the second array to it.
//            : Note : This is one of the simplest and fastest methods. It avoids unnecessary sorting, making it efficient for cases where order doesn't matter.
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> mergeTheTwo(vector<int> v1, vector<int> v2) {
    if(v1.size() == 0) return v2;
    if(v2.size() == 0) return v1;

    vector<int> ans = v1;
    ans.insert(ans.end(), v2.begin(), v2.end());

    // or simply
    // v1.insert(v1.end(), v2.begin(), v2.end());
    return ans;
}

int main() {
    int n1, n2;
    cin>>n1>>n2;
    vector<int> v1(n1);
    for(int i = 0; i < n1; i++) {
        cin>>v1[i];
    }
    vector<int> v2(n2);
    for(int i = 0; i < n2; i++) {
        cin>>v2[i];
    }
    vector<int> ans = mergeTheTwo(v1, v2);
    for(int i = 0; i < ans.size(); i++) {
        cout<<ans[i]<<" ";
    }
}

// Approach 4 : Using unordered_set for Unique Elements
//            : If both arrays are expected to contain only unique elements, and the final result doesn't need to be sorted, you can use an unordered_set to efficiently merge them.
//            : Since unordered_set automatically removes duplicates and allows average O(1) insertion time, it's highly efficient for this use case. Any element present in both arrays will appear only once in the final result.
//            : Use case : You want to eliminate duplicates across both arrays.
//                       : Order of elements in the result does not matter.
//                       : Arrays may be sorted or unsorted, but final sorted order is not needed.
//            : Note : If you want the result to be sorted and unique, use set instead of unordered_set.
#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_set>
using namespace std;

vector<int> mergeTheTwo(vector<int> v1, vector<int> v2) {
    unordered_set<int> ans;
    for(int val : v1) ans.insert(val); 
    for(int val : v2) ans.insert(val); 
    return vector<int>(ans.begin(), ans.end());
}

int main() {
    int n1, n2;
    cin>>n1>>n2;
    vector<int> v1(n1);
    for(int i = 0; i < n1; i++) {
        cin>>v1[i];
    }
    vector<int> v2(n2);
    for(int i = 0; i < n2; i++) {
        cin>>v2[i];
    }
    vector<int> ans = mergeTheTwo(v1, v2);
    for(int i = 0; i < ans.size(); i++) {
        cout<<ans[i]<<" ";
    }
}

// Question 15 : Move Zeroes to the left!
// Thinking & Approach : Here we will first analyse different situations that can arise in this question!
//                     : 1) An array with no zeroes OR that array has only one zero and that too at the index 0. In this case we dont need to do anything just print the array as it is!
//                     : 2) Apart from this we need to solve it!
// Approach 1 : We will use simply two pointers approach here! where one will be 'i' starting at index = 0 and 'j' at index = size - 1
//            : Now we will check some cases like : 1) if value at i = 0 but j != 0 then we will move i++ & j--
//                                                : 2) if value at i = 0 but j = 0 then we will move i++;
//                                                : 3) if value at i != 0 but j = 0 then we will swap values at i & j then will do i++ & j--
//                                                : 4) if value at i != 0 but j != 0 then we will move j--
// Approach 2 : We will use the same logic which we have used in case of solving the "sort 0 1" problem earlier!

// Approach 1 :
#include<iostream>
#include<vector>
using namespace std;

vector<int> moveZeroesLeft(vector<int> &v) {
    int i = 0;
    int j = v.size() - 1;
    while(i < j) {
        if(v[i] == 0 && v[j] != 0) {
            i++; j--;
        }
        else if(v[i] == 0 && v[j] == 0) {
            i++;
        }
        else if(v[i] != 0 && v[j] == 0) {
            swap(v[i], v[j]);
            i++; j--;
        }
        else {
            j--;
        }
    }
    return v;
}

int main() {
    int n;
    cin>>n;
    vector<int> v(n);
    int zeroFound = false;
    for(int i = 0; i < n; i++) {
        cin>>v[i];
        if(v[i] == 0) {
            zeroFound = true;
        }
    }
    if(zeroFound) {
        moveZeroesLeft(v);
        for(int i = 0; i < n; i++) {
            cout<<v[i]<<" ";
        }
    }
    else {
        for(int i = 0; i < n; i++) {
            cout<<v[i]<<" ";
        }
    }
}

// Approach 2 :
#include<iostream>
#include<vector>
using namespace std;

vector<int> moveZeroesLeft(vector<int> &v) {
    int i = 0;
    int j = v.size() - 1;
    while(i < j) {
        while(i < v.size() && v[i] == 0) i++;
        while(j >= 0 && v[j] != 0) j--;

        if(i < j) {
            swap(v[i], v[j]);
            i++; j--;
        }
    }
    return v;
}

int main() {
    int n;
    cin>>n;
    vector<int> v(n);
    int zeroFound = false;
    for(int i = 0; i < n; i++) {
        cin>>v[i];
        if(v[i] == 0) {
            zeroFound = true;
        }
    }
    if(zeroFound) {
        moveZeroesLeft(v);
        for(int i = 0; i < n; i++) {
            cout<<v[i]<<" ";
        }
    }
    else {
        for(int i = 0; i < n; i++) {
            cout<<v[i]<<" ";
        }
    }
}

// However, here's the catch: The above solutions do not preserve the relative order of the non-zero elements. While this wasn't an issue in problems like "Sort 0s and 1s," it is important here—so we need a better approach that maintains the original order.
#include<iostream>
#include<vector>
using namespace std;

vector<int> moveZeroesLeft(vector<int>& v) {
    int write = v.size() - 1;
    for (int i = v.size() - 1; i >= 0; i--) { // Step 1: Move non-zeroes to the end while maintaining their order
        if (v[i] != 0) {
            v[write] = v[i];
            write--;
        }
    }

    while (write >= 0) { // Step 2: Fill remaining elements with 0
        v[write] = 0;
        write--;
    }

    return v;
}

// Alternative to assigning values, you can also use swap() function!
vector<int> moveZeroesLeft(vector<int>& v) {
    int write = v.size() - 1;
    for (int i = v.size() - 1; i >= 0; i--) {
        if (v[i] != 0) {
            swap(v[write],v[i]);
            write--;
        }
    }
    return v;
}

int main() {
    int n;
    cin>>n;
    vector<int> v(n);
    int zeroFound = false;
    for(int i = 0; i < n; i++) {
        cin>>v[i];
        if(v[i] == 0) {
            zeroFound = true;
        }
    }
    if(zeroFound) {
        moveZeroesLeft(v);
        for(int i = 0; i < n; i++) {
            cout<<v[i]<<" ";
        }
    }
    else {
        for(int i = 0; i < n; i++) {
            cout<<v[i]<<" ";
        }
    }
}

// Question 16 : Remove Duplicates from an array! (In-Place)
// Approach : There can be approaches like Brute Force! using sets or simple array traversal! But we are asked to keep it in-place!
// Approach : So we are using a similar approach, we have used in the Move zeroes to right/left questions!
#include<iostream>
#include<vector>
using namespace std;

int removeDuplicates(vector<int> &v) {
    int n = v.size();
    int i = 0;
    for(int j = 1; j < n; j++) {
        if(v[i] != v[j]) {
            i++;
            v[i] = v[j];
        }
    }
    return i + 1;
}

int main() {
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i = 0; i < n; i++) {
        cin>>v[i];
    }
    int newLen = removeDuplicates(v);
    cout << "Unique elements: ";
    for(int i = 0; i < newLen; i++) {
        cout << v[i] << " ";
    }
    cout << "\nLength: " << newLen << endl;
}

// Question 17 : Check if an array is sorted and rotated or not!
// Approach 1 (Brute Force) : We need to take care about few conditions : If the array is sorted & rotated! Then there will be a break point in the array where arr[i] > arr[i + 1]. That point will be named as pivot index!
//                                                                      : Now, array should be sorted before and after this pivot index!
//                                                                      : Lastly, arr[size - 1] < arr[0], If it's not true... means array can be sorted but not rotated!
// Approach 2 (Count Breaks) : Count the number of times arr[i] > arr[i+1] : If it's more than one → Not sorted and rotated.
//                                                                         : If it's exactly one → Yes, sorted and rotated.
//                                                                         : For circular check, compare arr[n-1] > arr[0].
// Approach 1 :
#include<iostream>
#include<vector>
using namespace std;

bool sortedRotated1(vector<int> v) {
    int n = v.size();
    int pivot = -1;
    for(int i = 0; i < n - 1; i++) {
        if(v[i] > v[i + 1]) {
            pivot = i + 1;
            break;
        }
    }
    
    if(pivot == -1) {
        cout<<"Sorted but not rotated!";
        return false;
    }

    for(int i = 0; i < pivot - 1; i++) {
        if(v[i] > v[i + 1]) {
            return false;
        }
    }

    for(int i = pivot; i < n - 1; i++) {
        if(v[i] > v[i + 1]) {
            return false;
        }
    }
    
    if(v[0] < v[n - 1]) return false;
    return true;
}

// Approach 2 :
bool sortedRotated2(vector<int> v) {
    int n = v.size();
    int countBreaks = 0;
    for(int i = 0; i < n; i++) {
        if(v[i] > v[(i + 1) % n]) {
            countBreaks++;
        }
    }
    return countBreaks == 1;
}

int main() {
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i = 0; i < n; i++) {
        cin>>v[i];
    }
    cout<< (sortedRotated(v) ? "True" : "false");
}

// Question 3 : Addition of 2 Arrays!
//            : When adding two arrays, you are essentially adding two numbers digit by digit, just like normal mathematical addition.
//            : There are two ways to handle the result : Variation 1 : Return the Final Sum as a Number, where Add all digits starting from the end (units place) and calculate the total sum. and Simply return the sum as a single number.
//                                                      : Variation 2 : Return the Result as an Array, where Add the digits starting from the end (units place), storing each digit in reverse order in a new array. and At the end, reverse the array to get the final result in correct order.
// Approach (Variation 1) : Same digit-wise addition as above (use i, j, carry, sum).
//                        : Instead of pushing to a vector : Keep building the final number using ans += digit * multiplier; & multiplier *= 10;
//                        : Return ans as the final number.
//                        : Limitations : Works only when the result fits in int or long long. Will fail for very large numbers like 10^18+.
// Approach Variation 2) : Initialize : Two pointers i = v1.size() - 1, j = v2.size() - 1. carry = 0. result vector to store the answer in reverse order.
//                       : While both arrays have digits : Add v1[i] + v2[j] + carry. Store sum % 10 in result. Update carry = sum / 10. Decrement i and j
//                       : If any digits remain in either v1 or v2 : Add remaining digits with carry
//                       : If carry still exists : Push carry to result & Reverse the result vector to get the final number
//                       : Pros : Works for very large numbers (like 100+ digits) & Used in competitive programming
// Variation 1 :
#include<iostream>
#include<vector>
using namespace std;

long long additionOfArrays(vector<int> v1, vector<int> v2) {
    int carry = 0;
    int sum = 0;
    int i = v1.size() - 1;
    int j = v2.size() - 1;
    int digit = -1;
    long ans = 0;
    long multiplier = 1;
    while(i >= 0 && j >= 0) {
        sum = v1[i] + v2[j] + carry;
        carry = sum/10;
        digit = sum%10;
        ans = (multiplier * digit) + ans;
        multiplier *= 10;
        i--; j--;
    }
    while(i >= 0) {
        sum = v1[i] + carry;
        carry = sum/10;
        digit = sum%10;
        ans = (multiplier * digit) + ans;
        multiplier *= 10;
        i--;
    }
    while(j >= 0) {
        sum = v2[j] + carry;
        carry = sum/10;
        digit = sum%10;
        ans = (multiplier * digit) + ans;
        multiplier *= 10;
        j--;
    }
    while(carry != 0) {
        ans = (multiplier * carry) + ans;
        multiplier *= 10;
        carry = carry/10;
    }
    return ans;
}

int main() {
    int n1, n2;
    cin>>n1>>n2;
    vector<int> v1(n1);
    for(int i = 0; i < n1; i++) {
        cin>>v1[i];
    }
    vector<int> v2(n2);
    for(int i = 0; i < n2; i++) {
        cin>>v2[i];
    }
    cout<<additionOfArrays(v1, v2);
}

// Variation 2 :
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> additionOfArrays(vector<int> v1, vector<int> v2) {
    int carry = 0;
    int sum = 0;
    int i = v1.size() - 1;
    int j = v2.size() - 1;
    vector<int> result;
    while(i >= 0 && j >= 0) {
        sum = v1[i] + v2[j] + carry;
        carry = sum/10;
        sum = sum%10;
        result.push_back(sum);
        i--; j--;
    }
    while(i >= 0) {
        sum = v1[i] + carry;
        carry = sum/10;
        sum = sum%10;
        result.push_back(sum);
        i--;
    }
    while(j >= 0) {
        sum = v2[j] + carry;
        carry = sum/10;
        sum = sum%10;
        result.push_back(sum);
        j--;
    }
    while(carry != 0) {
        result.push_back(carry);
        carry = carry/10;
    }
    reverse(result.begin(), result.end());
    return result;
}

int main() {
    int n1, n2;
    cin>>n1>>n2;
    vector<int> v1(n1);
    for(int i = 0; i < n1; i++) {
        cin>>v1[i];
    }
    vector<int> v2(n2);
    for(int i = 0; i < n2; i++) {
        cin>>v2[i];
    }
    vector<int> ans = additionOfArrays(v1, v2);
    for(int val : ans) cout<<val;
}