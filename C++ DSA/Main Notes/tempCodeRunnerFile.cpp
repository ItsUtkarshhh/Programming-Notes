#include<iostream>
using namespace std;

int main() {
    int nr; int nc;
    cin>>nr>>nc;

    for(int i = 0; i < nr; i++) {
        for(int j = 0; j <= i; j++) {
            cout<<char('A' + (nr - i + j - 1));
        }
        cout<<endl;
    }
}