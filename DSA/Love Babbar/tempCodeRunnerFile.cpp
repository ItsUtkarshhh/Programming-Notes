#include <iostream>
using namespace std;

int partition(int arr[], int s, int e) {
    int pivot = arr[s];
    int cnt = 0;
    for (int i = s + 1; i <= e; i++) {
        if (arr[i] <= pivot) {
            cnt++;
        }
    }
    int pivotIndex = s + cnt; // Place pivot at right position
    swap(arr[pivotIndex], arr[s]);

    // Sorting Left and Right sub arrays!
    int i = s, j = e;

    while (i < pivotIndex && j > pivotIndex) {
        while (arr[i] <= pivot) {
            i++;
        }
        while (arr[j] > pivot) {
            j--;
        }
        if (i < pivotIndex && j > pivotIndex) {
            swap(arr[i++], arr[j--]);
        }
    }
    return pivotIndex;
}

// So yahaa toh humne recursion call krdiye! ki jo cheez humne partition function me kri hai pivot element ke saath original array me vhi same cheez tum baaki saari jo sub arrays banegi unn sab me krdo thru recursion!
void quickSort(int arr[], int s, int e) {
    if (s >= e) return;
    int p = partition(arr, s, e); // For partitioning and sorting!
    quickSort(arr, s, p - 1); // Sorting Left sub array!
    quickSort(arr, p + 1, e); // Sorting Right sub array!
}

int main() {
    int arr[5] = {3, 1, 4, 5, 2};
    int n = 5;
    quickSort(arr, 0, n - 1);
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}