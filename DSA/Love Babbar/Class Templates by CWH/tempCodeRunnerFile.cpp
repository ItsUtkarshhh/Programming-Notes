#include<iostream>
using namespace std;

template <typename T1=int, typename T2=float, typename T3=char> // Ye likhne ke baad agar mai int main me class ke objects ko use krte time koi data type specify nhi krunga toh automatically first value ko int, second value ko float and third ko char data type alot hojayega!
class myClass {
    T1 value1;
    T2 value2;
    T3 value3;
    public :
    myClass(T1 v1, T2 v2, T3 v3) {
        value1 = v1;
        value2 = v2;
        value3 = v3;
    }
    void display() {
        cout<<"Value of value1 : "<<value1<<endl;
        cout<<"Value of value2 : "<<value2<<endl;
        cout<<"Value of value3 : "<<value3<<endl;
    }
};

int main() {
    myClass<> obj1(1,2.5,'A');
    obj1.display();

    cout<<endl;

    myClass<float, char, int> obj2(2.5,'A',1);
    obj2.display();
}