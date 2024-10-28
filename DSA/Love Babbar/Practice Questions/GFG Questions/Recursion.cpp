// Printing all numbers from 1-n using recursion!
#include<iostream>
using namespace std;

void printingAll(int n) {
    if(n==0) {
        return;
    }
    printingAll(n-1);
    cout<<n<<" ";
}

int main() {
    int n;
    cin>>n;
    printingAll(n);
}

// Printing n-1 using recursion!
#include<iostream>
using namespace std;

void printingAll(int n) {
    if(n==0) {
        return;
    }
    cout<<n<<" ";
    printingAll(n-1);
}

int main() {
    int n;
    cin>>n;
    printingAll(n);
}

// Power of two using recursion!
#include<iostream>
using namespace std;

int powerofTwo(int n) {
    if(n==0) {
        return 1;
    }
    return 2 * powerofTwo(n-1);
}

int main() {
    int n;
    cin>>n;
    int ans = powerofTwo(n);
    cout<<ans;
}

// Mean of array using recursion
#include<iostream>
using namespace std;

int sumofArray(int* arr, int n) {
    if(n==0) {
        return 0;
    }
    int sum = *(arr) + sumofArray(arr+1,n-1);
    return sum;
}

float finalMean(int* arr, int n) {
    int sum = sumofArray(arr,n);
    return static_cast<float> (sum)/n; // This is a right way to do it! you have done almost everything correct! but your previous ans contained, return sum/n; where you were ot considering decimal values! and even decimal values ke liye tum function ka return type ya sum ka return tyoe chance kr rhe the! sabse best yhi hai ki sum and fuunction ka return type int hi rakho bss end me sum/n krte time, ans ko float me cast krdo!
}

int main() {
    int n;
    cin>>n;
    int* arr = new int[n];
    for(int i = 0;i<n; i++) {
        cin>>arr[i];
    }

    int ans = finalMean(arr,n);
    cout<<ans;
}

// Sum of natural numbers!
#include<iostream>
using namespace std;

int sumNaturalNum(int n) {
    if(n==1) { // Few improvements that you can do here is, keep if(n<=0) return 0; and then write the recurrence relation! but also in this question, recursive approach is not that feasible! here you should solve it iteratively! becoz of TC!
        return 1;
    }
    int sum = n + sumNaturalNum(n-1);
    return sum;
}

int main() {
    int n;
    cin>>n;
    int ans = sumNaturalNum(n);
    cout<<ans;
}

// Decimal to Binary! using recursion!
#include<iostream>
#include<math.h>
using namespace std;

int DecimaltoBinary(int n, int placevalue) {
    if(n==0) {
        return 0;
    }
    int digits = n&1;
    return (digits * placevalue) + DecimaltoBinary(n>>1,placevalue*10);
}

int main() {
    int n;
    cin>>n;
    int ans = DecimaltoBinary(n,1);
    cout<<ans;
}

// Sum of array elements using recursion!
#include<iostream>
using namespace std;

int sumofArr(int* arr, int size) {
    if(size==0) {
        return 0;
    }
    return *(arr) + sumofArr(arr+1,size-1);
}

int main() {
    int size;
    cin>>size;
    int* arr = new int[size];
    for(int i = 0; i<size; i++) {
        cin>>arr[i];
    }
    cout<<sumofArr(arr,size);
}

// Print reverse of a string using recursion!
#include<iostream>
#include<string>
using namespace std;

void reverseString(string &s1, int start, int end) {
    if(start>=end) {
        return;
    }
    swap(s1[start],s1[end]);
    reverseString(s1,start+1,end-1);
}

int main() {
    string s1;
    getline(cin,s1);
    int start = 0;
    int end = s1.length()-1;
    reverseString(s1,start,end);
    cout<<s1;
}

// Length of a string using recursion! and without using the build in length function!
// My Solution!
#include<iostream>
#include<string>
using namespace std;

int printLen(string s1, int s) {
    if(s1[s]=='\0') {
        return 0;
    }
    return 1 + printLen(s1,s+1);
}

int main() {
    string s1;
    getline(cin,s1);
    cout<<printLen(s1,0);
}

// ChatGPT Solution!
#include <iostream>
#include <string>
using namespace std;

int stringLength(const string &str) {
    if (str == "") {
        return 0;
    }
    return 1 + stringLength(str.substr(1)); // Recursive case: Return 1 plus the length of the remaining string
}

int main() {
    string str;
    getline(cin, str);
    int length = stringLength(str);
    cout<<length;
    return 0;
}

// sum of digits of a number using recursion!
#include<iostream>
using namespace std;

int sumofDigits(int n) {
    if(n==0) {
        return 0;
    }
    int digits = n%10;
    return digits + sumofDigits(n/10);
}

int main() {
    int n;
    cin>>n;
    cout<<sumofDigits(n);
}

// tail recursion to calculate sum of array elements!
#include<iostream>
using namespace std;

int sumofArrayElements(int* arr, int size) {
    if(size==0) { // Base case!
        return 0;
    }
    int sum = arr[0];
    return sum + sumofArrayElements(arr+1,size-1);
}

int main() {
    int n;
    cin>>n;
    int* arr = new int[n];
    for(int i = 0; i<n; i++) {
        cin>>arr[i];
    }
    cout<<sumofArrayElements(arr,n);
}