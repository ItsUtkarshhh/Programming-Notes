// ----------------------------------------------------------- Bubble Sort --------------------------------------------------------------------------->
// Logic & Thought Process : I have an array, which can be sorted or unsorted.
//                         : Aim is to sort in increasing order... the most naive approach would be..
//                         : Traverse the list, by taking the first element and compare with all the elements after it...
//                         : And the moment, you see an element which is less than or equal the current element, simply swap it.
//                         : After swappinh the element, move to the next element
// 

#include<iostream>
using namespace std;

void bubbleSort(int* arr, int size) {
    if(size == 0 || size == 1) return;

    for(int i = 0; i < size - 1; i++) {
        for(int j = 0; j < size - i - 1; j++) {
            if(arr[j] >= arr[j+1]) {
                swap(arr[j], arr[j+1]);
            }
        }
    }
}

void selectionSort(int* arr, int size) {
    if(size == 0 || size == 1) return;

    for(int i = 0; i < size - 1; i++) {
        int minIndex = i;
        for(int j = i; j < size; j++) {
            if(arr[j] <= arr[minIndex]) {
                minIndex = j;
            }
        }
        swap(arr[minIndex], arr[i]);
    }
}

void insertionSort(int* arr, int size) {
    if(size == 0 || size == 1) return;

    for(int i = 0; i < size - 1; i++) {
        int currElement = arr[i + 1];
        int j;
        for(j = i + 1; j > 0; j--) {
            if(arr[j - 1] > arr[j]) {
                arr[j] = arr[j-1];
            }
            else {
                break;
            }
        }
        arr[j] = currElement;
    }
}

int main() {
    int size;
    cin>>size;
    int* arr = new int[size];

    for(int i = 0; i < size; i++) {
        cin>>arr[i];
    }
    
    insertionSort(arr, size);
    for(int i = 0; i < size; i++) {
        cout<<arr[i]<<" ";
    }
}