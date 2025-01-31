// -------------------------------------------------------------- Lecture 63 : Introduction to Templates ------------------------------------------------------------------------------------------------------------------>
// Templates in C++!
// Templates in C++ allow functions and classes to operate with generic types, enabling code reusability and type safety. This means we can write a single piece of code that works with multiple data types without rewriting it for each type separately.
// There are two primary types of templates in C++ : Function Templates – Used to create generic functions.
//                                                 : Class Templates – Used to create generic classes.

// Why Do We Need Templates?
// Consider we create a Vector class with the following members : class Vector { int* arr; int size; // Other member functions... };
// This works well for int type vectors. However, what if we need a vector for float, char, or any other data type? One way is to create separate classes for each data type : class FloatVector { float* arr; int size; }; or class CharVector { char* arr; int size; };
// This leads to code duplication and makes the program harder to maintain.

// How Templates Solve This Problem?
// Instead of defining multiple versions of the same class, we can generalize it using templates : template <typename T> class Vector { T* arr; int size; // Other member functions... };
// Here, T acts as a placeholder for any data type, allowing us to create : Vector<int> for integers, Vector<float> for floating-point numbers, Vector<char> for characters, and so on
// Thus, templates allow us to define a blueprint for a class, making it adaptable to different data types dynamically, just like a class defines the blueprint for objects!

// Syntax : To create a class template, simply add template <typename T> before the class definition, replacing T with the desired data type!
// Example :
#include<iostream>
using namespace std;

template <typename T> // "template <class T>" Isko hum aise bhi likh sakte hai koi difference nhi hai, but its a good practice ki hum "typename" use kre taaki zyada clarity rahe!
class Number {
    T num;
    public:
    Number(T v) : num(v) {}
    T dislay() {
        return num;
    }
};

int main() {
    Number<int> Num1(5);
    cout<<Num1.dislay()<<" ";

    Number<float> Num2(5.2);
    cout<<Num2.dislay()<<" ";

    Number<char> Num3('H');
    cout<<Num3.dislay()<<" ";
} // Hence we can see that it can print anything, we just need to change the data type!

// -------------------------------------------------------------- Lecture 64 : Writing First C++ Templates ------------------------------------------------------------------------------------------------------------------>
// This program demonstrates how to calculate the dot product of two vectors containing int elements. It uses a normal class (vector) without templates. The key takeaway from this example is the limitation that it only works for int vectors, which will later be solved using templates.
#include <iostream>
using namespace std;

class MyVector { // Class to represent a mathematical vector
    public:
    int *arr; // Pointer to store array dynamically
    int size; // Size of the vector

    MyVector(int m) { // Constructor to initialize vector with given size
        size = m;
        arr = new int[size]; // Allocating dynamic memory for the array
    }

    ~MyVector() { // Destructor to release dynamically allocated memory (Prevents Memory Leak)
        delete[] arr;
    }

    int dotProduct(MyVector &v) { // Function to compute the dot product of two vectors
        int d = 0;
        for (int i = 0; i < size; i++) {
            d += this->arr[i] * v.arr[i]; // Multiply corresponding elements and sum them
        }
        return d;
    }
};
 
int main() {
    MyVector v1(3); // Creating first vector of size 3
    v1.arr[0] = 4;
    v1.arr[1] = 3;
    v1.arr[2] = 1;

    MyVector v2(3); // Creating second vector of size 3
    v2.arr[0] = 1;
    v2.arr[1] = 0;
    v2.arr[2] = 1;

    // Calculating the dot product
    int a = v1.dotProduct(v2);

    // Output the result
    cout << "Dot Product: " << a << endl;
    return 0;
}
// Important Points in this Code : Dynamic Memory Allocation : `arr` is allocated dynamically using `new int[size]`, allowing flexible vector sizes.
//                               : Destructor for Memory Management : `~MyVector()` ensures memory is properly released using `delete[] arr`, preventing memory leaks.
//                               : Using `this` Pointer : `this->arr[i]` ensures we're accessing the correct object's array.
//                               : Passing Objects by Reference : `vector &v` prevents unnecessary copying of objects, improving efficiency.
//                               : Dot Product Calculation : Multiplies corresponding elements of two vectors and sums them up.
//                               : Limitation of This Code : This only works for `int` type vectors.
//                                                         : If we want `float` or `double` vectors, we would need to rewrite the class!
//                                                         : Solution? Use Templates to generalize this class for all data types.

// Using Templates!
#include <iostream>
using namespace std;
 
template <class T> // We have just added this line and replaced all the data types with T!
class vector {
    public:
        T *arr;
        int size;
        vector(int m) {
            size = m;
            arr = new T[size];
        }
    T dotProduct(vector &v){
        T d = 0;
        for (int i = 0; i < size; i++) {
            d+=this->arr[i]*v.arr[i];
        }
        return d;
    }
};
 
int main() {
    vector<float> v1(3); // vector 1 with a float data type
    v1.arr[0] = 1.4;
    v1.arr[1] = 3.3;
    v1.arr[2] = 0.1;

    vector<float> v2(3); // vector 2 with a float data type
    v2.arr[0]=0.1;
    v2.arr[1]=1.90;
    v2.arr[2]=4.1;

    float a = v1.dotProduct(v2);
    cout<<a<<endl;
    return 0;
}

// -------------------------------------------------------------- Lecture 65 : Templates with multiple pointers! ------------------------------------------------------------------------------------------------------------------>
// Before Using Templates (Ordinary Class Example)
// This class can only store and print an `int` and a `char`.
// Limitation? What if we need `int-float`, `float-char`, `double-int` combinations? We can't keep making separate classes for each type.
#include<iostream>
using namespace std;

class myClass {
    public:
        int data1;
        char data2;
    void display() {
        cout << this->data1 << " " << this->data2 << endl;
    }
};

int main() {
    myClass obj;
    obj.data1 = 10;
    obj.data2 = 'A';
    obj.display();
}
// Problem : This class is **fixed** for `int` and `char` only.
//         : What if we need **different** type combinations? We will use Templates!

#include<iostream>
using namespace std;

template<class T1, class T2> // Creating a Template Class that supports multiple data types
class myClass {
    public:
    T1 data1;
    T2 data2;

    myClass(T1 a, T2 b) { // Constructor to initialize values
        data1 = a;
        data2 = b;
    }

    void display() { // Display function to print the data members
        cout << this->data1 << " " << this->data2 << endl;
    }
};

int main() {
    myClass<int, float> obj1(1, 1.5); // Object with int and float
    obj1.display(); // Output : 1 1.5

    myClass<int, char> obj2(1, 'A'); // Object with int and char
    obj2.display(); // Output : 1 A

    myClass<float, char> obj3(1.5, 'A'); // Object with float and char
    obj3.display(); // Output : 1.5 A
}
// Key Takeaways from this Code : Templates with Multiple Parameters : `template<class T1, class T2>` allows using multiple data types.
//                                                                   : We can pass **any** data types dynamically while creating objects.
//                              : Code Reusability & Flexibility : `T1` and `T2` act as placeholders for any data types.
//                                                               : The user defines these data types when creating objects.
//                              : Objects with Different Type Combinations : `myClass<int, float>` → Works with `int` and `float`
//                                                                         : `myClass<int, char>` → Works with `int` and `char`
//                                                                         : `myClass<float, char>` → Works with `float` and `char`
//                              : Advanced Possibilities : We can **pass class names** as `T1` and `T2` instead of just primitive data types.
//                                                       : This allows for template-based relationships between classes (Complex but powerful!).

// -------------------------------------------------------------- Lecture 66 : Templates with default parameters! ------------------------------------------------------------------------------------------------------------------>
// Templates with Default Parameters : Just like functions have default arguments, templates can have default types.
//                                   : If the user does not specify types while creating objects, these defaults are used.
#include<iostream>
using namespace std;

template <typename T1=int, typename T2=float, typename T3=char> // Default types: T1 → int, T2 → float, T3 → char
class myClass {
    T1 value1;
    T2 value2;
    T3 value3;

    public:
    myClass(T1 v1, T2 v2, T3 v3) { // Constructor to initialize values
        value1 = v1;
        value2 = v2;
        value3 = v3;
    }

    void display() { // Display function
        cout << "Value of value1 : " << value1 << endl;
        cout << "Value of value2 : " << value2 << endl;
        cout << "Value of value3 : " << value3 << endl;
    }
};

int main() {
    // Using default template types (int, float, char)
    myClass<> obj1(1, 2.5, 'A'); // No types specified → Uses default types
    obj1.display();

    cout << endl;

    // Using custom template types (float, char, int)
    myClass<float, char, int> obj2(2.5, 'A', 1); // Overriding default types
    obj2.display();
}
// Key Takeaways : Default Template Parameters : `template <typename T1=int, typename T2=float, typename T3=char>` and If no type is provided, defaults are used.
//               : Overriding Defaults : `myClass<float, char, int>` → Changes the default int-float-char to float-char-int.
//               : Useful when : You want to provide fallback types for most cases. But also allow users to override them when needed.

// ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------>
// Why study class templates!
// Why Study Class Templates : Code Reusability – Write once, use for multiple data types.
//                           : Type Safety – Prevents errors related to type mismatches.
//                           : Flexibility – Works for any data type, reducing redundant code.
//                           : Performance – Since templates are resolved at compile-time, they avoid the overhead of runtime polymorphism.
//                           : Standard Library Usage – The STL (Standard Template Library) heavily relies on templates (e.g., vector<T>, stack<T>, map<K, V>).

// Use Cases of Class Templates : Generic Data Structures : Instead of writing a separate class for each data type (int, double, string), use templates.
//                                                        : We can create Generic Stack Implementation, Generic Linked List, Generic Sorting Algorithm (Implemented using Function Templates) and more benefits

// Saves Time & Avoids Code Duplication : No need to write separate functions/classes for int, double, etc.
// Compile-Time Type Checking : Unlike void* (which allows unsafe casting), templates are type-safe.
// Faster Execution : Templates generate optimized code at compile-time, avoiding runtime overhead.

// Rest implement, practice and learn!