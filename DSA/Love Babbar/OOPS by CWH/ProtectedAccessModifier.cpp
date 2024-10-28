#include<iostream>
using namespace std;

class Base {
    // int a; // Here a and b are private data members of the base class hence it can't be inherited, so to inherit them we have to make them public, but if we make it public then anyone can make objects using these data members and can edit the values, so we want it to be private as well, but we can't make it private otherwise they will not be inherited...
    // So for this kind of situations where we want to keep the data members secure and private but we also want to inherit them so for these case we use "Protected" access modifier, this modifier keep the data members private but just make it inheritable.
    // int b;

    protected :
    int a;
    private :
    int b;
    public :
    int c;
};

// A table for Private Public Protected!
                        // Private Derivation       Public Derivation       Protected Derivation
// 1. Private Member        Not Inherited             Not Inherited           Not Inherited
// 2. Public Member         Private                   Public                  Protected
// 3. Protected Member      Private                   Protected               Protected

class Derived : protected Base {
    // Here we just inherited the protected derivations of the base class!
};

int main() {
    Base d; // Object for the base class
    Derived e; // Object for the derived class

    // d.a = 1; // a is a protected data member of the base class hence it can only be inherited but cannot be accessed!
    // d.b = 2; // b is a private data member of the base class hence it cannot be inherited and accessed!
    d.c = 3; // c is a public data members of the base class hence it can be inherited as well as accessed

    // e.a = 4; // a was a protected member of the base class and then it is inherited as protected hence it will still be protected due to which it still cannot be accessed! 
    // e.b = 5; // b was a private member of the base class hence it cannot be inherited hence there's no logic of writing e.b as becoz it is not even get inherited! so we can't create objects using the b private data member of the base class!
    // e.c = 6; // c was a public data mmber of the base class so it can be inherited as well as accessed throgh creating objects of the base class, but here when it got inherited in derived class under protected derivation of base class, hence it became protected, hence now it cannot be accessed by creating objects of the derivaed class as now it is protected data member of the derived class!
    
    // cout<<d.a; // Will show error
    // cout<<d.b; // Will show error
    cout<<d.c; // Will print 3!
    // cout<<e.a; // Will show error
    // cout<<e.b; // Will show error
    // cout<<e.c; // Will show error
    return 0;
}