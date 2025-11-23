#include<iostream>
#include<vector>
using namespace std;

int findKey(vector<int> v, int key) {
    int start = 0;
    int end = v.size() - 1;
    int mid = start + (end - start)/2;
    while(start <= end) {
        if(key == v[mid]) {
            return mid;
        }

        if(key > v[mid]) {
            start = mid + 1;
        }
        else {
            end = mid - 1;
        }

        mid = start + (end - start)/2;
    }

    return -1;
}

int main() {
    int n;
    cin>>n;
    vector<int> v(n);

    for(int i = 0; i < n; i++) {
        cin>>v[i];
    }

    int key;
    cin>>key;

    cout<<"Value is at index : "<<findKey(v, key);
}