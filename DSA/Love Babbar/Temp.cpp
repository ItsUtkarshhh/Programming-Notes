#include<iostream>
using namespace std;

int main() {
    char ch1[] = "Hello";  // Character array (null-terminated string)
    cout << "Address of ch1: " << (void*)ch1 << endl;  // Print the address of the first element of ch1
    cout << "Address of ch1[0]: " << (void*)&ch1[0] << endl;  // Print address of the first character in the array
    return 0;
}
