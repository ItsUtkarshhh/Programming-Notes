#include<iostream>
using namespace std;

int product(int a,int b); // Function prototype or Function declaration
// can also write int product(int, int); that we are just telling the compiler that we are introducing a function which will comtain 2 arguments of int type!

void greet(void); // Means it won't return a value also it won't accept any vaue value either. its just to perform a task and that't it.
// We can also write it as void greet(), both means the same.

int main() {
    int num1, num2;
    cout<<"Enter first number : ";
    cin>>num1;
    cout<<"Enter second number : ";
    cin>>num2;
    cout<<"Product of the two numbers : "<<product(num1,num2)<<endl; //Function call and the value passed in function call are actual parameters.
    greet();
    return 0;
}

int product(int a, int b) { // Function Definition
    int c = a*b; // Here the value a and b are formal parameters. and a and b are taking values from actual parameters (or can say copy the values from actual parameters.
    return c; 
}

void greet() {
    cout<<"Hello, Good Morning"<<endl;
} // No return type is needed.

// Swapping two numbers!
#include<iostream>
using namespace std;

void swap1(int a,int b) {
    int temp = a;
    a = b;
    b = temp;
}

void swap2(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int x = 2;
    int y = 3;
    cout<<"Value of x "<<x<<" value of y "<<y<<endl;
    swap1(x,y); // Call by value, hence it will not swap!
    cout<<"Value of x "<<x<<" value of y "<<y<<endl;

    swap2(&x, &y); // Call by refrence, hence it will swap!
    cout<<"Value of x "<<x<<" value of y "<<y<<endl;
    return 0;
}