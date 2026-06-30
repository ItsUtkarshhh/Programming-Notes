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

    for(int i = 0; i < size; i++) {

    }
}

int main() {
    int size;
    int* arr = new int[size];

    for(int i = 0; i < size; i++) {
        cin>>arr[i];
    }
    
    bubbleSort(arr, size);
}