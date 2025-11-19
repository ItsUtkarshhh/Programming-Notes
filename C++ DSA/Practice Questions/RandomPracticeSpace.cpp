#include<iostream>
#include<math.h>
#include<climits>
#include<map>
using namespace std;

void freqOfElements(int* arr, int n) {
    map<int, int> mp;
    for(int i = 0; i < n; i++) {
        mp[arr[i]]++;
    }

    for(auto it : mp) {
        cout<<"Value : "<<it.first<<" occured : "<<it.second<<" times\n";
    }
}

int main() {
    int n;
    cin>>n;
    int* arr = new int[n];
    for(int i = 0; i < n; i++) {
        cin>>arr[i];
    }
    freqOfElements(arr, n);
}