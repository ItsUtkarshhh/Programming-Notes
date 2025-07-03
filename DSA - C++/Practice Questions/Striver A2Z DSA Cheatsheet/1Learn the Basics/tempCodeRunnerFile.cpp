#include<iostream>
using namespace std;

int main() {
    int n;
    cout<<"Enter an odd number : ";
    cin>>n;
    for(int i = 1; i <= n; i++) {
        if(i < (n/2 + 1)) {
            for(int j = 1; j <= i; j++) {
                cout<<"*"<<" ";
            }
            cout<<endl;
        }
        else {
            for(int j = 1; j <= (n - i + 1); j++) {
                cout<<"*"<<" ";
            }
            cout<<endl;
        }
    }
}