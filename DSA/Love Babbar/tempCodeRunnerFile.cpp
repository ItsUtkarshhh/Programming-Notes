#include<iostream>
#include<climits>
using namespace std;

char maxOccChar(string str) {
    int count[26] = {0};
    for(int i = 0; i<str.length(); i++) {
        int index = str[i] - 'A'  + 'a';
        count[index]++;
    }
    int maxi = INT_MIN;
    int charNum = -1;
    for(int i = 0; i<26; i++) {
        if(count[i] > maxi) {
            maxi = count[i];
            charNum = i;
        }
    }
    return 'A' + charNum;
}

int main() {
    string str;
    cin>>str;
    cout<<maxOccChar(str);
}