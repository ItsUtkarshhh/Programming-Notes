#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void rotatebyK_F1(vector<int> &v, int steps) {
    steps = steps % v.size();
    reverse(v.begin(), v.end());
    reverse(v.begin(), v.begin() + steps);
    reverse(v.begin() + steps, v.end());
}

void rotatebyK_F2(vector<int> &v, int steps) {
    int n = v.size();
    steps = steps % n;
    for(int i = 0; i < steps; i++) {
        int lastVal = v[n-1];
        for(int j = n - 1; j > 0; j--) {
            v[j] = v[j-1];
        }
        v[0] = lastVal;
    }
}

int main() {
    int n;
    cin>>n;
    int steps;
    cin>>steps;
    vector<int> v(n);
    for(int i = 0; i < v.size(); i++) {
        cin>>v[i];
    }
    rotatebyK_F2(v, steps);
    for(int i = 0; i < v.size(); i++) {
        cout<<v[i]<<" ";
    }
}