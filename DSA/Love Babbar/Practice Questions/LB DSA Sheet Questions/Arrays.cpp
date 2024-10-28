// Reverse the array! - Using another array!
#include<iostream>
using namespace std;

int *reverseArray(int* arr, int size) { // Not that efficient becoz of redundant copying of element in case of odd number of elements!
    int* tempArray = new int[size];
    int s = 0;
    int e = size-1;
    while(s<=e) {
        tempArray[s] = arr[e];
        tempArray[e] = arr[s];
        s++;
        e--;
    }
    return tempArray;
}

int *reverseArray2(int* arr, int size) { // More effiecient as it passes all the test cases! and properly copies value from one array to another!
    int* tempArray = new int[size];
    int s = 0;
    int e = size-1;
    for(int i = 0; i<size; i++) {
        tempArray[i] = arr[size-i-1];
    }
    return tempArray;
}

int main() {
    int size;
    cin>>size;
    int* arr = new int[size];
    for(int i = 0; i<size; i++) {
        cin>>arr[i];
    }
    int* ans = reverseArray(arr, size);
    for(int i = 0; i<size; i++) {
        cout<<ans[i]<<" ";
    }

    int* ans2 = reverseArray2(arr, size);
    for(int i = 0; i<size; i++) {
        cout<<ans2[i]<<" ";
    }

    delete []arr;
    delete []ans;
    delete []ans2;
}

// Reverse the array! - Using same array!
#include<iostream>
using namespace std;

void printArray(int arr[], int size) {
    for(int i = 0; i<size; i++) {
        cout<<arr[i]<<" ";
    }
} 

void reverseArray(int* arr, int size) {
    int s = 0;
    int e = size-1;
    while(s<=e) {
        int temp = arr[e];
        arr[e] = arr[s];
        arr[s] = temp;
        s++;
        e--;
    }
    printArray(arr,size);
}

int main() {
    int size;
    cin>>size;
    int* arr = new int[size];
    for(int i = 0; i<size; i++) {
        cin>>arr[i];
    }
    reverseArray(arr,size);
}

// Reverse the array! - Using recursion!
#include<iostream>
using namespace std;

void printArray(int arr[], int size) {
    for(int i = 0; i<size; i++) {
        cout<<arr[i]<<" ";
    }
} 

void reverseArray(int* arr, int size) {  
    if (size<=1) {
        return;
    }
    int temp = arr[0];
    arr[0] = arr[size-1];
    arr[size-1] = temp;

    reverseArray(arr+1,size-2);
}

int main() {
    int size;
    cin>>size;
    int* arr = new int[size];
    for(int i = 0; i<size; i++) {
        cin>>arr[i];
    }
    reverseArray(arr,size);
    printArray(arr,size);

    delete []arr;
}

// Finding minimum and maximum value from an array and returning it in pair using pair data structure!
#include<iostream>
#include<utility>
#include<vector>
#include<climits>
using namespace std;

pair<int,int> findMiniMaxi(vector<int> arr) { // That is how you use Pair Data Structure!
    pair<int,int> p1;
    int maxi = INT_MIN;
    int mini = INT_MAX;
    for(int i = 0; i<arr.size(); i++) {
        if(arr[i] > maxi) {
            maxi = arr[i];
        }
    }
    for(int i = 0; i<arr.size(); i++) {
        if(arr[i] < mini) {
            mini = arr[i];
        }
    }
    p1.first = mini;
    p1.second = maxi;
    return p1;
}

int main() {
    int size;
    cin>>size;
    vector<int> arr(size);
    for(int i = 0; i<size; i++) {
        cin>>arr[i];
    }

    pair<int,int> ans = findMiniMaxi(arr);
    cout<<ans.first<<" "<<ans.second<<endl;   
}

// Find the Kth Smallest Element! - Here we have used min-heap from priority queue!
#include <iostream>
#include <queue>
#include <vector>
#include <climits> // For INT_MAX

using namespace std;

int kthSmallest(int arr[], int l, int r, int k) {
    priority_queue<int, vector<int>, greater<int>> pq1;
    
    // Push elements from index l to r into the min-heap
    for(int i = l; i <= r; i++) {
        pq1.push(arr[i]);
    }
    
    // Extract the kth smallest element
    int kthsmallestEle = INT_MAX;
    for(int i = 1; i <= k; i++) {
        kthsmallestEle = pq1.top();
        pq1.pop();
    }
    
    return kthsmallestEle;
}

int main() {
    int arr[] = {7, 10, 4, 3, 20, 15};
    int n = sizeof(arr) / sizeof(arr[0]);
    int l = 0; // Starting index
    int r = n - 1; // Ending index
    int k = 3; // Find the 3rd smallest element
    int kthSmallestElement = kthSmallest(arr, l, r, k);

    cout << "The " << k << "th smallest element is: " << kthSmallestElement << endl;

    return 0;
}

