#include<iostream>
#include<vector>
using namespace std;

int findMissingNumber(vector<int> v) {
    if(v.empty()) return -1;

    int maxi = INT_MIN;
    for(int i = 0; i < v.size(); i++) {
        maxi = max(maxi, v[i]);
    }

    int sum1 = 0;
    for(int i = 0; i <= maxi; i++) {
        sum1 += i;
    }

    int sum2 = 0;
    for(int i = 0; i < v.size(); i++) {
        sum2 += v[i];
    }

    return sum1 - sum2;
}

int main() {
    int size;
    cin>>size;
    
    vector<int> v(size);
    for(int i =  0; i < size; i++) {
        cin>>v[i];
    }
    
    cout<<findMissingNumber(v);
}