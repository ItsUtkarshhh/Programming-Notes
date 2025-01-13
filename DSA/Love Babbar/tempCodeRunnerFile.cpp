#include<iostream>
using namespace std;

class Base {
    int var_base;  // Base class variable
public:
    
    virtual void display() { // Display function in the base class (not virtual initially)
        cout << "1 Displaying Base class variable var_base: " << var_base << endl;
    }
};

class Derived : public Base {
public:
    int var_derived;  // Derived class variable
    
    void display() override { // Override display function in derived class, we don't need to use 'override' keyword to override a base class method, but it is considered good practice if you do it! as it makes you aware with errors if there's any potectial mistakes!
        cout << "2 Displaying Base class variable var_base: " << var_base << endl;  // Accessing the base class variable
        cout << "2 Displaying Derived class variable var_derived: " << var_derived << endl;  // Accessing the derived class variable
    }
};

int main() {
    // Creating pointers and objects of Base and Derived classes
    Base* base_class_pointer; // Pointer of Base class type
    Base Obj_base; // Base class object
    Derived Obj_derived; // Derived class object
    
    base_class_pointer = &Obj_derived; // Base class pointer pointing to derived class object

    base_class_pointer->var_base = 30; // Assigning a value to the base class variable through the base class pointer

    // Calling the display function via the base class pointer
    base_class_pointer->display();  // At this point, the virtual function mechanism kicks in

    /* 
    Explanation:
    - Initially, if we don't declare the display function as virtual in the base class, the compiler would call the base class version of display(), 
      even when we use a base class pointer (`base_class_pointer`) pointing to a derived class object. This is known as **static (compile-time) binding**.
      
    - However, since we've declared `display()` as a **virtual function** in the base class, the **dynamic (runtime) binding** takes place.
    - This means that even though `base_class_pointer` is a pointer of type `Base`, the function corresponding to the **actual object type** (which is `Derived`) is called. 
    - This is an example of **runtime polymorphism** where the function that gets called is determined at runtime based on the **type of object** that the pointer is actually pointing to.

    - When we assign the `base_class_pointer` to point to `Obj_derived`, the `display()` function of the `Derived` class is invoked, even though the pointer is of type `Base`.
    
    - **Important Note:** Since `base_class_pointer` is pointing to a `Base` class object and we can't directly access `var_derived` (a member of `Derived` class) through it, `var_derived` will not be initialized, so it will contain a **garbage value** when printed. The main purpose here was to show that the correct `display()` function (from `Derived`) is called despite using a base class pointer, which is only possible because of the virtual function mechanism.
    
    - The **binding** (i.e., which `display()` function to call) happens **at runtime**, not at compile-time, due to the use of the `virtual` keyword.

    - The program demonstrates how virtual functions enable **polymorphism** (dynamic binding), allowing derived class functions to be called using base class pointers or references.
    */
    
    return 0;
}