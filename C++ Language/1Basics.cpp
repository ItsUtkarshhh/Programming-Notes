// With namespace std;
#include<iostream>
using namespace std;
int main() {
    cout<<"Hello World";
    return 0;
}

// Without namespace std;
#include<iostream>
int main() {
    std::cout<<"Hello World";
    return 0;                 
}

// Use of Scope resolution operator
#include<iostream>
using namespace std;

int c = 65;

int main() {
    int a,b,c;
    cout<<"Enter the number :"<<endl;
    cin>>a>>b;
    c = a + b;
    cout<<"The sum of two numbers :"<<c<<endl; 
    cout<<"Value of global C :"<<::c; // Here we used scope resolution operator to access the c outside the main function, as "scope" resolution operator is the name itself enough to understand.
    return 0;
}

#include<iostream>
#include<typeinfo>
using namespace std;

int main() {
    float x = 34.4f; // "f" or "F" is used to specify float number
    long double y = 34.4l; // "l" or "L" is used to specify long double number

    // By default in C++ floating point numbers are treated as double, to convert them into float we have to use type casting
    cout<<typeid(3.14).name(); // It is printing d means it is a double value by default!
    // 34.4 -> its a double, to convert it into float we will write f after it
    // 34.4f now its a floating point number
    cout<<"the value of x is : "<<x<<endl<<"the value of y is : "<<y<<endl;
    return 0;
}

// Sizeof() Operator
#include<iostream>
using namespace std;

int main() {
    float x = 34.4f; // "f" or "F" is used to specify float number//
    long double y = 34.4l; // "l" or "L" is used to specify long double number//

    cout<<"the size of 34.4 is :"<<sizeof(34.4)<<endl;
    cout<<"the size of 34.4f is :"<<sizeof(34.4f)<<endl;
    cout<<"the size of 34.4F is :"<<sizeof(34.4F)<<endl;
    cout<<"the size of 34.4l is :"<<sizeof(34.4l)<<endl;
    cout<<"the size of 34.4L is :"<<sizeof(34.4L)<<endl;

    return 0;
}

// Refrence Variables
#include<iostream>
using namespace std;

int main() {
    int a = 65;
    int& b = a; // Refrence variable b, here the memory location where 5 is stored with the name 'a' similary here we added another name for the memory location where 65 is stored
    cout<<"Value of a :"<<a<<endl;
    cout<<"value of b :"<<b<<endl;
    return 0;
}


#include<iostream>
using namespace std;

// Pass by Value
void update(int n) { // Here the value of x is copied that's why it won't affect the x value in main()
    n++;
    cout<<"Update1 value : "<<n<<endl;
}

// Pass by Reference
void update2(int &y) { // Here we used refrence variable hence "y" became another name for the "x" variable where 65 is stored and hence on changing value in y changes the value in x too
    y++;
}

int main() {
    int x = 65;
    cout<<"Before : "<<x<<endl;
    update(x);
    cout<<"After : "<<x<<endl;
    update2(x);
    cout<<"Update2 Value : "<<x<<endl;
    return 0;
}


// Type casting
#include<iostream>
#include<iomanip>
using namespace std;

int main() {
   float a = 45.66666;
   float b = 65.50;
   cout<<"The value of a is : "<<a<<endl;
   cout<<"The value of b is : "<<b<<endl;
   cout<<"The value of b in int type (using typecasting) : "<<int(b)<<endl;
   cout<<"The value of b in int type (using typecasting) : "<<(int)b<<endl; 
   cout<<"The value of a in float type (using typecasting) : "<<float(a)<<endl;
   cout<<"The value of a in float type (using typecasting) : "<<setprecision(4)<<(float)a<<endl; // In type casting we just write that data type in which we want to print the number with parentheses ().
   printf("The value of a in float type (using typecasting) : %.5f\n", (float)a);
   return 0; 
}

// Constants in C++ : In C++, constants are values that do not change during the execution of a program. They are useful for defining fixed values that have semantic meaning within your code. There are several ways to define constants in C++:
//                  : Constants can be defined using 4 keywords, 1) "Const" 2) "Constexpr" 3) "Enum" 4) "#define".
//                  : Const : The const keyword is used to declare constants. A constant variable must be initialized at the time of its declaration.
//                  : Constexpr : The constexpr keyword is used to define constants that can be evaluated at compile time. This is more powerful than const because it guarantees that the value is a compile-time constant.
//                  : Enum : Enumerations are a way to define a set of named integer constants. They are often used to represent a collection of related values.
//                  : Macros (#define) : Macros are a preprocessor feature that defines constants. However, they are generally discouraged in modern C++ due to their lack of type safety and scope control.
// There values cannot be changed!
// Example 1 :
#include<iostream>
using namespace std;

int main() {
    const int a = 65;
    cout<<"Before changing value : "<<a<<endl;
    // a = 45; // Here you will get an error because "a" is a constant.
    cout<<"Before changing value : "<<a<<endl; // Here after writting "const" before "int a", now we can't change the value because of the constant keyword.
    return 0;
}

// Example 2 :
#include <iostream>
using namespace std;

constexpr int factorial(int n) {
    return (n <= 1) ? 1 : (n * factorial(n - 1));
}

int main() {
    constexpr int result = factorial(5);
    cout << "Factorial of 5 is: " << result << endl;
    return 0;
}

// Example 3 :
#include <iostream>
using namespace std;

enum Colors { RED, GREEN, BLUE };

int main() {
    Colors myColor = GREEN;
    if (myColor == GREEN) {
        cout << "The color is green." << endl;
    }
    return 0;
}

// Example 4 :
#include <iostream>
using namespace std;

#define MAX_SIZE 100

int main() {
    cout << "Max Size: " << MAX_SIZE << endl;
    return 0;
}

// Manipulators : Setw() and Setfill().
// Detailed Explaination of Setw : In C++, setw is a manipulator used with output streams (such as cout) to set the width of the next output field. This is part of the <iomanip> library, which provides a set of stream manipulators that can be used to control the formatting of output.
//                                    : Ye outputs ko format krne me kaam aata hai! jaise agar setw(5) likh diya and jo humara output hai vo 5 characters se kam ka hai toh ye left me kuch spaces chhor dega unn characters ke hisaab se!
//                                    : If the output is longer than n characters, it will not be truncated; instead, it will be displayed in full, ignoring the width setting. here we use setfill function!
// Example :
#include <iostream>
#include <iomanip>  // Include the iomanip library

int main() {
    int num = 123;
    double pi = 3.14159;

    std::cout << std::setw(10) << num << std::endl;      // Outputs "       123"
    std::cout << std::setw(10) << pi << std::endl;       // Outputs "   3.14159"
    std::cout << std::setw(10) << "Hello" << std::endl;  // Outputs "     Hello"

    // You can also chain manipulators
    std::cout << std::setw(10) << std::setfill('*') << num << std::endl; // Outputs "*******123", means ki pehle humne set krdiya ki 10 characters ka jagah output lega! and then agar output usse chhota hai toh humare paas choice hai ki yaa toh usko hum khaali chhor de, yaa toh setfill ka use krke unn spaces ko fill krde! and agar output more than 10 characters hota toh simply vo jo limit hai uski koi value nhi rehti!

    return 0;
}
