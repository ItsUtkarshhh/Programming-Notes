#include<iostream>
using namespace std;

char* reverseString(char* str, int size) {
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
    for(int i = 0; i <= n; i++) {
        cout<<revString[i];
    }
}
