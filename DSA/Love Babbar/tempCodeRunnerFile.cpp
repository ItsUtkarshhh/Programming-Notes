#include<iostream>
using namespace std;

int printArray(int arr[], int n) {
    for(int i = 0; i<n; i++) {
        cout<<arr[i]<<" ";
    }
}

int bubbleSort(int arr[], int n) {
    for(int i = 1; i<n; i++) {
        bool swapped = false;
        for(int j = 0; j<n-i; j++) {
            if(arr[j]>arr[j+1]) {
                swap(arr[j], arr[j+1]);
                swapped = true;
            }
        }
        if(swapped = false) {
            // Agar yahaa ye condition sahi hojaati hai means koi element swap nhi hua hai means ye array already sorted hai means hum yahaa pr loop exit kr sakte hai!
            break;
        }
    }
    printArray(arr, n);
}

int main() {
    int size;
    cin>>size;

    int arr1[500];
    for(int i = 0; i<size; i++) {
        cin>>arr1[i];
    }
    bubbleSort(arr1, size);
}