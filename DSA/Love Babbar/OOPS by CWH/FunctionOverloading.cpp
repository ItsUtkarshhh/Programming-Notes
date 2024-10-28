// Here in Function overloading we used same functions with different number of arguments, we can also use different data types of arguments, and each function we created will perform independently. This is Function Overloading.
// And it is an Example of POLYMORPHISM.
#include<iostream>
using namespace std;

int sum(int a, int b) {
    return a+b;
}

int sum(int x, int y, int z) {
    return x+y+z;
}

//Volume of Cube
int volume(int s) {
    return s*s*s;
}

//Volume of cylinder
int volume(int r, int h) {
    return 3.14*r*r*h;
}

//Volume of Cuboid
int volume(int l, int b, int h) {
    return l*b*h;
}

int main() {
    cout<<"Sum of 2 arguments : "<<sum(5,5)<<endl;
    cout<<"Sum of 3 arguments : "<<sum(5,5,5)<<endl;
    cout<<"Volume of a cube : "<<volume(5)<<endl;
    cout<<"Volume of a cylinder :"<<volume(5,5)<<endl;
    cout<<"Volume of a cuboid : "<<volume(5,5,10)<<endl;
    return 0;
}

#include<iostream>
using namespace std;

int sum(float a, float b) {
    return a+b;
}

int sum(int a, int b) {
    return a+b;
}

int sum(float a, float b, float c) {
    return a+b+c;
}

int sum(int a, int b, int c) {
    return a+b+c;
}

int main() {
    cout<<sum(3,4)<<endl; // This is called : int sum(int a, int b)
    cout<<sum(4,5)<<endl; // This is called : int sum(int a, int b)
    cout<<sum(5,6,7)<<endl; // This is called : int sum(int a, int b, int c)
    cout<<sum(6,7,8)<<endl; // This is called : int sum(int a, int b, int c)

    cout<<sum(6.0,7.0)<<endl; // This is called : int sum(float a, float b)
    cout<<sum(6,7,8)<<endl; // This is called : int sum(float a, float b, float c)
} // Here int can be converted to float but float can't be converted into int, coz of typecasting is not possible in every vice versa.
// Imp : Changing data type of function is not considered under function overloading! only the change in number of parametres and type of parameters are considered under function overloading!