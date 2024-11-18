#include<iostream>
using namespace std;

// int fact(int n) {
//     int ans = 1;
//     for(int i = n; i>0; i--) {
//         ans = ans*i;
//     }
//     return ans;
// }

int fact(int n) {
    if(n == 0) {
        return 1;
    }
    return n * fact(n-1);
}

int main() {
    int n;
    cin>>n;
    cout<<fact(n);
}