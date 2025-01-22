#include<iostream>
using namespace std;

int main() {
    int n;
    cin>>n;
    for(int i = 1; i<=n; i++) {
        for(int space = 0; space<n-i; space++) {
            cout<<" "<<" ";
        }

        for(int j = 1; j<=(2*i)-1; j++) {
            cout<<"*"<<" ";
        }

        for(int space = 0; space<n-i; space++) {
            cout<<" "<<" ";
        }
        cout<<endl;
    }
    for(int i = n; i>=1; i--) {
        for(int space = 0; space<n-i; space++) {
            cout<<" "<<" ";
        }

        for(int j = (2*i)-1; j>=1; j--) {
            cout<<"*"<<" ";
        }

        for(int space = 0; space<n-i; space++) {
            cout<<" "<<" ";
        }
        cout<<endl;
    }
}