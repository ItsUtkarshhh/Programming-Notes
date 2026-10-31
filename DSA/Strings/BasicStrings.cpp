// -------------------------------------------------- Basic Strings --------------------------------------------------------------->
// -------------------------------------------------- Problem 1 :  Reverse a String II --------------------------------------------------------------->
// Problem Statement : Given a string, the task is to reverse it. The string is represented by an array of characters s.Given a string, the task is to reverse it. The string is represented by an array of characters s.Given a string, the task is to reverse it. The string is represented by an array of characters s.
//                   : Perform the reversal in place with O(1) extra memory.
//                   : Note : no need to return anything, modify the given list.

#include<iostream>
using namespace std;

void reverseString(vector<char> &v) {
    if(v.empty()) {
        cout<<"Empty vector string of characters";
        return;
    }

    int s = 0; int e = v.size() - 1;
    while(s <= e) {
        swap(v[s], v[e]);
        s++; e--;
    }
}

int main() {
    int n;
    cin>>n;

    vector<char> v(n);
    for(int i = 0; i < n; i++) {
        cin>>v[i];
    }
    reverseString(v);
}

// -------------------------------------------------- Problem 2 : Palindrome Check --------------------------------------------------------------->
// Problem Statement : You are given a string s. Return true if the string is palindrome, otherwise false.
//                   : A string is called palindrome if it reads the same forward and backward.

#include<iostream>
using namespace std;

bool palindromeChecker(string &s) {
    if(s.length() == 0) {
        cout<<"Empty string!";
        return true;
    }
    
    int start = 0; int end = s.size() - 1;
    while(start <= end) {
        if(s[start] != s[end]) return false;
        start++; end--;
    }
    
    return true;
}

int main() {
    string s;
    cin>>s;
    cout<<palindromeChecker(s);
}

// -------------------------------------------------- Problem 3 : Largest Odd Number in a String --------------------------------------------------------------->
// Problem Statement : Given a string s, representing a large integer, the task is to return the largest-valued odd integer (as a string) that is a substring of the given string s.
//                   : The number returned should not have leading zero's. But the given input string may have leading zero. (If no odd number is found, then return empty string.)

#include<iostream>
using namespace std;

string largeOddNum(string &str) {
    if(str.length() == 0) return "";
    
    int start = 0;
    int end = str.length() - 1;
    
    while(end >= 0) {
        int digit = str[end] - '0';
        if(digit % 2 != 0) break;
        else end--;
    }
    
    if(end < 0) return "";
    
    while(start <= end && str[start] == '0') {
        start++;
    }
    
    if(start > end) return "";
    
    return str.substr(start, end - start + 1);
}

int main() {
    string s;
    cin>>s;
    cout<<palindromeChecker(s);
}

// -------------------------------------------------- Problem 4 : Longest Common Prefix --------------------------------------------------------------->
// Problem Statement : Write a function to find the longest common prefix string amongst an array of strings.
//                   : If there is no common prefix, return an empty string "".

#include<iostream>
#include<vector>
using namespace std;

string longestCommonPrefix(vector<string> &strArr) {
    if(strArr.size() == 0) return "Empty String";
    
    int shortestLength = INT_MAX;
    string shortestString = "";
    for(int i = 0; i < strArr.size(); i++) {
        if(strArr[i].length() < shortestLength) {
            shortestLength = strArr[i].length();
            shortestString = strArr[i];
        }
    }
    
    while(shortestString.length() != 0) {
        bool prefixExist = true;
        for(int i = 0; i < strArr.size(); i++) {
            if(!strArr[i].starts_with(shortestString)) { // Can use rfind(shortestString, 0) as well for C++ 11 Compatibility
                prefixExist = false;
                break;
            }
        }
        if(prefixExist) return shortestString;
        shortestString.pop_back();
    }
    
    return "Empty String";
}

int main() {
    int size;
    cin>>size;
    
    vector<string> strArr(size);
    for(int i = 0; i < size; i++) {
        cin>>strArr[i];
    }
    
    cout<<longestCommonPrefix(strArr);
}

// -------------------------------------------------- Problem 5 : Isomorphic Strings --------------------------------------------------------------->
// Problem Statement : Given two strings s and t, determine if they are isomorphic. Two strings s and t are isomorphic if the characters in s can be replaced to get t.
//                   : All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character, but a character may map to itself.

#include<iostream>
#include<map>
#include<set>
using namespace std;

bool isIsomorphic(string &s, string &t) {
    if(s.length() != t.length()) return false;
    
    map<char, char> hash;
    set<char> usedValues;
    
    for(int i = 0; i < s.length(); i++) {
        if(hash.find(s[i]) != hash.end()) {
            if(hash[s[i]] != t[i]) return false;
        }
        else {
            if(usedValues.count(t[i])) return false;
            hash[s[i]] = t[i];
            usedValues.insert(t[i]);    
        }
    }
    return true;
}

bool isIsomorphic2(string &s, string &t) {
    if(s.length() != t.length()) return false;
    
    unordered_map<char, char> hash;
    unordered_set<char> usedValues;
    
    for(int i = 0; i < s.length(); i++) {
        if(hash.find(s[i]) != hash.end()) {
            if(hash[s[i]] != t[i]) return false;
        }
        else {
            if(usedValues.count(t[i])) return false;
            hash[s[i]] = t[i];
            usedValues.insert(t[i]);    
        }
    }
    return true;
}

int main() {
    string s;
    string t;
    
    cin>>s>>t;
    cout<<isIsomorphic(s, t);
}

// -------------------------------------------------- Problem 6 : Rotate String --------------------------------------------------------------->
// Problem Statement : Given two strings s and goal, return true if and only if s can become goal after some number of shifts on s.
//                   : A shift on s consists of moving the leftmost character of s to the rightmost position.
//                   : For example, if s = "abcde", then it will be "bcdea" after one shift.

#include<iostream>
using namespace std;

void rotateString_Helper(string &str) {
    if(str.length() == 0) return;
    int firstChar = str[0];
    
    int i = 0;
    for(i = 0; i < str.length() - 1; i++) {
        str[i] = str[i+1];
    }

    str[i] = firstChar;
}

bool rotateString(string& s,string& goal){
    if(s.length() == 0 || goal.length() == 0) return false;
    
    int totalShifts = s.length();
    int shiftCount = 0;
    while(shiftCount < totalShifts) {
        if(s == goal) return true;
        rotateString_Helper(s);
        shiftCount++;
    }
    return false;
}

int main() {
    string str;
    string goal;
    
    cin>>str>>goal;
    cout<<rotateString(str, goal);
}

// -------------------------------------------------- Problem 7 : Valid Anagram --------------------------------------------------------------->
// Problem Statement : Given two strings s and t, return true if t is an anagram of s, and false otherwise.
//                   : An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

#include<iostream>
#include<map>
using namespace std;

bool validAnagram(string str1, string str2) {
    if(str1.length() == 0 || str2.length() == 0) return true;
    if(str1.length() != str2.length()) return false;

    map<char, int> hash1;
    map<char, int> hash2;
    
    for(int i = 0; i < str1.length(); i++) {
        hash1[str1[i]]++;
    }
    
    for(int i = 0; i < str2.length(); i++) {
        hash2[str2[i]]++;
    }
    
    return hash1 == hash2;
}

bool validAnagramBetter(string str1, string str2) {
    if(str1.length() == 0 || str2.length() == 0) return true;
    if(str1.length() != str2.length()) return false;

    unordered_map<char, int> hash;

    for(int i = 0; i < str1.length(); i++) {
        hash[str1[i]]++;
    }
    
    for(int i = 0; i < str2.length(); i++) {
        if(hash[str2[i]] == 0) return false;
        hash[str2[i]]--;
    }

    return true;
}

bool validAnagramOptimized(string str1, string str2) {
    if(str1.length() == 0 || str2.length() == 0) return true;
    if(str1.length() != str2.length()) return false;

    int charCount[256] = {0};
    for(int i = 0; i < str1.length(); i++) {
        charCount[str1[i]]++;
        charCount[str2[i]]--;
    }
    
    for(int i = 0; i < 256; i++) {
        if(charCount[i] != 0) return false;
    }
    
    return true;
}

int main() {
    string str1;
    string str2;
    
    cin>>str1>>str2;
    cout<<validAnagram(str1, str2);
}

// -------------------------------------------------- Problem 8 : Sort Characters by Frequency --------------------------------------------------------------->
// Problem Statement : You are given a string s. Return the array of unique characters, sorted by highest to lowest occurring characters.
//                   : If two or more characters have same frequency then arrange them in alphabetic order.

#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;

vector<char> freqChar(string &str)  {
    if(str.length() == 0) return {};
    
    unordered_map<char, int> hash;
    for(char ch  : str) {
        hash[ch]++;
    }
    
    vector<pair<int, char>> temp;
    for(auto [character, count] : hash) {
        temp.push_back({-count, character});
    }
    
    sort(temp.begin(), temp.end());
    
    vector<char> result;
    for(auto it : temp) {
        result.push_back(it.second);
    }
    return result;
}

vector<char> freqCharOptimized(string &str)  {
    if(str.length() == 0) return {};
    
    int countChars[256] = {0};
    for(int i = 0; i < str.length(); i++) {
        countChars[str[i]]++;
    }
    
    vector<pair<int, char>> temp;
    for(int i = 0; i < 256; i++) {
        char character = i;
        int count = countChars[i];
        
        if(count > 0) temp.push_back({-count, character});
    }
    
    sort(temp.begin(), temp.end());
    
    vector<char> result;
    for(auto it : temp) {
        result.push_back(it.second);
    }
    return result;
}

int main() {
    string str;
    cin>>str;
    
    vector<char> ans = freqChar(str);
    for(char ch : ans) {
        cout<<ch<<" ";
    }
}
