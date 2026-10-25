#include<iostream>
using namespace std;

template <typename T1=int, typename T2=float, typename T3=char> // Default types: T1 → int, T2 → float, T3 → char
class myClass {
    T1 value1;
    T2 value2;
    T3 value3;

    public:
    myClass(T1 v1, T2 v2, T3 v3) { // Constructor to initialize values
        value1 = v1;
        value2 = v2;
        value3 = v3;
    }

    void display() { // Display function
        cout << "Value of value1: " << value1 << endl;
        cout << "Value of value2: " << value2 << endl;
        cout << "Value of value3: " << value3 << endl;
    }
};

int main() {
    // Using default template types (int, float, char)
    myClass<> obj1(1, 2.5, 'A'); // No types specified → Uses default types
    obj1.display();

    cout << endl;

    // Using custom template types (float, char, int)
    myClass<float, char, int> obj2(2.5, 'A', 1); // Overriding default types
    obj2.display();
}