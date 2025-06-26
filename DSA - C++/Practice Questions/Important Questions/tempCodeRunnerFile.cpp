#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void rotatebyK_F(vector<int> &v, int steps) {
    reverse(v.begin(), v.end());
    reverse(v.begin(), v.begin() + steps);
    reverse(v.begin() + steps, v.end());
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
    rotatebyK_F(v, steps);
    for(int i = 0; i < v.size(); i++) {
        cout<<v[i]<<" ";
    }
}