#include <iostream>
#include <iomanip>  // Include the iomanip library
using namespace std;

int main() {
    int num = 123;
    double pi = 3.14159;

    cout << setw(10) << num << endl;      // Outputs "       123"
    cout << setw(10) << pi << endl;       // Outputs "   3.14159"
    cout << setw(10) << "Hello" << endl;  // Outputs "     Hello"

    // You can also chain manipulators
    cout << setfill('*') << setw(10) << num << endl; // Outputs "*******123", means ki pehle humne set krdiya ki 10 characters ka jagah output lega! and then agar output usse chhota hai toh humare paas choice hai ki yaa toh usko hum khaali chhor de, yaa toh setfill ka use krke unn spaces ko fill krde! and agar output more than 10 characters hota toh simply vo jo limit hai uski koi value nhi rehti!
}