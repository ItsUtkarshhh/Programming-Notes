#include<iostream>
using namespace std;

// Class A represents an object that contains an integer 'a'.
class A {
    int a; // Member variable to store the value.
    public:
    
    // Member function setdata, which uses the 'this' pointer and reference variables.
    A& setdata(int a) { 
        // Here, we are using a reference to avoid creating a copy of 'a' when passing to the function.
        // This allows the function to modify the original value instead of a copy.
        this->a = a; // Assign the passed value 'a' to the member variable 'a' using the 'this' pointer.
        cout << "Address of returned obj is: " << this << endl; // Printing the address of the object that called this function.
        return *this; // Return the object itself using the 'this' pointer (dereferencing it). This allows method chaining in main().
    }

    void getdata() {
        cout << "The value of a is " << a << endl;
    }
};

int main() {
    int x = 5; // Local variable with value 5.
    
    // Dynamically creating an object of class A using the 'new' keyword.
    A *a = new A; // Object 'a' is dynamically created and pointer is assigned to it.
    cout << "Address stored in pointer: " << a << endl; // Printing the address of the dynamically allocated object.
    
    // Creating a reference variable 'z' and calling the setdata function on the object created using pointer 'a'.
    // The setdata function returns a reference to the object itself, which is stored in 'z'.
    A &z = (*a).setdata(x); // Passing the value 'x' to setdata and assigning the returned reference to 'z'.
    
    // Displaying the value of 'a' using reference variable 'z'.
    z.getdata(); // The object 'z' is referring to the same object as 'a'.
    
    // Printing the address of the object referred to by 'z'.
    cout << "Address of object jo humein mila is: " << &z << endl;
    
    // Printing the address stored in pointer 'a', which should be the same as the address of 'z'.
    cout << "Address stored in pointer: " << a << endl;
    
    // All addresses should be the same because 'z' is just another name (reference) for the same object.
    
    return 0;
}