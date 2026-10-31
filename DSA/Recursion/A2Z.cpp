// ------------------------------------------- Basic Recursion Problems ------------------------------------------------------------------>
// -------------------------------------- Problem 1 : Sum of First N Numbers ------------------------------------------------------------------>
// Problem 1 : Given an integer N, return the sum of first N natural numbers. Try to solve this using recursion.

#include<iostream>
using namespace std;

int sumToN(int num) {
    if(n == 0 || n == 1) return n;
    return n + sumToN(n - 1);
}

int main() {
    int n;
    cin>>n;
    cout<<sumToN(n);
}

// -------------------------------------- Problem 2 : Factorial of a Given Number ------------------------------------------------------------------>
// Problem 2 : Given an integer n, return the factorial of n.
//           : Factorial of a non-negative integer, is the multiplication of all integers smaller than or equal to n (use 64-bits to return answer).

#include<iostream>
using namespace std;

int factorial(int n) {
    if(n == 1 || n == 0) return 1;
    return n * factorial(n - 1);
}

int main() {
    int n;
    cin>>n;
    cout<<factorial(n);
}

// -------------------------------------- Problem 3 : Sum of Array Elements II ------------------------------------------------------------------>
// Problem 3 : Given an array nums, find the sum of elements of array using recursion.

#include<iostream>
#include<vector>
using namespace std;

int sumOfArrayElements(vector<int> &arr, int start) {
    if(start == arr.size()) return 0;
    return arr[start] + sumOfArrayElements(arr, start + 1);
}

int sumOfArrayElements2(vector<int> &arr, int start) {
    if(arr.empty()) return 0;
    
    int lastElemnt = arr.back();
    arr.pop_back();
    
    return lastElemnt + sumOfArrayElements2(arr);
}

int main() {
    int size;
    cin>>size;
    
    vector<int> v(size);
    for(int i = 0; i < size; i++) {
        cin>>v[i];
    }
    
    int start = 0;
    cout<<sumOfArrayElements(v, start)<<endl;
    cout<<sumOfArrayElements2(v, start)<<endl;
}

// -------------------------------------- Problem 4 : Reverse a String I ------------------------------------------------------------------>
// Problem Statement : Given an input string as an array of characters, write a function that reverses the string.

#include<iostream>
#include<vector>
using namespace std;

void reverseString_Helper(vector<char> &s, int start, int end) {
    if(start >= end) return;
    swap(s[start], s[end]);
    start++; end--;
    reverseString_Helper(s, start, end);
}

vector<char> reverseString(vector<char>& s){
    reverseString_Helper(s, 0, s.size() - 1);
    return s;
}

int main() {
    int size;
    cin>>size;
    
    vector<char> arr(size);
    for(int i = 0; i < arr.size(); i++) {
        cin>>arr[i];
    }
    
    vector<char> result = reverseString(arr);
    for(int i = 0; i < result.size(); i++) {
        cout<<result[i]<<" ";
    }
}

// -------------------------------------- Problem 5 : Check if String is Palindrome or Not ------------------------------------------------------------------>
// Problem Statement : Given a string s, return true if the string is palindrome, otherwise false.
//                   : A string is called palindrome if it reads the same forward and backward.

#include<iostream>
using namespace std;

bool palindromeCheck_Helper(string &s, int start, int end) {
    if(start >= end) return true;
    
    if(s[start] != s[end]) return false;
    return palindromeCheck_Helper(s, start + 1, end - 1);
}

bool palindromeCheck(string& s){
    return palindromeCheck_Helper(s, 0, s.length() - 1);
}

int main() {
    string str;
    cin>>str;
    
    cout<<palindromeCheck(str);
}

// -------------------------------------- Problem 6 : Check if a Number is Prime or Not ------------------------------------------------------------------>
// Problem Statement : Given an integer num, return true if it is prime otherwise false.
//                   : A prime number is a number that is divisible only by 1 and itself.

#include<iostream>
#include<math.h>
using namespace std;

bool checkPrime_Helper(int num, int i) {
    if(i > sqrt(num)) return true;
    if(num % i == 0) return false;
    return checkPrime_Helper(num, i + 1);
}

bool checkPrime(int num){
    if(num < 2) return false;
    return checkPrime_Helper(num, 2);
}

int main()  {
    int n;
    cin>>n;
    
    cout<<checkPrime(n);
}

// -------------------------------------- Problem 7 : Reverse an array 2 ------------------------------------------------------------------>
// Problem Statement : Given an array nums of n integers, return reverse of the array.

#include<iostream>
#include<vector>
using namespace std;

void reverseArray_Helper(vector<int> &arr, int start, int end) {
    if(start >= end) return;
    swap(arr[start], arr[end]);
    reverseArray_Helper(arr, start + 1, end - 1);
}

vector<int> reverseArray(vector<int>& nums){			
    if(nums.empty()) return {};
    reverseArray_Helper(nums, 0, nums.size() - 1);
    return nums;
}

int main() {
    int size;
    cin>>size;

    vector<int> v(size);
    for(int i = 0; i < size; i++) {
        cin>>v[i];
    }

    vector<int> result = reverseArray(v);
    for(int i = 0; i < result.size(); i++) {
        cout<<result[i]<<" ";
    }
}

// -------------------------------------- Problem 8 : Check if the Array is Sorted II ------------------------------------------------------------------>
// Problem Statement : Given an array nums of n integers, return true if the array nums is sorted in non-decreasing order or else false.

#include<iostream>
#include<vector>
using namespace std;

bool isSorted_Helper(vector<int> &nums, int start) {
    if(start >= nums.size() - 1) return true;
    
    if(nums[start] > nums[start + 1]) return false;
    return isSorted_Helper(nums, start + 1);
}

bool isSorted(vector<int>& nums){
    if(nums.empty()) return true;
    return isSorted_Helper(nums, 0);
}

int main() {
    int size;
    cin>>size;
    
    vector<int> v(size);
    for(int i = 0; i < size; i++) {
        cin>>v[i];
    }
    
    cout<<isSorted(v);
}

// -------------------------------------- Problem 9 : Sum of Digits in a Given Number ------------------------------------------------------------------>
// Problem Statement : Given an integer num, repeatedly add all its digits until the result has only one digit, and return it.

#include<iostream>
using namespace std;

int addDigits(int num) {
    int val = num;
    while(val >= 0) {
        int sum = 0;
        while(val != 0) {
            int digit = val % 10;
            sum += digit;
            val = val / 10;
        }
        val = sum;
    }
    return val;
}

int sumDigits(int num) {
    if(num == 0) return 0;
    return (num % 10) + sumDigits(num / 10);
}

int addDigitsRec(int num) {
    if(num < 10) return num;
    return addDigitsRec(sumDigits(num));
}

int main() {
    int n;
    cin>>n;
    cout<<addDigitsRec(n);
}

// -------------------------------------- Problem 10 : Fibonacci Number ------------------------------------------------------------------>
// Problem Statement : The Fibonacci numbers, commonly denoted F(n) form a sequence, called the Fibonacci sequence, such that each number is the sum of the two preceding ones, starting from 0 and 1. That is,

#include<iostream>
using namespace std;

int fib(int n) {
    if(n == 0 || n == 1) return n;
    return fib(n-1) + fib(n-2);
}

int main() {
    int n;
    cin>>n;
    cout<<fib(n);
}