// ----------------------------------------------------------- Bubble, Selection & Insertion Sort --------------------------------------------------------------------------->
#include<iostream>
#include<vector>
using namespace std;

void bubbleSort(vector<int> &v) {
    if(v.size() == 0 || v.size() == 1) return;
    
    int n = v.size();
    
    for(int i = 0; i < n - 1; i++) {
        for(int j = 0; j < n - i - 1; j++) {
            if(v[j] >= v[j+1]) {
                swap(v[j], v[j+1]);
            }
        }
    }
}

void selectionSort(vector<int> &v) {
    if(v.size() == 0 || v.size() == 1) return;
    
    int n = v.size();
    
    for(int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for(int j = i + 1; j < n; j++) {
            if(v[minIndex] > v[j]) {
                minIndex = j;
            }
        }
        swap(v[minIndex], v[i]);
    }
}

void insertionSort(vector<int> &v) {
    if(v.size() == 0 || v.size() == 1) return;

    int n = v.size();
    
    for(int i = 0; i < n - 1; i++) {
        int j = i + 1;
        int temp = v[j];
        for(j = i + 1; j > 0; j--) {
            if(v[j - 1] > temp) {
                v[j] = v[j - 1];
            }
            else {
                break;
            }
        }
        v[j] = temp;
    }
}

// int main() {
//     int n;
//     cin>>n;
    
//     vector<int> v(n);
//     for(int i = 0; i < n; i++) {
//         cin>>v[i];
//     }
    
//     insertionSort(v);
//     for(int i = 0; i < n; i++) {
//         cout<<v[i]<<" ";
//     }
// }

// ----------------------------------------------------------- Merge Sort --------------------------------------------------------------------------->
#include<iostream>
#include<vector>
using namespace std;

void merge(vector<int> &v, int s, int e) {
    if(v.size() == 0 || v.size() == 1) return;

    int mid = s + (e - s)/2; // mid index
    int len1 = mid - s + 1;
    int len2 = e - mid;

    vector<int> left(len1);
    vector<int> right(len2);

    int k = s;
    for(int i = 0; i < left.size(); i++) {
        left[i] = v[k++];
    }

    for(int i = 0; i < right.size(); i++) {
        right[i] = v[k++];
    }

    k = s;
    int i = 0; int j = 0;
    while(i < left.size() && j < right.size()) {
        if(left[i] <= right[j]) {
            v[k++] = left[i++];
        }
        else if(left[i] > right[j]) {
            v[k++] = right[j++];
        }
    }

    while(i < left.size()) v[k++] = left[i++];
    while(j < right.size()) v[k++] = right[j++];
}

void mergeSortHelper(vector<int> &v, int s, int e) {
    if(s >= e) return;

    int mid = s + (e-s)/2;
    mergeSortHelper(v, s, mid);
    mergeSortHelper(v, mid + 1, e);
    merge(v, s, e);
}

void mergeSort(vector<int> &v) {
    if(v.size() == 0 || v.size() == 1) return;

    int s = 0;
    int e = v.size() - 1;
    mergeSortHelper(v, s, e);
}

// int main() {
//     int n;
//     cin>>n;

//     vector<int> v(n);
//     for(int i = 0; i < v.size(); i++) {
//         cin>>v[i];
//     }

//     mergeSort(v);
//     for(int i = 0; i < v.size(); i++) {
//         cout<<v[i]<<" ";
//     }
// }

// ----------------------------------------------------------- Quick Sort --------------------------------------------------------------------------->
#include<iostream>
#include<vector>
using namespace std;

int partition(vector<int> &v, int s, int e) {

    int pivot = v[s];
    int count = 0;
    for(int i = s + 1; i <= e; i++) {
        if(v[i] <= pivot) {
            count++;
        }
    }

    int pivotIndex = s + count;
    swap(v[pivotIndex], v[s]);

    int i = s; int j = e;
    while(i < pivotIndex && j > pivotIndex) {
        while(i < pivotIndex && v[i] <= v[pivotIndex]) {
            i++;
        }
        while(j > pivotIndex && v[j] > v[pivotIndex]) {
            j--;
        }
        if(i < pivotIndex && j > pivotIndex) {
            swap(v[i++], v[j--]);
        }
    }

    return pivotIndex;
}

void quickSortHelper(vector<int> &v, int s, int e) {
    if(s >= e) return;

    int p = partition(v, s, e);
    quickSortHelper(v, s, p - 1);
    quickSortHelper(v, p + 1, e);
}

void quickSort(vector<int> &v) {
    if(v.size() == 0 || v.size() == 1) return;

    int s = 0;
    int e = v.size() - 1;
    quickSortHelper(v, s, e);    
}

int main() {
    int n;
    cin>>n;

    vector<int> v(n);
    for(int i = 0; i < v.size(); i++) {
        cin>>v[i];
    }

    quickSort(v);
    for(int i = 0; i < v.size(); i++) {
        cout<<v[i]<<" ";
    }
}