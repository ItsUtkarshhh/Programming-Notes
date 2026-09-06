#include<iostream>
#include<vector>
using namespace std;

bool linearSearch(vector<int> &v, int key) {
    if(v.empty()) return false;

    for(int i = 0; i < v.size(); i++) {
        if(v[i] == key) return true;
    }
    return false;
}

int main() {
    int size;
    cin>>size;
    
    vector<int> v(size);
    for(int i =  0; i < size; i++) {
        cin>>v[i];
    }
    
    int key;
    cin>>key;
    cout<<linearSearch(v, key);
}