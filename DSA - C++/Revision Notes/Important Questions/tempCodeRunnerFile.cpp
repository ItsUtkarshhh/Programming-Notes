#include<iostream>
using namespace std;

int main() {
    int nr, nc;
    cin>>nr>>nc;
    for(int i = 1; i<=nr; i++) {
        for(int j = 1; j<=nc; j++) {
            cout<<char('A' + i*j - 1)<<" ";
        }
        cout<<endl;
    }
}