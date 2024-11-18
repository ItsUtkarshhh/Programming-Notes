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
// Also visit CodeStudio and read and understand and solve the articles nd questions! and you can visit it thru the link of below the lecture on yt!
// Practice to find TC and SC it is important!

// ---------------------------------------------------------- LECTURE 42 - OOPS Part 1 --------------------------------------------------------------------------------------------------------->
// What is it? It is that type of programming technique where things revolve around objects
// What are objects, objects has some properties, or state and has a behaviour! through OOPS we try to include real world objects into our program! taaki humare code ka real world application badh jaye!
// Now suppose in a game we have an entity as Hero, now that hero is an objects, kyunki a Hero has properties like it has a Name, Health, Level and etc... also it shows certain behaviours like Attack(), Defence() and similar etc... so this is the implication of OOPS!

// Classes and Objects
// Class : It is a user-defined data type!
// Objects : Instance of a class!
// So aise samajhlo ki jab hum koi int a; ko use krke ek variable and uska ek data type bnaate hai, similarly in OOPS we write Hero Ramesh, jisme Hero ek class hai jisse hum Ramesh naam ke object ka data type define kr rhe hai, mtlb ki Ramesh jo hai vo ek Hero type ka entity hai!
// So you can say that Class is the Data Type and Object is like the Variable!
// Lets code...
#include<iostream>
using namespace std;

class Hero {
    // iss class ki help se jo bhi objects hum banayenge ye unki properties hongi! for now its only health!
    int health;
};

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
    // cout<<"Utkarsh's health is : "<<Utkarsh.Health<<endl;
    // cout<<"Utkarsh's age is : "<<Utkarsh.Age<<endl;
    // They will give errors becoz right now they are private data members! we need to make them public to access them.. but lets first study the Access Modifiers in OOPS
}

// Access Modifiers!
// They are used to define the scope of Data Members, ki kisi data member ko hum kahaa pr access kr payenge, kya sirf class ke andar hi access kr payenge ya class ke bahar bhi yaa kisi aur class ke andar bhi and all...
// Their are three types of Access Modifiers : Public, Private and Protected!
#include<iostream>
using namespace std;

class Hero {
    private : // by default vaise bhi private hi rehte hai!
    int Health;
    public :
    int Age;
};

int main() {
    Hero Utkarsh;
    // cout<<"Utkarsh's health is : "<<Utkarsh.Health<<endl;
    cout<<"Utkarsh's age is : "<<Utkarsh.Age<<endl; // Age se pehle public likhne se age class ke bahar bhi accessible hogya but health abhi bhi private hi hai kyunki public neeche likha hua hai uske! by default saare private hote hai!
}
// Even agar hum koi function bhi bnaa dete hai class ke andar toh usko bhi hum private ya public ya protected bnaa sakte hai, jo private hoga vo sirf class ke andar hi access kiya jaa sakta hoga, public class ke bahar bhi access kiya jaa sakta hoga!

// Now suppose hum chahte hai ki kuch data members ko private rakhte hai but still hum unko access krna chahte hai int main me, toh for that we use Getter and Setter functions!
// These functions are created withing the public scope and can be accessed using "." operator!
#include<iostream>
using namespace std;

class Hero {
    private :
    int Health; // Now as health is private toh ab health ko directly access nhi kr sakte! so we need to create getter and setter functions for it in the public scope of the class, so lets do it!
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
    // Iss case me hume getter & setter functions sirf Health ke liye chahiye! kyunki sirf vhi ek private data member hai and baaki toh public hai toh unko hum aise hi access kr sakte hai!
};

int main() {
    Hero Utkarsh;
    Utkarsh.sethealth(100); // Even tho health is a private member we are able to set the value of Health using the setter function!
    cout<<"Utkarsh's health is : "<<Utkarsh.getHealth()<<endl; // Printed the value of Health using the getter function we have created inside the class
    
    Utkarsh.Age = 21;
    cout<<"Utkarsh's age is : "<<Utkarsh.Age<<endl;

    // Lets calculate size of the data members...
    cout<<"Size of Utkarsh : "<<sizeof(Utkarsh)<<endl; // this is showing the size : 16 jabki dekha jaye toh 13 aani chahiye, kyunki Health + Level + Age = 12, and then Name is of one byte so it should be 13, but answer is 16 aisa kyu? so aisa isliye beoz of Padding and Greedy alignment!
    // Padding : Padding involves inserting empty bytes between the members of a structure or class to ensure that each member is properly aligned in memory. The goal of padding is to ensure that each data member starts at an address that's a multiple of its size, which can improve memory access performance, especially on architectures that require aligned memory accesses.
    // Alignment : Alignment refers to the requirement that data types should start at particular memory addresses. For example, many architectures require that int variables start at memory addresses that are multiples of 4 (for 32-bit integers) or 8 (for 64-bit integers). Similarly, char variables can usually start at any address. Alignment can be influenced by the size of the data type. For example, if an int requires 4-byte alignment, and a char requires 1-byte alignment, the compiler may insert padding bytes between the members of a structure to ensure proper alignment.
    // Greedy Alignment : Greedy alignment is a strategy used by some compilers to minimize padding. In greedy alignment, the compiler tries to align each member of a structure or class to the largest alignment requirement of any member in the structure. This strategy helps reduce padding by minimizing the number of empty bytes inserted between members.
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
    Hero *Utkarsh2 = new Hero; // Jaise normally krte the vaise hi yahaa bhi kr rhe hai! isse heap me ek mere compiler ke according 4 byte ki memory allocate hogyi hogi jisme Utkarsh naam ke ek pointer ka address store hoga! and agar mera compiler 64 bits ka hota toh 8 bytes ki memory heap me allocate hoti! abhi 32 bits ka hai isliye bss 4 bytes ke memory hi allocate hoti hai heap me!
    (*Utkarsh2).Level = 69;
    (*Utkarsh2).sethealth(100);
    cout<<"Level : "<<(*Utkarsh2).Level<<endl;
    cout<<"Health : "<<(*Utkarsh2).getHealth()<<endl;

    // Another way dynamic vaali values print krne ka is...using "->" arrow operator, ye sirf dynamic ke time hi krna hai!
    cout<<"Level : "<<Utkarsh2->Level<<endl;
    cout<<"Health : "<<Utkarsh2->getHealth()<<endl;
}

// Now the thing is jab bhi koi object create hota hai tab ek constructor call hota hai sabse pehle and that is ObjectName.Class() kuch iss type ka constructor call hojaata hai automatically isko we call Default Constructor!
// These constructors work behind the scene zaruri nhi ki hum inko class me banaye but if banana chahte hai toh bnaa bhi sakte hai!
// Now ye jo constructors hote hai inka koi return type nhi hota! and koi input parameter nhi hota!
// Default Constructor! 
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
// Also agar ek baar default constructor bnaa diya toh usko hataoge toh ab error show krega kyunki jo compiler vaala tha vo khatam ho chuka hai once you have created your own constructor, so you have to keep it now!

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
        this -> Health = Health; // So agar kabhi parameterized constructor me jo paramter hum pass kr rhe hai and jiss data member ka use kr rhe hai dono ka name same hai toh in that case we use "this" keyword taaki ye btaa sake ki konsa variable object ka hai and konsa ek paramter hai!
        // so writing this we can see "this" keyword is used on the "Health" on left side of assignment operator which tells that left vaala object ka data member hai and right vaala paramter hai!

        // "this" ka bss yhi kaam hai ki confusion khatam krna ki konsa name kiska hai... hum chahe toh different names bhi use kr sakte hai but just telling ki agar same names use krna chahte hai toh ye "this" operator use kr sakte hai...
        // Overall "this" is a pointer which stores the address of the current object!
        // Current Object : When you create instances of a class, each instance is an object with its own set of data members and member functions. When you call a member function on an object, that object becomes the "current object" within the context of that function call.
    } // yahaa iss this -> Health ki help se hum bss ye kehna chah rhe hai ki jaise maanlo current object hai Utkarsh and usne iss constructor ko call kiya toh curent object Utkarsh ban gya hai toh ab jab iss constructor ke paas jab request ayegi tab ye aise hoga ki This Utkarsh ki Health ke andar jo paramter me di gyi value hai vo daal do!
    
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
}; // Here it was the explaination of this and parameterized constructor! lets code it properly!

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
    cout<<"Address of Utkarsh : "<<&Utkarsh<<endl; // <- this and "cout<<"Address of this : "<<this<<endl;" both are giving the same output!
    Hero1 Utkarsh2; // This object will call the default constructor! Thing is agar tumne koi default object bnaya hua hai and tumne agar pehle se compiler vaale constructor ko hataa ke apna koi constructor nhi banaya toh koi error nhi aayega! but agar tumne ek baar apna default constructor banaa diya! toh vo pehle vaala default constructor toh hatt gya hai! and ab jab bhi tum koi default object banaoge and then tum agar Default constructor hataate ho tab error show krega!
    // Pehle toh chalo theek tha default object banao ya naa banao, compiler ka default ka constructor sambhal le rha tha! but jaise hi tumne koi default constructor bnaa diya and tumhara koi default object bnaa hua hai... and ab agar tum vo default constructor hataoge tab error show krega!
    // means default constructor ko default object ke hone ya naa hone se fark nhi padta but default object ke liye ek default constructor hona zaruri hai!
} // Passing multiple paramters in parameterized constructor is also possible, we can use "this" for both the parameters also jo pass hue hai uss constructor me! 

// Copy Constructor!
// This constructor is used to copy objects!.. ek compiler ka khud ka copy constructor hota hai! agar hum apna explicitly create nhi krte hai toh vo default me jo ek compiler ka copy constructor rakhaa hua hai bg me vhi call hojaata hai jab bhi hum objects copy krne ka try krte hai!
// A copy constructor is a member function that initializes an object using another object of the same class. In simple terms, a constructor which creates an object by initializing it with an object of the same class, which has been created previously is known as a copy constructor.
// Copy constructor is used to initialize the members of a newly created object by copying the members of an already existing object.
// The copy constructor can be defined explicitly by the programmer. If the programmer does not define the copy constructor, the compiler does it for us.
// Toh chalo abhi we are defining our own copy constructor and using it to copy one object to another!
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
    // isliye jab humne name ki value me koi bhi change kiya toh vo change dono objects me reflect hua!
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

// Use of Copy Assignment operator! : Agar do object create ho chuki hai and dono me se kisi ek ko dusre me copy krna hai tab we use this operator, copy constructor me kya tha ki ek object create ho chuki hai dusra object bss create hua hai but initiallize nhi and hume pehle vaali ko dusre me copy krna hai then we use that, but here dono initialize ho rakhe hai and humne bss ek ko dusre me copy krna hai!
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

// Destructors : To de-allocate memory! it frees the memory jab object ka life span khatam hone vaala hota hai!
// Class create hote hi ye bhi create hojaata hai...
// Like suppose jaise upar vaale examples ke case me jo jo objects create hue hai vo sab jaise hi int main ka scope khatam hone vaala hoga usse pehle destructors call hojaate hai and vo memory ko free kr dete hai!
// Same as class name, no return type and no input parameter!
// Ye already class create krte hi ban jaate hai but agar chahte hai toh khud ke destructor bhi bnaa sakte hai!
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
    Hero4 *Utkarsh1 = new Hero4;
    // Here we will notice one thing that static objects ke liye constructor automatically call hojaata hai but dynamic ke liye hume alag se manually krna padta hai for that we need to do it manually!
    delete Utkarsh1; // This is to call the destructor for the dynamically created object
    // Kyunki agar ye nhi likhte toh static vaale ke liye ek baar constructor call hua and ek baar destructor, but dynamically ke case me sirf ek baar constructor call hua, destructor ko call krne ke liye we need to write delete object_name; taaki destructor bhi call hojaye!
}

// Static Keyword :
#include<iostream>
using namespace std;

class Hero5 {
    private :
    int age;

    public :
    int health;
    static int timeToComplete; // This keyword is used for those data members jo poore class ke liye same rehne vaale hai, jaise maanlo ek game hai usme time to complete kisi bhi object enemy ya hero ke liye same hi hone vaala hai! toh aise data members ke liye hum static keyword use krte hai! to initiallize them we write this outside the class, [datatype of static data member] [Class Name] :: [Static Data member name] = [Value]

    // Constructor :
    Hero5() {
        cout<<"Constructor Called!"<<endl;
    }

    ~Hero5() {
        cout<<"Destructor Called!"<<endl;
    }
};

int Hero5 :: timeToComplete = 5; // So here we have initialized it!
// Now ab isko access krne ke liye hume kisi object ki zarurat nhi hoti hai!

int main() {
    cout<<Hero5::timeToComplete<<endl; // It will print 5

    Hero5 h1;
    cout<<h1.timeToComplete<<endl; // Krne ko aise bhi kr skte hai but this is not recommended! kyunki ye kisi object ko belong hi krta ye class ko belong krta hai!

    Hero5 h2;
    h2.timeToComplete = 10; // Humne time to complete change krdiya ab, aur ab ye change jab hua hai toh ye poori class ke liye change hua hai!
    cout<<h1.timeToComplete<<endl; // Krne ko aise bhi kr skte hai but this is not recommended! kyunki ye kisi object ko belong hi krta ye class ko belong krta hai!
    cout<<h2.timeToComplete<<endl; // Krne ko aise bhi kr skte hai but this is not recommended! kyunki ye kisi object ko belong hi krta ye class ko belong krta hai!
}

// Static Functions : Same as static data members, this is also for the class not for the objects... objects bhi access kr sakte hai but hoti hai ye mainly class ke liye hai!
// Isme koi this keyword nhi hota kyunki this keyword ka kaam hi hai current object ko point krna pr yahaa toh object hi nhi hai isliye ye kisi kaam ka nhi static functions me!
// And static functions sirf static data members ko hi access kr sakte hai!
#include<iostream>
using namespace std;

class Hero5 {
    private :
    int age;

    public :
    int health;
    static int timeToComplete; // This keyword is used for those data members jo poore class ke liye same rehne vaale hai, jaise maanlo ek game hai usme time to complete kisi bhi object enemy ya hero ke liye same hi hone vaala hai! toh aise datam members ke liye hum static keyword use krte hai! to initiallize them we write this outisde the class, [datatype of static data member] [Class Name] :: [Static Data member name] = [Value]

    static int func() {
        // cout<<this->age<<endl; // this will throw error, kyunki naa toh yahaa this ka koi kaam aur naa hi age ka kyunki vo koi static data member nhi hai!
        // cout<<health<<endl; // Same here also...
        return timeToComplete; // This will work kyunki ye ek static data member hai!
    }

    // Constructor :
    Hero5() {
        cout<<"Constructor Called!"<<endl;
    }

    ~Hero5() {
        cout<<"Destructor Called!"<<endl;
    }
};

int Hero5 :: timeToComplete = 5;

int main() {
    cout<<Hero5::timeToComplete<<endl;
    cout<<Hero5::func()<<endl;
    // Both will print 5
}

// ---------------------------------------------------------- LECTURE 43 - OOPS Part 2 --------------------------------------------------------------------------------------------------------->
// OOPS has 4 pillars : Encapsulation, Inheritence, Polymorphism and Data Abstraction!
// Encapsulation : Encapsulation is combining all the data members and functions in one single entity which we called class!
// Ek Dawai ki capsule me kaafi saari dawai ki goliyan hoti hai toh bss vaisa hi maanlo, ki vo dawai ki goliyan Data Members and Functions hai...and uss dawai ki capsule ko hi hum class bolte hai!

// Fully Encapsulated Class : Where all of its Data Members are set Private! and can be accessed within the class only! Class ke Functions/Methods public ho sakte hai, but Data Members agar saare Private ho toh tab usko fully encapsulated kehte hai!
// In short Encapsulation is called Data Hiding, dont confuse it with Data Abstraction as Data Abstraction is Implementation Hiding!

// Advantages : Data Hiding ke kaaran Security badh jaati hai!
//            : If we want we can make our class Read-only vo aise ki hum koi setter naa banaye toh koi bhi usko change nhi kr payega! isliye the class which will be having only getter will be a Read-only class!
//            : Increases Code Reusability
//            : Encasulation helps in unit testing!
// Lets see an example and how we implement encapsulation, its nothing like big task...jo abhi tak hum krte aa rhe the vo encapsulation tha!
#include<iostream>
#include<cstring> // for strcpy
using namespace std;

class Student{
    private :
    char *Name;
    int age;
    int marks;

    // Student() { // Don create constructor in private kyunki object creation ke time ye call hota hai toh private hone ke kaaran ye call hi nhi ho payega, isliye isko ya kisi bhi function humesha public rakhna chahiye!
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
};

int main() {
    Student Utkarsh;
    char name[] = "Utkarsh";
    Utkarsh.setterfunc1(name,21,95);
    Utkarsh.getterfunc1();
}
// Overall this is all encapsulation only, jo bhi abhi tak lecture 42 me kr rhe the vo sab encapsulation hi hai! and iss example me ye jo class thi ye ek fully encapsulated class thi!

// Inheritance! : Jab kisi ek class ki koi property koi aur class inherit krleti hai toh usko hum inheritance kehte hai!
// Lets understand it with code...
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

class Male : public Human { // here this is the syntax to inherit one class from other, [class child_class_name : access_modifiers parent_class_name] jo class inherit krti hai that is child and jahaa se inherit krti hai that is parent!
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
    // Human H1; // Is object ke liye toh parent class ke saare data members use honge but ye class child class ke data members access nhi kr payega
    Male Utkarsh;
    // Utkarsh.age = 21;
    // Utkarsh.height = 170;
    // Utkarsh.weight = 70;

    // Utkarsh.salary = 5000000;
    // Ye cheeze upar vaali hum setter function se bhi set kr sakte hai...
    Utkarsh.setterFunc1(170,70,21);
    Utkarsh.setterFunc2(5000000);

    Utkarsh.getterFunc1();
    Utkarsh.getterFunc2();
}
// Now what happened is, ki humare pass classes thi do ek Human jo ek parent class thi and Male jo ek child class thi... ab dono classes ke apne apne data members and member function the... jab hum male me Human ko inherit karwaya toh Human ki jitni bhi properties thi vo sab inherit hogyi child class ke liye! and now child class ka koi bhi object parent class ke kisi bhi data members ya member function ko use kr sakta hai!

// In the above case our mode of inheritance was public and jin data members ko acess kr rhe the vo bhi public hi the isliye koi dikkat nhi aayi!
// But there will be some complications agar base class ke data members ka access modifier private ya protected hua toh...
// so for that remember this table...
// Access Modifier of base class     |       Mode of inheritance
//      Public                                      Public          ->       Public
//      Public                                      Private         ->       Private
//      Public                                      Protected       ->       Protected
//      Protected                                   Public          ->       Protected
//      Protected                                   Private         ->       Private
//      Protected                                   Protected       ->       Protected
//      Private                                     Public          ->       Not Possible
//      Private                                     Private         ->       Not Possible
//      Private                                     Protected       ->       Not Possible
// Private data member of any class cannot be inherited!

// What is Protected Access Modifier? So basically it is more or less similar to Private, it can be access within the class, the only difference is ki jab aap inheritence use kroge tab ye protected data member child class bhi access kr sakta hai! but private ke case me aisa nhi hai! This is the only difference!
// Ab baaki toh we know ki hum private public ya protected teeno ko hi member functions bnaa ke access kr sakte hai and then unn member functions ko use kr krke hum objects ke saath use kr sakte hai! jo abhi tak krte bhi aye hai!

// Tyoes of Inheritance!
// Simple | Multiple | Multi-Level | Hierarchial | Hybrid Inheritances!

// Single Inheritance : Jab koi ek class dusre class ke properties ko inherit krle! Like class B ne class A ki properties ko inherit krliya! then it is Single Inheritance!
// Above example of Human and Male is of Single Inheritance!
// Lets see example :
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
} // So here we have used single inheritance!

// Multi-Level Inheritance : Jab E class D class ko inherit kre and D class C class ko and C class B class ko and B class A class ko!
// Lets see example...
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
    // Here we can see the German Shephard class can access all the higher level classes becoz due to inheritance between its higher level class it got functionalities of all the highesr level classes
}

// Multiple Inheritance : When a class inherits more than 1 classes! Like suppose there is class C and it is inheriting 2 classes A and B, this is multiple inheritance!
// Lets see example...
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
} // So here this is example of Multiple Inheritance...
// Now thing is yahaa ye sab code likhne me thore error aa rhe hai kabhi kabhi isliye names of variable and function and class change krna pad rha hai kyunki yahaa pr ab bhot saari classes ban gyi hai and sabka scope poore code me hai! toh isliye vo thora understand krna revision ke time!
// Uss errors ko handle krne ke liye hi yahaa functions classes and data members ke names change krna pad rha hai!

// Hierarchial Inheritance : Here ek base class hota hai uski properties more than one classes inherit kr rhe hote hai! Multiple ke case me ek class ek se zyada ki properties inherit kr rha tha yahaa just opposite!
// Lets see...
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

// Hybrid Inheritance : Combination of more than one type of inheritance!
// lets see...                                                                                                                                                                                                                                                                                                                                                    
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

// Inheritance Ambiguity : Jab do classes ko kisi child ke dwara inherit kiya jaata hai and unn dono base classes me kisi member function ya data member ka name same hai and ab jab child class uss funtion ya data member ko use krne ka try krega toh compiler will get confuse ki konsa function ki baat ho rhi!
// So to solve this ambiguity we use "::" scope resolution operator!
// Lets see...
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
    j1.func(); // Agar sirf ye likhoge toh J class ka func() vaala function call hojayega, this is method over riding which we are about to study in runtime polymorphism
} // Ambiguity Resolved! using scope resolution operator!

// Now the thing is OOPS are used a lot in industries!! but jo abhi hum padh rhe hai ye bhot hi basic level ki OOPS hai, other wise OOPS jo actual use hoti hai usme aur isme zameen aasman ka antar hai!

// Polymorphism! : When one particular thing can have mutltiple forms! like a father can be a father for you but can also be son for his father, a husband for your mom, a brother for his sister and in a similar way!
// There are two type of Polymorphism! : Compile-Time Polymorphism and Runtime Polymorphism!

// Compile time Polymorphism : Isme konsa function kab call hona hai vo decide kiya jaata hai at the compile time! means, it is achieved through function overloading and operator overloading. In compile-time polymorphism, the decision about which function or operator to call is made during the compile-time, based on the types of arguments or operands involved. The compiler resolves the method or function call at compile-time.
// It is also called Static Polymorphism!
// Lets see...
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

// Operator overloading : Jaise we know + jo operator hai vo addition toh krta hi hai string ke case me concat bhi krta hai but hum chah rhe hai ki hum apne liye Hello bhi bulwaye jab bhi + operator call ho, logically it wont make sense, but just telling ki we want it to do this!
// Lets see...
// Chalo hum chahte hai ki + operator se - karwaye! logically it wont make sense but we are just using the operator overloading!
#include<iostream>
using namespace std;

class L {
    public :
    int a, b;

    void operator+ (L &obj) {
        int value1 = this->a;
        int value2 = obj.a;
        cout<<"Output : "<<value2 - value1<<endl;
    }

    void operator() () {
        cout<<"Inside the bracket function! "<<this->a<<endl; // Mtlb ki jab bhi bracket call ho, tab ye cout print krdena and jis obj ne call kiya ye uski a ki value print krdena!
    }
};

int main() {
    L obj1, obj2;
    obj1.a = 5;
    obj2.a = 12;

    obj1 + obj2;
    // + is a binary operator hai toh uske liye ye matter krta hai ki right left me konsa operand hai
    // toh humne yahaa obj1 ko left operand bnaa diya and obj2 ko right... now ab jo + ke case me jo operand right me hota hai vo as a input pass hota hai operator overloading me and jo left me hota hai vo current object hota hai ,mtlb ki uss object ke liye humari function call hui hoti hai!
    // means jab obj1 + obj2 likha humne, toh ye hua ki obj1 ne function call ki toh is kaaran se value1 me this->a jo likha hai vo usme obj1 ki value store ho rhi hai becoz we have used "this" and this points to the current object and current object is obj1 kyunki vo left me likha hua hai!... and value2 me jo obj.a likha hua vo obj2 ki baat ho rhi hai kyunki vo right me likha tha and isliye vo as paramter pass hua tha function call me! isliye value2 me obj2 ki value gyi!
    // Toh ab jab bhi + operator call hoga tab uske right and left operands ko dekh ke function call hoga and uske hisaab se - hojayega! 

    obj1(); // Obj1 ne call kiya bracket ko toh output me Inside the bracket function! print hoga and saath saath obj1 ki a value print hojayegi which is 5!
}

// There are some operators which cannot be overloaded! and they are... "::", "*", ".", "?:"

// Runtime Polymorphism : also known as dynamic polymorphism, is achieved through method overriding using inheritance and virtual functions. In runtime polymorphism, the decision about which function to call is made during the runtime, based on the type of object being referred to.
// Lets see...
// When we have different class suppose A and B and we are inheriting properties of A into B means A is base and B is child and they both have a function with same name func() and func() in A says cout<<"Hello" and func() in B says cout<<"Hi", toh hua kya hai ki ek class ne dusre class ko inherit krne ke baad same name ke function ko dusri tarah se implement krdiya!
// This is called Function Overriding or Method Overriding!
// There are some rules... 1) Method of parent and child class should have same names 2) Also both methods in both the classes should have same number of parameters 3) Method overriding is possible thru inheritance only!
// Means Runtime Polymorphism depends on Inheritance!

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
    void display() { // Here you have done method overiding... agar tum ye function nhi banate toh M vaala hi display function call hojaata kyunki N ne M ko inherit kr rakha hai, pr kyunki humne iss class ke liye N ki khud hi implementation daal di hai display() ki isliye agar N ka object bnaa ke function call krenge toh "Inside N class" print hoga...
        cout<<"Inside N class"<<endl;
    }
};

int main() {
    N obj1;
    obj1.display(); // Here it will print N class's implementation of display()... but if you want to specify ki which display function you want to call then in that case you use scope resolution operator!
    obj1.M::display(); // It will print according to the implementation of display function of M class
}
// Iska use is that ki agar humare paas ek base function hai uske 10 methods hai and then ek sub class hai usko uss base class ke 8 methods as it is use krne hai bss 2 jo uske methods hai unke iss sub class ko khud ke implementation use krne hai then we use this method over riding!

// Data Abstraction : It is called Implementation Hiding! jo essential cheeze hai vo dikhao baaki mtt dikhao jo hume dekhne ki zarurat nhi hai!
// Data Abstraction can be achieved using Private Public Protected access specifiers!
// Advantages : Only you can change to your data and no one else can! it makes application more secure by not allowing anyone else to see the background details! increase the reusability of the table! Avoid duplication of data!
     
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