#include<iostream>
using namespace std;

bool checkPowerOf2(int num) {
    return num > 0 && (num & (num - 1)) == 0;
}

int main() {
    int num;
    cin>>num;
    if(checkPowerOf2(num)) {
        cout<<"Yes "<<num<<" is a power of 2";
    }
    else {
        cout<<"No "<<num<<" is not a power of 2";
    }
}