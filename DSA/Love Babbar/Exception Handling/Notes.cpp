// What is Exception Handling?
// In C++, exceptions are runtime anomalies or abnormal conditions that a program encounters during its execution. The process of handling these exceptions is called exception handling. Using the exception handling mechanism, the control from one part of the program where the exception occurred can be transferred to another part of the code. So basically using exception handling in C++, we can handle the exceptions so that our program keeps running.

// Exception: An exception is an unexpected problem that arises during the execution of a program our program terminates suddenly with some errors/issues. Exception occurs during the running of the program (runtime).
// Types of Exception! : Synchronous & Asynchronous
// Synchronous : Exceptions that happen when something goes wrong because of a mistake in the input data or when the program is not equipped to handle the current type of data it’s working with, such as dividing a number by zero.
// Asynchronous : Exceptions that are beyond the program’s control, such as disc failure, keyboard interrupts, etc.

// C++ provides an inbuilt feature for Exception Handling. It can be done using the following specialized keywords: try, catch, and throw with each having a different purpose.
/* Basic Syntax of Exceptional Handling!
try {         
     // Code that might throw an exception
     throw SomeExceptionType("Error message");
 } 
catch( ExceptionName e1 )  {   
     // catch block catches the exception that is thrown from try block
 } 
*/

// Try block : The try keyword represents a block of code that may throw an exception placed inside the try block. It’s followed by one or more catch blocks. If an exception occurs, try block throws that exception.
// Catch block : The catch statement represents a block of code that is executed when a particular exception is thrown from the try block. The code to handle the exception is written inside the catch block.
// Throw block : An exception in C++ can be thrown using the throw keyword. When a program encounters a throw statement, then it immediately terminates the current function and starts finding a matching catch block to handle the thrown exception.
// Note : Multiple catch statements can be used to catch different type of exceptions thrown by try block.

// Why we need Exceptional Handling : Separation of Error Handling Code from Normal Code : There are always if-else conditions to handle errors in traditional error handling codes. These conditions and the code to handle errors get mixed up with the normal flow. This makes the code less readable and maintainable. With try/catch blocks, the code for error handling becomes separate from the normal flow.
//                                  : Functions/Methods can handle only the exceptions they choose : A function can throw many exceptions, but may choose to handle some of them. The other exceptions, which are thrown but not caught, can be handled by the caller. If the caller chooses not to catch them, then the exceptions are handled by the caller of the caller. In C++, a function can specify the exceptions that it throws using the throw keyword. The caller of this function must handle the exception in some way (either by specifying it again or catching it).
//                                  : Grouping of Error Types : In C++, both basic types and objects can be thrown as exceptions. We can create a hierarchy of exception objects, group exceptions in namespaces or classes, and categorize them according to their types.

// C++ program to demonstate the use of try,catch and throw in exception handling.
#include <iostream>
using namespace std;

int main() {
	// try block
	try {
		int numerator = 10;
		int denominator = 0;
		int res;

		// check if denominator is 0 then throw runtime error. Here runtime_error is a specialised class under the stdexcept header file
		if (denominator == 0) {
			throw "Division by zero not allowed!";
		}

		// calculate result if no exception occurs
		res = numerator / denominator;
		// printing result after division
		cout << "Result after division: " << res << endl;
	}
	// catch block to catch the thrown exception
	catch (const char* e) {
		// print the exception
		cout << "Exception " << e << endl;
	}
	return 0;
} // So this was the basic syntax for exceptional handling! where we have understoo the flow of how to handle the exceptions in C++!

// Now, there are some classes, methods and functions and other things we can add into this!
// Now here, hum ek general sa exceptional handling ka code likh rhe the jisme ek normal sa exception throw kr rhe the! and then usko ek normal se catch block ke through achieve kra rhe the! but now we can modify or can say optimize our code with using some classes and methods which come under the header file "stdexcept".
// So under the "stdexcept" there are multiple classes for exceptions! and all that classes inherits a base class which is a general class for all kinds of exception! and that is the class "exception", this is the base class for all the exception classes!
// Aisa samajh lo ki C++ me exceptional handling ko handle krne ke liye, ek "stdexcept" naam ki header file bani hui hai and uske andar different types of exceptions ko handle krne ke liye alag alag tarah ke exceptions jo hote hai unke naam pr classes bani hui hai! and vo sab classes inherit krti hai ek single class ko which is "exception" class! it is the standard base class to handle all type of exceptions! and other exceptions inherits it!
// other classes can inherit other classes too! but this runtime_error class inherits "exception" class!

// Now, the other classes to handle exceptions are :
// 1) runtime_error (derived from "exception" class)
// 2) overflow_error (derived from "runtime_error" class)
// 3) underflow_error (derived from "runtime_error" class)
// 4) logic_error (derived from "exception" class)
// 5) out_of_range (derived from "logic_error" class)
// 6) invalid_argument (derived from "logic_error" class)
// and more....

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
	// try block
	try {
		int numerator = 10;
		int denominator = 0;
		int res;

		// check if denominator is 0 then throw runtime error. Here runtime_error is a specialised class under the stdexcept header file
		if (denominator == 0) {
			throw runtime_error("Division by zero not allowed!"); // Here we have used the runtime_error class to determine this exception! kyunki technically this is the correct type of exception for dividing by zero! jiss type ka error hai uss type ka class hi handle krega!
            // jaise iss case me dividing by zero ek runtime error ki category me aata hai toh hum isme yhi class use krenge! koi aur class use krenge toh compile error dikhayega! kyunki it's not just about ki hum kya print kr rhe hai! kyunki "stdexcept" me jo code likha hua hai runtime_error ya kisi bhi aur class ka vo iss hisaab se hi likha hai ki ek particular tarah ke errors ko hi handle krne ke liye banaa hua hai! isliye using some other kind of exception class will cause compile error!
		}

		// calculate result if no exception occurs
		res = numerator / denominator;
		// printing result after division
		cout << "Result after division: " << res << endl;
	}
	// catch block to catch the thrown exception
	catch (const runtime_error& e) {
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

void processInput(int value) {
    if (value < 0) {
        throw invalid_argument("Negative value not allowed!");
    }
    else if (value > 100) {
        throw out_of_range("Value out of range!");
    }
    // Process the input value
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

// Now, as of now we have completed studying all the built-in exceptions! now, lets try some custom exceptios and lets how they are build and used!
// To make a custom exceptions, we need to create a class and make it inherit the "exception class" of the "stdexcept" header file! kyunki main class toh vhi hai and baaki toh usko inherit krke banti hai! so pehle hum yhi krenge!
// And then we will create a constructor which will initiate the error message whenever this classes name will be used!
// And then we need a .what() function, which will print the error message when the exception will occur!
// Custom exception handling!

// Before proceeding forward, lets first understand virtual functions and .what() function and how we override it!
// So the thing is, ki virtual functions are those functions, which are declared in a base class using the virtual keyword. This allows derived classes to override these functions, providing their own implementations. toh baat yhi ki virtual function base class me define hote hai and then hum unko override krte hai uss base class ke derived classes me!
// Means in this case .what() is virtual function jisko already base class me define kiya hua hai! and now usko hum uss base class ke inherited classes me override krte hai using this override kwyword!
// Now lets see, all these steps krte kaise hai...
#include<iostream>
#include<string>
#include<stdexcept>
using namespace std;

class MyException : public exception { // A MyException class is created which is inherited from the already built-in exception class in the stdexcept header file!
    private:
    string errorMessage; // message string to store the error message!
    
    public:
    MyException(const string& msg) : errorMessage(msg) {} // Constructor created and Initialized with error message
    const char* what() const noexcept override { // Here, "const" signifies that the method does not modify the state of the object it is called on. It promises not to modify any member variables of the class.
    // char* is a pointer which will be pointing at the string which is storing the error message!
    // what() is the function name using parenthesis! amd then the whole, "const char* what()" This declares a member function named what that returns a pointer to a const char. It is a standard method used in exception classes to retrieve an error message.
    // "const noexcept" these are additional specifiers! where "const" again ndicates that the method does not modify the object's state. and "noexcept" indicates that this function does not throw any exceptions itself.
    // "override" This keyword is used to explicitly indicate that this method overrides a virtual method from a base class (in this case, "exception" is that base class!).
        return errorMessage.c_str(); // Here, errorMessage is This is a member variable of type std::string that stores the error message. It is initialized in the constructor of the MyException class. and then "c_str()" it is a member function of the string class!
    } // Now what happens is, so dekho the thing is, here jo errorMessage vo ek string type ka data member hai is class ka! and dekha jaye toh vo ek object bhi hai string class ka! and uss hi same string class ka ek member function c_str() bhi hai! so what happens is formally is, It returns a pointer to a constant character array (C-string) that represents the contents of the string object. and This C-string is a standard C-style string, which is a sequence of characters ending with a null character ('\0').
    // So means, hum kya kr rhe hai ki hum ek string class kaa object (errorMessage) bnaa ke uske hi ek member function (c_str()) ko call kr rhe hai! and ye member function ek pointer return krta hai jo string ka internal character array ko point krta hai, jo ki null-terminated hota hai. Is pointer ko what() method return krta hai taaki jab exception catch ho, toh error message easily access ho sake.
    // And then finally hum what() method ko bhi call krte hai cout ki help se taaki jo isne return kiya hai vo print krde!
};

int main() {
    try {
        throw MyException("Something went wrong!");
    }
    catch (const MyException& e) {
        // Here, e.what() returns the C-string "Something went wrong!"
        cout << "Caught MyException : " << e.what() << endl; // Here, ye vaala catch match hoga kyunki humne try me jo exception throw kiya hai vo MyException type ka exception hai! toh jiss type ka exception hota hai uss hi type ka catch match hota hai!
    }
    catch (const std::exception& e) {
        cout << "Caught exception : " << e.what() << endl;
    }
}

// For now this is all from Exception handling!
// ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------->