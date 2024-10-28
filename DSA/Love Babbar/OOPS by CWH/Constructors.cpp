// Constructor is a special member function which the same name as of the class.
// And it is used to iniiallize the objects of its class.
// And it is automatically invoked whenever the object is created.
#include<iostream>
using namespace std;

class complex {
    int a,b;
    public :
    complex(); // Declaration of constructor. and here it is a 'default constructor' as it takes no parameter!
    void printNumber() {
        cout<<"Your number is : "<<a<<"i + "<<b<<"j"<<endl;
    }
};

complex :: complex() { // Defintion of constructor, it doesn't have a return type.
    a = 5; // Here we directly intialiized the values of a and b directly.
    b = 10; // If constructors will not be there then a and b will not be initialized and it will print garbage value! 
}

int main() {
    complex c;
    c.printNumber();
    return 0;
} // Constructor creates objects by itself.

// Properties of Constructor!
// 1. It should be declared in the public section of the class!
// 2. They are automatically invoked when the object is created
// 3. They cannot return values as they do not have return types
// 4. It can have default arguments
// 5. We cannot refer to their address

// Parameterized Contructor!!!
#include<iostream>
using namespace std;

class complex {
    int a,b;
    public :
    complex(int, int); // Here we have declared a paramterized constructor, as it contains two parameters!
    void printNumber() {
        cout<<"Your number is : "<<a<<"i + "<<b<<"j"<<endl;
    }
};

complex :: complex(int x, int y) { // Here we are defining the parametrized constructor as it takes 2 paramters x and y and assign there values in a and b!
    a = x;
    b = y;
}

int main() {
    // For paramterized constructor we have 2 types of calls that is Implicit call and Explicit call!
    // Implicit Call!
    complex a(1,2);
    a.printNumber();

    // Explicit Call!
    complex b = complex(3,4);
    b.printNumber();
    return 0;
}

#include<iostream>
using namespace std;

class Point {
    int x,y;
    public :
    Point (int a, int b) { // Here again we have declared and defined a parameterized constructor and and we have assigned two paramters to it
        x = a;
        y = b;
    }

    void displayPoint() { //Member function to display the points
        cout<<"The point is ("<<x<<", "<<y<<")"<<endl;
    }
};

int main() {
    Point P(2,3); // Here we have called it implicitly!
    P.displayPoint(); // And here we have called its member function of the class to display the point!

    Point Q(4,5);
    Q.displayPoint();

    return 0;
}

// Constructor Overloading!!!
#include<iostream>
using namespace std;

class Point {
    int x,y;
    public :
    // Below is an example of Constructor Overloading where we have Declared three same constructor but with different number of parameters, toh jab call krne ke time hum jitne paramters use krenge apne implicit call me, uss hisaab se vo vaala constructor call ho jayega!!
    Point (int a, int b) {
        x = a;
        y = b;
    }

    Point (int a) { // Ye constructor tab call hoga jab humne sirf ek parameter daala hoga aone call me
        x = a;
        y = 0;
    }

    Point() { // And ye constructor tab call hoga jab humne koi bhi paramter nhi daala while calling!
        x = 2;
        y = 2;
    }

    void displayPoint() {
        cout<<"The point is ("<<x<<", "<<y<<")"<<endl;
    }
};

int main() {
    Point c1(4,5); // Is case me first vaala constructor call hoga kyunki isme aur usme do parameters hai
    c1.displayPoint();

    Point c2(3); // Is case me 2nd vaala constructor call hoga kyunki isme sirf ek hi parameter hai call me
    c2.displayPoint();

    Point c3; // Isme 3rd vaala constructor call hoga kyunki isme ek bhi parameter nhi hai call me
    c3.displayPoint();
    // Hence this is constructor overloading where we have more than one constructor of same class and it is called again and again with different number of paramters!
    return 0;
}

// Default Constructors
#include<iostream>
using namespace std;

class Simple {
    private :
    int Data1;
    int Data2;
    public :
    Simple(int a, int b) { // Here we have declared a constructor which has two parameters a and b
        Data1 = a;
        Data2 = b;
    }

    void printData();
};

void Simple :: printData() {
    cout<<"The value of Data1 and Data2 is "<<Data1<<" and "<<Data2<<endl; // Here we wrote a function to do printing operations
}

int main() {
    Simple s(1,2);
    s.printData(); // Here we simply printing those data values
}


#include<iostream>
using namespace std;

class Simple {
    private :
    int Data1;
    int Data2;
    public :
    Simple(int a, int b=5) { // Here we have used a paramterized constructor and here it has a default value for b, so if be will not be alloted any value then due to default value the value of b will be directly alloted.
        Data1 = a;
        Data2 = b;
    }

    void printData();
};

void Simple :: printData() {
    cout<<"The value of Data1 and Data2 is "<<Data1<<" and "<<Data2<<endl; // Here we have used a print function to print the data values.
}

int main() {
    Simple s(1); // Here we have passed only one value and that is for a, if here we pass any value for b then that will get printed otherwise the default value will get printed.
    s.printData();
}

#include<iostream>
using namespace std;

class Simple {
    private :
    int Data1;
    int Data2;
    int Data3;
    public :
    Simple(int a, int b=5, int c=10) { // Here we again used a parameterized constructor where we have passed 3 parameters and out of which two are default parameters, means if we do not pass any value to it then the default values will get printed.
        Data1 = a;
        Data2 = b;
        Data3 = c;
    }

    void printData(); // Here we have a print function to print values
};

void Simple :: printData() {
    cout<<"The value of Data1 and Data2 is "<<Data1<<","<<Data2<<" and "<<Data3<<endl; // print function to print the 3 values.
}

int main() {
    Simple s(1); // Here we have passed only one value and that is for a and values for b and c will be default.
    s.printData();
}

// Dynamic Initiallization of Objects
// Understand this concept using Compund interest and Simple Interest
#include<iostream>
using namespace std;

class BankDeposit {
    int principal;
    int years;
    float interest;
    float ReturnValue;

    public :
    BankDeposit() {}
    BankDeposit(int p, int y, float r);
    BankDeposit(int p, int y, int r);
    void show();
};

BankDeposit :: BankDeposit(int p, int y, float r) {
    principal = p;
    years = y;
    interest = r;
    ReturnValue = principal;

    for(int i=0; i<y; i++) {
        ReturnValue = ReturnValue * (1+interest); // Here we will put the interest rate in decimals and that "1+interest" ss becoz that interest will add up to the principal after the first year!
    }
}

BankDeposit :: BankDeposit(int p, int y, int r) {
    principal = p;
    years = y;
    interest = float(r)/100;
    ReturnValue = principal;

    for(int i=0; i<y; i++) {
        ReturnValue = ReturnValue * (1+interest); // Here we will put the interest rate in integer and that "1+interest" is becoz that interest will add up to the principal after the first year! and here we have converted that interest rate from integer to float, but input will be in integer, and later on we have converted it in float and divided by hundred to added 1 and then we have multiplied it with return value which already stored principal value!
    }
}

void BankDeposit :: show() {
    cout<<"Principal Amount is : "<<principal<<". Return Value after "<<years<<" years is "<<ReturnValue<<endl; //This is a print function for the Return Value!
}


int main() {
    BankDeposit bd1, bd2, bd3;
    int p,y;
    float r;
    int R;

    cout<<"Enter the value of p, y and r : "<<endl;  // For Interest rate in Decimals!
    cin>>p>>y>>r;
    bd1 = BankDeposit(p,y,r);
    bd1.show();

    cout<<"Enter the value of p, y and R : "<<endl; // For Interest rate in Integer!
    cin>>p>>y>>R;
    bd2 = BankDeposit(p,y,R);
    bd2.show();

    bd3.show(); // Here as there is no parameters and anything then the default constructor will run but it will print garbage values!
    // But if we will remove that default constructor then it will show error!

    // Like what happened here is, if we have declared 3 objects bd1 bd2 bd3 then agar hum kabhi p y r ki value nhi bhi de paate hai fir bhi ye program run ho jaye default constructor ka use krke!
}

// Copy Constructor!
// A constructor which creates an object by initializing it with an object of the same class.
#include<iostream>
using namespace std;

class Number {
    int a;
    public :
    Number() {
        a = 0;
    } // We need to introduce this blank/default constructor as we have studied previously!

    Number(int num) {
        a = num;
    }

    Number(Number &obj) {
        cout<<"This is a copy constructor!!!!"<<endl;
        a = obj.a; // First we have to make this constructor and pass the reference of an object
    }

    void display() {
        cout<<"The number for this object is "<<a<<endl;
    }
};

int main() {
    Number x,y,z(50),z2; // (z3 is made later on!) Here we need to introduce a default constructor as we have learned previously!
    x.display(); // Here we have printed the value of x, which is 0
    y.display(); // Here we have printed the value of y, which is 0
    z.display(); // Here we have printed the value of z, which is 50
    // If we don't give any value uptill here it will print garbage value, but we assign some values to x and y in the default constructor we have made then it will result in printing those default values!

    // But now lets understand the copy constructor!
    // To make a copy constructor we have to do these things.....
    // Here we are calling the copy constructor explicitly!
    Number x1(x); // Here x1 is a variable of Number type and we have passed the refrence of x in it!
    x1.display(); // And this is a print function to print the x1!

    Number y1(y); // Here y1 is a variable of Number type and we have passed the refrence of y in it!
    y1.display(); // And this is a print function to print the y1!

    Number z1(z); // Here z1 is a variable of Number type and we have passed the refrence of z in it!
    z1.display(); // And this is a print function to print the z1!

    // Here we are not calling the copy constructor explicitly, but kyunki hum ek object ko dusre object me copy krne ki koshish kr rhe hai, toh compiler ye cheez notice krta hai and vo apne aap se hi copy constructor ko call lgaa deta hai! hence this is implicit call!
    // But what if remove the copy constructor? Will it show error and the answer is NO, because the compiler supplies its own copy constructor when no copy constructor is found!, But still we make one on our own!
    z2 = z; // Copy constructor will not be invoked becoz here object is already created and we are assigning the z later on!
    Number z3 = z; // Here copy constructor will be invoked! as becoz here the z3 is created in the same line and the value is assigned in the same line!
    z3.display(); // Here we are printing the value of z3 after the copy constructor is invoked! In the above line we were just checking whether the copy constructor is invoked or not and it is invoked! and now we are printing the value!
}



