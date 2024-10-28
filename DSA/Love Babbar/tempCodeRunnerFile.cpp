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