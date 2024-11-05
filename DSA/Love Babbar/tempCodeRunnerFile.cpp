#include<iostream>
using namespace std;

void swapalt(int arr[], int n) {
    for(int i = 0; i<n; i = i+2) {
        if(i+1 < n) {
            swap(arr[i], arr[i+1]);
        }
    }
    for(int i = 0; i<n; i++) {
        cout<<arr[i]<<" ";
    }
}

int main() {
    int arr[1000] = {0};
    int n;
    cin>>n;
    for(int i = 0; i<n; i++) {
        cin>>arr[i];
    }
    swapalt(arr,n);
}