#include<iostream>
using namespace std;

int main() {
    // Pointers -> A unique data type which stores the address of other variables.
    int a = 3;
    int* b = &a; 
    cout<<"The address of a : "<<b<<endl; 
    cout<<"The address of a : "<<&a<<endl; // & is a "address of" operator which stores address of the variable.

    cout<<"The value at address stored in b is : "<<*b<<endl; // * is "value at address operator" which is also called a de-refrencing operator, where we get the "value at the address which is stored in".

    // Pointer to Pointer
    int** c = &b;
    cout<<"The address of b : "<<c<<endl;
    cout<<"The address of b : "<<&b<<endl;
    cout<<"The value at address stored in c : "<<*c<<endl;
    cout<<"The value at the value at address stored in c : "<<**c<<endl;
    return 0;
}