#include<iostream>
#include<map>
#include<set>
#include<vector>
using namespace std;

vector<vector<int>> findPairSum3(vector<int> v, int sum) {
    map<int, int> freq;
    set<pair<int, int>> valPair;

    for (int num : v) {
        freq[num]++;
    }

    for (int i = 0; i < v.size(); i++) {
        int complement = sum - v[i];

        // Case 1: Pair of same elements (like 2 + 2 = 4)
        if (v[i] == complement && freq[v[i]] >= 2) {
            valPair.insert({v[i], v[i]});
            freq[v[i]] = 0; // mark both used
        }

        // Case 2: Normal case with two different values
        else if (v[i] != complement && freq[v[i]] > 0 && freq[complement] > 0) { // You may remove : v[i] != complement
            valPair.insert({min(v[i], complement), max(v[i], complement)});
            freq[v[i]] = 0;
            freq[complement] = 0;
        }
    }

    vector<vector<int>> result;
    for (auto &i : valPair) {
        result.push_back({i.first, i.second});
    }

    return result.size() > 0 ? result : vector<vector<int>>{{-1}};
}

int main() {
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i = 0; i < n; i++) {
        cin>>v[i];
    }
    int sum;
    cin>>sum;
    vector<vector<int>> ans = findPairSum3(v, sum);
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