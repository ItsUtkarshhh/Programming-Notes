#include<iostream>
#include<climits>
#include<vector>
using namespace std;

int minimumIndex(vector<int>& capacity, int itemSize) {
    int minSize = INT_MAX;
    int minSizeIndex = -1;
    for(int i = 0; i < capacity.size(); i++) {
        if(capacity[i] < minSize && capacity[i] >= itemSize) {
            minSize = capacity[i];
            minSizeIndex = i;
        }
    }
    return minSizeIndex;
}

int smallestBalancedIndex(vector<int>& nums) {
    int minIndex = INT_MAX;
    for(int i = 0; i < nums.size(); i++) {
        int sum = 0;
        int prod = 1;
        for(int j = 0; j < i; j++) {
            sum += nums[j];
        }
        for(int k = nums.size() - 1; k > i; k--) {
            prod *= nums[k];
        }
        if(sum == prod) {
            minIndex = min(minIndex, i);
        }
    }
    if(minIndex == INT_MAX) return -1;
    return minIndex;
}

int main() {
    vector<int> arr = {2,1,2};
    // int itemSize = 5;
    cout<<smallestBalancedIndex(arr);
}