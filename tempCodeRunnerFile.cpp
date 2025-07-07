#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
#include<map>
#include<unordered_map> // For better!
#include<set>
#include<unordered_set> // For better!
using namespace std;

int removeDuplicates(vector<int> v) {
    int n = v.size();
    int i = 0; int j = n - 1;
    while(i < j) {
        if(v[i] == v[i+1]) {
            swap(v[i+1], v[j]);
            j--;
            i++;
        }
        i++;
    }
    return i + 1;
}

int main() {
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i = 0; i < n; i++) {
        cin>>v[i];
    }
    int newLen = removeDuplicates(v);
    for(int i = 0; i < newLen; i++) {
        cout<<v[i]<<" ";
    }
}