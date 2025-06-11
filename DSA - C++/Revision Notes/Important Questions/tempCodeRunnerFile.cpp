#include<iostream>
#include<vector>
using namespace std;

int main() {
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i = 0; i < n; i++) {
        cin>>v[i];
    }
    if((v[n-1] % 10) == 0) {
        cout<<"Divisible by 10";
    }
    else {
        cout<<"Not divisible by 10";
    }
}