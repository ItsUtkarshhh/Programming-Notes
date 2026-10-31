#include<iostream>
#include<vector>
using namespace std;

bool isSorted_Helper(vector<int> &nums, int start) {
    if(start >= nums.size() - 1) return true;

    if(nums[start] > nums[start + 1]) return false;
    return isSorted_Helper(nums, start + 1);
}

bool isSorted(vector<int>& nums){
    if(nums.empty()) return true;
    return isSorted_Helper(nums, 0);
}

int main() {
    int size;
    cin>>size;

    vector<int> v(size);
    for(int i = 0; i < size; i++) {
        cin>>v[i];
    }

    cout<<isSorted(v);
}