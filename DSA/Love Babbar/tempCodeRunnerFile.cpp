#include<iostream>
using namespace std;

int main() {
    int a = 65;
    int& b = a; // Refrence variable b, here the memory location where 5 is stored with the name 'a' similary here we added another name for the memory location where 65 is stored!
    cout<<"Value of a :"<<a<<endl;
    cout<<"value of b :"<<b<<endl;
    return 0;
}