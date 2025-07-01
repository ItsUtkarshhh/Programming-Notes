#include<iostream>
#include<vector>
#include<map>
using namespace std;

vector<int> findUnion(vector<int> v1, vector<int> v2) {
    vector<int> finalVec;
    map<int, int> freq1;
    for(int i = 0; i < v1.size(); i++) {
        freq1[v1[i]]++;
    }

    map<int, int> freq2;
    for(int i = 0; i < v2.size(); i++) {
        freq2[v2[i]]++;
    }

    for(auto it: freq2) {
        int element = it.first;
        freq1[element] = max(it.second, freq1[it.first]);
    }

    for(auto it : freq1) {
        for(int i = 0; i < it.second; i++) {
            finalVec.push_back(it.first);
        }
    }
    return finalVec;
}

int main() {
    int n1, n2;
    cin>>n1>>n2;
    vector<int> v1(n1);
    vector<int> v2(n2);
    for(int i = 0; i < n1; i++) {
        cin>>v1[i];
    }
    for(int i = 0; i < n2; i++) {
        cin>>v2[i];
    }
    vector<int> result = findUnion(v1, v2);
    for(int i = 0; i < result.size(); i++) {
        cout<<result[i]<<" ";
    }
}