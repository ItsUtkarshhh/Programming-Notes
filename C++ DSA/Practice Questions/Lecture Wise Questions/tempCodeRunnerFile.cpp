#include<iostream>
#include<vector>
#include<map>
using namespace std;

int findKeyLS3(vector<int> v, int key) {
    map<int, int> mp;
    for(int i = 0; i < v.size(); i++) {
        if(!mp.count(v[i])) {
            mp[v[i]] = i;
        }
    }
    if(!mp.count(key)) return -1;
    return mp[key];
}

int main() {
    int n;
    cin>>n;
    vector<int> v(n);

    for(int i = 0; i < n; i++) {
        cin>>v[i];
    }

    int key;
    cin>>key;

    cout<<"Index of the key (if exist) : "<<findKeyLS3(v, key);
}