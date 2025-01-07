#include<iostream>
#include<vector>
#include<string>
using namespace std;

void solve(string str, int index, string output, vector<string> &ans) {
    if(index >= str.length()) {
        if(output.length() > 0) {
            ans.push_back(output);
        }
        return;
    }

    solve(str,index+1,output,ans);

    output.push_back(str[index]);
    solve(str,index+1,output,ans);
}

vector<string> subsequences(string str) {
    vector<string> ans;
    string output;
    int index = 0;
    solve(str, index, output, ans);
    return ans;
}

int main() {
    string str;
    cout<<"Enter your string : ";
    cin>>str;

    vector<string> result = subsequences(str);
    for(const auto &subsequence : result) {
        cout<<subsequence<<" ";
    }
}