#include<iostream>
using namespace std;

int main() {
    int num;
    cin>>num;
    int val = num;
    int count = 0;
    int mask = 0;
    while(val != 0) {
        mask = (mask << 1) | 1;
        val = val >> 1;
    }
    cout<<((~num) & (val));
}