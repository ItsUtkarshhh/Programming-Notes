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
// Approach : Will be using C++ string now onwards! Keep re-solve questions while revision using C style strings! But for learning purpose will use C++ strings!
//          : 