#include<iostream>
using namespace std;

bool isPrime(int val) {
    if(val == 1) return false;
    for(int i = 2; i < val; i++) {
        if(val % i == 0) {
            return false;
        }
    }
    return true;
}

void printPrime(int ll, int ul) {
    for(int i = ll; i <= ul; i++) {
        if(isPrime(i)) {
            cout<<i<<" ";
        }
    }
}

int main() {
    int ll, ul;
    cin>>ll>>ul;
    printPrime(ll, ul);
}