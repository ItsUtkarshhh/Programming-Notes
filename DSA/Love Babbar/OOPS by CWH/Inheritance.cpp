// INHERITANCE!!!!!!!!!!!!
// Reusability is one of the main feature of oops! In C++ we can reuse the class and add additional features to it, as reusing the class saves the time and money, reusing already tested and debugged class will save alot of effort in developing and debugging the same thing again!
// The concept of reusability in C++ is supported using inheritance!
// We can reuse the properties of existing class by inheriting from it!
// The existing class is called the base class!
// The new class which is inherited is called as a derived class!
// Reusing classes saves time and money!

// There are different types of Inheritance in C++! : Single Inheritance, Multiple Inheritance, Multi-level Inheritance, Hierarchial Inheritance, Hybrid Inheritance.
// Single Inheritance : Where derived class is derived from only one base class!
// Multiple Inheritance : Where derived class is derived from more than one base class!
// Hierarchial Inheritance : Where more than one derived classes are derived from one base class!
// Multi-Level Inheritance : Where derived class is derived from another derived class and that derived class is derived from one base class!
// Hybrid Inheritance : Where it is a combination of Multiple Inheritance and Multi-Level Inheritance.

#include<iostream>
using namespace std;

Base Class
class Employee {
    // int id; // Lets not keep anything private, as becoz we will not be able to inherit these properties of the base class!
    public :
    int id;
    float salary;
    Employee(int inpId) {
        id = inpId;
        salary = 34.0;
    }
    Employee() {} // We added this to avoid errors while creating an object of Programmer class!
};

// Syntax to make a derived class.
// class {{derived-class-name}} : {{visibility-mode}} {{base-class-name}} {
    // Members/Methods etc...
// }

// Here visibilty mode means that how we want to inherit the properties of the base class, privately or publicly? if we do it privately then the public members of the base class will become private members of the derived class, or else if we do it publicly then public members of the base class will become public members of the derived class! so for the following code we will use...
// Default visibilty mode of the derived class is Private!
// Private members of the base class are never inherited!

// Creating Derived class from the original base class
class Programmer : Employee { // Here default visibilty mode is private!
    public :
    Programmer(int inpId) {
        id = inpId;
    }
    int languageCode = 5;
    void getdata() { // Here we can print the id of the prorammer object using getdata function!
        cout<<id<<endl;
    }
};

int main() {
    Employee Utkarsh(1), Palak(2); // Here we can't directly make objects as in the base class we have given IDs to the contructor means whenever we will create any objects of the Base class we have to give them an ID. So we created two objects Utkarsh and Palak and gave them IDs 1 and 2.
    cout<<Utkarsh.salary<<endl;
    cout<<Palak.salary<<endl; // These two lines of cout will print the salary of Utkarsh and Palak which are the two objects of the base class names Employee.

    // Now we will create a derived class from here!
    Programmer Utkarsh2(3); // But till here it will also show error becoz when we will create the object utkarsh and give it the ID 2 then a object of the class programme will be created, but then as the Programmer class is the derived class of the class Employee so it will try to call a default constructor of the employee class which is not present till now! so we will add a default constructor of the Employee class! and hence all the errors will be removed!
    cout<<Utkarsh2.languageCode<<endl; // It wwill print 5 simply!
    Utkarsh2.getdata(); //Here we can print the id of the prorammer object using getdata function!
    // cout<<Utkarsh2.id<<endl; //Here it wont print the value of id of the object as becoz id ios a private inherited from the employee class! 
    return 0;
}

// Single Inheritance!
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

// Above we have kept the visibility mode as Public, thats why we were able to use the members and methods of the base class as they are publicly inherited! but now we will inherit it privately and then see what are the changes in the code we need to do!
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

void Base :: setdata(void) { //Here we defined the setdata function of the base class!
    data1 = 10;
    data2 = 20;
}

int Base :: getdata1() { // Here we defined the getdata1 function of the base class!
    return data1;
}

int Base :: getdata2() { // Here we defined the getdata2 function of the base class!
    return data2;
}

class Derived : private Base { // yahaa derived class ko privately inherit kiya gya hai hence, jo bhi data members and member functions base class me public the vo sab iss derived class ke private data members ban jayenge and jo private the base class me vo toh inherit hote hi hai vaise bhi!!
    int data3;
    public :
        void process(); // Isliye ab as setdata() and getdata() methods bhi iss derived class ke liye private ban chuke hai toh hum unko iss class ke objects ab directly access nhi kr sakte! so here now we have to use this process method jo public scope me hai! and now objects iss method ko use krke unn private data members ko access krenge!
        void display();

};

void Derived :: process() { // Defining the data members of the derived class
    setdata(); // We added the setdata function here as the process is the member function of the Derived class and hence it can internally access the private data member! 
    data3 = data2*getdata1();
}

void Derived :: display() { // Defining the data members of the derived class
    cout<<"Value of data 1 is : "<<getdata1()<<endl;
    cout<<"Value of data 2 is : "<<data2<<endl;
    cout<<"Value of data 3 is : "<<data3<<endl;
}

int main() {
    Derived der;
    // der.setdata(); // here we will not be able to use this method of the base class as the members of the base class is being inherited privately! 
    // Hence, else what we will do is that we will add the setdata function in the process method as the the private members of the class can only be accessed by the data members of the class within the class,
    // hence process is the method of the Derived class and which has inherited the Base class hence the process method can use the private data members of the Base class, hence we will add the setdata funtion in the process method and then while calling the process method the setdata function will get called automatically! 
    der.process();
    der.display();
    return 0;
}

// Multi-Level Inheritance!
// When we derived a class from one class and that class is derived from some other base class is called multilevel inheritance!!
#include<iostream>
using namespace std;

class student { // Base class
    protected :
    int roll_number;
    public :
    void set_roll_number(int);
    void get_roll_number(void);
};

void student :: set_roll_number(int r) {
    roll_number = r;
}

void student :: get_roll_number() {
    cout<<"Roll number of the student is : "<<roll_number<<endl;
}

class exam : public student { // Here we have inherited the base class publicly, means the protected members will be protected and the public members will be public and then here we created some other protected data members and some public data members!
    protected :
    float maths;
    float physics;

    public :
    void set_marks(float, float);
    void get_marks(void);
};

void exam :: set_marks(float m1, float m2) {
    maths = m1;
    physics = m2;
}

void exam :: get_marks() {
    cout<<"Marks obtained in maths : "<<maths<<endl;
    cout<<"Marks obtains in physics : "<<physics<<endl;
}

class result : public exam { // Here we have derived the exam class as public again means...we have inherited the protected data members as protected ands public data members as public! and we have created some other private and public data members
    float percentage;

    public :
    void display_result() {
        get_roll_number(); // this member function is inherited from the student base class thats why we can use it here as it is publicly inherited!
        get_marks(); // Similary this member function is inherited from exam base class so that we can use it here!
        cout<<"Your result in terms of percentage is : "<<100*((maths+physics)/200)<<"%"<<endl;
    }
};

int main() {
    result Utkarsh; // Here now we have created the object of the result class as it can use all the inherited data members and member function of the base class and also of super base class! So what actually we did here was that, we inherited the members of the student class to exam class and then we have inherited that exam class to the result class and hence we can use all the data members and members functions of all the classes by creating the object of the result class!
    Utkarsh.set_roll_number(65);
    Utkarsh.set_marks(95.0,96.0);
    Utkarsh.display_result();
    return 0;
    // A --> B --> C is the inheritance Path.
}

// Multiple Inheritance!
#include<iostream>
using namespace std;

/*
Syntax to inherit more than one base classes to the derived class!
class derived : visibility-mode base1, visibiltiy-mode base2 {
    <--class body-->
}
*/

class Base1 {
    protected :
    int base1value;

    public :
    set_base1value(int v1) {
        base1value = v1;
    }
};

class Base2 {
    protected :
    int base2value;

    public :
    set_base2value(int v2) {
        base2value = v2;
    }
};

// Its not neccessary that we can only inherit from only 2 base classes, rather we can inherit from as many as we want, so for example lets inherit from another Base in multiple inheritance!
class Base3 {
    protected :
    int base3value;

    public :
    set_base3value(int v3) {
        base3value = v3;
    }
};
// Hence here we have created three base classes and then we have inherited there inheritable data members into single derived class, this is called multiple inheritance!

class Derived : public Base1, public Base2, public Base3 {
    public :
    int show() {
        cout<<"The value of the Base 1 : "<<base1value<<endl;
        cout<<"The value of the Base 2 : "<<base2value<<endl;
        cout<<"The value of the Base 3 : "<<base3value<<endl;
        cout<<"The sum of the values of the Base 1, 2 and 3 : "<<base1value + base2value + base3value<<endl;
    }
};
/*
The inherited derived class is like :
Data members : 
    Base1value --> Protected
    Base2value --> protected
    Base3alue --> protected

Member Functions :
    set_base1value() --> Public
    set_base2value() --> Public
    set_base3value() --> Public
    show() --> Public
*/
int main() {
    Derived Obj1;
    Obj1.set_base1value(5);
    Obj1.set_base2value(25);
    Obj1.set_base3value(10);
    Obj1.show(); // For output!
}

// Ambiguity Resolution!
// When we create a function in one of the base class and we create the same function in the other base class and then when we try to inherit both the base classes into one singke derived class then the compiler get confuses that kiska function use krna chahiye as both are the same!
// And ye ambiguity sirf multiple inheritance me nhi balki single inheritance me bhi aa sakti hai yaa multi-level inheritance me bhi aa sakti hai....we will see two examples of Ambiguity resolution, below :-
#include<iostream>
using namespace std;

class Base1 {
    public :
    void greet() {
        cout<<"How are you"<<endl;
    }
};

class Base2 {
    public :
    void greet() {
        cout<<"Kaise ho?"<<endl;
    }
};

// So here we have created two Base classes and used two greet functions in both of them and then we derived both of the base classes in the Derived class, toh base classes ka object create krne pr toh vo apne apne base classes ke hi greet function ko call krenge...
// pr derived class ka object jab greet function ko call krega tab vo kis base class ke greet function ko call krega? kyunki derived class me toh khud ka koi greet function hai hi nhi toh greet function to inherited hai pr kis base class se?? this is ambiguity here, so to resolve this ambiguity,
// hum derived class me hi ek statement likh dete hai.....jo compiler ko bataa deta hai ki jab hum derived class ke object se greet function ko call kre tab kis base class ke greet fyunction ko call krna hai!! agar derived class ke paas already khud ka ek greet function hai toh isme koi ambiguity ayegi hi nhi and sab smoothly compile and run ho jayega!!
class Derived : public Base1, public Base2  {
    int a;
    public :
    void greet() {
        Base1 :: greet(); // this is the statement we are using here to resolve ambiguity!
    }
    // void greet() {
    //     cout<<"Whats upp??"<<endl;
    // } // Isme koi ambiguity nhi ayegi!
};

int main() {
    Base1 Base1obj;
    Base2 Base2obj;
    Base1obj.greet();
    Base2obj.greet();
    
    Derived DerivedObj1;
    DerivedObj1.greet(); // After solving the ambiguity, it will call the greet function of the Base1 class! hence Ambiguity Resolved!
    return 0;
}


// Another example of Ambiguity!!
// In this example of Ambiguity, here we are doing single inheritance, and here what happening is that we made a greet function in the base class and when we have inherited it in the derived class the derived class also got that greet function, hence whenever we will make a object of the derived class and if will call the the greet function,
// then the greet function of the base class class will get called, and if we add another greet function of the derived class then itself, then here the compiler will get another problem and that ki agar derived class ke object ne greet function call kiya then kis class ka greet function call hoga, derived ka ya base ka, so here this is an ambihuity,
// pr yahaa ye ambiguity khud hi resolve hojaati hai, as because, agar greet function derived class ne bhi apna khud ka banaya ha toh ofcourse agar derived class ka koi object greet function ko call krega toh vo derived class ke hi  greet function ko call krega na ki kisi aur ke ko!
#include<iostream>
using namespace std;

class Base {
    public :
    void greet() {
        cout<<"Hello World"<<endl; //Greet function of the base class!
    }
};

class Derived : public Base {
    public :
    void greet() {
        cout<<"Learning OOPS in C++"<<endl; //Greet function of derived class!
    }
};

int main() {
    Derived Obj1;
    Obj1.greet(); // Here greet function of derived class will be called as because greet function banaa hua hai derived class ka khud ka, agar nhi banaa hua hota toh base class ka greet function call hota!
    return 0;
}

// Virtual Base Class!
// When we have base class and suppose that base class has a variable 'a' and we have inherited that base class into two derived class B and C so now the 'a' variable will go to both the B and C but now if we will inherit that B and C to another D class, then this "a" variable will also get inherited to D,
// Pr ab kya dikkat hai ki jab humne B and C ko inherit kiya D class me, tab 'a' variable do baar inherit hogya, and this is the ambiguity here! ki ek hi variable do baar inherit hogya, to isko solve krne ke liye hum A class ko virtual Base class declare krdenge! and isse kya hoga ki jo 'a' variable hai vo bss ek baar hi inherit hoga! 
#include<iostream>
using namespace std;

class Student {
    protected :
    int roll_number;
    public :
    void set_roll_number(int a) {
        roll_number = a;
    }
    void print_roll_number() {
        cout<<"Roll number of the candidate is : "<<roll_number<<endl;
    }
}; // Yahaa humne ek base class banai jisme humne roll number diya candidate ko!

class Academics : virtual public Student {
    protected :
    int maths, physics;
    public :
    void set_marks(float m1, float m2) {
        maths = m1;
        physics = m2;
    }
    void print_marks() {
        cout<<"Candidate's marks in Maths is : "<<maths<<" and Physics is : "<<physics<<endl;
    }
}; // Yahaa humne ek derived class banai, jisko humne derive kiya through Virtual base class Student means agar koi same function ya member function ya data member do baar agar inherit hojaata hai toh vo last ke result me sirf ek baar hi jayega!

class Sports : virtual public Student {
    protected :
    int score;
    public :
    void set_score(int sc) {
        score = sc;
    }
    void print_score() {
        cout<<"Score of the candidate is : "<<score<<endl;
    }
}; // Same resoning as of the above Academics class

class Result : public Academics, public Sports {
    protected :
    int total;
    public :
    void display() {
        total = maths + physics + score;
        print_roll_number();
        print_marks();
        print_score();
        cout<<"Total score of the candidate is : "<<total<<endl;
    }
}; // Yahaa humne Result ko derive kiya from Sports and Academics vaale base classes se!

int main() {
    Result Utkarsh;
    Utkarsh.set_roll_number(65);
    Utkarsh.set_marks(95.7, 96.5);
    Utkarsh.set_score(9);
    Utkarsh.display();
    return 0;
}// And then finally yahaa humne saare functions ko call kiya! Hence, thats how here we have solved the ambiguity here!!

// Constructors in Derived Class!
// Theory : So, see what happens is, suppose humne kuch multiple classes ka inheritance kiya hai, like multiple ya multi-level! and lets take an example of multiple inheritance where order of inheritance is : A->B->C, now we have seen in most of the cases we make objects of the class C
// And, jo class A hai uske do data members hai a1 & a2, now class B ke bhi do data members hai b1 & b2, now C ke bhi hai c1 & c2. Now, jab hum C ke object creation me ek constructor call hoga, kaisa constructor call hoga, toh can be a default or it can be a paramterized constructor! Now after this ab question is kiska constructor call hoga? A, B ya C ka? toh dekho iss cheez me ek order maintain hota hai chaahe multiple ya multi-level ya kisi bhi aur type ka inheritance ho, usme jab derived class ka object create hota hai, toh base class ka constructor call hota hai! ab agar ek se zyada base classes hai toh uss case me jo base class pehle declare hua hoga uska constructor pehle call hoga!
// Don't confuse this constructor call with method call, kyunki usme jis class ka object hoga uske inheritance ke according vo method call hoga! but constructor ke case me aisa nhi hai kyunki constructor ka kaam koi process krna nhi hai, uska kaam hai ek class ke object ko create krna!

// So now, lets take an example of A->B->C, now agar kisi bhi class me koi bhi paramterized constructor nhi hai, toh mtlb ki ek default constructor hoga, ab chaahe ho vo user-defined ho ya backend vaala ho, whatever, point is ki iss constructor me koi arguments pass nhi krne hai object creation ke liye! tab jab hum C class ka object create kr rhe honge tab pehle A ka then B ka and then C ka default constructor call hojayega! without any trouble! and object will be easilty created!
// But if, maanlo kisi bhi base class me paramterized constructor ho, ab chahe vo ek argument le rha ho ya more than one, in both the cases hume derived class me bhi arguments pass krne honge! and for that agar humare base class me parameterized constructor hai, then in that case, C class me jo constructor create hoga, vo aise hoga...
// Syntax :
// Derived-Constructor(arg1, arg2, arg3, .....) : Base-Constructor(arg1, arg2, arg3, ....), Base-Constructor(arg1, arg2, arg3, ....) {
//     ...
// }
// The constructor of the derived class recieves all the arguments at once and then will pass the calls to the respective base classes!

// Special Case of virtual base class : The constructors for virtual base class are invoked before an non-virtual base class!
//                                    : If there are multiple virtual base classes, they are invoked in the order they are declared!
//                                    : Any non-virtual base class are then constructed before the derived class constructor is executed!

/*
Case1 :
Class B : public A {
    Order of execution of constructor is : first A() then B()
};

Case2 :
Class A : public B, public C {
    Order of execution of constructor is : first B() then C() then A()
};

Case3 :
Class A : public B, vitual public C {
    Order of Execution of constructor is : first C() then B() then A(), as becoz C is a virtual base class so it is given higher priority!
};
*/

#include<iostream>
using namespace std;

class Base1 {
    int Base1_data1;
    int Base1_data2;
    public:
    Base1(int i, int j) {
        Base1_data1 = i;
        Base1_data2 = j;
        cout<<"Base 1 constructor is called"<<endl;
    }
    void PrintData1() {
        cout<<"Value of Base 1 data1 and data2 is : "<<Base1_data1<<" and "<<Base1_data2<<endl;
    }
}; // Here we have declared one base class and added its constructor which takes a data i and the it has a print function jo uss data ki value print krta hai

class Base2 {
    int Base2_data1;
    public:
    Base2(int i) {
        Base2_data1 = i;
        cout<<"Base 2 constructor is called"<<endl;
    }
    void PrintData2() {
        cout<<"Value of Base 2 data1 is : "<<Base2_data1<<endl;
    }
}; // Here we have declared another base class and added its constructor which takes a data i and the it has a print function jo uss data ki value print krta hai

class Derived : public Base1, public Base2 { // Isme jaise humne base1 pehle likha hai and base2 baad me toh, pehle base1 ka contructor call hoga uske baad base2 ka, agar hum base2 pehle likh de toh base2 ka contructor pehle call hoga uske baad base1 ka, Aur agar hum base2 ko virtual base class declare krde toh base2 ka contructor pehle run hoga uske baad base1 ka!
    int derived1;
    int derived2;
    public:
    Derived(int a, int b, int c, int d) : Base1(c,d), Base2(d) { // This is the syntax to define a constructor of the derive class if base class have there own constructors!
        derived1 = a;
        derived2 = b;
        cout<<"Derived class constructor is called"<<endl; // These statements are just to show the order of execution of constructors!
    }
    void PrintDataDerived() {
        cout<<"Value of derived1 : "<<derived1<<endl;
        cout<<"Value of derived2 : "<<derived2<<endl;
    }
}; // And then here we have made a derived class jo Base1 and Base2 class ko inherit krta hai, and also iske paas bhi iske do variable hai derived naam se,
// and also iske paas iska khud ka ek contructor bhi hai, and uss constructor ko bhi inherit kiya gya hai base classes ke constructors se and then iss derived class ke paas bhi ek apna khud ka print function bhi hai jo derived class ki values ko print krega

int main() {
    Derived Utkarsh(1, 2, 3, 4);
    Utkarsh.PrintData1();
    Utkarsh.PrintData2();
    Utkarsh.PrintDataDerived();
    return 0;
}

// Initiallization List!
// Intialization list is nothing but a way we can assign value to the data members of the class for example :
#include<iostream>
using namespace std;
/*
Syntax for intialisation list in constructor is :
Constructor (argument-list) : initiallization section {
    [ constructor body ]
}
*/
//Example to use intiallization Section or intiallization list!
class Base {
    int a;
    int b;
    public :
    // Some variation in intiallization section :
    // Base(int i, int j) : a(i), b(i+j) -> This will work, and the output will be a = 6 and b = 10
    // Base(int i, int j) : a(i), b(2 * j) -> This will work, and the output will be a = 6 and b = 12
    // Base(int i, int j) : a(i), b(a + j) -> This will work, and the output will be a = 6 and b = 10
    // Base(int i, int j) : b(i), b(j) -> This won't work, as becoz in class, a is declared first and then b, so a should be initiallise first then b!
    Base(int i, int j) : a(i), b(j) { //Here in this line, humne a and b ko constructor ki body me initiallize krne ke bajaye, constructor ke saath saath initiallization section me hi initiallize krdiya!
        cout<<"Constructor is executed"<<endl;
        cout<<"Value of a is : "<<a<<endl;
        cout<<"Value of b is : "<<b<<endl;
    }
};

int main() {
    Base B(6,4);
    return 0;
}

// Another example to initiallize the data members for an object of a class through initiallization list is like this...
#include <iostream>
using namespace std;

class Example {
    const int a; // const member
    int& b; // reference member
    int x;
    int y;
public:
    // Constructor with initialization list
    Example(int i, int j, int& ref) : a(i), b(ref), x(i+j), y(x*2) { // Yahaa aisa samajh lo ki yahaa agar initiallzation list use nhi kiya hota, toh sab data members me alag se value assignment operator ke through dalti! but yahaa assignment vaala kaam ek line me hi hogya! and then humne constructor ki main body me unn sab values ko print kraya hai bss! agar aise list nhi bnaate toh sab data members me alag se values assign hoti jo parameters me pass hoke aa rhi hai!
        cout << "Constructor is executed" << endl;
        cout << "Value of a is: " << a << endl;
        cout << "Value of b is: " << b << endl;
        cout << "Value of x is: " << x << endl;
        cout << "Value of y is: " << y << endl;
    }
};

int main() {
    int value = 10;
    Example ex(6, 4, value); // here we have just passed the values for i, j and ref, and then baaki list ki initiallization me daaldi humne vahaa se calculate hoke unn unn data members me value assign hojayegi ek line me!
}