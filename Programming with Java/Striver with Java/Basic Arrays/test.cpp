#include<iostream>
#include<vector>
#include<map>
using namespace std;

int secondMaxOcc(vector<int> &v) {
    if(v.empty()) {
        cout<<"Empty vector";
        return -1;
    }

    map<int, int> hash;
    for(int num : v) {
        hash[num]++;
    }

    int maxElement = 0;
    int maxElementVal = 0;

    int secondMaxElement = maxElement;
    int secondMaxElementVal = maxElementVal;

    for(auto it : hash) {
        if(it.second > maxElementVal && it.second > secondMaxElementVal) {
            secondMaxElement = maxElement;
            secondMaxElementVal = maxElementVal;

            maxElement = it.first;
            maxElementVal = it.second;
        }
        else if(it.second < maxElementVal && it.second > secondMaxElementVal) {
            secondMaxElement = it.first;
            secondMaxElementVal = it.second;
        }
    }
    return secondMaxElement;
}

int main() {
    int size;
    cin>>size;

    vector<int> v(size);
    for(int i = 0; i < size; i++) {
        cin>>v[i];
    }

    cout<<secondMaxOcc(v);
}