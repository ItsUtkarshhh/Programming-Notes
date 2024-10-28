// Here when the object is destroyed then we also want ki jo dynamic memory vo gher ke baitha hai usko vo free krde, so to free that memory we use destructor!
// Destructor never takes an argument nor it returns any value!
#include<iostream>
using namespace std;

int count = 0;

class num {
    public :
    num() { // Yahaa humne ek constructor create kiya taaki jab bhi koi bhi object create ho toh ye call hojaye!!
        count++;
        cout<<"This is the point where the constructor is called for object number"<<count<<endl;
    }

    ~num() { // Yahaa humne ek destructor call kiya taaki jab bhi compiler ko ptaa chale ki aage is particular object ka koi kaam nhi hai toh ye destructor uss object ko destroy krde and taaki jo memory space uss object ne le rakhi thi vo free hojaye!!
        cout<<"This is the time where destructor is called for object number"<<count<<endl;
        count--;
    }
};

int main() {
    cout<<"We are inside our main function"<<endl; // These cout statements are just to tell where we are in the code while executing it.
    cout<<"Creating first object n1"<<endl;
    num n1; // First object is created so now the constructor will be called!!
    {
        cout<<"Entering this block"<<endl; // Entering this block we created two more objects toh ab unke bhi constructors bhi call honge!
        cout<<"Creating two more objects"<<endl;
        num n2,n3; // Two more objects are created so now unke liye bhi constructor call kiya jayega!
        cout<<"Exiting this block"<<endl;
    } // Now as soon as hum is block ko leave kre to jo objects unka future me koi kaam nhi hai toh vo dono objects ke liye destructor call hojayega and it will free us the memory space! isliye output me print hua hai "This is the time where destructor is called for object number 3 and 2". 
    cout<<"Back to main"<<endl; // Coming back to main and now as the object num1 ka bhi future me koi kaam nhi hai toh uske liye bhi ab destructor call hojayega and jo space usne occupy kr rakha tha vo bhi free hojayega!!
    return 0;   
}