#include<iostream>
using namespace std;

int main() {
    int numR;
    cin>>numR;
    int n = numR / 2;
    for(int i = 1; i <= n; i++) {
        int spaces = n - i;
        while(spaces) {
            cout<<" "<<" ";
            spaces--;
        }

        int stars = (2 * i) - 1;
        while(stars) {
            cout<<"*"<<" ";
            stars--;
        }

        spaces = n - i;
        while(spaces) {
            cout<<" "<<" ";
            spaces--;
        }
        cout<<endl;
    }
    for(int i = n; i >= 1; i--) {
        int spaces = n - i;
        while(spaces) {
            cout<<" "<<" ";
            spaces--;
        }

        int stars = (2 * i) - 1;
        while(stars) {
            cout<<"*"<<" ";
            stars--;
        }

        spaces = n - i;
        while(spaces) {
            cout<<" "<<" ";
            spaces--;
        }
        cout<<endl;
    }
}