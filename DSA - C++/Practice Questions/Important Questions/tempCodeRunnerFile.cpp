#include<iostream>
#include<string>
using namespace std;

int main() {
    string num;
    cin>>num;
    int res = 0;
    for(char bit : num) {
        res = res * 2 + (bit - '0');
    }
    cout<<res;
}