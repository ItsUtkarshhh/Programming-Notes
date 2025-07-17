// --------------------------------------------------------- Part 2 : Strings Based Questions! ----------------------------------------------------------------->
// Question 1 : Find the length of the character array & a string!
// Approach : Simply iterate through the array, and keep counting the number of characters and when you encounter \0 break the loop!
#include<iostream>
using namespace std;

int lenOfString1(const char* arr) {
    int count = 0;
    for(int i = 0; arr[i] != '\0'; i++) {
        count++;
    }
    return count;
}

int lenOfString2(char arr[]) {
    int count = 0;
    for(int i = 0; arr[i] != '\0'; i++) {
        count++;
    }
    return count;
}

int lenOfCharArray3(char* arr, int n) {
    int count = 0;
    for(int i = 0; i < n; i++) {
        count++;
    }
    return count;
}

int main() {
    int n;
    cin>>n;
    char* arr1 = new char[n];
    for(int i = 0; i < n; i++) {
        cin>>arr1[i];
    }
    cout<<"Length : "<<lenOfCharArray3(arr1, n)<<endl; // This approach doesn't make sense as you have input length and then printed it again by doing some operations.
    cout<<"Size of character array (Pointer) : "<<sizeof(arr1)<<endl;
    
    cout<<endl;
    
    char arr2[] = {'U', 'T', 'K', 'A', 'R', 'S', 'H'};
    cout<<"Length : "<<lenOfCharArray3(arr2, 7)<<endl;
    cout<<"Size of character array : "<<sizeof(arr2)<<endl;
    
    cout<<endl;
    
    char arr3[7] = {'U', 'T', 'K', 'A', 'R', 'S', 'H'};
    cout<<"Length : "<<lenOfCharArray3(arr3, 7)<<endl;
    cout<<"Size of character array : "<<sizeof(arr3)<<endl;
    
    cout<<endl;
    
    char str1[] = "Utkarsh";
    cout<<"Length : "<<lenOfString2(str1)<<endl;
    cout<<"Size of string : "<<sizeof(str1)<<endl;
    
    cout<<endl;
    
    char str2[] = {'U', 'T', 'K', 'A', 'R', 'S', 'H', '\0'};
    cout<<"Length : "<<lenOfString2(str2)<<endl;
    cout<<"Size of string : "<<sizeof(str2)<<endl;
    
    cout<<endl;

    // char* str3 = "Utkarsh"; - Technically Valid (but with a Warning). Compiles in many C++ compilers. But generates a warning in ISO C++ because : It allows modification of a string literal through a non-const pointer, which is undefined behavior.
    const char* str3 = "Utkarsh";
    cout<<"Length : "<<lenOfString1(str3)<<endl;
    cout<<"Size of string : "<<sizeof(str3)<<endl;
}

// Question 2 : Reverse a string
// Approach : Simply input a string - C/C++ style. And iterate over it and swap!
//          : If C Style strings : Keep start at 0 & end at size - 2. And start swapping!
//          : if C++ Style strings : Keep start at 0 & end at size - 1. And start swapping! - Less complex
#include<iostream>
using namespace std;

char* reverseString(char* str, int size) { // Can also use void here! as char* str will already change the original string str.
    int i = 0; int j = size - 2;
    while(i < j) {
        swap(str[i], str[j]);
        i++; j--;
    }
    return str;
}

int main() {
    int n;
    cin>>n;
    char* str = new char[n + 1];
    for(int i = 0; i < n; i++) {
        cin>>str[i];
    }
    str[n] = '\0';
    char* revString = reverseString(str, n + 1);
    // for(int i = 0; i <= n; i++) {
    //     cout<<revString[i];
    // }
    cout<<revString;
}

// Question 3 : Check for a palindrome
// Problem Statement : To check a string is a palindrome, it totally depends, upto what extent we are ready to consider a string a palindrome.
//                   : For example : We will consider to check if a string is palindrome or not if it contains only alphabets & numbers, if other characters are present we will simply remove them and find our valid string, and then check palindrome.
//                                 : Are we considering a strings like "Noon" a palindrome or not.
//                                 : Or, are we ready to keep all the characters inside the string, whether they are any 255 characters, for a valud string to check palindrome.
//                   : As of for this question, we will be considering any string contains big/small alphabets & numbers, as a valid string for palindrome check, if other characters are there just remove them. Also our palindrome check will not be case-sensitive.
// Note : Will be using C++ string now onwards! Keep re-solve questions while revision using C style strings! But for learning purpose will use C++ strings!
// Approach 1 (Reverse & Check) : Simply reverse the string, and compare it with the original string! If true then Palindrome, otherwise not. Here you can apply case-insensitivity.
// Approach 2 (Compare end to end) : Simply start two pointers, start & end. And compare each character, if at any given moment they turn out to be unequal, simply return false, else true. Here you can apply case-insensitivity.
#include<iostream>
#include<string>
using namespace std;

// Modifications in string to meet required  results
char toLowercase(char ch) {
    if(ch >= 'A' && ch <= 'Z') return ch - 'A' + 'a';
    else return ch;
}

bool charValidity(char ch) {
    if(ch >= 'A' && ch <= 'Z' || ch >= 'a' && ch <= 'z' || ch >= '0' && ch <= '9') return true;
    else return false;
}

string stringValidity(string str) {
    string result = "";
    for(int i = 0; i < str.length(); i++) {
        if(charValidity(str[i])) {
            result.push_back(str[i]);
        }
    }
    return result;
}

// Approach 1 (Reverse & Check) :
bool checkPalindrome1(string str) {
    string valString = stringValidity(str);
    for(int i = 0; i < valString.length(); i++) {
        valString[i] = toLowercase(valString[i]);
    }

    string revString = "";
    for(int i = valString.length() - 1; i >= 0; i--) { // You can use swap() also, this is just to show another way that this technique is also valid.
        revString.push_back(valString[i]);
    }

    return valString == revString;
}

// Approach 2 (Compare end to end) :
bool checkPalindrome2(string str) {
    string valString = stringValidity(str);
    int start = 0; int end = valString.length() - 1;
    while(start <= end) {
        if(toLowercase(valString[start]) != toLowercase(valString[end])) {
            return false;
        }
        start++; end--;
    }
    return true;
}

int main() {
    string str1;
    getline(cin, str1); // For full line as input
    // cin>>str1; // For only word as input
    if(checkPalindrome1(str1)) cout<<"Valid Palindrome!";
    else cout<<"Invalid Palindrome!";

    cout<<endl;

    if(checkPalindrome2(str1)) cout<<"Valid Palindrome!";
    else cout<<"Invalid Palindrome!";
}

// Question 4 : Find the maximum occuring characters in a string!
// Approach 1 (Brute Force) : Traverse the whole string, and use an array of size 256, to store occurence of all the characters based on their ASCII value! and then accessing them within the array based on ASCII value.
// Approach 2 (Better Approach) : Rather than using array of size 255, use a map! and directly access these elements.
// Note : '\0' is the null character (ASCII value 0) used to terminate C-style strings. But its behavior varies depending on how it's used.
//      : Behavior in Different Scenarios : Keyboard Input (e.g., getline(cin, str) or cin) : You cannot type a real '\0' from a keyboard. Typing \0 results in two characters: '\\' and '0', not a null character.
//                                        : std::string Handling : std::string can store '\0' like any normal character. It doesn't terminate the string. str.length() includes '\0' in its count.
//                                        : C-style Strings (char[], char*) : '\0' terminates the string. Any characters after it are ignored. strlen() stops counting at '\0'.
//                                        : Reading from File/Buffer : If a file or memory buffer includes '\0', std::string will handle it properly. But C-style string will truncate after '\0'.
//                                        : Literal Input Like "\\0" : It's not null character; it's just two characters '\\' and '0'. Hence stored literally as "\\0" in the string.
// Approach 1 (Brute Force) :
#include<iostream>
#include<string>
using namespace std;

char maxOccurence(string str) {
    int count[256] = {0};
    for(int i = 0; i < str.length(); i++) {
        int asciiIndex = str[i];
        count[asciiIndex]++;
    }
    int maxCount = 0;
    int asciiIndex = 0;
    for(int i = 0; i < 256; i++) {
        if(count[i] > maxCount) {
            maxCount = count[i];
            asciiIndex = i;
        }
    }
    // char maxOccChar = '\0' + asciiIndex; // Not a good practice
    // return maxOccChar;

    return (char)asciiIndex;
}

int main() {
    string str1;
    getline(cin, str1);
    cout<<"Maximum occuring character : "<<maxOccurence(str1);
}

// Approach 2 (Better Approach) :
#include<iostream>
#include<map>
#include<string>
using namespace std;

char maxOccurence(string str) {
    map<char,int> countMap;
    for(int i = 0; i < str.length(); i++) {
        countMap[str[i]]++;
    }
    int maxCount = 0;
    char maxOccur = '\0'; // Default character. As while user input, using keyboard it is not possible to enter \0, as program won't allow it, it will treat \ & 0 as two different characters.
    for(const auto& it : countMap) { // const : For better security check from un-intended modification in values.
        if(it.second > maxCount) {
            maxCount = it.second;
            maxOccur = it.first;
        }
    }
    return maxOccur;
}

int main() {
    string str1;
    getline(cin, str1);
    cout<<"Maximum occuring character : "<<maxOccurence(str1);
}

// Question 8 : You have a line of text and you have to replace all the spaces with the @40.
// Approach 1 (Brute Force) : Simply another empty string, and keep inserting the original string characters into this new string, and whenver you see a space, insert "@40" into it.
// Approach 2 (Using <sstream> header) : ostringstream stands for Output String Stream, part of the <sstream> library in C++. It allows you to treat a string like an output stream (like cout) and append to it efficiently.
//                                     : Example : ostringstream oss; oss << "hello"; // like cout, but to a string, oss << "world"; string result = oss.str(); // "helloworld"
//                                     : Why prefer ostringstream over string +=? : When you use += or push_back() on a string, Every time you append, the compiler might need to resize memory.
//                                                                                : For big strings, this results in many memory re-allocations and copies behind the scenes.
//                                                                                : It can lead to O(n²) time in the worst case.
//                                     : On the other hand, ostringstream : Internally manages buffer memory more efficiently
//                                                                        : Does fewer reallocations and memory copies
//                                                                        : Offers syntax similar to cout
//                                                                        : Results in better performance for large or heavy string manipulations
// Approach 1 (Brute Force) :
#include<iostream>
#include<string>
using namespace std;

string modifyString(string str) {
    string temp = "";
    for(int i = 0; i < str.length(); i++) {
        if(str[i] == ' ') {
            temp += "@40"; // Or push '@' '4' '0' three times into the temp.
        }
        else {
            temp.push_back(str[i]); // alternatively : temp += str[i]; will also work.
        }
    }
    return temp;
}

int main() {
    string str1;
    getline(cin, str1);
    cout<<"Maximum occuring character : "<<modifyString(str1);
}

// Approach 2 (Using <sstream> header) :
#include<iostream>
#include<string>
#include<sstream>
using namespace std;

string modifyString(string str) {
    ostringstream oss; // creates a string stream object
    for(int i = 0; i < str.length(); i++) {
        if(str[i] == ' ') {
            oss << "@40";
        }
        else {
            oss << str[i];
        }
    }
    return oss.str();  // converting the stream to a final string
}

int main() {
    string str1;
    getline(cin, str1);
    cout<<"Maximum occuring character : "<<modifyString(str1);
}

// Question 9 : Remove all the occurences of a sub string in a parent string!
// Apprach 1 (Using string methods) : Look inside the string (str) to see if the substring (substr) exists.
//                                  : If it does exist, find its position/index in the main string.
//                                  : Erase that substring from the main string.
//                                  : Repeat this process until no more such substrings are found.
//                                  : Note : What is size_t : size_t is an unsigned integer type.
//                                                          : It is guaranteed to be big enough to represent the size of any object in memory, so it is widely used in C++ for sizes, indexes, and lengths (e.g., in strings, arrays, containers).
//                                                          : Under the hood : On 32-bit systems: it’s usually unsigned int (4 bytes).
//                                                                           : On 64-bit systems: it’s usually unsigned long long or unsigned long (8 bytes).
//                                                                           : "typedef unsigned long size_t;" // simplified version
//                                                          : Defined as a typedef in the <cstddef> header (automatically included by many standard headers like <string>).
//                                          : What is string::npos : npos is a static constant member of the std::string class, and it stands for "not position" (i.e., invalid position).
//                                                                 : Its value is : static const size_t npos = -1;
//                                                                 : Since size_t is unsigned, assigning -1 to it results in the maximum possible value for that type.
//                                                                 : Example: On a 64-bit system, size_t(-1) = 18446744073709551615.
//                                  : Why using int instead of size_t is unsafe : When you write : int pos = str.find("abc");
//                                                                              : If "abc" is not found, str.find() returns string::npos, which is a very large unsigned value.
//                                                                              : This gets converted to a negative number (usually -1) due to signed-unsigned conversion when assigned to int.
//                                                                              : Now imagine you try : str.erase(pos, 3); // pos is -1 here! This would likely cause a runtime error or undefined behavior, because you're accessing an invalid index.
//                                  : Note : Can any string be that long to reach npos? : No. Physically impossible.
//                                                                                      : Even the most powerful systems can't allocate memory for a string that's several GBs or exabytes long, which would be required to hit an index like 4294967295.
//                                                                                      : So in practical usage: npos is always greater than any real string length.
//                                  : Efficiency check : If, N = length of strMain & M = length of strSub.
//                                                     : Each call to find() takes O(N) in the worst case (linear search). Each call to erase() may also take up to O(N) since strings in C++ are contiguous and need shifting after erasing characters. Suppose there are k occurrences of strSub in strMain.
//                                                     : Time Complexity : O(k * N) - Each find + erase may take O(N), repeated k times. In the worst case where strSub occurs repeatedly and overlaps are minimal, this could approach O(N^2).
//                                                     : Space Complexity : O(1) (excluding input and output) - In-place operation, as strMain is modified directly.
// Approach 2 (Using idea of stack) : Process : Idea is to simulate string building as we iterate over strMain character-by-character!
//                                            : At each step, push characters to a stack (or simply build a new string).
//                                            : After every push, check whether the last few characters on the stack match the strSub.
//                                            : If they do, we pop them (i.e., remove them).
//                                            : Otherwise, continue.
//                                  : This is efficient because : You go through the string only once → O(n)
//                                                              : No repeated searching, slicing, or reallocation like .find() + .erase()
//                                                              : Works better for large inputs.
// Approach 1 (Using string methods) : Brute Force
#include<iostream>
#include<string>
using namespace std;

string removeOccurence1(string strMain, string strSub) {
    size_t pos = strMain.find(strSub);
    while(pos != string::npos) {
        strMain.erase(pos, strSub.length());
        pos = strMain.find(strSub);
    }
    return strMain;
}

string removeOccurence2(string strMain, string strSub) { // Even though npos is the largest possible value — but in theory, comparing with .length() might seem safe, but using != npos is semantically correct.
    while(strMain.find(strSub) < strMain.length()) {
        strMain.erase(strMain.find(strSub), strSub.length());
    }
    return strMain;
}

int main() {
    string strMain;
    cin>>strMain;
    string strSub;
    cin>>strSub;
    string result = removeOccurence1(strMain, strSub);
    // string result = removeOccurence2(strMain, strSub);
    if(result != "") cout<<result;
    else cout<<"Empty string";
}

// Approach 2 (Using idea of stack) : Optimal Solution
#include<iostream>
#include<string>
using namespace std;

string removeOccurence(string strMain, string strSub) {
    string res = "";
    int subLen = strSub.length();

    for(int i = 0; i < strMain.length(); i++) {
        res += strMain[i]; // Simulate stack push

        // If last part of res matches strSub, remove it
        if(res.size() >= subLen && res.substr(res.size() - subLen) == strSub) {
            res.erase(res.size() - subLen); // Simulate stack pop
        }
    }
    return res.empty() ? "Empty String" : res;
}

int main() {
    string strMain;
    cin>>strMain;
    string strSub;
    cin>>strSub;
    string result = removeOccurence(strMain, strSub);
    if(result != "") cout<<result;
    else cout<<"Empty string";
}