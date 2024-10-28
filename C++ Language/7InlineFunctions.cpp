#include<iostream>
using namespace std;

inline int product(int a, int b) { // Inline function just reduces the compile time, but it is helpful only for small and simple functions.
    return a*b;
}

int main() {
    int x,y;
    cout<<"Enter the numbers : ";
    cin>>x>>y;
    cout<<"Product of the two numbers : "<<product(x,y);
    return 0;
}
// Inline functions are not a command, its a request to the compiler to make it inline and it depends on compiler to whether to make it inline or not.
// Functions which are recursive, contains loops, static variables, switch or goto statements can't be made inline.
// So basically inline kaam krta ye hai ki compile time me jab function calls hote hai toh execution main() se uss function pr jaata hai jo call hua hai! and isme thora time lag jaata hai! so to just save that time, we request to make some functions inline! kyunki isme ye hota hai ki jis function ko inline banaya gya hai usko jab call krte hai main() me toh vo uss function pr jaata nhi hai, balki uss function ko hi le aata hai uss main() ki execution line me! taaki jaane me time waste na ho! so this is what the kind of use of Inline functions to reduce time taken! 

// Default arguments
#include<iostream>
using namespace std;

float MoneyRecieved (int CurrentAmount, float InterestRate = 1.50) {
    return CurrentAmount*InterestRate;
}

int main() {
    int Money = 100000;
    cout<<"If your current money is "<<Money<<" Rs, then after interest you will get "<<MoneyRecieved(Money)<<" Rs after one year."<<endl; // Here our compiler used that "default value" that we have passed in the function defintion.
    cout<<"If your current money is "<<Money<<" Rs, then after interest you will get "<<MoneyRecieved(Money,1.6)<<" Rs after one year."; // Here we changed the value on our own and we passed a new value, so means if we won't pass any value in the function call here then it will take that default value which we have given in function defintion that is 1.5.
    return 0;
} // All the default function arguments should be on the extreme right, otherwise we won't be able to call it, make sense >_<.