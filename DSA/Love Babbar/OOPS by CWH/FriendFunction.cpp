// First use of friend function.
#include<iostream>
using namespace std;

class complex {
    int a,b;

    public :
    int setNumber(int n1, int n2) {
        a = n1;
        b = n2;
    }

    // Below line means that non-member - sum_of_complex function is allowed to do anything with private data members.
    friend complex sum_of_complex(complex o1, complex o2); // Here in the class we declared the complex sum_of_complex as the friend function of the class complex.

    int print() {
        cout<<"The complex number is : "<<a<<"i + "<<b<<"j"<<endl;
    }
};

complex sum_of_complex(complex o1, complex o2) { // Here we made a function of the type complex, which was not a member function of the class also but using this we are trying to access the private data members and that we can't do...so here we will make it a friend function of the class complex and using which we can access the private data members of the class.
    complex o3;                                  // So a friend function is not a member function of the class, but it can still access the private data members using the keyword "friend".
    o3.setNumber((o1.a + o2.a), (o1.b + o2.b));
    return o3;
}

int main() {
    complex c1, c2, sum;
    c1.setNumber(2,3);
    c1.print();

    c2.setNumber(3,2);
    c2.print();

    // sum.sum_of_complex(); // We can't call the sum_of_complex function using the class object because it's not a data member.
    sum = sum_of_complex(c1,c2);     
    sum.print();
    return 0;
}

// Properties of Friend Function.
// 1.) Not in the scope of the class.
// 2.) Since it is not in the scope of the class, it cannot be called from the object of that class. c1.sum_of_complex() == Invalid
// 3.) Can be invoked without the help of any object.
// 4.) Usually contains the objects as arguments.
// 5.) This friend function can be declared inside private section or in the public section of the class.
// 6.) It cannot access the members directly by the names and need objects_name.member_name to access any member.

// Simplest Example to undertstand friend function.
#include<iostream>
using namespace std;

class Y; // Here we have to tell the compiler that there will be class named Y.

class X {
    int data;
    public :
    void setValue(int value) {
        data = value;
    }
    friend void addValue(X, Y); // Declaration that addValue is a friend function of class X.
};

class Y {
    int data; // This data private member is not same as the previously in class A. We can also give it some other name.
    public :
    void setValue(int value) {
        data = value;
    }
    friend void addValue(X, Y); // Declaration that addValue is a friend function of class Y.
};

void addValue(X o1, Y o2) {
    cout<<"Sum of the two values of two classes : "<<(o1.data + o2.data);
}

int main() {
    X a1;
    a1.setValue(5);

    Y b1;
    b1.setValue(5);

    addValue(a1, b1);
}


// A bit difficult approach with Friend function.
#include<iostream>
using namespace std;

class B; // Declaring the class B before hand.

class A {
    int data;
    friend void swap(A &, B &);
    public :
    int setValue(int val1) {
        data = val1;
    }
    void display() {
        cout<<data<<endl;;
    }
};

class B {
    int data;
    friend void swap(A &, B &);
    public :
    int setValue(int val2) {
        data = val2;
    }
    void display() {
        cout<<data<<endl;
    }
};

void swap(A &o1, B &o2) { // This is a swap function which will take the input of the address of the objects of class A and B.
    int temp = o1.data; // Here we are accessing the values of data from both the classes using dot operator and swapping them.
    o1.data = o2.data;
    o2.data = temp;
}

int main() {
    A obj1;
    obj1.setValue(3);

    B obj2;
    obj2.setValue(4);

    swap(obj1, obj2);

    cout<<"Value of obj1 : ";
    obj1.display();
    cout<<"Value of obj2 : ";
    obj2.display();
}
