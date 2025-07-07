// Intersection of Two arrays!
#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
#include<map>
#include<unordered_map> // For better!
#include<set>
#include<unordered_set> // For better!
using namespace std;

void rotatebyK(vector<int> &v, int k) {
    for(int i = 0; i < k; i++) {
        int lastVal = v[v.size() - 1];
        for(int j = 0; j < v.size() - 2; j++) {
            int temp = v[j+1];
            v[j+1] = v[j];
            v[j + 2] = temp;
        }
        v[0] = lastVal;
    }
}

int main() {
    int n1;
    cin>>n1;
    vector<int> v1(n1);
    for(int i = 0; i < n1; i++) {
        cin>>v1[i];
    }
    int k;
    cin>>k;
    rotatebyK(v1, k);
    for(int val : v1) {
        cout<<val<<" ";
    }
}