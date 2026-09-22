#include<iostream>
#include<vector>
using namespace std;

void removeDuplicates(vector<int> &v) {
    if(v.empty()) return;

    int i = 0; int j = 1;
    while(j < v.size()) {
        if(v[i] != v[j]) {
            i++;
            swap(v[i], v[j]);
        }
        j++;
    }
    v.resize(i+1);
}

void moveAllZeroes(vector<int> &v) {
    if(v.empty()) return;

    int i = 0; int j = 0;
    while(j < v.size()) {
        if(v[j] != 0) {
            swap(v[i], v[j]);
            i++;
        }
        j++;
    }
}

int longestSubStringNoRep(string &str) {
    if(str.empty()) return 0;

    int maxLen = INT_MIN;
    map<char, int> hash;

    for(char i = 'a'; i < 'z'; i++) {
        hash[i] = -1;
    }

    int left = 0;
    int right = 0;
    string subStr = "";

    while(right < str.size()) {
        if(hash[[str[right]]] == -1 || hash[str[right]] < left) {
            subStr = subStr + str[right];
            maxLen = max(maxLen, right - left + 1);
        }
        else {
            left = hash[str[right]] + 1;
        }
        hash[str[right]] = right;
        right++;
    }
}

int main() {
    int size;
    cin>>size;
    vector<int> v(size);

    for(int i = 0; i < size; i++) {
        cin>>v[i];
    }

    moveAllZeroes(v);
    for(int i = 0; i < v.size(); i++) {
        cout<<v[i]<<" ";
    }
}