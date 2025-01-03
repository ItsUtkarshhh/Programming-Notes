#include<iostream>
#include<climits>
using namespace std;

int main() {
    int n;
    cin>>n;
    int* arr = new int[n];
    int max_element = INT_MIN;
    for(int i = 0; i<n; i++) {
        cin>>arr[i];
        if(arr[i] > max_element) {
            max_element = arr[i];
        }
    }

    int* count = new int[max_element+1]();
    for(int i = 0; i<n; i++) {
        count[arr[i]]++;
    }
    for(int i = 0; i<=max_element; i++) {
        if(count[i] == 1) {
            cout<<"There is atleast one unique element, that is : "<<i;
        }
    }
}