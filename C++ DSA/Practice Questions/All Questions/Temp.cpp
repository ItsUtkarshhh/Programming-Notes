#include<iostream>
#include<climits>
using namespace std;

int maxi(int* arr, int n) {
    int maximum = INT_MIN;
    for(int i = 0; i < n; i++) {
        maximum = max(arr[i], maximum);
    }
    return maximum;
}

int mini(int* arr, int n) {
    int minimum = INT_MAX;
    for(int i = 0; i < n; i++) {
        minimum = min(arr[i], minimum);
    }
    return minimum;
}

int main() {
    int n;
    cin>>n;
    int* arr = new int[n];
    for(int i = 0; i < n; i++) {
        cin>>arr[i];
    }
    cout<<maxi(arr, n)<<endl;
    cout<<mini(arr, n)<<endl;
}