#include<iostream>
using namespace std;

int main() {
    int n;
    cin>>n;
    start :
    cout<<"Number : "<<n<<endl;
    n++;

    if(n < 5) {
        goto start;
    }
    else {
        cout<<"Limit reached!";
    }
}