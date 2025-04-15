// --------------------------------------------------------------- Lec 1 : Sorting 1 ---------------------------------------------------------------------------------------------------------------------------------------------->
#include<iostream>
using namespace std;

void printArray(int* arr, int n) {
    for(int i = 0; i<n; i++) {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

// Selection Sort!
void selectionSort(int* arr, int n) {
    for(int i = 0; i<n-1; i++) {
        int minIndex = i;
        for(int j = i+1; j<n; j++) {
            if(arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        swap(arr[minIndex], arr[i]);
    }
    printArray(arr, n);
}

// Bubble Sort!
void bubbleSort(int* arr, int n) {
    for(int i = 1; i<n; i++) {
        bool swapped = false;
        for(int j = 0; j<n-i; j++) {
            if(arr[j] > arr[j+1]) {
                swap(arr[j], arr[j+1]);
                swapped = true;
            }
            if(!swapped) {
                break;
            }
        }
    }
    printArray(arr, n);
}

// Insertion Sort!
void insertionSort(int* arr, int n) {
    int j;
    for(int i = 1; i<n; i++) {
        int temp = arr[i];
        for(j = i-1; j>= 0; j--) {
            if(arr[j] > temp) {
                arr[j+1] = arr[j];
            }
            else {
                break;
            }
        }
        arr[j+1] = temp;
    }
    printArray(arr,n);
}

int main() {
    int arr1[5] = {5,4,3,2,1};
    int arr2[5] = {5,4,3,2,1};
    int arr3[5] = {5,4,3,2,1};
    
    selectionSort(arr1, 5);
    bubbleSort(arr2, 5);
    insertionSort(arr3, 5);
}

// --------------------------------------------------------------- Lec 2 : Sorting 2 ---------------------------------------------------------------------------------------------------------------------------------------------->
// Merge sort!
#include<iostream>
using namespace std;

void printArray(int arr[], int n) {
    for(int i = 0; i<n; i++) {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void merge(int arr[], int s, int e) {
    int mid = s + (e-s)/2;
    int len1 = mid - s + 1;
    int len2 = e - mid;

    int* first = new int[len1];
    int* second = new int[len2];

    int mainArrayIndex = s;
    for(int i = 0; i<len1; i++) {
        first[i] = arr[mainArrayIndex++];
    }

    mainArrayIndex = mid + 1;
    for(int i = 0; i<len2; i++) {
        second[i] = arr[mainArrayIndex++];
    }

    int index1 = 0;
    int index2 = 0;
    mainArrayIndex = s;
    
    while(index1 < len1 && index2 < len2) {
        if(first[index1] < second[index2]) {
            arr[mainArrayIndex++] = first[index1++];
        }
        else {
            arr[mainArrayIndex++] = second[index2++];
        }
    }

    while(index1 < len1) {
        arr[mainArrayIndex++] = first[index1++];
    }

    while(index2 < len2) {
        arr[mainArrayIndex++] = second[index2++];
    }

    delete[] first;
    delete[] second;
}

void mergeSort(int arr[], int s, int e) {
    if(s >= e) {
        return;
    }
    int mid = s + (e-s)/2;
    mergeSort(arr, s, mid);
    mergeSort(arr, mid + 1, e);
    merge(arr, s, e);
}

int main() {
    int arr[10] = {5,4,6,10,62,34,12,3,2,1};
    mergeSort(arr, 0, 9);
    printArray(arr,10);
}

// Recursive Bubble Sort!
#include<iostream>
using namespace std;

void printArray(int arr[], int n) {
    for(int i = 0; i<n; i++) {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void bubbleSortRec(int arr[], int n) {
    if(n == 0 || n == 1) {
        return;
    }
    for(int i = 0; i<n; i++) {
        if(arr[i] > arr[i+1]) {
            swap(arr[i], arr[i+1]);
        }
    }
    bubbleSortRec(arr, n-1);
}

int main() {
    int arr[10] = {5,4,6,10,62,34,12,3,2,1};
    bubbleSortRec(arr, 10);
    printArray(arr,10);
}

// Recursive Insertion Sort!
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

// Quick sort!
