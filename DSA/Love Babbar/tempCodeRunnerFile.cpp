#include<iostream>
#include<vector>
using namespace std;

void reverse(vector<int>& v) {
    int s = 0;
    int e = v.size()-1;
    while(s<e) {
        swap(v[s],v[e]);
        s++;
        e--;
    }
}

void sum(int arr1[], int n1, int arr2[], int n2) {
    int carry = 0;
    int i = n1-1; int j = n2-1;
    int value = 0;
    vector<int> v;
    while(i >= 0 && j >= 0) {
        int val1 = arr1[i];
        int val2 = arr2[j];
        value = carry + val1 + val2;
        value = value%10;
        carry = value/10;
        v.push_back(value);
        i--;
        j--;
    }
    while(i >= 0) {
        int val1 = arr1[i];
        value = carry + val1;
        value = value%10;
        carry = value/10;
        v.push_back(value);
        i--;
    }
    while(j >= 0) {
        int val2 = arr2[j];
        value = carry + val2;
        value = value%10;
        carry = value/10;
        v.push_back(value);
        j--;
    }
    while(carry != 0) {
        v.push_back(carry%10);
        carry = carry/10;
    }
    reverse(v);
    for(int i : v) {
        cout<<i;
    }
}

int main() {
    int n1,n2;
    cin>>n1>>n2;
    int arr1[100] = {0};
    int arr2[100] = {0};
    for(int i = 0; i<n1; i++) {
        cin>>arr1[i];
    }
    for(int i = 0; i<n2; i++) {
        cin>>arr2[i];
    }
    sum(arr1,n1,arr2,n2);
}