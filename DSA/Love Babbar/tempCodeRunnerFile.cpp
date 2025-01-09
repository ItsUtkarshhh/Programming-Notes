#include<iostream>
using namespace std;

class Employee {
    public :
    int id;
    float salary;
    Employee(int inpId) {
        id = inpId;
        salary = 34.0;
    }
    // Employee() {} // We added this to avoid errors while creating an object of Programmer class!
};

class Programmer : Employee { // Here default visibilty mode is private!
    public :
    Programmer() {}
    Programmer(int inpId) {
        id = inpId;
    }
    int languageCode = 5;
    void getdata() { // Here we can print the id of the prorammer object using getdata function!
        cout<<id<<endl;
    }
};

int main() {
    Employee Utkarsh(1), Palak(2); // These objects will call the Base Class's parameterized constructor! with IDs 1 & 2.
    // Employee Utkarsh, Palak; // These objects will call the Base Class's default constructor!
    cout<<Utkarsh.salary<<endl;
    cout<<Palak.salary<<endl;

    // Now, Lets create Derived Class!
    Programmer Utkarsh2(3); // But till here it will also show error becoz when we will create the object utkarsh and give it the ID 2 then a object of the class programme will be created, but then as the Programmer class is the derived class of the class Employee so it will try to call a default constructor of the employee class which is not present till now! so we will add a default constructor of the Employee class! and hence all the errors will be removed!
    cout<<Utkarsh2.languageCode<<endl; // It wwill print 5 simply!
    Utkarsh2.getdata(); //Here we can print the id of the prorammer object using getdata function!
    // cout<<Utkarsh2.id<<endl; //Here it wont print the value of id of the object as becoz id ios a private inherited from the employee class! 
    return 0;
}