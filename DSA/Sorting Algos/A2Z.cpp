// --------------------------------------------------- Sorting Algorithms ----------------------------------------------------->
// --------------------------------------------------- Selection Sort ----------------------------------------------------->
#include<iostream>
using namespace std;

void selectionSort(vector<int> &v) {
    if(v.empty()) {
        cout<<"Empty array";
        return {};
    }
    
    for(int i = 0; i < v.size(); i++) {
        int minIndex = i;
        for(int j = i; j < v.size(); j++) {
            if(v[j] < v[minIndex]) {
                minIndex = j;
            }
        }
        swap(v[minIndex], v[i]);
    }
    return v;
}

int main() {
    int size;
    cin>>size;
    
    vector<int> v(size);
    for(int i = 0; i < size; i++) {
        cin>>v[i];
    }
    selectionSort(v);
    for(int i = 0; i < size; i++) {
        cout<<v[i]<<" ";
    }
}

// --------------------------------------------------- Bubble Sort & Recursion ----------------------------------------------------->
#include<iostream>
using namespace std;

void bubbleSort(vector<int> &v) {
    if(v.empty()) {
        cout<<"Empty array";
        return;
    }
    
    for(int i = 1; i < v.size(); i++) {
        for(int j = 0; j < v.size() - i; j++) {
            if(v[j] > v[j + 1]) {
                swap(v[j], v[j+1]);
            }
        }
    }
}

void bubbleSortBetter(vector<int> &v) {
    if(v.empty()) {
        cout<<"Empty array";
        return;
    }
    
    for(int i = 1; i < v.size(); i++) {
        bool swapped = false;
        for(int j = 0; j < v.size() - i; j++) {
            if(v[j] > v[j + 1]) {
                swapped = true;
                swap(v[j], v[j+1]);
            }
        }
        if(swapped == false) break;
    }
}

int main() {
    int size;
    cin>>size;
    
    vector<int> v(size);
    for(int i = 0; i < size; i++) {
        cin>>v[i];
    }
    bubbleSort(v);
    for(int i = 0; i < size; i++) {
        cout<<v[i]<<" ";
    }
}

// --------------------------------------------------- Insertion Sort ----------------------------------------------------->
#include<iostream>
using namespace std;

void insertionSort(vector<int> &v) {
    if(v.empty()) {
        cout<<"Empty array";
        return;
    }
    
    for(int i = 1; i < v.size(); i++) {
        int currentVal = v[i];
        int j = i-1;

        while(j >= 0 && v[j] > currentVal) {
            v[j+1] = v[j];
            j--;
        }
        v[j+1] = currentVal;
    }
}

int main() {
    int size;
    cin>>size;
    
    vector<int> v(size);
    for(int i = 0; i < size; i++) {
        cin>>v[i];
    }
    bubbleSort(v);
    for(int i = 0; i < size; i++) {
        cout<<v[i]<<" ";
    }
}

// --------------------------------------------------- Merge Sort ----------------------------------------------------->
#include<iostream>
using namespace std;

vector<int> merge(vector<int> left, vector<int> right) {
    if(left.empty()) return right;
    if(right.empty()) return left;
    
    int start1 = 0;
    int start2 = 0;
    
    vector<int> result;
    
    while(start1 < left.size() && start2 < right.size()) {
        if(left[start1] <= right[start2]) {
            result.push_back(left[start1]);
            start1++;
        }
        else if(left[start1] > right[start2]) {
            result.push_back(right[start2]);
            start2++;
        }
    }
    
    while(start1 < left.size()) {
        result.push_back(left[start1]);
        start1++;
    }
    while(start2 < right.size()) {
        result.push_back(right[start2]);
        start2++;
    }
    
    return result;
}

vector<int> mergeSort_Helper(vector<int> &v, int start, int end) {
    if(start > end) return {};
    if(start == end) return {v[start]};
    
    int mid = start + (end-start)/2;
    
    vector<int> left = mergeSort_Helper(v, start, mid);
    vector<int> right = mergeSort_Helper(v, mid + 1, end);
    return merge(left, right);
}

vector<int> mergeSort(vector<int> v) {
    if(v.empty()) return {};
    return mergeSort_Helper(v, 0, v.size() - 1);
}

int main() {
    int size;
    cin>>size;
    
    vector<int> v(size);
    for(int i = 0; i < size; i++) {
        cin>>v[i];
    }
    mergeSort(v);
    for(int i = 0; i < size; i++) {
        cout<<v[i]<<" ";
    }
}

// --------------------------------------------------- Quick Sort ----------------------------------------------------->
#include<iostream>
using namespace std;

int partition(vector<int> &v, int start, int end) {
    int pivotElement = v[start];
    int count = 0;
    
    for(int i = start + 1; i <= end; i++) {
        if(v[i] <= pivotElement) {
            count++;
        }
    }

    int pivotIndex = start + count;
    swap(v[pivotIndex], v[start]);
    
    int i = start; int j = end;
    while(i < pivotIndex && j > pivotIndex) {
        while(i <= end && v[i] <= pivotElement) i++;
        while(j >= start && v[j] > pivotElement) j--;
        if (i < pivotIndex && j > pivotIndex) {
            swap(v[i], v[j]);
            i++; j--;
        }
    }
    return pivotIndex;
}

vector<int> quickSort_Helper(vector<int> &v, int start, int end) {
    if(start >= end) return {};
    
    int pivotIndex = partition(v, start, end);
    quickSort_Helper(v, start, pivotIndex - 1);
    quickSort_Helper(v, pivotIndex + 1, end);
    return v;
}

vector<int> quickSort(vector<int> v) {
    if(v.empty() || v.size() == 1) return v;
    return quickSort_Helper(v, 0, v.size() - 1);
}

int main() {
    int size;
    cin>>size;
    
    vector<int> v(size);
    for(int i = 0; i < size; i++) {
        cin>>v[i];
    }
    mergeSort(v);
    for(int i = 0; i < size; i++) {
        cout<<v[i]<<" ";
    }
}

// --------------------------------------------------- Quick Sort ----------------------------------------------------->
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void sortPhase(vector<int> &v, int start, int boundary) {
    if(start >= boundary) return;
    if(v[start] > v[start + 1]) swap(v[start], v[start + 1]);
    sortPhase(v, start + 1, boundary);
}

void bubbleSortRecursion_HelperB(vector<int> &v, int start, int size) {
    if(start >= size - 1) return;
    sortPhase(v, 0, size - start - 1);
    bubbleSortRecursion_HelperB(v, start + 1, size);
}

void bubbleSortRecursion_HelperA(vector<int> &v, int size) {
    if(size <= 0) return;
    
    for(int i = 0; i < size - 1; i++) {
        if(v[i] > v[i + 1]) swap(v[i], v[i + 1]);
    }

    bubbleSortRecursion_HelperA(v, size - 1);
}

void bubbleSortRecursion(vector<int> &v) {
    if(v.empty() || v.size() == 1) return;
    bubbleSortRecursion_HelperA(v, v.size());
    // bubbleSortRecursion_HelperB(v, 0, v.size());
}

int main() {
    int size;
    cin>>size;
    
    vector<int> v(size);
    for(int i = 0; i < size; i++) {
        cin>>v[i];
    }
    bubbleSortRecursion(v);
    for(int i = 0; i < size; i++) {
        cout<<v[i]<<" ";
    }
}
