#include<iostream>
using namespace std;

void printArray(int arr[], int n) {
    for(int i = 0; i<n; i++) {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void moveZeroes(int arr[], int n) {
    int i = 0;
    for(int j = 0; j<n; j++) {
        if(arr[j]!=0) {
            swap(arr[j],arr[i]);
            i++;
        }
    }
    printArray(arr,n);
}

int main() {
    int n;
    cin>>n;
    int arr1[100];
    for(int i = 0; i<n; i++) {
        cin>>arr1[i];
    }
    moveZeroes(arr1,n);
}