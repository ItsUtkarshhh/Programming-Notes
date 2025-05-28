#include<iostream>
using namespace std;

int main() {
    int nr, nc;
    cin>>nr>>nc;
    int count = 0;
    for(int i = 1; i<=nr; i++) {
        for(int j = 0; j<nc; j++) {
            cout<<char('A' + count)<<" ";
            count++;
        }
        cout<<endl;
    }
}