#include<iostream>
#include<vector>
using namespace std;

int singleOne(vector<int> v) {
    int val = 0;
    for(int i = 0; i<v.size(); i++) {
        val = val ^ v[i];
    }
    return val;
}

int main() {
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i = 0; i<n; i++) {
        cin>>v[i];
    }
    cout<<singleOne(v);
}