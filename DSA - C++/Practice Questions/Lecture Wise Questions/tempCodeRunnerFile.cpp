#include<iostream>
#include<string>
using namespace std;

string removeOccurence(string strMain, string strSub) {
    string res = "";
    int subLen = strSub.length();

    for(int i = 0; i < strMain.length(); i++) {
        res += strMain[i]; // Simulate stack push

        // If last part of res matches strSub, remove it
        if(res.size() >= subLen && res.substr(res.size() - subLen) == strSub) {
            res.erase(res.size() - subLen); // Simulate stack pop
        }
    }
    return res.empty() ? "Empty String" : res;
}

int main() {
    string strMain;
    cin>>strMain;
    string strSub;
    cin>>strSub;
    string result = removeOccurence(strMain, strSub);
    if(result != "") cout<<result;
    else cout<<"Empty string";
}