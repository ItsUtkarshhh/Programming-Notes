#include<iostream>
using namespace std;

class Base {
    int data1; // This data1 can not be inherited as it is a private member of the base class!
    public :
        int data2;
        void setdata();
        int getdata1();
        int getdata2();
};

void Base :: setdata(void) { // Here we defined the setdata function of the base class! ye default set kr rhe hai data1 and 2 ko! hum abhi khud se data1 and data2 ko set nhi kr payenge!
    data1 = 10;
    data2 = 20;
}

int Base :: getdata1() { // Here we defined the getdata1 function of the base class!
    return data1;
}

int Base :: getdata2() { // Here we defined the getdata2 function of the base class!
    return data2;
}

class Derived : public Base { // Class is being derived publically hence all of the public data members of the base class are derived publiclally for the derived class also!
    int data3;
    public :
        void process();
        void display();

};

void Derived :: process() { // Defining the data members of the derived class, data1 ke liye getdata1() mwthod use krna padega kyunki data1 ek private memeber hai bhale hi hum Base class inherit ki hai Derived class me pr data1 ek private member tha base class ka isliye vo inherit nhi hua so usko use krne ke liye hume getdata1() method use krna padega!
    data3 = data2*getdata1();
}

void Derived :: display() { // Defining the data members of the derived class
    cout<<"Value of data 1 is : "<<getdata1()<<endl;
    cout<<"Value of data 2 is : "<<data2<<endl;
    cout<<"Value of data 3 is : "<<data3<<endl;
}

int main() {
    Derived der;
    der.setdata(); // Here we can use the setdata() getdata() methods of the base class with the objects of the derived class, as becoz we have inherited the the base class hence means we can use all of its public data members! 
    der.process();
    der.display();
    return 0;
}