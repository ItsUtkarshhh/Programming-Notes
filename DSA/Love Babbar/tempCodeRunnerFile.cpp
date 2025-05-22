#include<iostream>
#include<typeinfo> // To check type related info
using namespace std;

int main() {
    float x = 34.4f; // "f" or "F" is used to specify float number
    long double y = 34.4l; // "l" or "L" is used to specify long double number

    // By default in C++ floating point numbers are treated as double, to convert them into float we have to use type casting
    // 34.4 -> its a double, to convert it into float we will write f after it
    // 34.4f now its a floating point number
    cout<<"the value of x is : "<<x<<endl<<"the value of y is : "<<y<<endl;

    float i = 3.14;
    cout<<sizeof(i)<<endl;
    cout<<typeid(i).name()<<endl; // It will print float! as it was already declared and initiallized using float! so it will print float!
    cout<<typeid(3.14).name()<<endl; // It will print double! as decimals are treated as double by default in C++
    return 0;
}