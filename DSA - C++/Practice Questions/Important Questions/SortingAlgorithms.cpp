// --------------------------------------------------------- Part 1 : Selection Sort! ----------------------------------------------------------------->
// Thinking & Thought Process :
#include<iostream>
#include<vector>
using namespace std;

void selectionSort(vector<int> &v) {
    int n = v.size();
    for(int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for(int j = i + 1; j < n; j++) {
            if(v[j] < v[minIndex]) {
                minIndex = j;
            }
        }
        swap(v[i], v[minIndex]);
    }
}

int main() {
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i = 0; i < n; i++) {
        cin>>v[i];
    }
    selectionSort(v);
    for(int i = 0; i < n; i++) {
        cout<<v[i]<<" ";
    }
}
// Time Complexity: O(n^2) – expected for selection sort. Both best case & worst case!
// Space Complexity: O(1) extra space, since it's sorting in-place.

// --------------------------------------------------------- Part 2 : Bubble Sort! ----------------------------------------------------------------->
// Thinking & Thought Process :
#include<iostream>
#include<vector>
using namespace std;

void bubbleSort(vector<int> &v) {
    int n = v.size();
    for(int i = 1; i <= n - 1; i++) {
        bool swapped = false;
        for(int j = 0; j < n - i; j++) {
            if(v[j] > v[j + 1]) {
                swap(v[j], v[j + 1]);
                swapped = true;
            }
        }
        if(swapped == false) {
            cout<<"Already sorted!";
            return;
        }

    }
}

int main() {
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i = 0; i < n; i++) {
        cin>>v[i];
    }
    bubbleSort(v);
    for(int i = 0; i < n; i++) {
        cout<<v[i]<<" ";
    }
}
// Best Case TC : During checking swapped elements, the TC : O(n)! And this will be achieved when the array is already sorted!
// Worst Case TC : The worst case will be when the array is reversed! Then TC : O(n^2).
// Space Complexity : Here we did'nt took any extra space, only declared some variables, hence, SC : O(1).

// --------------------------------------------------------- Part 3 : Insertion Sort! ----------------------------------------------------------------->
// Thinking & Thought Process :
#include<iostream>
#include<vector>
using namespace std;

void insertionSort(vector<int> &v) {
    int n = v.size();
    int j;
    for(int i = 1; i < n; i++) {
        int temp = v[i];
        for(int j = i - 1; j >= 0; j--) {
            if(v[j] > temp) {
                v[j + 1] = v[j];
            }
            else {
                break;
            }
        }
        v[j + 1] = temp;
    }
}

int main() {
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i = 0; i < n; i++) {
        cin>>v[i];
    }
    insertionSort(v);
    for(int i = 0; i < n; i++) {
        cout<<v[i]<<" ";
    }
}