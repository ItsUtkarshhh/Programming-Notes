// ---------------------------------------------------------- Lecture 67 : Function Templates -------------------------------------------------------------------------------------------->
// To understand this go and study class templates! so, just like class templates! yahaa hum templates ko same purpose ke liye use krte hai! generalise krne ke liye functions ko! vahaa class ko generalize kr rhe the and yahaa functions ko!
#include<iostream>
using namespace std;

float findAverage(int a, int b) { // This function take two parameters of int type and find the average as a float value!
    float average = (a+b)/2.0;
    return average;
}

float findAverage(int a, float b) { // This function take two parameters one of int type and one of float type and find the average as a float value!
    float average = (a+b)/2.0;
    return average;
}

float findAverage(float a, float b) { // This function take two parameters of float type and find the average as a float value!
    float average = (a+b)/2.0;
    return average;
}

// int findAverage(int a, int b) { // This function take two parameters as int type and find the average as a int value!
//     int average = (a+b)/2;
//     return average;
// }
// Note : In C++, function overloading allows multiple functions to have the same name as long as their parameter lists (signatures) are different. However, having two functions with the exact same parameter list but different return types is not allowed because the compiler cannot distinguish between them based on return type alone.
// So we can't keep the last findAverage() function!

int main() {
    cout<<findAverage(1,2)<<endl;
    cout<<findAverage(1,2.5f)<<endl;
    cout<<findAverage(1.5f,2.5f)<<endl;
    // cout<<findAverage(1,2)<<endl;
}
// But as we can see hume alag alag values ke liye alag alag functions bnane pad rhe hai average ke liye! also ambiguity bhi generate hojaa rhi hai! so best ki ki hum ek template bnaa le taaki naa hi itne functions bnaane pade and na hi koi ambiguity ho!

// Using Templates for functions!
#include <iostream>
using namespace std;

template <typename T1, typename T2>
auto findAverage(T1 a, T2 b) -> decltype((a + b) / 2.0) { // auto is used here to indicate that the return type will be deduced automatically.
    return (a + b) / 2.0;
} // The trailing return type syntax (-> decltype(...)) specifies that the return type of the function is determined by the type of the expression (a + b) / 2.0. This is something new you can understand!
// decltype((a + b) / 2.0) deduces the type of the expression (a + b) / 2.0, ensuring that the return type is exactly what this expression would yield.

// Ek tarah se mtlb ye samajh lo, ki "auto findAverage(T1 a, T2 b) -> decltype((a + b) / 2.0)" yahaa ye likhne ka mtlb ye hua ki ye jo expression hai (a + b) / 2.0, decltype usko deduce krega and jo bhi return type samajh ayega uss type me auto keyword kaam krega! and uss type ka function ka return type ban jayega!
// In proper language : When you write auto findAverage(T1 a, T2 b) -> decltype((a + b) / 2.0), it means that the decltype keyword will deduce the return type based on the expression (a + b) / 2.0. The auto keyword is used in conjunction with decltype to automatically determine and use this deduced type as the return type of the function.
// In short, In other words, decltype((a + b) / 2.0) figures out what the type of (a + b) / 2.0 is, and auto ensures that the function returns a value of this type.

int main() {
    cout << findAverage(1, 2) << endl;        // Calls findAverage(int, int)
    cout << findAverage(1, 2.5f) << endl;     // Calls findAverage(int, float)
    cout << findAverage(1.5f, 2.5f) << endl;  // Calls findAverage(float, float)
    return 0;
}
// You can use a more simplistic approach for functional templates, this is just an example jab zyda ambiguity hojaye tab iase krlo! otherwise a more simplistic example for function templates are given below...

// Another example (Simpler example) :
#include<iostream>
using namespace std;

template <typename T>
void swapp(T &a, T &b) {
    T temp = a;
    a = b;
    b = temp;
}

int main() {
    int a = 5;
    int b = 4;
    cout<<a<<" "<<b<<endl;
    swapp(a,b);
    cout<<a<<" "<<b<<endl;

    // We dont need to make another function for float values! becoz we have declared the swapp() function using templates!
    float x = 5;
    float y = 4;
    cout<<x<<" "<<y<<endl;
    swapp(x,y);
    cout<<x<<" "<<y<<endl;
}

// ---------------------------------------------------------- Lecture 68 : Member Function Templates and Overloading Template Functions -------------------------------------------------------------------------------------------->
// Member Functions Templates :
#include<iostream>
using namespace std;

template <typename T>
class myClass {
    public:
    T data;
    myClass(T v) {
        data = v;
    }
    // void display() { // Lets make this display function out of the class definition!
    //     cout<<data<<endl;
    // }
    void display();
};

template <typename T>
void myClass<T> :: display() {
    cout<<data<<endl;
}

int main() {
    myClass<int> Utkarsh(365);
    cout<<Utkarsh.data<<endl;
    Utkarsh.display();
} // Hence yaahaa se you understood is that, ki harr class and harr member functions ke liye yaa kisi aur general functions ke liye bhi alag se templates define/declare krna hota hai! taaki compiler ko ptaa rhe ki konse class/function me templates use kiye gye hai ya nhi!

// Now lets understand the other part...
// Overloading Template Functions :
#include<iostream>
using namespace std;

void func(int a) {
    cout<<"This is first function, "<<a<<endl;
}

template <typename T>
void func(T a) {
    cout<<"This is templatised function, "<<a<<endl;
}

int main() {
    func(5); // Isme ye confusion hota hai ki konsa function call hoga, template vaala ya bina uske vaala, so yahaa call hoga jisse ye function call exactly match krta hai! and that is normal vaala func()
    func(5.5);  // Calls the template function because there is no exact match for double.
    func('A');  // Calls the template function because there is no exact match for char.
    func("Hello");  // Calls the template function because there is no exact match for const char*.
}
// So yahaa samjhaana ye chah rhe hai ki, agar ek function call hoti hai and same function ke liye do functions hai, one is regular function and another is template function, then compiler goes for the exact match with the function call and that is with the normal function!

// Another example :
#include <iostream>
using namespace std;

void func(int a) {
    cout << "Non-template function for int: " << a << endl;
}

void func(double a) {
    cout << "Non-template function for double: " << a << endl;
}

template <typename T>
void func(T a) {
    cout << "Template function for generic type: " << a << endl;
}

int main() {
    func(10);    // Non-template function for int
    func(10.5);  // Non-template function for double
    func('A');   // Template function for generic type
    func("C++"); // Template function for generic type
    return 0;
} // Yahaa bhi vhi hua, jinn function call ke liye exact match tha unko use krliya and jahaa pr exact match nhi tha vahaa template use krliya!
// Also agar do hi function available ho and dono hi template ho in that case, unn dono template functions me se bhi jo exact match hoga vo call hoga! (Ab ofc si baat hai do ekdum exactly same function toh declare nhi krenge, toh function call me koi ek ko hi toh call krenge!)

// Another example :
#include <iostream>
using namespace std;

template <typename T>
void func1(T a) {
    cout << "Template function1 for generic type: " << a << endl;
}

template <typename T>
void func2(T a) {
    cout << "Template function2 for generic type: " << a << endl;
}

int main() {
    func1(5); // First template function called, ofcourse based on exact same rule
    func2('A'); // Second template function called, ofcourse based on exact same rule
    return 0;
}