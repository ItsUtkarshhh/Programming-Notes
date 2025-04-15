#include<iostream>
using namespace std;

void printArray(int arr[], int n) {
    for(int i = 0; i<n; i++) {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void insertionSortRec(int arr[], int i, int n) {
    if(i == n) {
        return;
    }
    int temp = arr[i];
    int j;
    for(j = i-1; j>=0; j--) {
        if(arr[j] > temp) {
            arr[j+1] = arr[j];
        }
        else {
            break;
        }
    }
    arr[j+1] = temp;
    insertionSortRec(arr, i+1, n);
}

int main() {
    int arr[10] = {5,4,6,10,62,34,12,3,2,1};
    insertionSortRec(arr, 0, 10);
    printArray(arr,10);
}