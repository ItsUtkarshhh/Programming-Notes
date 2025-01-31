#include<iostream>
using namespace std;

int main() {
    int n;
    cin>>n;
    for(int i = 1; i<=n; i++) {
        for(int star = 0; star<=n-i; star++) {
            cout<<"*"<<" ";
        }

        for(int space = 1; space<(2*i)-1; space++) {
            cout<<" "<<" ";
        }

        for(int star = 0; star<=n-i; star++) {
            cout<<"*"<<" ";
        }
        cout<<endl;
    }
    for(int i = n; i>=1; i--) {
        for(int star = 0; star<=n-i; star++) {
            cout<<"*"<<" ";
        }

        for(int space = (2*i)-1; space>1; space--) {
            cout<<" "<<" ";
        }

        for(int star = 0; star<=n-i; star++) {
            cout<<"*"<<" ";
        }
        cout<<endl;
    }
}