#include <iostream>

const int getValue() {
    return 42;
}

const int func(int x) {
    x = x + 1;
    return x;
}

int main() {
    const int val = getValue();
    // val = 100; // This will cause a compilation error because val is declared as const
    std::cout << "Value: " << val << std::endl; // Output: Value: 42
    func(3);
    return 0;
}