// ------------------------------------------------ Hashing ---------------------------------------------------------------->
// ---------------------------------- Problem 1 : Highest Occurring Element in an Array ----------------------------------------->
#include<iostream>
#include<vector>
#include<map>
using namespace std;

int highestOccElement(vector<int> &v) {
    if(v.empty()) return -1;

    map<int, int> mp;
    for(int num : v) {
        mp[num]++;
    }

    int maxOccElement = 0;
    int maxOccValue = 0;
    for(auto it : mp) {
        if(it.second > maxOccValue) {
            maxOccElement = it.first;
            maxOccValue = it.second;
        }
    }
    
    return maxOccElement;
}

int main() {
    int n;
    cin>>size;

    vector<int> v(size);
    for(int i = 0; i < size; i++) {
        cin>>v[i];
    }
    
    cout<<highestOccElement(v);
}

// ---------------------------------- Problem 2 :  Second Highest Occurring Element ----------------------------------------->
#include<iostream>
#include<vector>
#include<map>
using namespace std;

int secHighestOccElement(vector<int> &v) {
    if(v.empty()) return -1;

    map<int, int> mp;
    for(int num : v) {
        mp[num]++;
    }
    
    int maxOccElement = -1;
    int maxOccElementFreq = 0;
    int secMaxOccElement = -1;
    int secMaxOccElementFreq = 0;
    
    for(auto it : mp) {
        if(it.second > maxOccElementFreq) {
            secMaxOccElement = maxOccElement;
            secMaxOccElementFreq = maxOccElementFreq;

            maxOccElement = it.first;
            maxOccElementFreq = it.second;
        }
        else if(it.second < maxOccElementFreq && (it.second > secMaxOccElementFreq || (it.second == secMaxOccElementFreq && it.first < secMaxOccElement))) {
            secMaxOccElement = it.first;
            secMaxOccElementFreq = it.second;
        }
    }
    
    return secMaxOccElement;
}

int main() {
    int n;
    cin>>size;

    vector<int> v(size);
    for(int i = 0; i < size; i++) {
        cin>>v[i];
    }
    
    cout<<secHighestOccElement(v);
}

// ---------------------------------- Problem 3 : Sum of Highest and Lowest Frequency ----------------------------------------->
#include<iostream>
#include<vector>
#include<map>
using namespace std;

int sumHighestAndLowest(vector<int> &v) {
    if(v.empty()) return -1;

    map<int, int> mp;
    for(int num : v) {
        mp[num]++;
    }
    
    int maxOccElement = -1;
    int maxOccElementFreq = 0;
    int minOccElement = -1;
    int minOccElementFreq = INT_MAX;
    
    for(auto it : mp) {
        if(it.second > maxOccElementFreq) {
            maxOccElement = it.first;
            maxOccElementFreq = it.second;
        }
        if(it.second < minOccElementFreq) {
            minOccElement = it.first;
            minOccElementFreq = it.second;
        }
    }
    
    return maxOccElementFreq + minOccElementFreq;
}

int main() {
    int n;
    cin>>size;

    vector<int> v(size);
    for(int i = 0; i < size; i++) {
        cin>>v[i];
    }
    
    cout<<secHighestOccElement(v);
}