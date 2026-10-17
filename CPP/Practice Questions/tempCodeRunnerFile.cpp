#include<iostream>
#include<vector>
#include<map>
using namespace std;

int maximumElement(vector<int> v) {
    if(v.size() < 1) return -1;

    int maxi = INT_MIN;
    for(int i = 0; i < v.size(); i++) {
        if(v[i] > maxi) maxi = v[i];
    }

    return maxi;
}

int minimumElement(vector<int> v) {
    if(v.size() < 1) return -1;

    int mini = INT_MAX;
    for(int i = 0; i < v.size(); i++) {
        if(v[i] < mini) mini = v[i];
    }

    return mini;
}

void swapAlternatively(vector<int> &v) {
    if(v.size() < 1) {
        cout<<"Size is less than 1"<<endl;
        return;
    }

    for(int i = 0; i < v.size() - 1; i = i + 2) {
        swap(v[i], v[i+1]);
    }
}

bool checkUnique(vector<int> v) {
    if(v.size() < 1) return false;

    int maxElement = INT_MIN;
    for(int i = 0; i < v.size(); i++)  {
        if(v[i] > maxElement) maxElement = v[i];
    }

    vector<int> freqArr(maxElement + 1);

    for(int i = 0; i < v.size(); i++) {
        freqArr[v[i]]++;
    }

    for(int i = 0; i <= maxElement; i++) {
        if(freqArr[i] == 1) {
            // cout<<"Unique Element Found : "<<i<<endl;
            return true;
        }
    }
    return false;
}

bool checkUnique2(vector<int> v) {
    if(v.size() < 1) return false;

    map<int, int> freq;
    for(int i = 0; i < v.size(); i++) {
        freq[v[i]]++;
    }

    for(auto it : freq) {
        if(it.first == 1) {
            return true;
        }
    }
    return false;
}

int main() {
    int size;
    cin>>size;

    vector<int> v(size);
    for(int i = 0; i < size; i++) {
        cin>>v[i];
    }

    cout<<checkUnique2(v);
}