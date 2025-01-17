#include<iostream>
#include<string>
using namespace std;

char lowercase(char ch) {
    if(ch >= 'A' && ch <= 'Z') {
        return ch - 'A' + 'a';
    }
    return ch;
}

bool valid(char ch) {
    if(ch >= 'A' && ch <= 'Z' || ch >= '0' && ch <= '9' || ch >= 'a' && ch <= 'z') {
        return true;
    }
    return false;
}

bool Palindrome(string str) {
    string temp = "";
    for(int i = 0; i<str.length(); i++) {
        if(valid(str[i])) {
            temp.push_back(str[i]);
        }
    }
    for(int i = 0; i<temp.length(); i++) {
        temp[i] = lowercase(temp[i]);
    }

    int s = 0;
    int e = temp.length()-1;
    while(s<e) {
        if(temp[s] == temp[e]) {
            s++;
            e--;
        }
        else {
            return false;
        }
    }
    return true;
}

int main() {
    string str;
    cin>>str;
    if(Palindrome(str)) {
        cout<<"Palindrome!";
    }
    else {
        cout<<"Not a Palindrome!";
    }
}