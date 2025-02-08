// ---------------------------------------------------------- LECTURE 41 - Recursion Day-11 : Time and Space Complexity of Recursive Algorithms --------------------------------------------------------------------------------------------------------->
// In this lecture most of the part is about the mathematics that how the TC and SC are calculated, so vo cheez abhi notes bnaate time maine dekhli hai toh next time jab padhoge tab ek baar agar zarurat pade ki kaise TC and SC calculate hua hai toh tab firse ek baar dekh lena!
// Overall most of the part is mathematics!
// But here are the final results of all the TC and SC calculated for the some recursive algorithms!
// There are different methods to find the TC and SC... like recursion tree and Elimination method, Substitution method and more... you can explore all of them when you will be revising!

// TIME COMPLEXITIES :
// Factorial : O(n)
// Binary Search : O(logn)
// Merge Sort : O(nlogn)
// Fibonacci Series : O(2^n)

// SPACE COMPLEXITIES :
// This is a little different from TC as yahaa pr memory kaise use ho rhi hai uski baat hoti hai... so yahaa hum baiscally ye nikalte hai ki kitni max space use ho rhi hai kisi instant time pe!
// Factorial : O(n)
// Binary Search : O(logn)
// Merge Sort : O(n)
// Fibonacci Series : O(n)

// With that... try to find TC and SC of all the previous algorithms that have been done in all these Day1 - Day11 of recursion! using the suitable methods!
// Also visit CodeStudio and read and understand and solve the articles and questions! and you can visit it thru the link of below the lecture on yt!
// Practice to find TC and SC it is important!

// ---------------------------------------------------------- LECTURE 42 - OOPS Part 1 --------------------------------------------------------------------------------------------------------->
// A programming paradigm where everything revolves around objects, integrating real-world objects into the program to increase real-world application.
// Objects : Have properties (state) and behaviors (functions). Example : A game hero with properties like Name, Health, Level, and behaviors like Attack() and Defend().
// Classes : A user-defined data type. Defines the blueprint or template for objects. And an object is an instance of a class. Example : int a; -> a is a variable of type int. Hero Ramesh; -> Ramesh is an object of type Hero.

// So you can say that Class is the Data Type and Object is like the Variable!
// Lets code...
#include<iostream>
using namespace std;

class Hero {
    int health;
}; // iss class ki help se jo bhi objects hum banayenge ye unki properties hongi! for now its only health!

int main() {
    Hero Utkarsh; // So what we did here is we made an Object (instance of class Hero) Utkarsh jo Hero type ka hai!
    cout<<"Size of Utkarsh : "<<sizeof(Utkarsh)<<endl; // It will output as 4 bytes kyunki Utkarsh jo object hai uski abhi sirf ek hi property hai and that is Health and health is of int type and int occupies 4 bytes!
    // Agar koi property nhi likhi hogi toh output 1 byte ayega kyunki compiler class ki identfication ke liye kuch nhi toh 1 byte toh memory me store kr hi deta hai!
}
// Now doing this has two ways, yaa toh hum alag se Hero.cpp vaali file create krle and then usko preprocessor directive me daal ke uss Hero.cpp file ko include krle yaa toh explicitly yhi pr class bnaa de! We can do either way, choice is ours!
// Now if you want to access the properties which are technically called Data Members using Objects, you need to use "." operator!

// Let see...
#include<iostream>
using namespace std;

class Hero {
    int Health;
    int Age;
};

int main() {
    Hero Utkarsh;
    cout<<"Utkarsh's health is : "<<Utkarsh.Health<<endl;
    cout<<"Utkarsh's age is : "<<Utkarsh.Age<<endl;
    // They will throw errors becoz right now they are private data members! we need to make them public to access them.. but lets first study the Access Modifiers in OOPS!
}

// Access Modifiers!
// They are used to define the scope of Data Members, ki kisi data member ko hum kahaa pr access kr payenge, kya sirf class ke andar hi access kr payenge ya class ke bahar bhi yaa kisi aur class ke andar bhi and all...
// Their are three types of Access Modifiers : Public, Private and Protected!
#include<iostream>
using namespace std;

class Hero {
    private :
        int Health; // Private member (not accessible outside the class)
    public :
        int Age; // Public member (accessible outside the class)
}; // Any data member or member function, created privately cannot be accessed outside of it!

int main() {
    Hero Utkarsh;
    // cout<<"Utkarsh's health is : "<<Utkarsh.Health<<endl; // It will throw error
    cout<<"Utkarsh's age is : "<<Utkarsh.Age<<endl; // It won't throw error, but will print garbage value as it is not initiallized!
}

// Now if you have private data members, but you still want to access it! In that case you can make Getter and Setter Function! These functions are created withing the public scope and can be accessed using "." operator!
#include<iostream>
using namespace std;

class Hero {
    private :
    int Health; // Now as health is private toh ab health ko directly access nhi kr sakte! so we need to create getter and setter functions for it in the public scope of the class!
    public :
    int Age;
    int Level;
    char Name;
    void print() {
        cout<<Level<<endl;
    }
    int getHealth() {
        return Health;
    }
    int sethealth(int h) {
        Health = h;
    }
}; // Getter Setter functions are only created for private data members, so that we can access them! not for public data members, as they are already accessible outside the class!

int main() {
    Hero Utkarsh;
    Utkarsh.sethealth(100); // Even tho health is a private member we are able to set the value of Health using the setter function!
    cout<<"Utkarsh's health is : "<<Utkarsh.getHealth()<<endl; // Printed the value of Health using the getter function we have created inside the class!
    
    Utkarsh.Age = 21;
    cout<<"Utkarsh's age is : "<<Utkarsh.Age<<endl;

    // Lets calculate size of the data members...
    cout<<"Size of Utkarsh : "<<sizeof(Utkarsh)<<endl; // Output : 16, jabki dekha jaye toh 13 aani chahiye, kyunki Health + Level + Age = 12, and then Name is of one byte so it should be 13, but answer is 16 aisa kyu? so aisa isliye beoz of Padding and Greedy alignment!
    // Padding : Padding involves inserting empty bytes between the members of a structure or class to ensure that each member is properly aligned in memory. The goal of padding is to ensure that each data member starts at an address that's a multiple of its size, which can improve memory access performance, especially on architectures that require aligned memory accesses.
    // Alignment : Alignment refers to the requirement that data types should start at particular memory addresses. For example, many architectures require that int variables start at memory addresses that are multiples of 4 (for 32-bit integers) or 8 (for 64-bit integers). Similarly, char variables can usually start at any address. Alignment can be influenced by the size of the data type. For example, if an int requires 4-byte alignment, and a char requires 1-byte alignment, the compiler may insert padding bytes between the members of a structure to ensure proper alignment.
    // Greedy Alignment : Greedy alignment is a strategy used by some compilers to minimize padding. In greedy alignment, the compiler tries to align each member of a structure or class to the largest alignment requirement of any member in the structure. This strategy helps reduce padding by minimizing the number of empty bytes inserted between members.
}

// We can also define class methods outside the class! But we just need to first declare it inside!
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
    // cin>>this->a>>this->b>>this->c; // To take input from the user!
    // Some obvious considerations : Remove the paramsters, as the method will no longer depend on parameters being passed to it. Instead, it will prompt the user for input directly!
    //                             : You may want to do anyone of the two way of assigning values to a, b, c.
    this->a = a;
    this->b = b;
    this->c = c;
}

int main() {
    Student1 Utkarsh;
    // Utkarsh.a = 6559; // Will throw error, as "a" is private here. Hence, cannot be accessed directly!
    Utkarsh.scan(6, 6, 3);
    Utkarsh.d = 65;
    Utkarsh.e = 59;
    Utkarsh.print();
    return 0;
}

// Static and Dynamic Allocation!
#include<iostream>
using namespace std;

class Hero {
    private :
    int Health;
    public :
    int Age;
    int Level;
    char Name;
    void print() {
        cout<<Level<<endl;
    }
    int getHealth() {
        return Health;
    }
    int sethealth(int h) {
        Health = h;
    }
};

int main() {
    // Statically Created Object!
    Hero Utkarsh1;
    // Here we can use the normal syntax to print its properties!
    Utkarsh1.Level = 69;
    Utkarsh1.sethealth(100);
    cout<<"Level : "<<Utkarsh1.Level<<endl;
    cout<<"Health : "<<Utkarsh1.getHealth()<<endl;

    // Dynamically Created Object!
    Hero *Utkarsh2 = new Hero; // Allocates memory dynamically on the heap. Utkarsh2 is a pointer storing the address of the allocated memory. 32-bit Compiler : Allocates 4 bytes of memory on the heap. 64-bit Compiler : Allocates 8 bytes of memory on the heap.
    (*Utkarsh2).Level = 69;
    (*Utkarsh2).sethealth(100);
    cout<<"Level : "<<(*Utkarsh2).Level<<endl;
    cout<<"Health : "<<(*Utkarsh2).getHealth()<<endl;

    // Another way dynamic vaali values print krne ka is...using "->" arrow operator, ye sirf dynamic ke time hi krna hai!
    cout<<"Level : "<<Utkarsh2->Level<<endl;
    cout<<"Health : "<<Utkarsh2->getHealth()<<endl;
}

// Default Constructor!
// A special method that is automatically called when an object is created. Called as ObjectName.Class() internally.
// Key Points : Default Constructor : No return type and No input parameters.
//            : Works behind the scenes even if not explicitly defined in the class.
// You can also define your own default constructor in the class if needed!
#include<iostream>
using namespace std;

class Hero {
    private :
    int Health;
    public :
    int Age;
    int Level;
    char Name;
    Hero() {
        cout<<"Constructor Called!"<<endl;
    }
    void print() {
        cout<<Level<<endl;
    }
    int getHealth() {
        return Health;
    }
    int sethealth(int h) {
        Health = h;
    }
};

int main() {
    // Statically Created Object
    Hero Utkarsh; // Jaise hi hum iss object ko create krenge vaise hi default constructor call hojayega, agar humne explicitly class me nhi bnaaya hua koi default constructor then compiler ne jo default constructor background me banaya hua hai vo call hojayega pr usko koi effect nhi dikhega,
    // but agar hum koi apna khud ka default constructor bnaate hai toh jo pehle vaala constructor hai ye naya vaala usko replace krdega! and iss naye vaale ka effect dekhne ke liye we can use the cout statement! ki jaise hi object creation hua vaise hi constructor call hogya!

    // Dynamically Created Object
    Hero *Utkarsh1 = new Hero; // Dono hi case me same constructor call hoga! kyunki class toh same hi hai dono objects ka!
    // Hero *Utkarsh2 = new Hero(); // Aise bhi likh sakte hai
}
// Note : If you define a constructor (default or parameterized) : The compiler-generated default constructor (implicit constructor) is no longer provided.
//      : If you later remove your custom constructor and try to create an object without explicitly defining a constructor again, it will result in an error because the compiler doesn't auto-generate the default constructor anymore.

// Example (Creating constructor outside the class)!
#include<iostream>
using namespace std;

class complex {
    int a,b;
    public :
    complex(); // Declaration of constructor.
    void printNumber() {
        cout<<"Your number is : "<<a<<"i + "<<b<<"j"<<endl;
    }
};

complex :: complex() { // Defintion of constructor, it doesn't have a return type.
    a = 5;
    b = 10;
}

int main() {
    complex c;
    c.printNumber();
    return 0;
} // Similarly you can do for parameterized constructor!

// Parameterized Constructor! and "This" keyword!
#include<iostream>
using namespace std;

class Hero {
    private :
    int Health;

    public :
    int Age;
    int Level;
    char Name;
    
    // Hero(int Health) {
    //     Health = Health; // In such cases it causes confusion for compiler ki kis health ko kidhar daalna hai, so for that we use a "this" keyword, where "this" is a pointer that stores the address of the current object! so this is how we use it...
    // }

    Hero(int Health) {
        this -> Health = Health; // Resolves ambiguity : Left side is the object's data member, right side is the parameter.
        // "this" eliminates confusion when parameter and data member have the same name. If names are different, "this" is not required.
        // "this" is a pointer storing the address of the current object.
        // Current object : The object that invokes the function or constructor. Example : If the current object is "Utkarsh", this constructor assigns the parameter value to "Utkarsh's" Health.
    }
    Hero() {
        cout<<"Constructor Called!"<<endl;
    }
    void print() {
        cout<<Level<<endl;
    }
    int getHealth() {
        return Health;
    }
    int sethealth(int h) {
        Health = h;
    }
};

#include<iostream>
using namespace std;

class Hero1 {
    private :
    int Health;

    public :
    int Age;
    int Level;
    char Name;

    Hero1(int Health) {
        cout<<"Address of this : "<<this<<endl;
        this -> Health = Health;
    }
    Hero1() {
        cout<<"Constructor Called!"<<endl;
    }
    void print() {
        cout<<Level<<endl;
    }
    int getHealth() {
        return Health;
    }
    int sethealth(int h) {
        Health = h;
    }
};

int main() {
    Hero1 Utkarsh(100); // This object will call the paramterized constructor!
    cout<<"Address of Utkarsh : "<<&Utkarsh<<endl; // Also "cout<<"Address of this : "<<this<<endl;" both are giving the same output!

    Hero1 Utkarsh2; // Creates an object using the default constructor.
    // Note : If you have not defined any constructor, the compiler provides a default constructor automatically.
    //      : However, if you explicitly define a constructor (parameterized or default), the compiler's default constructor is removed.
    //      : So, if you have a default object and remove the default constructor (after defining it), it will result in a compilation error because the default constructor is required for creating default objects.

    // Multiple parameters in the parameterized constructor : You can pass multiple parameters to a parameterized constructor. In such cases, "this" can be used to distinguish between parameters and member variables for each parameter.
}

// Copy Constructor!
// Purpose : Used to copy objects by initializing a new object with the data of an existing object of the same class.
// Key Points : A compiler-provided copy constructor exists by default and is automatically used if you don’t define one explicitly.
//            : It initializes the new object by copying the data members of the existing object.
//            : Member functions are not copied in either assignment or copy construction. Functions (methods) are part of the class definition and are shared across all objects of the class. So, they don't need to be copied, they already belong to the class.
// Definition : Default Copy Constructor: Automatically provided by the compiler if not explicitly defined.
//            : Custom Copy Constructor: Defined by the programmer to control the copy process.
// Usage : Custom Copy Constructor : Defined by the programmer to control the copy process.
//       : Default Copy Constructor : Automatically provided by the compiler if not explicitly defined.
#include<iostream>
using namespace std;

class Hero2 {
    private :
    int health;

    public :
    int level;
    int age;

    Hero2(Hero2& old_obj) { // Here we use & to avoid ambiguity! Using & ensures that you're working with the original object rather than a copy. If you don't use &, the copy constructor would be called to create a copy, and any modifications made within the copy constructor would only affect the copy, not the original object.
        health = old_obj.health;
        level = old_obj.level;
        age = old_obj.age;
    }

    Hero2(int health, int age, int level) {
        this -> health = health;
        this -> age = age;
        this -> level = level;
    }

    void display() {
        cout<<"Health of the object : "<<health<<endl;
        cout<<"Age of the object : "<<age<<endl;
        cout<<"Level of the object : "<<level<<endl;
    }
};

int main() {
    Hero2 old_obj1(100,21,69); // Created and intiallized an object using a paramterized constructor! agar default hota toh hume sab values alag alag initiallize krni padti!
    Hero2 new_obj1(old_obj1); // Copies the old object into the new one! agar khud se apna copy constructor nhi create krenge toh compiler khud ka copy constructor call krdega agar hum object aise copy krne ka try krenge toh! khud ka create krne ka yhi fayeda hota hai ki hum thora customize kr sakte hai ki hum kaise copy krna chahte hai object ko!

    old_obj1.display();
    new_obj1.display();
}

// Now lets understandd deep and shallow copy constructors!
#include<iostream>
#include<string>
#include<cstring>
using namespace std;

class Hero3 {
    private :
    int health;

    public :
    int level;
    int age;
    char *name; // Here we are trying to allocate the memory for name dynamically, vo kaise? vo aise ki hum name ko intizallize default constructor me karayenge! taaki jab object create ho tab hi name ke liye memory allocate aur vo bhi dynamically!

    Hero3() {
        cout<<"Default constructor called!";
        name = new char[100];
    }

    void setterFunc(char name[], int health, int level, int age) { // Created the setter function, kuch nhi bss jo cheeze pehle hum alag alag likh rhe the unn sabko ek me hi likh diya setter function bnaa ke!
        strcpy(this->name,name);
        this->health = health;
        this->level = level;
        this->age = age;
    }

    void getterFunc() { // Did the same with the getter function!
        cout<<endl;
        cout<<"[ Name : "<<name<<", ";
        cout<<"Health : "<<health<<", ";
        cout<<"Level : "<<level<<", ";
        cout<<"Age : "<<age<<" ]"<<endl;
    }
};

int main() {
    Hero3 hero1;
    char name[] = "Utkarsh";
    hero1.setterFunc(name, 100, 69, 21); // So here we have set the details for our object 1 which is hero1!
    hero1.getterFunc();

    // Now lets create a copy of this object! using default copy constructor!
    Hero3 hero2(hero1); // Poora ka poora hero1, hero2 me copy hogya as it is...
    hero2.getterFunc(); // Humne usko print bhi karaa liya!

    // Now lets change the name in the hero1...
    hero1.name[1] = 'S'; // humne ye chhota sa change kiya hero1 ke name me... and now lets print it...
    hero1.getterFunc(); // And its name is printing Stkarsh... jo ekdum sahi hai kyunki humne yhi changes kiye hai... but now comes the interesting part...
    hero2.getterFunc(); // hero2 me bhi name change hogya hai!! jabki humne name me changes sirf hero1 me kiye the!
    // So this is called shallow copy!...toh jo humara default copy constructor hota hai vo ek shallow copy constructor hota hai!
    // Lets understand aisa kyu hua!
    // Jab humne name me Utkarsh store kiya toh, "Utkarsh/0" store hua memory me, and then humne class me jo name banaya vo ek pointer ki help se banaya and and vo name hi as a data member humne dono objects me daale hai, toh jo dono objects bane hai unme 4 data members ke liye space bani hui hai jaise name, health, age, level... ab jo name vaali space hai usme toh name variable ka address stored hai na! and jab copy bhi hua object toh name ka address bhi copy hui!
    // Isliye jab humne name ki value me koi bhi change kiya toh vo change dono objects me reflect hua!
}

// Ab agar ye cheez hone se rokni hai toh usko hum deep copy kehte hai! and hume apne copy constructor ko deep copy banana tha!
// so we need to do the changes in the copy constructor's defintion!
#include<iostream>
#include<string>
#include<cstring>
using namespace std;

class Hero3 {
    private :
    int health;

    public :
    int level;
    int age;
    char *name;

    Hero3() {
        cout<<"Default constructor called!";
        name = new char[100];
    }

    // Creating a copy constructor which will perform the deep copy! this will over write the default copy constructor which was doing the shallow copy!
    Hero3(Hero3& temp) { // Uss shallow copy se bachne ke liye what this will do is ki ye jo name vaali array thi uska bhi ek copy bana dega object copy krte time, isse jo bhi changes hum krenge ek object ke name vo dusre object ke name me carry forward nhi honge, kyunki dono ke liye apne apne name vaale array separate hogye hai! pehle dono ke liye changes same hi array me ho rhe the!
        char *ch = new char[strlen(temp.name) + 1];
        strcpy(ch, temp.name);
        this->name = ch;
        this->health = temp.health;
        this->age = temp.age;
        this->level = temp.level;
    }

    void setterFunc(char name[], int health, int level, int age) {
        strcpy(this->name,name);
        this->health = health;
        this->level = level;
        this->age = age;
    }

    void getterFunc() {
        cout<<endl;
        cout<<"[ Name : "<<name<<", ";
        cout<<"Health : "<<health<<", ";
        cout<<"Level : "<<level<<", ";
        cout<<"Age : "<<age<<" ]"<<endl;
    }
};

int main() {
    Hero3 hero1;
    char name[] = "Utkarsh";
    hero1.setterFunc(name, 100, 69, 21);
    hero1.getterFunc();

    Hero3 hero2(hero1);
    hero2.getterFunc();

    // Dono me se kisi bhi object ke name ya kisi aur data member (property) me koi bhi changes kroge toh vo dono object me show krenge! shallow copy constructor ke case me!
    // But agar tum yhi Deep copy kroge toh jisme jo change kroge vo change sirf usme hi reflect hoga!
    hero1.name[1] = 'S';
    hero1.getterFunc();
    hero2.getterFunc();

    hero2.name[2] = 'K';
    hero1.getterFunc();
    hero2.getterFunc();
    // So from this example both deep and shallow copy constructors are clear!
}

// Use of Copy Assignment operator : Agar do object create ho chuki hai and dono me se kisi ek ko dusre me copy krna hai tab we use this operator, copy constructor me kya tha ki ek object create ho chuki hai dusra object bss create hua hai but initiallize nhi and hume pehle vaali ko dusre me copy krna hai then we use that, but here dono initialize ho rakhe hai and humne bss ek ko dusre me copy krna hai!
#include<iostream>
#include<string>
#include<cstring>
using namespace std;

class Hero3 {
    private :
    int health;

    public :
    int level;
    int age;
    char *name;

    Hero3() {
        cout<<"Default constructor called!";
        name = new char[100];
    }

    void setterFunc(char name[], int health, int level, int age) {
        strcpy(this->name,name);
        this->health = health;
        this->level = level;
        this->age = age;
    }

    void getterFunc() {
        cout<<endl;
        cout<<"[ Name : "<<name<<", ";
        cout<<"Health : "<<health<<", ";
        cout<<"Level : "<<level<<", ";
        cout<<"Age : "<<age<<" ]"<<endl;
    }
};

int main() {
    Hero3 hero1;
    char name[] = "Utkarsh";
    hero1.setterFunc(name, 100, 69, 21);
    hero1.getterFunc();

    char name2[] = "Aditya";
    Hero3 hero2;
    hero2.setterFunc(name2, 100, 70, 22);
    hero2.getterFunc();

    // So after creating and initiallizing both the objects we are just going to assign one to another...
    hero1 = hero2; // Ab hero1 me hero2 ki saari values copy hogyi hai!
    hero1.getterFunc(); // Output of hero1 will be the output of hero2 kyunki hero2 ki values humne saari hero1 me copy krdi hai!
}

// Example (copying using assignment operator)
#include<iostream>
using namespace std;

class Number {
    int a;
    public :
    Number() {
        a = 0;
    }

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
    Number x,y,z(50),z2;
    x.display(); // Here we have printed the value of x, which is 0
    y.display(); // Here we have printed the value of y, which is 0
    z.display(); // Here we have printed the value of z, which is 50
    // If we don't give any value uptill here it will print garbage value, but we assign some values to x and y in the default constructor we have made then it will result in printing those default values!

    // But now lets understand the copy constructor! There are three ways of copying one object to another! Through "copy constructor", "assignment operator" and using "copy constructor + assignment operator"!
    // Using Copy Constructor! - Calling Copy Constructor Explicitly!
    Number x1(x); // Here x1 is a variable of Number type and we have passed the reference of x in it!
    x1.display();

    Number y1(y); // Here y1 is a variable of Number type and we have passed the refrence of y in it!
    y1.display();

    Number z1(z); // Here z1 is a variable of Number type and we have passed the refrence of z in it!
    z1.display();

    // Using Assignment Operator! - It won't invoke copy constructor, it will just copy the data members value to the new already declared object!
    z2 = z; // z2 has already been created as an object. When you use the assignment operator (=), the copy constructor is not invoked. Instead, the assignment operator is used to copy the value of z to z2.
    z2.display(); // The data members (variables) of object z will be copied to z2. So, the values of z.a, z.health, etc., will be assigned to the corresponding members of z2. This copying happens at the variable level, not at the function level.

    // Using Copy constructor + Assignment operator! - Calling Copy Constructor Implicitly!
    Number z3 = z; // z3 is being created and initialized with the value of z in the same line. This is treated as an initialization, not an assignment. Even though the syntax looks like an assignment, this is actually copy initialization, which involves calling the copy constructor to initialize z3 with z.
    z3.display();
    // A new object (z3) is created, and values from z are copied into z3. This invokes the copy constructor. Just like the assignment operator, the data members of z are copied to z3. This includes any variables like a, health, etc.
    // But what if remove the copy constructor? Will it show error and the answer is NO, because the compiler supplies its own copy constructor when no copy constructor is found!, But still we make one on our own!
}

// Destructors!
// Purpose : Used to deallocate memory and clean up resources when an object's lifetime ends.
// Key Points : Automatically called when the object goes out of scope or is explicitly deleted.
//            : No return type and no input parameters.
//            : Same name as the class, prefixed with a ~ (Example : ~ClassName).
// Default Behavior : A default destructor is automatically created by the compiler if not explicitly defined.
// Custom Destructors : Programmers can define their own destructors for custom cleanup operations.
// Example Usage : In cases like the above examples, destructors are called automatically when the main scope ends, freeing memory.
// lets see an example...
#include<iostream>
using namespace std;

class Hero4 {
    private :
    int age;

    public :
    int health;

    // Constructor :
    Hero4() {
        cout<<"Constructor Called!"<<endl;
    }

    ~Hero4() {
        cout<<"Destructor Called!"<<endl;
    }
};

int main() {
    // Object created statically!
    Hero4 Utkarsh;

    // Object created dynamically!
    Hero4 *Utkarsh1 = new Hero4; // Here we will notice one thing that static objects ke liye constructor automatically call hojaata hai but dynamic ke liye hume alag se manually krna padta hai for that we need to do it manually!
    delete Utkarsh1; // This is to call the destructor for the dynamically created object
    // Kyunki agar ye nhi likhte toh static vaale ke liye ek baar constructor call hua and ek baar destructor, but dynamically ke case me sirf ek baar constructor call hua, destructor ko call krne ke liye we need to write delete object_name; taaki destructor bhi call hojaye!
}

// Static Keyword!
// Purpose : Used for data members or methods that are shared across all objects of a class.
// Key Points : Shared Across the Class : A static data member is common to all objects of the class.
//            : If we do not initiallize it, it will contain 0 initially!
//            : Example : In a game, timeToComplete is the same for all Hero or Enemy objects.
// Single Memory Allocation : Memory for static members is allocated only once, shared by all objects.
// Initialization Outside the Class : [datatype] [ClassName]::[StaticDataMember] = [Value];
// Access Without Objects : Static members can be accessed using the class name (e.g., ClassName::StaticMember).

// Basic Understanding Example :
#include<iostream>
using namespace std;

void counter() {
    // static int count; // This will automatically initialize `count` to 0 (default for static variables). And it will incremented as the loop goes on!
    static int count = 0; // This explicitly initializes `count` to 0 (same as the default behavior). But still the static key words behaviour makes it retain its previous value! Hence, it behaves the same as above!
    cout << count++ << endl;
}

int main() {
    // counter(); // First it will print 0.
    // counter(); // Then it will print 1 because first 0 is stored in the count and then it will got increamented.
    // counter(); // Then it will print 2 as because the second output 1 got stored in the static count variable.
    // counter(); // and similarly...
    // counter(); // and similarly...

    for(int i = 0; i < 5; i++) {
        counter();
    }
    return 0;
}
// Note : During the first function call, the static variable count is initialized to 0 (since you specified = 0), and its value is stored in memory.
//      : After the first call, the static variable does not get re-initialized. The value of count remains in memory. Every time the function is called afterward, the previous value of count is used (because it's retained), and it gets incremented by 1.
//      : The static variable lives in a special area of memory known as the data segment (not the stack), which is why it persists across function calls.
//      : Whereas, if there would be some normal variable, then that would have initiallized again and again! and would have printed 0 eveytime!

// Practical Example :
#include<iostream>
using namespace std;

class Hero5 {
    private :
    int age;

    public :
    int health;
    static int timeToComplete;

    // Constructor :
    Hero5() {
        cout<<"Constructor Called!"<<endl;
    }

    // Destructor :
    ~Hero5() {
        cout<<"Destructor Called!"<<endl;
    }
};

int Hero5 :: timeToComplete = 5; // Initialization, and we don't need objects to access static data members!

int main() {
    cout<<Hero5::timeToComplete<<endl; // It will print 5

    Hero5 h1;
    cout<<h1.timeToComplete<<endl; // Krne ko aise bhi kr skte hai but this is not recommended! kyunki ye kisi object ko belong hi krta ye class ko belong krta hai!

    Hero5 h2;
    h2.timeToComplete = 10; // Humne time to complete change krdiya ab, aur ab ye change jab hua hai toh ye poori class ke liye change hua hai!
    cout<<h1.timeToComplete<<endl; // Krne ko aise bhi kr skte hai but this is not recommended! kyunki ye kisi object ko belong hi krta ye class ko belong krta hai!
    cout<<h2.timeToComplete<<endl; // Krne ko aise bhi kr skte hai but this is not recommended! kyunki ye kisi object ko belong hi krta ye class ko belong krta hai!
}

// Static Functions!
// Purpose : Functions that belong to the class rather than any specific object. Can be called using the class name (Example : ClassName::StaticFunction) or through objects.
// Key Points : Independent of Objects : Static functions are primarily for the class, not tied to any particular object.
//            : No this Keyword : this is used to refer to the current object, but since static functions don't work on a specific object, this is not available.
// Access Rules : Can only access static data members of the class.
// Advantages : Used for tasks that are independent of any object instance (Example : utility functions, counters, shared calculations).
//            : Saves memory, as they don’t require object creation to be called.
// Example Use Case : A static function like getGameTime() can return the game timer value, which is shared across all players or entities.
#include<iostream>
using namespace std;

class Hero5 {
    private :
    int age;

    public :
    int health;
    static int timeToComplete;

    static int func() {
        // cout<<this->age<<endl; // this will throw error, kyunki naa toh yahaa this ka koi kaam aur naa hi age ka kyunki vo koi static data member nhi hai!
        // cout<<health<<endl; // Same here also...
        return timeToComplete; // This will work kyunki ye ek static data member hai!
    }

    // Constructor :
    Hero5() {
        cout<<"Constructor Called!"<<endl;
    }

    // Destructor :
    ~Hero5() {
        cout<<"Destructor Called!"<<endl;
    }
};

int Hero5 :: timeToComplete = 5;

int main() {
    cout<<Hero5::timeToComplete<<endl;
    cout<<Hero5::func()<<endl; // Both will print 5
}

// Another Example :
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
} // Without static keyword it won't increament the count becoz a normal data member is valid only till end of the block whereas a static data member will be valid for the entire program.
// Final Crux : Static Variables/Data Members and Static Member Functions are primarly associated with classes! but they can also be used aprt from classes!

// Array of Objects!
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
    // One way to call the functions of the class is to make different objects and call them indivisually. another way is to make an array of object and then apply loop.
    Employee Hawkins_Lab[5];
    for(int i = 0; i < 5; i++) {
        Hawkins_Lab[i].setID();
        Hawkins_Lab[i].getID();
    }
    return 0;
}

// Friend Function : A friend function is a special function that is not a member of a class but has access to the private and protected members of that class. In other words, it can access and modify the private data of a class, which is typically not allowed for regular functions outside the class.
// Key Points : Not in the scope of the class.
//            : Since it is not in the scope of the class, it cannot be called from the object of that class. c1.sum_of_complex() == Invalid
//            : Can be invoked without the help of any object.
//            : Usually contains the objects as arguments.
//            : This friend function can be declared inside private section or in the public section of the class.
//            : It cannot access the members directly by the names and need objects_name.member_name to access any member.

// Example 1 : Simplest one to understand Friend Function!
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

void addValue(X o1, Y o2) { // Here, this addValue was a friend function, that is why it was able to access the dprivate ata members of X & Y. 
    cout<<"Sum of the two values of two classes : "<<(o1.data + o2.data);
}

int main() {
    X a1;
    a1.setValue(5);
    Y b1;
    b1.setValue(5);
    addValue(a1, b1);
}

// Example 2 : Simplest one to understand Friend Function!
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

// Working Examples of Classes and Objects!
// Question 1 : Check if a number is Binary or not!
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
    for (int i = 0; i < s.length(); i++) {
        if (s.at(i) != '0' && s.at(i) != '1') { // Use "at()" to access characters safely
            cout << "Incorrect binary format. Please enter a valid binary number." << endl;
            exit(0); // Exit the program if the binary format is invalid
        }
    }
}

void binary :: ones_compliment() {
    chk_binary(); // If we just call the chk_binary() function inside this function, we don't need to call it in the main() function. and this is called "Nesting of member function" where we called a member function inside another member function.
    for (int i = 0; i < s.length(); i++) {
        if (s.at(i) == '1') {
            s.at(i) = '0';
        }
        else {
            s.at(i) = '1';
        }
    }
}

void binary :: display() {
    cout << "Binary number: " << s << endl;
}

int main() {
    binary b;
    b.read_binary();
    // b.chk_binary(); // Iski need nhi hai kyunki already call hogya hai ones compliment function me!
    b.display(); // If we call this function before one_compliments() function it won't do ones compliment...so we have to call that function after the call of ones_compliment function.
    b.ones_compliment();
    b.display();
    return 0;
}

// Question 2 : Simple and Compound Interest!
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

    bd3.show();
}

// Question 3 : Adding Complex Numbers
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

// ---------------------------------------------------------- LECTURE 43 - OOPS Part 2 --------------------------------------------------------------------------------------------------------->
// OOPS has 4 pillars : Encapsulation, Inheritence, Polymorphism and Data Abstraction!
// Encapsulation : Encapsulation is the concept of bundling or grouping all the data (variables) and functions (methods) that operate on the data into a single unit, which is called a class.
//               : Analogy : Think of a capsule (encapsulation) that stores medicine (data) and you can only take it (access the data) in a controlled manner (through methods/functions). This way, the data is protected and can only be changed in a certain way.
// Key Points : Data and Functions Together : In a class, the data members (variables) and functions (methods) are combined together.
//            : Access Control : You can control how the data is accessed or modified by using access specifiers like private, protected, and public.
//            : Purpose : It protects the data from outside interference and misuse, ensuring data security and integrity.

// Fully Encapsulated Class : A fully encapsulated class is one where all the data members are private, and access to them is only possible through public methods (getters and setters). This ensures complete control over how the data is accessed or modified.
// Note : In short Encapsulation is called Data Hiding, dont confuse it with Data Abstraction as Data Abstraction is Implementation Hiding!

// Advantages : Data Hiding ke kaaran Security badh jaati hai!
//            : If we want we can make our class Read-only vo aise ki hum koi setter naa banaye toh koi bhi usko change nhi kr payega! isliye the class which will be having only getter will be a Read-only class!
//            : Increases Code Reusability
//            : Encasulation helps in unit testing!

// Implementation, What we were doing till now was encapsulation already!
#include<iostream>
#include<cstring> // for strcpy
using namespace std;

class Student{
    private :
    char *Name;
    int age;
    int marks;

    // Student() { // Don't create constructor in private kyunki object creation ke time ye call hota hai toh private hone ke kaaran ye call hi nhi ho payega, isliye isko ya kisi bhi function humesha public rakhna chahiye!
    //     cout<<"Constructor called!";
    //     Name = new char[100];
    // }

    public :
    Student() {
        cout<<"Constructor called!"<<endl;
        Name = new char[100];
    }

    void setterfunc1(char Name[], int age, int marks) {
        cout<<"setter function called"<<endl;
        strcpy(this->Name, Name);
        this->age = age;
        this->marks = marks;
    }

    void getterfunc1() {
        cout<<"getter function called"<<endl;
        cout<<"Name : "<<Name<<" ";
        cout<<"Age : "<<age<<" ";
        cout<<"marks : "<<marks<<" ";
    }
}; // This is a Fully Encapsulated Class!

int main() {
    Student Utkarsh;
    char name[] = "Utkarsh";
    Utkarsh.setterfunc1(name,21,95);
    Utkarsh.getterfunc1();
}

// Inheritance : Inheritance is when one class inherits the properties and behaviors (methods) of another class. It allows a class to reuse code from another class, making it easier to create and maintain.
//             : Extended Functionalities : The child class can also add its own properties or methods or override parent class methods to customize behavior.

// Implementation!
#include<iostream>
using namespace std;

class Human {
    public :
    int height;
    int weight;
    int age;

    void setterFunc1(int height, int weight, int age) {
        this->height = height;
        this->weight = weight;
        this->age = age;
    }

    void getterFunc1() {
        cout<<"Height : "<<height<<endl;
        cout<<"Weight : "<<weight<<endl;
        cout<<"Age : "<<age<<endl;
    }
};

class Male : public Human { // Here this is the syntax to inherit one class from other, [class child_class_name : access_modifiers parent_class_name] jo class inherit krti hai that is child and jahaa se inherit krti hai that is parent!
    public :
    int salary;

    void setterFunc2(int salary) {
        this->salary = salary;
    }
    void getterFunc2() {
        cout<<"Salary : "<<salary<<endl;
    }
};

int main() {
    Human H1; // Is object ke liye toh parent class ke saare data members use honge but ye class child class ke data members access nhi kr payega!
    Male Utkarsh;

    // Manually setting Parent classes attributes for Child class object!
    // Utkarsh.age = 21;
    // Utkarsh.height = 170;
    // Utkarsh.weight = 70;

    // Manually setting Child class attributes for Child class object!
    // Utkarsh.salary = 5000000;

    // Doing the same above thing, using Parent and Child Class's Getter() and Setter()!
    Utkarsh.setterFunc1(170,70,21);
    Utkarsh.setterFunc2(5000000);

    Utkarsh.getterFunc1();
    Utkarsh.getterFunc2();
}
// Note : When a child class (e.g., Male) inherits from a parent class (e.g., Human), the child class automatically gets all the public properties (data members) and methods (functions) of the parent class.
// What Happens : The child class can access the parent class's members (both data and functions).
//              : The child class can also add its own members or modify inherited methods.
// Key Point : The child class can use the parent class's functionality without redefining it, allowing for code reuse.
// Note : Public members are inherited, while private members are not, unless accessed through public functions (getters/setters).

// In the above case, since we used public mode of inheritance and the data members being accessed were also public. Hence, there was no issue.
// But there will be some complications agar base class ke data members ka access modifier private ya protected hua toh...
// so for that remember this table...
// A table for mode of Inheritance and Derivation!
//                     Private Derivation       Public Derivation       Protected Derivation
// Private Member        Not Inherited             Not Inherited           Not Inherited
// Public Member         Private                   Public                  Protected
// Protected Member      Private                   Protected               Protected
// Private data member of any class cannot be inherited!

// Protected Access Modifier : The protected access modifier is like private, meaning the data members are accessible only within the class. However, the difference is that child classes can also access protected members, whereas they cannot access private members.
// Summary : Private : Only accessible inside the class.
//         : Protected : Accessible inside the class and by child/derived classes (through inheritance).
//         : Public : Accessible everywhere.

// Example (Inheritance Mind Puzzle) :
#include<iostream>
using namespace std;

class Base {
    protected:
        int a;
    private:
        int b;
    public:
        int c;
};

class Derived : protected Base {
    // Here, protected inheritance means the protected members of the base class will be inherited as protected.
};

int main() {
    Base d; // Object of the base class
    Derived e; // Object of the derived class

    // Accessing members of base class
    // d.a = 3; // 'a' is protected, cannot be accessed directly.
    // d.b = 3; // 'b' is private, hence not inherited.
    d.c = 3; // Public members of the base class can be accessed directly.

    // Members inherited by derived class
    // e.a = 4; // 'a' is inherited as protected, so it cannot be accessed directly in the derived class.
    // e.b = 5; // 'b' is private, hence not inherited.
    // e.c = 6; // 'c' is inherited as protected in derived class due to protected inheritance, so cannot be accessed directly.

    cout << d.c; // Will print 3, as 'c' is public in base class and accessible here.
    return 0;
}

// Types of Inheritance!
// Simple Inheritance : A single child class inherits from a single parent class.
// Multiple Inheritance : A single child class inherits from multiple parent classes.
// Multi-Level Inheritance : A child class inherits from a parent class, and then another class inherits from that child class (creating a chain).
// Hierarchial Inheritance : Multiple child classes inherit from a single parent class.
// Hybrid Inheritance : A combination of two or more types of inheritance (like multiple and multi-level inheritance together).

// Single Inheritance!
// Example :
#include<iostream>
using namespace std;

class Animal { // Base class!
    public :
    int age;
    int weight;

    void speak() {
        cout<<"Speak!"<<endl;
    }
};

class Dog : public Animal { // Child class inheriting base class Animal!
    public :
    void speakDog() {
        cout<<"Bark!"<<endl;
    }
};

int main() {
    Dog d1;
    d1.speak();
    d1.speakDog();
} // Hence, Single Inheritance!

// Multi-Level Inheritance!
// Example :
#include<iostream>
using namespace std;

class Animal { // Base class!
    public :
    int age;
    int weight;

    void speak() {
        cout<<"Animals can Speak!"<<endl;
    }
};

class Dog : public Animal { // Child class inheriting base class Animal!
    public :
    void speakDog() {
        cout<<"Dogs Bark!"<<endl;
    }
};

class GermanShephard : public Dog {
    public :
    void Color() {
        cout<<"German Shephard has Yellow color with Black stripes!"<<endl;
    }
};

int main() {
    GermanShephard GS1;
    GS1.speak();
    GS1.speakDog();
    GS1.Color();
    // Here we can see the German Shephard class can access all the higher level classes becoz due to inheritance between its higher level class it got functionalities of all the highesr level classes!
}

// Multiple Inheritance!
// Example :
#include<iostream>
using namespace std;

class Animals { // Base class!
    public :
    int age;
    int weight;

    void cantSpeak() {
        cout<<"Animals can't Speak!"<<endl;
    }
};

class Humans { // Base class!
    public :
    int age;
    int weight;

    void speak() {
        cout<<"Humans can Speak!"<<endl;
    }
};

class Mix : public Animals, public Humans {
    // Isme kuch likha nhi zarurat nhi abhi abhi bsss samjhaane vaala kaam chal rha hai! agar koi iska apna function ya data members bnaa denge toh vo bhi Mix ke kisi objects ka banake use kr sakte hai
};

int main() {
    Mix m1;
    m1.speak();
    m1.cantSpeak();
}
// Note : Now thing is yahaa ye sab code likhne me thore error aa rhe hai kabhi kabhi isliye names of variable and function and class change krna pad rha hai kyunki yahaa pr ab bhot saari classes ban gyi hai and sabka scope poore code me hai! toh isliye vo thora understand krna revision ke time!
//      : Uss errors ko handle krne ke liye hi yahaa functions classes and data members ke names change krna pad rha hai!

// Hierarchial Inheritance!
// Example :
#include<iostream>
using namespace std;

class A {
    public :
    void func1() {
        cout<<"Inside Function 1"<<endl;
    }
};

class B : public A {
    public :
    void func2() {
        cout<<"Inside Function 2"<<endl;
    }
};

class C : public A {
    public :
    void func3() {
        cout<<"Inside Function 3"<<endl;
    }
};

int main() {
    A obj1;
    obj1.func1(); // Calling its own function

    cout<<endl;

    B obj2;
    obj2.func1(); // Calling base class function
    obj2.func2(); // Calling its own function

    cout<<endl;

    C obj3;
    obj3.func1(); // Calling base class function
    // obj3.func2(); // Ye possible nhi ho payega kyunki B and C me koi relation nhi hai!
    obj3.func3(); // Calling its own function
}

// Hybrid Inheritance!
// Example :
#include<iostream>
using namespace std;

class D { // Base class, which is doing hierarchial inheritance
    public :
    void funcD() {
        cout<<"Inside D class!"<<endl;
    }
};

class E { // Base class
    public :
    void funcE() {
        cout<<"Inside E class!"<<endl;
    }
};

class F : public D { // Class F doing Single Inheritance of class D
    public :
    void funcF() {
        cout<<"Inside F class!"<<endl;
    }
};

class G : public D, public E { // Class G multiple inheritance of class D and F
    public :
    void funcG() {
        cout<<"Inside G class!"<<endl;
    }
};

int main() {
    D d1;
    d1.funcD();

    cout<<endl;

    E e1;
    e1.funcE();

    cout<<endl;

    F f1;
    f1.funcD();
    f1.funcF();

    cout<<endl;

    G g1;
    g1.funcD();
    g1.funcE();
    g1.funcG();
} // So here we can see there are different types of inheritance are perfoming at once, so it is called Hybrid Inheritance!

// Inheritance Ambiguity : When a child class inherits from two parent classes and both parent classes have a member function or data member with the same name, the compiler gets confused about which one to use when the child class tries to access it.
// To resolve this confusion, we use the :: (scope resolution operator) to specify which parent class's function or data member the child should use
// Example :
#include<iostream>
using namespace std;

class H { // Base class
    public :
    void func() {
        cout<<"Inside H class!"<<endl;
    }
};

class I { // Base class
    public :
    void func() {
        cout<<"Inside I class!"<<endl;
    }
};

class J : public H, public I {
    public :
    void func() {
        cout<<"Inside J class!"<<endl;
    }
};

int main() {
    J j1;
    j1.func(); // This is ambigous or can say it is confusing ki kiske func() function ki baat ho rhi hai!.. so we need to use scope resolution operator!
    j1.H::func();
    j1.I::func();
    j1.J::func();
    j1.func(); // Agar sirf ye likhoge toh J class ka func() vaala function call hojayega, this is method over riding which we are about to study in runtime polymorphism!
} // Ambiguity Resolved using scope resolution operator!

// The OOPS concepts we study at a basic level are just the foundational principles. While these concepts (like classes, objects, inheritance, encapsulation, etc.) are the building blocks, the way OOP is applied in the industry can be much more complex and sophisticated.
// While basic OOP gives you the necessary understanding, industry-level OOP is much more complex, structured, and focuses on scalability, maintainability, and efficiency. It involves not just syntax but a deeper understanding of architecture and system design principles.

// Case Study 1 :
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
// Code Understanding (Important Concept Clarity)!
// Base class "Employee", has two attributes id, salary and one Parameterized constructor! and a Default constructor!
// Derived class "Programmer", has one attribute languageCode and one Parameterized constructor! and one class method getdata().
// Derived class privately inherits the Base class! Hence, all the base class public attributes and methods become private attributes and methods for the derived class!
// Lets now discuss how constructors participate in Inheritance, After all, its all about how a derived class inherits base class and its attributes, methods and constructors! We have already discussed about attributes and methods.
// How constructors participate in Inheritance, Constructors do not get inherited in C++ when a derived class is created from a base class. However, the base class constructors can be called within the derived class, either explicitly or implicitly.
// Why constructors do not get inherit : Constructors are special member functions that are used to initialize objects. Since the derived class might need to initialize its own specific members (which are not in the base class), the derived class must have its own constructor. The base class constructor is not inherited, but the derived class can still use it to initialize the base class part of the object.
// In Inheritance, there should always be a base class default constructor! Because, during the derived class object initialisation, base class default constructor needs to be called to initialise the base class part of the derived class objects!
// For inheritance to work smoothly, if the base class has only a parameterized constructor and no default constructor, the derived class must explicitly call the base class's constructor in the initializer list.
// If the base class has a default constructor, it is automatically called when a derived class object is created, unless the derived class explicitly calls another constructor of the base class.

// Example 1 (Simple Public Inheritance Example) :
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

void Base :: setdata() { // Here we defined the setdata function of the base class! ye default set kr rhe hai data1 and 2 ko!
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

// Example 2 (Simple Private Inheritance Example) :
#include<iostream>
using namespace std;

class Base {
    int data1;
    public :
        int data2;
        void setdata();
        int getdata1();
        int getdata2();
};

void Base :: setdata(void) {
    data1 = 10;
    data2 = 20;
}

int Base :: getdata1() {
    return data1;
}

int Base :: getdata2() {
    return data2;
}

class Derived : private Base {
    int data3;
    public :
        void process();
        void display();

};

void Derived :: process() {
    setdata(); // We added the setdata function here as the process is the member function of the Derived class and hence it can internally access the private data member! 
    data3 = data2*getdata1();
}

void Derived :: display() {
    cout<<"Value of data 1 is : "<<getdata1()<<endl;
    cout<<"Value of data 2 is : "<<data2<<endl; // Here, we can also use getdata2();
    cout<<"Value of data 3 is : "<<data3<<endl;
}

int main() {
    Derived der;
    // der.setdata(); // Here becoz setData() is inherited privately, hence it becomes private data member of the derived class as well now, hence cannot be accessed by objects! But to use it, as process() is a public method of derived class, and as methods or attributes inside a class has accessed to its private data members, so we have included the setData() method inside the Derived class! Same we have done in display() method calling getdata2().
    der.process();
    der.display();
    return 0;
}

// Ambiguity Resolution in Inheritance!
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

class Derived : public Base1, public Base2  {
    int a;
    public :
    void greet() {
        Base1 :: greet(); // this is the statement we are using here to resolve ambiguity!
    }
    // void greet() { // Isme koi ambiguity nhi ayegi!
    //     cout<<"Whats upp??"<<endl;
    // }
}

int main() {
    Base1 Base1obj;
    Base2 Base2obj;
    Base1obj.greet();
    Base2obj.greet();
    
    Derived DerivedObj1;
    DerivedObj1.greet(); // After solving the ambiguity, it will call the greet function of the Base1 class! hence Ambiguity Resolved!
    return 0;
}

// Example : Here this is no Ambiguity!
#include<iostream>
using namespace std;

class Base {
    public :
    void greet() {
        cout<<"Hello World"<<endl; // Greet function of the base class!
    }
};

class Derived : public Base {
    public :
    void greet() {
        cout<<"Learning OOPS in C++"<<endl; // Greet function of derived class!
    }
};

int main() {
    Derived Obj1;
    Obj1.greet(); // Which greet() method will be called will depend on the object which is calling it!
    return 0;
}

// Virtual Base Class!
// Concept : In a scenario where you have a base class A with a variable a, and it is inherited by two derived classes B and C, both B and C will have their own copies of a. Now, if both B and C are inherited into another class D, the variable a will be inherited twice—once from B and once from C. This results in ambiguity, as the compiler wouldn't know which copy of a to use.
//         : To solve this issue, you can declare A as a virtual base class. This ensures that a is inherited only once, even though B and C inherit from A. This way, D will only have a single instance of a.
#include<iostream>
using namespace std;

class Student {
    protected :
    int roll_number; // Protected Data Attribute!
    public :
    void set_roll_number(int a) {
        roll_number = a;
    }
    void print_roll_number() {
        cout<<"Roll number of the candidate is : "<<roll_number<<endl;
    }
};

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
}; // In virtual inheritance, the class that is going to be inherited by multiple classes should be declared as a virtual base class. This ensures that the members and functions from that base class are inherited only once, even if multiple intermediate derived classes inherit from it.

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
};

int main() {
    Result Utkarsh;
    Utkarsh.set_roll_number(65);
    Utkarsh.set_marks(95.7, 96.5);
    Utkarsh.set_score(9);
    Utkarsh.display();
    return 0;
}

// Constructors in Derived Class!
// In the case of multiple inheritance, when an object of the derived class is created, the constructor of the base classes is called first, followed by the constructor of the derived class.
// The order of constructor calls follows the order of inheritance :
// Base class constructors are called first, starting with the one that appears first in the inheritance list.
// After the base class constructors, the constructor of the derived class is called.
// For example, in a scenario where classes A, B, and C have been inherited in a multiple inheritance pattern (A -> B -> C), the constructors will be called in the order: A's constructor, B's constructor, then C's constructor.
// This is different from method calls, where the method of the class where the object is created will be executed. The constructor, however, is responsible for creating the object and initializing the class, and the base class constructors are always called before the derived class constructor.

// Constructors Behaviour : Default Constructor : When all classes in the inheritance chain have default constructors, the constructors are called in the order of inheritance. For example, in a scenario of A -> B -> C, the constructors are called in the order: A(), then B(), and then C().
//                        : Parameterized Constructor : If a base class has a parameterized constructor, then the derived class must pass the appropriate arguments to the base class constructor.
//                                                    : The derived class constructor will pass arguments to the base class constructor in the following format : Derived-Constructor(arg1, arg2, ...) : Base-Constructor(arg1, arg2, ...) {
//                                                                                                                                                                  Derived class constructor body
//                                                                                                                                                                }
//                        : Special Case of Virtual Base Class : If a class has a virtual base class, its constructor is called before any non-virtual base class constructors. And if there are multiple virtual base classes, their constructors are invoked in the order in which they are declared.
//                                                             : Non-virtual base class constructors are executed after the virtual base class constructor and before the derived class constructor.

// Example :
// Case 1 (Regular inheritance) : class B : public A {
//                                      // Constructor order: A() -> B()
//                                }

// Case 2 (Multiple Inheritance) : class A : public B, public C {
//                                      // Constructor order: B() -> C() -> A()
//                                 }

// Case 3 (Virtual base class) : class A : public B, virtual public C {
//                                      // Constructor order: C() -> B() -> A() (since C is a virtual base class)
//                               }

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
// Example to use intiallization Section or intiallization list!
class Base {
    int a;
    int b;
    public :
    // Some variation in intiallization section :
    // Base(int i, int j) : a(i), b(i+j) -> This will work, and the output will be a = 6 and b = 10
    // Base(int i, int j) : a(i), b(2 * j) -> This will work, and the output will be a = 6 and b = 8
    // Base(int i, int j) : a(i), b(2 * a) -> This will work, and the output will be a = 6 and b = 12
    // Base(int i, int j) : b(i), b(j) -> This won't work, as becoz in class, a is declared first and then b, so a should be initiallise first then b!
    Base(int i, int j) : a(i), b(j) { // Here in this line, humne a and b ko constructor ki body me initiallize krne ke bajaye, constructor ke saath saath initiallization section me hi initiallize krdiya!
        cout<<"Constructor is executed"<<endl;
        cout<<"Value of a is : "<<a<<endl;
        cout<<"Value of b is : "<<b<<endl;
    }
};

int main() {
    Base B(6,4);
    return 0;
}

// Example 2 :
#include <iostream>
using namespace std;

class Example {
    const int a; // const member
    int& b; // reference member
    int x;
    int y;
public:
    // Constructor with initialization list
    Example(int i, int j, int& ref) : a(i), b(ref), x(i+j), y(x*2) { // Either we can assign separate values to each attribute inside the constructor's body! or we can just create this list!
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

// Example 3 :
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
}; // Here we have declared one base class and added its constructor which takes a data i and the it has a print method!

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
}; // Here we have declared another base class and added its constructor which takes a data i and the it has a print method!

class Derived : public Base1, public Base2 {
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
};

int main() {
    Derived Utkarsh(1, 2, 3, 4);
    Utkarsh.PrintData1();
    Utkarsh.PrintData2();
    Utkarsh.PrintDataDerived();
    return 0;
}

// Polymorphism!
// Formal Definition : Polymorphism means "many forms". It is when one thing can take multiple forms based on the context.
//                   : When one particular thing can have mutltiple forms! like a father can be a father for you but can also be son for his father, a husband for your mom, a brother for his sister and in a similar way in programming, one function or object can behave differently based on the situation.!
//                   : There are two type of Polymorphism : Compile-Time Polymorphism and Runtime Polymorphism!

// Compile Time Polymorphism : In compile-time polymorphism, the decision about which function or operator to call is made during compilation based on the types of arguments or operands.
//                           : Achieved Through : Function Overloading : Same function name but different parameters.
//                                              : Operator Overloading : Changing how operators work for user-defined data types.
//                           : The method or function call is resolved by the compiler before the program runs, which is why it's also called static polymorphism.

// Compile Time Polymorphism using Function Overloading!
// Example :
#include<iostream>
using namespace std;

class K {
    public :
    void sayHello() {
        cout<<"Hello Utkarsh"<<endl;
    }

    void sayHello(string name) {
        cout<<"Hello "<<name<<endl;
    }

    void sayHello(string name, int age) {
        cout<<"Hello "<<name<<" Your age is "<<age<<endl;
    }

    void SayHello(string name, int age, int height = 0, int weight = 0) { // Isme kya hoga ki iss function ko agar hume access krna hai toh object bnaa ke chaahe 2 arguments pass kro ya chahe 3 yaa chahe 4, teeno hi case me work krega kyunki yahaa humne default arguments use kiye hai!
        cout<<"Hello "<<name<<" Your age is "<<age<<" your height is "<<height<<" your weight is "<<weight<<endl;
    }

    // int sayHello(string name, int age) { // This will show error kyunki yahaa bhi function ko overload toh krne ki koshish kr rhe hai but vo sirf return type change krke and this is not valid, agar function overload krna hai toh vo sirf number of input arguments ya type of arguments ko change krke hi ho sakta hai!
    //     cout<<"Hello "<<name<<" Your age is "<<age<<endl;
    //     return 1;
    // }
}; // So saare functions ka name same hai bss arguments ka number ya type different hai and this is how function overloading works!

int main() {
    K k1;
    k1.sayHello();
    k1.sayHello("Palak");
    k1.sayHello("Kinshuk", 22);
    k1.sayHello("Paresh",21); // height and weight nhi daala fir bhi work krega! this is becoz of default arguments!
} // So this is Function overloading in compile time polymorphism, ki yahaa ek hi function ke multiple forms exists! and compile time me hi decide ho rha hai arguments ka type and number dekh ke hi decide ho rha hai ki konsa function call hona hai!

// Compile Time Polymorphism using Operator Overloading!
// Example :
#include<iostream>
using namespace std;

class L {
    public :
    int a;

    void operator+ (L &obj) {
        int value1 = this->a;
        int value2 = obj.a;
        cout<<"Output : "<<value2 - value1<<endl;
    }

    void operator() () {
        cout<<"Inside the bracket function! "<<this->a<<endl; // Overloaded "()", so that the object which calls it, due to overloading, it will print the "a" value of that object! 
    }
}; // To demonstrate operator overloading, we are making "+" operator to do "-" (subtraction)!

int main() {
    L obj1, obj2;
    obj1.a = 5;
    obj2.a = 12;

    obj1 + obj2;
    // + is a binary operator hai toh uske liye ye matter krta hai ki right left me konsa operand hai, toh humne yahaa obj1 ko left operand bnaa diya and obj2 ko right... now ab jo + ke case me jo operand right me hota hai vo as a input pass hota hai operator overloading me and jo left me hota hai vo current object hota hai, mtlb ki uss object ke liye humari function call hui hoti hai!
    // means jab obj1 + obj2 likha humne, toh ye hua ki obj1 ne function call ki toh is kaaran se value1 me this->a jo likha hai vo usme obj1 ki value store ho rhi hai becoz we have used "this" and this points to the current object and current object is obj1 kyunki vo left me likha hua hai!... and value2 me jo obj.a likha hua vo obj2 ki baat ho rhi hai kyunki vo right me likha tha and isliye vo as paramter pass hua tha function call me! isliye value2 me obj2 ki value gyi!
    // Toh ab jab bhi + operator call hoga tab uske right and left operands ko dekh ke function call hoga and uske hisaab se - hojayega! 

    obj1(); // Obj1 ne call kiya bracket ko toh output me Inside the bracket function! print hoga and saath saath obj1 ki a value print hojayegi which is 5!
}

// Note : There are some operators which cannot be overloaded! and they are... "::", "*", ".", "?:"

// Runtime Polymorphism : It allows a function to behave differently based on the type of object it is working with, even when the function is called in the same way.
//                      : The decision about which function to call is made during runtime (when the program is running), based on the actual object type.
//                      : It is done through Function/Method overriding (using inheritance) and virtual functions.

// Function Overriding : When a child class defines a function with the same name and same parameters as a function in the parent class, this is called method overriding.
//                     : The child class provides its own implementation of the function, which replaces the parent class’s version.
// Rules : Same function name in both parent and child classes. Same number of parameters in both functions. Possible only through inheritance (parent-child relationship).
// Example : If class A has func() printing "Hello" and class B (which inherits from A) has func() printing "Hi", this is overriding the function from class A in class B.
#include<iostream>
using namespace std;

class M {
    public :
    void display() {
        cout<<"Inside M class"<<endl;
    }
};

class N : public M {
    public :
    void display() { // Here you have done method overiding... agar tum ye function nhi banate toh M vaala hi display function call hojaata kyunki N ne M ko inherit kr rakha hai, pr kyunki humne iss class ke liye N ki khud ki implementation daal di hai display() ki isliye agar N ka object bnaa ke function call krenge toh "Inside N class" print hoga...
        cout<<"Inside N class"<<endl;
    }
};

int main() {
    N obj1;
    obj1.display(); // Here it will print N class's implementation of display()... but if you want to specify ki which display function you want to call then in that case you use scope resolution operator!
    obj1.M::display(); // It will print according to the implementation of display function of M class!
}
// Usage : If a base class has 10 methods, and a subclass needs to use 8 methods as they are but wants to implement its own version for 2 methods, we use method overriding.
//       : This allows the subclass to override only the required methods while inheriting others from the base class without changes.

// Example : Demonstrating Runtime Polymorphism using Base and Derived class pointers!
#include<iostream>
using namespace std;

class Base { // Base class definition - this is our parent class
    public:
    int var_base; // Base class member variable
    
    void display() { // Base class display function, When called through base class pointer, this version will execute
        cout<<"Displaying Base class variable var_base : "<<var_base<<endl;
    }
};

class Derived : public Base { // Derived class inherits publicly from Base class, This means Derived gets everything public from Base
    public:
    int var_derived; // Additional member specific to Derived class
    
    void display() { // Derived class overrides base class display function, This version will execute when called through Derived class pointer
        cout<<"Displaying Base class variable var_base : "<<var_base<<endl; // Can access var_base because it's inherited from Base
        cout<<"Displaying Derived class variable var_derived : "<<var_derived<<endl;
    }
};

int main() {
    // Create objects of both classes
    Base Obj_base; // Creates a Base class object in memory
    Derived Obj_derived; // Creates a Derived class object (includes Base class part)

    Base* base_class_pointer; // Create a Base class pointer
    
    base_class_pointer = &Obj_derived; // IMPORTANT: Pointing base class pointer to derived class object!
    // This is allowed because Derived "is-a" Base (inheritance relationship)
    
    base_class_pointer->var_base = 34; // Set value using base class pointer, Can only access Base class members through base_class_pointer
    
    base_class_pointer->display(); // Calls Base class display even though pointing to Derived object, This is because pointer type (Base*) determines which function to call
    
    // base_class_pointer->var_derived = 100;  // Would cause compilation error, because cannot access derived class members through base class pointer
    
    Derived* derived_class_pointer; // Create a Derived class pointer
    
    derived_class_pointer = &Obj_derived; // Point it to Derived class object, This gives full access to both Base and Derived members
    
    // Can set both Base and Derived class variables
    derived_class_pointer->var_derived = 400; // Setting Derived class variable
    derived_class_pointer->var_base = 300; // Setting inherited Base class variable
    
    derived_class_pointer->display(); // Calls Derived class display, Shows both variables because Derived's display shows both!
    
    // derived_class_pointer = &Obj_base;  // Would cause compilation error, because cannot point Derived pointer to Base object and this is because Base doesn't have all members that Derived has
    
    // Memory safety best practice:
    // Always initialize pointers if not immediately assigning
    Derived* safe_pointer = nullptr; // Good practice
    return 0;
}
// Final Crux : The main point is about how the SAME function name (display) behaves DIFFERENTLY based on what type of pointer is calling it, and this decision happens during runtime (when program is running).
// How This Shows Runtime Polymorphism!
// Same Function, Different Behaviors : Both classes have a display() function.
//                                    : Same function name behaves differently depending on who's calling it
//                                    : Just like a "speak" command would make a dog bark and a cat meow
// Runtime Decision Making : The decision of which display() to call isn't made during compilation
//                         : It's made while the program is running. Like having a TV remote (pointer) that adapts its behavior based on which TV (object) it's controlling
// The Big Picture : It's like having a universal interface (Base pointer), That can work with different specific implementations (Derived objects), But maintains type safety and proper behavior, All while making decisions on-the-fly during program execution.

// Virtual Functions : Virtual functions are functions that are declared in a base class and are intended to be overridden in a derived class. These functions are used to achieve runtime polymorphism in C++.
//                   : A virtual function is declared using the virtual keyword in the base class, and it allows the derived class to provide its specific implementation of the function.
//                   : Without virtual functions, the function call is resolved at compile-time based on the type of the pointer/reference.
//                   : With virtual functions, the function call is resolved at runtime based on the actual object type being pointed to by the pointer/reference.
// Example (Using above example only) :
#include<iostream>
using namespace std;

class Base {
public:
    int var_base;  // Base class variable
    
    virtual void display() { // Display function in the base class (not virtual initially)
        cout << "1 Displaying Base class variable var_base: " << var_base << endl;
    }
};

class Derived : public Base {
public:
    int var_derived;  // Derived class variable
    
    void display() override { // Override display function in derived class, we don't need to use 'override' keyword to override a base class method, but it is considered good practice if you do it! as it makes you aware with errors if there's any potectial mistakes!
        cout << "2 Displaying Base class variable var_base: " << var_base << endl;  // Accessing the base class variable
        cout << "2 Displaying Derived class variable var_derived: " << var_derived << endl;  // Accessing the derived class variable
    }
};

int main() {
    // Creating pointers and objects of Base and Derived classes
    Base* base_class_pointer; // Pointer of Base class type
    Base Obj_base; // Base class object
    Derived Obj_derived; // Derived class object
    
    base_class_pointer = &Obj_derived; // Base class pointer pointing to derived class object

    base_class_pointer->var_base = 30; // Assigning a value to the base class variable through the base class pointer

    // Calling the display function via the base class pointer
    base_class_pointer->display(); // At this point, the virtual function mechanism kicks in
    return 0;

    // Explanation : Initially, if we don't declare the display function as virtual in the base class, the compiler would call the base class version of display(), even when we use a base class pointer (`base_class_pointer`) pointing to a derived class object. This is known as static (compile-time) binding.
    //             : However, since we've declared `display()` as a virtual function in the base class, the dynamic (runtime) binding takes place. This means that even though `base_class_pointer` is a pointer of type `Base`, the function corresponding to the actual object type (which is `Derived`) is called.
    //             : This is an example of runtime polymorphism where the function that gets called is determined at runtime based on the type of object that the pointer is actually pointing to. When we assign the `base_class_pointer` to point to `Obj_derived`, the `display()` function of the `Derived` class is invoked, even though the pointer is of type `Base`.
    //             : Important Note : Since `base_class_pointer` is pointing to a `Base` class object and we can't directly access `var_derived` (a member of `Derived` class) through it, `var_derived` will not be initialized, so it will contain a **garbage value** when printed. The main purpose here was to show that the correct `display()` function (from `Derived`) is called despite using a base class pointer, which is only possible because of the virtual function mechanism.
    //             : The binding (i.e., which `display()` function to call) happens at runtime, not at compile-time, due to the use of the `virtual` keyword. The program demonstrates how virtual functions enable **polymorphism** (dynamic binding), allowing derived class functions to be called using base class pointers or reference.
}
// Final Note : The whole point was one is to demonstrate the runtime polymorphism, how it depends on the type of pointer we are using to accessing the methods of base and derived class!
//            : Concept : We used Virtual function, coz what happened is, in the first example, when we used the base class pointer and pointed it at the derived class object! then using base class pointer to access the display() method, it is calling base class version of display() method! but if you think, at the very basic level, pointer is a special variable which is storing the address of another variable!
//                      : And here we were doing the same thing! we were using Base class pointer to point at the derived class object! (Base* base_class_pointer = &obj_derived) and on dereferencing it (base_class_pointer->display()) it is calling the base class version of display() method, which if you think is wrong! so thats why we made display() method of base class virtual!
//            : With using Virtual : Now, when you use base_class_pointer->display(), the program will check the actual object type (Derived in this case) and call the Derived class version of the display() method, because it knows that the pointer is pointing to a Derived object.

// Example 4 :
#include<iostream>
#include<cstring>
using namespace std;

// The protected access modifier allows a class’s members (variables and methods) to be accessible within the class itself, by derived classes (subclasses), but not by objects of the class or outside the class.
// It's often used when you want to allow derived classes to access and modify the members of the base class, but you want to restrict direct access to those members from outside the class.
// How its different from Private Access Modifier : Members declared as private are only accessible within the class where they are declared. They are not accessible from any derived classes or from outside the class, even if the class is inherited.
//                                                : private is used to completely hide members from other classes and derived classes. It ensures that data is protected from modification or direct access by any code outside the class.
class CWH {
    protected:
        string title;
        float rating;
    public:
        CWH (string s, float r) {
            title = s;
            rating = r;
        }
        virtual void display() {} // Base class display function is declared virtual
};

class CWHVideo : public CWH {
    float VideoLength;
    public:
        CWHVideo (string s, float r, float vl) : CWH(s, r) {
            VideoLength = vl;
        }
        void display() {  // Derived class display function
            cout<<"This is an amazing video with title : "<<title<<endl;
            cout<<"ratings : "<<rating<<" out of 5 stars!"<<endl;
            cout<<"Length of this video is : "<<VideoLength<<" Minutes!"<<endl;
        }
};

class CWHText : public CWH {
    float words;
    public :
        CWHText (string s, float r, int wc) : CWH(s, r) {
            words = wc;
        }
        void display() { // Derived class display function
            cout<<"This is an amazing text tutorial with title : "<<title<<endl;
            cout<<"ratings : "<<rating<<" out of 5 stars!"<<endl;
            cout<<"Words count of the text is : "<<words<<" Words!"<<endl;
        }
};

int main() {
    string title;
    float rating, vlen;
    int words;

    // Creating a CWHVideo object
    title = "C++ Video tutorial!";
    vlen = 4.56;
    rating = 4.45;
    CWHVideo Cvdo(title, rating, vlen); // Object creation with values set through constructor

    // Creating a CWHText object
    title = "C++ Video tutorial text!";
    words = 433;
    rating = 4.15;
    CWHText Ctext(title, rating, words); // Object creation with values set through constructor
    
    // Now, we are demonstrating runtime polymorphism using base class pointers!
    CWH* CWH_pointer[2]; // Declaring an array of pointers to the base class (CWH)
    CWH_pointer[0] = &Cvdo;  // Pointing base class pointer to CWHVideo object
    CWH_pointer[1] = &Ctext; // Pointing base class pointer to CWHText object

    // Calling display() function through base class pointers to invoke derived class functions
    CWH_pointer[0]->display(); // Calls the display function of CWHVideo
    CWH_pointer[1]->display(); // Calls the display function of CWHText

    // Here, we're achieving runtime polymorphism by calling the correct derived class function based on the object type the pointer is pointing to.
    // Because the display function is virtual, it will dynamically call the respective derived class function, even though we're using a base class pointer.

    // Without the virtual keyword, the display function of the base class would have been called, which doesn't display any information.
    // If you remove the display function from one of the derived classes, the corresponding pointer would call the base class's display function.
    // If base class display function had some output, it would be printed for the missing derived class function.
}

// Abstract Base Class & Pure Virtual Functions!
// Explaination : The code demonstrates the concept of Abstract Base Classes (ABCs) and Pure Virtual Functions in C++. It shows how we can create a base class with a pure virtual function and how this ensures that derived classes must implement their own versions of that function.
// Key Concepts : Abstract Base Class : An abstract base class is a class that contains at least one pure virtual function.
//                                    : A pure virtual function is a function declared in the base class but has no implementation (it's set to = 0). This enforces that the derived class must provide its own implementation of the function.
//                                    : An abstract base class cannot be instantiated directly. It can only serve as a blueprint for derived classes.
//              : Virtual Function : A virtual function is a function in a base class that can be overridden in a derived class. If a derived class does not override it, the base class's implementation is used.
//              : Pure Virtual Function : A pure virtual function is a function that is declared in the base class with = 0. It doesn't have any implementation in the base class and forces the derived class to provide an implementation.
// Example :
#include<iostream>
#include<cstring>
using namespace std;

class CWH {
    protected:
        string title; // Title of the content (either video or text)
        float rating; // Rating for the content
    public:
        CWH(string s, float r) { // Constructor to initialize title and rating
            title = s;
            rating = r;
        }
        
        virtual void display() = 0; // Pure virtual function : No implementation here in the base class.
};

class CWHVideo : public CWH {
    float VideoLength; // Video length in minutes
    public:
        CWHVideo(string s, float r, float vl) : CWH(s, r) { // Constructor to initialize title, rating, and video length
            VideoLength = vl;
        }

        void display() { // Override the pure virtual function in derived class
            cout << "This is an amazing video with title: " << title << endl;
            cout << "Ratings: " << rating << " out of 5 stars!" << endl;
            cout << "Length of this video is: " << VideoLength << " minutes!" << endl;
        }
};

class CWHText : public CWH {
    float words; // Number of words in the text tutorial
    public:
        CWHText(string s, float r, int wc) : CWH(s, r) { // Constructor to initialize title, rating, and word count
            words = wc;
        }

        void display() { // Override the pure virtual function in derived class
            cout << "This is an amazing text tutorial with title: " << title << endl;
            cout << "Ratings: " << rating << " out of 5 stars!" << endl;
            cout << "Words count of the text is: " << words << " words!" << endl;
        }
};

int main() {
    string title;
    float rating, vlen;
    int words;

    // Creating object for Video
    title = "C++ Video tutorial!";
    vlen = 4.56; // Video length in minutes
    rating = 4.45; // Video rating
    CWHVideo Cvdo(title, rating, vlen);

    // Creating object for Text
    title = "C++ Video tutorial text!";
    words = 433; // Number of words in the text
    rating = 4.15; // Text rating
    CWHText Ctext(title, rating, words);

    // Creating array of pointers to Base class (CWH)
    CWH* CWH_pointer[2];  
    CWH_pointer[0] = &Cvdo;  // Pointing to Video
    CWH_pointer[1] = &Ctext; // Pointing to Text

    // Calling display() function through base class pointer
    CWH_pointer[0]->display();  // Calls the display function of CWHVideo
    CWH_pointer[1]->display();  // Calls the display function of CWHText
}

// Data Abstraction!
// Purpose : Data abstraction is the concept of hiding unnecessary details from the user and showing only the essential information. In simple words, it's like giving a "brief view" of the object or data, and hiding the complexity.
//         : It is also called Implementation Hiding because you hide the internal workings of an object (like its data and methods) and only provide access to what’s needed.
// Key Points : What is Hidden : You hide the implementation details (e.g., internal data and how it works) and expose only the important functionality or data that is necessary for the user to interact with.
//            : How is it Achieved : Access Modifiers like private, protected, and public are used to control which parts of the class are accessible to the outside world.
//                                 : Private : Hides data members and methods so they cannot be accessed directly from outside the class.
//                                 : Protected : Allows derived classes to access certain members while keeping them hidden from other parts of the program.
//                                 : Public : Exposes only the necessary parts that users can interact with.
// Advantages of Data Abstraction : Security, Simplification, Reduced Complexity, Encapsulation, Reusability, Maintaining and Updating!
//                                : Error Prevention : By hiding internal data and providing controlled access (through functions), you reduce the risk of unwanted changes or incorrect usage, as users can't directly modify the internal state of the object.

// Why Classes over Structures?
// Lack of Encapsulation : Structures are primarily designed to store data, not behavior. They don’t combine data (attributes) and functionality (methods) in one place as effectively as classes do.
//                       : In a structure, you can’t define methods to operate on the data easily in some languages (like C). You’ll need to write separate functions, which are harder to manage and not tied to the data they work on.

// No Access Control : In structures, everything is typically public by default (e.g., in C or C++). Structures can have private, public, and protected members just like classes. This means you can technically achieve access control in structures too.
//                   : But still, the default access modifier is Public, and if you forget to explicitly specify private, your structure’s members will remain public. This can lead to unintentional exposure of data. Classes are safer by default, as you need to explicitly make members public.

// No Inheritance : Structures generally do not support inheritance, which is a core feature of object-oriented programming (OOP).
//                : Without inheritance, you can’t reuse code efficiently or create relationships between objects, leading to duplication.

// No Polymorphism : Structures don’t support features like polymorphism (e.g., virtual functions in C++). This makes it impossible to write flexible and dynamic code where the same method can behave differently in different contexts.
//                 : Polymorphism is critical for building scalable and maintainable applications. Without it, your code becomes rigid and harder to extend.

// No Constructors and Destructors : Structures don’t support constructors and destructors (in some languages like C), which are essential for object lifecycle management.
//                                 : You’ll need to write manual initialization and cleanup code, which increases the chance of bugs and makes your code less efficient.

// Limited Dynamic Features : Structures lack support for advanced OOP features like dynamic memory allocation and virtual functions (e.g., in C++). Classes are more flexible and powerful when working with complex scenarios.
//                          : Without these features, you can’t handle dynamic or real-world problems efficiently.

// Not Suited for Modern Programming : Structures were designed for procedural programming (e.g., C). They don’t align well with modern object-oriented programming principles, which focus on modularity, abstraction, and reusability.
//                                   : You miss out on modern best practices and features that make coding more efficient and scalable.

// Some miscellaneous examples (CWH) :
// Example 1 : Pointers to objects and arrows in CPP!
#include<iostream>
using namespace std;

class Complex {
    int real, imaginary;
    public :
    void setdata(int a, int b) {
        real = a;
        imaginary = b;
    }

    void getdata() {
        cout<<"The value of the real part is : "<<real<<endl;
        cout<<"The value of the imaginary part is : "<<imaginary<<endl;
    }
};

int main() {
    // Creating objects normally (Stack allocation)
    Complex c1;
    c1.setdata(1,5);
    c1.getdata();
    
    // In the above code, we used the standard way to create objects and call member functions of the class.
    // Now, let's use pointers to call member functions of the class using the arrow operator.

    // Statically creating objects using pointers (Stack allocation with pointers)
    Complex* ptr = &c1; // Storing the address of the object 'c1' in the pointer 'ptr'. Now, we can access and modify the object 'c1' using the pointer 'ptr' and the dereferencing (*) operator.
    (*ptr).setdata(1,5);
    (*ptr).getdata(); // Accessing and calling the setdata/getdata method using the dereference operator

    // Dynamically creating objects using the new operator (Heap allocation)
    Complex* ptr2 = new Complex; // The pointer 'ptr2' will hold the address of the dynamically allocated Complex object.
    (*ptr2).setdata(1,5);
    (*ptr2).getdata(); // Accessing and calling the setdata/getdata method using dereference operator on dynamically created object

    // Accessing methods using the Arrow (->) Operator (Pointer to object)
    Complex c2; // Creating an object of Complex class statically (on the stack)
    Complex* ptr3 = &c2; // Pointer 'ptr3' stores the address of object 'c2'

    // The arrow operator (->) is used to access member functions when dealing with pointers.
    ptr3->setdata(1,5); // Setting the values of real and imaginary parts using the arrow operator.
    ptr3->getdata(); // Displaying the real and imaginary parts using the arrow operator.
    return 0;
}
// Summary : Objects can be created statically (on the stack) or dynamically (on the heap).
//         : The arrow operator (->) is used when dealing with pointers to objects. 
//         : The dereference operator (*) can be used to access members of the object when using a pointer to the object.

// Example 2 : Array of objects using pointers!
#include<iostream>
using namespace std;

class ShopItem {
    int id;
    float price;
    public :
    void setData(int a, float b) {
        id = a;
        price = b;
    }
    void getData() {
        cout << "Id of the item is: " << id << endl;
        cout << "Price of the item is: " << price << endl;
    }
};

int main() {
    int size = 3; // Define the size of the array
    // Dynamically create an array of ShopItem objects
    ShopItem* ptr = new ShopItem[size];
    int p;
    float q;

    // Create a temporary pointer to hold the base address of the dynamically created array
    ShopItem* ptrTemp = ptr;

    // Loop to input data (id and price) for each ShopItem object
    for (int i = 0; i < size; i++) {
        cout << "Enter the id and price of the item purchased: " << i + 1 << endl; 
        // 'i+1' is used to display item numbering starting from 1 (not 0)
        cin >> p >> q;
        ptr->setData(p, q); // Set the data for the current item
        ptr++; // Move the pointer to the next object in the array
    }

    // Loop to display the data (id and price) of each ShopItem object
    for (int i = 0; i < size; i++) {
        cout << "Item Number: " << i + 1 << endl;
        ptrTemp->getData(); // Access the member function using the arrow operator
        ptrTemp++; // Move the temporary pointer to the next object in the array
    }
    return 0;
}
// Reason of using 2 pointers here, "ptr" and "ptrTemp"!
// In the first loop, the pointer ptr increments with each iteration, moving through the dynamically allocated objects. After the loop ends, it points to an invalid memory location (past the last object), which may lead to accessing garbage values.
// To avoid this, the starting address of the pointer (ptr) is saved in ptrTemp before the first loop ends. Then, ptrTemp is used in the second loop to correctly access and display the data of the objects from the beginning.

// Example 3 : More use of 'this' pointer!
#include<iostream>
using namespace std;

class A {
    int a;
    public:
    A setdata(int a) { // In the setdata function, instead of using void, we return the object itself (of type A). This allows us to chain function calls.
        this-> a = a; // The this pointer is used to distinguish the member variable a from the parameter a. It stores the address of the object being created.
        return *this; // return *this; returns the current object (pointed to by this) by dereferencing the this pointer. This enables the function to return the object itself.
    }
    void getdata() {
        cout<<"The value of a is "<<a<<endl;
    }
};

int main() {
    A a; // Object created!
    a.setdata(4).getdata(); // Here, we call setdata(4) and then chain the getdata() function call on the returned object, all in one line. This works because setdata returns the object itself.
    return 0;
}

// Example 4 : This code demonstrates the use of reference variables, memory allocation, and passing by reference in C++.
//           : It highlights the benefits of using references to avoid unnecessary object copies, optimizing memory usage, and explains how the this pointer works in object-oriented programming.
#include<iostream>
using namespace std;

class A {
    int a; // Private member variable
    public:
    
    // setdata returns a reference to the current object (A&). This enables method chaining and avoids object copying
    A& setdata(int a) { 
        this->a = a; // Use 'this' pointer to distinguish between parameter 'a' and member variable 'a'
        cout << "Address of returned obj is: " << this << endl; // Print the object's address
        return *this; // Return reference to current object by dereferencing 'this'
    }

    // Simple getter method to display the value of 'a'
    void getdata() {
        cout << "The value of a is " << a << endl;
    }
};

int main() {
    int x = 5; // Initialize local variable
    A *a = new A; // Create object dynamically and store its address in pointer 'a'
    cout << "Address stored in pointer: " << a << endl;
    A &z = (*a).setdata(x); // Create reference 'z' that refers to the same object as 'a'. Call setdata through pointer 'a' and store the returned reference
    z.getdata(); // Access the object through reference 'z'
    
    // Print addresses to verify that 'a' and 'z' refer to the same object
    cout << "Address of object jo humein mila is: " << &z << endl;
    cout << "Address stored in pointer: " << a << endl;
    
    delete a;
    return 0;
}

// Example 5 : Similar to Example 4, just a different way!
#include<iostream>
using namespace std;

class A {
    int a;
    public:
    A& setdata(int a) { // Return by reference to avoid copies
        this->a = a;
        cout << "Address of object (this): " << this << endl;
        return *this;
    }
    
    void getdata() {
        cout << "The value of a is " << a << endl;
        cout << "Address of member variable a: " << &a << endl; // This prints address of member variable
    }
};

int main() {
    A a;
    a.setdata(5).getdata();
    // A &z = a.setdata(5); // They both are doing same thing in terms of output! But sometimes method chaining is more better for fluency of the code!
    cout << "Address of object a: " << &a << endl;
    
    A &z = a;  // z is a reference to a
    cout << "Address of reference z: " << &z << endl;  // Will be same as &a
    z.getdata();
    return 0;
}

// Example 6 : More advance version of Example 4 & 5!
#include<iostream>
using namespace std;

class A {
    int a;
    public:
    A & setdata(int &x) { // Both &s prevent copying, & in return type (A setdata) will prevent from creating object copies And & in parameter (int x) will prevent from creating copies of the input value
        cout << "\nAddress of x in setdata is: " << &x << endl; // Will print same address as x in main since x is passed by reference
        this->a = x; // Store x's value in member variable a
        cout << "\nAddress of returned object from setdata is: " << this << endl; // Will print the address of object 'a'
        return *this; // Return reference to same object
    }

    void getdata() {
        // Will print same address as in setdata since we're working with same object
        cout << "\nAddress of object operated by getdata is: " << this << endl;
        cout << "Value inside is: " << a << endl;
    }
};

int main() {
    int x = 5;
    A a;
    cout << "\nAddress of x in main is: " << &x; // Original x's address
    cout << "\nAddress of 'a' is: " << &a << endl; // Original object's address
    a.setdata(x).getdata(); // Chain the calls
    cout << "\nAddress of 'a' is: " << &a << endl; // Same address again
    return 0;
}

// ---------------------------------------------------------- LECTURE 44 - Linked Lists and Its Types --------------------------------------------------------------------------------------------------------->
// Linked Lists Basics : Linked List is a data structure made up of nodes, where each node contains some data and the address of the next node
// Why Do We Need Linked Lists? : Arrays : You can't change the size of an array at runtime.
//                              : Vectors : You can change the size of a vector at runtime, but it’s not efficient. When you increase the size of a vector, a new, larger vector is created, and all elements from the old vector are copied over. This process is slow and inefficient, especially for large vectors.
//                              : Memory Management : Dynamically resizing arrays or vectors can lead to memory wastage and inefficient processing.

// How Linked Lists Help : Dynamic Size : Linked Lists can grow and shrink in size at runtime without the need for complex memory management.
//                       : No Memory Wastage : Only the required memory is used, with no extra space wastage.
//                       : Easy Insertions/Deletions : Adding or removing elements is straightforward and efficient.

// Linked List Structure : Linked Lists don't require contiguous memory blocks.
//                       : Nodes are connected through addresses, allowing them to be stored anywhere in memory.

// Summary of Singly Linked List Implementation!
// Singly Linked List : A Singly Linked List consists of nodes where each node contains Data (The value stored in the node) and Next Pointer (A pointer to the next node in the list, or NULL if it's the last node)
// Structure : The list is structured as : [Value1, Address of next node] -> [Value2, Address of next node] -> [Value3, Address of next node] -> NULL
//           : Head (The first node in the list) and Tail (The last node in the list (points to NULL))
// Linked List Types : Singly Linked List : Nodes point to the next node in the list.
//                   : Doubly Linked List : Each node has two pointers: one pointing to the next node and another pointing to the previous node.
//                   : Circular Linked List : The last node points back to the first node, making the list circular.
// Class-based Implementation : A template class is used to create the linked list node.
//                            : Node Class : Has two attributes : data (stores the node's value) and next (a pointer to the next node).
//                                         : A constructor initializes the node with data and sets the next pointer to NULL.
#include<iostream>
using namespace std;

class NodeSLL1 { // Node class to represent a single node in the linked list
    public :
    int data; // Stores the data of the node
    NodeSLL1* next; // Pointer to the next node

    NodeSLL1(int data) { // Constructor to initialize the node with data and set next to NULL
        this->data = data; // Set the node's data
        this->next = NULL; // Initialize next pointer to NULL (end of the list)
    }
};

int main() {
    NodeSLL1* n1 = new NodeSLL1(10); // Create a new node 'n1' with data 10

    // Output the data and the next pointer of the node 'n1'
    cout << n1->data << endl; // Print the value of the node (10)
    cout << n1->next << endl; // Print the address of the next node (NULL)
    // The created node 'n1' has data 10 and is pointing to NULL (end of the list)
}

// Insertion from the Head!
// Approach : The approach creates a new node, sets its next pointer to the current head, then updates the head to the new node, effectively building the linked list from tail to head.
// Implementation!
#include<iostream>
using namespace std;

// Node creation!
class NodeSLL2 {
    public:
    int data;
    NodeSLL2* next;

    NodeSLL2(int data) {
        this->data = data;
        this->next = NULL;
    }
};

void insertAtHeadSLL1(NodeSLL2* &head, int data) {
    // Empty List!
    NodeSLL2* newNode = new NodeSLL2(data);
    if(head == NULL) {
        head = newNode;
        return;
    }
    newNode->next = head;
    head = newNode;
}

void printNodeSLL1(NodeSLL2* &head) {
    if (head == NULL) {
        cout << "Empty List!" << endl;
        return;
    }
    NodeSLL2* temp = head;
    while(temp != NULL) {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}

int main() {
    NodeSLL2* n1 = new NodeSLL2(10);
    NodeSLL2* head = n1;
    NodeSLL2* tail = n1;

    insertAtHeadSLL1(head, 5);
    insertAtHeadSLL1(head, 0);
    insertAtHeadSLL1(head, -5);
    cout<<"Current Linked List : ";
    printNodeSLL1(head);

    cout<<endl;

    cout<<"Current Head : "<<head->data<<" "<<"Current Tail : "<<tail->data<<endl;
}

// Inserting from the Tail!
// Approach 1 : Use a tail pointer to directly insert the new node at the end in constant time (O(1)).
// Approach 2 : Traverse the list using a temporary pointer until reaching the last node, then insert the new node. This method avoids using the tail pointer but has a time complexity of O(n) for large lists.
//            : Advantages : Simpler function signature without the tail pointer.
//            : Disadvantages : Slower for large lists due to the O(n) traversal time.
// Implementation!
#include<iostream>
using namespace std;

// Node creation!
class NodeSLL3 {
    public:
    int data;
    NodeSLL3* next;

    NodeSLL3(int data) {
        this->data = data;
        this->next = NULL;
    }
};

void insertAtHeadSLL2(NodeSLL3* &head, int data) {
    // Empty List!
    NodeSLL3* newNode = new NodeSLL3(data);
    if(head == NULL) {
        head = newNode;
        return;
    }
    newNode->next = head;
    head = newNode;
}

void insertAtTailSLL1(NodeSLL3* &head, NodeSLL3* &tail, int data) {
    NodeSLL3* newNode = new NodeSLL3(data);
    // Empty List!
    if(tail == NULL) {
        head = tail = newNode;
        tail->next = NULL;
        return;
    }
    tail->next = newNode;
    tail = newNode;
}

void printNodeSLL2(NodeSLL3* &head) {
    if (head == NULL) {
        cout << "Empty List!" << endl;
        return;
    }
    NodeSLL3* temp = head;
    while(temp != NULL) {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}

int main() {
    NodeSLL3* n1 = new NodeSLL3(10);
    NodeSLL3* head = n1;
    NodeSLL3* tail = n1;

    insertAtHeadSLL2(head, 5);
    insertAtHeadSLL2(head, 0);
    cout<<"Current Linked List : ";
    printNodeSLL2(head);

    cout<<endl;

    insertAtTailSLL1(head, tail, 15);
    insertAtTailSLL1(head, tail, 20);
    cout<<"Current Linked List : ";
    printNodeSLL2(head);

    cout<<endl;

    cout<<"Current Head : "<<head->data<<" "<<"Current Tail : "<<tail->data<<endl;
}

// Insertion Anywhere (Head, Tail, or Middle):
// Empty List : If head is NULL, create a new node and set it as the head.
// Insert at Head : If position is 1, insert using insertAtHead() function.
// Insert at Tail/Middle : Traverse to the desired position and insert.
// Update Tail : If inserted node is at the end (newNode->next == NULL), update tail pointer.
// Implementation!
#include<iostream>
using namespace std;

// Node creation!
class NodeSLL4 {
    public:
    int data;
    NodeSLL4* next;

    NodeSLL4(int data) {
        this->data = data;
        this->next = NULL;
    }
};

void insertAtHeadSLL3(NodeSLL4* &head, int data) {
    NodeSLL4* newNode = new NodeSLL4(data);
    // Empty List!
    if(head == NULL) {
        head = newNode;
        return;
    }
    newNode->next = head;
    head = newNode;
}

void insertAtTailSLL2(NodeSLL4* &head, NodeSLL4* &tail, int data) {
    NodeSLL4* newNode = new NodeSLL4(data);
    // Empty List!
    if(tail == NULL) {
        head = tail = newNode;
        tail->next = NULL;
        return;
    }
    tail->next = newNode;
    tail = newNode;
}

int getLenSLL1(NodeSLL4* &head) {
    int len = 0;
    NodeSLL4* temp = head;
    while(temp != NULL) {
        len++;
        temp = temp->next;
    }
    return len;
}

void insertAnywhereSLL1(NodeSLL4* &head, NodeSLL4* &tail, int pos, int data) {
    // Empty List!
    if(head == NULL) {
        NodeSLL4* newNode = new NodeSLL4(data);
        head = newNode;
        tail = newNode;
        return;
    }

    // Insertion at Head!
    if(pos == 1) {
        insertAtHeadSLL3(head, data);
        return;
    }

    int len = getLenSLL1(head);
    if(pos < 1 || pos > len + 1) {
        cout<<"Invalid position!";
        return;
    }

    NodeSLL4* temp = head;
    int count = 1;

    // Traversing between nodes where excluding first node and last node!
    while(count < pos - 1 && temp->next != NULL) {
        temp = temp->next;
        count++;
    }

    // Insertion at Tail Node!
    NodeSLL4* newNode = new NodeSLL4(data);

    if(temp->next == NULL) {
        temp->next = newNode;
        tail = newNode;
        return;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}

void printNodeSLL3(NodeSLL4* &head) {
    if (head == NULL) {
        cout << "Empty List!" << endl;
        return;
    }
    NodeSLL4* temp = head;
    while(temp != NULL) {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}

int main() {
    NodeSLL4* n1 = new NodeSLL4(10);
    NodeSLL4* head = n1;
    NodeSLL4* tail = n1;

    insertAtHeadSLL3(head, 5);
    insertAtHeadSLL3(head, 0);
    cout<<"Current Linked List : ";
    printNodeSLL3(head);

    cout<<endl;
    cout<<"Current Head : "<<head->data<<" "<<"Current Tail : "<<tail->data<<endl;

    insertAtTailSLL2(head, tail, 15);
    insertAtTailSLL2(head, tail, 20);
    cout<<"Current Linked List : ";
    printNodeSLL3(head);

    cout<<endl;
    cout<<"Current Head : "<<head->data<<" "<<"Current Tail : "<<tail->data<<endl;

    cout<<endl;

    insertAnywhereSLL1(head, tail, 1, -5);
    insertAnywhereSLL1(head, tail, getLenSLL1(head)+1, 25);
    insertAnywhereSLL1(head, tail, 3, 1000);
    cout<<"Current Linked List : ";
    printNodeSLL3(head);

    cout<<endl;
    cout<<"Current Head : "<<head->data<<" "<<"Current Tail : "<<tail->data<<endl;
}

// Deletion of Node from Singly LL!
// Empty List Check : If the list is empty, return immediately as deletion is not possible.
// Position Validation : Ensure the position is valid (within range), otherwise show an error.
// Delete Head Node : If position is 1, update the head to the next node, delete the original head.
// Delete Node at Other Positions : Traverse to the node just before the one to be deleted, adjust pointers to skip the node, and delete it.
// Update Tail : If deleting the last node, update the tail pointer to the previous node.
#include<iostream>
using namespace std;

// Node creation!
class NodeSLL5 {
    public:
    int data;
    NodeSLL5* next;

    NodeSLL5(int data) {
        this->data = data;
        this->next = NULL;
    }

    ~NodeSLL5() {
        cout<<"Node deleted with value : "<<this->data<<endl;
    }
};

void insertAtHeadSLL4(NodeSLL5* &head, int data) {
    // Empty List!
    NodeSLL5* newNode = new NodeSLL5(data);
    if(head == NULL) {
        head = newNode;
        return;
    }
    newNode->next = head;
    head = newNode;
}

void insertAtTailSLL3(NodeSLL5* &head, NodeSLL5* &tail, int data) {
    NodeSLL5* newNode = new NodeSLL5(data);
    // Empty List!
    if(tail == NULL) {
        head = tail = newNode;
        tail->next = NULL;
        return;
    }
    tail->next = newNode;
    tail = newNode;
}

int getLenSLL2(NodeSLL5* &head) {
    int len = 0;
    NodeSLL5* temp = head;
    while(temp != NULL) {
        len++;
        temp = temp->next;
    }
    return len;
}

void insertAnywhereSLL2(NodeSLL5* &head, NodeSLL5* &tail, int pos, int data) {
    // Empty List!
    if(head == NULL) {
        NodeSLL5* newNode = new NodeSLL5(data);
        head = newNode;
        tail = newNode;
        return;
    }

    // Insertion at Head!
    if(pos == 1) {
        insertAtHeadSLL4(head, data);
        return;
    }

    int len = getLenSLL2(head);
    if(pos < 1 || pos > len + 1) { // Validating Position!
        cout<<"Invalid position!";
        return;
    }

    NodeSLL5* temp = head;
    int count = 1;

    // Traversing between nodes where excluding first node and last node!
    while(count < pos - 1) {
        temp = temp->next;
        count++;
    }

    // Checking if its Insertion at Tail, if yes then Insert at Tail and update Tail pointer!
    NodeSLL5* newNode = new NodeSLL5(data);

    if(temp->next == NULL) {
        temp->next = newNode;
        tail = newNode;
        return;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}

void deleteNodeSLL2(NodeSLL5* &head, NodeSLL5* &tail, int pos) {
    // Empty List!
    if(head == NULL) {
        cout<<"Empty List!";
        return;
    }

    // Validating Position!
    int len = getLenSLL2(head);
    if(pos < 1 || pos > len) {
        cout<<"Invalid Position!";
        return;
    }

    // Deleting from head!
    if(pos == 1) {
        NodeSLL5* temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
        return;
    }

    // General case!
    NodeSLL5* prev = NULL;
    NodeSLL5* curr = head;
    int count = 1;

    while(count < pos) {
        prev = curr;
        curr = curr->next;
        count++;
    }

    prev->next = curr->next;
    if(curr->next == NULL) { // Deleting from tail!
        tail = prev;
        delete curr;
        return;
    }
    curr->next = NULL;
    delete curr;
}

void printNodeSLL4(NodeSLL5* &head) {
    if (head == NULL) {
        cout << "Empty List!" << endl;
        return;
    }
    NodeSLL5* temp = head;
    while(temp != NULL) {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

int main() {
    NodeSLL5* n1 = new NodeSLL5(10);
    NodeSLL5* head = n1;
    NodeSLL5* tail = n1;

    insertAtHeadSLL4(head, 5);
    insertAtHeadSLL4(head, 0);
    cout<<"Current Linked List : ";
    printNodeSLL4(head);
    cout<<"Current Head : "<<head->data<<" "<<"Current Tail : "<<tail->data<<endl;

    cout<<endl;
    
    insertAtTailSLL3(head, tail, 15);
    insertAtTailSLL3(head, tail, 20);
    cout<<"Current Linked List : ";
    printNodeSLL4(head);
    cout<<"Current Head : "<<head->data<<" "<<"Current Tail : "<<tail->data<<endl;

    cout<<endl;

    insertAnywhereSLL2(head, tail, 1, -5);
    insertAnywhereSLL2(head, tail, getLenSLL2(head)+1, 25);
    insertAnywhereSLL2(head, tail, 3, 1000);
    insertAnywhereSLL2(head, tail, getLenSLL2(head)+1, 40);
    cout<<"Current Linked List : ";
    printNodeSLL4(head);
    cout<<"Current Head : "<<head->data<<" "<<"Current Tail : "<<tail->data<<endl;

    cout<<endl;

    deleteNodeSLL2(head, tail, 1);
    cout<<"Current Linked List : ";
    printNodeSLL4(head);
    cout<<"Current Head : "<<head->data<<" "<<"Current Tail : "<<tail->data<<endl;
    
    cout<<endl;

    deleteNodeSLL2(head, tail, 3);
    cout<<"Current Linked List : ";
    printNodeSLL4(head);
    cout<<"Current Head : "<<head->data<<" "<<"Current Tail : "<<tail->data<<endl;

    cout<<endl;

    deleteNodeSLL2(head, tail, getLenSLL2(head));
    cout<<"Current Linked List : ";
    printNodeSLL4(head);
    cout<<"Current Head : "<<head->data<<" "<<"Current Tail : "<<tail->data<<endl;
}

// Doubly Linked List (DLL)!
// A Doubly Linked List (DLL) is a type of Linked List where each node stores the address of both the next and the previous node. Unlike a Singly Linked List (SLL), where nodes only point to the next node.
// DLL nodes have two pointers : Next Pointer (next) : Stores the address of the next node in the list.
//                             : Previous Pointer (prev) : Stores the address of the previous node in the list.
// Implementation!
// Doubly Linked List!
#include<iostream>
using namespace std;

class NodeDLL1 { // Node creation
    public:
    int data;
    NodeDLL1* next = NULL;
    NodeDLL1* prev = NULL;

    NodeDLL1(int data) {
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
};

void insertAtHeadDLL1(NodeDLL1* &head, int data) { // Insertion at Head!
    NodeDLL1* temp = new NodeDLL1(data);
    if(head == NULL) {
        head = temp;
        return;
    }
    head->prev = temp;
    temp->next = head;
    head = temp;
}

void insertAtTailDLL1(NodeDLL1* &head ,NodeDLL1* &tail, int data) { // Insertion at Tail!
    NodeDLL1* temp = new NodeDLL1(data);
    if(tail == NULL) {
        head = tail = temp;
        return;
    }
    tail->next = temp;
    temp->prev = tail;
    tail = temp;
}

int getLenDLL1(NodeDLL1* &head) { // Claculating Length of LL!
    NodeDLL1* temp = head;
    int len = 0;
    while(temp != NULL) {
        len++;
        temp = temp->next;
    }
    return len;
}

void insertAnywhereDLL1(NodeDLL1* &head, NodeDLL1* &tail, int data, int pos) { // Insertion anywhere based on Position!
    // Empty List!
    if(head == NULL) {
        NodeDLL1* temp = new NodeDLL1(data);
        head = tail = temp;
        return;
    }

    // Insertion at Head if pos == 1.
    if(pos == 1) {
        insertAtHeadDLL1(head, data);
        return;
    }

    int len = getLenDLL1(head);
    if(pos < 1 || pos > len + 1) { // Validating position!
        cout<<"Invalid Length!";
        return;
    }

    NodeDLL1* temp = head;
    int count = 1;
    while(count < pos - 1) { // Traversing between nodes where excluding first node and last node!
        count++;
        temp = temp->next;
    }

    NodeDLL1* newNode = new NodeDLL1(data);
    
    if(temp->next == NULL) { // Checking if its Insertion at Tail, if yes then Insert at Tail and update Tail pointer!
        newNode->prev = temp;
        temp->next = newNode;
        tail = newNode;
        return;
    }

    // Else insertion in somewhere middle
    newNode->prev = temp;
    newNode->next = temp->next;
    temp->next = newNode;
}

void printNodeDLL1(NodeDLL1* &head) {
    NodeDLL1* temp = head;
    while(temp != NULL) {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

int main() {
    NodeDLL1* n1 = new NodeDLL1(10);
    NodeDLL1* head = n1;
    NodeDLL1* tail = n1;

    cout<<"Current LinkedList : ";
    printNodeDLL1(head);
    cout<<"Current Head : "<<head->data<<" Current Tail : "<<tail->data<<endl;

    cout<<endl;

    insertAtHeadDLL1(head, 5);
    insertAtHeadDLL1(head, 0);
    insertAtHeadDLL1(head, -5);
    insertAtHeadDLL1(head, -10);
    cout<<"Current LinkedList : ";
    printNodeDLL1(head);
    cout<<"Current Head : "<<head->data<<" Current Tail : "<<tail->data<<endl;

    cout<<endl;

    insertAtTailDLL1(head, tail, 15);
    insertAtTailDLL1(head, tail, 20);
    insertAtTailDLL1(head, tail, 25);
    insertAtTailDLL1(head, tail, 30);
    cout<<"Current LinkedList : ";
    printNodeDLL1(head);
    cout<<"Current Head : "<<head->data<<" Current Tail : "<<tail->data<<endl;

    cout<<endl;

    insertAnywhereDLL1(head, tail, -15,1);
    insertAnywhereDLL1(head, tail, -20,1);
    insertAnywhereDLL1(head, tail, 101,5);
    insertAnywhereDLL1(head, tail, 35, getLenDLL1(head) + 1);
    insertAnywhereDLL1(head, tail, 40, getLenDLL1(head) + 1);
    cout<<"Current LinkedList : ";
    printNodeDLL1(head);
    cout<<"Current Head : "<<head->data<<" Current Tail : "<<tail->data<<endl;
}
// Note : Using both head and tail makes operations faster and avoids unnecessary traversal.
//      : Using only head reduces space but increases time complexity for tail insertions (O(n)).

// Deletion of Node!
// Approach : Deleting the Head Node : The head node's prev will point to NULL because it's the first node. The head's next node will have its prev pointer updated to point to the new head.
//                                   : Update the head to point to the next node. Finally, free the memory of the old head node to prevent memory leaks.
//          : Deleting a Node Other Than the Head : Set the previous node's next pointer to the current node's next (i.e., skip the node). Set the current node's next pointer to NULL.
//                                                : Free the memory of the current node after unlinking it from the list.
// Implementation!
#include<iostream>
using namespace std;

class NodeDLL2 {
    public:
    int data;
    NodeDLL2* next = NULL;
    NodeDLL2* prev = NULL;

    NodeDLL2(int data) {
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }

    ~NodeDLL2() {
        next = NULL;
        prev = NULL;
        cout << "Value of deleted node: " << data << endl;
    }
};

void insertAtHeadDLL2(NodeDLL2* &head, int data) {
    NodeDLL2* temp = new NodeDLL2(data);
    if(head == NULL) {
        head = temp;
        return;
    }
    head->prev = temp;
    temp->next = head;
    head = temp;
}

void insertAtTailDLL2(NodeDLL2* &head ,NodeDLL2* &tail, int data) {
    NodeDLL2* temp = new NodeDLL2(data);
    if(tail == NULL) {
        head = tail = temp;
        return;
    }
    tail->next = temp;
    temp->prev = tail;
    tail = temp;
}

int getLenDLL2(NodeDLL2* head) {
    NodeDLL2* temp = head;
    int len = 0;
    while(temp != NULL) {
        len++;
        temp = temp->next;
    }
    return len;
}

void insertAnywhereDLL2(NodeDLL2* &head, NodeDLL2* &tail, int data, int pos) {
    if(head == NULL) {
        NodeDLL2* temp = new NodeDLL2(data);
        head = tail = temp;
        return;
    }

    if(pos == 1) {
        insertAtHeadDLL2(head, data);
        return;
    }

    int len = getLenDLL2(head);
    if(pos < 1 || pos > len + 1) {
        cout<<"Invalid Length!";
        return;
    }

    NodeDLL2* temp = head;
    int count = 1;
    while(count < pos - 1) {
        count++;
        temp = temp->next;
    }

    if(temp->next == NULL) {
        NodeDLL2* newNode = new NodeDLL2(data);
        newNode->prev = temp;
        temp->next = newNode;
        tail = newNode;
        return;
    }

    NodeDLL2* newNode = new NodeDLL2(data);
    newNode->prev = temp;
    newNode->next = temp->next;
    temp->next->prev = newNode;
    temp->next = newNode;
}

void deleteNodeDLL1(NodeDLL2* &head, NodeDLL2* &tail, int pos) {
    if(head == NULL) { // Empty List!
        cout<<"Empty List!";
        return;
    }

    int len = getLenDLL2(head);
    if(pos < 1 || pos > len) { // Validating Position!
        cout<<"Invalid Position!";
        return;
    }

    if(pos == 1) { // Deleting from Head!
        NodeDLL2* temp = head;
        head = temp->next;
        if(head != NULL) {
            head->prev = NULL;
        }
        else {
            tail = NULL;
        }
        temp->next = NULL;
        delete temp;
        return;
    }

    NodeDLL2* temp = head;
    int count = 1;
    while(count < pos) { // Traversing to a particular node!
        count++;
        temp = temp->next;
    }

    if(temp->next == NULL) { // Delete from tail!
        tail = temp->prev;
        tail->next = NULL;
        temp->prev = NULL;
        delete temp;
        return;
    }

    // Delete from somewhere middle!
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    temp->prev = NULL;
    temp->next = NULL;
    delete temp;
}

void printNodeDLL2(NodeDLL2* &head) {
    NodeDLL2* temp = head;
    while(temp != NULL) {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

int main() {
    NodeDLL2* n1 = new NodeDLL2(10);
    NodeDLL2* head = n1;
    NodeDLL2* tail = n1;

    cout<<"Current LinkedList : ";
    printNodeDLL2(head);
    cout<<"Current Head : "<<head->data<<" Current Tail : "<<tail->data<<endl;

    cout<<endl;

    insertAtHeadDLL2(head, 5);
    insertAtHeadDLL2(head, 0);
    insertAtHeadDLL2(head, -5);
    insertAtHeadDLL2(head, -10);
    cout<<"Current LinkedList : ";
    printNodeDLL2(head);
    cout<<"Current Head : "<<head->data<<" Current Tail : "<<tail->data<<endl;

    cout<<endl;

    insertAtTailDLL2(head, tail, 15);
    insertAtTailDLL2(head, tail, 20);
    insertAtTailDLL2(head, tail, 25);
    insertAtTailDLL2(head, tail, 30);
    cout<<"Current LinkedList : ";
    printNodeDLL2(head);
    cout<<"Current Head : "<<head->data<<" Current Tail : "<<tail->data<<endl;

    cout<<endl;

    insertAnywhereDLL2(head, tail, -15,1);
    insertAnywhereDLL2(head, tail, -20,1);
    insertAnywhereDLL2(head, tail, 101,5);
    insertAnywhereDLL2(head, tail, 35, getLenDLL2(head) + 1);
    insertAnywhereDLL2(head, tail, 40, getLenDLL2(head) + 1);
    cout<<"Current LinkedList : ";
    printNodeDLL2(head);
    cout<<"Current Head : "<<head->data<<" Current Tail : "<<tail->data<<endl;

    cout<<endl;

    deleteNodeDLL1(head, tail, 5);
    cout<<"Current LinkedList : ";
    printNodeDLL2(head);
    cout<<"Current Head : "<<head->data<<" Current Tail : "<<tail->data<<endl;

    cout<<endl;

    deleteNodeDLL1(head, tail, 1);
    cout<<"Current LinkedList : ";
    printNodeDLL2(head);
    cout<<"Current Head : "<<head->data<<" Current Tail : "<<tail->data<<endl;

    cout<<endl;

    deleteNodeDLL1(head, tail, getLenDLL2(head));
    cout<<"Current LinkedList : ";
    printNodeDLL2(head);
    cout<<"Current Head : "<<head->data<<" Current Tail : "<<tail->data<<endl;
}

// Circular Linked List!
// A Circular Linked List (CLL) is a variation of a linked list where the last node connects back to the first node instead of NULL.
// There are two types : Singly Circular Linked List - Each node has a next pointer and The last node’s next points to the head (first node).
//                     : Doubly Circular Linked List - Each node has both next and prev pointers and The last node’s next points to the head, and the head’s prev points to the last node.
// Key Differences from a Normal Linked List : Uses tail instead of head (for efficient insertions and deletions, its a choice not a rule).
//                                           : Circular nature – No NULL pointers; every node connects in a loop.
//                                           : No fixed position-based insertions/deletions – We insert or delete relative to an existing node.
//                                           : Head is not required since we can always access head via tail->next. (Again its a choice, you can use both head and tail for easier traversal)
// Insertion in a Circular Linked List : Inserting When the List is Empty : Create a new node where next points to itself. -> Set tail = newNode.
//                                                                        : Example for Singly Circular Linked List : Node* newNode = new Node(value); newNode->next = newNode; // Points to itself tail = newNode; // Update tail 
//                                                                        : Example for Doubly Circular Linked List : Node* newNode = new Node(value); newNode->next = newNode; newNode->prev = newNode; tail = newNode;
//                                     : Inserting After a Given Node (When List is Not Empty) : Find the node (current) after which the new node should be inserted. Create a new node (temp). Adjust pointers so that temp is linked properly.
//                                                                                             : Case 1 : Inserting After Any Node, Store current->next in a temporary variable, Link temp->next = current->next and Update current->next = temp.
//                                                                                                      : If inserting after the last node (tail), update tail = temp.
//                                     : Handling Doubly Circular Linked List (DCLL) Insertions : In DCLL, we need to update both next and prev pointers : temp->next = current->next; temp->prev = current; current->next->prev = temp; current->next = temp;
//                                                                                              :  If inserting after tail, update tail = temp.

// Insertion in Circular Linked List is based on two factors Position and Elements!
// Position : Most widely followed approach because positions are fixed and do not change dynamically like values.
//          : Used in list-based applications (e.g., playlists, circular queues, OS scheduling, etc.).
//          : Better control over placement—can insert at the beginning, middle, or end easily.
//          : Limitations : Requires traversing the list up to the (n-1)th node, making it O(n) in worst case.
//                        : Index-based insertion does not depend on the element values.
// Elements : Common when elements have unique identifiers (e.g., student IDs, employee IDs, etc.).
//          : Used when we don't know the position but need to insert relative to a value.
//          : In case of duplicate values insertion can happen in 4 ways, insertion after 1st occurence (default), insertion after last occurence, insertion after nth occurence and insertion after all (each) occurence.
//          : Limitations : If there are duplicate values, it inserts after the first occurrence by default.
//                        : Searching for the value takes O(n) time in the worst case.

// Conclusion : Position based insertion is most common in real-world applications like : Circular queues (used in operating systems, buffering, etc.), Multitasking OS scheduling (Round-Robin scheduling), Data structures like circular lists used in graph traversal (e.g., adjacency lists) and more...
//            : Value-based insertion is preferred when dealing with unique identifiers or sorted lists where insertion needs to be based on values.
//            : Here in, we have implemented two insertion methods including one as Position and one as default after first element! rest you can implement at per need!

// Implementation! (Element based insertion!)
#include <iostream>
using namespace std;

class NodeCSLL1 {
public:
    int data;
    NodeCSLL1* next;

    NodeCSLL1(int data) {
        this->data = data;
        this->next = NULL;
    }
};

// Insert a node after the given element
void insertNodeCSLL1(NodeCSLL1*& tail, int element, int data) {
    NodeCSLL1* newNode = new NodeCSLL1(data);

    // Case 1: Empty List
    if (tail == NULL) {
        tail = newNode;
        newNode->next = newNode;
        return;
    }

    // Case 2: Insert after a specific element
    NodeCSLL1* current = tail;
    do {
        if (current->data == element) {
            newNode->next = current->next;
            current->next = newNode;
            if (current == tail) {
                tail = newNode; // Update tail if inserting after the last node
            }
            return;
        }
        current = current->next;
    } while (current != tail);

    cout << "Element " << element << " not found in the list!" << endl;
    delete newNode; // Prevent memory leak
}

// Print the list
void printListCSLL1(NodeCSLL1* tail) {
    if (tail == NULL) {
        cout << "List is empty!" << endl;
        return;
    }

    NodeCSLL1* current = tail->next;
    do {
        cout << current->data << " ";
        current = current->next;
    } while (current != tail->next);
    cout << endl;
}

int main() {
    NodeCSLL1* tail = NULL;

    insertNodeCSLL1(tail, -1, 3);
    cout<<"Current Linked List : ";
    printListCSLL1(tail);
    cout<<"Current Tail : "<<tail->data<<endl;
    
    cout<<endl;

    insertNodeCSLL1(tail, 3, 5);
    cout<<"Current Linked List : ";
    printListCSLL1(tail);
    cout<<"Current Tail : "<<tail->data<<endl;

    cout<<endl;

    insertNodeCSLL1(tail, 5, 7);
    cout<<"Current Linked List : ";
    printListCSLL1(tail);
    cout<<"Current Tail : "<<tail->data<<endl;

    cout<<endl;

    insertNodeCSLL1(tail, 7, 9);
    cout<<"Current Linked List : ";
    printListCSLL1(tail);
    cout<<"Current Tail : "<<tail->data<<endl;

    cout<<endl;

    insertNodeCSLL1(tail, 3, 4);
    cout<<"Current Linked List : ";
    printListCSLL1(tail);
    cout<<"Current Tail : "<<tail->data<<endl;

    cout<<endl;

    insertNodeCSLL1(tail, 9, 10);
    cout<<"Current Linked List : ";
    printListCSLL1(tail);
    cout<<"Current Tail : "<<tail->data<<endl;

    cout<<endl;

    insertNodeCSLL1(tail, 7, 8);
    cout<<"Current Linked List : ";
    printListCSLL1(tail);
    cout<<"Current Tail : "<<tail->data<<endl;

    cout<<endl;

    insertNodeCSLL1(tail, 10, 2);
    cout<<"Current Linked List : ";
    printListCSLL1(tail);
    cout<<"Current Tail : "<<tail->data<<endl;

    return 0;
}

// Implementation! (Position based insertion!)
#include<iostream>
using namespace std;

class NodeCSLL2 { // General Node Creation!
    public:
    int data;
    NodeCSLL2* next;

    NodeCSLL2(int data) {
        this->data = data;
        this->next = NULL;
    }
};

int getLenCSLL2(NodeCSLL2* tail) { // Calculating Length!
    if(tail == NULL) {
        cout<<"Empty List!";
        return 0;
    }
    NodeCSLL2* curr = tail->next;
    int len = 0;
    do {
        len++;
        curr = curr->next;
    } while (curr != tail->next);
    return len;
}

void insertNodeCSLL2(NodeCSLL2* &tail, int pos, int data) {
    NodeCSLL2* newNode = new NodeCSLL2(data);

    if(tail == NULL) { // Empty List Condition!
        tail = newNode;
        newNode->next = newNode;
        return;
    }

    int len = getLenCSLL2(tail);
    if(pos < 1 || pos > len + 1) { // Validating Position!
        cout<<"Invalid Position!";
        delete newNode;
        return;
    }

    if (pos == 1) { // Insertion at Head!
        newNode->next = tail->next;
        tail->next = newNode;
        if (tail == tail->next) {
            tail = newNode;
        }
        return;
    }

    if(pos == len + 1) { // Insertion at Tail!
        newNode->next = tail->next;
        tail->next = newNode;
        tail = newNode;
        return;
    }

    // Insert at some position in between!
    NodeCSLL2* temp = tail->next;
    int count = 1;
    while(count < pos - 1) {
        count++;
        temp = temp->next;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}


void printListCSLL2(NodeCSLL2* tail) {
    if (tail == NULL) {
        cout << "List is empty!" << endl;
        return;
    }

    NodeCSLL2* current = tail->next;
    do {
        cout << current->data << " ";
        current = current->next;
    } while (current != tail->next);
    cout << endl;
}

int main() {
    NodeCSLL2* n1 = new NodeCSLL2(10);
    NodeCSLL2* tail = n1;
    tail->next = tail; // Making it a circular LL!
    cout<<"Current Linked List : ";
    printListCSLL2(tail);
    cout<<"Current Tail : "<<tail->data;

    cout<<endl;

    insertNodeCSLL2(tail, getLenCSLL2(tail) + 1, 20);
    cout<<"Current Linked List : ";
    printListCSLL2(tail);
    cout<<"Current Tail : "<<tail->data;

    cout<<endl;

    insertNodeCSLL2(tail, getLenCSLL2(tail) + 1, 30);
    cout<<"Current Linked List : ";
    printListCSLL2(tail);
    cout<<"Current Tail : "<<tail->data;

    cout<<endl;
    
    insertNodeCSLL2(tail, getLenCSLL2(tail) + 1, 40);
    cout<<"Current Linked List : ";
    printListCSLL2(tail);
    cout<<"Current Tail : "<<tail->data;

    cout<<endl;

    insertNodeCSLL2(tail, getLenCSLL2(tail) + 1, 50);
    cout<<"Current Linked List : ";
    printListCSLL2(tail);
    cout<<"Current Tail : "<<tail->data;

    cout<<endl;

    insertNodeCSLL2(tail, getLenCSLL2(tail) + 1, 60);
    cout<<"Current Linked List : ";
    printListCSLL2(tail);
    cout<<"Current Tail : "<<tail->data;
}

// Deletion of Node in Circular Linked List!
// Approach : Check if List is Empty : If tail is NULL, just return as nothing to delete
//          : Check Single Node Case : If node points to itself (tail->next == tail), it's the only node and If this single node has the value we want to delete, then Delete it and Set tail to NULL
//          : Handle Multiple Nodes : Keep track of two nodes, previous and current, Previous starts at tail, Current starts at the first node (tail->next), Keep moving through list until either : We find the value to delete, or We've checked the whole list
//          : When Node is Found : If it's the tail node : Make previous node the new tail, Point new tail to the first node
//                               : If it's any other node : Simply connect previous node to the node after current and Delete the node we found
//          : If Value Not Found : Just return or show error message
//          : Memory Cleanup : Always remember to free the deleted node's memory and Don't break the circular nature of the list.
//          : Note : Node deletion can be performed based on either position or element value. The approach remains similar, and you can practice both methods. Here, we will focus on deleting a node based on its element value.

// Implementing!
#include <iostream>
using namespace std;

class NodeCSLL3 {
public:
    int data;
    NodeCSLL3* next;

    NodeCSLL3(int data) {
        this->data = data;
        this->next = nullptr;
    }

    ~NodeCSLL3() {
        cout << "Value of deleted element: " << data << endl;
    }
};

void insertNodeCSLL3(NodeCSLL3*& tail, int element, int data) {
    NodeCSLL3* newNode = new NodeCSLL3(data);

    // Case 1: Empty List (tail == NULL)
    if (tail == nullptr) {
        tail = newNode;
        newNode->next = newNode; // Points to itself (circular)
        return;
    }

    NodeCSLL3* current = tail->next; // Start from the head (tail's next)
    do {
        if (current->data == element) {
            newNode->next = current->next;
            current->next = newNode;
            
            // If inserted after tail, update the tail pointer
            if (current == tail) {
                tail = newNode;
            }
            return;
        }
        current = current->next;
    } while (current != tail->next); // Loop until you complete the circle

    cout << "Element " << element << " not found in the list!" << endl;
    delete newNode; // Prevent memory leak
}

// Delete a node with a given element
void deleteNodeCSLL3(NodeCSLL3*& tail, int element) {
    if (tail == nullptr) {
        cout << "List is empty!" << endl;
        return;
    }

    NodeCSLL3* prev = tail;
    NodeCSLL3* curr = tail->next;

    // Case 1: Single node in the list
    if (curr == tail && curr->data == element) {
        delete tail;
        tail = nullptr;
        return;
    }

    // Case 2: Multiple nodes
    do {
        if (curr->data == element) {
            prev->next = curr->next;
            if (curr == tail) {
                tail = prev; // Update tail if the last node is deleted
            }
            delete curr;
            return;
        }
        prev = curr;
        curr = curr->next;
    } while (curr != tail->next);
    cout << "Element " << element << " not found in the list!" << endl;
}

// Print the list
void printListCSLL3(NodeCSLL3* tail) {
    if (tail == nullptr) {
        cout << "List is empty!" << endl;
        return;
    }

    NodeCSLL3* current = tail->next;
    do {
        cout << current->data << " ";
        current = current->next;
    } while (current != tail->next);
    cout << endl;
}

int main() {
    NodeCSLL3* tail = nullptr;

    // Test case: Insert into empty list
    insertNodeCSLL3(tail, -1, 3);  // Insert after -1, which is not in the list
    cout << "Current Linked List: ";
    printListCSLL3(tail);
    cout << "Current Tail: " << tail->data << endl;
    cout << endl;

    // Test case: Delete the only node
    deleteNodeCSLL3(tail, 3);
    cout << "Current Linked List: ";
    printListCSLL3(tail);
    cout << "Current Tail: " << (tail ? to_string(tail->data) : "null") << endl; // Just to print NULL, if the list is empty!
    cout << endl;

    // Test case: Insert multiple nodes
    insertNodeCSLL3(tail, -1, 5);  // Insert into empty list (tail is null)
    cout << "Current Linked List: ";
    printListCSLL3(tail);
    cout << "Current Tail: " <<(tail ? to_string(tail->data) : "null") << endl;
    cout << endl;

    insertNodeCSLL3(tail, 5, 7);  // Insert after 5
    cout << "Current Linked List: ";
    printListCSLL3(tail);
    cout << "Current Tail: " << (tail ? to_string(tail->data) : "null") << endl;
    cout << endl;

    insertNodeCSLL3(tail, 7, 9);  // Insert after 7
    cout << "Current Linked List: ";
    printListCSLL3(tail);
    cout << "Current Tail: " << (tail ? to_string(tail->data) : "null") << endl;
    cout << endl;

    insertNodeCSLL3(tail, 9, 3);  // Insert after 9 (tail)
    cout << "Current Linked List: ";
    printListCSLL3(tail);
    cout << "Current Tail: " << (tail ? to_string(tail->data) : "null") << endl;
    cout << endl;

    // Test case: Delete from the list
    deleteNodeCSLL3(tail, 7);  // Delete node with data 7
    cout << "Current Linked List: ";
    printListCSLL3(tail);
    cout << "Current Tail: " << (tail ? to_string(tail->data) : "null") << endl;
    cout << endl;

    deleteNodeCSLL3(tail, 9);  // Delete node with data 9 (tail)
    cout << "Current Linked List: ";
    printListCSLL3(tail);
    cout << "Current Tail: " << (tail ? to_string(tail->data) : "null") << endl;
    cout << endl;

    deleteNodeCSLL3(tail, 3);  // Delete node with data 3 (only element)
    cout << "Current Linked List: ";
    printListCSLL3(tail);
    cout << "Current Tail: " << (tail ? to_string(tail->data) : "null") << endl;
    cout << endl;

    deleteNodeCSLL3(tail, 5);
    cout << "Current Linked List: ";
    printListCSLL3(tail);
    cout << "Current Tail: " << (tail ? to_string(tail->data) : "null") << endl;
    cout<<endl;

    // Edge case: Try to delete from an empty list
    deleteNodeCSLL3(tail, 5);  // List is empty
    cout << "Current Linked List: ";
    printListCSLL3(tail);
    cout << "Current Tail: " << (tail ? to_string(tail->data) : "null") << endl;

    return 0;
}

// Circular Doubly Linked List!
// Implementation of node creation, insertion, deletion, and print length functions combined.
// Insertion : Insertion can be performed based on either the position or the element’s value. Positions can be classified into four types : After the first occurrence, After the last occurrence, After the nth occurrence, After all occurrences.
//           : There are also other combinations based on positions, but for now, we will focus only on insertion after the first occurrence. You can implement the rest as per your requirements.
//           : Approach : Start at the head node : Begin by setting the current pointer to the head of the list. This is where the traversal begins.
//                      : Traverse the list : Loop through the nodes starting from the head and look for the first occurrence of the given element. Since the list is circular, you will stop when the current node comes back to the head node.
//                      : Find the first occurrence : If the element matches the data in the current node, you've found the first occurrence.
//                      : Insert the new node : Once the first occurrence is found, create a new node with the given data. Set the next pointer of the new node to point to the node after current. Set the prev pointer of the new node to point to current. Then, update the next pointer of current to point to the new node, and the prev pointer of the node after current (if it exists) to point to the new node.
//                      : Empty List : If the list is empty (head is NULL), create the new node and set both head and tail to this node, making the list circular.
//                      : Update pointers : In a circular doubly linked list, ensure that the next of the tail node points to the head, and the prev of the head points to the tail, maintaining the circular structure.

// Deletion : Check if the list is empty : If the head is NULL, that means the list is empty, so there's nothing to delete.
//          : Find the node to delete : Traverse the list starting from the head node. Check each node’s data to see if it matches the value of the node you want to delete. Since the list is circular, keep traversing using the next pointer until you either find the node or return to the head node.
//          : Handle the node to delete : If the node to delete is found : If the node to delete is the only node : Set both the head and tail to NULL, as the list will become empty.
//                                                                       : If the node to delete is the head node : Update the head pointer to the next node and adjust the prev pointer of the new head node to point to the tail.
//                                                                       : If the node to delete is the tail node : Update the tail pointer to the previous node and adjust the next pointer of the new tail node to point to the head.
//                                                                       : If the node is somewhere in between : Adjust the next pointer of the previous node to point to the node after the current node. Adjust the prev pointer of the next node to point to the node before the current node.
//          : Update the circular links : Ensure that the next pointer of the new tail points to the head, and the prev pointer of the new head points to the tail, maintaining the circular nature of the list.
//          : Note : Deletion can also be based on the position of the node, in addition to the value. Currently, we are implementing the deletion based on the node's value. You can try implementing deletion based on position on your own, as we've done similar tasks in the past!

// Implementing!
#include <iostream>
using namespace std;

class NodeCDLL1 {
public:
    int data;
    NodeCDLL1* next;
    NodeCDLL1* prev;

    NodeCDLL1(int data) {
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
};

// Insert a node after a given element
void insertNodeCDLL1(NodeCDLL1* &tail, int element, int data) {
    NodeCDLL1* newNode = new NodeCDLL1(data);

    // Case 1: Empty List
    if (tail == NULL) {
        tail = newNode;
        newNode->next = newNode;
        newNode->prev = newNode;
        return; // No need to delete the node here, it's part of the list
    }

    NodeCDLL1* temp = tail->next;
    
    do {
        if (temp->data == element) {
            newNode->next = temp->next;
            temp->next->prev = newNode;
            temp->next = newNode;
            newNode->prev = temp;

            if (temp == tail) {
                tail = newNode;
            }
            break;
        }
        temp = temp->next;
    } while (temp != tail->next);

    // If element not found in the list
    cout << "Element " << element << " not found in the list!" << endl;
    delete newNode; // Prevent memory leak if the node couldn't be inserted
}

void deleteNodeCDLL1(NodeCDLL1* &tail, int value) {
    if (tail == NULL) {
        cout << "Empty List! Cannot delete node." << endl;
        return;
    }

    NodeCDLL1* prev = tail;
    NodeCDLL1* curr = tail->next;
    
    do {
        if (curr->data == value) {
            // Case 1: Only one node in the list
            if (curr == tail && curr->next == curr) {
                delete curr;
                tail = NULL;
                break;
            }
            // Case 2: Deleting any other node
            prev->next = curr->next;
            curr->next->prev = prev;

            // If the node to delete is the tail node, update the tail
            if (curr == tail) {
                tail = prev;
            }
            delete curr;
            break;
        }
        prev = curr;
        curr = curr->next;
    } while (curr != tail->next);

    // If element not found
    cout << "Element " << value << " not found in the list!" << endl;
}

// Print the list
void printListCDLL1(NodeCDLL1* tail) {
    if (tail == NULL) {
        cout << "List is empty!" << endl;
        return;
    }

    NodeCDLL1* current = tail->next;
    do {
        cout << current->data << " ";
        current = current->next;
    } while (current != tail->next);
    cout << endl;
}

int main() {
    NodeCDLL1* tail = NULL;

    // Inserting elements into the empty list
    cout << "Inserting 10 in empty list:" << endl;
    insertNodeCDLL1(tail, -1, 10); // Insert 10 in an empty list (no element)
    printListCDLL1(tail);

    // Insert 20 after 10
    cout << "\nInserting 20 after 10:" << endl;
    insertNodeCDLL1(tail, 10, 20);
    printListCDLL1(tail);

    // Insert 30 after 20
    cout << "\nInserting 30 after 20:" << endl;
    insertNodeCDLL1(tail, 20, 30);
    printListCDLL1(tail);

    // Insert 15 after 10
    cout << "\nInserting 15 after 10:" << endl;
    insertNodeCDLL1(tail, 10, 15);
    printListCDLL1(tail);

    // Insert 25 after 20
    cout << "\nInserting 25 after 20:" << endl;
    insertNodeCDLL1(tail, 20, 25);
    printListCDLL1(tail);

    // Trying to insert after a non-existing element (50)
    cout << "\nInserting 50 after non-existing element 50:" << endl;
    insertNodeCDLL1(tail, 50, 50); // Should print "Element 50 not found in the list!"
    printListCDLL1(tail);

    // Deleting node with value 10 (it is the first node now)
    cout << "\nDeleting node with value 10:" << endl;
    deleteNodeCDLL1(tail, 10);
    printListCDLL1(tail);

    // Deleting node with value 30 (it is the last node now)
    cout << "\nDeleting node with value 30:" << endl;
    deleteNodeCDLL1(tail, 30);
    printListCDLL1(tail);

    // Deleting node with value 20
    cout << "\nDeleting node with value 20:" << endl;
    deleteNodeCDLL1(tail, 20);
    printListCDLL1(tail);

    // Deleting the node with value 25 (tail node)
    cout << "\nDeleting node with value 25 (tail):" << endl;
    deleteNodeCDLL1(tail, 25);
    printListCDLL1(tail);

    // Deleting the only remaining node (tail == NULL)
    cout << "\nDeleting the last remaining node:" << endl;
    deleteNodeCDLL1(tail, 15);
    printListCDLL1(tail);

    // Trying to delete from an empty list
    cout << "\nDeleting from an empty list:" << endl;
    deleteNodeCDLL1(tail, 15); // Should print "Empty List! Cannot delete node."
    printListCDLL1(tail);

    return 0;
}
// Rest you can learn and understand more by implementing them again and again in different ways! and solving variety of questions!

// ---------------------------------------------------------- LECTURE 45 - Linked Lists Questions --------------------------------------------------------------------------------------------------------->
// Question 1 : Reverse a Linkedlist!
// Iterative Approach : To reverse a linked list, we do not move the nodes themselves, but rather reverse the links between them. Suppose we have a linked list : [3 → address of next node] → [4 → address of next node] → [5 → address of next node] → [6 → address of next node] → [7 → NULL]
//                    : Here, the first node (3) is the head, and the last node (7) is the tail. Instead of shifting elements as we do in arrays, we will reverse the direction of the links so that each node points to its previous node instead of the next one.
//                    : Initialize Three Pointers : prev → Initially set to NULL, as the new last node will point to NULL.
//                                                : curr → Points to the current node, starting at head.
//                                                : forward → Stores curr->next to avoid losing track of the remaining list.
//                    : Reverse the Links Iteratively : Set curr->next = prev to reverse the link.
//                                                    : Move prev one step forward (prev = curr).
//                                                    : Move curr one step forward (curr = forward).
//                    : Continue Until curr Becomes NULL : At this point, prev will be pointing to the new head (which was previously the tail).
//                                                       : Return prev as the new head of the reversed linked list.
// Implementation!
#include<iostream>
using namespace std;

class NodeSLL6 {
    public:
    int data;
    NodeSLL6* next;

    NodeSLL6(int data) {
        this->data = data;
        this->next = NULL;
    }
};

void insertAtHeadSLL6(NodeSLL6* &head, int data) {
    NodeSLL6* newNode = new NodeSLL6(data);
    if(head == NULL) {
        head = newNode;
        return;
    }
    newNode->next = head;
    head = newNode;
    return;
}

void insertAtTailSLL6(NodeSLL6* &head, NodeSLL6* &tail, int data) {
    NodeSLL6* newNode = new NodeSLL6(data);
    if(tail == NULL) {
        head = newNode;
        tail = newNode;
        return;
    }
    tail->next = newNode;
    tail = newNode;
    return;
}

int getLenSLL6(NodeSLL6* head) {
    if(head == NULL) {
        cout<<"Empty List!";
        return -1;
    }
    int len = 0;
    NodeSLL6* temp = head;
    while(temp != NULL) {
        len++;
        temp = temp->next;
    }
    return len;
}

void insertAnywhereSLL6(NodeSLL6* &head, NodeSLL6* &tail, int pos, int data) {
    NodeSLL6* newNode = new NodeSLL6(data);
    if(head == NULL) {
        head = newNode;
        tail = newNode;
        return;
    }

    int len = getLenSLL6(head);
    if(pos < 1 || pos > len + 1) {
        cout<<"Invalid position!";
        delete newNode;
        return;
    }

    if(pos == 1) {
        insertAtHeadSLL6(head, data);
        delete newNode;
        return;
    }

    NodeSLL6* temp = head;
    int count = 1;
    while(count < pos - 1) {
        count++;
        temp = temp->next;
    }

    if(pos == len + 1) {
        insertAtTailSLL6(head, tail, data);
        delete newNode;
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

NodeSLL6* reverseSLL6(NodeSLL6* &head, NodeSLL6* &tail) {
    if(head == NULL || head->next == NULL) {
        return head;
    }
    NodeSLL6* prev = NULL;
    NodeSLL6* curr = head;
    NodeSLL6* forward = NULL;
    tail = head;
    while(curr != NULL) {
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    }
    head = prev;
    return head;
}

void printListSLL6(NodeSLL6* head) {
    if(head == NULL) {
        cout<<"Empty List!";
        return;
    }
    NodeSLL6* temp = head;
    while(temp != NULL) {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

int main() {
    NodeSLL6* n1 = new NodeSLL6(10);
    NodeSLL6* head = n1;
    NodeSLL6* tail = n1;

    insertAnywhereSLL6(head, tail, getLenSLL6(head) + 1, 20);
    insertAnywhereSLL6(head, tail, getLenSLL6(head) + 1, 30);
    insertAnywhereSLL6(head, tail, getLenSLL6(head) + 1, 40);
    insertAnywhereSLL6(head, tail, getLenSLL6(head) + 1, 50);
    insertAnywhereSLL6(head, tail, getLenSLL6(head) + 1, 60);
    cout<<"Current Linked List : ";
    printListSLL6(head);

    reverseSLL6(head, tail);

    cout<<"Reversed Linked List : ";
    printListSLL6(head);
} // This approach time complexity and space complexity are, T(n) = O(n) & Space Complexity : O(1).

// In the recursive approach, we handle one case at a time, set a base condition to stop recursion, and let recursion do the rest.
// Steps : Point the next of the current node to the previous node.
//       : Move prev and curr forward.
//       : Recursively call the function for the remaining list.
//       : The base case occurs when curr becomes NULL, meaning we’ve reached the end. At this point, prev holds the last node, which becomes the new head.
// Implementation!
#include<iostream>
using namespace std;

class NodeSLL7 {
    public:
    int data;
    NodeSLL7* next;

    NodeSLL7(int data) {
        this->data = data;
        this->next = NULL;
    }

    ~NodeSLL7() {
        cout<<"Value of deleted element: "<<data<<endl;
    }
};

void insertAtHeadSLL7(NodeSLL7* &head, int data) {
    NodeSLL7* newNode = new NodeSLL7(data);
    if(head == NULL) {
        head = newNode;
        return;
    }
    newNode->next = head;
    head = newNode;
    return;
}

void insertAtTailSLL7(NodeSLL7* &head, NodeSLL7* &tail, int data) {
    NodeSLL7* newNode = new NodeSLL7(data);
    if(tail == NULL) {
        head = newNode;
        tail = newNode;
        return;
    }
    tail->next = newNode;
    tail = newNode;
    return;
}

int getLenSLL7(NodeSLL7* head) {
    if(head == NULL) {
        cout << "Empty List!";
        return -1;
    }
    int len = 0;
    NodeSLL7* temp = head;
    while(temp != NULL) {
        len++;
        temp = temp->next;
    }
    return len;
}

void insertAnywhereSLL7(NodeSLL7* &head, NodeSLL7* &tail, int pos, int data) {
    NodeSLL7* newNode = new NodeSLL7(data);
    if(head == NULL) {
        head = newNode;
        tail = newNode;
        return;
    }

    int len = getLenSLL7(head);
    if(pos < 1 || pos > len + 1) {
        cout << "Invalid position!";
        delete newNode;
        return;
    }

    if(pos == 1) {
        insertAtHeadSLL7(head, data);
        delete newNode;
        return;
    }

    NodeSLL7* temp = head;
    int count = 1;
    while(count < pos - 1) {
        count++;
        temp = temp->next;
    }

    if(pos == len + 1) {
        insertAtTailSLL7(head, tail, data);
        delete newNode;
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

void reverseSLL7(NodeSLL7* &head, NodeSLL7* &tail, NodeSLL7* curr, NodeSLL7* prev) {
    // Base case
    if(curr == NULL) {
        tail = head;
        head = prev;
        return;
    }
    NodeSLL7* forward = curr->next;
    reverseSLL7(head, tail, forward, curr);
    curr->next = prev;
}

NodeSLL7* ReversedLinkedListSLL7(NodeSLL7* &head, NodeSLL7* &tail) {
    if(head == NULL || head->next == NULL) {
        return head;
    }

    NodeSLL7* curr = head;
    NodeSLL7* prev = NULL;
    reverseSLL7(head, tail, curr, prev); 
    return head;
}

void printListSLL7(NodeSLL7* head) { 
    if(head == NULL) {
        cout << "Empty List!";
        return;
    }
    NodeSLL7* temp = head;
    while(temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    NodeSLL7* n1 = new NodeSLL7(10);
    NodeSLL7* head = n1;
    NodeSLL7* tail = n1;

    insertAnywhereSLL7(head, tail, getLenSLL7(head) + 1, 20);
    insertAnywhereSLL7(head, tail, getLenSLL7(head) + 1, 30);
    insertAnywhereSLL7(head, tail, getLenSLL7(head) + 1, 40);
    insertAnywhereSLL7(head, tail, getLenSLL7(head) + 1, 50);
    insertAnywhereSLL7(head, tail, getLenSLL7(head) + 1, 60);
    
    cout << "Current Linked List : ";
    printListSLL7(head);

    ReversedLinkedListSLL7(head, tail);

    cout << "Reversed Linked List : ";
    printListSLL7(head);
} // So here the time complexity is again the same O(n) and space complexity is O(n)!

// Question 2 : Find middle node of the linkedlist!
// Approach 1 : So what we will do is we will find the length of the list! and then we will calculate the middle node! in case of odd length, the middle node vo hoga jo ekdum beech me hai! and in case of even length, middle node 2 honge toh unme se hum iss question ke liye right vaala consider krenge! now lets understand the rest of it through code...
#include<iostream>
using namespace std;

class NodeSLL8 {
    public:
    int data;
    NodeSLL8* next;

    NodeSLL8(int data) {
        this->data = data;
        this->next = NULL;
    }

    ~NodeSLL8() {
        cout << "Value of deleted element: " << data << endl;
    }
};

void insertAtHeadSLL8(NodeSLL8* &head, int data) {
    NodeSLL8* newNode = new NodeSLL8(data);
    if(head == NULL) {
        head = newNode;
        return;
    }
    newNode->next = head;
    head = newNode;
    return;
}

void insertAtTailSLL8(NodeSLL8* &head, NodeSLL8* &tail, int data) {
    NodeSLL8* newNode = new NodeSLL8(data);
    if(tail == NULL) {
        head = newNode;
        tail = newNode;
        return;
    }
    tail->next = newNode;
    tail = newNode;
    return;
}

int getLenSLL8(NodeSLL8* head) {
    if(head == NULL) {
        cout << "Empty List!";
        return -1;
    }
    int len = 0;
    NodeSLL8* temp = head;
    while(temp != NULL) {
        len++;
        temp = temp->next;
    }
    return len;
}

void insertAnywhereSLL8(NodeSLL8* &head, NodeSLL8* &tail, int pos, int data) {
    NodeSLL8* newNode = new NodeSLL8(data);
    if(head == NULL) {
        head = newNode;
        tail = newNode;
        return;
    }

    int len = getLenSLL8(head);
    if(pos < 1 || pos > len + 1) {
        cout << "Invalid position!";
        delete newNode;
        return;
    }

    if(pos == 1) {
        insertAtHeadSLL8(head, data);
        delete newNode;
        return;
    }

    NodeSLL8* temp = head;
    int count = 1;
    while(count < pos - 1) {
        count++;
        temp = temp->next;
    }

    if(pos == len + 1) {
        insertAtTailSLL8(head, tail, data);
        delete newNode;
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

NodeSLL8* findMiddleNodeSLL8(NodeSLL8* head) {
    int len = getLenSLL8(head);
    int mid = len / 2;
    NodeSLL8* temp = head;
    int cnt = 0;
    while(cnt < mid) {
        temp = temp->next;
        cnt++;
    }
    return temp;
}

void printListSLL8(NodeSLL8* head) { 
    if(head == NULL) {
        cout << "Empty List!";
        return;
    }
    NodeSLL8* temp = head;
    while(temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    NodeSLL8* n1 = new NodeSLL8(10);
    NodeSLL8* head = n1;
    NodeSLL8* tail = n1;

    insertAnywhereSLL8(head, tail, getLenSLL8(head) + 1, 20);
    insertAnywhereSLL8(head, tail, getLenSLL8(head) + 1, 30);
    insertAnywhereSLL8(head, tail, getLenSLL8(head) + 1, 40);
    insertAnywhereSLL8(head, tail, getLenSLL8(head) + 1, 50);
    insertAnywhereSLL8(head, tail, getLenSLL8(head) + 1, 60);
    
    cout << "Current Linked List : ";
    printListSLL8(head);
    
    NodeSLL8* middleNode = findMiddleNodeSLL8(head);
    cout << "Middle Node: " << middleNode->data << endl;

    cout<<endl;

    NodeSLL8* n2 = new NodeSLL8(10);
    NodeSLL8* head2 = n2;
    NodeSLL8* tail2 = n2;

    insertAnywhereSLL8(head2, tail2, getLenSLL8(head2) + 1, 20);
    insertAnywhereSLL8(head2, tail2, getLenSLL8(head2) + 1, 30);
    insertAnywhereSLL8(head2, tail2, getLenSLL8(head2) + 1, 40);
    insertAnywhereSLL8(head2, tail2, getLenSLL8(head2) + 1, 50);
    insertAnywhereSLL8(head2, tail2, getLenSLL8(head2) + 1, 60);
    insertAnywhereSLL8(head2, tail2, getLenSLL8(head2) + 1, 70);
    
    cout << "Current Linked List : ";
    printListSLL8(head2);
    
    NodeSLL8* middleNode2 = findMiddleNodeSLL8(head2);
    cout << "Middle Node: " << middleNode2->data << endl;
    
    return 0;
}
// Time Complexity: T(n) + T(n/2); Here T(n) for the getlength function and T(n/2) for the loop in findMiddleNode.
// So, the overall time complexity is O(n).
// However, we observe that we traverse the list once completely and then only halfway. Let's explore an optimized solution based on this observation...

// Optimized Approach : Concept : Imagine two people : Fast person runs 2 meters/sec, Slow person runs 1 meter/sec
//                              : In 5 seconds, the fast person covers 10 meters, while the slow one covers 5 meters (half of the total distance).
//                              : We use this analogy to find the middle node in a linked list using two pointers : Slow pointer moves one step at a time. Fast pointer moves two steps at a time.
//                    : Algorithm : Edge cases : If the list is empty → return NULL. If the list has one node → return head. If the list has two nodes → return head->next.
//                                : Initialize : slow = head, fast = head->next. (or fast = head, in this case the loop condition will change slightly!)
//                                             : Traverse the list : Move slow one step forward.
//                                                                 : Move fast two steps forward.
//                                                                 : Stop when fast reaches NULL.
//                                                                 : Return slow (middle node).
// Implementation!
#include<iostream>
using namespace std;

class NodeSLL9 {
    public:
    int data;
    NodeSLL9* next;

    NodeSLL9(int data) {
        this->data = data;
        this->next = NULL;
    }

    ~NodeSLL9() {
        cout << "Value of deleted element: " << data << endl;
    }
};

void insertAtTailSLL9(NodeSLL9* &head, NodeSLL9* &tail, int data) {
    NodeSLL9* newNode = new NodeSLL9(data);
    if(tail == NULL) {
        head = newNode;
        tail = newNode;
        return;
    }
    tail->next = newNode;
    tail = newNode;
}

int getLenSLL9(NodeSLL9* head) {
    int len = 0;
    NodeSLL9* temp = head;
    while(temp != NULL) {
        len++;
        temp = temp->next;
    }
    return len;
}

NodeSLL9* findMiddleNodeSLL9A(NodeSLL9* head) { // Alternatively : "while(fast != NULL && fast->next != NULL)" for manage even number of nodes differently!
    if(head == NULL || head->next == NULL) {
        return head;
    }
    NodeSLL9* slow = head;
    NodeSLL9* fast = head->next;
    while(fast != NULL) {
        fast = fast->next;
        if(fast != NULL) {
            fast = fast->next;
        }
        slow = slow->next;
    }
    return slow;
}

NodeSLL9* findMiddleNodeSLL9B(NodeSLL9* head) {
    if(head == NULL || head->next == NULL) {
        return head;
    }
    NodeSLL9* slow = head;
    NodeSLL9* fast = head;
    while(fast != NULL && fast->next != NULL) {
        fast = fast->next;
        if(fast != NULL) {
            fast = fast->next;
        }
        slow = slow->next;
    }
    return slow;
}

void printListSLL9(NodeSLL9* head) { 
    if(head == NULL) {
        cout << "Empty List!";
        return;
    }
    NodeSLL9* temp = head;
    while(temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    NodeSLL9* n1 = new NodeSLL9(10);
    NodeSLL9* head = n1;
    NodeSLL9* tail = n1;

    insertAtTailSLL9(head, tail, 20);
    insertAtTailSLL9(head, tail, 30);
    insertAtTailSLL9(head, tail, 40);
    insertAtTailSLL9(head, tail, 50);
    insertAtTailSLL9(head, tail, 60);
    
    cout << "Current Linked List: ";
    printListSLL9(head);
    
    NodeSLL9* middleNodeA1 = findMiddleNodeSLL9A(head);
    cout << "Middle Node (Method 1): " << middleNodeA1->data << endl;

    NodeSLL9* middleNodeB1 = findMiddleNodeSLL9B(head);
    cout << "Middle Node (Method 2): " << middleNodeB1->data << endl;

    cout << endl;

    NodeSLL9* n2 = new NodeSLL9(10);
    NodeSLL9* head2 = n2;
    NodeSLL9* tail2 = n2;

    insertAtTailSLL9(head2, tail2, 20);
    insertAtTailSLL9(head2, tail2, 30);
    insertAtTailSLL9(head2, tail2, 40);
    insertAtTailSLL9(head2, tail2, 50);
    insertAtTailSLL9(head2, tail2, 60);
    insertAtTailSLL9(head2, tail2, 70);

    cout << "Current Linked List: ";
    printListSLL9(head2);

    NodeSLL9* middleNodeA2 = findMiddleNodeSLL9A(head2);
    cout << "Middle Node (Method 1): " << middleNodeA2->data << endl;

    NodeSLL9* middleNodeB2 = findMiddleNodeSLL9B(head2);
    cout << "Middle Node (Method 2): " << middleNodeB2->data << endl;

    return 0;
} // Hence, TC : O(n) and SC : O(1)

// ---------------------------------------------------------- LECTURE 46 - Linked Lists Questions --------------------------------------------------------------------------------------------------------->
// Question 1 : Reverse the Linkedlist in the groups of K
// Example : Input : 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> NULL, with K = 2
//         : Output : 3 -> 2 -> 5 -> 4 -> 7 -> 6 -> NULL
// Approach : Reverse the first K nodes iteratively : Swap links between K nodes.
//          : Recursively process the remaining list : The head of the next reversed group is obtained using recursion. and Link the reversed K-group to the next recursively solved group.
// Implementation!
#include<iostream>
using namespace std;

class NodeSLL10 {
    public:
    int data;
    NodeSLL10* next;

    NodeSLL10(int data) {
        this->data = data;
        this->next = NULL;
    }

    ~NodeSLL10() {
        cout << "Value of deleted element: " << data << endl;
    }
};

void insertAtTailSLL10(NodeSLL10* &head, NodeSLL10* &tail, int data) {
    NodeSLL10* newNode = new NodeSLL10(data);
    if(tail == NULL) {
        head = newNode;
        tail = newNode;
        return;
    }
    tail->next = newNode;
    tail = newNode;
    return;
}

NodeSLL10* ReverseK(NodeSLL10* head, int K) {
    if(head == NULL) {
        return NULL;
    }
    NodeSLL10* prev = NULL;
    NodeSLL10* curr = head;
    NodeSLL10* next = NULL;
    int count = 0;
    while(curr != NULL && count < K) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        count++;
    }
    if(next != NULL) {
        head->next = ReverseK(next, K);
    }
    return prev;
}

void printListSLL10(NodeSLL10* head) { 
    if(head == NULL) {
        cout << "Empty List!";
        return;
    }
    NodeSLL10* temp = head;
    while(temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    NodeSLL10* n1 = new NodeSLL10(10);
    NodeSLL10* head = n1;
    NodeSLL10* tail = n1;

    insertAtTailSLL10(head, tail, 20);
    insertAtTailSLL10(head, tail, 30);
    insertAtTailSLL10(head, tail, 40);
    insertAtTailSLL10(head, tail, 50);
    insertAtTailSLL10(head, tail, 60);
    
    cout << "Current Linked List: ";
    printListSLL10(head);

    cout<<"Enter you value of K : ";
    int k;
    cin>>k;
    NodeSLL10* reversedK = ReverseK(head, k);
    cout << "Current Linked List: ";
    printListSLL10(reversedK);

    return 0;
} // Time Complexity (TC) : Each node is visited only once, so for n nodes, TC = O(n).
// Space Complexity (SC) : Recursive calls reverse K nodes at a time, requiring n/K recursive calls. Since each call uses O(K) space, total space used is O(n).

// Question 2 : Check whether a LinkedList is Circular or Not.
// Approach : Base Cases : If the list is empty, return true (considered circular). If there is only one node, check head->next. If it's NULL, return false; if it points to head, return true.
//          : General Case (More than 1 node) : Use a pointer (temp) starting from head->next (to avoid counting head twice). Traverse the list until temp becomes head or NULL. If temp == head, it's circular; otherwise, it's not.
#include<iostream>
using namespace std;

// Node class for both Circular and Singly Linked Lists
class GeneralNodeLL {
public:
    int data;
    GeneralNodeLL* next;

    GeneralNodeLL(int data) {
        this->data = data;
        this->next = NULL;
    }

    ~GeneralNodeLL() {
        cout << "Memory freed for node with value: " << data << endl;
    }
};

// Insert into Circular Linked List
void insertCircularLL(GeneralNodeLL*& tail, int element, int data) {
    GeneralNodeLL* newNode = new GeneralNodeLL(data);

    if (tail == NULL) {
        tail = newNode;
        newNode->next = newNode;
        return;
    }

    GeneralNodeLL* current = tail;
    do {
        if (current->data == element) {
            newNode->next = current->next;
            current->next = newNode;
            if (current == tail) {
                tail = newNode; // Update tail if inserting after the last node
            }
            return;
        }
        current = current->next;
    } while (current != tail);

    cout << "Element " << element << " not found in the list!" << endl;
    delete newNode; // Prevent memory leak
}

// Insert into Singly Linked List at the Tail
void insertSinglyLL(GeneralNodeLL*& head, GeneralNodeLL*& tail, int data) {
    GeneralNodeLL* newNode = new GeneralNodeLL(data);
    if(tail == NULL) {
        head = newNode;
        tail = newNode;
        return;
    }
    tail->next = newNode;
    tail = newNode;
    return;
}

// Check if Linked List is Circular
bool checkCircularLL(GeneralNodeLL* head) {
    if (head == NULL) return false;

    GeneralNodeLL* temp = head->next;
    while (temp != NULL && temp != head) {
        temp = temp->next;
    }
    if(temp == head) {
        return true;
    }
    else {
        return false;
    }
}

// Print Linked List
void printLinkedList(GeneralNodeLL* head) {
    if (head == NULL) {
        cout << "Empty List!" << endl;
        return;
    }
    GeneralNodeLL* temp = head;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != NULL && temp != head); // Handles both circular and singly LL
    cout << endl;
}

int main() {
    // Creating Circular Linked List
    GeneralNodeLL* tailC = NULL;
    insertCircularLL(tailC, -1, 10);
    insertCircularLL(tailC, 10, 20);
    insertCircularLL(tailC, 20, 30);
    insertCircularLL(tailC, 30, 40);
    insertCircularLL(tailC, 40, 50);
    insertCircularLL(tailC, 50, 60);
    cout << "Circular Linked List: ";
    printLinkedList(tailC);

    // Checking if Circular Linked List is Circular
    if (checkCircularLL(tailC)) {
        cout << "It is a Circular Linked List!" << endl;
    } else {
        cout << "It is NOT a Circular Linked List!" << endl;
    }

    cout << endl;

    // Creating Singly Linked List
    GeneralNodeLL* headS = NULL;
    GeneralNodeLL* tailS = NULL;
    insertSinglyLL(headS, tailS, 5);
    insertSinglyLL(headS, tailS, 15);
    insertSinglyLL(headS, tailS, 25);
    insertSinglyLL(headS, tailS, 35);
    insertSinglyLL(headS, tailS, 45);
    insertSinglyLL(headS, tailS, 55);
    cout << "Singly Linked List: ";
    printLinkedList(headS);

    // Checking if Singly Linked List is Circular
    if (checkCircularLL(headS)) {
        cout << "It is a Circular Linked List!" << endl;
    } else {
        cout << "It is NOT a Circular Linked List!" << endl;
    }

    return 0;
} // Time Complexity : O(n) – We traverse the entire list (n nodes).
// Space Complexity : O(1) – No extra space is used.
// Another Approach : Another approach is using Maps. Since maps store data as key-value pairs, we can mark each visited node as true while traversing. If we encounter a node that is already marked true, the list is circular; otherwise, it is not.
//                  : Although, its not the best approach, as it will require an extra space to store the boolean values!

// ---------------------------------------------------------- LECTURE 47 - Detect & Remove Loop Question in LL --------------------------------------------------------------------------------------------------------->
// Loop Detection and Removal in Linked List!
// It is divided into three parts : Detect the Loop : Check whether the linked list contains a cycle.
//                                : Find the Starting Node of the Loop : Identify the exact node where the loop begins.
//                                : Remove the Loop : Break the cycle to restore the linked list to a linear structure.

// Understanding Loops in a Linked List!
// A loop in a linked list occurs when a node points back to a previous node instead of NULL. This causes the list to cycle indefinitely when traversed.
// There are two main cases of loops : Case 1 : A node somewhere in the middle of the list points back to a previous node, forming a cycle.
//                                   : Case 2 : A circular linked list, where the last node connects back to the first node, forming a full cycle.
// Our goal is to detect if a cycle exists, identify where it starts, and then remove it so that the linked list functions normally.
// Implementation!
#include <iostream>
#include <map>
using namespace std;

// Node class for both Circular and Singly Linked Lists
class GeneralNodeLL2 {
public:
    int data;
    GeneralNodeLL2* next;

    GeneralNodeLL2(int data) {
        this->data = data;
        this->next = NULL;
    }

    ~GeneralNodeLL2() {
        cout << "Memory freed for node with value: " << data << endl;
    }
};

// Insert into Circular Linked List
void insertCircularLL2(GeneralNodeLL2*& tail, int element, int data) {
    GeneralNodeLL2* newNode = new GeneralNodeLL2(data);

    if (tail == NULL) {
        tail = newNode;
        newNode->next = newNode;
        return;
    }

    GeneralNodeLL2* current = tail;
    do {
        if (current->data == element) {
            newNode->next = current->next;
            current->next = newNode;
            if (current == tail) {
                tail = newNode;
            }
            return;
        }
        current = current->next;
    } while (current != tail);

    cout << "Element " << element << " not found in the list!" << endl;
    delete newNode;
}

// Insert into Singly Linked List at Tail
void insertSinglyLL2(GeneralNodeLL2*& head, GeneralNodeLL2*& tail, int data) {
    GeneralNodeLL2* newNode = new GeneralNodeLL2(data);
    if (tail == NULL) {
        head = newNode;
        tail = newNode;
        return;
    }
    tail->next = newNode;
    tail = newNode;
}

// Check if a Linked List is Circular
bool checkCircularLL2(GeneralNodeLL2* head) {
    if (head == NULL) return false;

    GeneralNodeLL2* temp = head->next;
    while (temp != NULL && temp != head) {
        temp = temp->next;
    }
    return (temp == head);
}

// Detect Loop using Map (Extra Space O(N))
bool detectLoopWithMaps(GeneralNodeLL2* head) {
    if (head == NULL) return false;

    map<GeneralNodeLL2*, bool> visited;
    GeneralNodeLL2* temp = head;

    while (temp != NULL) {
        if (visited[temp] == true) {
            return true; // Loop detected
        }
        visited[temp] = true;
        temp = temp->next;
    }
    return false;
}

// Print a Linked List
void printLinkedList2(GeneralNodeLL2* head) {
    if (head == NULL) {
        cout << "Empty List!" << endl;
        return;
    }
    GeneralNodeLL2* temp = head;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != NULL && temp != head);
    cout << endl;
}

int main() {
    GeneralNodeLL2* tailC = NULL;
    insertCircularLL2(tailC, -1, 10);
    insertCircularLL2(tailC, 10, 20);
    insertCircularLL2(tailC, 20, 30);
    insertCircularLL2(tailC, 30, 40);
    insertCircularLL2(tailC, 40, 50);
    insertCircularLL2(tailC, 50, 60);
    cout << "Circular Linked List : ";
    printLinkedList2(tailC);

    cout << (checkCircularLL2(tailC) ? "It is a Circular Linked List!" : "It is NOT a Circular Linked List!") << endl;
    cout << (detectLoopWithMaps(tailC) ? "Loop detected!" : "No Loop detected!") << endl;

    cout<<endl;

    GeneralNodeLL2* headS = NULL;
    GeneralNodeLL2* tailS = NULL;
    insertSinglyLL2(headS, tailS, 5);
    insertSinglyLL2(headS, tailS, 15);
    insertSinglyLL2(headS, tailS, 25);
    insertSinglyLL2(headS, tailS, 35);
    insertSinglyLL2(headS, tailS, 45);
    insertSinglyLL2(headS, tailS, 55);
    cout << "Singly Linked List : ";
    printLinkedList2(headS);

    cout << (checkCircularLL2(headS) ? "It is a Circular Linked List!" : "It is NOT a Circular Linked List!") << endl;
    cout << (detectLoopWithMaps(headS) ? "Loop detected!" : "No Loop detected!") << endl;

    cout<<endl;

    GeneralNodeLL2* headS2 = NULL;
    GeneralNodeLL2* tailS2 = NULL;
    insertSinglyLL2(headS2, tailS2, 100);
    insertSinglyLL2(headS2, tailS2, 200);
    insertSinglyLL2(headS2, tailS2, 300);
    insertSinglyLL2(headS2, tailS2, 400);
    insertSinglyLL2(headS2, tailS2, 500);
    insertSinglyLL2(headS2, tailS2, 600);

    GeneralNodeLL2* temp = headS2; // Adding an Inside Loop!
    while (temp != NULL) {
        if (temp->data == 300) {
            tailS2->next = temp;
            break;
        }
        temp = temp->next;
    }
    // cout << "Singly Linked List : ";
    // printLinkedList(headS2); // Here this printLinkedList() is designed to print a LL which either circular or singly! not for inside loop! Hence, it will print Infinite LL!
    cout<<"Linked List with Inside Loop at : 300"<<endl;
    // cout << (checkCircularLL(headS2) ? "It is a Circular Linked List!" : "It is NOT a Circular Linked List!") << endl; // Similarly this checkCircularLL() func is also designed for circular loops, hence, this won't work as we think!
    cout << (detectLoopWithMaps(headS2) ? "Loop detected!" : "No Loop detected!") << endl;

    return 0;
}
// Learning Note : checkCircularLL() Function : Purpose : Designed only for Circular Linked Lists.
//                                            : Limitation : It cannot detect an inside loop in a singly linked list; it only verifies if a given list is circular.
//                                            : Usage : Best suited for checking if a linked list is completely circular (i.e., the last node connects back to the head).
//               : detectLoopWithMaps() Function : Purpose : A general-purpose loop detection function that detects : Inside loops in a singly linked list, A fully circular linked list, Cases where no loop exists.
//                                               : Working : Uses a hash map to track visited nodes.
//                                               : Complexity : Time Complexity: O(n) and Space Complexity: O(n) (due to extra storage for tracking visited nodes)
//               : Why doesn’t checkCircularLL() work for inside loops? checkCircularLL() checks only if a list is completely circular by seeing if traversal reaches the head again. If there's an inside loop (somewhere in the middle, not connecting to the head), this function won’t detect it.
//               : Optimized Approach : Floyd’s Cycle Detection Algorithm (Tortoise and Hare Algorithm)

// Optimized Approach : Floyd’s Cycle Detection Algorithm (Tortoise and Hare Algorithm)
// Approach : Imagine two people running on a circular track : Tortoise (slow pointer) moves one step at a time and Hare (fast pointer) moves two steps at a time.
//                                                           : If the track is a straight path, the hare will reach the end, and there’s no loop. If the track is circular (i.e., there’s a loop), the hare will eventually catch up to the tortoise inside the loop.
//          : Steps of the Algorithm : Start two pointers : slow = head (moves 1 step at a time) and fast = head (moves 2 steps at a time)
//                                   : Move both pointers : slow = slow->next and fast = fast->next->next
//                                   : Check for a loop : If fast becomes NULL, the list has no loop and If slow == fast, there is a loop.
//          : Why Does This Work? Since the fast pointer moves twice as fast, it either reaches NULL (no loop) or enters the loop and catches up with slow and This happens because the distance between fast and slow reduces every step.
//          : Time and Space Complexity : Time Complexity : O(n) (At most n steps before detection) and Space Complexity: O(1) (No extra memory used)
//          : Advantages of Floyd’s Algorithm : No extra space required (unlike hash maps).
//                                            : Detects all types of loops (circular and inside loops).
//                                            : Fast and efficient (O(n) time).
// Implementation!
#include <iostream>
#include <map>
using namespace std;

// Node class for both Circular and Singly Linked Lists
class GeneralNodeLL3 {
public:
    int data;
    GeneralNodeLL3* next;

    GeneralNodeLL3(int data) {
        this->data = data;
        this->next = NULL;
    }

    ~GeneralNodeLL3() {
        cout << "Memory freed for node with value: " << data << endl;
    }
};

// Insert into Circular Linked List
void insertCircularLL3(GeneralNodeLL3*& tail, int element, int data) {
    GeneralNodeLL3* newNode = new GeneralNodeLL3(data);

    if (tail == NULL) {
        tail = newNode;
        newNode->next = newNode;
        return;
    }

    GeneralNodeLL3* current = tail;
    do {
        if (current->data == element) {
            newNode->next = current->next;
            current->next = newNode;
            if (current == tail) {
                tail = newNode;
            }
            return;
        }
        current = current->next;
    } while (current != tail);

    cout << "Element " << element << " not found in the list!" << endl;
    delete newNode;
}

// Insert into Singly Linked List at Tail
void insertSinglyLL3(GeneralNodeLL3*& head, GeneralNodeLL3*& tail, int data) {
    GeneralNodeLL3* newNode = new GeneralNodeLL3(data);
    if (tail == NULL) {
        head = newNode;
        tail = newNode;
        return;
    }
    tail->next = newNode;
    tail = newNode;
}

// Check if a Linked List is Circular
bool checkCircularLL3(GeneralNodeLL3* head) {
    if (head == NULL) return false;

    GeneralNodeLL3* temp = head->next;
    while (temp != NULL && temp != head) {
        temp = temp->next;
    }
    return (temp == head);
}

// Detect Loop using Map (Extra Space O(N))
bool detectLoopWithMaps2(GeneralNodeLL3* head) {
    if (head == NULL) return false;

    map<GeneralNodeLL3*, bool> visited;
    GeneralNodeLL3* temp = head;

    while (temp != NULL) {
        if (visited[temp] == true) {
            return true; // Loop detected
        }
        visited[temp] = true;
        temp = temp->next;
    }
    return false;
}

GeneralNodeLL3* floydLoopDetectionAlgo(GeneralNodeLL3* head) {
    // Empty List...
    if(head == NULL) {
        return NULL;
    }
    GeneralNodeLL3* fast = head;
    GeneralNodeLL3* slow = head;

    while(slow != NULL && fast != NULL) {
        fast = fast->next;
        if(fast != NULL) {
            fast = fast->next;
        }
        slow = slow->next;

        if(slow == fast) {
            return slow;
        }
    }
    return NULL;
}

// Print a Linked List
void printLinkedList3(GeneralNodeLL3* head) {
    if (head == NULL) {
        cout << "Empty List!" << endl;
        return;
    }
    GeneralNodeLL3* temp = head;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != NULL && temp != head);
    cout << endl;
}

int main() {
    GeneralNodeLL3* tailC = NULL;
    insertCircularLL3(tailC, -1, 10);
    insertCircularLL3(tailC, 10, 20);
    insertCircularLL3(tailC, 20, 30);
    insertCircularLL3(tailC, 30, 40);
    insertCircularLL3(tailC, 40, 50);
    insertCircularLL3(tailC, 50, 60);
    cout << "Circular Linked List : ";
    printLinkedList3(tailC);

    cout << "(Detect Loop using Circular LL Logic) " << (checkCircularLL3(tailC) ? "It is a Circular Linked List!" : "It is NOT a Circular Linked List!") << endl;
    cout << "(Detect Loop using Maps) " << (detectLoopWithMaps2(tailC) ? "Loop detected!" : "No Loop detected!") << endl;
    cout << "(Detect Loop using Floyd's Algo) " << (floydLoopDetectionAlgo(tailC) ? "Loop detected!" : "No Loop detected!") << endl;

    cout<<endl;

    GeneralNodeLL3* headS = NULL;
    GeneralNodeLL3* tailS = NULL;
    insertSinglyLL3(headS, tailS, 5);
    insertSinglyLL3(headS, tailS, 15);
    insertSinglyLL3(headS, tailS, 25);
    insertSinglyLL3(headS, tailS, 35);
    insertSinglyLL3(headS, tailS, 45);
    insertSinglyLL3(headS, tailS, 55);
    cout << "Singly Linked List : ";
    printLinkedList3(headS);

    cout << "(Detect Loop using Circular LL Logic) " << (checkCircularLL3(headS) ? "It is a Circular Linked List!" : "It is NOT a Circular Linked List!") << endl;
    cout << "(Detect Loop using Maps) " << (detectLoopWithMaps2(headS) ? "Loop detected!" : "No Loop detected!") << endl;
    cout << "(Detect Loop using Floyd's Algo) " << (floydLoopDetectionAlgo(headS) ? "Loop detected!" : "No Loop detected!") << endl;
    
    cout<<endl;
    
    GeneralNodeLL3* headS2 = NULL;
    GeneralNodeLL3* tailS2 = NULL;
    insertSinglyLL3(headS2, tailS2, 100);
    insertSinglyLL3(headS2, tailS2, 200);
    insertSinglyLL3(headS2, tailS2, 300);
    insertSinglyLL3(headS2, tailS2, 400);
    insertSinglyLL3(headS2, tailS2, 500);
    insertSinglyLL3(headS2, tailS2, 600);
    
    GeneralNodeLL3* temp = headS2; // Adding an Inside Loop!
    while (temp != NULL) {
        if (temp->data == 300) {
            tailS2->next = temp;
            break;
        }
        temp = temp->next;
    }
    
    cout<<"Linked List with Inside Loop at : 300"<<endl;
    // cout << "(Detect Loop using Circular LL Logic) " << (checkCircularLL3(headS2) ? "It is a Circular Linked List!" : "It is NOT a Circular Linked List!") << endl; // // Won't work here!
    cout << "(Detect Loop using Maps) " << (detectLoopWithMaps2(headS2) ? "Loop detected!" : "No Loop detected!") << endl;
    cout << "(Detect Loop using Floyd's Algo) " << (floydLoopDetectionAlgo(headS2) ? "Loop detected!" : "No Loop detected!") << endl;   
    return 0;
}

// Finding the Starting Node of a Loop in a Linked List!
// Approach : Using Floyd’s Cycle Detection Algorithm
//          : Steps : Detect the Loop using Floyd’s Cycle Detection Algorithm.
//                  : Use slow (moves 1 step) and fast (moves 2 steps).
//                  : If slow == fast, a loop exists, and they meet at an intersection point inside the loop.
//          : Find the Starting Node of the Loop : Reset slow to head, but keep fast at the intersection point.
//                                               : Move both one step at a time (slow = slow->next, fast = fast->next).
//                                               : The point where they meet again is the starting node of the loop.
//          : Why Does This Work? : The distance equation in a loop follows : A + B = K*C
//                                : Where : A = Distance from head to loop start, B = Distance from loop start to intersection, C = Length of the loop and k = Some integer.
//                                : Since both pointers now move at the same speed, they will meet at the start of the loop after covering distance A.
//          : Complexity Analysis : Time Complexity: O(n) (At most 2 passes over the list) and Space Complexity: O(1) (No extra space used)
// Implementation!
#include <iostream>
#include <map>
using namespace std;

// Node class for both Circular and Singly Linked Lists
class GeneralNodeLL4 {
    public:
    int data;
    GeneralNodeLL4* next;

    GeneralNodeLL4(int data) {
        this->data = data;
        this->next = NULL;
    }

    ~GeneralNodeLL4() {
        cout << "Memory freed for node with value: " << data << endl;
    }
};

// Insert into Circular Linked List
void insertCircularLL4(GeneralNodeLL4*& tail, int element, int data) {
    GeneralNodeLL4* newNode = new GeneralNodeLL4(data);

    if (tail == NULL) {
        tail = newNode;
        newNode->next = newNode;
        return;
    }

    GeneralNodeLL4* current = tail;
    do {
        if (current->data == element) {
            newNode->next = current->next;
            current->next = newNode;
            if (current == tail) {
                tail = newNode;
            }
            return;
        }
        current = current->next;
    } while (current != tail);

    cout << "Element " << element << " not found in the list!" << endl;
    delete newNode;
}

// Insert into Singly Linked List at Tail
void insertSinglyLL4(GeneralNodeLL4*& head, GeneralNodeLL4*& tail, int data) {
    GeneralNodeLL4* newNode = new GeneralNodeLL4(data);
    if (tail == NULL) {
        head = newNode;
        tail = newNode;
        return;
    }
    tail->next = newNode;
    tail = newNode;
}

GeneralNodeLL4* floydLoopDetectionAlgo2(GeneralNodeLL4* head) {
    // Empty List...
    if(head == NULL) {
        return NULL;
    }
    GeneralNodeLL4* fast = head;
    GeneralNodeLL4* slow = head;

    while(slow != NULL && fast != NULL) {
        fast = fast->next;
        if(fast != NULL) {
            fast = fast->next;
        }
        slow = slow->next;

        if(slow == fast) {
            return slow;
        }
    }
    return NULL;
}

GeneralNodeLL4* getStartingNode(GeneralNodeLL4* head) {
    if(head == NULL) {
        return NULL;
    }
    GeneralNodeLL4* intersection = floydLoopDetectionAlgo2(head);
    GeneralNodeLL4* slow = head;

    while(slow != intersection) {
        slow = slow->next;
        intersection = intersection -> next;
    }
    return slow; // Here in the end the slow will be pointing at the starting node of the loop!
}

// Print a Linked List
void printLinkedList4(GeneralNodeLL4* head) {
    if (head == NULL) {
        cout << "Empty List!" << endl;
        return;
    }
    GeneralNodeLL4* temp = head;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != NULL && temp != head);
    cout << endl;
}

int main() {
    GeneralNodeLL4* headS = NULL;
    GeneralNodeLL4* tailS = NULL;

    insertSinglyLL4(headS, tailS, 10);
    insertSinglyLL4(headS, tailS, 20);
    insertSinglyLL4(headS, tailS, 30);
    insertSinglyLL4(headS, tailS, 40);
    insertSinglyLL4(headS, tailS, 50);

    tailS->next = headS->next->next; // Creating a loop at node 30

    // Detect the loop
    GeneralNodeLL4* loopNode = floydLoopDetectionAlgo2(headS);
    if (loopNode) {
        cout << "Loop detected at node with value: " << loopNode->data << endl;
        GeneralNodeLL4* loopStart = getStartingNode(headS); // Find the starting node of the loop
        cout << "The loop starts at node with value: " << loopStart->data << endl;
    }
    else {
        cout << "No loop detected in the linked list!" << endl;
    }

    return 0;
}

// Removing Loop!
// We need to break the loop that we detected using Floyd’s Cycle Detection Algorithm.
// Idea : We find the starting node of the loop. -> Then, we move inside the loop until we reach the node just before the starting node. -> We change its next pointer to NULL, effectively breaking the cycle.
// Approach : Detect the Loop (Using Floyd’s Algorithm) : If a loop exists, slow and fast will meet at some node inside the loop.
//          : Find the Starting Node of the Loop : Now, slow is at the node where the loop starts. For our example (10 → 20 → 30 → 40 → 50 → 30...), this function will return 30.
//          : Remove the Loop : To remove the loop we do the following, Traverse the loop starting from loopStart -> Stop at the node just before the loop starts -> Set its next pointer to NULL, breaking the loop.
//                            : We effectively "disconnect" the last node of the loop from pointing back into the cycle.
// Implementation!
#include <iostream>
using namespace std;

class GeneralNodeLL5 {
public:
    int data;
    GeneralNodeLL5* next;

    GeneralNodeLL5(int data) {
        this->data = data;
        this->next = NULL;
    }
};

// Insert at Tail for Singly Linked List
void insertSinglyLL5(GeneralNodeLL5*& head, GeneralNodeLL5*& tail, int data) {
    GeneralNodeLL5* newNode = new GeneralNodeLL5(data);
    if (tail == NULL) {
        head = newNode;
        tail = newNode;
        return;
    }
    tail->next = newNode;
    tail = newNode;
}

// Detect Loop using Floyd’s Algorithm
GeneralNodeLL5* floydLoopDetectionAlgo3(GeneralNodeLL5* head) {
    if (head == NULL) return NULL;

    GeneralNodeLL5* slow = head;
    GeneralNodeLL5* fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) return slow;
    }
    return NULL;
}

// Find the Starting Node of the Loop
GeneralNodeLL5* getStartingNode2(GeneralNodeLL5* head) {
    if (head == NULL) return NULL;

    GeneralNodeLL5* intersection = floydLoopDetectionAlgo3(head);
    if (intersection == NULL) return NULL;

    GeneralNodeLL5* slow = head;

    while (slow != intersection) {
        slow = slow->next;
        intersection = intersection->next;
    }
    return slow;
}

// Remove Loop from the Linked List
void removeLoop(GeneralNodeLL5* head) {
    if (head == NULL) return;

    GeneralNodeLL5* loopStart = getStartingNode2(head);
    if (loopStart == NULL) return;

    GeneralNodeLL5* temp = loopStart;

    while (temp->next != loopStart) {
        temp = temp->next;
    }

    temp->next = NULL;
}

// Print the Linked List
void printLinkedList5(GeneralNodeLL5* head) {
    if (head == NULL) {
        cout << "Empty List!" << endl;
        return;
    }
    GeneralNodeLL5* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Main Function
int main() {
    GeneralNodeLL5* headS = NULL;
    GeneralNodeLL5* tailS = NULL;

    insertSinglyLL5(headS, tailS, 10);
    insertSinglyLL5(headS, tailS, 20);
    insertSinglyLL5(headS, tailS, 30);
    insertSinglyLL5(headS, tailS, 40);
    insertSinglyLL5(headS, tailS, 50);

    tailS->next = headS->next->next; // Creating a loop at node 30
    cout<<"Tail next (Before Removal) : "<<tailS->next->data<<endl;

    // Detect Loop
    GeneralNodeLL5* loopNode = floydLoopDetectionAlgo3(headS);
    if (loopNode) {
        cout << "Loop detected at node with value : " << loopNode->data << endl;
        GeneralNodeLL5* loopStart = getStartingNode2(headS);
        cout << "The loop starts at node with value : " << loopStart->data << endl;

        // Remove the loop
        removeLoop(headS);
        cout << "Loop removed. Linked List after loop removal : ";
        printLinkedList5(headS);
        cout << "Tail next (After Removal) : " << (tailS->next == NULL ? "null" : to_string(tailS->next->data)) << endl;
    }
    else {
        cout << "No loop detected!" << endl;
    }
    return 0;
}

// ---------------------------------------------------------- LECTURE 48 - Remove Duplicates from sorted/unsorted Linkedlists! --------------------------------------------------------------------------------------------------------->
// Question 1 : Suppose a linkedlist 10->20->20->30->30->30->30->40->NULL, so this LL is sorted and now we will, remove all the duplicates so we will get the final output as 10->20->30->40->NULL
// Approach : With the example of the above case, we will use tow pointers, head and current, initially dono head pr point kr rhe honge! now hum current ko use krke current ka data and current ke next ka data compare krenge, agar dono same honge toh hum current ka next ka data delete krdenge and current ke next ko current->next->next pr point kraa denge! and agar same nhi hote toh hum current ko just ek aage badhaa dete!
// Lets code now....
#include<iostream>
using namespace std;

// Basic code to create the singly linkedist!
class Node26 {
    public :
    int data;
    Node26* next;

    Node26(int data) {
        this->data = data;
        this->next = NULL;
    }

    ~Node26() {
        int value = this->data; // isme isko bhi likhne ki zrurat nhi hai, kyunki jiss jagah pr delete keyword call hua hoga hoga vo uske hisaab se data utha lega! toh alag se specify krne ki zarurat nhi hai!
        cout<<"Memory is free for the node with data "<<value<<endl;
    } // Here we have changed the destructor a little bit becoz destructor already delete krta hai, toh usme alag se delete operation perform krne ki zarurat nhi hai!
};

void insertatHead(Node26* &head, int data) {
    Node26* temp = new Node26(data);
    temp->next = head;
    head = temp;
}

void insertAtTail(Node26* &tail, int data) {
    Node26* temp = new Node26(data);
    tail->next = temp;
    tail = tail->next;
}

void insertAtAnyPosition(Node26* &head, Node26* &tail, int position, int data) {
    if(position == 1) {
        insertatHead(head,data);
        return;
    }

    Node26* temp = head;
    int cnt = 1;

    while(cnt < position-1) {
        temp = temp->next;
        cnt++;
    }

    if(temp->next == NULL) {
        insertAtTail(tail,data);
        return;
    }

    Node26* NodetoInsert = new Node26(data);
    NodetoInsert->next = temp->next;
    temp->next = NodetoInsert;
}

void printNode(Node26* &head) {
    Node26* temp = head;
    while(temp != NULL) {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

Node26* uniqueSortedList(Node26* head) { // This function is to remove all the duplicate elements!
    // Empty list...
    if(head == NULL) {
        return NULL;
    }
    Node26* curr = head;
    while(curr != NULL) {
        if((curr->next != NULL) && (curr->data == curr->next->data)) {
            Node26* next_to_next = curr->next->next;
            Node26* nodeToDelete = curr->next;
            curr->next = next_to_next;
            delete(nodeToDelete);
        }
        else {
            curr = curr->next;
        }
    }
    return head;
}

int main() {
    Node26* node = new Node26(10);
    Node26* head = node;
    Node26* tail = node;
    cout<<"First node of LL : ";
    printNode(head);

    // inserting more nodes...
    insertAtAnyPosition(head, tail, 2, 20);
    insertAtAnyPosition(head, tail, 3, 20);
    insertAtAnyPosition(head, tail, 4, 30);
    insertAtAnyPosition(head, tail, 5, 30);
    insertAtAnyPosition(head, tail, 6, 40);
    cout<<"Singly Linked List : ";
    printNode(head); // Currently this LL contains duplicate elements!

    // Removing duplicate elements...
    head = uniqueSortedList(head);
    printNode(head);
} // Time Complexity : O(n) and Space Complexity : O(1).
// So this is how we will remove duplicates in a sorted Linkedlist!, now lets remove duplicates from UnSorted!

// Removing duplicates in unsorted Linkedlist!
// Jaise pehle hum kr rhe the ki current ko harr iteration me aage badhaa rhe the and current->data and current->next hai usko compare kr rhe the agar dono same ho rhe the toh current->next ko pehle delete krke and then usko current->next->next pr point kraa de rhe the! and aise current ko aage badhaye jaa rhe the jab tak current->next NULL na hojaye!
// Approach 1 : So in this case what we will do is, hum iss baar curr ko head pr rakhenge and then poori LL traverse krenge then jaha jahaa same values dikhengi current->data se, unn unn nodes ke data ko vahaa se delete krte jayenge! and that is how we will move further! but isme TC will become O(n^2) which is not a good thing, so...
// Approach 2 : Yaa toh pehle hi LL ko sort krlo and then jo pehle vaala tha method tha usse hi solve krlo! in this case the TC : O(nlogn)
// Approach 3 : Yaa toh map use krlo, where map create krlo <node, bool> type ka jisme jo jo nodes hum visit krte jayenge unko hum true mark krte jayenge! and jab bhi traverse krte time koi aisa node aata hai jo map me already true marked hai usko delete krke uske prev node ko uske aage vaale node pr point kraa denge! and similarly for other nodes!
// Code for Approach 1, rest you can try while doing practice!
#include<iostream>
using namespace std;

// Basic code to create the singly linkedist!
class Node27 {
    public :
    int data;
    Node27* next;

    Node27(int data) {
        this->data = data;
        this->next = NULL;
    }

    ~Node27() {
        int value = this->data;
        cout<<"Memory is free for the node with data "<<value<<endl;
    }
};

void insertatHead(Node27* &head, int data) {
    Node27* temp = new Node27(data);
    temp->next = head;
    head = temp;
}

void insertAtTail(Node27* &tail, int data) {
    Node27* temp = new Node27(data);
    tail->next = temp;
    tail = tail->next;
}

void insertAtAnyPosition(Node27* &head, Node27* &tail, int position, int data) {
    if(position == 1) {
        insertatHead(head,data);
        return;
    }

    Node27* temp = head;
    int cnt = 1;

    while(cnt < position-1) {
        temp = temp->next;
        cnt++;
    }

    if(temp->next == NULL) {
        insertAtTail(tail,data);
        return;
    }

    Node27* NodetoInsert = new Node27(data);
    NodetoInsert->next = temp->next;
    temp->next = NodetoInsert;
}

void printNode(Node27* &head) {
    Node27* temp = head;
    while(temp != NULL) {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

Node27* uniqueUnsortedList(Node27* head) { // This function is to remove all the duplicate elements!
    // Empty list...
    if(head == NULL) {
        return NULL;
    }
    Node27* curr = head;
    while(curr != NULL) {
        Node27* temp = curr;
        while(temp->next != NULL) {
            if(temp->next->data == curr->data) {
                Node27* duplicate = temp->next;
                temp->next = temp->next->next;
                delete duplicate;
            }
            else {
                temp = temp->next;
            }
        }
        curr = curr->next;
    }
    return head;
}

int main() {
    Node27* node = new Node27(10);
    Node27* head = node;
    Node27* tail = node;
    cout<<"First node of LL : ";
    printNode(head);

    // inserting more nodes...
    insertAtAnyPosition(head, tail, 2, 20);
    insertAtAnyPosition(head, tail, 3, 20);
    insertAtAnyPosition(head, tail, 4, 30);
    insertAtAnyPosition(head, tail, 5, 30);
    insertAtAnyPosition(head, tail, 6, 40);
    cout<<"Singly Linked List : ";
    printNode(head); // Currently this LL contains duplicate elements!

    // Removing duplicate elements...
    head = uniqueUnsortedList(head);
    printNode(head);
} // It will have TC : O(n^2) becoz we have used two loops!, and SC will be constant O(1) kyunki koi extra space nhi li gyi hai!
// Rest, write and practice other approaches as well! as they are important to know, kyunki interviews me different approaches puche jaa sakte hai!
// Along with this learn to split cicular LL into two halves! and write the code!

// ---------------------------------------------------------- LECTURE 49 - Merge 2 Sorted LLs, Sort 0s, 1s, 2s --------------------------------------------------------------------------------------------------------->
// Question 1 : We are given with a LL with 0s 1s and 2s in the LL as nodes but they are are not in a sequence! so we have to sort them in a order!, like if you have a LL, 0->1->0->2->1->2, so we need to sort them as 0->0->1->1->2->2, so how will you do this...
// Approach 1 : So what we will do is that we will traverse the whole LL and count all the 0s 1s and 2s in the LL and then jo given LL hai usme hi start se end tak jaate jaate jitni jitni baar 0s 1s and 2s hai unko LL me data replace krte jayenge!
// Lets code this approach :
#include<iostream>
using namespace std;

// Basic code to create the singly linkedist!
class Node28 {
    public :
    int data;
    Node28* next;

    Node28(int data) {
        this->data = data;
        this->next = NULL;
    }

    ~Node28() {
        int value = this->data;
        cout<<"Memory is free for the node with data "<<value<<endl;
    }
};

void insertatHead(Node28* &head, int data) {
    Node28* temp = new Node28(data);
    temp->next = head;
    head = temp;
}

void insertAtTail(Node28* &tail, int data) {
    Node28* temp = new Node28(data);
    tail->next = temp;
    tail = tail->next;
}

void insertAtAnyPosition(Node28* &head, Node28* &tail, int position, int data) {
    if(position == 1) {
        insertatHead(head,data);
        return;
    }

    Node28* temp = head;
    int cnt = 1;

    while(cnt < position-1) {
        temp = temp->next;
        cnt++;
    }

    if(temp->next == NULL) {
        insertAtTail(tail,data);
        return;
    }

    Node28* NodetoInsert = new Node28(data);
    NodetoInsert->next = temp->next;
    temp->next = NodetoInsert;
}

Node28* sortList(Node28* head) { // Here we have codes the same approach! to print all the nodes 0 1 2 one by one according to there count! by replace the previous nodes data with the sorted ones!
    int zeroCount = 0;
    int oneCount = 0;
    int twoCount = 0;

    Node28* temp = head;
    while(temp != NULL) {
        if(temp->data == 0) {
            zeroCount++;
        }
        else if(temp->data == 1) {
            oneCount++;
        }
        else if(temp->data == 2) {
            twoCount++;
        }
        temp = temp->next;
    }

    temp = head;
    while(temp != NULL) {
        if(zeroCount != 0) {
            temp->data = 0;
            zeroCount--;
        }
        else if(oneCount != 0) {
            temp->data = 1;
            oneCount--;
        }
        else if(twoCount != 0) {
            temp->data = 2;
            twoCount--;
        }
        temp = temp->next;
    }
    return head;
}

void printNode(Node28* &head) {
    Node28* temp = head;
    while(temp != NULL) {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

int main() {
    Node28* node = new Node28(0);
    Node28* head = node;
    Node28* tail = node;
    cout<<"First node of LL : ";
    printNode(head);

    // inserting more nodes...
    insertAtAnyPosition(head, tail, 2, 2);
    insertAtAnyPosition(head, tail, 3, 1);
    insertAtAnyPosition(head, tail, 4, 0);
    insertAtAnyPosition(head, tail, 5, 1);
    insertAtAnyPosition(head, tail, 6, 2);
    cout<<"Singly Linked List : ";
    printNode(head);

    head = sortList(head); // Updated the head
    printNode(head); // Printing the LL with the new head!
} // TC will be O(n) kyunki do loops alag alag traverse hue hai! and koi extra space nhi use ki bss variables hi create kiye hai! so SC will be O(1)

// Approach 2 : Now what if we are not allowed to replace the data! then in that case what else can we replace or change? that is Links! so we will try to change the Links of nodes though this approach!
// So what we will do is we will create 3 LLs one for 0s and one 1s and one for 2s, and then we will merge all of them! Here we will be using dummy nodes like ye ek tarah se head nodes honge saare individual LLs ke taaki hum identify kr sake ki ye jo 3 LLs honge vo teeno kiske kiske hai! and then final jab hum merge kr rhe honge toh inn Dummy nodes ki help se hi krenge!
// Bina dummy nodes ke bhi hojayega question solve, pr usme if condition lga lga ke pagal hojayenge! isliye we will use dummy nodes!
// Lets code and see further...
#include<iostream>
using namespace std;

// Basic code to create the singly linkedist!
class Node28 {
    public :
    int data;
    Node28* next;

    Node28(int data) {
        this->data = data;
        this->next = NULL;
    }

    ~Node28() {
        int value = this->data;
        cout<<"Memory is free for the node with data "<<value<<endl;
    }
};

void insertatHead(Node28* &head, int data) {
    Node28* temp = new Node28(data);
    temp->next = head;
    head = temp;
}

void insertAtTail(Node28* &tail, int data) {
    Node28* temp = new Node28(data);
    tail->next = temp;
    tail = tail->next;
}

void insertAtAnyPosition(Node28* &head, Node28* &tail, int position, int data) {
    if(position == 1) {
        insertatHead(head,data);
        return;
    }

    Node28* temp = head;
    int cnt = 1;

    while(cnt < position-1) {
        temp = temp->next;
        cnt++;
    }

    if(temp->next == NULL) {
        insertAtTail(tail,data);
        return;
    }

    Node28* NodetoInsert = new Node28(data);
    NodetoInsert->next = temp->next;
    temp->next = NodetoInsert;
}

void insertAtTail2(Node28* &tail, Node28* curr) { // This is just created to insert the data into the created sub-LLs in the sortList function!
    tail->next = curr;
    tail = curr;
}

Node28* sortList(Node28* head) { // As we discussed in the approach using dummy nodes! and merge all the three LLs!
    // Three individual LLs created for 0s 1s and 2s
    // Here we have created head and tail both! kyunki humaari jo LL ki implementations hai usme hum head and tail dono leke chal rhe hai and isliye humne insert at tail ko bhi implement kiya hua hai apne insertAtAnyPosition me! so isliye humne tail bhi banai! otherwise jab actually implement log krte hai toh generally tail bnaate hi nhi hai sirf head ke through hi inserting operations implement kr dete hai! but okay hum head nad tail dono leke chal rhe hai!
    // So here we have created three dummy nodes with head and tails which are be pointing at sub-LLs of 0s 1s and 2s! and later on we will merge them!
    Node28* zeroHead = new Node28(-1);
    Node28* zeroTail = zeroHead;

    Node28* oneHead = new Node28(-1);
    Node28* oneTail = oneHead;

    Node28* twoHead = new Node28(-1);
    Node28* twoTail = twoHead;

    Node28* curr = head;
    while(curr != NULL) {
        int value = curr->data;
        if(value == 0) {
            insertAtTail2(zeroTail, curr);
        }
        else if(value == 1) {
            insertAtTail2(oneTail, curr);
        }
        else if(value == 2) {
            insertAtTail2(twoTail, curr);
        }
        curr = curr->next;
    }
    // Now we will merge the created three sub-LLs...
    // Approach is ki hum zerotail ke next ko oneHead ke next se link kr denge (one head is just a dummy node main data toh oneHead ke next node se store hona shuru ho rha hai isliye zeroTail next ko oneHead ke next se link kraa rhe hai!)
    // and similarly for other sub-LLs... but isme ek dikkat ho sakti hai, that is ki what if zeroHead vaali LL me toh 0s hai, pr 1s vaali poori khali ho! and jo 2s vaali hai usme 2s hai, so in this case hum 0s vaali LL ko 2s vaali LL se link naa krke 2s vaali se link krdenge seedha, and for this we will use a if else conditions!

    // 1s list is not empty...
    if(oneHead->next != NULL) {
        zeroTail->next = oneHead->next;
    }
    else {
        zeroTail->next = twoHead->next;
    }

    oneTail->next = twoHead->next;
    twoTail->next = NULL;
    // Ab yahaa tak ka toh kaam hogya! but ab humari list ready hai, but now we need to remove the dummy nodes as becoz they are using extra space also zeroHead vaal dummy node toh abhi current head bnaa hua hai is merged LL ka, so hum chahenge ki usko 0s ki first vaali node pr point kraye! toh hum head bhi change krna hoga!
    head = zeroHead->next;

    // Deleting dummy nodes!
    delete zeroHead;
    delete oneHead;
    delete twoHead;

    return head;
}

void printNode(Node28* &head) {
    Node28* temp = head;
    while(temp != NULL) {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

int main() {
    Node28* node = new Node28(0);
    Node28* head = node;
    Node28* tail = node;
    cout<<"First node of LL : ";
    printNode(head);

    // inserting more nodes...
    insertAtAnyPosition(head, tail, 2, 2);
    insertAtAnyPosition(head, tail, 3, 1);
    insertAtAnyPosition(head, tail, 4, 0);
    insertAtAnyPosition(head, tail, 5, 1);
    insertAtAnyPosition(head, tail, 6, 2);
    cout<<"Singly Linked List : ";
    printNode(head);

    head = sortList(head); // Updated the head
    printNode(head); // Printing the LL with the new head!
} // TC : O(n) and SC : O(1), iski aur upar vaale approach ki TC and SC dono same hai, so ab interviewer pr depend krta hai ki what they will ask! if they tell to sort 0s 1s and 2s without replacement, then you will use this approach!


// Question 2 : Merge two sorted LLs!
// You will be given with two sorted LLs and dono ko merge krke jo resultant LL hogi vo bhi sorted honi chahiye!
// Lets see the approach : Pehli baar toh agar dono me se koi bhi LL empty hoti hai toh hum dusri vaali LL ko print krdenge as simple as that! but now lets see otherwise...
// So, here what we will do is, suppose have two LLs one is LL1 and another is LL2, now, LL1 me do pointer honge prev and curr, and hum prev and curr node ke beech me kisi aisi value ko dhundenge dusri LL me jo inn dono ke beech me aa sakti hai, agar aa sakti hai toh simply uss node ko daal denge LL1 me and prev ko update krke uss node pr le ayenge jisko abhi abhi merge kiya LL1 me from LL2, now again we will check ki kya ab kr sakte hai ki prev and curr ke beech me koi node insert from LL2, if yes then will repeat the same and if noe then will just update prev and curr! and will keep on doing this jab tak LL2 k NULL nhi aa jaata!
// So yahaa hum merge krne ke liye kisi ek LL ko LL1 maanenge and ek ko LL2! and LL2 ke nodes ko LL1 me add krte jayenge! and once LL2 ka NULL aajaata hai toh hum vhi ruk jayenge! and will print LL1!
// Also hum kisko LL1 maanna hai and kisko LL2 ye bhi toh ptaa krna padega! kyunki LL1 me LL2 ka data tab hi daalenge na jab LL2 ka first node badaa ho LL1 ke first node se!, so for that pehle hume yhi ptaa krna pdega ki konsa LL1 and and konsa LL2!
// Now lets code...
#include<iostream>
using namespace std;

// Basic code to create the singly linkedist!
class Node29 {
    public :
    int data;
    Node29* next;

    Node29(int data) {
        this->data = data;
        this->next = NULL;
    }

    ~Node29() {
        int value = this->data;
        cout<<"Memory is free for the node with data "<<value<<endl;
    }
};

void insertatHead(Node29* &head, int data) {
    Node29* temp = new Node29(data);
    temp->next = head;
    head = temp;
}

void insertAtTail(Node29* &tail, int data) {
    Node29* temp = new Node29(data);
    tail->next = temp;
    tail = tail->next;
}

void insertAtAnyPosition(Node29* &head, Node29* &tail, int position, int data) {
    if(position == 1) {
        insertatHead(head,data);
        return;
    }

    Node29* temp = head;
    int cnt = 1;

    while(cnt < position-1) {
        temp = temp->next;
        cnt++;
    }

    if(temp->next == NULL) {
        insertAtTail(tail,data);
        return;
    }

    Node29* NodetoInsert = new Node29(data);
    NodetoInsert->next = temp->next;
    temp->next = NodetoInsert;
}

Node29* solve(Node29* ActualLL1, Node29* ActualLL2) {
    // Here we have created prev and curr jisko use krke hum Actual LL1 pr windows create krenge jisme hum LL2 ke elements ko compare krke merge krenge!
    Node29* prev = ActualLL1;
    Node29* curr = prev->next;

    // This is a pointer is created jisse hum Actual LL2 me traverse krenge!
    Node29* temp = ActualLL2;
    Node29* tempNext = temp->next; // Isko hum bss use krenge ActualLL2 ko track me rakhne ke liye ki kahin jab ActualLL2 ke nodes ActualLL1 me merge ho rhe ho toh uss instant pr kahin baaki nodes ka access na kho jaye humse! isliye ye create kiya gya hai! It is just like a helping pointer! which will just track the nodes of ALL2.

    while(curr != NULL && temp != NULL) {
        if((temp->data >= prev->data) && (temp->data <= curr->data)) {
            prev->next = temp; // Prev of ALL1 ke next ko ALL2 ke temp se link krdiya! 
            tempNext = temp->next; // ALL2 ke remaining nodes ka track na kho jaye isliye unko tempNext ek helping pointer create krke usko uss remaining part of ALL2 pr point kraa diya!
            temp->next = curr; // Ab hum safely temp of ALL2 ke next ko ALL1 ke curr ke saath link kr sakte hai

            // Now just update the pointers...
            prev = temp;
            temp = tempNext;
        }
        else {
            // If me tha ki agar temp prev and curr ke beech me lie krta hai toh temp daaldo ALL1 me, but what if agar nhi krta hai lie between prev and curr...then...
            // So in this case hume bss prev and curr ko aage badhaana padega!
            prev = curr;
            curr = curr->next;
        }
    }
    return ActualLL1;
}

Node29* mergeLLs(Node29* LL1, Node29* LL2) {
    if(LL1 == NULL) {
        return LL2;
    }
    if(LL2 == NULL) {
        return LL1;
    }

    // Here we have managed that konsi Linkedlist actual LL1 banegi and konsi actual LL2!
    if(LL1->data <= LL2->data) {
        return solve(LL1, LL2);
    }
    else {
        return solve(LL2, LL1);
    }
}

void printNode(Node29* &head) {
    Node29* temp = head;
    while(temp != NULL) {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

int main() {
    // Creating Linkedlist 1...
    Node29* LL1 = new Node29(1);
    Node29* headLL1 = LL1;
    Node29* tailLL1 = headLL1;
    cout<<"First node of LL1 : ";
    printNode(headLL1);

    // Inserting more nodes in LL1...
    insertAtAnyPosition(headLL1, tailLL1, 2, 5);
    insertAtAnyPosition(headLL1, tailLL1, 3, 6);
    insertAtAnyPosition(headLL1, tailLL1, 4, 8);
    insertAtAnyPosition(headLL1, tailLL1, 5, 10);
    insertAtAnyPosition(headLL1, tailLL1, 6, 15);
    cout<<"Singly Linkedlist LL1 : ";
    printNode(headLL1);

    cout<<endl;

    // Creating Linkedlist 2...
    Node29* LL2 = new Node29(1);
    Node29* headLL2 = LL2;
    Node29* tailLL2 = headLL2;
    cout<<"First node of LL2 : ";
    printNode(headLL2);

    // Inserting more nodes in LL2...
    insertAtAnyPosition(headLL2, tailLL2, 2, 2);
    insertAtAnyPosition(headLL2, tailLL2, 3, 3);
    insertAtAnyPosition(headLL2, tailLL2, 4, 7);
    insertAtAnyPosition(headLL2, tailLL2, 5, 9);
    insertAtAnyPosition(headLL2, tailLL2, 6, 12);
    cout<<"Singly Linkedlist LL2 : ";
    printNode(headLL2);

    cout<<endl;

    // merging the two Linkedlists LL1 and LL2...
    Node29* head = mergeLLs(LL1, LL2);
    cout<<"Final merged Linkedlist : ";
    printNode(head);
} // So that is how we do it! and its TC : O(n) and SC : O(1), kyunki do loops chale hai jo poori linkedlist traverse kr rhe hai and space bhi koi as such li nhi hai bss variables alot kiye hai!

// But there is still one problem and that is ki suppose LL1 has only 1 node then in that case prev will be at that node and curr will be at NULL, now due to which solve vaale function me kabhi bhi Loop chalega hi nhi!, so bss yhi ek case handle krna bacha hai upar vaale case me!, so for that we will do this...
#include<iostream>
using namespace std;

class Node29 {
    public :
    int data;
    Node29* next;

    Node29(int data) {
        this->data = data;
        this->next = NULL;
    }

    ~Node29() {
        int value = this->data;
        cout<<"Memory is free for the node with data "<<value<<endl;
    }
};

void insertatHead(Node29* &head, int data) {
    Node29* temp = new Node29(data);
    temp->next = head;
    head = temp;
}

void insertAtTail(Node29* &tail, int data) {
    Node29* temp = new Node29(data);
    tail->next = temp;
    tail = tail->next;
}

void insertAtAnyPosition(Node29* &head, Node29* &tail, int position, int data) {
    if(position == 1) {
        insertatHead(head,data);
        return;
    }

    Node29* temp = head;
    int cnt = 1;

    while(cnt < position-1) {
        temp = temp->next;
        cnt++;
    }

    if(temp->next == NULL) {
        insertAtTail(tail,data);
        return;
    }

    Node29* NodetoInsert = new Node29(data);
    NodetoInsert->next = temp->next;
    temp->next = NodetoInsert;
}

Node29* solve(Node29* ActualLL1, Node29* ActualLL2) {
    // If only one node is present in the ActualLL1, iss case me simply uss first node ke next ko ActualLL2 ke first se link krdo, and thats it!
    if(ActualLL1->next == NULL) {
        ActualLL1->next = ActualLL2;
        return ActualLL1;
    } // this is the change we have done here!

    Node29* prev = ActualLL1;
    Node29* curr = prev->next;

    Node29* temp = ActualLL2;
    Node29* tempNext = temp->next;

    while(curr != NULL && temp != NULL) {
        if((temp->data >= prev->data) && (temp->data <= curr->data)) {
            prev->next = temp;
            tempNext = temp->next;
            temp->next = curr;

            // Now just update the pointers...
            prev = temp;
            temp = tempNext;
        }
        else {
            prev = curr;
            curr = curr->next;
        }
    }
    return ActualLL1;
}

Node29* mergeLLs(Node29* LL1, Node29* LL2) {
    if(LL1 == NULL) {
        return LL2;
    }
    if(LL2 == NULL) {
        return LL1;
    }

    // Here we have managed that konsi Linkedlist actual LL1 banegi and konsi actual LL2!
    if(LL1->data <= LL2->data) {
        return solve(LL1, LL2);
    }
    else {
        return solve(LL2, LL1);
    }
}

void printNode(Node29* &head) {
    Node29* temp = head;
    while(temp != NULL) {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

int main() {
    // Creating Linkedlist 1 with only one element!...
    Node29* LL1 = new Node29(1);
    Node29* headLL1 = LL1;
    Node29* tailLL1 = headLL1;
    cout<<"First node of LL1 : ";
    printNode(headLL1);

    cout<<"Singly Linkedlist LL1 : ";
    printNode(headLL1);

    cout<<endl;

    // Creating Linkedlist 2...
    Node29* LL2 = new Node29(1);
    Node29* headLL2 = LL2;
    Node29* tailLL2 = headLL2;
    cout<<"First node of LL2 : ";
    printNode(headLL2);

    // Inserting more nodes in LL2...
    insertAtAnyPosition(headLL2, tailLL2, 2, 2);
    insertAtAnyPosition(headLL2, tailLL2, 3, 3);
    insertAtAnyPosition(headLL2, tailLL2, 4, 7);
    insertAtAnyPosition(headLL2, tailLL2, 5, 9);
    insertAtAnyPosition(headLL2, tailLL2, 6, 12);
    cout<<"Singly Linkedlist LL2 : ";
    printNode(headLL2);

    cout<<endl;

    // merging the two Linkedlists LL1 and LL2...
    Node29* head = mergeLLs(LL1, LL2);
    cout<<"Final merged Linkedlist : ";
    printNode(head);
} // So overall that is how we merge two linkedlists!

// ---------------------------------------------------------- LECTURE 50 - Palindrome Problem! --------------------------------------------------------------------------------------------------------->
// Question : Check whether the List is a palidrome or not!, we already know what is a palindrome!
// Approach 1 : So here we will proceed with creating an array! and then will copy all the nodes value into the array! and then will apply the array vaala logic to check a palindrome! so is case me SC : o(n) kyunki jitne nodes honge utni space lagegi! and TC : O(n) kyunki ek toh LL traverse krne me O(n) ki TC thi and then reverse krne me O(n) so we will get the final TC : O(n)!
// Lets code this....
#include<iostream>
#include<vector>
using namespace std;

class Node30 {
    public :
    int data;
    Node30* next;

    Node30(int data) {
        this->data = data;
        this->next = NULL;
    }

    ~Node30() {
        int value = this->data;
        cout<<"Memory is free for the node with data "<<value<<endl;
    }
};

void insertatHead(Node30* &head, int data) {
    Node30* temp = new Node30(data);
    temp->next = head;
    head = temp;
}

void insertAtTail(Node30* &tail, int data) {
    Node30* temp = new Node30(data);
    tail->next = temp;
    tail = tail->next;
}

void insertAtAnyPosition(Node30* &head, Node30* &tail, int position, int data) {
    if(position == 1) {
        insertatHead(head,data);
        return;
    }

    Node30* temp = head;
    int cnt = 1;

    while(cnt < position-1) {
        temp = temp->next;
        cnt++;
    }

    if(temp->next == NULL) {
        insertAtTail(tail,data);
        return;
    }

    Node30* NodetoInsert = new Node30(data);
    NodetoInsert->next = temp->next;
    temp->next = NodetoInsert;
}

bool checkPalindrome(vector<int> arr) {
    int n = arr.size();
    int s = 0;
    int e = n-1;
    while(s<=e) {
        if(arr[s] != arr[e]) {
            return 0;
        }
        s++;
        e--;
    }
    return 1;
}

bool isPalindrome(Node30* head) {
    vector<int> arr;
    Node30* temp = head;
    while(temp != NULL) {
        arr.push_back(temp->data);
        temp = temp->next;
    }
    return checkPalindrome(arr);
}

void printNode(Node30* &head) {
    Node30* temp = head;
    while(temp != NULL) {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

int main() {
    // Creating a Linkedlist...
    Node30* node = new Node30(1);
    Node30* head = node;
    Node30* tail = head;
    cout<<"First node of LL : ";
    printNode(head);

    cout<<"Singly Linkedlist : ";
    insertAtAnyPosition(head, tail, 2, 2);
    insertAtAnyPosition(head, tail, 3, 3);
    insertAtAnyPosition(head, tail, 4, 2);
    insertAtAnyPosition(head, tail, 5, 1);
    printNode(head);

    if(isPalindrome(head)) {
        cout<<"This Linked List is a Palindrome!";
    }
    else {
        cout<<"Its not a Palindrome!";
    }
} // So yes this is how we do it with approach 1...

// But in the above approach we are taking extra space! so lets try something there different where we could minimize the SC!
// Approach 2 : Isme what we do is hum pehle LL ka mid find krenge and then mid ke next se remaining LL ko reverse krenge and then uske baad ek ek krke first node ko mid ke next node se compare krenge and second node ko mid ke next ke next se compare krenge and so on...
// agar sab same hote hai toh it will be a Palindrome! otherwise not! and then last me vapis LL ko reverse krdenge taki we get our original LL back jo humne compare krne ke liye reverse krdi thi
// lets code this...
#include<iostream>
using namespace std;

class Node31 {
    public :
    int data;
    Node31* next;

    Node31(int data) {
        this->data = data;
        this->next = NULL;
    }

    ~Node31() {
        int value = this->data;
        cout<<"Memory is free for the node with data "<<value<<endl;
    }
};

void insertatHead(Node31* &head, int data) {
    Node31* temp = new Node31(data);
    temp->next = head;
    head = temp;
}

void insertAtTail(Node31* &tail, int data) {
    Node31* temp = new Node31(data);
    tail->next = temp;
    tail = tail->next;
}

void insertAtAnyPosition(Node31* &head, Node31* &tail, int position, int data) {
    if(position == 1) {
        insertatHead(head,data);
        return;
    }

    Node31* temp = head;
    int cnt = 1;

    while(cnt < position-1) {
        temp = temp->next;
        cnt++;
    }

    if(temp->next == NULL) {
        insertAtTail(tail,data);
        return;
    }

    Node31* NodetoInsert = new Node31(data);
    NodetoInsert->next = temp->next;
    temp->next = NodetoInsert;
}

Node31* getMid(Node31* head) {
    Node31* slow = head;
    Node31* fast = head->next;

    while(fast != NULL && fast->next != NULL) {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}

Node31* reverse(Node31* head) {
    Node31* curr = head;
    Node31* prev = NULL;
    Node31* next = NULL;

    while(curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

bool isPalindrome(Node31* head) {
    // If the list is empty...
    if(head == NULL || head->next == NULL) {
        return 1;
    }

    // Finding the middle node...
    Node31* mid = getMid(head);

    // Reverse the list after the middle node...
    Node31* temp = mid->next;
    mid->next = reverse(temp);

    // Now lets compare the two halves! for that we will create two pointers! head1 and head2! where head1 will be pointing at the first half of the LL and head2 will pointing at the other half of the LL!
    Node31* head1 = head;
    Node31* head2 = mid->next;
    while(head2 != NULL) {
        if(head1->data != head2->data) {
            return 0;
        }
        head1 = head1->next;
        head2 = head2->next;
    }
    
    // Now bss ab vapis LL ko reverse krdo! taki we get our original LL back! hum chaahe toh bina iske bhi humara answer sahi ayega! we just have used this piece of code with a wider perspective! that ki kabhi agar hume future me LL original vaali chahiye! toh thats why we did this! taaki original LL intact rahe!
    temp = temp->next;
    reverse(temp);

    // Now return true agar ye sab hoke uss loop se successfully bahar aa chuke hai toh...
    return true;
}

void printNode(Node31* &head) {
    Node31* temp = head;
    while(temp != NULL) {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

int main() {
    // Creating a Linkedlist...
    Node31* node = new Node31(1);
    Node31* head = node;
    Node31* tail = head;
    cout<<"First node of LL : ";
    printNode(head);

    cout<<"Singly Linkedlist : ";
    insertAtAnyPosition(head, tail, 2, 2);
    insertAtAnyPosition(head, tail, 3, 3);
    insertAtAnyPosition(head, tail, 4, 2);
    insertAtAnyPosition(head, tail, 5, 1);
    printNode(head);

    if(isPalindrome(head)) {
        cout<<"This Linked List is a Palindrome!";
    }
    else {
        cout<<"Its not a Palindrome!";
    }
} // Here the TC : O(n) and SC : O(1), so here we have reduced the space complexity! as becoz no extra space is used! but the TC : O(n) kyunki time toh utna hi lag rha hai! kyunki abhi we are traversing the whole LL, pehle mid nikalne me TC : O(n/2) then reverse me TC : O(n), then humne jo comparison kiya hai usme TC : O(n), then lastly firse reverse krne me TC : O(n), so overall our TC : 3*O(n) + O(n/2) = O(n)!