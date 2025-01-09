#include<iostream>
using  namespace std;

class employee {
    private :
    int id;
    static int count; // Static data member to count the number of employee.

    public :
    void set_data() {
        cout<<"Enter the ID of the employee : ";
        cin>>id;
        count++;
    }
    void get_data() {
        cout<<"The ID of the employee is "<<id<<" and this is employee number "<<count<<endl;
    }
    static void getCount() {
        // cout<<id; // Will throw an error becoz "id" is not a static data member so it can't be access in static member function.
        cout<<"Value of the count is : "<<count<<endl;
    }
};

int employee :: count = 100; // Static data member is initialized from here, and not from the class. and if we don't initialize it, it will self-initialize with 0.

int main() {
    employee Utkarsh, Palak, Preyansh;
    Utkarsh.set_data();
    Utkarsh.get_data();
    employee :: getCount(); // Static member function don't need an object to get called, it can be initialized with just the name of the class. and Static member function can use or access only the static data member or functions.

    Palak.set_data();
    Palak.get_data();
    employee :: getCount();

    Preyansh.set_data();
    Preyansh.get_data();
    employee :: getCount();
}