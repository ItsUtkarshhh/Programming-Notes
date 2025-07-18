#include<iostream>
#include<map>
#include<vector>
#include<string>
using namespace std;

string compressString(string str) {
    map<char,int> freq;
    for(char ch : str) {
        freq[ch]++;
    }

    string result = "";
    for(auto it : freq) {
        result += it.first;
        if(it.second > 1) result += to_string(it.second);
    }
    return result;
}

int main() {
    string str;
    cin>>str;
    string result = compressString(str);
    cout<<result;
}