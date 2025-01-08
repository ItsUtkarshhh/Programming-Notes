#include<iostream>
#include<vector>
#include<string>
using namespace std;

vector<string> letterCombination(string number) {
    vector<string> ans;
    if(number.length() == 0) {
        return ans;
    }
}

int main() {
    string num;
    cin>>num;
    letterCombination(num);
}