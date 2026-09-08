// ------------------------------------------------------------- Sliding Window & Two Pointers ---------------------------------------------------------------------------------------------------------------->
// ----------------------------------------------------------------------- Problem 1 ---------------------------------------------------------------------------------------------------------------->
// Problem : Find the maximum sum in an array with the window of size K - Constant Window Size
// Approach : For constant window problems, generally compute the value for the first window and then move forward with the expansion and shrnking of the window maintaining the size K.

#include<iostream>
#include<vector>
using namespace std;

int maxSumSubarray(vector<int> &v, int k) {
    if(v.empty()) return 0;
    if(k <= 0 || k > v.size()) return 0;
    
    int left = 0;
    int right = k-1;
    int sum = 0;
    int maxSum = INT_MIN;
    
    for(int i = left; i <= right; i++) {
        sum += v[i];
    }
    
    maxSum = max(maxSum, sum);
    
    right = k;
    while(right < v.size()) {
        sum -= v[left];
        left++;
        sum += v[right];
        right++;
        
        maxSum = max(maxSum, sum);
    }
    
    return maxSum;
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
    
    cout<<maxSumSubarray(v, k);
}

// ----------------------------------------------------------------------- Problem 2 ---------------------------------------------------------------------------------------------------------------->
// Problem : Longest Subarray with the sum <= K
// Brute Force : Generate all the subarrays using nested loops and compute the longest subarrays among those.
// Better : Use two pointers, as the two ends of the window, and expand and shrink based on the conditions, and updates the maxLen.
// Optimal : We don't need to shrink continously below the maxLen, so we replaced the "while" with "if"

#include<iostream>
#include<vector>
using namespace std;

// Better
int LongestSubarrayWithSumK(vector<int> v, int k) {
    if(v.empty()) return 0;
    
    int left = 0;
    int right = left;
    int sum = 0;
    int maxLen = 0;
    
    while(right < v.size()) {
        sum += v[right];
        while(left <= right && sum > k) {
            sum -= v[left];
            left++;
        }
        if(sum <= k) {
            maxLen = max(maxLen, right - left + 1);
        }
        right++;
    }
    return maxLen;
}

// Optimal
int LongestSubarrayWithSumK2(vector<int> v, int k) {
    if(v.empty()) return 0;
    
    int left = 0;
    int right = left;
    int sum = 0;
    int maxLen = 0;
    
    while(right < v.size()) {
        sum += v[right];
        if(left <= right && sum > k) {
            sum -= v[left];
            left++;
        }
        if(sum <= k) {
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
    
    cout<<LongestSubarrayWithSumK2(v, k);
}

// ----------------------------------------------------------------------- Problem 3 ---------------------------------------------------------------------------------------------------------------->
// Problem : Maximum Points you can obtain from N cards.
// Approach : Its a constant window problem, so first we will calculate the sum of the first window, and then will move forward, by subtracting one from the left side subarray and adding one from the right side subarray.

int maxPointsFromCards(vector<int> &v, int k) {
    if(v.empty()) return 0;
    
    int sum = 0;
    int maxSum = INT_MIN;
    
    for(int i = 0; i <= k-1; i++) {
        sum += v[i];
    }
    
    maxSum = max(maxSum, sum);
    int rightIndex = v.size() - 1;
    
    for(int i = k-1; i >= 0; i--) {
        sum = sum - v[i] + v[rightIndex];
        maxSum = max(maxSum, sum);
        rightIndex--;
    }
    return maxSum;
}

// ----------------------------------------------------------------------- Problem 4 ---------------------------------------------------------------------------------------------------------------->
// Problem : Longest Substring Without Repeating Characters
// Brute Force : Try to generate all the subarrays, and use a hashmap to track occurrence of all of them. And update the max length accordingly.
// Optimal : Use the sliding window logic, to traverse the string in the form of a window of sub strings, and check for the dupllications within those sub strings using hashmap.

// Brute Force :
int longestSubStringNoRep(string &str) {
    if(str.empty()) return 0;

    string subStr = "";
    int maxLen = INT_MIN;
    
    for(int i = 0; i < str.length(); i++) {
        subStr = "";
        map<char, int> hash;
        for(int j = i; j < str.length(); j++) {
            if(hash[str[j]] == 0) {
                subStr = subStr + str[j];
                maxLen = max(maxLen, j - i + 1);
                hash[str[j]]++;
            }
            else {
                break;
            }
        }
    }
    return maxLen;
}

// Optimal :
int longestSubStringNoRep(string &str) {
    if(str.empty()) return 0;
    
    string subStr = "";
    int maxLen = INT_MIN;
    map<char, int> hash;
    
    for(char ch = 'a'; ch <= 'z'; ch++) {
        hash[ch] = -1;
    }
    
    int left = 0; int right = 0;
    while(right < str.length()) {
        if(hash[str[right]] == -1 || hash[str[right]] < left) {
            subStr = subStr + str[right];
            maxLen = max(maxLen, right - left + 1);
        }
        else {
            left = hash[str[right]] + 1;
        }
        hash[str[right]] = right;
        right++;
    }
    
    return maxLen;
}

// ----------------------------------------------------------------------- Problem 5 ---------------------------------------------------------------------------------------------------------------->
// Problem : Max Consecutive Ones III - Longest Subarray with at most K zeroes.
// Brute Force : Generate all the sub arrays and keep couting the zeroes, if the zeroes exceeds K value, then simply calculate the length of that sub array. And similarly move forward.
// Optimal 1 : Expand right, count zeroes, if zeroes exceeds K, then shrink left until zeroes < k, and track the maximum valid window length.
// Optimal 2 : Expand right, count zeroes, if zeroes exceeds K, then shrink left once, and update the max length only when it zeroes are within range.

// Brute :
int maxConsecutiveOnes(vector<int> &v, int k) {
    if(v.empty()) return 0;
    
    int zeroes = 0;
    int maxLen = 0;
    
    for(int i = 0; i < v.size(); i++) {
        zeroes = 0;
        for(int j = i; j < v.size(); j++) {
            if(v[j] == 0) {
                zeroes++;
            }
            if(zeroes <= k) {
                maxLen = max(maxLen, j - i + 1);
            }
            else {
                break;
            }
        }
    }
    return maxLen;
}

// Optimal 1 :
int maxConsecutiveOnes(vector<int> &v, int k) {
    if(v.empty()) return 0;
    
    int zeroes = 0;
    int maxLen = 0;
    
    int left = 0; int right = 0;
    while(right < v.size()) {
        if(v[right] == 0) {
            zeroes++;
        }
        if(zeroes <= k) {
            maxLen = max(maxLen, right - left + 1);
        }
        else {
            while(zeroes > k) {
                if(v[left] == 0) zeroes--;
                left++;
            }
        }
        right++;
    }
}

// Optimal 2 :
int maxConsecutiveOnes(vector<int> &v, int k) {
    if(v.empty()) return 0;
    
    int zeroes = 0;
    int maxLen = 0;
    
    int left = 0; int right = 0;
    while(right < v.size()) {
        if(v[right] == 0) {
            zeroes++;
        }
        if(zeroes > k) {
            if(v[left] == 0) zeroes--;
            left++;
        }
        if(zeroes <= k) {
            maxLen = max(maxLen, right - left + 1);
        }
        right++;
    }
    return maxLen;
}

// ----------------------------------------------------------------------- Problem 6 ---------------------------------------------------------------------------------------------------------------->
// Problem : Fruit Into Baskets - Maximum length of sub array with at most two types of numbers.
// Brute Force : Generate all the subarray, collects unique fruit types using a set, stops when types exceed two, and updates the maximum length found.
// Optimal 1 : Use a sliding window with left and right pointers, shrinks the window incrementally using a while loop whenever unique fruit types exceed two. And update the maxLen everytime after the inner while loop.
// Optimal 2 : Use a sliding window with left and right pointers, shrinks the window once whenever unique fruit types exceed two. And update the maxLen only when the condition is valid.

// Brute Force :
int totalFruit(vector<int> &v) {
    if(v.empty()) return 0;
    
    int maxLen = 0;
    
    for(int i = 0; i < v.size(); i++) {
        set<int> fruits;
        for(int j = i; j < v.size(); j++) {
            fruits.insert(v[j]);
            if(fruits.size() > 2) {
                break;
            }
            maxLen = max(maxLen, j - i + 1);
        }
    }
    return maxLen;
}

// Optimal 1 :
int totalFruit(vector<int> &v) {
    if(v.empty()) return 0;
    
    int maxLen = 0;
    
    map<int, int> fruits;
    int left = 0; int right = 0;
    while(right < v.size()) {
        fruits[v[right]]++;
        
        while(fruits.size() > 2) {
            fruits[v[left]]--;
            if(fruits[v[left]] == 0) {
                fruits.erase(v[left]);
            }
            left++;
        }
        maxLen = max(maxLen, right - left + 1);
        right++;
    }
    return maxLen;
}

// Optimal 2 :
int totalFruit(vector<int> &v) {
    if(v.empty()) return 0;
    
    int maxLen = 0;
    
    map<int, int> fruits;
    int left = 0; int right = 0;
    while(right < v.size()) {
        fruits[v[right]]++;

        if(fruits.size() > 2) {
            fruits[v[left]]--;
            if(fruits[v[left]] == 0) {
                fruits.erase(v[left]);
            }
            left++;
        }
        else {
            maxLen = max(maxLen, right - left + 1);
        }
        right++;
    }
    return maxLen;
}

// ----------------------------------------------------------------------- Problem 7 ---------------------------------------------------------------------------------------------------------------->
// Problem : Longest sub string with at most K distinct characters.
// Brute Force :
// Optimal :

// Brute Force :
int longestSubstringWithKDistinct(string str, int k) {
    if(str.empty()) return 0;
    
    int maxLen = 0;
    
    for(int i = 0; i < str.length(); i++) {
        set<int> st;
        for(int j = i; j < str.length(); j++) {
            st.insert(str[j]);
            
            if(st.size() > k) {
                break;
            }
            
            maxLen = max(maxLen, j - i + 1);
        }
    }
    return maxLen;
}

// Optimal :
int longestSubstringWithKDistinct(string str, int k) {
    if(str.empty()) return 0;
    
    int maxLen = 0;
    map<char, int> hash;

    int left = 0; int right = 0;
    while(right < str.length()) {
        hash[str[right]]++;
        
        while(hash.size() > k)  {
            hash[str[left]]--;
            if(hash[str[left]] == 0) hash.erase(str[left]);
            left++;
        }
        
        maxLen = max(maxLen, right - left + 1);
        right++;
    }
    return maxLen;
}

// Optimal 2 :
int longestSubstringWithKDistinct(string str, int k) {
    if(str.empty()) return 0;

    int maxLen = 0;
    map<char, int> hash;
    
    int left = 0; int right = 0;
    while(right < str.length()) {
        hash[str[right]]++;
        
        if(hash.size() > k)  {
            hash[str[left]]--;
            if(hash[str[left]] == 0) hash.erase(str[left]);
            left++;
        }
        else {
            maxLen = max(maxLen, right - left + 1);
        }
        right++;
    }
    return maxLen;
}

// ----------------------------------------------------------------------- Problem 8 ---------------------------------------------------------------------------------------------------------------->
// Problem : Number of Substrings Containing All Three Characters
// Brute Force : Generate every possible substring, track its distinct characters using a set, and increment the count whenever the substring contains all three characters.
// Better : Generate substrings from each starting index, and once all three characters are found, add all possible extensions (n-j) and move ahead.
// Optimal : Track the latest occurrence of each required character in an array, whenever all are present, add the minimum index plus one.

// Brute Force :
int allThreeCharactersSubstr(string str) {
    if(str.empty()) return 0;
    
    int count = 0;
    
    for(int i = 0; i < str.length(); i++) {
        set<char> hash;
        for(int j = i; j < str.length(); j++) {
            hash.insert(str[j]);
            if(hash.size() == 3) count++;
        }
    }
    return count;
}

// Better :
int allThreeCharactersSubstr(string str) {
    if(str.empty()) return 0;
    
    int count = 0;
    int n = str.length();
    
    for(int i = 0; i < str.length(); i++) {
        set<int> hash;
        for(int j = i; j < str.length(); j++) {
            hash.insert(str[j]);
            if(hash.size() == 3) {
                count = count + (n-j);
                break;
            }
        }
    }
    return count;
}

// Optimal (For Specific Characters) :
int allThreeCharactersSubstr(string str) {
    if(str.empty()) return 0;
    
    int count = 0;
    map<char, int> hash = {
        {'a', -1},
        {'b', -1},
        {'c', -1}
    };
    int left = 0; int right = 0;

    while(right < str.length()) {
        hash[str[right]] = right;
        
        if(hash['a'] >= 0 && hash['b'] >= 0 && hash['c'] >= 0) {
            count = count + min(hash['a'], hash['b'], hash['c']) + 1;
        }
        right++;
    }
    return count;
}

// Optimal (General Case) :
int allThreeCharactersSubstr(string str) {
    if(str.empty()) return 0;
    
    int count = 0;
    int hashArray[3] = {-1, -1, -1};
    int left = 0; int right = 0;
    
    while(right < str.length()) {
        hashArray[str[right] - 'a'] = right;
        
        if(hashArray[0] >= 0 && hashArray[1] >= 0 && hashArray[2] >= 0) {
            count = count + min(hashArray[0], hashArray[1], hashArray[2]) + 1;
        }
        right++;
    }
    return count;
}

// ----------------------------------------------------------------------- Problem 9 ---------------------------------------------------------------------------------------------------------------->