#include<iostream>
using namespace std;

class Employee {
    public :
    int id;
    float salary;
    Employee() {} // Default Constructor!
    Employee(int inpId) { // Parameterized Constructor!
        id = inpId;
        salary = 34.0;
    }
};

class Programmer : Employee {
    public :
    int languageCode = 5;
    Programmer(int inpId) { // Parameterized Constructor!
        id = inpId;
    }
    void getdata() {
        cout<<id<<endl;
    }
};

int main() {
    // Base class objects creation!
    Employee Utkarsh(1), Palak(2);
    cout<<Utkarsh.salary<<endl;
    cout<<Palak.salary<<endl;

    // Derived class objects creation!
    Programmer Utkarsh2(3);
    cout<<Utkarsh2.languageCode<<endl;
    Utkarsh2.getdata();
    // Utkarsh2.salary = 22; // Cannot access this, as the Programmer class is privately inherited! hence, then base class public data members are now the private data members of the derived class!
    // cout<<Utkarsh2.salary<<endl;
    // cout<<Utkarsh2.id<<endl;
    return 0;
}