#include<iostream>
#include<vector>
using namespace std;

void secondLargest(vector<int> &v) {
    int max1 = INT_MIN;
    int max2 = INT_MIN;
    for(int i = 0; i < n; i++) {
        if(v[i] >= max1) {
            max2 = max1;
            max1 = v[i];
        }
        else if(v[i] < max1 && v[i] >= max2) {
            max2 = v[i];
        }
    }
    return max2;
}

int main() {
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i = 0; i < n; i++) {
        cin>>v[i];
    }
    secondLargest(v);
}