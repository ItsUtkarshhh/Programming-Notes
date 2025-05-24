#include<iostream>
using namespace std;

void printArray(int arr[], int n) {
    for(int i = 0; i<n; i++) {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int partition(int arr[], int s, int e) {
    int pivot = arr[s];
    int count = 0;
    for(int i = s+1; i<e; i++) {
        if(arr[i] <= pivot) {
            count++;
        }
    }

    int pivotIndex = s + count;
    swap(arr[s], arr[pivotIndex]);

    int i = s; int j = e-1;
    while(i < pivotIndex && j > pivotIndex) {
        while(arr[i] <= arr[pivotIndex]) {
            i++;
        }
        while(arr[j] > arr[pivotIndex]) {
            j--;
        }
        if(i < pivotIndex && j > pivotIndex) {
            swap(arr[i++], arr[j--]);
        }
    }
    return pivotIndex;
}

void quickSort(int arr[], int s, int e) {
    if(s >= e-1) {
        return;
    }
    int p = partition(arr, s, e);
    quickSort(arr, s, p);
    quickSort(arr, p+1, e);
}

int main() {
    int arr[10] = {5,4,6,10,62,34,12,3,2,1};
    quickSort(arr, 0, 10);
    printArray(arr, 10);
}