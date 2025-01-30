#include<iostream>
#include<string>
#include<stdexcept>
using namespace std;

class MyException : public exception { // Custom exception class inheriting from std::exception
    private:
    string errorMessage; // Member variable to store error message

    public:
    MyException(const string& msg) : errorMessage(msg) {} // Constructor to initialize errorMessage with a string

    const char* what() const noexcept override { // Overriding the virtual what() method to return custom error message
        return errorMessage.c_str(); // c_str() returns a pointer to a C-style string (const char*) representing the contents of errorMessage
    }
};

int main() {
    try {
        throw MyException("Something went wrong!"); // Throwing custom exception with a message
    }
    catch (const MyException& e) {
        cout << "Caught MyException: " << e.what() << endl; // Catching the custom exception and printing the error message
    }
    catch (const std::exception& e) {
        cout << "Caught exception: " << e.what() << endl; // Catching any other exceptions and printing the generic error message
    }
}