#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

vector<vector<int>> pairSum(vector<int> v1, vector<int> v2, int sum) {
    vector<vector<int>> ansPair;
    for(int i = 0; i<v1.size(); i++) {
        for(int j = i+1; j<v2.size(); j++) {
            if(v1[i] + v2[j] == sum) {
                vector<int> temp;
                temp.push_back(min(v1[i], v2[j]));
                temp.push_back(max(v1[i], v2[j]));
                ansPair.push_back(temp);
            }
        }
    }
    sort(ansPair.begin(), ansPair.end())
    return ansPair
}

int main() {
    int n1,n2;
    cin>>n1>>n2;
    vector<int> arr1(n1);
    vector<int> arr2(n2);
    for(int i = 0; i<n1; i++) {
        cin>>arr1[i];
    }
    for(int i = 0; i<n2; i++) {
        cin>>arr2[i];
    }
    int sum;
    cin>>sum;
    vector<vector<int>> ans = pairSum(arr1,arr2);
    
}