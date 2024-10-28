// New and Delete Keywords!!
// Compile aur Run do alag alag process hote hai, vs code me dono saath me hojaata hai, pr vaise ye dono alag alag hote hai
// Compile Time : Jab hum poora code likh dete hai uske baad jab hum program compile krte hai, tab ek documentation banti hai usme poore program ke baare me likha hota hai ki program ko kya requirements hai and kitni memory chahiye, toh utni memory allocate krdeta hai compiler uss program ko!
// Run Time : Jab sab compile hojaye aur documentation ban jaaye, and after jab hum compile hone ke baad apne inputs and all dede, uske baad program jab humare diye gaye intructions ko follow krke hume uske according ouput deta hai, vo hota hai Runtime! and iss Runtime me jo memory allocate hoti hai usko kehte hai Dynamic Memory!
#include<iostream>
using namespace std;

int main() {
    // Using Basic method and assigning values!
    int a = 4;
    int* ptr = &a; // Here we have assigned the address of the block whose name is a and has stored the value 4.
    *ptr = 50; // Here we can also update the value!
    cout<<"Value at address of a is : "<<*(ptr)<<endl; // Here we have printed that value.

    // Static Memory Allocation :
    // When we write a code like int a = 4; yahaa memory abhi code likhte hi allocate nhi hoti, ye code likhne ke baad jab hum usko compile krte hai, tab ek documentation ready krta hai compiler ki jab iss program ko run kiya jaaye toh kyaa kyaa requiremnets hongi, VS Code me compiler and run saath me ho rha hai, vrna agar bhot old skool compiler use kre jaise jo 1st year me kiya tha usme pehle compile krna pad rha tha and then run hota tha!
    // Toh compile krne pr compiler vo saari requirements full fill krta hai through documenting the code and saari jitni bhi memory allocate honi hai jo static hai (Static keyword ki baat nhi kr rhe) unn sabko vo allocate krdeta hai taaki jab programm run ho tab tab jo bhi memory hai uspe vo sara program run ho jaye!

    // Dynamic Memory Allocation :
    // When we write int* p = new int(40); toh ye vaala part of code documentation me nhi hota, compiler isko aise samjhta hai ki chalo theek hai 1 int ke liye hume ek aur memory block allocate krna pad sakta hai during the runtime, jab program run ho rha ho!
    // Jab hum run krte hai program tab ye vaali memory allocate hoti hai, compiler ye memory allocate nhi krta, vo runtime me khud allocate hojaati hai!

    // Using New Operator!!
    int* p = new int(40); // Here we are allocating one int size block and giving its address to p so that it can access it dynamically!
    cout<<"Here dynamically allocated memory is : "<<*(p)<<endl;
    delete p;

    int* arr = new int[3]; // Here we are allocating 3 contigous memory locations and giving the address of its 0th index to arr, so that it can access it dynamically!
    arr[0] = 10;
    // *(arr+1) = 20; // This will also work!
    arr[1] = 20;
    arr[2] = 30;
    cout<<"Value at arr[0] is : "<<arr[0]<<endl;
    cout<<"Value at arr[1] is : "<<arr[1]<<endl;
    cout<<"Value at arr[2] is : "<<arr[2]<<endl;

    // Using Delete Keyword!!
    delete[] arr; // Here this statements will delete the dynamically allocated array and due to which it will print garbage values only, kbhi kbhi ye allocated memory ko free toh krdeta hai pr, show nhi krta kabhi kbhi! so thats not a problem, but haa memory free ho chuki hai jo allocate hui thi array ke liye! 
    arr = nullptr;
}

// Pointers to objects and arrows in CPP
// Here we will try to create objects using Pointers!
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
    // Creating objects normally!
    Complex c1;
    c1.setdata(1,5);
    c1.getdata();
    // In the above code we use the standard way to create objects and call member functions of the class!, but now we will create objects and call its member functions using pointers and arrow operators!

    // Creating objects using pointers :
    // The below code will give the same value as of the above!
    // Complex c1;
    Complex* ptr = &c1; // Storing the address of the object in ptr and then de-referencing the ptr pointer to access the data members of the class Complex! 
    (*ptr).setdata(1,5);
    (*ptr).getdata();

    // Creating objects using new operator :
    Complex* ptr2 = new Complex; // This can be an another way of creating objects! and here objects are being created dynamically!
    (*ptr2).setdata(1,5); // Here we are accessing the class member function using de-refrence and dot operator! after the objects are created dynamically!
    (*ptr2).getdata();

    // Creating objects using Arrow Operator :
    Complex c2;
    Complex* ptr3 = &c2; //Yahaa humne statically object create krdiya and here it is static allocation of memory to the complex type of object created! and here the object is already created before the runtime!
    // Complex* ptr = new Complex; //Here we are creating object dynamically, and the memory will be allocated to the Complex object during the runtime!
    ptr3->setdata(1,5); //Here we atre accessing the class member function using the Arrow operator!
    ptr3->getdata(); //Similary...
    return 0;
}

// Array of objects using pointers!
#include<iostream>
using namespace std;

// Below we have created a normal class, and made two functions!
class ShopItem {
    int id;
    float price;
    public :
    void setData(int a, float b) {
        id = a;
        price = b;
    }
    void getData() {
        cout<<"Id of the item is : "<<id<<endl;
        cout<<"Id of the price is : "<<price<<endl;
    }
};

int main() {
    int size = 3;
    ShopItem* ptr = new ShopItem[size]; // Dynamically created an array!
    int i, p;
    float q;
    ShopItem* ptrTemp = ptr; // Reason to create this ptrTemp is written after the first for loop!
    for(i = 0; i<size; i++) { // For loop to input the data from the user!
        cout<<"Enter the id and price of the item purchased : "<<i+1<<endl;//Humne yahaa i+1 likha hai becoz object ki numbering ke liye, object 0 koi sense nhi banayega isliye i+1 krdiya taaki numbering 1 se ho!
        cin>>p>>q;
        ptr->setData(p,q);
        ptr++;
    } // Till the end of the loop, humara ptr pointer ++ hote hote 3 par pohoch jayega, and vhaa pe toh koi object hi nhi hai toh vahaa garbage value print hogi,
    // and output vaale for loop me hume starting se hi objects ko output kraana hai toh hum ye pointer ka first address ptrTemp me store krlenge and then usko hi dusre vaale for loop me use krenge!
    for(i = 0; i < size ; i++) { //For loop to output the data!
        cout<<"Item Number : "<<i+1<<endl;
        ptrTemp->getData(); // Used arrow operator to de-reference the Member function! 
        ptrTemp++;
    }
    return 0;
}

// This Pointer!
#include<iostream>
using namespace std;

class A {
    int a;
    public :
    void setData(int a) {
        // a = a; // This will show error becoz the compiler gets confused ki ye kis a ko kis a me assign krne ki baat ho rhi hai!
        // Now what happens in C++ is that priority is given to local variables, due to which class vaale a ko koi fark nhi padta hai kyunki local variable setData me uska khud ka local a hai!
        this->a = a; // Yahaa humne this likh ke btaa diya ki "iss" variable ke andar (jo ek class variable hai) setData ke local variable ki value store krni hai!
        //Agar hum yahaa this na lagaye toh, a = a vaale a's and argument vaala a sab ek hi hai, isliye hum class variable vaale me a me kuch assign nhi kr paa rhe! isliye this lgaana zaruri hai is case me!
    }
    void getData() {
        cout<<"The Value of a is : "<<a<<endl;
    }
}; // "This" is a keyword, which is a pointer which points to the object which invokes the member function!

int main() {
    A a;
    a.setData(4);
    a.getData();
    return 0;
}
// But is that the only thing this pointer is used for?? as becoz agar yhi dikkat hoti jo upar vaale code me hai toh hum bss variable ka naam change krke store krdete, but ofcourse not, "this" ka aur bhi kaam hai!

// Lets learn more about this keyword :
// Example 1 :
#include<iostream>
using namespace std;

class A {
    int a;
    public:
    A setdata(int a) { // Here rather than creating it a void function, we made it a A type function where A is a data type!
        this-> a = a; // Used this so that compiler can get to know ki kis a me kis a ko daalna hai!
        return *this; // Yahaa humne vo value jo this pointer ne store ki hai vo hum return kr rhe hai using de-refrence operator! As we know that this is pointer that points to the object when it is created, or can say it stores the address of the object that is created just like a normal pointer stores the value of a normal variable, similarly in classes this is a pointer that stores the address of the object which is created!
    } //And that's why "return *this" likhne pr ye object return kr rha hai! kyunki ye uspar hi point kr rha tha toh usko de-refrence krne pr vo vhi return kr rha hai ab!
    void getdata() {
        cout<<"The value of a is "<<a<<endl;
    }
};

int main() {
    A a; // Object created!
    a.setdata(4).getdata(); // Here we called both the member functions in one line! as becoz jo setdata function hai class me vo object return kr rha hai, toh hum vo object ko firse use kr rhe hai getdata func ko call krne ke liye!
    return 0;
}

// Example 2 :
#include<iostream>
using namespace std;
// Here we are trying to demonstrate that why & is used while declaring the setdata function!
class A {
    int a;
    public:
    A  setdata(int a) { // Jaisa humne pehle padhaa tha ki ek hi block of memory ko hum ek se zyada naam de sakte hai using refrence variables, we can write : int a = 5; yahaa humne ek block of memory ko a naam diya aur usme 5 store krdiya, and then we wrote, int &b = a; here we have said that, ki jis block of memory ka naam a hai usko b bhi krdo! taaki hum ek hi block of memory ko do naam de sake and usko hum do naam se refer kr sake, isse hume ek hi value ko store krne ke liye do block of memory nhi chahiye hogi and isse memory bhi bachegi!
        this -> a = a; // To bss aisa kuch kaam humne kiya hai upar A &setdata me ho rha hai. like it is just preventing from generating copies of the same value to pass in two different places! but agar yahaa pr hum ye vaala & htaa bhi de fir copies banegi pr do different jagah store nhi hogi kyunki humne int main() me &z = a kiya hua hai mtlb humne z ko a se reference kiya hua hai!
        cout<<"Address of returned obj is: "<<this<<endl;
        return *this; // Here we return the object, as this ek uss object pr point kr rha hai jisne iss member function ko call kiya hai aur this me uss object ka address stored hai and toh ab ye uss object ko de-refenrence krke return kr rha hai! isko aisa bhi maan sakte hai ki object ko hi return kr rha hai! aur jo copies hoti hai object unme se ek setdata me rehti hai and dusri copy return hoti hai agar & na lagaye toh, isliye dono ka address different hojaata hai, aur & lgaane pr vo bss as it is object return krdeta hai jo setdata me hai! pr bina & ke vo ek uss object ki copy bnaa ke send krta hai int main me, it's similar to call by reference and call by value!
    }
    void getdata() {
        cout<<"The value of a is "<<a<<endl;
    }
};

int main() {
    int x = 5;
    A *a = new A; // Dynamically created an object! and saved its address in a!
    cout<<"Address stored in pointer: "<<a<<endl; //printing that address
    A &z = (*a).setdata(x); // Here we intiallized a reference variable z, jisme humne "a" vaale object se setdata() member function ke through ek value set ki thi, uss hi object ko ab hum ek dusra naam de rhe hai "z"! 
    z.getdata(); // Printing the value of z!
    cout<<"Address of object jo humein mila is: "<<&z<<endl; // Printing z's address!
    cout<<"Address stored in pointer: "<<a<<endl; // Printing a's address
    // Hence in this code, all the addresses should be same as sab ek hi hai, bss alag alag way aur alag alag naam se ek hi value store kr rhe hai!
    return 0;
}

// Example 3 :
#include<iostream>
using namespace std;

class A {
    int a;
    public:
    A setdata(int a) { // Here we have setdata as "A" type and it will return the object! 
        this -> a = a;
        cout<<"Address of returned obj is: "<<this<<endl; // To print the address of this pointer!
        return *this; // Here it will return object which will be then used in getdata to print the value, and here it will geneate copies of it! but the copies will store in one memory block only, becoz we have referenced the "z" as "a" means we have just given the a another name! hence a and z are storing the same value! and they both have the same address!
    } // Agar hum yahaa A & setdata nhi likhenge toh iski is *this ki copies pass hongi, pr vo copies in the end ek hi jagah chali jayengi kyunki humne &z = a kiya hua hai, pr agar hum ye &z = a naa kre tab a ki jo value hum assign krenge z me vo kisi aur memory block me store hojayegi. pr abhi vo refrence krdene ke kaaran ek hi jagah store hai!
    void getdata() {
        cout<<"The value of a is "<<a<<endl;
        cout<<"Address of a "<<&a<<endl; // here you will see the difference, ki object ki copy return hui hai, jab humne a.setdata(5).getdata(); ye call kiya, toh setdata me 5 gya and jo int main vaala "a" hai uska address store hua "this" me, and then ek copy of the object return hua getdata() me and now jab humne getdata() me "a" ka address print karaya toh vo address alag tha setdata() me jo address tha usse! kyunki setdata() me "return *this" krne se ek copy return hua tha jisko getdata() ne use kiya isliye usme "a" ka address alag tha baaki harr jagah se!
        // Kyunki getdata() ke alawa harr jagah hum original a ko access kr rhe hai, chaahe this pointer me uska address store krke yaa z ko usse reference krke! isliye harr jagah address same print hoga bss yhi getdata() me different address print hoga!
    }
};

int main() {
    A a;
    a.setdata(5).getdata();
    cout<<"Address of a is : "<<&a<<endl; // Printing the address of a object!
    A &z = a; // referencing z to a!
    cout<<"Address of z is : "<<&z<<endl; // Printing the address of z object!
    // cout<<"Value at z is : "<<z<<endl; This is not how we print the value stored in a object, we use it member function!
    z.getdata(); // printing z's value!
    return 0;
}

// Example 4 :
#include<iostream>
using namespace std;

class A {
    int a;
    public:
    A setdata(int a) {
        this -> a = a;
        cout<<"\nAddress of returned object from setdata is: "<<this<<endl; // Yahaa jo address print hoga vhi "a" object ka bhi address hoga!
        return *this; // Yahaa jab humne & use nhi kiya toh "return *this" krne pr ek copy of the object bnaa jisme se ke baar object ka address uske this me store hogya and dusra "a" ko int main me paas hogya return *this ke through!
    } // agar hum & lgaa dete, toh as it is object pass hojaata int main me!
    void getdata() {
        cout<<"\nAddress of object operated by getdata is: "<<this<<endl;
        cout<<"Value inside is: "<<a<<endl;
    }
};
int main() {
    int x = 5;
    A a;
    cout<<"\nAddress of x in main is: "<<&x;
    cout<<"\nAddress of 'a' is: "<<&a<<endl;
    a.setdata(x).getdata(); // Yahaa a.setdata(x) ke form me setdata ne ek object return kiya hai jiska address alag hai pehle vaale se, isliye iska jab hum address print krayenge getdata() vaale function ke through this will have a different address print hua!
    cout<<"\nAddress of 'a' is: "<<&a<<endl;
    return 0;
}

// Example 5 :
#include<iostream>
using namespace std;

class A {
    int a;
    public:
    A & setdata(int &x) { // Here setdata se pehle vaala & object se copies hone se bachaa rha hai and &x vaala & x ki copies hone se bachaa rha hai, and ofcourse kisi cheez ki copy ban rhi hai toh vo kahin aur hi store hogi
        cout<<"\nAddress of x in setdata is: "<<&x<<endl; // Agar x ke pehle & nhi lgaa hota toh x ki ek copy pass hoti and due to which yahaa aur int main me do different "x" bante and dono ka address alag hota!
        this -> a = x;
        cout<<"\nAddress of returned object from setdata is: "<<this<<endl; // Iska address same hi hoga jo object ka hai, kyunki isme object ka address hi store hai, chahe hum setdata ke pehle & lgaaye ya nahi!
        return *this;
    }
    void getdata() {
        cout<<"\nAddress of object operated by getdata is: "<<this<<endl; // Pr agar hum setdata function ke pehle & na lagaye toh yahaa pr this ki value change hojayegi kyunki int main me a.setdata jo hai usme ek copy of object return hoga jo ofcourse ek alag jagah pr store hoga! pr agar hum setdata ke pehle & lagayenge toh this ka address setdata aur getdata dono me same hoga!
        cout<<"Value inside is: "<<a<<endl;
    }
};

int main() {
    int x = 5;
    A a;
    // Upar vaale functions me jo bhi hua hai uske hisaab se hi yahaa pr outputs ayenge!
    cout<<"\nAddress of x in main is: "<<&x;
    cout<<"\nAddress of 'a' is: "<<&a<<endl;
    a.setdata(x).getdata();
    cout<<"\nAddress of 'a' is: "<<&a<<endl;
    return 0;
}