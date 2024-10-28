#include<iostream>
using namespace std;

class Base {
    public :
    int var_base;
    virtual void display() {
        cout<<"1 Displaying Base class variable var_base : "<<var_base<<endl;
    }
};

class Derived : public Base {
    public :
    int var_derived;
    void display() {
        cout<<"2 Displaying Base class variable var_base : "<<var_base<<endl;
        cout<<"2 Displaying Derived class variable var_derived : "<<var_derived<<endl;
    }
};

int main() {
    Base* base_class_pointer;
    Base Obj_base;
    Derived Obj_derived;
    base_class_pointer = &Obj_derived;
    // base_class_pointer->display(); // jaisa bhi tak ho rha tha toh agar abhi hum isko run krenge toh bhale hi humne abhi kisi var ki value set nhi ki hai,
    // pr we know ki yahaa pr by-default base class ka display function run hoga! pr agar hum chahte hai ki ye cheez change ho, and derived class ka display function run ho, kyunki dervied ke hi object ko base class ka pointer point kr rha hai, toh yhi pr use hote hai virtual functions! Toh ab hum base class ke display ko virtual declare krdenge!
    
    base_class_pointer->var_base = 30;
    base_class_pointer->display(); // agar abhi hum bss aise hi display karayenge then we know hum var_derived ko value nhi de payenge, kyunki hum base class ke pointer se derived class ke data members ko access nhi kr sakte, isliye hum usko set nhi kar payenge, but haa ye sirf ye dikhane ke liye tha ki hum base class ke pointer se bhi derived class ke member function ko access kr sakte hai, through virtual functions!
    // and ye sab decision bhale hi pehle compiler ne dekh liya ho, but binding and all functions ki and pointers ki vo sab runtime pr hi hui hai! vo bhi pointer ke type ko dekh kr!
    // yhaa pr humne base class ke member function ko virtual declare krdiya taaki base class ka pointer jab display function call kre tab derived class ka display function dikhe bss! and vhi call hojaye, but ofcourse as becoz hum derived class ke data member toh set nhi kr sakte hai toh var_derived ke liye toh garbage value hi print hogi, but okay our main purpose was to ye samajhna ki kaise base class ke pointer se hum derived class ka display function call kar paye, and that is through virtual function!
}