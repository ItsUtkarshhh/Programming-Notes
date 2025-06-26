#include<iostream>
#include<vector>
using namespace std;

vector<int> reverseAfterK(vector<int> &v, int k) {
    int start = k;
    int end = v.size() - 1;
    while(start <= end) {
        swap(v[start], v[end]);
        start++;
        end--;
    }
}

int main() {
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i = 0; i < n; i++) {
        cin>>v[i];
    }
    int index;
    cin>>index;
    reverseAfterK(v, index);
    for(int i = 0; i < n; i++) {
        cout<<v[i]<<" ";
    }
}