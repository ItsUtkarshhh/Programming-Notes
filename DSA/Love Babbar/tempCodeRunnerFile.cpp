#include<iostream>
using namespace std;

void LCM(int n1, int n2) {
    int value = max(n1,n2);
    while(1) {
        if(value % n1 == 0 && value % n2 == 0) {
            cout<<value;
            return;
        }
        value++;
    }
}

int main() {
    int n1,n2;
    cin>>n1>>n2;
    LCM(n1,n2);
}