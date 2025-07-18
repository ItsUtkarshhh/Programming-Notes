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
// Note : We'll use C++ strings for solving this. Try re-solving with C-style strings during revision for better practice.
// Problem Statement : To determine if a string is a palindrome, it depends on what we choose to consider as valid characters.
//                   : For this problem, we will : Only consider alphanumeric characters (i.e., letters and digits)
//                                               : Ignore case sensitivity
//                                               : Remove all other characters like spaces, punctuation, or symbols before checking
//                   : For example, "Noon" or "A man, a plan, a canal: Panama" will be treated as valid palindromes after cleaning and normalization.
// Approach 1 (Reverse & Check) : Clean the string, convert it to lowercase, reverse it, and compare it with the cleaned original. If both match, it's a palindrome.
// Approach 2 (Compare end to end) : Use two pointers (start and end), move inward while skipping non-alphanumeric characters, and compare characters in a case-insensitive way. If all characters match, return true; otherwise, return false.
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
// Approach 1 (Using String Methods) : Keep checking if strSub exists in strMain using .find().
//                                   : If found, erase it using .erase().
//                                   : Repeat until strSub is no longer found.
//                                   : Important Notes : size_t : size_t is a special unsigned integer type used in C++ to represent sizes, lengths, or indexes.
//                                                              : It's defined to be large enough to hold the maximum size any object (like arrays, strings, etc.) can have. It's used with many functions like string.length(), string.find(), etc.
//                                                              : Unsigned means it can’t be negative. Defined as a typedef in the <cstddef> header (automatically included by many standard headers like <string>).
//                                                              : Under the hood : On 32-bit systems: it’s usually unsigned int (4 bytes).
//                                                                               : On 64-bit systems: it’s usually unsigned long long or unsigned long (8 bytes).
//                                                     : string::npos : std::string::npos is a constant used to represent "no position" — or simply, "not found".
//                                                                    : It is returned by methods like .find() when the substring is not found in the main string.
//                                                                    : Internally : static const size_t npos = -1; - Since size_t is unsigned, assigning -1 to it becomes the maximum possible value for that type. On a 64-bit system: npos = 18446744073709551615
//                                                     : Why not assign .find() result to an int? : Suppose a case : std::string str = "hello"; int pos = str.find("xyz"); // Dangerous!
//                                                                                                                 : The .find("xyz") returns std::string::npos because "xyz" is not found.
//                                                                                                                 : std::string::npos is defined as size_t(-1), which means it holds a very large unsigned value (e.g., 4294967295 on 32-bit systems or 18446744073709551615 on 64-bit).
//                                                                                                                 : Now, if you assign this large size_t value to a signed int, the value overflows because : int is a smaller type than size_t (especially on 64-bit systems).
//                                                                                                                                                                                                           : int is signed, so it can represent negative numbers but only up to a certain maximum.
//                                                                                                                 : Because of this : The value wraps around due to overflow. The large unsigned value gets interpreted as -1 in the signed int using two's complement representation.
//                                                                                                                 : This can lead to bugs. For example : str.erase(pos, 3); - You are trying to erase from index -1! (invalid access)
//                                   : Time Complexity : Worst case: O(k × N), where k = number of times strSub appears and N = length of strMain. Because each .find() and .erase() can take O(N).
//                                   : Space Complexity : O(1) extra space (in-place operation).
// Approach 2 (Using idea of Stack) : Process : Idea is to simulate string building as we iterate over strMain character-by-character!
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

// Question 10 : Check whether s1 contains a substring that is a permutation (i.e., rearrangement) of string s2. If such a substring exists, return true; otherwise, return false."
// Approach 1 (Brute Force) : A very basic method is to generate all possible permutations of the string s1, and then check if any of those permutations exist as a substring in s2 using the .find() method.
//                          : This approach is correct, but highly inefficient — since generating all permutations takes a lot of time and memory (around n! for a string of length n). Then, checking each permutation in s2 adds to the time as well. So, this method is not suitable for large inputs.
//                          : Time Complexity : O(n! × m), where n is the length of s1, and m is the length of s2. Generating permutations: O(n!) or roughly O(2ⁿ) as you noted. Comparing each with substrings of s2.
//                          : Space Complexity : O(n!) for storing permutations.
// Approach 2 (Sliding window + Hashmaps) : Idea : If s2 is of length k, then any permutation of s2 must also be of length k. So, you slide a window of size k over s1 and check whether the frequency of characters in that window matches with the frequency of s2.
//                                               : Build frequency map of s2 : This stores how many times each character occurs in s2.
//                                               : Build initial frequency map of first k characters of s1
//                                               : Compare both maps : Maps in C++ (std::map) support == comparison — which compares both keys and values. So if the current window is a permutation, this will be true. (Can only be done for ordered maps)
//                                               : Slide the window over s1 : Now, for each character after the first k in s1, slide the window forward by : Adding the new character entering the window
//                                                                                                                                                         : Removing the character that just left the window
//                                                                                                                                                         : And check again if the updated map matches freq2.
//                                                                                                                                                         : If loop ends and no match found : return false;
//                                        : Time Complexity : Creating freq2 → O(k), First window setup → O(k), Sliding window → O(n - k), Map comparison per slide → O(26) (assuming lowercase only) or up to O(K) (K = distinct characters), So, total time: O(n * K), where K = distinct characters (typically ≤ 26 for lowercase).
//                                        : Space Complexity : O(K) for each map (where K = number of unique characters)
//                                        : This approach can be optimal for most general cases! but may not be optimal for "lowercase only" case, for that we can use vectors!
// Approach 3 (Better Approach 2) : Idea : Since we are only dealing with lowercase English letters (or can convert everything to lowercase), we can use a fixed-size array/vector of size 26 to track character frequencies instead of map<char, int>.
//                                       : This makes the comparison and updates faster and memory-efficient, as all indices are predefined.
//                                       : Create a frequency vector of s1. This stores the count of each character in s1.
//                                       : Initialize window frequency vector from s2 (first window of size s1.length())
//                                       : Compare freq1 and freq2. If not equal, start sliding the window.
//                                       : Slide the window : For every index i from s1.length() to s2.length() : Add s2[i] to the frequency, Remove s2[i - s1.length()] from the frequency.
//                                       : If no match found after all windows : return false;
//                                : Time Complexity : O(n) where n = s2.length() - Each character is added and removed from the frequency array exactly once.
//                                : Space Complexity : O(1) - Two vectors of size 26 = constant space.
//                                : Optimal solution for when both strings contains lowercase letters! - There's always some small optimization you can do in this, but it won't change the core of this approach!
// Approach 1 (Brute Force) :
#include<iostream>
#include<string>
#include<unordered_set>
#include<algorithm>
#include<map>
#include<vector>
using namespace std;

bool checkPermutations1(string s1, string s2) {
    sort(s2.begin(), s2.end()); // Sorting for next_permutation
    unordered_set<string> seen; // To avoid duplicate permutations

    do {
        if (seen.find(s2) != seen.end()) continue; // Skip duplicates
        seen.insert(s2);
        if (s1.find(s2) != string::npos) return true;
    } while (next_permutation(s2.begin(), s2.end()));

    return false;
}

// Approach 2 (Sliding window + Hashmaps) :
bool checkPermutations2(string s1, string s2) {
    int k = s2.length();
    map<char,int> freq1;
    map<char,int> freq2;
    for(int i = 0; i < k; i++) freq2[s2[i]]++;
    
    int index = 0;
    for(index = 0; index < k; index++) freq1[s1[index]]++;

    if(freq1 == freq2) return true; // You can do this only when maps are not unordered!
    while(index < s1.length()) {
        freq1[s1[index]]++;
        freq1[s1[index - k]]--;
        if (freq1[s1[index - k]] == 0) freq1.erase(s1[index - k]); // Clean up the map to keep it minimal
        if(freq1 == freq2) return true;
        index++;
    }
    return false;
}

// Approach 3 (Better Approach 2) :
bool checkPermutations3(string s1, string s2) {
    if (s1.length() < s2.length()) return false;

    vector<int> freq1(26, 0), freq2(26, 0);

    for (char c : s2) freq2[c - 'a']++;
    for (int i = 0; i < s2.length(); i++) freq1[s1[i] - 'a']++;

    if (freq1 == freq2) return true;

    for (int i = s2.length(); i < s1.length(); i++) {
        freq1[s1[i] - 'a']++;
        freq1[s1[i - s2.length()] - 'a']--;
        if (freq1 == freq2) return true;
    }

    return false;
}

int main() {
    string str1, str2;
    cin>>str1>>str2;
    if(checkPermutations3(str1, str2)) cout<<"True: A permutation exists in s1."<<endl;
    else cout<<"False: No permutation found."<<endl;
}

// Question 11 : Removing all adjacent duplicates! You are given a string s consisting of lowercase English letters. A duplicate removal consists of choosing two adjacent and equal letters and removing them.
//             : We repeatedly make duplicate removals on s until we no longer can. Return the final string after all such duplicate removals have been made. It can be proven that the answer is unique.
