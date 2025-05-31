#include<iostream>
#include<vector>
using namespace std;

vector<int> sort01(vector<int> &v) {
    int start = 0; int end = v.size() - 1;
    while(start < end) {
        while(v[start] == 0 && start < end) {
            start++;
        }
        while(v[end] == 1 && start < end) {
            end--;
        }
        if(v[start] == 1 && v[end] == 0) {
            swap(v[start], v[end]);
            start++; end--;
        }
    }
}

int main() {
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i = 0; i<n; i++) {
        cin>>v[i];
    }
    sort01(v);
    for(int i = 0; i<v.size(); i++) {
        cout<<v[i]<<" ";
    }
}