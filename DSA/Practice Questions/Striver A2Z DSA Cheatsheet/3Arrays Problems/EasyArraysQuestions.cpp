// Question 1 (GFG) : Maximum element in the array!
#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int largest(vector<int> &arr) {
    if(arr.size() == 0) return -1;
    if(arr.size() == 1) return arr[0];
    int max = INT_MIN;
    for(int i = 0; i<arr.size(); i++) {
        if(arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

int main() {
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i = 0; i<n; i++) {
        cin>>arr[i];
    }
    int answer = largest(arr);
    cout<<answer;
}

// Question 2 (GFG) : Find the second largest element of the array!
#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int getSecondLargest(vector<int> &arr) {
    if(arr.size() == 0 || arr.size() == 1) return -1;
    int max1 = arr[0];
    int max2 = INT_MIN;
    for(int i = 1; i<arr.size(); i++) {
        if(arr[i] > max1) {
            max2 = max1;
            max1 = arr[i];
        }
        else if(arr[i] < max1 && arr[i] > max2) {
            max2 = arr[i];
        }
    }
    return (max2 == INT_MIN) ? -1 : max2;
}

int main() {
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i = 0; i<n; i++) {
        cin>>arr[i];
    }
    int answer = getSecondLargest(arr);
    cout<<answer;
}

// Question 3 (CodeStudio) : Check if an array is sorted or not!
#include<iostream>
#include<vector>
using namespace std;

int isSorted(vector<int> a) {
    int flag = true;
    for(int i = 0; i<a.size()-1; i++) {
        if(a[i+1] < a[i]) {
            flag = false;
        }
    }
    return (flag == true) ? 1 : 0;
}

int main() {
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i = 0; i<n; i++) {
        cin>>arr[i];
    }
    int answer = isSorted(arr);
    cout<<answer;
}