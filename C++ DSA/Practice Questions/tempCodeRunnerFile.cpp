// Q1 : Finding maximum/minimum elements in an Array!
#include<iostream>
#include<map>
#include<vector>
using namespace std;

vector<int> uniqueElements(vector<int> v) {
    if(v.size() == 0) return {};

    map<int> hash;
    for(int i = 0; i < v.size(); i++) {
        hash[v[i]]++;
    }

    vector<int> ans;
    for(auto it : hash) {
        if(it.second == 1) {
            ans.push_back(it.second);
        }
    }
    return ans;
}

void printVector(vector<int> v) {
    if(v.size() == 0) {
        cout<<"Empty Vector";
        return;
    }

    for(int i = 0; i < v.size(); i++) {
        cout<<v[i]<<" ";
    }
}

int main() {
    int n;
    cin>>n;

    vector<int> v(n);
    for(int i = 0; i < n; i++) {
        cin>>v[i];
    }
    vector<int> ans = uniqueElements(v);
    printVector(ans);
}