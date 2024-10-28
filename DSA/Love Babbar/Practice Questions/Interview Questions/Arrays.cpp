// Q 1) Printing first letter of each word in a sentence!
#include<iostream>
using namespace std;

void printFL(string s) {
    int i = 0;
    cout<<s[0];
    for(int j = 0; j<s.length(); j++) {
        if(s[j-1] == ' ' && s[j] != ' ') {
            i = j;
            cout<<s[i];
        }
    }
}

int main() {
    string s;
    getline(cin,s);
    printFL(s);
}