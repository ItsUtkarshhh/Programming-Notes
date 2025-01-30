// Exception Handling!
// Exception : An unexpected problem that occurs during program execution (runtime).
// Exception Handling : A mechanism to handle these runtime errors without crashing the program.
// Types of Exceptions : Synchronous Exceptions : Caused by logical errors in the program (e.g., divide by zero, invalid input).
//                     : Asynchronous Exceptions : Caused by external factors (e.g., hardware failure, disk error, keyboard interrupt).

// C++ Exception Handling Keywords : try : Defines a block where exceptions might occur.
//                                 : catch : Catches and handles exceptions thrown in the try block.
//                                 : Generates (throws) an exception when an error is detected.

// Basic Syntax of Exception Handling in C++ : try { // Code that may throw an exception throw "An error occurred"; // Throwing an exception catch (const char* msg) { cout << "Exception caught: " << msg << endl; }

// Why Do We Need Exception Handling : Keeps Error Handling Separate from Normal Code, Avoids cluttering the main logic with error-checking conditions.
//                                   : Better Code Readability & Maintainability, Errors are handled in a structured way using try/catch.
//                                   : Allows Selective Exception Handling, Functions can choose which exceptions they handle and pass the rest to the caller.
//                                   : Supports Grouping of Error Types, Exceptions can be categorized into custom classes for better organization.
//                                   : Note : Multiple catch statements can be used to catch different type of exceptions thrown by try block.

// C++ program to demonstate the use of try, catch and throw in exception handling.
#include <iostream>
using namespace std;

int main() {
	try { // try block
		int numerator = 10;
		int denominator = 0;
		int res;

		if (denominator == 0) { // check if denominator is 0 then throw runtime error. Here runtime_error is a specialised class under the stdexcept header file
			throw "Division by zero not allowed!";
		}
		res = numerator / denominator; // calculate result if no exception occurs
		cout << "Result after division: " << res << endl; // printing result after division
	}
	catch (const char* e) { // catch block to catch the thrown exception
		cout << "Exception " << e << endl; // print the exception
	}
	return 0;
} // So this was the basic syntax for exceptional handling! where we have understoo the flow of how to handle the exceptions in C++!

// Using Exception Classes in C++ (stdexcept)!
// Understanding the stdexcept Library : C++ provides the stdexcept header file, which contains predefined exception classes for different error types.
//                                     : These classes inherit from the base class exception, which is the general class for all exceptions in C++.
//                                     : This approach allows us to use specific exception types rather than generic exceptions.

// Brief overview of hierarchy of Exceptions!
// exception (Base Class) : This is the base class for all exceptions in C++. All standard exception classes inherit from this class. 
// logic_error (Sub-class of exception) : This class represents errors related to logical mistakes in the program (i.e., problems that can be detected at compile time or are due to wrong assumptions in logic).
//                                      : Common sub-classes : domain_error : Raised when a function receives an input that is outside its valid domain (e.g., taking the square root of a negative number).
//                                                           : invalid_argument : Raised when an invalid argument is passed to a function (e.g., passing a negative number where only positive is allowed).
//                                                           : length_error : Raised when an operation would exceed the allowable size or length (e.g., trying to resize a vector beyond its maximum size).
//                                                           : out_of_range : Raised when an index or value is out of the acceptable range (e.g., accessing an element beyond an array's bounds).
// runtime_error (Sub-class of exception) : This class represents errors that occur during the runtime execution of a program (i.e., these errors cannot be predicted at compile time).
//                                        : Common sub-classes : range_error : Raised when a value goes beyond an acceptable range (e.g., attempting to store a number too large for a data type).
//                                                             : overflow_error : Raised when an arithmetic overflow occurs (e.g., adding two large integers and exceeding the maximum representable value).
//                                                             : underflow_error : Raised when an arithmetic underflow occurs (e.g., subtracting too small a value from another and going below the smallest representable value).
//                                                             : bad_alloc : Raised when a memory allocation fails (e.g., when new cannot allocate memory).

// And then we have a .what() method, which In C++, the .what() method is a virtual function defined in the std::exception class and inherited by all standard exception classes! ek general implementation of .what() base class me hoti hai and baaki inherited class me bhi iski alag implementation hoti hai toh vo uss hisaab se override hojaati hai!
// Also from the above classes for exceptions, itna toh samajh aagya hoga ki we have multiple base classes and derived classes! some base classes are also derived from another base class! but there is only one supreme base class that does not inherit any other class and that is "exception" class!

// .what() method : Functionality : The .what() method is used to retrieve a C-style string (const char*) that describes the exception.
//                : Returns : It returns a pointer to a null-terminated character string (const char*) that represents the exception message.
//                : It is a virtual function!

// Lets see some example...
// Example 1 : This is the modified version of the above example!
#include <iostream>
#include<stdexcept>
using namespace std;

int main() {
	try { // try block
		int numerator = 10;
		int denominator = 0;
		int res;

		if (denominator == 0) { // check if denominator is 0 then throw runtime error. Here runtime_error is a specialised class under the stdexcept header file
			throw runtime_error("Division by zero not allowed!"); // Here we have used the runtime_error class to determine this exception! kyunki technically this is the correct type of exception for dividing by zero! jiss type ka error hai uss type ka class hi handle krega!
            // jaise iss case me dividing by zero ek runtime error ki category me aata hai toh hum isme yhi class use krenge! koi aur class use krenge toh compile error dikhayega! kyunki it's not just about ki hum kya print kr rhe hai! kyunki "stdexcept" me jo code likha hua hai runtime_error ya kisi bhi aur class ka vo iss hisaab se hi likha hai ki ek particular tarah ke errors ko hi handle krne ke liye banaa hua hai! isliye using some other kind of exception class will cause compile error!
		}
		res = numerator / denominator; // calculate result if no exception occurs
		cout << "Result after division: " << res << endl; // printing result after division
	}
	catch (const runtime_error& e) { // catch block to catch the thrown exception
		// print the exception
		cout << "Exception : " << e.what() << endl; // Here you should be using what() as becoz now as you are using the class runtime_error! so to catch exception messages you need to use .what() keyword!
	}
	return 0;
}

// Similarly we can write more catch blocks, ab jiss tarah ka exception hoga uss catch block ke saath match hojayega and uske according error throw hojayega!
// Another example, and it contains multiple catch statements! and it will throw and catch different exception based on the input!
#include <iostream>
#include <stdexcept>
using namespace std;

void processInput(int value) { // Process the input value
    if (value < 0) {
        throw invalid_argument("Negative value not allowed!");
    }
    else if (value > 100) {
        throw out_of_range("Value out of range!");
    }
}

int main() {
    try {
        processInput(-5);
    }
    catch (const invalid_argument& e) {
        cout << "Caught invalid_argument: " << e.what() << endl;
    }
    catch (const out_of_range& e) {
        cout << "Caught out_of_range: " << e.what() << endl;
    }
    catch (const exception& e) { // this is for more genral, ki agar kisi type ka exception match nhi hua toh ye catch statement use hojayega! kyunki here we have used "exception" class, ab kisi bhi tarah ka exception ho, hoga toh vo iske under hi! isliye we include this at the last! ki agar kuch nhi match hua toh ye match hojayega!
        cout << "Caught an exception: " << e.what() << endl;
    }
    return 0;
}

// After seeing standard exceptions in C++, lets move to custom exceptions!
// To create custom exceptions in C++, we need to : Inherit from the exception class: This class is defined in the stdexcept header, and all standard exceptions in C++ inherit from it. So, for custom exceptions, we need to create a class that inherits from exception.
//                                                : Define a constructor : This constructor will initialize an error message, which will be used when the exception is thrown.
//                                                : Implement the what() function: The what() function is used to return the error message as a string, which will be displayed when the exception is caught.
//                                                : By following these steps, we can handle custom exceptions in our program

// Note : Virtual functions are functions that are declared in a base class using the virtual keyword, allowing derived classes to provide their own implementations (overriding them). In simpler terms, a function defined as virtual in the base class can be overridden in any derived class.
//      : In the case of the .what() function, it is a virtual function already defined in the exception base class. Derived classes can then override the .what() function to provide their specific error messages. The override keyword is used in the derived class to indicate that we're providing a custom implementation for this function.

// The code demonstrates how to create a custom exception class in C++ by inheriting from the built-in exception class provided in the stdexcept header
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
// Explaination : Class Definition : MyException is a custom exception class that inherits from the standard exception class.
//                                 : The MyException class contains a private string variable errorMessage to store the error message passed during exception creation.
//              : Constructor : The constructor of MyException initializes the errorMessage string with the value passed to it when an exception is thrown.
//              : Overriding the what() Function : The what() function is overridden from the base exception class. and what() returns a pointer to a C-string (const char*) which is the error message stored in the errorMessage member. This is achieved by calling the c_str() function on the errorMessage string object.
//                                               : Const correctness : const ensures that the what() function doesn't modify the state of the object.
//                                               : Noexcept : This ensures that what() will not throw any exceptions.
//              : Catching the Exception : In the main function, the exception is thrown using throw MyException("Something went wrong!");.
//                                       : The catch block catches this specific MyException and calls e.what() to print the error message ("Something went wrong!").
//                                       : If an exception other than MyException occurs, the second catch block catches it as a generic std::exception.

// ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------->