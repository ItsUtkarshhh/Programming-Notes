#include<iostream>
#include<stack>
#include<string>
using namespace std;

bool validParanthesis(string& str) {
    stack<char> st;
    for(int i = 0; i < str.length(); i++) {
        char ch = str[i];
        if(!st1.empty()) {
            char top = st1.top();
            if( (ch == '}' && top == '{') || (ch == ')' && top == '(') || (ch == ']' && top == '[')) {
                st1.pop();
            }
            else {
                return false;
            }
        }
        else {
            return false;
        }
    }
    if(st1.empty()) {
        return true;
    }
    else {
        return false;
    }
}

int main() {
    
}