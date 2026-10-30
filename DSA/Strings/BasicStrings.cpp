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

int largeOddNum(string &str) {
    if(str.length() == 0) return -1;

    int finalNumString = "";
    for(int i = str.length() - 1; i >= 0; i--) {
        int digit = str[i] - '0';
        if(digit % 2 != 0)
    }
}

int main() {
    string s;
    cin>>s;
    cout<<palindromeChecker(s);
}