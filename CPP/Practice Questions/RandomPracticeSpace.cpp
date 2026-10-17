#include<iostream>
#include<vector>
using namespace std;

// Both Sorted
vector<int> intersectionOfTwoArrays(vector<int>  v1, vector<int> v2) {
    if(v1.size() < 1  || v2.size() < 1) return {};

    vector<int> result;
    int first = 0; int second = 0;

    while(first < v1.size() && second < v2.size()) {
        if(v1[first] == v2[second]) {
            result.push_back(v1[first]);
            first++;
            second++;
        }
        else if(v1[first] > v2[second]) {
            second++;
        }
        else {
            first++;
        }
    }
    return result;
}

// Sorted vs Unsorted - Brute Force
vector<int> intersectionOfTwoArrays(vector<int>  v1, vector<int> v2) {
    if(v1.size() < 1  || v2.size() < 1) return {};

    vector<int> result;

    for(int i = 0; i < v1.size(); i++) {
        int val1 = v1[i];
        for(int j = 0; j < v2.size(); j++) {
            if(v2[j] == val1) {
                result.push_back(v2[j]);
                v2[j] = INT_MIN;
                break;
            }
        }
    }
    return result;
}

// Sorted vs Unsorted - Better Force
vector<int> intersectionOfTwoArrays(vector<int>  v1, vector<int> v2) {
    if(v1.size() < 1  || v2.size() < 1) return {};

    vector<int> result;

    for(int i = 0; i < v1.size(); i++) {
        int val1 = v1[i];
        for(int j = 0; j < v2.size(); j++) {
            if(v2[j] == val1) {
                result.push_back(v2[j]);
                v2[j] = INT_MIN;
                break;
            }
            else if(v2[j] > val1) {
                break;
            }
        }
    }
    return result;
}

int main() {
    int size1;
    cin>>size1;
    vector<int> v1(size1);
    for(int i = 0; i < size1; i++) {
        cin>>v1[i];
    }

    int size2;
    cin>>size2;
    vector<int> v2(size2);
    for(int i = 0; i < size2; i++) {
        cin>>v2[i];
    }

    vector<int> ans = intersectionOfTwoArrays(v1, v2);
    for(int i = 0; i < ans.size(); i++) {
        cout<<ans[i]<<" ";
    }

}