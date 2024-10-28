#include<iostream>
using namespace std;

void printArray(int arr[], int size) {
    for(int i = 0; i<size; i++) {
        cout<<arr[i]<<" ";
    }
}

void insertionSort(int arr[], int size) {
    int j;
    for(int i = 1; i < size; i++) {
        int temp = arr[i];
        for(int j = i-1; j>=0; j--) {
            if(arr[j] > temp) {
                arr[j+1] = arr[j];
            }
            else {
                break;
            }
        }
        arr[j+1] = temp;
    }
    printArray(arr,size);
}

int main() {
    int arr[10] = {9,8,7,6,5,4,3,2,1,0};
    insertionSort(arr,10);
    // insertionSort2(arr,10);
}


#include<iostream>
using namespace std;

void merge(int* arr, int s, int e) {
    int mid = s + (e-s)/2;

    int len1 = mid - s + 1;
    int len2 = e - s;

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

    mainArrayIndex = s;
    int index1 = 0;
    int index2 = 0;

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
}

void mergeSort(int* arr, int s, int e) {
    if(s>=e) {
        return;
    }
    int mid = s + (e-s)/2;
    mergeSort(arr,s,mid);
    mergeSort(arr,mid+1,e);
    merge(arr,s,e);
}


int main() {
    int size;
    cin>>size;

    int* arr = new int[size];
    for(int i = 0; i<size; i++) {
        cin>>arr[i];
    }

    mergeSort(arr, 0, size);
    for(int i = 0; i<size; i++) {
        cout<<arr[i]<<" ";
    }
}