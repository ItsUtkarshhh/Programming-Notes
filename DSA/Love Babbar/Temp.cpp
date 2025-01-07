#include<iostream>
using namespace std;

void merge(int* arr, int s, int e) {
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

    delete[] first;
    delete[] second;
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
    int n;
    cin>>n;
    int* arr1 = new int[n];
    for(int i = 0; i<n; i++) {
        cin>>arr1[i];
    }
    int s = 0;
    int e = n-1;
    mergeSort(arr1,s,e);
    for(int i = 0; i<n; i++) {
        cout<<arr1[i]<<" ";
    }
}

#include<iostream>
using namespace std;

int partition(int* arr, int s, int e) {
    int pivot = arr[s];
    int count = 0;
    for(int i = s+1; i<=e; i++) {
        if(arr[i] <= pivot) {
            count++;
        }
    }

    int pivotIndex = s + count;
    swap(arr[pivotIndex],arr[s]);

    int i = s;
    int j = e;

    while(i<pivotIndex && j>pivotIndex) {
        while(arr[i] <= pivot) {
            i++;
        }
        while(arr[j] > pivot) {
            j--;
        }
        if(i < pivotIndex && j > pivotIndex) {
            swap(arr[i++],arr[j--]);
        }
    }
    return pivotIndex;
}

void quickSort(int* arr, int s, int e) {
    if(s>=e) {
        return;
    }
    int p = partition(arr, s, e);
    quickSort(arr,s,p-1);
    quickSort(arr,p+1,e);
}

int main() {
    int n;
    cin>>n;
    int* arr1 = new int[n];
    for(int i = 0; i<n; i++) {
        cin>>arr1[i];
    }
    int s = 0;
    int e = n-1;
    quickSort(arr1,s,e);
    for(int i = 0; i<n; i++) {
        cout<<arr1[i]<<" ";
    }
}