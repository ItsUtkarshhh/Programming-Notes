// Pattern 11 : Print pattern like 1 -> 0 1 -> 1 0 1 -> 0 1 0 1...
#include<iostream>
using namespace std;

int main() {
    int n;
    cin>>n;
    int binary = 1;
    for(int i = 1; i<=n; i++) {
        if(i%2 != 0) {
            binary = 1;
        }
        else {
            binary = 0;
        }
        for (int j = 1; j<=i; j++) {
            cout<<binary<<" ";
            binary = 1 - binary;
        }
        cout<<endl;
    }
}
