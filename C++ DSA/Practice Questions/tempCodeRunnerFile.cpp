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
    while(j < right.size()) arr[k++] = left[j++];
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