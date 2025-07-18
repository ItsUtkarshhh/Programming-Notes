#include<iostream>
#include<string>
#include<unordered_set>
#include<algorithm>
#include<map>
#include<vector>
using namespace std;

bool checkPermutations1(string s1, string s2) {
    sort(s2.begin(), s2.end()); // Sorting for next_permutation
    unordered_set<string> seen; // To avoid duplicate permutations

    do {
        if (seen.find(s2) != seen.end()) continue; // Skip duplicates
        seen.insert(s2);
        if (s1.find(s2) != std::string::npos) return true;
    } while (std::next_permutation(s2.begin(), s2.end()));

    return false;
}

// Approach 2 (Sliding window + Hashmaps) :
bool checkPermutations2(string s1, string s2) {
    int k = s2.length();
    map<char,int> freq1;
    map<char,int> freq2;
    for(int i = 0; i < k; i++) freq2[s2[i]]++;
    
    int index = 0;
    for(index = 0; index < k; index++) freq1[s1[index]]++;

    if(freq1 == freq2) return true; // You can do this only when maps are not unordered!
    while(index < s1.length()) {
        freq1[s1[index]]++;
        freq1[s1[index - k]]--;
        if (freq1[s1[index - k]] == 0) freq1.erase(s1[index - k]); // Clean up the map to keep it minimal
        if(freq1 == freq2) return true;
        index++;
    }
    return false;
}

// Approach 3 (Better Approach 2) :
bool checkPermutations3(string s1, string s2) {
    if (s1.length() < s2.length()) return false;

    vector<int> freq1(26, 0), freq2(26, 0);

    for (char c : s2) freq2[c - 'a']++;
    for (int i = 0; i < s2.length(); i++) freq1[s1[i] - 'a']++;

    if (freq1 == freq2) return true;

    for (int i = s2.length(); i < s1.length(); i++) {
        freq1[s1[i] - 'a']++;
        freq1[s1[i - s2.length()] - 'a']--;
        if (freq1 == freq2) return true;
    }

    return false;
}

int main() {
    string str1, str2;
    cin>>str1>>str2;
    if(checkPermutations3(str1, str2)) cout<<"True: A permutation exists in s2."<<endl;
    else cout<<"False: No permutation found."<<endl;
}