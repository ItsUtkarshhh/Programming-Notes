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
        else if (v[i] != complement && freq[v[i]] > 0 && freq[complement] > 0) {
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