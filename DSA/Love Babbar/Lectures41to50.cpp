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
//                       : No Memory Wastage : Only the required memory is used, with no extra space wasted.
//                       : Easy Insertions/Deletions : Adding or removing elements is straightforward and efficient.

// Linked List Structure : Linked Lists don't require contiguous memory blocks.
//                       : Nodes are connected through addresses, allowing them to be stored anywhere in memory.

// Singly Linked List Example : Structure : [Value1, Address of next node] -> [Value2, Address of next node] -> [Value3, Address of next node] -> [Value4, Address of next node] -> NULL! Head Node : The first node in the list. Tail Node : The last node in the list.
// There are three types...Singly, Doubly and Circular!
// Now lets implement it... we will use classes to implement it... as array jaise hote hai na vaise hi hum yahaa LinkedList ko bhi ek keyword ki tarah banaa denge classes ka use krke... kyunki in the end class toh ek template hi toh bnati hai kisi ek data type ka! toh bss hum vhi krenge Linked List ki implementation ke liye!
// Now lets see...
#include<iostream>
using namespace std;

// Template created for creation of node!
class Node {
    public :
    int data;
    Node* next;

    Node(int data) { // we have made a constructor so that jab bhi koi node ka object create hota hai toh vaise hi uske andar nodes ki properties aajaye! jo iss implementation me likhi hui hai!
        this-> data = data;
        this->next = NULL;
    } // And this keyword is used for obv reasons, taaki hum current object ke data and next pointer ko sambhal sake!
};

int main() {
    Node* n1 = new Node(10); // Here one node is created dynamically and it is of "Node" type...
    cout<<n1->data<<endl;
    cout<<n1->next<<endl;
} // So here we have created a node n1 which has a value and is pointing at NULL. Now to create a Linked List, we need to insert more nodes before (before the head) and after (after the tail) it!

// Lets first Insert from the Head!
// Approach : Just like we have created a node template! similarly we will create more nodes and by default all the next pointer of all the nodes are pointing at NULL. so we will just make that next pointer point at the node which was created before this one. means overall just creating new nodes and storing address of the old nodes in these new node's next pointer!
// Now lets implement it....
#include<iostream>
using namespace std;

class Node2 {
    public :
    int data;
    Node2* next;

    Node2(int data) {
        this->data = data;
        this->next = NULL;
    }
}; // This template will just create default nodes (which will just contain a value and a next pointer which will store NULL at this point) whenever we call them using the constructor! so like, we are trying to create LL from tail to head...

void insertAtHead1(Node2* &head, int data) {
    Node2* temp = new Node2(data);
    temp->next = head;
    head = temp;
} // Now here, what we did is... ab ek first node toh humara create ho chuka hai! so now ab hum ek aur node create krenge jo default hi hoga mtlb usme value toh stored hogi pr vo initially vo bhi NULL ko hi point kr rha hoga...
// Flow : Ek temp node banai jo abhi default hai, fir uske next ko head pr point kraya and then head ko update krdiya usme temp daalke, taaki vo ab new node ko point kre!

void print(Node2* &head) {
    Node2* temp = head;
    while(temp != NULL) {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
} // Used temp to iterate through each node! It starts from the head node and iterates through each node using the next pointer until reaching the end of the list (where next is NULL).

int main() {
    Node2* n1 = new Node2(10);
    Node2* head = n1;
    print(head);

    insertAtHead1(head,12);
    print(head);

    insertAtHead1(head,15);
    print(head);
} // In short, default nodes created (using the class implementations) ! then we started linking every new node's next pointer at the old node (this is done using the insertAtHead() function!) and through this we have build a linkedlist! and here we are creating it in from tail to head fashion!

// Lets write for Inserting node at tail...
#include<iostream>
using namespace std;

class Node3 {
    public :
    int data;
    Node3* next;

    Node3(int data) {
        this->data = data;
        this->next = NULL;
    }
};

void insertAtHead2(Node3* &head, int data) {
    Node3* temp = new Node3(data);
    temp->next = head;
    head = temp;
} 

void insertAtTail1(Node3* &tail, int data) {
    Node3* temp = new Node3(data);
    tail->next = temp;
    tail = tail->next;
} // This you can understand ki kya changes hue hai isme... just pointer old node's next pointer at the new node! its just reverse of the inserting at head implementation!

void print(Node3* &head) {
    Node3* temp = head;
    while(temp != NULL) {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

int main() {
    Node3* n1 = new Node3(10);
    Node3* head = n1;
    Node3* tail = n1;
    print(head);
    
    insertAtTail1(tail,12);
    print(head);

    insertAtTail1(tail,15);
    print(head);
}

// Inserting node at any position in the linked list : Head, Tail or Anywhere in between!
// Approach : Here we have used the insertAtAnyPosition() to insert a particular node at any position! steps followed...
// If the list is empty (head == NULL): It creates a new node and sets it as the head of the list.
// If inserting at the head (pos == 1): It calls a helper function insertAtHead3 to add the node at the beginning.
// For positions other than head : It traverses the list until it reaches the node just before the desired position. If it reaches the end of the list before the position, it adds the new node at the end by calling insertAtTail2. Otherwise, it inserts the new node at the correct position by adjusting pointers: Sets the new node's next to point to the node that was originally at that position. Updates the previous node’s next to point to the new node. 
// If the new node is the new tail (i.e., newNode->next == NULL): It updates the tail pointer to the new node.
// Implementing...
#include<iostream>
using namespace std;

class Node5 {
    public :
    int data;
    Node5* next;

    Node5(int data) {
        this->data = data;
        this->next = NULL;
    }
};

void insertAtHead3(Node5* &head, int data) {
    Node5* temp = new Node5(data);
    temp->next = head;
    head = temp;
}

void insertAtTail2(Node5* &tail, int data) {
    Node5* temp = new Node5(data);
    tail->next = temp;
    tail = tail->next;
}

void insertAtAnyPosition1(Node5* &head, int pos, int data) {
    if(head == NULL) {
        Node5* newNode = new Node5(data);
        head = newNode;
        return;
    }

    if(pos == 1) {
        insertAtHead3(head,data);
        return;
    }

    Node5* tail = head;
    Node5* temp = head;
    int cnt = 1;

    while(cnt < pos && temp->next != NULL) {
        temp = temp->next;
        cnt++;
    }

    if(temp->next == NULL) {
        insertAtTail2(tail,data);
        return;
    }

    Node5* newNode = new Node5(data);
    newNode->next = temp->next;
    temp->next = newNode;

    if(newNode->next == NULL) {
        tail = newNode;
    }
}

void printNode(Node5* &head) {
    Node5* temp = head;
    while(temp != NULL) {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

int main() {
    Node5* newNode = new Node5(10);
    
    // head and tail defined!
    Node5* head = newNode;
    Node5* tail = newNode;
    
    insertAtHead3(head,9);
    insertAtHead3(head,8);

    insertAtTail2(tail,11);
    insertAtTail2(tail,12);

    // You can make a function which takes head and tail both for input, but that is not actually required! becoz we mostly consider head only as from where we start linked-list!
    // insertAtAnyPosition(head,tail,1,7);
    // insertAtAnyPosition(head,tail,4,20);
    // insertAtAnyPosition(head,tail,7,30);

    // Now you can use insert at any position function to insert at any position in the Linked list!
    insertAtAnyPosition1(head,1,30);
    insertAtAnyPosition1(head,3,40);
    insertAtAnyPosition1(head,4,50);

    cout<<"Head : "<<head->data<<endl;
    cout<<"Tail : "<<tail->data<<endl;

    printNode(head);
}

// Now, Deleting a node from Singly LL!
// Approach : First we check ki LL empty hai ya nhi, if yes then no deletion possible and return! But if this stands false, then find length of LL and see if the position < 1 || position is > len, if this stands true display an error message! but if bith stands false, the...
// check if position == 1, then adjust the head node and point it to the next one and then point the prev head to NULL using a local pointer temp and then delete this! but again if pos != 1, then finally, iterate over the position jahaa pr deletion of node krna hai and then in the same manner, uss node ko delete krdo using the delete keyword!
// And pehle se ek Tail pointer bnaa ke rakho taaki agar iterate krte krte last node pr pohoch gye toh tail bhi update krna hota hai! agar uss position tak pohochte pohchte tail node pr aagye toh uss tail node ko delete krke tail node ko update krna hota hai taaki LL ke head and tail intact rahe!
#include<iostream>
using namespace std;

class Node6 {
    public :
    int data;
    Node6* next;

    Node6(int data) {
        this->data = data;
        this->next = NULL;
    }

    ~Node6() {
        cout << "Memory is free for the node with data " << this->data << endl;
    }
};

void insertAtHead4(Node6* &head, int data) {
    Node6* temp = new Node6(data);
    temp->next = head;
    head = temp;
}

void insertAtTail3(Node6* &tail, int data) {
    Node6* temp = new Node6(data);
    tail->next = temp;
    tail = tail->next;
}

void insertAtAnyPosition2(Node6* &head, int pos, int data) {
    if(head == NULL) {
        Node6* newNode = new Node6(data);
        head = newNode;
        return;
    }

    if(pos == 1) {
        insertAtHead4(head,data);
        return;
    }

    Node6* tail = head;
    Node6* temp = head;
    int cnt = 1;

    while(cnt < pos && temp->next != NULL) {
        temp = temp->next;
        cnt++;
    }

    if(temp->next == NULL) {
        insertAtTail3(tail,data);
        return;
    }

    Node6* newNode = new Node6(data);
    newNode->next = temp->next;
    temp->next = newNode;

    if(newNode->next == NULL) {
        tail = newNode;
    }
}

int getLengthofLL(Node6* &head) {
    int len = 0;
    Node6* temp = head;
    while(temp != NULL) {
        temp = temp->next;
        len++;
    }
    return len;
}

void deleteNode1(Node6* &head, int pos) {
    if(head == NULL) {
        cout<<"List is empty!";
        return;
    }

    int len = getLengthofLL(head);
    if(pos < 1 || pos > len) {
        cout<<"Position is out of bounds!";
        return;
    }

    Node6* tail = head; // Tail pointer initiated at head and then iterated towards the end! so to make it actually point at the tail!
    while (tail->next != NULL) {
        tail = tail->next;
    }

    if(pos == 1) {
        Node6* temp = head;
        head = head->next;
        temp->next = NULL; // We are manually setting the curr->next to NULL for this case, means now we will use the destructor with only cleanup process!
        delete temp;
        return;
    }
    else {
        Node6* prev = NULL;
        Node6* curr = head;
        int cnt = 1;

        while(cnt < pos) {
            prev = curr;
            curr = curr->next;
            cnt++;
        }

        prev->next = curr->next;
        if (curr->next == NULL) {
            tail = prev;
        }
        curr->next = NULL; // We are manually setting the curr->next to NULL, means now we will use the destructor with only cleanup process!
        delete curr;
    }
}

void printNode(Node6* &head) {
    Node6* temp = head;
    while(temp != NULL) {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

int main() {
    Node6* node1 = new Node6(10);
    Node6* head = node1;
    Node6* tail = node1;

    insertAtAnyPosition2(head,2,20);
    insertAtAnyPosition2(head,3,30);
    insertAtAnyPosition2(head,4,40);
    insertAtAnyPosition2(head,5,50);
    insertAtAnyPosition2(head,6,60);

    printNode(head);

    // Calling the delete function for the node with data value 30, its position is 3
    deleteNode1(head,3);

    // Printing the updated linkedlist...
    cout<<"The updated linked list is : ";
    printNode(head);
}
// A quick summary of what Linked List are and how we have created nodes, inserted at head, tail and then how we have inserted at any position, and then how we have deleted a node! also how we have found the length of the LL!
// Lets go...
// Creation of Node : Using class of Node type which contains, and which helps in node creation by alotting two memory spaces one for data and another to store address of next node, but by default is pointing at NULL!
// Inserting at Head/Tail : Using the function insertAtHead()/insertAtTail() function to insert a node at head, details are mentioned already! Here if we observe, then the insertion of node happens from tail to head, in case of Insertion at head! and head to tail, in case of head to tail! you can use both head and tail as well to handle the insertion, but just manage the insertion and updation of head and tail node properly!
// Insertion at Any Position : Using the function we can insert at any position, and for this we have two helper function, isert at head/tail(), and through this we can insert at any position of the linked list! Here also you can use head and tail both for insertion, but its on us if we want that or not!
// Deleting Node (based on position) : Deleting node requires, checking some condition first, like empty list, list with single element, position out of bounds and deletion from any other position including tail! Here also you can use head and tail both for deletion, but its on us if we want that or not!

// Doubly LinkedLists : LL which stores address of both the nodes next and prev of it! so it has two pointers, next and prev both!
// Lets create it with the same logic as of above...
#include<iostream>
using namespace std;

// Creation of node basic structure!
class Node7 {
    public :
    int data;
    Node7* prev;
    Node7* next;

    Node7 (int data) {
        this->data = data;
        this->prev = NULL;
        this->next = NULL;
    }
};

void printNode(Node7* &head) {
    Node7* temp = head;
    while(temp != NULL) {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

// Finding Length of the LinkedList!
int getLength(Node7* &head) {
    int len = 0;
    Node7* temp = head;
    while(temp != NULL) {
        len++;
        temp = temp->next;
    }
    return len;
}

// So what happened here is, jaise we know double linkeds are like this [NULL,data1,next node address] <--> [previour node address,data2,next node address] <--> [previour node address,data3,next node address] <--> [previour node address,data4,NULL]
// So simply, first we checked whether the list is empty or not, if it is empty we made a new node and updated the head pointer to this first node "temp". but if list is not empty, in that case we have just used this newly created node and used its two pointers prev and next to link it with the remaining list!
void insertAtHeadDLL1(Node7* &head, int data) {
    Node7* temp = new Node7(data);
    if(head == NULL) {
        head = temp;
        return;
    }
    temp -> next = head;
    head -> prev = temp;
    head = temp;
}

// So here we just inserted the node in the same way as of from head, just here we have used tail for it!
void insertAtTailDLL1(Node7* &tail, int data) {
    Node7* temp = new Node7(data);
    if (tail == NULL) {
        tail = temp;
        return;
    }
    tail->next = temp;
    temp->prev = tail;
    tail = temp;
}

// You can create this function, using head and tail both, or only head too... that depends on your needs! If you use both head and tail then you can insert from both ends and you dont need to traverse the whole list if in case you want to insert a node at a particular position!
void insertAtAnyPositionDLL1(Node7* &head, Node7* &tail, int position, int data) {
    // Case 1: If the list is empty!
    if(head == NULL) {
        Node7* newNode = new Node7(data);
        head = newNode;
        tail = newNode;
        return;
    }
    
    // Case 2: Insert at position 1 (head)
    if(position == 1) {
        insertAtHeadDLL1(head, data); // Update head and possibly tail if list was empty
        return;
    }

    Node7* temp = head;
    int cnt = 1;

    // Traverse to the node just before the desired position
    while(cnt < position && temp->next != NULL) {
        temp = temp->next;
        cnt++;
    }

    // Case 3: If we reached the end of the list, insert at the tail
    if(temp->next == NULL) {
        insertAtTailDLL1(tail, data);
        return;
    }

    // Case 4: Insert in the middle of the list
    Node7* NodetoInsert = new Node7(data);
    NodetoInsert->next = temp->next;
    if(temp->next != NULL) {
        temp->next->prev = NodetoInsert;
    }
    temp->next = NodetoInsert;
    NodetoInsert->prev = temp;
}



int main() {
    Node7* node1 = new Node7(10);
    Node7* head = node1;
    Node7* tail = node1;

    printNode(head);
    cout<<"Length : "<<getLength(head)<<endl;

    insertAtHeadDLL1(head,9);
    printNode(head);

    insertAtHeadDLL1(head,8);
    insertAtHeadDLL1(head,7);
    insertAtHeadDLL1(head,6);
    insertAtHeadDLL1(head,5);
    printNode(head);

    insertAtTailDLL1(tail,11);
    insertAtTailDLL1(tail,12);
    insertAtTailDLL1(tail,13);
    insertAtTailDLL1(tail,14);
    printNode(head);

    insertAtAnyPositionDLL1(head, tail, 3, 100); // Insertin at any randome position
    printNode(head);
    
    insertAtAnyPositionDLL1(head, tail, 1, 101); // Inserting at Head using this function
    printNode(head);

    cout<<"Head : "<<head->data<<endl;
    cout<<"Tail : "<<tail->data<<endl;
    insertAtAnyPositionDLL1(head, tail, getLength(head)+1, 102); // Inserting at Tail using this function, writing this becoz tumko last position pr insert krna hai and agar sirf getlength() use kroge toh mtlb ki tum 12 position opr insert krna chah rhe ho and that will move the last element one node aage and it will insert 102 at second last position, so to insert at tail you need position of the last element + 1.
    printNode(head);

} // Here we have created a node and inserted at head and tail and at any position of the linkedlist & then printed it, also length of the linkedlists!

// Now lets do some correction.... and that is manlo jaise abhi toh hum pehle se ek node create krte then and then hum uske aage ya peeche se insert krna shuru krte the... maanlo agar vo initial node hi naa vo and hum linkedlist ekdum scratch se banana shuru kre bina uss initial node ke! then we need to do this...
#include<iostream>
using namespace std;

class Node8 {
    public :
    int data;
    Node8* prev;
    Node8* next;

    Node8 (int data) {
        this->data = data;
        this->prev = NULL;
        this->next = NULL;
    }
};

int getLength(Node8* &head) {
    int len = 0;
    Node8* temp = head;
    while(temp != NULL) {
        len++;
        temp = temp->next;
    }
    return len;
}

void insertAtHead(Node8* &head, Node8* &tail, int data) {
    if(head == NULL) {
        Node8* temp = new Node8(data);
        head = temp;
        tail = temp;
    }
    else {
        Node8* temp = new Node8(data);
        temp -> next = head;
        head -> prev = temp;
        head = temp;
    }
}

void insertAtTail(Node8* &head, Node8* &tail, int data) {
    if(tail == NULL) {
        Node8* temp = new Node8(data);
        tail = temp;
        head = temp;
    }
    else {
        Node8* temp = new Node8(data);
        tail->next = temp;
        temp->prev = tail;
        tail = temp;
    }
}

void insertAtAnyPosition(Node8* &head, Node8* &tail, int position, int data) {
    // Insert at position 1 which is head
    if(position == 1) {
        insertAtHead(head,tail,data);
        return;
    }

    Node8* temp = head;
    int cnt = 1;

    while(cnt < position-1) {
        temp = temp->next;
        cnt++;
    }

    if(temp->next == NULL) {
        insertAtTail(head,tail,data);
        return;
    }

    Node8* NodetoInsert = new Node8(data);
    NodetoInsert->next = temp->next;
    NodetoInsert->next->prev = NodetoInsert;
    temp->next = NodetoInsert;
    NodetoInsert->prev = temp;
}

void printNode(Node8* &head) {
    Node8* temp = head;
    while(temp != NULL) {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

int main() {
    Node8* head = NULL; // At the initial stage there is no node at all!
    Node8* tail = NULL;

    // Now we will start adding nodes into it using the insertAtHead and insertAtTail function or insertAtAnyFunction...
    insertAtHead(head,tail,10);
    printNode(head);

    insertAtHead(head,tail,9);
    insertAtHead(head,tail,8);
    insertAtHead(head,tail,7);
    insertAtHead(head,tail,6);
    cout<<"Current Linkedlist is : ";
    printNode(head);

    insertAtTail(head,tail,11);
    insertAtTail(head,tail,12);
    insertAtTail(head,tail,13);
    insertAtTail(head,tail,14);
    cout<<"Current Linkedlist is : ";
    printNode(head);
} // So here the thing is, yahaa kya hua ki jo head and tail hai vo dono starting me dono NULL ko point kr rhe the and then humne kya kiya ki insert at head function call kiya toh pehle ek node create hua and then jo vo head and tail the jo pehle NULL koi point kr rhe the vo ab uss node1 ko point krne lage!
// And then humne uss temp ko head and tail me copy krdiya and then next time se jab bhi insertathead ko use krke jab bhi koi node add hua toh uss time else vaali condition kaam kr rhi thi jo head ko update kr rhi thi and tail vaisa ka vaisa node1 ko point kr rha tha!
// and ye same cheez humne insertattail ke saath bhi krdi! isliye humne tail and head dono hi as a paramter pass krdiye! vrna vaise tail naam se kabhi koi paramter nhi bnaate hai! head se hi saara kaam karaate hai!
// So if you want to create a insertAtTail function using only head! then in that case, pehle hum head se last pointer tak jayenge loop me iterate karaake! and then hum jaake value/data insert krenge! isme thori time compelxity badh jayegi which will be O(n), but space bachega jo humne tail banane me lagaya tha!

// Now lets move to deleting a node!
// Approach : Jaise pehle rhi thi same vaisi hi, pehle head ko delete krna seekhte hai, toh jo head hai uska prev toh NULL ko point kr rha hoga and jo uska next hai vo next node ko point kr rha hoga, and jo next node hai uska prev head ko point kr rha hoga, and then humne head update bhi krna hai and then memory bhi free krni hai!
// So flow will be...
// temp->next->prev = NULL, then head = temp->next, then temp->next = NULL and then last me memory free krdo destructor call krke using the delete keyword kyunki these nodes are dynamically allocated and they are to be deleted manually!
// Ab agar head ke alawa koi aur node delete krna hota toh, the flow would be...
// curr->prev = NULL, then prev->next = curr->next, then curr->next = NULL and then lastly memory free krdena hai!
// Now lets code it....
#include<iostream>
using namespace std;

class Node9 {
    public :
    int data;
    Node9* prev;
    Node9* next;

    Node9 (int data) {
        this->data = data;
        this->prev = NULL;
        this->next = NULL;
    }

    ~Node9() { // Bina destructor banaye bhi kaam chal jaata! koi dikkat nhi hoti, bss thora cuctomize krne ke liye deletion ko we are using destructor
        int value = this->data;
        if(next != NULL) {
            delete next;
            next = NULL;
        }
        cout<<"Memory free for the node with data value : "<<value<<endl;
    }
};

int getLength(Node9* &head) {
    int len = 0;
    Node9* temp = head;
    while(temp != NULL) {
        len++;
        temp = temp->next;
    }
    return len;
}

void insertAtHead(Node9* &head, Node9* &tail, int data) {
    if(head == NULL) {
        Node9* temp = new Node9(data);
        head = temp;
        tail = temp;
    }
    else {
        Node9* temp = new Node9(data);
        temp -> next = head;
        head -> prev = temp;
        head = temp;
    }
}

void insertAtTail(Node9* &head, Node9* &tail, int data) {
    if(tail == NULL) {
        Node9* temp = new Node9(data);
        tail = temp;
        head = temp;
    }
    else {
        Node9* temp = new Node9(data);
        tail->next = temp;
        temp->prev = tail;
        tail = temp;
    }
}

void insertAtAnyPosition(Node9* &head, Node9* &tail, int position, int data) {
    // Insert at position 1 which is head
    if(position == 1) {
        insertAtHead(head,tail,data);
        return;
    }

    Node9* temp = head;
    int cnt = 1;

    while(cnt < position-1) {
        temp = temp->next;
        cnt++;
    }

    if(temp->next == NULL) {
        insertAtTail(head,tail,data);
        return;
    }

    Node9* NodetoInsert = new Node9(data);
    NodetoInsert->next = temp->next;
    NodetoInsert->next->prev = NodetoInsert;
    temp->next = NodetoInsert;
    NodetoInsert->prev = temp;
}

void printNode(Node9* &head) {
    Node9* temp = head;
    while(temp != NULL) {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

void deleteNode(Node9* &head, int position) {
    // Deleting the first node...
    if(position == 1) {
        Node9* temp = head;
        temp->next->prev = NULL;
        head = temp->next;
        temp->next = NULL;
        // Ab memory free krdo...
        delete temp;
    }

    // Deleting middle nodes and last node...
    else {
        Node9* current = head;
        Node9* prev = NULL;

        int cnt = 1;
        while(cnt < position) {
            prev = current;
            current = current->next;
            cnt++;
        }

        prev->next = current->next;
        if(current->next != NULL) { // Checking to avoid null pointer dereference
            current->next->prev = prev;
        }
        current->prev = NULL;
        current->next = NULL;
        delete current;
    }
}

int main() {
    Node9* head = NULL;
    Node9* tail = NULL;

    // Now we will start adding nodes into it using the insertAtAnyFunction...
    insertAtAnyPosition(head,tail,1,101);
    insertAtAnyPosition(head,tail,2,102);
    insertAtAnyPosition(head,tail,3,103);
    insertAtAnyPosition(head,tail,4,104);
    insertAtAnyPosition(head,tail,5,105);
    insertAtAnyPosition(head,tail,6,106);
    cout<<"Current Linkedlist is : ";
    printNode(head);

    deleteNode(head,1);
    printNode(head);

    deleteNode(head,4);
    printNode(head);

    deleteNode(head,getLength(head)); // Using the getlength function taaki hum last node ko delete kr sake!
    printNode(head);
}

// Circular Linkedlist : Ye bhi do type ke hote hai, Singly circular linkedlist! and Doubly circular linkedlist! So overall isme kya hota hai ki in case of singly ki jo last node hota hai uska next linkedlist ke head ko point kr rha hota hai! and in case of double jo last node hota hai uska next linkedlist ke head ko point kr rha hota hai and jo head ka prev hai vo last node ko point kr rha hota hai!
// Yahaa humari approach thori alag hogi, yahaa hume head ki zarurat nhi hai yahaa hum tail ka use krenge! kyunki uss tail se hi hum tail->next krke head tak pohoch sakte hai and tail se toh hum tail ko access kr hi sakte hai! in case of singly, in case of doubly we can use the tail->prev and tail->next and all to access any node... also yahaa head ka koi logic nhi banta kyunki jab linkedlist circular hai toh isliye!
// Also yaha ye bhi differene hai ki yahaa hum position kuch define nhi kar payenge as such! toh isliye yaha kisi ek element ke respect me dusra node add ya delete krenge!
// In case of empty list, we will create a node which will have a value and its next will be pointing towards its ownself!
// And agar pehle se koi node hai toh uss element ke respect me daalenge ki kahaa nayaa node insert hoga!
// Now lets see the approach...
// In case of empty list : Pehle hum ek node create krenge and isko hum khudse hi point kraa denge! tail = NULL, temp = tail, temp->next = temp.
// Second case when there is already a node in the linkedlist : Then in that case pehle toh humne ek forward name se ek space banai and isme humne temp->next store kiya, then humne current->next = temp, temp->next = forward.
// Now suppose there are already two nodes are present and now we want to insert a third node : Imagine it like, [3,address of next node] -> [5,pointing towards the supposedly first node], then ab isme we have 2 cases maanlo we want to insert after node with data 3, so this is the flow, pehle ek node create kro and then jahaa 3 vaala node point kr rha hai na usk store krlo, forward = curr->next; yaa isse better hai you can do is, jo nayaa node humne create kiya usko we have named temp, so temp->next = current->next; and then current->next = temp; Another case can be if we want to insert a node after 5, so in that case, so first create a node, temp->next = current->next; current->next = temp;
// Now lets code these logic...
#include<iostream>
using namespace std;

class Node10{
    public :
    int data;
    Node10* next;

    Node10 (int data) {
        this->data = data;
        this->next = NULL;
    }

    ~Node10() {
        int value = this->data;
        if(next != NULL) {
            delete next;
            next = NULL;
        }
        cout<<"Memory free for the node with data value : "<<value<<endl;
    }
};

void insertNode(Node10* &tail, int element, int data) {
    // Suppose the list is empty...
    if(tail == NULL) {
        Node10* newNode = new Node10(data);
        tail = newNode;
        newNode->next = newNode;
    }
    else {
        // Now if the list is not empty...and the element we have input is present!
        Node10* current = tail;
        // Now we are finding that element vaala node thru traversal!
        while(current->data != element) {
            current = current->next;
        } // Also this insertNode function is insertion after the first occurence of a element, like agar ek element ki more than one occurence hai, toh ye pehle hi occurence pr insert krdega!
        // Now elememnt is found and the current is representing that element vaala node!
        Node10* temp = new Node10(data);
        temp->next = current->next;
        current->next = temp;
    }
} // Now isme ye jo element hai in case of empty list agar hum function call me ye element pass kr bhi dete hai fir bhi koi fark nhi padega kyunki vo element list me hai hi nhi!
// Now lets see how to print the list...
// here in this case insertion is based on elements, which can case certain confusions and all, becoz of duplicates of the element may present, but iska ek pro bhi hai hum data ke base pr bhi kr sakte hai, but sabse better rehta hai ki position ke base pr insertion krna!

void printNode(Node10* tail) {
    Node10* temp = tail;
    // cout<<tail->data<<" ";

    // while(tail->next != temp) {
    //     tail = tail->next;
    //     cout<<tail->data<<" ";
    // }
    // cout<<endl;
    // Iss upar vaale logic se bhi print hojayega linkedlist, but we have another way of doing the same thing, that is do while loop, we rarely use it but here we can!

    do {
        cout<<tail->data<<" ";
        tail = tail->next;
    } while(tail != temp);
    cout<<endl;
}

int main() {
    Node10* tail = NULL; // This shows that the list is empty!

    insertNode(tail,-1,3); // Yahaa humne -1 daal diya but kyunki ye empty list thi startting me toh ye -1 match nhi hoga kabhi and iss function call se seedha 3 insert hojayega! and linkedlist will have its first node which is 3
    cout<<"Current Linked List : ";
    printNode(tail);

    insertNode(tail,3,5); // Isme humne vo 2nd case apply kiya, jab pehle iss function call se poore list me check hua ki kahin 3 hai and jahaa 3 mila uske aage 5 add krdiya! vaise ye same cheez hui toh empty list ke case me bhi hai bss vahaa kabhi -1 mila nhi isliye if vaala statement execute hua insertNode function ka first node ke case me!
    cout<<"Current Linked List : ";
    printNode(tail);

    insertNode(tail,5,7);
    cout<<"Current Linked List : ";
    printNode(tail);

    insertNode(tail,7,9);
    cout<<"Current Linked List : ";
    printNode(tail);

    insertNode(tail,3,4);
    cout<<"Current Linked List : ";
    printNode(tail);

    insertNode(tail,9,10);
    cout<<"Current Linked List : ";
    printNode(tail);

    insertNode(tail,7,8);
    cout<<"Current Linked List : ";
    printNode(tail);

    // insertNode(tail,-1,2); // Iss case me kuch hua hi nhi kyunki -1 exist hi nhi krta! empty ke case me hogya tha kyunku uss time list empty thi/ tail NULL tha but iss time nhi! but basically yahaa humara ye try tha ki hum 3 se pehle 2 daal de so for that being said iska koi sense nhi hai! kyunki... it is circular, so 3 ke pehle 2 daalde ya jo tail vaala element hai uske baad 2 daalde it means the same! so just insert 2 after 10...
    insertNode(tail,10,2);
    cout<<"Current Linked List : ";
    printNode(tail);
}

// Deletion of node in case of Circular Linkedlists!
// So we will here try to delete when we are given with the node's data, and uske basis pr hum delete krenge! also hum position ke basis pr bhi delete kr sakte hai but you can try on your own, here lets try for only data based deletion!
#include<iostream>
using namespace std;

class Node11{
    public :
    int data;
    Node11* prev;
    Node11* next;

    Node11 (int data) {
        this->data = data;
        this->next = NULL;
    }

    ~Node11() {
        int value = this->data;
        if(next != NULL) {
            delete next;
            next = NULL;
        }
        cout<<"Memory free for the node with data value : "<<value<<endl;
    }
};

void insertNode(Node11* &tail, int element, int data) {
    // Suppose the list is empty...
    if(tail == NULL) {
        Node11* newNode = new Node11(data);
        tail = newNode;
        newNode->next = newNode;
    }
    else {
        // Now if the list is not empty...and the element we have input is present!
        Node11* current = tail;
        // Now we are finding that element vaala node thru traversal!
        while(current->data != element) {
            current = current->next;
        }
        // Now element is found and the current is representing that element vaala node!
        Node11* temp = new Node11(data);
        temp->next = current->next;
        current->next = temp;
    }
}

void deleteNode(Node11* &tail, int value) {
    // If the list is empty!
    if(tail == NULL) {
        cout<<"Linkedlist is empty!"<<endl;
        return;
    }
    else {
        // If the list is non-empty
        // and assuming the "value" is present in the list!
        Node11* prev = tail; // Here we have defined ki prev and tail kya kya hai!
        Node11* curr = prev->next;
        while(curr->data != value) {
            prev = curr;
            curr = curr->next;
        }
        prev->next = curr->next;
        if(tail == curr) {
            tail = prev;
        }
        curr->next = NULL;
        delete curr;
    }
}
// So basically what we did is, ek jo circular linkedlist hai usme hume jis node ko delete krna hai vo hum identify yahaa value se kr rhe hau uss node ki, so hum uss value ke base pr uss node tak pohche and then humne uss node ke prev ke next ko current node (mtlb jahaa actual value hai) ke next pr point krwa diya! and jo current node hai uske next ko NULL krdiya! isme tail ko prev node pr point kraane ki zarurat nhi hai kyunki its a circular LL toh vo toh pehle se hi point kr rha hoga!

void printNode(Node11* tail) {
    Node11* temp = tail;
    do {
        cout<<tail->data<<" ";
        tail = tail->next;
    } while(tail != temp);
    cout<<endl;
}

int main() {
    Node11* tail = NULL; // This shows that the list is empty!
    deleteNode(tail,3); // Iss time it will print the LL is empty!

    // now lets insert some data...
    insertNode(tail,-1,3);
    insertNode(tail,3,4);
    insertNode(tail,4,5);
    insertNode(tail,5,6);
    insertNode(tail,6,7);
    insertNode(tail,7,8);
    cout<<"Current Linked List is : ";
    printNode(tail);

    deleteNode(tail,3); // Iss case me ek dikkat ho rhi thi where, kyunki ye LL kuch aise hai, 3 4 5 6 7 8 so iss case me current = 3 and so prev = 8 hojayega! so ab agar hum 3 ko delete krte hai toh prev ab current->next ko point krega! toh yahaa tak theek tha, but jab humne 3 delete kiya toh tail abhi bhi current pr tha toh usko humne fir if statement ki help se update krdiya! ye dikkat sirf tab hi aati hai jab kisi aise node ko delete kr rhe hai jisko tail point kr rakha hai! and yahaa pr 3 vaisa hi node tha, so isliye we need to add this if condition in the deleteNode statement!
    printNode(tail);
}

// Toh upar toh we have handles two cases one of trying deletion on empty LL and deleting a single node from the LL when there are more than 1 nodes... now lets see deletion of the node when there is only one node in LL...
// Iss case me kya hoga ki, like suppose you have a LL with only one node, [3,address of itself], now isme kya hoga ki iska tail bhi yhi pr hoga, iska prev and iska current bhi yhi pr point kr rha hoga, toh jab hum isko delete krenge toh iski memory toh free hogyi! toh jab hum print karayenge LL tab jo cheez humne delete krdi usko kaise vapis print ho sakti hai? isliye error ya segmentation fault ya garbage value print hogi, lets solve this thing, so that we get a more genuine answer!
#include<iostream>
using namespace std;

class Node12{
    public :
    int data;
    Node12* prev;
    Node12* next;

    Node12 (int data) {
        this->data = data;
        this->next = NULL;
    }

    ~Node12() {
        int value = this->data;
        if(next != NULL) {
            delete next;
            next = NULL;
        }
        cout<<"Memory free for the node with data value : "<<value<<endl;
    }
};

void insertNode(Node12* &tail, int element, int data) {
    // Suppose the list is empty...
    if(tail == NULL) {
        Node12* newNode = new Node12(data);
        tail = newNode;
        newNode->next = newNode;
    }
    else {
        Node12* current = tail;
        while(current->data != element) {
            current = current->next;
        }
        Node12* temp = new Node12(data);
        temp->next = current->next;
        current->next = temp;
    }
}

void deleteNode(Node12* &tail, int value) {
    // If the list is empty!
    if(tail == NULL) {
        cout<<"Linkedlist is empty!"<<endl;
        return;
    }
    else {
        Node12* prev = tail; // Here we have defined ki prev and tail kya kya hai!
        Node12* curr = prev->next;
        while(curr->data != value) {
            prev = curr;
            curr = curr->next;
        }
        prev->next = curr->next;
        // When there is only 1 node in linked list...
        if(curr == tail) {
            tail = NULL;
        }
        // for >= 2 nodes linkedlist
        else if(tail == curr) {
            tail = prev;
        }
        curr->next = NULL;
        delete curr;
    }
}

void printNode(Node12* tail) {
    Node12* temp = tail;
    // Empty list...
    if(tail == NULL) {
        cout<<"Linkedlist is Empty!";
        return;
    }
    do {
        cout<<tail->data<<" ";
        tail = tail->next;
    } while(tail != temp);
    cout<<endl;
}

int main() {
    Node12* tail = NULL;
    insertNode(tail,-1,3);
    cout<<"Current Linked List is : ";
    printNode(tail);
    deleteNode(tail,3);
    printNode(tail);
}
// Must try the dry run for all of the codes and logic and try for yourself also for better understanding! visit codestudio for more topics related to it!

// ---------------------------------------------------------- LECTURE 45 - Linked Lists Questions --------------------------------------------------------------------------------------------------------->
// Question : Reverse a Linkedlist
// Approach 1 (An iterative approach): We can do this like, suppose you have linkedlist like [3,address of next node] -> [4,address of next node] -> [5,address of next node] -> [6,address of next node] -> [7,address of next node] -> NULL... ab iss linkedlist me jo pehla node hai vo head hai and last vaala tail, toh arrays me kya krte the ki hum poore elements ko yahaa se vahaa utha kr rakhte the, but here we just reverse the links, that ki jo node abhi right vaale node ko point kr rha tha vo ab bss pichle vaale node ko point kr rha tha
// Now lets see how we will achieve this...
// So first we will make a pointer name as "prev" jo kisi NULL ko point kr rha hoga, then we will create a "curr" jo abhi ke liye current head node ko point kr rha hoga, then ab hume reverse krna hai toh hume saare links ulte krne honge, toh hum agar starting me hi head ke next ko next node se hataa ke prev jo ki humne NULL banaya hua hai uss pr point kraa denge toh head ka link baaki linkedlist ke elements se toot jayega! and our linkedlist will be lost! so for that we will also create a forward pointer jo curr->next ko point kr rha hoga!
// Now, hum jaise jaise curr vaale nodes ke pointers ko "unke" prev pr point krte jayenge, vaise vaise hum forward ko bhi aage shift krte jaana hai! for this we will use the while loop! and jab curr == NULL hojayega tab hum loop se exit hojayenge! as kyunki iss time pr prev new head ko point kr rha hoga (jo head reverse krne se pehle tail tha)! and then lastly we will return prev, becoz that is the new head, and hum head se hi reversed linkedlist print krenge!
// Lets code this approach...
#include<iostream>
using namespace std;

class Node13 {
    public :
    int data;
    Node13* next;

    Node13(int data) {
        this->data = data;
        this->next = NULL;
    }

    ~Node13() {
        int value = this->data;
        if(this->next != NULL) {
            delete next;
            this->next = NULL;
        }
        cout<<"Memory is free for the node with data "<<value<<endl;
    }
};

void insertatHead(Node13* &head, int data) {
    Node13* temp = new Node13(data);
    temp->next = head;
    head = temp;
}

void insertAtTail(Node13* &tail, int data) {
    Node13* temp = new Node13(data);
    tail->next = temp;
    tail = tail->next;
}

void insertAtAnyPosition(Node13* &head, Node13* &tail, int position, int data) {
    if(position == 1) {
        insertatHead(head,data);
        return;
    }

    Node13* temp = head;
    int cnt = 1;

    while(cnt < position-1) {
        temp = temp->next;
        cnt++;
    }

    if(temp->next == NULL) {
        insertAtTail(tail,data);
        return;
    }

    Node13* NodetoInsert = new Node13(data);
    NodetoInsert->next = temp->next;
    temp->next = NodetoInsert;
}

Node13* ReversedLinkedList(Node13* head) {
    // In case of empty list or list have only one node...
    if(head == NULL || head->next == NULL) {
        return head;
    }
    // Now if list is not empty and has more than 1 node...
    Node13* prev = NULL; // Prev create krke usko initially null pr point kraa diya
    Node13* curr = head; // current create krke usko initially current head pr point kraa diya
    Node13* forward = NULL; // forward ko current ke next pr point kraa diya taaki iterate kr sake linkedlist ko bina list ko lost kiye

    while(curr != NULL) {
        // then iterated the list.... by moving the forward further and changing the links using curr and prev pointers!
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    }
    return prev;
}

void printNode(Node13* &head) {
    Node13* temp = head;
    while(temp != NULL) {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

int main() {
   Node13* node1 = new Node13(10);
   Node13* head = node1;
   Node13* tail = node1;
   printNode(head);

    // Inserting more elements to the linkedlist...
    insertAtAnyPosition(head, tail, 2, 20);
    insertAtAnyPosition(head, tail, 3, 30);
    insertAtAnyPosition(head, tail, 4, 40);
    insertAtAnyPosition(head, tail, 5, 50);
    insertAtAnyPosition(head, tail, 6, 60);
    insertAtAnyPosition(head, tail, 7, 70);
    insertAtAnyPosition(head, tail, 8, 80);
    cout<<"Current Linkedlist : ";
    printNode(head);

    cout<<"Reversed Linkedlist : ";
    Node13* reversedHead = ReversedLinkedList(head);
    printNode(reversedHead);
} // This approach time complexity and space complexity are, T(n) = O(n) & Space Complexity : O(1).
// This was an iterative approach, lets see another one...

// Approach 2 (A recursive one) : Toh jaisa abhi tak hum krte aaye hai recursive approach me, ki ek case sambhal lo base condition btaa do ki kahaa rukna hai baaki recursion sambhal lega!
// So what we will do is, hum first node ke next ko prev pr point kraa denge and baaki then recursion sambhal lega! 
// Base case will be ki hum jab last me pohochenge tab humara curr null hogya hoga and prev last node ko point kr rha hoga (jo reversed list ka head hai), so hum head ko prev me copy krke return krdenge! and then jo conditions upar lagai thi forwards curr and prev ki, vhi same operations yahaa pr bhi perform honge! and then baaki me recursive call krdenge!
// Lets code this....
#include<iostream>
using namespace std;

class Node14 {
    public :
    int data;
    Node14* next;

    Node14(int data) {
        this->data = data;
        this->next = NULL;
    }

    ~Node14() {
        int value = this->data;
        if(this->next != NULL) {
            delete next;
            this->next = NULL;
        }
        cout<<"Memory is free for the node with data "<<value<<endl;
    }
};

void insertatHead(Node14* &head, int data) {
    Node14* temp = new Node14(data);
    temp->next = head;
    head = temp;
}

void insertAtTail(Node14* &tail, int data) {
    Node14* temp = new Node14(data);
    tail->next = temp;
    tail = tail->next;
}

void insertAtAnyPosition(Node14* &head, Node14* &tail, int position, int data) {
    if(position == 1) {
        insertatHead(head,data);
        return;
    }

    Node14* temp = head;
    int cnt = 1;

    while(cnt < position-1) {
        temp = temp->next;
        cnt++;
    }

    if(temp->next == NULL) {
        insertAtTail(tail,data);
        return;
    }

    Node14* NodetoInsert = new Node14(data);
    NodetoInsert->next = temp->next;
    temp->next = NodetoInsert;
}

void reverse(Node14* &head, Node14* curr, Node14* prev) {
    // Base case
    if(curr == NULL) {
        head = prev;
        return;
    }
    Node14* forward = curr->next;
    reverse(head,forward,curr);
    curr->next = prev;
}

Node14* ReversedLinkedList(Node14* head) {
    // In case of empty list or list have only one node...
    if(head == NULL || head->next == NULL) {
        return head;
    }
    // Now if list is not empty and has more than 1 node...
    Node14* curr = head;
    Node14* prev = NULL;
    reverse(head, curr, prev);
    return head;
}

void printNode(Node14* &head) {
    Node14* temp = head;
    while(temp != NULL) {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

int main() {
   Node14* node1 = new Node14(10);
   Node14* head = node1;
   Node14* tail = node1;
   printNode(head);

    // Inserting more elements to the linkedlist...
    insertAtAnyPosition(head, tail, 2, 20);
    insertAtAnyPosition(head, tail, 3, 30);
    insertAtAnyPosition(head, tail, 4, 40);
    insertAtAnyPosition(head, tail, 5, 50);
    insertAtAnyPosition(head, tail, 6, 60);
    insertAtAnyPosition(head, tail, 7, 70);
    insertAtAnyPosition(head, tail, 8, 80);
    cout<<"Current Linkedlist : ";
    printNode(head);

    cout<<"Reversed Linkedlist : ";
    Node14* reversedHead = ReversedLinkedList(head);
    printNode(reversedHead);
} // So here the time complexity is again the same O(n) and space complexity is O(n)!

// Question 2 : Find middle of the linkedlist!
// Approach 1 : So what we will do is we will find the length of the list! and then we will calculate the middle node! in case of odd length, the middle node vo hoga jo ekdum beech me hai! and in case of even length, middle node 2 honge toh unme se hum iss question ke liye right vaala consider krenge! now lets understand the rest of it through code...
#include<iostream>
using namespace std;

class Node15 {
    public :
    int data;
    Node15* next;

    Node15(int data) {
        this->data = data;
        this->next = NULL;
    }

    ~Node15() {
        int value = this->data;
        if(this->next != NULL) {
            delete next;
            this->next = NULL;
        }
        cout<<"Memory is free for the node with data "<<value<<endl;
    }
};

void insertatHead(Node15* &head, int data) {
    Node15* temp = new Node15(data);
    temp->next = head;
    head = temp;
}

void insertAtTail(Node15* &tail, int data) {
    Node15* temp = new Node15(data);
    tail->next = temp;
    tail = tail->next;
}

void insertAtAnyPosition(Node15* &head, Node15* &tail, int position, int data) {
    if(position == 1) {
        insertatHead(head,data);
        return;
    }

    Node15* temp = head;
    int cnt = 1;

    while(cnt < position-1) {
        temp = temp->next;
        cnt++;
    }

    if(temp->next == NULL) {
        insertAtTail(tail,data);
        return;
    }

    Node15* NodetoInsert = new Node15(data);
    NodetoInsert->next = temp->next;
    temp->next = NodetoInsert;
}

void printNode(Node15* &head) {
    Node15* temp = head;
    while(temp != NULL) {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

// Function to find the length of the list...
int getlength(Node15* head) {
    int len = 0;
    while(head != NULL) {
        len++;
        head = head->next;
    }
    return len;
}

// Function to find the middle node...
Node15* findMiddleNode(Node15* head) {
    int len = getlength(head);
    int ans = (len/2);
    Node15* temp = head;
    int cnt = 0;
    while(cnt < ans) {
        temp = temp->next;
        cnt++;
    }
    return temp;
} // So here what we did is, pehle getlength se length nikala! and then ans me len/2 store kiya, then list ke head ko temp me store kiya! and jo ans me jo len/2 store hai vahaa tak loop ko iterate kraa ke jab loop exit hua toh temp me vo node tha jo middle node hai! toh in the last humne temp return krdiya!
// in case of even number of elements, let say 6, then ans = 3 (mtlb humara loop 3 baar chalega), and humara jo middle node hoga vo 4th position pr hoga! so loop start hua, cnt = 0 se, and now the thing is, starting me temp jo hai vo head pr tha, toh cnt = 0 me vo node2 pr aaya, then cnt = 1 pr vo node3 pr aaya, then cnt = 2 hua toh vo node4 pr aagya! and then jab cnt = 3 hua toh loop exit hogya and jo temp me node4 store hua vo return krdiya humne!
// Toh yahaa thora dekhna padega ki kya ans chahiye uske according hum apna loop utni baar chalaa sakte hai, also ans me (len/2) store krna hai ya (len/2) + 1, ye sab pehle hi dekhna hoga! love babbar ka answer yhi galat aa rha tha!

int main() {
    Node15* node1 = new Node15(10);
    Node15* head = node1;
    Node15* tail = node1;
    printNode(head);

    // Inserting odd number of element...
    insertAtAnyPosition(head,tail,2,20);
    insertAtAnyPosition(head,tail,3,30);
    insertAtAnyPosition(head,tail,4,40);
    insertAtAnyPosition(head,tail,5,50);
    // Inserting another element to make it an list weith even number of elements...
    insertAtAnyPosition(head,tail,6,60); // in this case 30 and 40 both will be middle element but for this question we are considering the right one is the middle element, so 40 will be the ans!
    
    cout<<"Current Linked List : ";
    printNode(head);

    Node15* middleNode = findMiddleNode(head);
    cout<<"Middle element of the Linked List is : "<<middleNode->data<<endl;
}
// Time Complexity : T(n) + T(n/2); -> T(n) for getlength function ke liye and T(n/2) findmiddlenode vaale function me loop ke liye!
// So overall humari TC : O(n)...
// But here we can see that ek baar hum full traversal kr rhe hai and ek baar hum sirf half hi kr rhe hai! so lets see the optimized solution based on this approach...

// Optimized Approach : Now suppose you have two person one is fast and another is slow, fast one runs 2 metre in 1 sec and slow one runs 1 metre in 1 sec! Now, jitni agar 5 sec ki race hai usme fast person will cover 10 metres and slow one will cover 5 metres! so we can see ki slow half distance cover krega, toh yahaa hum iss logic ka use krke slow ki help se middle node nikal sakte hai!
// Now lets see the coding logic...
// in case of empty list : NULL (no middle node)
// in case of one node : Head
// in case of 2 nodes : Head->next
// In all other cases, we will keep fast at head->next and slow at head, now in case of suppose odd 5 nodes, and starting with slow at head and fast at head->next means node2, so first iteration me slow node2 pr pohchega and uss hi iteration me fast node4 pr pohchega, now dusri iteration me slow ek aage badh ke node3 pr pohochega and fast node4 se do aage NULL pr pohoch jayega and yahaa hum loop se exit hojayenge! and we will return slow, kyunki vo apni sahi jagah pohoch gya!
// In case of even number of nodes, slow will ba again at head and fast will be at head->next which is node2, now in the first iteration slow will be at node2 and fast will be at node4 and then in the next iteration slow will be at node3 and fast will be at node6 and then in the next iteration, slow will be at node4 and fast can't move 2 nodes further becoz there is only one left and that is NULL, so fast will move only one step ahead and here fast is now pointing at NULL, and here we will exit the loop and we will see that slow again covered our half distance, as we have finalised the middle node in case of even is the right one... hence we got it! and now we will return the slow...
// Lets code this logic...
#include<iostream>
using namespace std;

class Node16 {
    public :
    int data;
    Node16* next;

    Node16(int data) {
        this->data = data;
        this->next = NULL;
    }

    ~Node16() {
        int value = this->data;
        if(this->next != NULL) {
            delete next;
            this->next = NULL;
        }
        cout<<"Memory is free for the node with data "<<value<<endl;
    }
};

void insertatHead(Node16* &head, int data) {
    Node16* temp = new Node16(data);
    temp->next = head;
    head = temp;
}

void insertAtTail(Node16* &tail, int data) {
    Node16* temp = new Node16(data);
    tail->next = temp;
    tail = tail->next;
}

void insertAtAnyPosition(Node16* &head, Node16* &tail, int position, int data) {
    if(position == 1) {
        insertatHead(head,data);
        return;
    }

    Node16* temp = head;
    int cnt = 1;

    while(cnt < position-1) {
        temp = temp->next;
        cnt++;
    }

    if(temp->next == NULL) {
        insertAtTail(tail,data);
        return;
    }

    Node16* NodetoInsert = new Node16(data);
    NodetoInsert->next = temp->next;
    temp->next = NodetoInsert;
}

void printNode(Node16* &head) {
    Node16* temp = head;
    while(temp != NULL) {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

Node16* getMiddleNode(Node16* head) {
    if(head == NULL || head->next == NULL) {
        return head;
    }
    Node16* slow = head;
    Node16* fast = head->next;
    while(fast != NULL) {
        fast = fast->next;
        if(fast != NULL) {
            fast = fast->next;
        }
        slow = slow->next;
    }
    return slow;
}

Node16* findMiddleNode(Node16* head) {
    getMiddleNode(head);
}

int main() {
    Node16* node1 = new Node16(10);
    Node16* head = node1;
    Node16* tail = node1;
    printNode(head);

    // Inserting odd number of element...
    insertAtAnyPosition(head,tail,2,20);
    insertAtAnyPosition(head,tail,3,30);
    insertAtAnyPosition(head,tail,4,40);
    insertAtAnyPosition(head,tail,5,50);
    // Inserting another element to make it an list weith even number of elements...
    insertAtAnyPosition(head,tail,6,60); // in this case 30 and 40 both will be middle element but for this question we are considering the right one is the middle element, so 40 will be the ans!
    
    cout<<"Current Linked List : ";
    printNode(head);

    Node16* middleNode = findMiddleNode(head);
    cout<<"Middle element of the Linked List is : "<<middleNode->data<<endl;
}
// So this is the more optimized solution! here the TC : O(n) and SC : O(1)

// ---------------------------------------------------------- LECTURE 46 - Linked Lists Questions --------------------------------------------------------------------------------------------------------->
// Question 1 : Reverse the Linkedlist in the groups of K
// Like suppose you have a linkedlist, node1 -> node2 -> node3 -> node4 -> node5 -> node6 -> NULL.
// Now, if we are asked to reverse the linkedlist in the group of K, then if K = 2, then it means to reverse the linkedlist in the group of 2, means the final output will be, node2 -> node1 -> node4 -> node3 -> node6 -> node5 -> NULL here the head will be node2, and then similarly for K equal to any other value...
// lets see the approach : Now if you get the input 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> NULL here the head is 2, and now in this case, the reverse with the K group will be like, 3 -> 2 -> 5 -> 4 -> 7 -> 6 -> NULL.
// To do this pehle hum iteratively pehle do nodes ko reverse krenge and then baaki ke jo elements hai unko recursively solve krke iske aage lgaa denge!
// Pehle lets code then you we will do a dry run! to understand it clearly!
#include<iostream>
using namespace std;

class Node17 {
    public :
    int data;
    Node17* next;

    Node17(int data) {
        this->data = data;
        this->next = NULL;
    }

    ~Node17() {
        int value = this->data;
        if(this->next != NULL) {
            delete next;
            this->next = NULL;
        }
        cout<<"Memory is free for the node with data "<<value<<endl;
    }
};

void insertatHead(Node17* &head, int data) {
    Node17* temp = new Node17(data);
    temp->next = head;
    head = temp;
}

void insertAtTail(Node17* &tail, int data) {
    Node17* temp = new Node17(data);
    tail->next = temp;
    tail = tail->next;
}

void insertAtAnyPosition(Node17* &head, Node17* &tail, int position, int data) {
    if(position == 1) {
        insertatHead(head,data);
        return;
    }

    Node17* temp = head;
    int cnt = 1;

    while(cnt < position-1) {
        temp = temp->next;
        cnt++;
    }

    if(temp->next == NULL) {
        insertAtTail(tail,data);
        return;
    }

    Node17* NodetoInsert = new Node17(data);
    NodetoInsert->next = temp->next;
    temp->next = NodetoInsert;
}

void printNode(Node17* &head) {
    Node17* temp = head;
    while(temp != NULL) {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

Node17* ReverseK(Node17* head, int K) {
    // Base case...
    if(head == NULL) {
        return NULL;
    }
    // In other cases...
    // Step 1 : Reverse first K Nodes...
    Node17* next = NULL;
    Node17* curr = head;
    Node17* prev = NULL;
    int count = 0;
    while( curr != NULL && count < K) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        count++;
    }
    // Step 2 : Recursion will handle rest of it...
    if(next != NULL) {
        head->next = ReverseK(next,K);
    }
    // Step 3 : Return the head of the reversed list...
    return prev;
}
// So what we did here is, Now suppose jo LL input me aaya hai that is 1 -> 2 -> 3 -> 4 -> NULL. now, hume isko reverse krna hai in K groups! and here for demo we let K = 2, now first we will take first 2 node, 1 -> 2 -> remaining LL, and here head is at 1, Now as hum log LL ko reverse krne ke time sirf links ko reverse krdete hai toh kaam ban jaata hai! toh bss yahaa bhi jo 1 -> 2 -> remainging list, isme se humne 2 vaali link ko hataa ke 1 pr point kraa diya and 1 jo pehle 2 ko point kr rha tha ab vo peeche ki taraf kisi NULL ko point kra denge! so what we got is, NULL <- 1 <- 2
// Now, ye sab cheeze hui kaise toh ye sab hua humare inn operations se, humne pehle Node17* next and prev ko null pr point karaya and curr ko head pr, mtlb ki at this moment head is at 1, mtlb in 1 -> 2 -> NULL, isme head is at 1, and prev and next are at NULL now we iterated a loop, where we put the condition ki jab tak current null na hojaye and jo count hai vo K se kam na hojaye, ye tab hoga jab humaare LL me jo k value hai usse kam nodes bache hai in that case hum exit hojayenge loop se, and now iss loop ke andar we did operations! lets understand how these operations are helping in reversing the first 2 nodes (as K = 2)
// So first we wrote, next = curr->next; means next ko NULL se hataa ke curr ke next node pr point karaa do means now the next is at 2 node, and then humne curr->next = prev; krdiya, isse kya hua ki prev me toh NULL tha and isse humne current ke next me NULL daal diya! means now at this moment curr uss par abhi head toh hai pr vo abhi NULL ko point kr rha hai! as in our approach humne discuss kiya tha ki hume links reverse krni hai toh bss hum vhi kr rhe hai current (which is currently head) usko NULL point kraa ke (mtlb ek tarah se kehdo ki peeche point kraa ke) now, we did prev = curr; it means, ab iss moment me curr and prev dono hi 1 ko point kr rhe hai! and next 2 ko point kr rha hai! now we did is curr = next; mtlb ab jahaa next point kr rha hai vaaha current point kr rha hai! and then humne count aage badhaa diya!
// Now lets summarize what we did, pehle jahaa head point kr rha tha vahaa current point kr rha tha! and prev and next NULL ko point kr rhe the! then in the first line of while loop, humne next ko NULL se shift krke vahaa point kraa diya jahaa curr ka next point kr rha tha, then humne next line me curr (head) ke next ko vahaa point kraa diya jahaa prev point kr rha tha mtlb ki NULL, then in next line prev ko humne vahaa point kraa diya jahaa curr (head) abhi point kr rha hai! and then in next line humne current ko vahaa point kraa diya jahaa next point kr rha hai! mtlb ki at this moment, jab loop end hone vaala hai tab humara jo pehla K group tha vo aisa hogya hai! NULL <- 1 <- 2, and isme prev pehle NULL pe tha inn sab operations se humne usko 2 pr point kra diya and curr and next ko 2 pr point kra diya and then count++ krdiya to tell ki ek iteration khatam hogyi! and then firse humne ye same opeartions kiye jab next ko humne first curr->next pr point kraya! and all vo sab steps repeat kiye jo just abhi kiye the!
// And jab ye loop se exit hoke aaye toh pehla K group reverse hogya tha! and then baaki ke liye we used recursion! and the rest of the LL is handled by recursion!

int main() {
    int K;
    cout<<"Enter the value of K : ";
    cin>>K;
    Node17* node1 = new Node17(10);
    Node17* head = node1;
    Node17* tail = node1;
    printNode(head);

    // Inserting odd number of element...
    insertAtAnyPosition(head,tail,2,20);
    insertAtAnyPosition(head,tail,3,30);
    insertAtAnyPosition(head,tail,4,40);
    insertAtAnyPosition(head,tail,5,50);
    insertAtAnyPosition(head,tail,6,60);
    cout<<"Current LL : ";
    printNode(head);

    cout<<"Reversed LL in groups of K : ";
    Node17* reversedK = ReverseK(head, K);
    printNode(reversedK);
} // TC : Hum harr node ko sirf ek baar visit kr rhe hai and total numbers of node agar n hai toh TC = O(n)!
// SC : Humari harr recursive calls pr K nodes ko reverse kr rhe hai and usme hum constant space le rhe hai! and aise hum n/k times space lenge baaki recursive calls me toh humari Sc = n/k * k = n, so SC = O(n)!

// Question 2 : Check whether a LinkedList is Circular or Not.
// Approach will be, like suppose if your LL is empty then return true and if your LL has only 1 node then check if the head->next is NULL or is it point towards itself, if NULL then return false and if it is equal to head->next then return true, then another case of nodes > 1... in that case, make a pointer of Node type and point it at head->next! agar head pr point krayenge then vo head ko do baar count krlega so isliye point it at heads next...
// Then, ek loop chalo iss hi temp ka use krke jo abhi head->next ko point kr rha hai, and tak tak chalao jab tak temp yaa toh head ke equal na hojaye ya toh NULL na hojaye, then agar loop ke end me temp head ko point kr rha ho toh mtlb ki it is a circular LL and if NULL ko point kr rha ho toh mtlb ki it is a non-circular LL kyunki circular me kahin bhi NULL toh hoga nhi!
// Now lets code...
#include<iostream>
using namespace std;

// Creating a Circular LinkedList
class Node18{
    public :
    int data;
    Node18* prev;
    Node18* next;

    Node18 (int data) {
        this->data = data;
        this->next = NULL;
    }

    ~Node18() {
        int value = this->data;
        if(next != NULL) {
            delete next;
            next = NULL;
        }
        cout<<"Memory free for the node with data value : "<<value<<endl;
    }
};

void insertNodeCircularLL(Node18* &tail, int element, int data) {
    // Suppose the list is empty...
    if(tail == NULL) {
        Node18* newNode = new Node18(data);
        tail = newNode;
        newNode->next = newNode;
    }
    else {
        Node18* current = tail;
        while(current->data != element) {
            current = current->next;
        }
        Node18* temp = new Node18(data);
        temp->next = current->next;
        current->next = temp;
    }
}

void printNodeCircularLL(Node18* tail) {
    Node18* temp = tail;
    do {
        cout<<tail->data<<" ";
        tail = tail->next;
    } while(tail != temp);
    cout<<endl;
}

// Checking for Circular or not!
bool isCircularList(Node18* head) {
    // Empty list..
    if(head == NULL) {
        return NULL;
    }

    // We can write single node and more than 1 node case under one condition, as they are overlapping...
    Node18* temp = head->next;
    while(temp != NULL && temp != head) {
        temp = temp->next;
    }
    if(temp == head) {
        return true;
    }
    else {
        return false;
    }
}

int main() {
    // Creating Circular LL...
    Node18* tailC = NULL;
    insertNodeCircularLL(tailC, -1, 10);
    insertNodeCircularLL(tailC, 10, 20);
    insertNodeCircularLL(tailC, 20, 30);
    insertNodeCircularLL(tailC, 30, 40);
    insertNodeCircularLL(tailC, 40, 50);
    insertNodeCircularLL(tailC, 50, 60);
    cout<<"Circular LL : ";
    printNodeCircularLL(tailC);

    // Now lets write code for checking that the LL is circular or not...
    if(isCircularList(tailC)) {
        cout<<"It is a Circular LL!";
    }
    else {
        cout<<"It is not a Circular LL";
    }
} // TC : O(n) kyunki hum poori list ko travers kr rhe hai so n is number of nodes! and then SC : O(1) kyunki humne koi space nhi li isme!

// There is another approach also to solve this question... that is useing Maps! as maps me values key value pair ke form me store hoti hai toh,
// jaise jaise jo node traverse hote jaa rhi hai usko true mark krte jayenge and jab poori linkedlist traverse krne ke baad agar vapis true value pr ajaye iterate krne pr means that is a cicular LL otherwise Not!
// try this on your own while doing revision!


// ---------------------------------------------------------- LECTURE 47 - Detect & Remove Loop Question in LL --------------------------------------------------------------------------------------------------------->
// Question : Detect and Remove loop in the LL! but this question is divided into 3 parts, 1) Detect the loop, 2) Output the starting node of the loop!, 3) Remove loop
// 1) Detect the loop/cycle in LL : We just need to check whether the LL has loop or not!
// Yahaa pr hum kis tarah ke loops ki baat kr rhe hai ye janna zaruri hai! so like maanlo kuch nodes hai node1 -> node2 -> node3 -> node4 and now this node4 is again pointing towards node2 or node3 then iss case me ek loop ban jayega! and due to which jab bhi hum node4 visit krenge then hum node2 pr chalenge jayenge agar node4 lets say node2 pr point kr rha hoga and then hum ek loop me fass jayenge!
// Abb iska hi ek extreme case hota hai circular linkedlist jisme node4 seedha node1 ko hi point kr rha hoga toh usme bhi ek loop hota hai! toh dono hi cases me humne loop find krna hai ki kya loop exist krta hai ya nhi!
#include<iostream>
#include<map>
using namespace std;

// Creating a Circular LinkedList
class Node19{
    public :
    int data;
    Node19* prev;
    Node19* next;

    Node19 (int data) {
        this->data = data;
        this->next = NULL;
    }

    ~Node19() {
        int value = this->data;
        if(next != NULL) {
            delete next;
            next = NULL;
        }
        cout<<"Memory free for the node with data value : "<<value<<endl;
    }
};

void insertNodeCircularLL(Node19* &tail, int element, int data) {
    // Suppose the list is empty...
    if(tail == NULL) {
        Node19* newNode = new Node19(data);
        tail = newNode;
        newNode->next = newNode;
    }
    else {
        Node19* current = tail;
        while(current->data != element) {
            current = current->next;
        }
        Node19* temp = new Node19(data);
        temp->next = current->next;
        current->next = temp;
    }
}

void printNodeCircularLL(Node19* tail) {
    Node19* temp = tail;
    do {
        cout<<tail->data<<" ";
        tail = tail->next;
    } while(tail != temp);
    cout<<endl;
}

// Checking for Circular or not!
bool isCircularList(Node19* head) {
    // Empty list..
    if(head == NULL) {
        return NULL;
    }

    Node19* temp = head->next;
    while(temp != NULL && temp != head) {
        temp = temp->next;
    }
    if(temp == head) {
        return true;
    }
    else {
        return false;
    }
}

// Function to detect a loop in the list!
// Approach : So for this question we will create a map and isme content key values ke pair ke form me store rehta hai, so what we will do is we will use this maps! and isme vaise hi data store krenge! jo jo nodes visit hote jayenge unko true mark krte rehna and jab poori list traverse krne ke baad jab bhi agar vapis true vaala node pr pointer aayega tab true return krdenge ki haa iss list me loop hai!
bool detectLoop(Node19* head) {
    if(head == NULL) {
        return false;
    }
    map<Node19*, bool> visited;
    Node19* temp = head;

    while(temp != NULL) {
        if(visited[temp] == true) {
            return true;
        }
        visited[temp] = true;
        temp = temp->next;
    }
    return false;
} // jo dono tarah ke loops the vo dono tarah ke loops ye function detect kr sakta hai!

int main() {
    // Creating Circular LL...
    Node19* tail = NULL;
    insertNodeCircularLL(tail, -1, 10);
    insertNodeCircularLL(tail, 10, 20);
    insertNodeCircularLL(tail, 20, 30);
    insertNodeCircularLL(tail, 30, 40);
    insertNodeCircularLL(tail, 40, 50);
    insertNodeCircularLL(tail, 50, 60);
    cout<<"Circular LL : ";
    printNodeCircularLL(tail);

    if(detectLoop(tail)) {
        cout<<"Loop Exist!";
    }
    else {
        cout<<"Loop does not exist!";
    }
} // You can try to execute the detectLoop function in case of singly linkedlist, there it will print Loop does not exist! kyunki usme loop hi nhi hoga!
// TC : O(n) and SC : O(n), but there is an algorithm, which is called Floyd Cycle Detection algorithm, and this algorithm can reduce the Space complexity to O(1). upar vaale algo se bhi harr tarah ke loops/cycle detect hojayenge but floyd cycle detection ek more optimized way hai cycles in a LL detect krne ka!

// Approach 2 to solve this question! : So here we will be using the floyd cycle detection algorithm! and in this we will use jo humne fast and slow vaale pointer padhe the pehle vo sab! but pehle humne slow ko head pr rakha tha and fast ko head->next pr, but iss algo me dono head pr honge! and then vhi same cheez hoga ki fast 2 nodes ek baar me traverse krega but slow ek ek krke aage badhega!
// Now agar traverse krte krte fast and slow equal hogye kabhi bhi then means cycle exist! and agar kabhi nhi mile ya fast ya slow me se koi bhi NULL hogya toh means cycle does not exist!
#include<iostream>
#include<map>
using namespace std;

// Now here what we will do is we will create a singly linkedlist and a singly linkedlist with a inner loop (jo pehla vaala case tha jisme node4 node2 ko point kr rha tha) and then a circular linkedlist! and then we will use both the methods to check are we able to identify loop/cycle in the three LLs using the two methods...
// First using the detectLoop() function on all three LLs...
// Constructing a Singly Linkedlist (Will use this class to make 2 LLs one without any loop and other with a inner loop)
class Node20 {
    public :
    int data;
    Node20* next;

    Node20(int data) {
        this->data = data;
        this->next = NULL;
    }

    ~Node20() {
        int value = this->data;
        if(this->next != NULL) {
            delete next;
            this->next = NULL;
        }
        cout<<"Memory is free for the node with data "<<value<<endl;
    }
};

void insertatHead(Node20* &head, int data) {
    Node20* temp = new Node20(data);
    temp->next = head;
    head = temp;
}

void insertAtTail(Node20* &tail, int data) {
    Node20* temp = new Node20(data);
    tail->next = temp;
    tail = tail->next;
}

void insertAtAnyPosition(Node20* &head, Node20* &tail, int position, int data) {
    if(position == 1) {
        insertatHead(head,data);
        return;
    }

    Node20* temp = head;
    int cnt = 1;

    while(cnt < position-1) {
        temp = temp->next;
        cnt++;
    }

    if(temp->next == NULL) {
        insertAtTail(tail,data);
        return;
    }

    Node20* NodetoInsert = new Node20(data);
    NodetoInsert->next = temp->next;
    temp->next = NodetoInsert;
}

void printNode(Node20* &head) {
    Node20* temp = head;
    while(temp != NULL) {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

// Constructing a Circular LinkedList...
class Node21{
    public :
    int data;
    Node21* prev;
    Node21* next;

    Node21 (int data) {
        this->data = data;
        this->next = NULL;
    }

    ~Node21() {
        int value = this->data;
        if(next != NULL) {
            delete next;
            next = NULL;
        }
        cout<<"Memory free for the node with data value : "<<value<<endl;
    }
};

void insertNodeCircularLL(Node21* &tail, int element, int data) {
    // Suppose the list is empty...
    if(tail == NULL) {
        Node21* newNode = new Node21(data);
        tail = newNode;
        newNode->next = newNode;
    }
    else {
        Node21* current = tail;
        while(current->data != element) {
            current = current->next;
        }
        Node21* temp = new Node21(data);
        temp->next = current->next;
        current->next = temp;
    }
}

void printNodeCircularLL(Node21* tail) {
    Node21* temp = tail;
    do {
        cout<<tail->data<<" ";
        tail = tail->next;
    } while(tail != temp);
    cout<<endl;
}

// Creating two different functions for Singly LLs and Circular LL, becoz currently I want to keep it simple and just want to understand the things clearly! isliye dono type ke LLs ke liye alag alag detectLoop function create kiye hai!
// For Singly LLs...
bool detectLoop1(Node20* head) {
    if(head == NULL) {
        return false;
    }
    map<Node20*, bool> visited;
    Node20* temp = head;

    while(temp != NULL) {
        if(visited[temp] == true) {
            return true;
        }
        visited[temp] = true;
        temp = temp->next;
    }
    return false;
}

// For Circular LLs...
bool detectLoop2(Node21* head) {
    if(head == NULL) {
        return false;
    }
    map<Node21*, bool> visited;
    Node21* temp = head;

    while(temp != NULL) {
        if(visited[temp] == true) {
            return true;
        }
        visited[temp] = true;
        temp = temp->next;
    }
    return false;
}

int main() {
    // Creating Singly LL 1 without any loop...
    Node20* nodeLL1 = new Node20(10);
    Node20* headLL1 = nodeLL1;
    Node20* tailLL1 = nodeLL1;
    cout<<"First node of LL1 : ";
    printNode(headLL1);

    // inserting more nodes...
    insertAtAnyPosition(headLL1, tailLL1, 2, 20);
    insertAtAnyPosition(headLL1, tailLL1, 3, 30);
    insertAtAnyPosition(headLL1, tailLL1, 4, 40);
    insertAtAnyPosition(headLL1, tailLL1, 5, 50);
    insertAtAnyPosition(headLL1, tailLL1, 6, 60);
    cout<<"Singly Linked List 1 : ";
    printNode(headLL1);

    // Detecting Loop using detectLoop1 function of Singly LLs...
    if(detectLoop1(headLL1)) {
        cout<<"Loop Exist!";
    }
    else {
        cout<<"Loop does not exist!";
    } // And as expected it is printing Loop does not exist!

    cout<<endl;
    cout<<endl;

    // Now Lets create another singly LL but this time with an inner loop!
    Node20* nodeLL2 = new Node20(100);
    Node20* headLL2 = nodeLL2;
    Node20* tailLL2 = nodeLL2;
    cout<<"First node of LL2 : ";
    printNode(headLL2);


    // inserting more nodes...
    insertAtAnyPosition(headLL2, tailLL2, 2, 200);
    insertAtAnyPosition(headLL2, tailLL2, 3, 300);
    insertAtAnyPosition(headLL2, tailLL2, 4, 400);
    insertAtAnyPosition(headLL2, tailLL2, 5, 500);
    insertAtAnyPosition(headLL2, tailLL2, 6, 600);
    cout<<"Singly Linked List 2 : ";
    printNode(headLL2);

    // Detecting Loop using detectLoop1 function of Singly LLs...
    // But for that lets create an inner loop, by pointing the tail of this LL2 at position 3...
    tailLL2->next = headLL2->next->next; // Ab agar tum isko normally bhi seedha head se point kraa doge toh ye bhi ek circular LL ban jayega, toh your did'ne need to implement circular LL alag se, but ofc alag se krne ke apne fayede hai ki tumko harr baar ye line nhi likhni padegi kyunki vo uski class me hi implemented hai and nayaa element add krne ke time dikkat aa sakti hai also jo different operations hum perform krte hai circular LL pr vo hum aise krke na kr paye!
    // even tho koi as such dikkat nhi hogi pr we need to be then more careful while performing delet insert and other operations, but yahaa hum bss ye check kr rhe hai ki LLs me loop exist krta hai ki nhi toh ye hum aise bhi check kr sakte hai!

    // Now lets check that, does the loop exist...
    if(detectLoop1(headLL2)) {
        cout<<"Loop Exist!";
    }
    else {
        cout<<"Loop does not exist!";
    } // And as expected it is showing that the loop exists!

    cout<<endl;
    cout<<endl;

    // Now lets create a circular linkedlist using its implementation in class node21...
    Node21* tailC = NULL;
    insertNodeCircularLL(tailC,-1,1000);
    insertNodeCircularLL(tailC,1000,2000);
    insertNodeCircularLL(tailC,2000,3000);
    insertNodeCircularLL(tailC,3000,4000);
    insertNodeCircularLL(tailC,4000,5000);
    insertNodeCircularLL(tailC,5000,6000);
    cout<<"Circular Linked List : ";
    printNodeCircularLL(tailC);

    // Now lets check whether detectLoop2 function of circular LL can detect the loop in it...
    if(detectLoop2(tailC)) {
        cout<<"Loop Exist!";
    }
    else {
        cout<<"Loop does not exist!";
    } // As expected it is printing Loop exist!
}

// Now using Floyd Detection Algorithm on all the three LLs to detect the loop...
#include<iostream>
#include<map>
using namespace std;

// Constructing a Singly Linkedlist (Will use this class to make 2 LLs one without any loop and other with a inner loop)
class Node22 {
    public :
    int data;
    Node22* next;

    Node22(int data) {
        this->data = data;
        this->next = NULL;
    }

    ~Node22() {
        int value = this->data;
        if(this->next != NULL) {
            delete next;
            this->next = NULL;
        }
        cout<<"Memory is free for the node with data "<<value<<endl;
    }
};

void insertatHead(Node22* &head, int data) {
    Node22* temp = new Node22(data);
    temp->next = head;
    head = temp;
}

void insertAtTail(Node22* &tail, int data) {
    Node22* temp = new Node22(data);
    tail->next = temp;
    tail = tail->next;
}

void insertAtAnyPosition(Node22* &head, Node22* &tail, int position, int data) {
    if(position == 1) {
        insertatHead(head,data);
        return;
    }

    Node22* temp = head;
    int cnt = 1;

    while(cnt < position-1) {
        temp = temp->next;
        cnt++;
    }

    if(temp->next == NULL) {
        insertAtTail(tail,data);
        return;
    }

    Node22* NodetoInsert = new Node22(data);
    NodetoInsert->next = temp->next;
    temp->next = NodetoInsert;
}

void printNode(Node22* &head) {
    Node22* temp = head;
    while(temp != NULL) {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

// Constructing a Circular LinkedList...
class Node23{
    public :
    int data;
    Node23* prev;
    Node23* next;

    Node23 (int data) {
        this->data = data;
        this->next = NULL;
    }

    ~Node23() {
        int value = this->data;
        if(next != NULL) {
            delete next;
            next = NULL;
        }
        cout<<"Memory free for the node with data value : "<<value<<endl;
    }
};

void insertNodeCircularLL(Node23* &tail, int element, int data) {
    // Suppose the list is empty...
    if(tail == NULL) {
        Node23* newNode = new Node23(data);
        tail = newNode;
        newNode->next = newNode;
    }
    else {
        Node23* current = tail;
        while(current->data != element) {
            current = current->next;
        }
        Node23* temp = new Node23(data);
        temp->next = current->next;
        current->next = temp;
    }
}

void printNodeCircularLL(Node23* tail) {
    Node23* temp = tail;
    do {
        cout<<tail->data<<" ";
        tail = tail->next;
    } while(tail != temp);
    cout<<endl;
}

// Creating two different functions for Singly LLs and Circular LL, becoz currently I want to keep it simple and just want to understand the things clearly! isliye dono type ke LLs ke liye alag alag detectLoop function create kiye hai!
// For Singly LLs...
Node22* floydDetectLoop1(Node22* head) {
    // Empty List...
    if(head == NULL) {
        return NULL;
    }
    Node22* fast = head;
    Node22* slow = head;

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

// For Circular LLs...
Node23* floydDetectLoop2(Node23* head) {
    // Empty List...
    if(head == NULL) {
        return NULL;
    }
    Node23* fast = head;
    Node23* slow = head;

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

int main() {
    // Creating Singly LL 1 without any loop...
    Node22* nodeLL1 = new Node22(10);
    Node22* headLL1 = nodeLL1;
    Node22* tailLL1 = nodeLL1;
    cout<<"First node of LL1 : ";
    printNode(headLL1);

    // inserting more nodes...
    insertAtAnyPosition(headLL1, tailLL1, 2, 20);
    insertAtAnyPosition(headLL1, tailLL1, 3, 30);
    insertAtAnyPosition(headLL1, tailLL1, 4, 40);
    insertAtAnyPosition(headLL1, tailLL1, 5, 50);
    insertAtAnyPosition(headLL1, tailLL1, 6, 60);
    cout<<"Singly Linked List 1 : ";
    printNode(headLL1);

    // Detecting Loop using floydDetectLoop1() function of Singly LLs...
    if(floydDetectLoop1(headLL1) != NULL) {
        cout<<"Loop Exist!";
    }
    else {
        cout<<"Loop does not exist!";
    } // And as expected it is printing Loop does not exist!

    cout<<endl;
    cout<<endl;

    // Now Lets create another singly LL but this time with an inner loop!
    Node22* nodeLL2 = new Node22(100);
    Node22* headLL2 = nodeLL2;
    Node22* tailLL2 = nodeLL2;
    cout<<"First node of LL2 : ";
    printNode(headLL2);


    // inserting more nodes...
    insertAtAnyPosition(headLL2, tailLL2, 2, 200);
    insertAtAnyPosition(headLL2, tailLL2, 3, 300);
    insertAtAnyPosition(headLL2, tailLL2, 4, 400);
    insertAtAnyPosition(headLL2, tailLL2, 5, 500);
    insertAtAnyPosition(headLL2, tailLL2, 6, 600);
    cout<<"Singly Linked List 2 : ";
    printNode(headLL2);

    // Detecting Loop using floydDetectLoop1() function of Singly LLs...
    tailLL2->next = headLL2->next->next;

    // Now lets check that, does the loop exist...
    if(floydDetectLoop1(headLL2) != NULL) {
        cout<<"Loop Exist!";
    }
    else {
        cout<<"Loop does not exist!";
    } // And as expected it is showing that the loop exists!

    cout<<endl;
    cout<<endl;

    // Now lets create a circular linkedlist using its implementation in class node21...
    Node23* tailC = NULL;
    insertNodeCircularLL(tailC,-1,1000);
    insertNodeCircularLL(tailC,1000,2000);
    insertNodeCircularLL(tailC,2000,3000);
    insertNodeCircularLL(tailC,3000,4000);
    insertNodeCircularLL(tailC,4000,5000);
    insertNodeCircularLL(tailC,5000,6000);
    cout<<"Circular Linked List : ";
    printNodeCircularLL(tailC);

    // Now lets check whether floydDetectLoop2() function of circular LL can detect the loop in it...
    if(floydDetectLoop2(tailC) != NULL) {
        cout<<"Loop Exist!";
    }
    else {
        cout<<"Loop does not exist!";
    }
}
// Now lets see why it works...
// Kyunki harr iteration me dono nodes ke beech ka distance ek ek unit kam hote jaata hai! and in the end kahin toh milna hi hai! so that is why this algorithm actually works!

// Identify the starting point of the Loop!
// Approach : What we will do is, ki hum pehle step me toh Floyd Cycle Detection algo ke through vo point of intersection toh nikal hi lenge jahaa Fast and Slow meet kr rhe hai! and then jab hum vo nikal le then in the next step what we will do is, slow ko vapis se head pr point kraa denge and fast toh abhi bhi uss point of intersection pr hi point kr rha hai! but ab iss step me hum slow and fast ko same rate se move krenge and jahaa pr iss baar ye meet kr jaye that will be the starting node of the loop!
// But lets see why this logic works? isme ek A + B = K*C ka expression banta hai LL me, and vo kaise that you can visit again Love Babbar vdo! its very simple and easy! so iss logic se hi this algo works! refer the vdo for details and accurate explaination!
// Lets code this logic now....
#include<iostream>
using namespace std;

// Basic code to create the singly linkedist!
class Node24 {
    public :
    int data;
    Node24* next;

    Node24(int data) {
        this->data = data;
        this->next = NULL;
    }

    ~Node24() {
        int value = this->data;
        if(this->next != NULL) {
            delete next;
            this->next = NULL;
        }
        cout<<"Memory is free for the node with data "<<value<<endl;
    }
};

void insertatHead(Node24* &head, int data) {
    Node24* temp = new Node24(data);
    temp->next = head;
    head = temp;
}

void insertAtTail(Node24* &tail, int data) {
    Node24* temp = new Node24(data);
    tail->next = temp;
    tail = tail->next;
}

void insertAtAnyPosition(Node24* &head, Node24* &tail, int position, int data) {
    if(position == 1) {
        insertatHead(head,data);
        return;
    }

    Node24* temp = head;
    int cnt = 1;

    while(cnt < position-1) {
        temp = temp->next;
        cnt++;
    }

    if(temp->next == NULL) {
        insertAtTail(tail,data);
        return;
    }

    Node24* NodetoInsert = new Node24(data);
    NodetoInsert->next = temp->next;
    temp->next = NodetoInsert;
}

void printNode(Node24* &head) {
    Node24* temp = head;
    while(temp != NULL) {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

// We need it as we have discussed in the approach!
Node24* floydDetectLoop1(Node24* head) {
    // Empty List...
    if(head == NULL) {
        return NULL;
    }
    Node24* fast = head;
    Node24* slow = head;

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

// Code to implement the solution to find the starting node of the Loop!
Node24* getStartingNode(Node24* head) {
    if(head == NULL) {
        return NULL;
    }
    Node24* intersection = floydDetectLoop1(head);
    Node24* slow = head;

    while(slow != intersection) {
        slow = slow->next;
        intersection = intersection -> next;
    }
    return slow; // Here in the end the slow will be pointing at the starting node of the loop!
}

int main() {
    Node24* node = new Node24(100);
    Node24* tail = node;
    Node24* head = node;
    cout<<"First node of LL : ";
    printNode(head);


    // inserting more nodes...
    insertAtAnyPosition(head, tail, 2, 200);
    insertAtAnyPosition(head, tail, 3, 300);
    insertAtAnyPosition(head, tail, 4, 400);
    insertAtAnyPosition(head, tail, 5, 500);
    insertAtAnyPosition(head, tail, 6, 600);
    cout<<"Singly Linked List : ";
    printNode(head);

    // Creating an inner loop!
    tail->next = head->next->next;

    // Now as we have already created a loop! lets find the starting node of the Linkedlist
    Node24* startingNode = getStartingNode(head);
    cout<<"The starting node of the loop is : "<<startingNode->data<<endl;
} // So that is how we have find the starting node of the loop!

// Removing the Loop! isme what we will do is, we will jo starting point hai Loop ka usse pehle jo node hai (inside the loop) usko NULL ko point kraa denge! ek tarah se jaise loop create hua tha vaise hi remove bhi hoga, jaise tail ko kisi ek particular node pr point kraya tha na bss uss hi pointer ko hataa do we will get the loop removed!
// Toh for this we will need floyd detect loop vaala function jo interection point detect krega jiski help se hum starting node nikalenge and then uss starting se pehle vaale node ko (Loop ke andar) NULL pr point kraa denge! and we will get the answer!
#include<iostream>
using namespace std;

// Basic code to create the singly linkedist!
class Node25 {
    public :
    int data;
    Node25* next;

    Node25(int data) {
        this->data = data;
        this->next = NULL;
    }

    ~Node25() {
        int value = this->data;
        if(this->next != NULL) {
            delete next;
            this->next = NULL;
        }
        cout<<"Memory is free for the node with data "<<value<<endl;
    }
};

void insertatHead(Node25* &head, int data) {
    Node25* temp = new Node25(data);
    temp->next = head;
    head = temp;
}

void insertAtTail(Node25* &tail, int data) {
    Node25* temp = new Node25(data);
    tail->next = temp;
    tail = tail->next;
}

void insertAtAnyPosition(Node25* &head, Node25* &tail, int position, int data) {
    if(position == 1) {
        insertatHead(head,data);
        return;
    }

    Node25* temp = head;
    int cnt = 1;

    while(cnt < position-1) {
        temp = temp->next;
        cnt++;
    }

    if(temp->next == NULL) {
        insertAtTail(tail,data);
        return;
    }

    Node25* NodetoInsert = new Node25(data);
    NodetoInsert->next = temp->next;
    temp->next = NodetoInsert;
}

void printNode(Node25* &head) {
    Node25* temp = head;
    while(temp != NULL) {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

// We need it as we have discussed in the approach!
Node25* floydDetectLoop1(Node25* head) {
    // Empty List...
    if(head == NULL) {
        return NULL;
    }
    Node25* fast = head;
    Node25* slow = head;

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

// We also needed this...
Node25* getStartingNode(Node25* head) {
    if(head == NULL) {
        return NULL;
    }
    Node25* intersection = floydDetectLoop1(head);
    if(intersection == NULL) { // Here we puting checks ki agar intersection NULL na hojaye agar hogya toh intersection -> next krne pr error aa sakta hai, kyunki iska mtlb hoga ki hum NULL->next try kr rhe hai find krne ka! which is not logical! so it can give our segementation fault or system may crash! or things like that! overall it will show error!
        return NULL;
    }
    Node25* slow = head;

    while(slow != intersection) {
        slow = slow->next;
        intersection = intersection -> next;
    }
    return slow;
}

Node25* removeLoop(Node25* head) {
    if(head == NULL) {
        return NULL;
    }
    Node25* startofLoop = getStartingNode(head);
    // Ye humne extra NULL checks lagaye vrna segementation fault y faaltu ka kuch errors aa sakte hai, kyunki agar hume ye check nhi lgaye toh getStartingNode se NULL value aane pr intersection me NULL store hoga! and then temp me bhi NULL jayega and then temp->next ke time pr NULL->next calculate krne ki koshish hogi which will return an error! or a segementation fault!
    if(startofLoop == NULL) {
        return NULL;
    }
    Node25* temp = startofLoop;

    while(temp->next != startofLoop) {
        temp = temp -> next;
    }
    temp -> next = NULL;
}

int main() {
    Node25* node = new Node25(100);
    Node25* tail = node;
    Node25* head = node;
    cout<<"First node of LL : ";
    printNode(head);


    // inserting more nodes...
    insertAtAnyPosition(head, tail, 2, 200);
    insertAtAnyPosition(head, tail, 3, 300);
    insertAtAnyPosition(head, tail, 4, 400);
    insertAtAnyPosition(head, tail, 5, 500);
    insertAtAnyPosition(head, tail, 6, 600);
    cout<<"Singly Linked List : ";
    printNode(head);

    // Creating an inner loop!
    tail->next = head->next->next;

    // Found the starting point of the Loop!
    Node25* startingNode = getStartingNode(head);
    cout<<"The starting node of the loop is : "<<startingNode->data<<endl;

    // Removing the loop!
    removeLoop(head);

    // To check whether loop is removed or not,
    cout<<tail->next<<endl;
} // So that is how you remove loops from LL

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