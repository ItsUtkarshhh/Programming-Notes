#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<vector<int>> findPairSum(vector<int> v, int sum) {
    vector<vector<int>> valPair;
    vector<int> valSum;
    for(int i = 0; i < v.size(); i++) {
        for(int j = i + 1; j < v.size(); j++) {
            if(v[i] + v[j] == sum) {
                valSum.push_back(min(v[i], v[j]));
                valSum.push_back(max(v[i], v[j]));
                valPair.push_back(valSum);
            }
        }
        valSum.pop_back();
        valSum.pop_back();
    }
    sort(valPair.begin(), valPair.end());
    return valPair;
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
    vector<vector<int>> ans = findPairSum(v, sum);
    if (ans.size() == 1 && ans[0].size() == 1 && ans[0][0] == -1) {
        cout << "[-1]";
    }
    else {
        cout << "[";
        for (int i = 0; i < ans.size(); i++) {
            cout << "[";
            for (int j = 0; j < ans[i].size(); j++) {
                cout << ans[i][j];
                if (j != ans[i].size() - 1) cout << ", ";
            }
            cout << "]";
            if (i != ans.size() - 1) cout << ", ";
        }
        cout << "]";
    }
}