#include<iostream>
#include<vector>
#include<unordered_set>
#include<climits>
using namespace std;
// -8 2 3 -6 11
vector<int> firstNegativeBF(vector<int> arr, int k) {
    vector<int> ans;
    for(int i = 0; i <= arr.size() - k; i++) {
        int index = INT_MAX;
        int found = false;
        for(int j = i; j < i + k; j++) {
            if(arr[j] < 0) {
                index = j;
                found = true;
                ans.push_back(arr[index]);
                break;
            }
        }
        if(found == false) {
            ans.push_back(0);
        }
    }
    return ans;
}

int main() {
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i = 0; i<n; i++) {
        cin>>v[i];
    }
    int windowSize;
    cin>>windowSize;
    vector<int> res = firstNegativeBF(v, windowSize);
    for(int i = 0; i < res.size(); i++) {
        cout<<res[i]<<" ";
    }
}