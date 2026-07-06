#include<iostream>
#include<vector>
using namespace std;

void merge(vector<int> &arr, int s, int e) {
    if(arr.size() < 2) return;

    int mid = s + (e-s)/2;
    int len1 = mid - s + 1;
    int len2 = e - mid;

    vector<int> left(len1);
    vector<int> right(len2);

    int k = s;
    for(int i = 0; i < len1; i++) {
        left[i] = arr[k++];
    }

    k = mid + 1;
    for(int i = 0; i < len2; i++) {
        right[i] = arr[k++];
    }

    int i = 0; int j = 0;
    k = s;
    while(i < left.size() && j < right.size()) {
        if(left[i] <= right[j]) {
            arr[k++] = left[i++];
        }
        else {
            arr[k++] = right[j++];
        }
    }

    while(i < left.size()) arr[k++] = left[i++]; 
    while(j < right.size()) arr[k++] = right[j++];
}

void mergeSortHelper(vector<int> &arr, int s, int e) {
    if(s >= e) return;

    int mid = s + (e-s)/2;
    mergeSortHelper(arr, s, mid);
    mergeSortHelper(arr, mid + 1, e);
    merge(arr, s, e);
}

void mergeSort(vector<int> &arr) {
    if(arr.size() < 2) return;

    int s = 0; int e = arr.size() - 1;
    mergeSortHelper(arr, s, e);
}

int partition(vector<int> &arr, int s, int e) {
    int pivot = arr[s];
    int count = 0;

    for(int i = s + 1; i <= e; i++) {
        if(arr[i] < pivot) {
            count++;
        }
    }

    int pivotIndex = s + count;
    swap(arr[pivotIndex], arr[s]);

    int i = s; int j = e;
    while(i < pivotIndex && j > pivotIndex) {
        while(arr[i] <= arr[pivotIndex] && i < pivotIndex) {
            i++;
        }
        while(arr[j] > arr[pivotIndex] && j > pivotIndex) {
            j--;
        }
        if(i < pivotIndex && j > pivotIndex) {
            swap(arr[i++], arr[j--]);
        }
    }
    return pivotIndex;
}

void quickSortHelper(vector<int> &arr, int s, int e) {
    if(s >= e) return;

    int p = partition(arr, s, e);
    quickSortHelper(arr, s, p - 1);
    quickSortHelper(arr, p + 1, e);
}

void quickSort(vector<int> &arr) {
    if(arr.size() < 2) return;

    int s = 0; int e = arr.size() - 1;
    quickSortHelper(arr, s, e);
}

int main() {
    int n;
    cin>>n;

    vector<int> v(n);
    for(int i = 0; i < n; i++) {
        cin>>v[i];
    }

    mergeSort(v);
    for(int i = 0; i < v.size(); i++) {
        cout<<v[i]<<" ";
    }
}