#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> additionOfArrays(vector<int> v1, vector<int> v2) {
    int carry = 0;
    int sum = 0;
    int i = v1.size() - 1;
    int j = v2.size() - 1;
    vector<int> result;
    while(i >= 0 & j >= 0) {
        sum = v1[i] + v2[j] + carry;
        carry = sum/10;
        sum = sum%10;
        result.push_back(sum);
        i--; j--;
    }
    while(i >= 0) {
        sum = v1[i] + carry;
        carry = sum/10;
        sum = sum%10;
        result.push_back(sum);
        i--;
    }
    while(j >= 0) {
        sum = v2[j] + carry;
        carry = sum/10;
        sum = sum%10;
        result.push_back(sum);
        j--;
    }
    while(carry != 0) {
        result.push_back(carry);
        carry = carry/10;
    }
    reverse(result.begin(), result.end());
    return result;
}

int main() {
    int n1, n2;
    cin>>n1>>n2;
    vector<int> v1(n1);
    for(int i = 0; i < n1; i++) {
        cin>>v1[i];
    }
    vector<int> v2(n2);
    for(int i = 0; i < n2; i++) {
        cin>>v2[i];
    }
    vector<int> ans = additionOfArrays(v1, v2);
    for(int val : ans) cout<<val;
}