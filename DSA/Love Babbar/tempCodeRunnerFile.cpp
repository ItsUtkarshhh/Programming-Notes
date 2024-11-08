#include<iostream>
using namespace std;

void SelectionSort(int arr[], int n) {
    int minIndex = 0;
    for(int i = 0; i<n; i++) {
        minIndex = i;
        for(int j = i+1; j<n; j++) {
            if(arr[minIndex] > arr[j]) {
                minIndex = j;
            }
        }
        swap(arr[minIndex], arr[i]);
    }
}

void BubbleSort(int arr[], int n) {
    for(int i = 1; i<n; i++) {
        for(int j = 0; j<n-i; j++) {
            if(arr[j] > arr[j+1]) {
                swap(arr[j], arr[j+1]);
            }
        }
    }
}

int main() {
    int n;
    cin>>n;
    int arr[1000] = {0};
    for(int i = 0; i < n; i++) {
        cin>>arr[i];
    }
    SelectionSort(arr,n);
    for(int i = 0; i<n; i++) {
        cout<<arr[i]<<" ";
    }

    BubbleSort(arr,n);
    for(int i = 0; i<n; i++) {
        cout<<arr[i]<<" ";
    }
}