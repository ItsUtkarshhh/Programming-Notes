#include<iostream>
using namespace std;

void printFib(int n) {
    if(n <= 0) {
        cout<<"Invalid Position!";
        return;
    }
    if(n == 1) {
        cout<<0<<endl;
        return;
    }
    else if(n == 2) {
        cout<<0<<" "<<1<<endl;
        return;
    }
    else {
        int first = 0;
        int second = 1;
        while(n != 0) {
            int next = first + second;
            cout<<first<<" ";
            first = second;
            second = next;
            n--;
        }
    }
    return;
}

int main() {
    int n;
    cin>>n;
    printFib(n);
}