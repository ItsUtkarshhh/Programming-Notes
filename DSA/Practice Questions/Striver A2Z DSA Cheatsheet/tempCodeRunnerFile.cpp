#include<iostream>
using namespace std;

int main() {
    int n;
    cin>>n;
    for(int i = 1; i<=n; i++) {
        int space = n-1;
        while(space) {
            cout<<" "<<" ";
            space--;
        }

        for(int j = 1; j<=i; j++) {
            cout<<"*"<<" ";
        }

        space = n-1;
        while(space) {
            cout<<" "<<" ";
            space--;
        }
        cout<<endl;
    }
}