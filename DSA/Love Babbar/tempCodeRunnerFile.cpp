#include<iostream>
using namespace std;

void printArray(int* arr, int n) {
    for(int i = 0; i<n; i++) {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void bubbleSort(int* arr, int n) {
    for(int i = 1; i<n; i++) {
        for(int j = 0; j<n-i; j++) {
            if(arr[j+1] < arr[j]) {
                swap(arr[j], arr[j+1]);
            }
        }
    }
    printArray(arr,n);
}

void selectionSort(int* arr, int n) {
    for(int i = 0; i<n-1; i++) {
        int minIndex = i;
        for(int j = i+1; j<n-1; j++) {
            if(arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);
    }
    printArray(arr,n);
}

int main() {
    int n;
    cin>>n;
    int* arr1 = new int[n]();
    for(int i = 0; i<n; i++) {
        cin>>arr1[i];
    }
    bubbleSort(arr1,n);
    selectionSort(arr1,n);
}