#include<iostream>
#include<vector>
using namespace std;

pair<int, int> twoSum2_V2(vector<int> v, int k) {
    int n = v.size();
    int i = 0; int j = n - 1;
    while(i < j) {
        int sum = v[i] + v[j];
        if(sum == k) return {i, j};
        if(sum > k) j--;
        else i++;
    }
    return {-1, -1};
}

int main() {
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i = 0; i < n; i++) {
        cin>>v[i];
    }
    int k;
    cin>>k;
    pair<int, int> ans = twoSum2_V2(v, k);
    cout<<"["<<ans.first<<", "<<ans.second<<"]"<<endl;
}