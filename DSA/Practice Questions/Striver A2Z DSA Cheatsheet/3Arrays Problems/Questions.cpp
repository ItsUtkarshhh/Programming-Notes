// ------------------------------------------------------------ Lec 1 : Easy ---------------------------------------------------------------------------------------------->
// Question 1 : Largest element in the array!
#include<iostream>
#include<climits>
using namespace std;

int main() {
    int n;
    cin>>n;
    int* arr = new int[n];
    for(int i = 0; i<n; i++) {
        cin>>arr[i];
    }
    int maxVal = INT_MIN;
    for(int i = 0; i<n; i++) {
        if(arr[i] > maxVal) {
            maxVal = arr[i];
        }
    }
    cout<<"Max value of the array : "<<maxVal;
} // TC : O(n) and SC : O(1) rest all methods will be overkill.

// Question 2 : Find the largest element in the array!
#include<iostream>
#include<climits>
using namespace std;

int main() {
    int n;
    cin>>n;
    int* arr = new int[n];
    for(int i = 0; i<n; i++) {
        cin>>arr[i];
    }
    int max1 = arr[0];
    int max2 = INT_MIN;
    for(int i = 0; i<n; i++) {
        if(arr[i] > max1) {
            max2 = max1;
            max1 = arr[i];
        }
        else if(arr[i] < max1 && arr[i] > max2) {
            max2 = arr[i];
        }
    }
    if(max2 == INT_MIN) {
        cout<<-1;
    }
    else {
        cout<<"Second largest element of the array : "<<max2;
    }
}

// Question 3 : Check if an array is sorted or not!
#include<iostream>
using namespace std;

int main() {
    int n;
    cin>>n;
    int* arr = new int[n];
    for(int i = 0; i<n; i++) {
        cin>>arr[i];
    }
    bool sorted = true;
    for(int i = 0; i<n-1; i++) {
        if(arr[i] > arr[i+1]) {
            sorted = false;
            break;
        }
    }
    if(sorted) {
        cout<<"Array is sorted!";
    }
    else {
        cout<<"Not sorted!";
    }
}

// Generalise it for ascending and descending order!
#include<iostream>
using namespace std;

int main() {
    int n;
    cin>>n;
    int* arr = new int[n];
    for(int i = 0; i<n; i++) {
        cin>>arr[i];
    }
    bool ascending = true;
    bool descending = true;
    for(int i = 0; i<n-1; i++) {
        if(arr[i] > arr[i+1]) {
            ascending = false;
        }
        if(arr[i] < arr[i+1]) {
            descending = false;
        }
    }
    if(ascending) cout<<"Array is sorted in ascending order!";
    else if(descending) cout<<"Array is sorted in ascending order!";
    else cout<<"Not sorted at all!";
}