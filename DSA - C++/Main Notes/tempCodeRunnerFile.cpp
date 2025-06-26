#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int firstOccurence(vector<int> v, int key) {
    int start = 0;
    int end = v.size() - 1;
    int mid = start + (end - start)/2;
    int index = 0;
    while(start < end) {
        if(key == v[mid]) {
            index = mid;
            end = mid - 1;
        }
        else if(key > v[mid]) {
            start = mid + 1;
        }
        else {
            end = mid - 1;
        }
    }
    return index;
}

int lastOccurence(vector<int> v, int key) {
    int start = 0;
    int end = v.size() - 1;
    int mid = start + (end - start)/2;
    int index = 0;
    while(start < end) {
        if(key == v[mid]) {
            index = mid;
            start = mid + 1;;
        }
        else if(key > v[mid]) {
            start = mid + 1;
        }
        else {
            end = mid - 1;
        }
    }
    return index;
}

int main() {
    int size;
    cin>>size;
    vector<int> v(size);
    for(int i = 0; i < size; i++) {
        cin>>v[i];
    }
    sort(v.begin(), v.end());
    int key;
    cin>>key;
    cout<<"First occurence at index : "<<firstOccurence(v, key);
    cout<<"Last occurence at index : "<<lastOccurence(v, key);
}