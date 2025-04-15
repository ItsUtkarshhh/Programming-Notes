#include<iostream>
using namespace std;

int main() {
    int n;
    cin>>n;
    int* arr = new int[n];
    for(int i = 0; i<n; i++) {
        cin>>arr[i];
    }
    bool sorted = true;
    for(int i = 0; i<n; i++) {
        if(arr[i] > arr[i+1]) {
            sorted = false;
        }
    }
    if(sorted) {
        cout<<"Array is sorted!";
    }
    else {
        cout<<"Not sorted!";
    }
}