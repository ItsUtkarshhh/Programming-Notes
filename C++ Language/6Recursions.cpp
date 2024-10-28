// Calling a function in a function defintion.
// Solving factorial using recursions.
#include<iostream>
using namespace std;

int factorial(int n) {
    if (n<=1) {
        return 1;
    }
    return n*factorial(n-1); // Here we called the funcytion in the function defintion.
}

int main() {
    int a;
    cout<<"Enter the number : "<<endl;
    cin>>a;
    cout<<"Factorial of "<<a<<" is : "<<factorial(a)<<endl;
    return 0;

} // Gives correct answers upto 16 only. becoz of the range of int! to get more values we can use long or long long int!

// Solving fibonacci sequence using recursions.
#include<iostream>
using namespace std;

int fib(int n) {
    if (n<=0) {
        return 0;
    }
    else if (n==1) {
        return 1;
    }
    else {
        return fib(n-1) + fib(n-2);
    }
} // Nere our logic is accorind to indexes not positions, so start with 0th index!

int main() {
    int a;
    cout<<"Enter the number : ";
    cin>>a;
    cout<<"The Fibonacci sequence upto "<<a<<" is : "<<fib(a);
    return 0;
} // Here to print fibonacci sequence, the itterative approach will be better if we se while printing fib(5) it will calculate fib(3) two times, which will take more time and which is not the best way to solve the problem, so we should use the recursive approach where it is useful, otherwise don't, and use itterative approach rather.