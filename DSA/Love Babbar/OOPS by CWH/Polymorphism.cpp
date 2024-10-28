// Polymorphism in C++
// Polymorphism means that one thing can have multiple forms!
// Example of Polymorphism are : Function Overloading, Operator Overloading!
//                             : Virtual Function!

// Polymorphism has two types : Compile time Polymorphism
//                            : Runtime Polymorphism

// Compile Time polymorphism : Function Overloading & Operator Overloading
// In Compile time polymorphism, decisions are taken within compile time, for example in case of function overloading, multiple functions hote hai, jo different types/number of input pr different functions kaam krte hai! and iss cheez ko static binding ya early binding bhi kehte hai! iska mmtlb ki compiler ko pehle se hi pta hota hai ki next kya hone vaala hai!
// To kab konsa function run hoga ye cheez compile time me hi decide krli jaati hai isliye isko Compile Time Polymorphism kehte hai!, and same as for Operator Overloading!

// RunTime Polymorphism :
// Runtime polymorphism is achieved though virtual functions! Compile Time polymorphism me kya ho rha tha ki jo compiler hai vo compile time me hi programs and functions ke taar aapas me jod de rha tha (In desi bhasha) but what happens in Runtime Polymorphism is jab function run ho rha hoga tab ye decide hoga ki konsa function execute hoga humare pointer ke type ke according, aur yahaa pe vo taar runtime pr judega! so overall virtual functions ke through Runtime polymorphism achieve kiya jaa sakta hai!
// Aisa nhi hai ki runtime polymorphism me hum dekh ke btaa nhi payenge ki kya hone vaala hai, rather bss ye hoga ki jo binding hoti hai, vo program ke execution ke waqt hogi, means dynamically hogi! and Runtime polymorphism ko late binding bhi kehte hai! and vo bhi pointer ke type according! So ab pehle we need to study the pointer to derived class concept, then we will move further with it to understand Runtime polymorphism, as becoz compile time toh hum jaane anjaane me pehle hi padh chuke hai! So now we will study Pointer to derived class first and then will move to Virtual functions to understand Runtime Polymorphism!

// Performing Runtime Polymorphism through pointer to derived class!
#include<iostream>
using namespace std;

class Base {
    public :
    int var_base;
    void display() {
        cout<<"Displaying Base class variable var_base : "<<var_base<<endl;
    }
};

class Derived : public Base {
    public :
    int var_derived;
    void display() {
        cout<<"Displaying Base class variable var_base : "<<var_base<<endl;
        cout<<"Displaying Derived class variable var_derived : "<<var_derived<<endl;
    }
};

int main() {
    Base Obj_base; // Base class object created!
    Derived Obj_derived; // Derived class object created!

    Base* base_class_pointer; // Base class ka ek pointer banaya jo base class ke objects ko point krega!
    base_class_pointer = &Obj_derived; // But the twist is ki humne base class ke pointer ko derived class ke objects se point kraa diya! and isme koi dikkat nhi hai it wont show any error! But agar even tho base class ke pointer ko humne derived class se point kraa diya, but still jab hum display function call krenge, toh vo base class ka hi call hoga kyunki pointer base class ka hai!
    
    base_class_pointer->var_base = 34; // Yahaa humne base class ke pointer se var_base ki value set krdi! and ab hum iska display function call krke isko print bhi kr sakte hai!
    base_class_pointer->display(); // Yahaa base class ka display function call hua! kyunki ofc base class ka base class pointer apne hi toh data members ya member functions ko call kr sakta hai! kyunki vo thori inherit kiya hai kisi class ko!
    // base_class_pointer->var_derived = 100; // It will throw an error! Yahaa humne dekha ki bhale hi isne derived class ke object ko point kiya ho, pr ye derived class ke variable ki value ko change nhi kr sakta! ye sirf unn hi data members and and member funcion ko access kr sakta hai jo base class se derive hui hai ya base class ki hai! 
    // yahaa pr humne base class ke pointer ko derived class ke object se point karaya fir bhi base class ka display function call hua! toh ab agar humne base class ke hi object ko hi point kiya hota base class ke pointer se fir toh obvious tha ki base class ka hi display function call hoga!
    
    // Now lets do something new, derived class ke pointer ko derived class ke hi object se point krawate hai, toh ab kya hoga...
    Derived* derived_class_pointer;
    derived_class_pointer = &Obj_derived;
    derived_class_pointer->var_derived = 400;
    derived_class_pointer->var_base = 300;
    derived_class_pointer->display(); // Pehli baat toh ki yahaa pr dervied class ka display function call hoga! and then Yahaa pr var_base and var_derived dono ki values print hojayengi! and if you notice, yahaa humne alag se var_base ki value set nhi ki, vo pehle se hi base class ke pointer ne hi upar set ki hui thi, isliye dono var_base and var_derived dono print hogye, otherwise agar upar value nhi initialize ki hui hoti var_base ki, and humne yahaa bhi nhi kiya hua tha, toh garbage value print hoti! toh yaa toh hume pehle base class ke pointer se hi set krdo value var_base ki yaa toh alag se dervived class ke through krdo set! agar yahaa pe var_base ki value set nhi kroge toh jo base class ke pointer ke through jo value set hui hai vahi yahaa pr bhi print hojayegi, aur agar yahaa pr alag se set krdoge value toh yahaa pr var_base ki value alag hogi and bae class me var_base ki value alag hogi!

    // derived_class_pointer = &Obj_base; // It will show error! becoz a derived class pointer cannot point to base class object! becoz derived class has some additional properties and methods that are not present in its base class, and a pointer to the base class cannot access them!
    // derived_class_pointer->var_base = 10; // Yahaa iska mtlb ye ki koi derive class ka pointer base class ko point krke var_base ko change nhi kr sakta! vo sirf apni inherited var_base ko hi change kr sakta hai! na ki original base class ke var_base ko!
    // derived_class_pointer->display(); // Same reason here!

    // That's why ye upar ke 3 line worthless hogye, kyunki derived class ka pointer point hi nhi kar sakta base class ke object ko!
    // But also ye better rehta hai ki jab hum pointer banaye toh usko uss samay hi kisi object pr point kraa de! aise hi naa chhor de! kyunki agar aise hi chhor denge toh vo pointer kisi bhi memory address pr point krne lagega! and which is not good! toh jab bhi koi aisa pointer banao jispe pataa nhi hai tumko ki tumko kiska address store krna hai, toh usko null se initiallize krdo taaki vo null pointer ban jaye, and it means vo kahin pr bhi point nhi kr rha hai!
    // hence as you can see this is late binding or you can say Runtime polymorphism, becoz yahaa pr runtime me decide ho rha hai ki kab konsa display function run hoga! and vo bhi pointer ka type dekh ke, ki agar base class ka pointer hai toh base class ka display function run hoga and agar derived class ka pointer hai toh derived class ka display function execute hoga!
}

// Virtual Functions!
// Abhi upar kya ho rha tha ki base class ka pointer hai aur agar derived class ke object ko point kr rha hai, fir bhi base class ka hi function run ho rha tha, pr ab agar hum chahte hai ki agar derived class ke object ko point kr rha hai base class ka pointer, toh derived class ka hi function run ho, for that we need virtual function!
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

// Virtual Functions Example 2 :
#include<iostream>
#include<cstring>
using namespace std;

class CWH {
    protected:
        string title;
        float rating;
    public:
        CWH (string s, float r) {
            title = s;
            rating = r;
        }
        virtual void display() {}
};

class CWHVideo : public CWH {
    float VideoLength;
    public:
        CWHVideo (string s, float r, float vl) : CWH(s, r) {
            VideoLength = vl;
        }
        void display() {
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
        void display() {
            cout<<"This is an amazing text tutorial with title : "<<title<<endl;
            cout<<"ratings : "<<rating<<" out of 5 stars!"<<endl;
            cout<<"Words count of the text is : "<<words<<" Words!"<<endl;
        }
};

int main() {
    string title;
    float rating, vlen;
    int words;

    title = "C++ Video tutorial!";
    vlen = 4.56;
    rating = 4.45;
    CWHVideo Cvdo(title, rating, vlen); // Yahaa humne object create krdiya, and constructors ke wajah se saath hi saath values bhi daal di!
    // Cvdo.display();

    title = "C++ Video tutorial text!";
    words = 433;
    rating = 4.15;
    CWHText Ctext(title, rating, words); // Yahaa humne object create krdiya, and constructors ke wajah se saath hi saath values bhi daal di!
    // Ctext.display();
    
    // Till here everything was normal, like normally humne 3 classes banai, do me humne CWH ko inherit kiya! and constructors ko use krke humne objects create kiye and then sabme display function de diya apna apna!
    // Abhi tak virtual function ka koi role nhi tha! kyunki abhi tak kahin bhi pointers the hi nhi! toh agar abhi tak me agar hum virtual keyword hataa bhi de tab bhi koi fark nhi padega!
    // But now we will perform Runtime Polymorphism! and vo tab hota hai jab hum base class ke pointers bnaate hai and then usko derived class se point kraate hai! so lets do that...
    CWH* CWH_pointer[2]; // Yahaa humne do pointers saath me bnaa liye! ek pointer CWH_pointer[0] pr hai and ek CWH_pointer[1] and inn dono se hum CWHVideo and CWHText ko point krayenge!
    CWH_pointer[0] = &Cvdo;
    CWH_pointer[1] = &Ctext;

    // Yahaa pr hum runtime polymorphism ke logic se display kr rhe hai! upar hum normally hi values display kr rhe the!
    CWH_pointer[0]->display();
    CWH_pointer[1]->display();
    // Yahaa upar ke 2 line me runtime polymorphism ke thru display karwaa rhe hai values!
    // as we can see that, humne do base class ke pointers banaye, then unse humne dono derived class ke objects ko point kraya! and then humne dono base class pointers se display function call karwaya!
    // and as humne padhaa tha, ki baseclass pointers se sirf base class ke hi members function call ho sakte hai! toh uss cheez se bachne ke liye, humne base class ke display function ko virtual declare krdiya, taaki unn derived class ke khud ke hi display functions call ho! and in the end vahi hua!
    // but agar hum kisi bhi ek derived class ka display function htaa de na, toh jo pointer uss derived class ke object ko point kr rha hai uss pointer se agar display function call krenge na toh vo base class ka display function call krdega!
    // and yahaa humne base class ke display me kuch likha hi nhi hai, toh fir kuch print hi nhi hoga uss derived class ke liye! (agar base class ke display me kuch likha hota toh vhi uske hisaab se hi output aajaata sirf uss derived class ke liye jiska display function humne comment out krdiya hai, agar base class ke display me cout<<"Hi!; likha hota toh uss derived class ke liye vhi print hojaata!), hope it got clear!
    // Agar koi doubt hai toh kisi bhi ek derived class ka display function hataa ke dekh lo, vhi output hoga jo base class ke display me likha hai!
} // hence this is Virtual function!

// So lets, give a short formal knowledge of Compile Time and Runtime polymorphism! and related all topics!
// Compile Time Polymorphism : Compiler time polymorphism, also known as static polymorphism or early binding, is resolved during compile time. The two main techniques used to achieve compiler time polymorphism in C++ are function overloading and operator overloading.
//                           : Function Overloading : Function overloading allows multiple functions to have the same name with different parameters (type or number of parameters). The correct function to call is determined at compile time based on the arguments passed to the function.
//                           : Operator Overloading : Operator overloading allows you to redefine the way operators work for user-defined types. This can make classes behave more like built-in types.

// Runtime Polymorphism : Runtime polymorphism, also known as dynamic polymorphism or late binding, is resolved during runtime. It is achieved through inheritance and virtual functions.
//                      : Virtual Functions : Virtual functions are member functions in a base class that can be overridden in a derived class. "The function to call is determined at runtime based on the type of the object pointed to", not the type of the pointer. (Double quoted line is important, upar hum thora galat phrase kr rhe the logic ko, but baaki sab sahi kiya hai upar, bss bolne ka tareeka thora galat tha upar!)

// Abstract Base Class!
// There is a term called Pure Virtual Function!, and Abstract Base class and Pure Virtual Functions are Inter-related! as becoz Abstract Base class are those, jinke paas atleast ek pure virtual function hota hai!
// Abstract base class vo hoti hai jisko banaya hi isliye jaata hai taaki usse aur derived classes bane! abstract base class ko inherit krne ke liye hi banaya jaata hai, uski khud ke function ke defintion as such nhi hote, so abstract base class is made as a template to inherit into the derived classes!
// And abstract base class ko banane ke liye, uss class ke andar atleast ek pure virtual function hona hi chahiye!
// Like in the below example jo humne dekha tha, that isme jo base class hai uski koi as such khud ki koi functionalities nhi hai, and then usme ek virtual function hai display naam se, pr usko pure bnaane ke liye hum usko = 0 krdenge, kyunki abhi tak kya ho rha tha ki jab hum base class ke pointer se derived class ka display function call kr rhe the and agar derived class ka display function naa ho udhar toh base class ka display function call ho jaa rha tha! and as becoz uss base class ke display me kuch hai nhi toh uss derived class ke liye koi output nhi aa rha tha!
// Toh ab agar hum Base class ke display function ko = 0 krdenge toh vo do-nothing function ban jayega! and ye do nothing function ko hi pure virtual function kehte hai, ye krne pr even tho agar derived class ka koi display function hai, fir bhi base class ka display call nhi hoga! kyunki vo ab bss inherit krne ke liye banaya hua hai, pr usme kuch hai nhi khud ka, and vo ab pure virtual function hai!
// virtual aur pure-virtual me yhi difference hai! ki virtual jo hai vo agar kisi derived class ka display function naa ho toh base class ka call hojayega (but bhale hi print kuch nhi hoga kyunki humne usme kuch likha nhi hai!) aur pure virtual me even tho derived class ka koi display function nhi hai, fir bhi base class ka display call nhi hoga!
// And from this pure-virtual function ke kaaran, ab Base class ab proper Abstract Base class ban jayega! kyunki ab pehle jo display function bhi call ho jaa rha tha, ab pure banne ke baad vo bhi call nhi hoga! and hence now base class is now proper abstract base class! as becoz ab vo sirf inherit hone ke liye hi use hoga! 
#include<iostream>
#include<cstring>
using namespace std;

class CWH {
    protected:
        string title;
        float rating;
    public:
        CWH (string s, float r) {
            title = s;
            rating = r;
        }
        virtual void display() = 0;
};

class CWHVideo : public CWH {
    float VideoLength;
    public:
        CWHVideo (string s, float r, float vl) : CWH(s, r) {
            VideoLength = vl;
        }
        void display() {
            cout<<"This is an amazing video with title : "<<title<<endl;
            cout<<"ratings : "<<rating<<" out of 5 stars!"<<endl;
            cout<<"Length of this video is : "<<VideoLength<<" Minutes!"<<endl;
        } // Pr ab agar abstract base class banne ke baad, agar hum kisi bhi derived class ka display function nhi likhenge, toh error show krega, kyunki base class ka run nhi kr sakte, toh derived class ke paas toh khud ka hona chahiye!
};

class CWHText : public CWH {
    float words;
    public :
        CWHText (string s, float r, int wc) : CWH(s, r) {
            words = wc;
        }
        void display() {
            cout<<"This is an amazing text tutorial with title : "<<title<<endl;
            cout<<"ratings : "<<rating<<" out of 5 stars!"<<endl;
            cout<<"Words count of the text is : "<<words<<" Words!"<<endl;
        }
};

int main() {
    string title;
    float rating, vlen;
    int words;

    title = "C++ Video tutorial!";
    vlen = 4.56;
    rating = 4.45;
    CWHVideo Cvdo(title, rating, vlen);
    // Cvdo.display();

    title = "C++ Video tutorial text!";
    words = 433;
    rating = 4.15;
    CWHText Ctext(title, rating, words);
    // Ctext.display();

    // Through Base class pointers!
    CWH* CWH_pointer[2];
    CWH_pointer[0] = &Cvdo;
    CWH_pointer[1] = &Ctext;

    // Yahaa pr hum runtime polymorphism ke logic se display kr rhe hai! pr pointer bnaane se pehle iss hi int main me upar hum normally hi values display kr rhe the!
    CWH_pointer[0]->display();
    CWH_pointer[1]->display();
}