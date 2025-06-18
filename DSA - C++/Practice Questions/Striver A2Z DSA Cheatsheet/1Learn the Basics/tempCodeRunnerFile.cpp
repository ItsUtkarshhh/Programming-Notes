#include<iostream>
using namespace std;

int main() {
    int n;
    cin>>n;
    for(int i = 1; i <= n; i++) {
        int space = ((2 * (n - i + 1)) - 2)/2;
        while(space) {
            cout<<" "<<" ";
            space--;
        }
        
        int stars = (2 * i) - 1;
        while(stars) {
            cout<<"*"<<" ";
            stars--;
        }

        space = ((2 * (n - i + 1)) - 2)/2;
        while(space) {
            cout<<" "<<" ";
            space--;
        }
        cout<<endl;
    }
}