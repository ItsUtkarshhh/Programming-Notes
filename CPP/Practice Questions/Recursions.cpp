// Question 1 : Print a name n times using recursion!
#include<iostream>
#include<string>
using namespace std;

void printName(int n, string name) {
    if(n == 0) return;
    cout<<name<<" ";
    n--;
    printName(n, name);
}

int main() {
    int n;
    cout<<"Enter times : ";
    cin>>n;
    string name;
    cout<<"Enter name : ";
    cin>>name;
    cout<<"Execution : ";
    printName(n, name);
}

// Question 2 and 3 : Print 1 to N and N to 1 using recursion!
#include<iostream>
using namespace std;

void printCounting1toN(int n) {
    if(n == 0) return;
    printCounting1toN(n-1);
    cout<<n<<" ";
}

void printCountingNto1(int n) {
    if(n == 0) return;
    cout<<n<<" ";
    printCountingNto1(n-1);
}

int main() {
    int n;
    cout<<"Enter n : ";
    cin>>n;
    printCounting1toN(n);
    cout<<endl;
    printCountingNto1(n);
}

// Question 4 : Sum of first N numbers! TC : O(n) and SC : O(n) - Not always recursion is the best approach, like here SC is O(n), instead if you just simply return n*(n+1)/2, then the SC : O(1).
#include<iostream>
using namespace std;

int printSum(int n) {
    if(n == 0) return 0;
    return n + printSum(n-1);   
}

int main() {
    int n;
    cout<<"Enter n : ";
    cin>>n;
    cout<<printSum(n);
}

// Question 5 : Factorial of N! TC : O(n) and SC : O(n) - Again without recursion using a for loop it would have saved alot of space! where the SC : O(1).
#include<iostream>
using namespace std;

int printFact(int n) {
    if(n == 0) return 1;
    return n * printFact(n-1);   
}

int main() {
    int n;
    cout<<"Enter n : ";
    cin>>n;
    cout<<printFact(n);
}

// Question 6 : Reverse and Array!
#include<iostream>
#include<vector>
using namespace std;

void reverseArray(vector<int> &v, int start, int end) {
    if(start < end) {
        swap(v[start], v[end]);
        reverseArray(v, start + 1, end - 1);
    }
}

int main() {
    int n;
    cout<<"Enter size of array : ";
    cin>>n;
    vector<int> arr(n);
    for(int i = 0; i<n; i++) {
        cin>>arr[i];
    }
    reverseArray(arr, 0, n-1);
    for(int i = 0; i<n; i++) {
        cout<<arr[i]<<" ";
    }
}

// Question 7 : Check if the given String is Palindrome or not!
#include<iostream>
#include<string>
using namespace std;

bool checkPalindrome(string str, int start, int end) {
    if(start >= end) {
        return true;
    }
    if(str[start] != str[end]) {
        return false;
    }
    return checkPalindrome(str, start + 1, end - 1);
}

int main() {
    string str;
    cin>>str;
    if(checkPalindrome(str, 0, str.length() - 1)) {
        cout<<"Palindome!";
    }
    else {
        cout<<"Not a palindrome!";
    }
}

// Question 7 : Print Fibonacci Series up to Nth term, 0 1 1 2 3 5 8 13 21 34...
// Using Position!
#include<iostream>
using namespace std;

int printFib1(int pos) {
    int Pos1 = 0;
    int Pos2 = 1;
    if(pos == 1) {
        return 0;
    }
    if(pos == 2) {
        return 1;
    }
    return printFib1(pos - 1) + printFib1(pos - 2);
}

int main() {
    int pos;
    cin>>pos;
    cout<<printFib1(pos);
}

// Using Index!
#include<iostream>
using namespace std;

int printFib2(int index) {
    int index0 = 0;
    int index1 = 1;
    if(index == 0 || index == 1) {
        return index;
    }
    return printFib2(index - 1) + printFib2(index - 2);
}

int main() {
    int index;
    cin>>index;
    cout<<printFib2(index);
}

// Printing the series till Nth term!
#include <iostream>
using namespace std;

int printFib3(int pos) {
    if (pos == 0) {
        return 0;
    }
    if (pos == 1) {
        return 1;
    }
    return printFib3(pos - 1) + printFib3(pos - 2);
}

int main() {
    int N;
    cout << "Enter N: ";
    cin >> N;

    cout << "Fibonacci Series up to " << N << " terms: ";
    for (int i = 0; i < N; ++i) {
        cout << printFib3(i) << " ";
    }
    return 0;
}

// Printing the series till a particular value!
#include <iostream>
using namespace std;

void printFib4(int a, int b, int X) {
    if (a > X) return; // base condition: stop when a crosses X

    cout << a << " "; // print current Fibonacci number
    printFib4(b, a + b, X); // move to next
}

int main() {
    int X;
    cout << "Enter value X: ";
    cin >> X;

    cout << "Fibonacci series till " << X << " is: ";
    printFib4(0, 1, X); // start with 0 and 1
    return 0;
}