// Classes : Basic template for creating objects. and extensions of structures.
// Objects : Basic run time entities or the instances of class!
// Creation of objects are called Instantiation.

// What is the problem with structures? Structure does not provide data hiding, whereas C++ provides data hiding, we can hide our data so that not everyone can access it...whereas in structures we can't hide data and it can be accessed from anywhere in the program...so if we want security so we should go for classes
// Another reason to use classes is that in classes we can use function more conveniently.

// Creating class student! and creating print function inside it! and scan function inside it! but define humne sirf print function kiya hai class ke andar! class ke bahar scan function ko declare kiya gya hai!
#include<iostream>
using namespace std;

class Student1 {
    private :
    int a,b,c;
    public :
    int d,e;
    void scan(int a, int b, int c);
    void print() {
        cout<<"Value of a : "<<a<<endl;
        cout<<"Value of b : "<<b<<endl;
        cout<<"Value of c : "<<c<<endl;
        cout<<"Value of d : "<<d<<endl;
        cout<<"Value of e : "<<e<<endl;
    }
};

void Student1 :: scan(int a, int b, int c) {
    // If you want to take input from user, then do this...
    // cin>>this->a>>this->b>>this->c;
    // But as becoz humne ye function banaya hi iss type se hai ki hum function call me input chahte hai toh cin krne ki koi zarurat nhi hai!

    // If you want to pass the value to the data members in the function call, then do this...
    this->a = a;
    this->b = b;
    this->c = c;
} // Ya toh input leke scan krne ka alag method banao class ka, kyunki what will happen is agar hum method definition me int a, int b, int c likhenge iska mtlb hum cin se input nhi lena chahte hai, hum bss chahte hai ki function call me jo values ho bss vhi pass ho jaye! toh iss case me hum chahte hai ki function call ki values pass ho toh cin ki zarurat nhi hai...
// Vrna agar hum method definition me int a, int b, int c, likhenge toh hume function call me bhi values pass krni padengi! but agar method definition me cin likha hua hoga toh user se hi input lega ye method even after passing the values in the method/function call. so better is agar values pass krke input lena hai toh ek function bnao and user se input lena hai toh ek alag function bnao! dont mix them!

int main() {
    Student1 Utkarsh;
    //Utkarsh.a = 6559; we can't do this becoz...it will throw error because a is private here. Hence we can't access any private data member with just the dot operator.
    Utkarsh.scan(6, 6, 3); // Do this to call the function with passing the values!
    Utkarsh.d = 65;
    Utkarsh.e = 59;
    Utkarsh.print();
    return 0;
}

// OOPs - Classes and Objects 
// C++ - Intially it was called C with classes
// Class - Extension of Structures
// Structures had limitations like : Members are public, No methods
// Classes - Structure + More
// Classes can have methods and properties
// Classes can make few members as public and few as private
// Structures in C++ are typedefed already
// You can declare objects along with the class declaration
// Example : class Employee {
//     // Class defintion
//     } Utkarsh, Palak; --> These will become objects of the class employee.
// }
// Utkarsh.salary = 8000000; --> It  makes no sense if salary is a private member function. and it will throw an error that you are trying to access private data members in int main using class objects!


// Nesting of member functions.
#include<iostream>
#include<string>
using namespace std;

class binary {
    private :
    string s;
    // chk_binary(); If we make this function private, then we can't call it in the main() function. and if we will try to call it will show error, becoz of private member function. And can only used by members of the class.
    // So basically hum krte kya hai ki hum humesha Data members ko private rakhte hai! and member functions ko humesha public taaki hum unn member functions ki help se private ya public data members ko access kr paye!
    public :
    void read_binary();
    void chk_binary();
    void ones_compliment();
    void display();
};

void binary :: read_binary() {
   cout<<"Enter the binary number : ";
   cin>>s; 
}

void binary :: chk_binary() {
    for(int i = 0; i < s.length(); i++) {
        if(s.at(i) != '0' && s.at(i) != '1') { //--> "at()" is function of string
            cout<<"Incorrect binary format"<<endl;
        }     
    }
}

void binary :: ones_compliment() {
    chk_binary(); // If we just call the chk_binary() function inside this function, we don't need to call it in the main() function. and this is called "Nesting of member function" where we called a member function inside another member function. 
    for(int i = 0; i < s.length(); i++) {
        if (s.at(i) == '1') {
            s.at(i) = '0';
            }
        else {
            s.at(i) = '1';
        }
    }
}

void binary :: display() {
    cout<<"Ones compliment of your binary number is : "<<s<<endl;
}

int main() {
    binary b;
    b.read_binary();
    // b.chk_binary(); // Iski need nhi hai kyunki already call hogya hai ones compliment function me!
    b.display(); // If we call this function before one_compliments() function it won't do ones compliment...so we have to call that function after the call of ones_compliment function.
    b.ones_compliment();
    b.display();
    return 0;
} // Here this method does not correctly gives the one's complement of a binary number! but yes the method is correct! the only problem is sahi jagah pr sahi function call nhi kiya and sahi jagah pr sahi return statement nhi likhe hai! vrna ye ekdum sahi kaam krta! otherwise logic of one's complement and logic for chk_binary is correct!

// Another example of class!
#include<iostream>
#include<string>
using namespace std;

class Student2 {
    private :
    string name[50];
    int marks[50];
    int count;

    public :
    void counter() { count = 0; }
    void details_of_student();
    void display_name_of_student();
    void display_marks_of_student();
};

void Student2 :: details_of_student() {
    cout<<"Enter name of the student : ";
    cin>>name[count];
    cout<<"Enter marks of the student : ";
    cin>>marks[count];
    count++;
}

void Student2 :: display_name_of_student() {
    for(int i = 0; i < count; i++) {
        cout<<"Name of the student is : "<<name[i]<<endl;
    }
}

void Student2 :: display_marks_of_student() {
    for(int i = 0; i < count; i++) {
        cout<<"Marks of "<<name[i]<<" is : "<<marks[i]<<endl;
    }
}

int main() {
    Student2 Baccha;
    Baccha.counter();
    Baccha.details_of_student();
    Baccha.display_name_of_student();
    Baccha.display_marks_of_student();

    Baccha.details_of_student();
    Baccha.display_name_of_student();
    Baccha.display_marks_of_student();

    return 0;
}

// Another example of classes and their member functions!
#include<iostream>
using namespace std;
class Student{
    private:
    string name;
    int marks;
    public:
    void get_data();
    void display_data();
};

void Student :: get_data() {
    cout<<"Enter name of student: ";
    cin>>name;
    cout<<"Enter marks of student: ";
    cin>>marks;
}

void Student::display_data() {
    cout<<endl<<"Name of student is: "<<name<<endl;
    cout<<"Marks of "<<name<<" are "<<marks<<endl;
}

int main() {
    int n;
    cout<<"Enter number of students: ";
    cin>>n;
    Student bachche[500]; // Wrote 500 just as default! kyunki dynamically memory allocate toh kr nhi rhe!
    for(int i=0;i<n;i++) {
    bachche[i].get_data();
    }
    for(int i=0;i<n;i++) {
    bachche[i].display_data();
    }
}

// Static Data Members
// Static int a; --> it will contain 0 even if we don't intialize it. and it will contain 0 when the first object is created.
// Only one copy is created and it is available till entire program.

// int a; until we don't initialize it will contain garbage value.
// It is available till only end of the block.
#include<iostream>
using namespace std;

void counter() {
    static int count; // Here count will initialize with 0, because it is a static variable. And it is valid till the end of the program. Static variable are initialized only once.
    cout<<count++<<endl;
}

int main() {
    //counter(); First it will print 0.
    //counter(); Then it will print 1 because first 0 is stored in the count and then it will got increamented.
    //counter(); Then it will print 2 as because the second output 1 got stored in the static count variable.
    //counter(); and similarly...
    //counter(); and similarly...

    for(int i = 0; i < 5; i++) {
        counter();
    }
    return 0;
}

// Difference between Normal Variable and Static Variable!
#include<iostream>
using namespace std;

void counter() {
    // int count; // Here it is a normal count variable, so it will contain garbage value until we don't initialize it. So it will print Garbage value if we don't initialize it.
    int count = 0; // but even on initializing it, it will print 0 0 0 0 0 because this count variable is only till end of the block. so it will print 0 0 0 0 0. and also kyunki harr function call me count baar baar initiallize hote jaa rha hai! jabki static ke case me aise nhi hota, vo baar initiallize nhi hota isliye uske case me 1 2 3 4 5 print ho rha hai!
    cout<<count++<<endl;
}

int main() {
    //counter();
    //counter();
    //counter();
    //counter();
    //counter();

    for(int i = 0; i < 5; i++) {
        counter();
    }
    return 0;
}

// ---------------------------------------------------------------------------- Static Data Member and Static Member Function ---------------------------------------------------------------------------->
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
// Without static keyword it won't increament the count becoz a normal data member is valid only till end of the block whereas a static data member will be valid for the entire program.
// Static member function don't need an object to get called, it can be initialized with just the name of the class. and Static member function can use or access only the static data member or functions.

// -------------------------------------------------------------- Array of Objects! -------------------------------------------------------------------------------------------------->
// The similar logic can be used in array of structure's instances!
#include"iostream"
using namespace std;

class Employee {
    private :
    int id;
    int salary;

    public :
    void setID() {
        salary = 2,00,00,000;
        cout<<"Enter the ID of the employee is : "<<endl;
        cin>>id;
    }

    void getID() {
        cout<<"The ID of this employee is : "<<id<<endl;
    }
};

int main() {
    //One way to call the functions of the class is to make different objects and call them indivisually. another way is to make an array of object and then apply loop.
    Employee Hawkins_Lab[5];
    for(int i = 0; i < 5; i++) {
        Hawkins_Lab[i].setID();
        Hawkins_Lab[i].getID();
    }
    return 0;

}

// -------------------------------------------------------------- Adding complex number using classes! -------------------------------------------------------------------------------------------------->
#include<iostream>
using namespace std;

class complex {
    private :
    int a;
    int b;

    public :
    void setData(int v1, int v2) {
        a = v1;
        b = v2;
    }

    void setDataBySum(complex o1, complex o2) {
        a = o1.a + o2.a;
        b = o1.b + o2.b;
    }

    void print() {
        cout<<"The sum of the complex number is "<<a<<"i + "<<b<<"j"<<endl;
    }
};

int main() {
    complex c1, c2, c3;
    c1.setData(1,2);
    c1.print();   

    c2.setData(4,5);
    c2.print();

    c3.setDataBySum(c1,c2);
    c3.print();

    return 0;
}