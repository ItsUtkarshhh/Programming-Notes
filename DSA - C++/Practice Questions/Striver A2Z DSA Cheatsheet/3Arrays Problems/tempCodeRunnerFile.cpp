#include<iostream>
using namespace std;

int main() {
    int n;
    cin>>n;
    int* arr = new int[n];
    for(int i = 0; i < n; i++) {
        cin>>arr[i];
    }
    bool sortedAsc = true;
    bool sortedDesc = true;
    for(int i = 0; i < n-1; i++) {
        if(arr[i] > arr[i+1]) {
            sortedAsc = false;
            // break;
        }
        if(arr[i] < arr[i+1]) {
            sortedDesc = false;
            // break;
        }
    }
    if(sortedAsc) {
        cout<<"Sorted array in ascending order!";
    } else if(sortedDesc) {
        cout<<"Sorted array in descending order!";
    }
    else {
        cout<<"Not sorted!";
    }
}