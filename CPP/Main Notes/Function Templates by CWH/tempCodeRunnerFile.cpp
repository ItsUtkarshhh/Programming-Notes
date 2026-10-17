#include <iostream>
using namespace std;

template <typename T>
void func1(T a) {
    cout << "Template function1 for generic type: " << a << endl;
}

template <typename T>
void func2(T a) {
    cout << "Template function2 for generic type: " << a << endl;
}

int main() {
    func1(5);
    func2('A');
    return 0;
}