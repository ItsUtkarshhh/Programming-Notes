// ------------------------------------------------------- Question 1 : Largest Element ----------------------------------------------------------------------------------------------------------->
// Brute Force : Sort the array and return the (n-1)th element of the array.
// Better : Perform a linear traversal and iteratively find the largest value.

// Better :
#include<iostream>
#include<vector>
using namespace std;

int main() {
    int size;
    cin>>size;
    vector<int> v(size);
    for(int i =  0; i < size; i++) {
        cin>>v[i];
    }

    int maxi = INT_MIN;
    for(int i = 0; i < size; i++) {
        maxi = max(maxi, v[i]);
    }

    cout<<"Maximum Value : "<<maxi<<endl;
}

// ------------------------------------------------------- Question 2 : Second Largest Element ----------------------------------------------------------------------------------------------------------->
// Brute Force : Sort the array in ascending order and get the (n-2)th element
// Better : Traverse the array, and maintain two values largest and second largest at every iteration, and by the end of the array, you will get the second largest.

// Better :
#include<iostream>
#include<vector>
using namespace std;

int main() {
    int size;
    cin>>size;
    vector<int> v(size);
    for(int i =  0; i < size; i++) {
        cin>>v[i];
    }

    int maxi = INT_MIN;
    int secondMaxi = maxi;
    for(int i = 0; i < size; i++) {
        if(v[i] > secondMaxi && v[i] > maxi) {
            secondMaxi = maxi;
            maxi = v[i];
        }
        else if(v[i] > secondMaxi && v[i] < maxi) {
            secondMaxi = v[i];
        }
    }

    if(secondMaxi == INT_MIN) {
        cout<<-1<<endl;
        return 0;
    }
    cout<<"Second Maximum Value : "<<secondMaxi<<endl;
}

// ------------------------------------------------------- Question 3 : Check if an Array is Sorted (Ascending) ----------------------------------------------------------------------------------------------------------->
// Brute Force : Keep comparing the next element to its previous element and if at any moment the next element is smaller than the previous element, then simply return false/unsorted.

// Brute Force
#include<iostream>
#include<vector>
using namespace std;

int main() {
    int size;
    cin>>size;
    vector<int> v(size);
    for(int i =  0; i < size; i++) {
        cin>>v[i];
    }

    for(int i = 0; i < size - 1; i++) {
        if(v[i] > v[i+1]) {
            cout<<"Unsorted Array!";
            return 0;
        }
    }
    cout<<"Sorted Array!";
    return 0;
}

// ------------------------------------------------------- Question 4 : Remove Duplicates in-place from Sorted Array ----------------------------------------------------------------------------------------------------------->
// Brute Force : (Not In Place) - Insert all the elemeents into a set and then insert back them into the original vector and decrease the size of the original vector to its new length.
// Better : As the is sorted, we can traverse using two pointers, one will take care of the last unique element and the other will traverse further over duplicates until a new unique element occurs & then will resize the vector accordingly.

#include<iostream>
#include<set>
using namespace std;

// Brute Force
void removeDuplicates1(vector<int> &v) {
    if(v.empty()) {
        cout<<"Array is empty!";
        return;
    }
    
    set<int> st(v.begin(), v.end());
    
    int i = 0;
    for(int val : st) {
        v[i++] = val;
    }
    
    v.resize(st.size);
}

// Better
void removeDuplicates2(vector<int> &v) {
    if(v.empty()) {
        cout<<"Array is empty!";
        return;
    }
    
    int i = 0; int j = i+1;
    while(j < v.size()) {
        if(v[i] != v[j]) {
            i++;
            v[i] = v[j];
        }
        j++;
    }
    
    v.resize(i+1);
}

int main() {
    int size;
    cin>>size;
    
    vector<int> v(size);
    for(int i =  0; i < size; i++) {
        cin>>v[i];
    }
    
    removeDuplicates1(v);
    // removeDuplicates2(v);
    
    for(int i = 0; i < size; i++) {
        cout<<v[i]<<" ";
    }
}

// ------------------------------------------------------- Question 5 : Left Rotate the Array by One ----------------------------------------------------------------------------------------------------------->
// Brute Force : Simply store the first value in a variable and shift the rest of the array by one towards left and update the last value with the stored value.
// Better : Conceptually divide the arrays into three sections, index0 - (k-1), k - indexN & index0 - indexN, and Reverse the three sections one by one.

// Brute Force
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// Brute Force
void leftRotateByOneA(vector<int> &v) {
    if(v.empty()) {
        cout<<"Empty array!";
        return;
    }

    int val = v[0];
    for(int i = 0; i < v.size() - 1; i++) {
        v[i] = v[i+1];
    }

    v[v.size() - 1] = val;
}

// Better
void leftRotateByOneB(vector<int> &v, int k) {
    if(v.empty()) {
        cout<<"Empty array!";
        return;
    }
    
    reverse(v.begin(), v.begin() + k);
    reverse(v.begin() + k, v.end());
    reverse(v.begin(), v.end());
}

int main() {
    int size;
    cin>>size;
    
    vector<int> v(size);
    for(int i =  0; i < size; i++) {
        cin>>v[i];
    }
    
    int k;
    cin>>k;
    
    // leftRotateByOneA(v);
    leftRotateByOneB(v, k);

    for(int i = 0; i < size; i++) {
        cout<<v[i]<<" ";
    }
}

// ------------------------------------------------------- Question 6 : Move all Zeros to the end of the array (Mainting Relative Order) ----------------------------------------------------------------------------------------------------------->
// Brute Force : Input all values to temporary array & then append number of zeroes as present in the original array.
// Better : (Order not maintained) Use two pointers, keep one at starting & another at the end, and swap based on zero and non zero conditions.
// Optimal : Use the read & write pointer strategy, as similar as removing duplicates problem, where one pointer will keep the track of the last non zero value & read pointer will track the next zero values and will swap/assign.

#include<iostream>
#include<vector>
using namespace std;

// Better
void moveZeroesToEnd(vector<int> &v) {
    if(v.empty()) {
        cout<<"Empty array!";
        return;
    }
    
    int i = 0; int j = v.size() - 1;
    while(i < j) {
        if(v[i] == 0 && v[j] == 0) j--;
        else if(v[i] != 0 && v[j] == 0) j--;
        else if(v[i] != 0 && v[j] != 0) i++;
        else {
            swap(v[i], v[j]);
            i++; j--;
        }
    }
}

// Optimal
void moveZeroesToEnd(vector<int> &v) {
    if(v.empty()) {
        cout<<"Empty array!";
        return;
    }
    
    int i = 0; int j = 0;
    while(j < v.size()) {
        if(v[j] != 0) {
            swap(v[i], v[j]);
            i++;
        }
        j++;
    }
}

int main() {
    int size;
    cin>>size;
    
    vector<int> v(size);
    for(int i =  0; i < size; i++) {
        cin>>v[i];
    }
    
    moveZeroesToEnd(v);
    
    for(int i = 0; i < size; i++) {
        cout<<v[i]<<" ";
    }
}

// ------------------------------------------------------- Question 7 : Linear Search ----------------------------------------------------------------------------------------------------------->
// Brute Force : Traverse the array linear way and compare it with the key at every iteration and if matches, return true or that element as per the need.

// Brute Force
#include<iostream>
#include<vector>
using namespace std;

bool linearSearch(vector<int> &v, int key) {
    if(v.empty()) return false;
    
    for(int i = 0; i < v.size(); i++) {
        if(v[i] == key) return true;
    }
    return false;
}

int main() {
    int size;
    cin>>size;
    
    vector<int> v(size);
    for(int i =  0; i < size; i++) {
        cin>>v[i];
    }
    
    int key;
    cin>>key;
    cout<<linearSearch(v, key);
}

// ------------------------------------------------------- Question 8 : Union of Two Sorted Arrays ----------------------------------------------------------------------------------------------------------->
// Brute Force 1 : This problem is based on set union, and as the arrays can contain duplicates, we can simply use hashmaps, so store all values from both the arrays and then simply iterate over the map to restore the values in final result array.
// Brute Force 2 : Similarly, we can use set, as we do not want duplicates in the final result, we can simply insert both the arrays into the set, and then insert back those set elements into the final result vector.
// Optimal : We can use two pointer strategy, where we can simply traverse both the arrays, and will keep on adding those values into the final result array.

#include<iostream>
#include<vector>
#include<map>
#include<set>
using namespace std;

// Brute Force 1 :
vector<int> unionOfTwoArrays1(vector<int> &v1, vector<int> &v2) {
    if(v1.empty()) return v2;
    if(v2.empty()) return v1;
    
    map<int, int> freqMap;
    for(int i : v1) freqMap[i]++;
    for(int i : v2) freqMap[i]++;
    
    vector<int> result;
    for(auto it : freqMap) {
        result.push_back(it.first);
    }
    
    return result;
}

// Brute Force 2 :
vector<int> unionOfTwoArrays2(vector<int> &v1, vector<int> &v2) {
    if(v1.empty()) return v2;
    if(v2.empty()) return v1;

    set<int> st;
    for(int i : v1) st.insert(i);
    for(int i : v2) st.insert(i);
    
    vector<int> result;
    for(int i : st) {
        result.push_back(i);
    }

    return result;
}

// Optimal :
vector<int> unionOfTwoArrays3(vector<int> &v1, vector<int> &v2) {
    if(v1.empty()) return v2;
    if(v2.empty()) return v1;

    int i = 0; int j = 0;
    vector<int> result;

    while(i < v1.size() && j < v2.size()) {
        if(v1[i] < v2[j]) {
            if(result.empty() || result.back() != v1[i]) {
                result.push_back(v1[i]);
            }
            i++;
        }
        else if(v1[i] > v2[j]) {
            if(result.empty() || result.back() != v2[j]) {
                result.push_back(v2[j]);
            }
            j++;
        }
        else {
            if(result.empty() || result.back() != v1[i]) {
                result.push_back(v1[i]);
            }
            i++; j++;
        }
    }
    
    while(i < v1.size()) {
        if(result.empty() || result.back() != v1[i]) {
            result.push_back(v1[i]);
            }
            i++;
        }
        
        while(j < v2.size()) {
            if(result.empty() || result.back() != v2[j]) {
                result.push_back(v2[j]);
        }
        j++;
    }
    
    return result;
}

int main() {
    int size1, size2;
    cin>>size1>>size2;
    
    vector<int> v1(size1);
    for(int i =  0; i < size1; i++) {
        cin>>v1[i];
    }
    
    vector<int> v2(size2);
    for(int i =  0; i < size2; i++) {
        cin>>v2[i];
    }

    vector<int> result = unionOfTwoArrays1(v1, v2);
    for(int i = 0; i < result.size(); i++) {
        cout<<result[i]<<" ";
    }
}

// ------------------------------------------------------- Question 9 : Find the Missing Number ----------------------------------------------------------------------------------------------------------->
// Brute Force : Simple linear traversal and finding the missing element between [1,N] in the array.
// Better : Find the sum of all the numbers from 1-n & sum of all the numbers in the array and their subtraction will be the missing number.
// Optimal : Use the XOR Operation.

#include<iostream>
#include<vector>
using namespace std;

// Better
int findMissingNumber1(vector<int> v) {
    if(v.empty()) return -1;
    
    int range = v.size() + 1;
    int sum1 = range * (range + 1) / 2;

    int sum2 = 0;
    for(int i = 0; i < v.size(); i++) {
        sum2 += v[i];
    }
    
    return sum1 - sum2;
}

// Optimal
int findMissingNumber2(vector<int> v) {
    if(v.empty()) return -1;
    
    int range = v.size() + 1;
    int XorVal = 0;
    for(int i = 1; i <= range; i++) {
        XorVal ^= i;
    }

    for(int i = 0; i < v.size(); i++) {
        XorVal ^= v[i];
    }
    
    return XorVal;
}

int main() {
    int size;
    cin>>size;
    
    vector<int> v(size);
    for(int i =  0; i < size; i++) {
        cin>>v[i];
    }
    
    cout<<findMissingNumber2(v);
}

// ------------------------------------------------------- Question 10 : Count Maximum Consecutive One's in the array ----------------------------------------------------------------------------------------------------------->
// Brute / Optimal : Traverse by keeping the track of maximum consecutive ones everytime the streak breaks. and return the final maximum ones value.

#include<iostream>
#include<vector>
using namespace std;

int maxConsecutiveOnes(vector<int> &v) {
    if(v.empty()) return -1;

    int maxOnesCount = 0;
    int currentCount = 0;
    
    for(int i = 0; i < v.size(); i++) {
        if(v[i] == 1) {
            currentCount++;
        }
        else {
            currentCount = 0;
        }
        maxOnesCount = max(currentCount, maxOnesCount);
    }

    return maxOnesCount;
}

int main() {
    int size;
    cin>>size;
    
    vector<int> v(size);
    for(int i =  0; i < size; i++) {
        cin>>v[i];
    }
}

// ------------------------------------------------------- Question 11 : Find the number that appears once, and the other numbers twice ----------------------------------------------------------------------------------------------------------->
// Brute Force : Pick each element one by one and traverse the same array and count occurrence, and check for the count everytime the inner loop ends, if the count == 1, then return the number simply.
// Better : Use a map to count frequency of each number, and then get the number with the frequency one. And this same can be done using another array (but that will waste a lots of space unneccessarily).
// Optimal : We can use the properties, if the other numbers are appearing twice, we can simply XOR all the numbers in the array and only one number will remain at the end, that will be the unique number.

#include<iostream>
#include<vector>
using namespace std;

// Optimal :
int getSingleElement(vector<int> &v) {
    if(v.empty()) return -1;
    
    int XorVal = 0;
    for(int i = 0; i < v.size(); i++) {
        XorVal ^= v[i];
    }
    
    return XorVal;
}

int main() {
    int size;
    cin>>size;
    
    vector<int> v(size);
    for(int i =  0; i < size; i++) {
        cin>>v[i];
    }

    cout<<getSingleElement(v);
}

// ------------------------------------------------------- Question 12 : Longest Subarray with given Sum K (Only Positives) ----------------------------------------------------------------------------------------------------------->
// Brute Force : Traverse the array with two pointers, which will denote the window size. Keep adding values until the sum == K, if it get equals K, note the size of the subarray and break when size > K.
// Better : Use two pointers to maintain, expand, and shrink the window size as per the sum value, and when sum == k, stores the maxLen and if sum > k then shrinks the window.
// Optimal 1 : We don't need to shrink continously below the maxLen, so we replaced the "while" with "if"
// Optimal 2 : Prefix Sum & Hashmap (Can be used here, but works best in case of +ve, -ve & zeroes.)

#include<iostream>
#include<vector>
using namespace std;

// Brute Force : 
int longestSubarrayLen1(vector<int> &v, int k) {
    if(v.empty()) return 0;
    
    int maxLen = 0;
    int sum = 0;
    
    for(int i = 0; i < v.size(); i++) {
        sum = 0;
        for(int j = i; j < v.size(); j++) {
            sum += v[j];
            if(sum == k) {
                maxLen = max(maxLen, j - i + 1);
            }
            else if(sum > k) {
                break;
            }
        }
    }
    return maxLen;
}

// Better :
int longestSubarrayLen2(vector<int> &v, int k) {
    if(v.empty()) return 0;
    
    int left = 0;
    int right = 0;
    int sum = 0;
    int maxLen = 0;
    
    while(right < v.size()) {
        sum += v[right];
        while(left <= right && sum > k) {
            sum -= v[left];
            left++;
        }
        if(sum == k) {
            maxLen = max(maxLen, right - left + 1);
        }
        right++;
    }
    return maxLen;
}

// Optimal 1 :
int longestSubarrayLen2(vector<int> &v, int k) {
    if(v.empty()) return 0;
    
    int left = 0;
    int right = 0;
    int sum = 0;
    int maxLen = 0;
    
    while(right < v.size()) {
        sum += v[right];
        if(left <= right && sum > k) {
            sum -= v[left];
            left++;
        }
        if(sum == k) {
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

    int finalLength = longestSubarrayLen(v, k);
    cout<<finalLength<<endl;
}

// ------------------------------------------------------- Question 13 : Longest Subarray with given Sum K (Positives & Negatives) ----------------------------------------------------------------------------------------------------------->