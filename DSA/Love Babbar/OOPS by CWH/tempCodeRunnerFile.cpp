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