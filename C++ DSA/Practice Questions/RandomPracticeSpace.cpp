#include<iostream>
#include<vector>
#include<map>
using namespace std;

void sort01(vector<int> &v) {
    map<int, int> mp;
    for(int i = 0; i < v.size(); i++) {
        mp[v[i]]++;
    }

    int i = 0;
    while(mp[0]) {
        v[i] = 0;
        i++;
        mp[0]--;
    }

    while(mp[1]) {
        v[i] = 1;
        i++;
        mp[1]--;
    }
}

void sort01_2(vector<int> &v) {
    int i = 0;
    int j = v.size() - 1;

    while(i < j) {
        if(v[i] == 1 && v[j] == 0) {
            swap(v[i], v[j]);
            i++;
            j--;
        }

        else if(v[i] == 0 && v[j] == 0) {
            i++;
        }

        else if(v[i] == 1 && v[j] == 1) {
            j--;
        }

        else {
            i++;
            j--;
        }
    }
}

int main() {
    int n;
    cin>>n;

    vector<int> v(n);
    for(int i = 0; i < n; i++) {
        cin>>v[i];
    }

    sort01_2(v);

    for(int i = 0; i < v.size(); i++) {
        cout<<v[i]<<" ";
    }
}