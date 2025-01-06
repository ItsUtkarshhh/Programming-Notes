#include<iostream>
#include<string>
#include<vector>
using namespace std;

void printVector(vector<string> v) {
    for(int i = 0; i<v.size(); i++) {
        cout<<v[i]<<" ";
    }
    cout<<endl;
}

void compress(vector<string> v) {
    int i = 0;
    vector<string> ans;
    while(i<v.size()) {
        int j = i+1;
        if(j<v.size() && v[i] == v[j]) {
            j++;
        }
        int count = j-i;
        ans.push_back(v[i]);
        if(count > 1) {
            string cnt = to_string(count);
            for(char ch : cnt) {
                ans.push_back(string(1,ch));
            }
        }
        i = j;
    }
    printVector(ans);
}

int main() {
    int n;
    cin>>n;
    vector<string> v1(n);
    for(int i = 0; i<n; i++) {
        cin>>v1[i];
    }
    compress(v1);
}