#include<iostream>
using namespace std;

class Hero {
    private :
        int Health; // Private member (not accessible outside the class)
    public :
        int Age; // Public member (accessible outside the class)
};

int main() {
    Hero Utkarsh;
    // cout<<"Utkarsh's health is : "<<Utkarsh.Health<<endl; // It will throw error
    cout<<"Utkarsh's age is : "<<Utkarsh.Age<<endl; // It won't throw erroor, but will print garbage value as it is not initiallized!
}