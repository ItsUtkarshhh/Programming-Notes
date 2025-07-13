#include<iostream>
#include<vector>
using namespace std;

vector<int> rearrangePosNeg(vector<int> v) {
    int n = v.size();
    vector<int> pos, neg;

    for (int i = 0; i < n; i++) {
        if (v[i] >= 0)
            pos.push_back(v[i]);
        else
            neg.push_back(v[i]);
    }

    vector<int> result(n);
    int i = 0, p = 0, q = 0;

    while (p < pos.size() && q < neg.size()) {
        result[i++] = pos[p++];
        result[i++] = neg[q++];
    }
    while (p < pos.size()) {
        result[i++] = pos[p++];
    }
    while (q < neg.size()) {
        result[i++] = neg[q++];
    }

    return result;
}

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    vector<int> result = rearrangePosNeg(v);
    for (int val : result) {
        cout << val << " ";
    }
    return 0;
}