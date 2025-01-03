#include<iostream>
#include<vector>
using namespace std;

void printArray(vector<int> arr) {
    for(int i = 0; i<arr.size(); i++) {
        cout<<arr[i]<<" ";
    }
}

void intersectArrays(vector<int> arr1, vector<int> arr2) {
    vector<int> ansArray;
    int i1 = 0;
    int i2 = 0;
    bool commonPresent = false;
    while(i1<arr1.size() && i2<arr2.size()) {
        if(arr1[i1] == arr2[i2]) {
            commonPresent = true;
            ansArray.push_back(arr1[i1]);
        }
        if(arr1[i1] > arr2[i2]) {
            i2++;
        }
        else {
            i1++;
        }
    }
    if(commonPresent) {
        printArray(ansArray);
    }
    else {
        cout<<-1;
    }
}

int main() {
    int n1,n2;
    cin>>n1>>n2;
    vector<int> arr1(n1);
    vector<int> arr2(n2);
    for(int i = 0; i<n1; i++) {
        cin>>arr1[i];
    }
    for(int i = 0; i<n2; i++) {
        cin>>arr2[i];
    }
    intersectArrays(arr1,arr2);
}