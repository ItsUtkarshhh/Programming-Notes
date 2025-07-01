#include<iostream>
#include<vector>
using namespace std;

int largestSum(vector<int> v, int k) {
    int i = 0; int j = i + 1;
    int sum = 0;
    int count = 0;
    while(i + 1 < v.size() && j < v.size()) {
        sum = v[i] + v[j] + sum;
        if(sum == k) {
            count = max(count, j - i + 1);
            i++; j++;
        }
        else if(sum < k) {
            j++;
        }
        else {
            i++; j++;
        }
    }
    return count;
}

int main() {
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i = 0; i<n; i++) {
        cin>>v[i];
    }
    int sum;
    cin>>sum;
    cout<<largestSum(v, sum);
}