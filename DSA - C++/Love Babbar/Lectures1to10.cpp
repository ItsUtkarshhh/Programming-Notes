// Data Structures and Algorithms
// Data Structures : They are way to arrange data in main memory for efficient usage and they are ingredients to make good algorithms. Example : Arrays, Stacks, Linked List, Queue, Binary Search Trees.
// Algorithms : Sequence of steps to solve a given problem. Eg : Sorting an Array
// Database : Collection of information in permanent storage for faster retrieval and updation.
// Data warehouse : Management of huge amount of legacy data for better analysis. Legacy data is that data which is stored for analysis purposes and now it has no use. like facebook stores some data like how many times you viewed one profile and how many times you commented a particular comment, these data are of no use but they are being stored to analyse and create algorithms, this is data warehouse.
// Big Data : Analysis of too large complex data which cannot be deal with traditional data processing application, like making a search engine will require you a lotttt of data that a normal or general processing computer can't even store.

// ---------------------------------------------------------- LECTURE 1 - Basics --------------------------------------------------------------------------------------------------------->
// To solve a problem we do the following steps like, understand the problem, look for the given values, analyse the approach to be taken to solve the problem and then start programming!
// But proper program likhne se pehle hum ek rough code/solution likhte hai jisko hum pseudo code kehte hai!
// Pehle hum solution sochte hai rough format me and then uske liye ek flowchart and pseudo code likhte hai and then hum proper program likhte hai code krke and then vo code machine level language me convert hota hai and then vo execute hota hai!

// Flowchart : A diagramatic representation of the program/approach is called a flowchart! isme hum kuch symbols ka use krke apne rough solution ko diagramatic form me represent krte hai!
// Pseudo Code : Generic way of representing a particular solution so that it can be coded in different languages!

// Flowchart Components and Pseudo Code Explanation!
// Flowchart Components : Oval Block : Represents the start or end of the program.
//                      : Parallelogram Block : Used for input/output operations.
//                      : Rectangle Block : Represents a process, such as calculations or variable assignments.
//                      : Diamond Block : Represents decision-making (used for if-else conditions).
//                      : Example : Flowchart for Summing Two Numbers, If you want to create a flowchart for adding two numbers, it would include the following steps...
//                                : Start the program -> Take input values for a and b -> Compute the sum: sum = a + b -> Display the result -> End the program

// Pseudo Code Explanation : Pseudo code is a structured way to represent an algorithm in a language-agnostic format, making it easy to translate into any programming language.
//                         : The pseudo code for summing two numbers is : Start -> Read a, b -> sum = a + b -> Print sum -> End
//                         : Why Use Pseudo Code? It provides a clear step-by-step logic before actual implementation. It ensures that the algorithm is understandable across different programming languages. It helps in debugging and improving logic before writing real code.

// C/C++ Notes Summary
// These notes comprehensively cover C and C++, making them complete for understanding the language. For additional practice, you can explore a variety of problems from platforms like LeetCode (LC), CodeStudio (CS), InterviewBit (IB), HackerRank (HR), HackerEarth (HE), GeeksforGeeks (GFG), and CodeChef (CC).
// Understanding the Compiler : A compiler translates code into machine language and helps detect errors. It identifies compile-time errors (syntax errors) and runtime errors (logical errors that occur during execution).
// Program Flow and Flowchart Representation : In C++, program execution starts with the int main() function. In a flowchart, the Start block corresponds to int main() in code.
// Understanding using namespace std; in C++, C++ contains multiple namespaces, which group functions and variables to prevent naming conflicts. using namespace std; means we are specifically using the standard (std) namespace, which includes predefined functionalities like cout. Without this, we would have to use std::cout instead of cout for printing output.

// How the cpp file converts to the executable file!
// Preprocessing -> Compilation -> Assembler -> Linker
// Preprocessor : Isme ye hota hai ki jo bhi pre processor directives hote hai, like file inclusion, macros expansion and all! ye sab hota hai like jo bhi hum likhte hai #include me vo saari directories and files include hoti hai file me! and saare macros expand hote hai like #define and all! and then iss step me humari ".cpp" file ".i" or ".ii" file me convert hoti hai!
// Compilation : Isme jo humari preprocessed file hai vo ".i" se ".s" me convert hoti hai! and jo humara C++ ka code hai vo assembly code me convert hota hai! also iss process me saare errors and all check hote hai!
// Assembler : Isme jo humari compiled file hoti hai ".s" vaali ye ".o" object file me convert hoti hai! means isme jo assembly code hai vo machine language code me convert hota hai! and the object file contains machine-level code, along with other information necessary for linking.
// Linker : Isme saari object files include hoti hai and then ek final ".exe" file banti hai, jo final executable file hoti hai!

#include <iostream>
using namespace std;

int main() {
    // Implicit Type Conversion (Type Casting)
    
    // Example 1 : Converting 'char' to 'int'
    int a = 'b'; // 'b' has an ASCII value of 98
    cout << a << endl; // Output : 98

    // Example 2 : Converting 'int' to 'char'
    char ch = 99; // 99 corresponds to 'c' in the ASCII table
    cout << ch << endl; // Output : c

    // Handling Large Values in 'char' Type
    char ch2 = 123456; 
    // Since 'char' can only store 1 byte (8 bits), only the least significant 8 bits of 123456 will be stored. If 123456 in binary is 0001 1110 0010 0000, then the last 8 bits (0100 0000) are stored. ASCII value of 64 is '@', so the output will be '@'.
    cout << ch2 << endl; // Output : @ (may vary based on system implementation)

    // Storing Negative Numbers Using Two’s Complement
    int num = -5; // Storing -5 in memory
    // Step 1 : Ignore the negative sign and take 5 in binary : 00000000 00000000 00000000 00000101 (5 in 4 bytes)
    // Step 2 : Take 1’s complement (invert all bits) : 11111111 11111111 11111111 11111010
    // Step 3 : Take 2’s complement (add 1 to 1’s complement) : 11111111 11111111 11111111 11111011 (Stored value in memory)
    // Finally : The leftmost bit (1) represents the sign (1 = negative, 0 = positive). This means the system recognizes it as -5.
    cout << num << endl; // Output : -5

    // Retrieving & Printing Negative Numbers
    // Step 1 : Read the stored value : 11111111 11111111 11111111 11111011
    // Step 2 : Take 1’s complement : 00000000 00000000 00000000 00000100
    // Step 3 : Take 2’s complement (add 1) : 00000000 00000000 00000000 00000101
    // The value obtained is 5, Since the leftmost bit of the original stored value was 1 (indicating negative), the final output is displayed as -5.

    // Note : Positive values are stored in memory exactly as their binary representation without any modifications.
    return 0;
}

// All the data types are : int, float, char, long, double, long double, long long!
// Other than all these data types, there are some ways of declaring data types, signed and unsigned! signed means all +ve and -ve values of that range! then unsigned is only for +ve values range! along with that there is "auto" which decides data type based on the operations jo hum perform kr rhe hote hai!

// "const" keyword Use Cases : The const keyword in C and C++ is used to declare constants - variables whose values cannot be changed after initialization!
// Use case 1 : const int MAX_VALUE = 100; This declares a constant MAX_VALUE with the value 100. Once initialized, its value cannot be modified.
// Use case 2 : void printMessage(const char* message) { printf("%s\n", message); } The const keyword can be used in function parameters to indicate that the function will not modify the value passed to it. This can help prevent accidental modifications and improve code clarity.
//            : Also another is "char* const var_name", it means its a constant pointer!
// Example :
#include <iostream>

void printMessage(const char* message) {
    // message = "New message"; // This will cause a compilation error
    printf("%s\n", message);
}

int main() {
    const char* msg = "Hello, World!";
    printMessage(msg); // Output: Hello, World!
    return 0;
}

// Use case 3 : const int* ptr; Pointer to Constant Data : Ye line ka matlab hai ki ptr ek pointer hai jo constant integer data ko point karta hai. Iska matlab hai ki ptr dvara point kiye gaye data ko modify nahi kiya ja sakta, lekin khud pointer ko dusre data ko point karne ke liye change kiya ja sakta hai.
//            : Also is pointer ka use krke value ko change nhi kiya jaa sakta! but value ko itself memory block se change kiya jaa sakta hai! bss ptr ko use krke nhi!
// Example :
#include <iostream>

int main() {
    int value = 42;
    const int* ptr = &value; // ptr is a pointer to constant integer data
    
    // *ptr = 100; // This will cause a compilation error because ptr points to constant data
    value = 100; // This is allowed since the value itself can be changed

    std::cout << "Value: " << *ptr << std::endl; // Output: Value: 100
    return 0;
}

// Use case 4 : int x = 10; int* const ptr = &x; Constant Pointer : This declares a constant pointer ptr that points to an integer. Once initialized, the pointer itself cannot be changed to point to another memory location, but the data it points to can be modified. means it is just opposite of pointer to constant data!
// Example :
#include <iostream>

int main() {
    int x = 10;
    int* const ptr = &x; // ptr is a constant pointer to an integer

    // ptr = &y; // This will cause a compilation error because ptr itself is constant
    *ptr = 20; // This is allowed since the data pointed to by ptr can be changed

    std::cout << "x: " << x << std::endl; // Output: x: 20
    return 0;
}

// Use case 5 : Constant Member Functions (C++) : In C++, the const keyword can be used to declare member functions as constant. These functions promise not to modify the state of the object they are called on. This is particularly useful in classes to ensure that certain member functions don't modify the object's state accidentally.
//            : In simple language : Okay so constant member functions means, once an object is created with some values of its data members, then the a member functions which is declared as constant, it cannot change the values of the data members of the object.
// Example :
#include <iostream>

class MyClass {
private:
    int value;
public:
    MyClass(int val) : value(val) {}

    void print() const {
        // value = 100; // This will cause a compilation error because print() is a constant member function and hence it cannot change the value of "value" variable becoz it is a data member of the class!
        printf("Value: %d\n", value);
    }
};

int main() {
    MyClass obj(42);
    obj.print(); // Output: Value: 42
    return 0;
}

// Use case 6 : Return Values : In C++, you can declare a function's return value as const. This indicates that the return value should not be modified by the caller.
// Example :
#include <iostream>

const int getValue() {
    return 42;
}

int main() {
    const int val = getValue();
    // val = 100; // This will cause a compilation error because val is declared as const
    std::cout << "Value: " << val << std::endl; // Output: Value: 42
    return 0;
}

// ---------------------------------------------------------- LECTURE 2 - Basics --------------------------------------------------------------------------------------------------------->
#include <iostream>
using namespace std;

int main() {
    // In C++, we have two variations of integer data types : signed and unsigned.
    // Signed integers can store both negative and positive values within the range: -(2^31) to (2^31 - 1).
    // Unsigned integers can only store positive values, ranging from 0 to (2^32 - 1).
    
    unsigned int a = -123; // Assigning a negative value to an unsigned int
    cout << a << endl;
    return 0;

    // Explanation : Normally, negative values are stored in memory using 2's complement representation.
    //             : However, when a negative value is assigned to an unsigned integer, the compiler does not treat it as negative.
    //             : Instead, it interprets the stored binary value as a large positive number.
    
    // Breakdown : -123 in binary (assuming a 32-bit system) : Step 1 : Ignore the negative sign and convert 123 to binary -> 00000000 00000000 00000000 01111011 (Binary of 123)
    //                                                       : Step 2 : Take 1's complement (invert bits) -> 11111111 11111111 11111111 10000100
    //                                                       : Step 3 : Take 2's complement (add 1) -> 11111111 11111111 11111111 10000101 (This is how -123 is stored in memory)
    // Hence, When we print an unsigned integer, the leftmost bit is NOT treated as a sign bit. The entire binary sequence is read as a positive number.
    // In this case, 11111111 11111111 11111111 10000101 is interpreted as: 2^32 - 123 = 4,294,967,173 (which is why we get this output).
    // Unsigned Equivalent = 2^32 - 123, in more general form : 2^32 - |X| where, X is an unsigned value passed! (This formula is not mathematically determined, its is just analysed that this happens!)
    // What actually happens is : 1 * 2^31 + 1 * 2^30 + 1 * 2^29 + ... + 1 * 2^7 + 0 * 2^6 + 1 * 2^2 + 0 * 2^1 + 1 * 2^0 (For 11111111 11111111 11111111 10000101)

    // Summary :
    // - Negative numbers are always stored in memory using 2's complement representation.
    // - When using signed integers, the leftmost bit determines the sign (1 for negative, 0 for positive).
    // - When using unsigned integers, all bits contribute to the magnitude, ignoring the sign.
    // - This is why assigning a negative number to an unsigned int results in a large positive number.
}

// Some extra info : int/int = int, float/int = float, double/int = double

// A little overview on relational operartor!
#include<iostream>
using namespace std;

int main() {
    int a = 1;
    int b = 0;

    int first = a>b; // And similarly we can do with other relational operators!
    cout<<first<<endl;

    int second = a&&b; // And similarly we can do this with other logical operators!
    cout<<second<<endl;
}

// ---------------------------------------------------------- LECTURE 3 - Basics + Pattern Making --------------------------------------------------------------------------------------------------------->
// Conditional statements me agar hum else if use kr rhe hai, toh bina hum else ke bhi end kr sakte hai, it depends on our use, vrna sirf else if me end krne pr koi dikkat nhi hai!
// Pattern making :
// Practice Question 1 : Draw a pattern with 4 rows and 4 columns!
#include<iostream>
using namespace std;

int main() {
    int n; 
    cin>>n; // This is the input of ki kitni rows me * print krwaane hai, if its 5 means ki hum 5 rows me * print krwaana chahte hai!
    int i = 1;
    while(i<=n) { // toh humne loop chlaa diya 1st row se nth row tak
        int j = 1;
        while(j<=n) { // Now ab harr row me kitne * print krne hai vo j vaala loop decide krega!
            cout<<"*"<<" ";
            j++;
        }
        cout<<endl; // Once we will be done printing the * in one row, so now we will change the row and move on to the next row!
        i++;
    }
} // Understand the logic here, we used the outer loop to switch between rows and inner loop to print the * (switch between columns)!

// Practice Question 2 : Print 1 three times in 1st row, 2 three times in 2nd row, 3 three times in 3rd row!
// Using While Loop!
#include<iostream>
using namespace std;

int main() {
    int n;
    cin>>n;
    int i = 1;
    while(i<=n) {
        int j = 1;
        while(j<=n) {
            cout<<i;
            j++;
        }
        cout<<endl;
        i++;
    }
}

// Using For Loop
#include<iostream>
using namespace std;

int main() {
    int n;
    cin>>n;
    int i;
    for(i=1; i<=n; i++) {
        int j;
        for(j=1; j<=n; j++) {
            cout<<i;
        }
        cout<<endl;
    }
}

// Using Do While Loop!
#include<iostream>
using namespace std;

int main() {
    int n;
    cin>>n;
    int i = 1;
    do {
        int j = 1;
        do {
            cout<<i;
            j++;
        } while (j<=n);
        cout<<endl;
        i++;
    } while (i<=n);
}

// Basic Questions
// Question 1 : Write a Program to Display Fibonacci Series upto certain number n (n is entered by user) Example: n = 100, Output : Fibonacci Series: 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89
// This code is in C language!
#include <stdio.h>

void printFibonacciSeries(int n) {
    int a = 0, b = 1, next;
    if (n < 0) {
        printf("Please enter a non-negative number.\n");
        return;
    }
    printf("Fibonacci Series: ");
    if (n >= 0) {
        printf("%d", a);
    }
    if (n >= 1) {
        printf(", %d", b);
    }
    next = a + b;
    while (next <= n) {
        printf(", %d", next);
        a = b;
        b = next;
        next = a + b;
    }
    printf("\n");
    return;
}

int main() {
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);
    printFibonacciSeries(n);
    return 0;
}

// Question 2 : Find the GCD of 2 numbers input by the user!
// Method 1: Brute Force Method (Simple + Easy + Logical Approach) :
#include<iostream>
using namespace std;

int GCD(int a, int b) {
    int result = min(a,b);
    while(result > 0) {
        if(a % result == 0 && b % result == 0) {
            break; // Takes you out of the loop!
        }
        result--;
    }
    return result;
}

int main() {
    int a,b;
    cin>>a>>b;
    cout<<"GCD : "<<GCD(a,b);
}

// Method 2 calculating GCD :
#include<iostream>
using namespace std;

int GCD(int a, int b) {
    if(a == 0) {
        return b;
    }
    if(b == 0) {
        return a;
    }
    if(a == b) {
        return a;
    }
    if(a > b) {
        return GCD(a-b,b);
    }
    else {
        return GCD(a,b-a);
    }
}

int main() {
    int a,b;
    cin>>a>>b;
    int ans = GCD(a,b);
    cout<<"GCD : "<<ans;
}

// Method 3 for calculating GCD (In C Language) :
// Here we are using the long-division method in coding form!
#include<stdio.h>

int GCD(int a, int b) {
    while(b != 0) {
        int temp = b;
        b = a%b;
        a = temp;
    }
    return a;
}

int main() {
    int a,b;
    scanf("%d%d",&a,&b);
    printf("%d",GCD(a,b));
}

// Question 3 : Find LCM of 2 numbers entered by the user!
// Code is in C language!
// Approach : We can find LCM with the formula, LCM(a,b) * GCD(a,b) = a*b
#include<stdio.h>

int GCD(int a, int b) {
    while(b!=0) {
        int temp = b;
        b = a%b;
        a = temp;
    }
    return a;
} // The logic behind this approach is this mathematical equivalent "gcd(a, b) = gcd(b, a mod b)."

int main() {
    int a,b;
    scanf("%d%d",&a,&b);
    printf("LCM of the 2 numbers is : %d",(a*b)/(GCD(a,b)));
}

// Solving the above question without finding GCD!
#include <stdio.h>

int findLCM(int a, int b) {
    int max = (a > b) ? a : b;
    while (1) {
        if (max % a == 0 && max % b == 0) {
            return max;
        }
        max++;
    }
}

int main() {
    int num1 = 4;
    int num2 = 6;

    int lcm = findLCM(num1, num2);
    printf("LCM of %d and %d is %d\n", num1, num2, lcm);
    return 0;
}
// Traditional method to calculate HCF/GCD is hum dono numbers ke factors nikalte hai! and then unme se jo jo common hote hai unko apas me product krke jo value hoti hai vo final HCF/GCD hota hai!
// Traditional method for calculating LCM is hum dono numbers ko again factorize krte hai! and then unme se jo jo maximum powers hai saare numbers ki unko apas me product krke final LCM nikal lete hai! 

// ---------------------------------------------------------- LECTURE 4 - Pattern Making --------------------------------------------------------------------------------------------------------->
// Here we will be solving only questions related to patterns!
// Practice Queston 3 : Create a pattern like there are 4 rows and 1st column contains only 1, 2nd column contains only 2, 3rd column contains only 3, 4th column contains only 4!
// Using only While loop, we can try it into for and do while loop!
#include<iostream>
using namespace std;

int main() {
    int n;
    cin>>n;
    int i = 1;
    while (i<=n) {
        int j = 1;
        while (j<=n) {
            cout<<j;
            j++;
        }
        cout<<endl;
        i++;
    }
}

// Practice Question 4 : Create a pattern where it has three rows and 1 2 3 in first row, 4 5 6 in 2nd row and 7 8 9 in 3rd row!
#include<iostream>
using namespace std;

int main() {
    int n;
    cin>>n;
    int i = 1;
    int count = 1;
    while (i<=n) {
        int j = 1;
        while(j<=n) {
            cout<<count;
            count++;
            j++;
        }
        cout<<endl;
        i++;
    }
}

// Practice Question 5 : Print the star pattern, where 1st row has 1 star, 2nd row has 2 stars and so on..
#include<iostream>
using namespace std;

int main() {
    int n;
    cin>>n;
    int i = 1;
    while(i<=n) {
        int j = 1;
        while(j<=i) {
            cout<<"*";
            j++;
        }
        cout<<endl;
        i++;
    }
}

// Practice Question 6 : Print 1 one time in 1st row, 2 two times in 2nd row and so on....
#include<iostream>
using namespace std;

int main() {
    int n;
    cin>>n;
    int i = 1;
    while(i<=n) {
        int j = 1;
        while(j<=i) {
            cout<<i;
            j++;
        }
        cout<<endl;
        i++;
    }
}

// Practice Question 7 : Print 1 in 1st row, 2 3 in 2nd, 4 5 6 in 3rd and so on...
#include<iostream>
using namespace std;

int main() {
    int n;
    cin>>n;
    int i = 1;
    int count = 1;
    while (i<=n) {
        int j = 1;
        while(j<=i) {
            cout<<count;
            count++;
            j++;
        }
        cout<<endl;
        i++;
    }
}

// Practice Question 8 : 1 in 1st row, 2 3 in 2nd row, 3 4 5 in 3rd row, 4 5 6 7 in 4th row and so on...
#include<iostream>
using namespace std;

int main() {
    int n;
    cin>>n;
    int i = 1;
    while(i<=n) {
        int j = 1;
        int count = i;
        while(j<=i) {
            cout<<count;
            count++;
            j++;
        }
        cout<<endl;
        i++;
    }
}

// Without count
#include<iostream>
using namespace std;

int main() {
    int n;
    cin>>n;
    int i = 1;
    while(i<=n) {
        int j = i;
        while(j<2*i) {
            cout<<j;
            j++;
        }
        cout<<endl;
        i++;
    }
}

// Another approach for without count...
#include<iostream>
using namespace std;

int main() {
    int n;
    cin>>n;
    int row =  1;
    while(row<=n) {
        int col = 1;
        while(col<=row) {
            cout<<row+col-1<<" ";
            col++;
        }
        cout<<endl;
        row++;
    }
}

// Another simplest and best approach :
#include<iostream>
using namespace std;

int main() {
    int n;
    cin>>n;
    for(int row = 1; row<=n; row++) {
        for(int col = 0; col<row; col++) {
            cout<<row+col<<" ";
        }
        cout<<endl;
    }
}

// Practice Question 9 : Print 1 in 1st row, 2 1 in 2nd row, 3 2 1 in 3rd row and so on...
#include<iostream>
using namespace std;

int main() {
    int n;
    cin>>n;
    int i = 1;
    while(i<=n) {
        int count = i;
        int j = 1;
        while(j<=i) {
            cout<<count;
            count--;
            j++;
        }
        cout<<endl;
        i++;
    }
}

// Solving the above question without using an extra variable count!
#include<iostream>
using namespace std;

int main() {
    int n;
    cin>>n;
    int i = 1;
    while(i<=n) {
        int j = 0;
        while(j<i) {
            cout<<i-j<<" ";
            j++;
        }
        cout<<endl;
        i++;
    }
}

// Another simplest and best approach :
#include<iostream>
using namespace std;

int main() {
    int n;
    cin>>n;
    for(int row = 1; row<=n; row++) {
        for(int col = row; col>0; col--) {
            cout<<col<<" ";
        }
        cout<<endl;
    }
}

// Practice Question 10 : Print ABCDE in each row as input by the user.
#include<iostream>
using namespace std;

int main() {
    int n;
    cin>>n;
    int i = 1;
    while(i<=n) {
        char j = 1; // But it would be better if we write "int j = 1"! as that is more intuitive and correct semantically too! otherwise it will cause only unnecessary confusion!
        char val = 'A';
        while(j<=n) {
            cout<<val;
            val++;
            j++;
        }
        cout<<endl;
        i++;
    }
}

// Another simplest and best approach :
#include<iostream>
using namespace std;

int main() {
    int n;
    cin>>n;
    for(int i = 1; i<=n; i++) {
        for(int j = 0; j<n; j++) {
            cout<<char('A'+j)<<" ";
        }
        cout<<endl;
    }
}

// Practice Question 11 : Print A three times in 1st row, B three times in 2nd row, C three times in 3rd row and so on...
// My Solution :
#include<iostream>
using namespace std;

int main() {
    int n;
    cin>>n;
    int i = 1;
    char val = 'A';
    while(i<=n) {
        int j = 1;
        while(j<=n) {
            cout<<val;
            j++;
        }
        cout<<endl;
        val++;
        i++;
    }
}

// Love Babbar Solution :
#include<iostream>
using namespace std;

int main() {
    int n;
    cin>>n;
    int i = 1;
    while(i<=n) {
        int j = 1;
        while(j<=n) {
            char ch = 'A'+i-1;
            cout<<ch;
            j++;
        }
        cout<<endl;
        i++;
    }
}

// Another simplest and best approach :
#include<iostream>
using namespace std;

int main() {
    int n;
    cin>>n;
    for(int i = 0; i<n; i++) {
        for(int j = 0; j<n; j++) {
            cout<<char('A'+i)<<" ";
        }
        cout<<endl;
    }
}

// Practice Question 13 : Print A B C in every row as input by the user!
#include<iostream>
using namespace std;

int main() {
    int n;
    cin>>n;
    int i = 1;
    while(i<=n) {
        int j = 1;
        char val = 'A';
        while(j<=n) {
            cout<<val;
            val++;
            j++;
        }
        cout<<endl;
        i++;
    }
}

// Another Approach :
#include<iostream>
using namespace std;

int main() {
    int n;
    cin>>n;
    int row = 1;
    while(row<=n) {
        int col = 1;
        while(col<=n) {
            char ch = 'A'+ col - 1;
            cout<<ch<<" ";
            col++;
        }
        cout<<endl;
        row++;
    }
}

// Another simplest and best approach :
#include<iostream>
using namespace std;

int main() {
    int n;
    cin>>n;
    for(int i = 0; i<n; i++) {
        for(int j = 0; j<n; j++) {
            cout<<char('A'+j)<<" ";
        }
        cout<<endl;
    }
}

// Practice Question 14 : Print A B C and then D E F in the next line and so on...
#include<iostream>
using namespace std;

int main() {
    int n;
    cin>>n;
    int i = 1;
    char val = 'A';
    while(i<=n) {
        int j = 1;
        while(j<=n) {
            cout<<val;
            j++;
            val++;
        }
        cout<<endl;
        i++;
    }
}

// Without using count - It is not very easily intuitive, so not recommended for begineers! but good for competitive programming!
#include<iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << (n * (i - 1) + j) << " "; // To interpret this logic its tough initially! but as you build your problem solving ability it will become more and more intuitive!
        }
        cout << endl;
    }
    return 0;
}

// Practice Question 15 : Print A B C, B C D in next row, C D E in next row and so on...
// My Solution #1 :
#include<iostream>
using namespace std;

int main() {
    int n;
    cin>>n;
    int i = 1;
    char val = 'A';
    while(i<=n) {
        int j = 1;
        while(j<=n) {
            cout<<val;
            val++;
            j++;
        }
        val--;
        val--;
        cout<<endl;
        i++;
    }
}

// My Solution #2 :
#include<iostream>
using namespace std;

int main() {
    int n;
    cin>>n;
    int i = 0;
    while(i<n) {
        char val = 'A'+i;
        int j = 1;
        while(j<=n) {
            cout<<val;
            val++;
            j++;
        }
        cout<<endl;
        i++;
    }
}

// Love Babbar Solution :
#include<iostream>
using namespace std;

int main() {
    int n;
    cin>>n;
    int i = 1;
    while(i<=n) {
        int j = 1;
        while(j<=n) {
            char ch = 'A'+i+j-2;
            cout<<ch;
            j++;
        }
        cout<<endl;
        i++;
    }
}

// My Solution #3 : More easy to understand
#include<iostream>
using namespace std;

int main() {
    int n;
    cin>>n;
    int row = 1;
    while(row<=n) {
        char ch = 'A'+(row-1);
        int col = 1;
        while(col<=n) {
            cout<<ch<<" ";
            ch++;
            col++;
        }
        cout<<endl;
        row++;
    }
}

// Another simplest and best approach :
#include<iostream>
using namespace std;

int main() {
    int n;
    cin>>n;
    for(int i = 0; i<n; i++) {
        for(int j = 0; j<n; j++) {
            cout<<char('A'+i+j)<<" ";
        }
        cout<<endl;
    }
}

// Practice Question 16 : Print A, B B then C C C and so on...
// My Solution :
#include<iostream>
using namespace std;

int main() {
    int n;
    cin>>n;
    int i = 1;
    char val = 'A';
    while(i<=n) {
        int j = 1;
        while(j<=i) {
            cout<<val;
            j++;
        }
        val++;
        cout<<endl;
        i++;
    }
}

// Love Babbar Solution :
#include<iostream>
using namespace std;

int main() {
    int n;
    cin>>n;
    int i = 1;
    while(i<=n) {
        int j = 1;
        while(j<=i) {
            char val = 'A'+i-1;
            cout<<val;
            j++;
        }
        cout<<endl;
        i++;
    }
}

// Another simplest and best approach :
#include<iostream>
using namespace std;

int main() {
    int n;
    cin>>n;
    for(int i = 0; i<n; i++) {
        for(int j = 0; j<=i; j++) {
            cout<<char('A'+i)<<" ";
        }
        cout<<endl;
    }
}

// Practice Question 17 : Print A, B C, D E F, G H I J and so on....
// My Solution :
#include<iostream>
using namespace std;

int main() {
    int n;
    cin>>n;
    int i = 1;
    char val = 'A';
    while(i<=n) {
        int j = 1;
        while(j<=i) {
            cout<<val;
            val++;
            j++;
        }
        cout<<endl;
        i++;
    }
}

// Without extra space : By ChatGPT, These approach will take time to sink in! Its fine... keep practicing!
#include<iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            cout << char('A' + (i * (i - 1)) / 2 + j - 1) << " "; 
        }
        cout << endl;
    }
    return 0;
}

// Practice Question 18 : Print A, B C, C D E, D E F G and so on...
// Love babbar solution :
#include<iostream>
using namespace std;

int main() {
    int n;
    cin>>n;
    int i = 1;
    while(i<=n) {
        int j = 1;
        char val = 'A'+i+j-2;
        while(j<=i) {
            cout<<val;
            val++;
            j++;
        }
        cout<<endl;
        i++;
    }
}
// To observe the pattern you need to make a matrix and then find that formula, like here it is A + i + j - 2, isko nikalne ke liye make a matrix and then find the pattern!

// Another simplest and best approach :
#include<iostream>
using namespace std;

int main() {
    int n;
    cin>>n;
    for(int i = 0; i<n; i++) {
        for(int j = 0; j<=i; j++) {
            cout<<char('A'+i+j)<<" ";
        }
        cout<<endl;
    }
}

// Practice Question 19 : Print a pattern like D, C D, B C D, A B C D and so on...
#include<iostream>
using namespace std;

int main() {
    int n;
    cin>>n;
    int i = 1;
    while(i<=n) {
        int j = 1;
        char val = 'A'+n-i+j-1; // char val = 'A'+n-i+j-1; isme j-1 krne ka koi logic nhi hai, isko hataa bhi doge and sirf n-row likhoge toh bhi same answer ayega kyunki inner loop exit hone ke baad col/j toh firse 1 hi ho jaa rha hai iske kaaran baar baar j-1 krne pr 0 hi ho jaa rha hai! and hence just write it as 'A' + n - row; its enuf!
        while(j<=i) {
            cout<<val;
            val++;
            j++;
        }
        cout<<endl;
        i++;
    }
}

// Another approach :
#include<iostream>
using namespace std;

int main() {
    int n;
    cin>>n;
    for(int i = n; i>0; i--) {
        for(int j = 0; j<=(n-i); j++) {
            cout<<char('A'+i+j-1)<<" ";
        }
        cout<<endl;
    }
}

// Love Babbar Solution :
#include<iostream>
using namespace std;

int main() {
    int n;
    cin>>n;
    int i = 1;
    while(i<=n) {
        int j = 1;
        char val = 'A'+n-i;
        while(j<=i) {
            cout<<val;
            val++;
            j++;
        }
        cout<<endl;
        i++;
    }
}

// Practice Question 20 : Print this ___* in first row, __** in 2nd row, _***, in 3rd row and so on...
#include<iostream>
using namespace std;

int main() {
    int n;
    cin>>n;
    int i = 1;
    while(i<=n) {
        // Pehle Spaces print krlo
        int space = n-i;
        while(space) {
            cout<<" ";
            space--;
        }

        // Then stars print krlo
        int j = 1;
        while(j<=i) {
            cout<<"*";
            j++;
        }
        cout<<endl;
        i++;
    }
}

// Practice Question 21 : Print this **** in 1st row, ***_ in 2nd row, **__ in 3rd row and so on...
#include<iostream>
using namespace std;

int main() {
    int n;
    cin>>n;
    int i = 1;
    while(i<=n) {
        int j = 1;
        while(j<=n-i+1) { // You can see this as j <= n - (i-1);
            cout<<"*";
            j++;
        }
        cout<<endl;
        i++;
    }
}

// Another Approach :
#include<iostream>
using namespace std;

int main() {
    int n;
    cin>>n;
    int i = 1;
    while(i<=n) {
        int j = n-i;
        while(j>=0) {
            cout<<"*";
            j--;
        }
        cout<<endl;
        i++;
    }
}

// Another simplest and best approach :
#include<iostream>
using namespace std;

int main() {
    int n;
    cin>>n;
    for(int i = 0; i<n; i++) {
        for(int j = 1; j<=n-i; j++) {
            cout<<"*"<<" ";
        }
        cout<<endl;
    }
}

// Practice Question 22 : Print this ****, _***, __**, ___* and so on...
#include<iostream>
using namespace std;

int main() {
    int n;
    cin>>n;
    int i;
    for(i = 1; i <= n; i++) {
        int space;
        for(space=0; space<i-1; space++) {
            cout<<' ';
        }
        int stars;
        for(stars=0; stars<=n-i; stars++)
            cout<<'*';
        cout<<endl;
    }
}

// Another simplest and best approach :
#include<iostream>
using namespace std;

int main() {
    int n;
    cin>>n;
    for(int i = 0; i<n; i++) {
        int space = i;
        while(space) {
            cout<<" "<<" ";
            space--;
        }
        int j = n-i;
        while(j>0) {
            cout<<"*"<<" ";
            j--;
        }        
        cout<<endl;
    }
}

// ---------------------------------------------------------- LECTURE 5 - Bitwise Operators --------------------------------------------------------------------------------------------------------->
// Bitwise Operators in C++
// There are 4 main bitwise operators: AND (&), OR (|), NOT (~), and XOR (^). These work at the binary level.
// AND (&) : Performs bitwise AND. Example : 2 & 3 → (10 & 11) = 10 (Decimal: 2)
// OR (|) : Performs bitwise OR. Example : 2 | 3 → (10 | 11) = 11 (Decimal: 3)
// NOT (~) : Inverts all bits (One’s Complement). Example : ~2 → 00000000 00000000 00000000 00000010 (binary representation), After NOT: 11111111 11111111 11111111 11111101, Converting to decimal (Two’s Complement) gives -3
// XOR (^) : Bits that are the same become 0, different bits become 1. Example : 2 ^ 3 → (10 ^ 11) = 01 (Decimal: 1)

// Bitwise Shift Operators : Left Shift (<<) and Right Shift (>>)
// Left Shift (<<) : Moves bits to the left by a given number of positions. Example: 3 << 2, 3 (00000000 00000000 00000000 00000011) → Left shift by 2 → 12 (00000000 00000000 00000000 00001100)
//                 : Generally, left shift is equivalent to multiplying by powers of 2 (3 × 2 × 2 = 12).
// Right Shift (>>) : Moves bits to the right by a given number of positions, effectively dividing by powers of 2.
// Important Note : For small numbers, left shift ≈ multiplication by 2, and right shift ≈ division by 2.
//                : For large numbers, left shift may turn positive numbers into negative due to the most significant bit becoming 1.
//                : Left shift pads with 0s on the right (for positive numbers) and For negative numbers, padding behavior depends on the compiler.


// Now lets program it! :
#include<iostream>
using namespace std;

int main() {
    // Bitwise Operators!
    cout<<(2&3)<<endl;
    cout<<(2|3)<<endl;
    cout<<(~2)<<endl;
    cout<<(2^3)<<endl;

    // Left-Shift and Right_Shift!
    cout<<(3<<2)<<endl;
    cout<<(2>>2)<<endl;
    cout<<(5<<1)<<endl;
    cout<<(5>>1)<<endl;
}

// Control Statements in Loops :
// Break Statement : Immediately exits the nearest enclosing loop when encountered.
// Continue Statement : Skips the current iteration and moves to the next iteration of the loop.
// Exit Statement : Terminates the entire program immediately and returns control to the operating system.

// Loop Structures :
// For Loop : A for loop consists of three parts: initialization, condition, and update. Multiple expressions can be included in each section using commas.
// While Loop : Executes a block of code repeatedly as long as the condition remains true. Condition is checked before each iteration, meaning the loop might not run at all if the condition is false initially.
// Do-While Loop : Similar to the while loop but guarantees at least one execution of the loop body because the condition is checked after execution.

// Implementations!
#include<iostream>
using namespace std;

int main() {
    {
        cout << "Answer of first block : ";
        int a, b = 1;
        a = 10;
        if (++a) {
            cout << b;
        } else {
            cout << ++b;
        }
    }
    cout << endl << endl;
    {
        cout << "Answer of second block : ";
        int a = 1;
        int b = 2;
        if (a-- > 0 && ++b > 2) {
            cout << "Stage 1 - Inside If ";
        } else {
            cout << "Stage 2 - Inside Else ";
        }
        cout << a << " " << b;
    }
    cout << endl << endl;
    {
        cout << "Answer of third block : ";
        int a = 1;
        int b = 2;
        if (a-- > 0 || ++b > 2) {
            cout << "Stage 1 - Inside If ";
        } else {
            cout << "Stage 2 - Inside Else ";
        }
        cout << a << " " << b;
    }
    cout << endl << endl;
    {
        cout << "Answer of fourth block : ";
        int a = 1;
        int b = 2;
        if (a-- > 0 || ++b > 2) {
            cout << "Stage 1 - Inside If ";
        } else {
            cout << "Stage 2 - Inside Else ";
        }
        cout << a << " " << b;
    }
    cout << endl << endl;
    {
        cout << "Answer of fifth block : ";
        int number = 3;
        cout << 25 * (++number);
    }
    cout << endl << endl;
    {
        cout << "Answer of sixth block : ";
        int a = 1;
        int b = a++;
        int c = ++a;
        cout << a << " " << b << " " << c;
    }
    cout << endl << endl;
    {
        cout << "Answer of seventh block : ";
        for (int i = 0; i <= 5; i++) {
            cout << i << " ";
        }
    }
    cout << endl << endl;
    {
        cout << "Answer of eighth block : ";
        for (int i = 0; i <= 5; i++) {
            cout << i << " ";
        }
    }
    cout << endl << endl;
    {
        cout << "Answer of ninth block : ";
        for (int i = 0; i <= 15; i += 2) {
            cout << i << " ";
            if (i & 1) {
                continue;
            }
        }
    }
    cout << endl << endl;
    {
        cout << "Answer of tenth block : ";
        for (int i = 0; i < 5; i++) {
            for (int j = i; j <= 5; j++) {
                cout << i << " " << j << endl;
            }
        }
    }
    cout << endl << endl;
    {
        cout << "Answer of eleventh block : ";
        for (int i = 0; i < 5; i++) {
            for (int j = i; j <= 5; j++) {
                if (i + j == 10) {
                    break;
                }
                cout << i << " " << j << endl;
            }
        }
    }
    return 0;
}
// Now as of this course of Love Babbar DSA, now its time for watching out operators precedence, but that is not very important, we can always go and check to get to know that, but kuch yaad rehna chahiye, so they are...
// Priority order : 1) ! 2) *, /, % 3) +, - 4) <, <=, >=, > 5) ==, != 6) && 7) ||
// Modulus operator does not support float values!

// Leetcode Question 1 : Subtract the product and sum of all the digits of an Integer!
// Approach : Start with the input number -> Use modulo 10 to extract the last digit of the number (one's place) and update both sum and product -> Divide the number by 10 to remove the last digit -> Repeat the process until the number becomes 0 -> Finally, subtract the sum from the product to get the result.
// For example, for the number 234 : Extract digits: 4, 3, 2 -> Calculate sum and product: Sum = 4 + 3 + 2, Product = 4 * 3 * 2 -> Subtract product and sum to get the final answer.
#include<iostream>
using namespace std;

int main() {
    int n;
    cin>>n;
    int rem;
    int product = 1;
    int sum = 0;
    for(; n!=0;) {
        rem = n%10;
        product = product * rem;
        sum = sum + rem;
        n = n/10;
    }
    int answer = product - sum;
    cout<<answer;
}

// Another way of writing the above syntax!
#include<iostream>
using namespace std;

int main() {
    int n;
    // cin>>n;
    int rem;
    int product = 1;
    int sum = 0;
    for(cin>>n; n!=0; n/=10) {
        rem = n%10;
        product = product * rem;
        sum = sum + rem;
    }
    int answer = product - sum;
    cout<<answer;
}

// Using functions we can also do this... but we will study functions later... but still for reference...
#include<iostream>
using namespace std;

int sum(int a) {
    int ans = 0;
    while(a>0) {
        int digit = a%10;
        ans += digit;
        a /= 10;
    }
    return ans;
}

int prod(int a) {
    int ans = 1;
    while(a>0) {
        int digit = a%10;
        ans *= digit;
        a /= 10;
    }
    return ans;
}

int main() {
    int n;
    cin>>n;
    int sub = prod(n) - sum(n);
    cout<<sub;
}

// Leetcode Question 2 : Number of 1 Bits, find the number of 1 bits in the unsigned integer input by the user!
// Approach 1 : Decimal to Binary Approach : Convert the number to binary, iterate through each bit, and count how many times '1' appears.
// Approach 2 : Right Shift Approach : Continuously right shift the number and check the least significant bit (LSB) to count how many times '1' appears.
#include<iostream>
using namespace std;

int main() {
    uint32_t n;
    int count = 0;
    for(cin>>n; n!=0; n=n>>1) { // Alternativaly can write, "n>>=1" as a shortcut! 
        if(n&1) {
            count++;
        }
    }
    cout<<count;
} // Note : Using a while loop is a more natural and intuitive approach for this case. While a for loop works fine and it can loop cool, but a while loop aligns better with the logic of continuously checking and modifying n.

// ---------------------------------------------------------- LECTURE 6 - Decimal to Binary & Binary to Decimal --------------------------------------------------------------------------------------------------------->
// Decimal to Binary Conversion :
// 1st Approach : Divide the decimal number by 2, store the remainder, and repeat until the number becomes 0. Then reverse the remainders to get the binary representation.
// Use Case : When you want to convert positive integers into binary.
// For example : To convert 10 to binary, Divide 10 by 2 : Remainder : 0 & Quotient : 5 -> Divide 5 by 2 : Remainder : 1 & Quotient : 2 -> Divide 2 by 2 : Remainder : 0 & Quotient : 1 -> Divide 1 by 2 : Remainder : 1 & Quotient : 0
//             : Stop when the quotient becomes 0
//             : Now, write the remainders in reverse order : 1010, Thats the binary representation of 10

// 2nd Approach : Kisi number ko 1 ke saath bitwise AND karne se : If result is 1 then ODD number & if result is 0 then EVEN number.
//              : From here we can say that, we using bitwise AND operator, we can find the rightmost bit of a number!
//              : Now to check all bits, just keep doing the bitwise AND of that number, and keep doing the right-shift! to check all the bits of that number! and when the number becomes 0, then stop!
// Use Cases : Checking if a Number is Odd or Even
//           : Extracting the Rightmost Bit of a Number
//           : Binary Representation of a Number
//           : Bit Counting (Hamming Weight)
//           : Reversing the Bits
//           : Optimized Looping for Bitwise Tasks (Avoiding unnecessary checks by directly iterating over the bits of the number.)
//           : Power of Two Check (A number is a power of two if it has exactly one 1 in its binary representation.)
// Example : Start with ans = 0, which will store the final binary number. Use a variable digit to store the bits obtained through bitwise operations.
//         : Using bitwise operations, extract each bit of the given number (as explained earlier using n&1 and right-shift n = n>>1).
//         : To form the binary number from individual bits, use the formula : ans = (10^i * digits) + ans.

// Note : There is another formula, which is : (ans = ans * 10) + digit... Use case discussed below...
//      : (ans = ans * 10) + digit : It will be used when, you want ki jiss order me digits retrieve hue hai uss hi order me combine krke output aaye! Example : If you got digits 1 2 3, then applying this formula will combine the number in the order they are retreived! means output will be 123.
//      : ans = (10^i * digits) + ans : It will be used when, you want ki jiss order me digits retrieve hue hai uske reverse order me combine krke output aaye! Example : If you got digits 1 2 3, then applying this formula will combine the number in the reverse of the order in which they are retreived! means output will be 321.

// Implementations :
// First Approach :
#include<iostream>
#include<math.h>
using namespace std;

int main() {
    int n;
    cin>>n;
    int i = 0;
    int ans = 0;
    while(n!=0) {
        int rem = n%2;
        ans = (ceil(pow(10,i)) * rem) + ans; // Here we have to use the ceil function, becoz pow function gives double value! and so isliye hume isko inlcude krna padega! vrna sahi answer nhi ayega!
        i++;
        n = n/2;
    }
    cout<<ans;
}

// Second Approach :
#include<iostream>
#include<math.h>
using namespace std;

int main() {
    int n;
    cin>>n;
    int ans = 0;
    int i = 0;
    while(n!=0) {
        int digit = n&1;
        ans = (ceil(pow(10,i)) * digit) + ans; // Here again we have to use the ceil function for the previous reasons!
        n = n>>1;
        i++;
    }
    cout<<ans;
}

// This method can convert both +ve/-ve number into binary!
#include <iostream>
using namespace std;

// Function to convert a decimal number to binary and print it, printing whole 32 bits!
void printBinary(int n) {
    for (int i = sizeof(n) * 8 - 1; i >= 0; i--) {
        cout << ((n >> i) & 1);
    }
    cout << endl;
}

int main() {
    int n;
    cout << "Enter an integer: ";
    cin >> n;
    printBinary(n);
    return 0;
}
// Use this approach, when you just want to take a look at that how a number (+ve/-ve) is stored in the memory! +ve numbers get stored in memory as it is after converting in binary, -ve numbers goes through 1s and 2s complement and then get to store in memory! so this method just simply print what is stored in memory as it is!
// So what are the above 2 approaches, they also convert decimal to binary! but they convert only bits which we want for other operations! this method is just when you need to see all 32 bits! but the above method will not show you all 32 bits coz as soon as number == 0 they will terminate! But both approaches are correct for conversion!
// Both are correct approaches! but for negative this is the one! kyunki upar vaale approaches -ve decimals ko convert nhi kr rhe hai binary me!

// Binary to Decimal Conversion :
// Approach : To convert binary to decimal, we use the fact that each bit in the binary number represents a power of 2, starting from 2^0 for the rightmost bit. Start from the rightmost bit (least significant bit). If the bit is 1, add 2^n (where n is the position of the bit) to the total sum. Move to the next bit and repeat until you've processed all the bits.
#include<iostream>
#include<math.h>
using namespace std;

int main() {
    int n;
    cin>>n;
    int i = 0;
    int ans = 0;
    while(n!=0) {
        int digit = n%10;
        if(digit == 1) {
            ans = ans + ceil(pow(2,i));
        }
        i++;
        n = n/10;
    }
    cout<<ans;
}
// Note : But here we need to keep somethings in mind and they are, jab input le rhe hai tab hum, like for example, agar kisine 101 input diya toh vo actually hum ek decimal 101 number input de rhe hai naa ki binary number, toh agar binary se decimal convert krna hai toh hume binary number hi input dena hoga!
//      : Toh vo kaise hoga? Toh what we have done above is we have divided the input number with 10 and then we have used the remainder taaki fir hum bit by bit krke binary se decimal me convert krne ke liye code likh sake!
//      : Vaise agar jab hum thore aur concepts padh lenge tab hum strings ko use krke binary se decimal convert kr sakte hai! taaki jo number hum input kr rhe hai vo bit by bit krke string ke harr ek entry me store hojaye! and that's how thing will proceed!

// ---------------------------------------------------------- LECTURE 7 - Leetcode Questions --------------------------------------------------------------------------------------------------------->
// Practice Question 1 : Reverse an Integer! but if it goes out of the range of int them print 0!
#include<iostream>
#include<math.h>
#include<climits>
using namespace std;

int main() {
    int n;
    cin>>n;
    int i = 0;
    int ans = 0;
    while(n!=0) {
        int digit = n%10;
        if((ans*10 > INT_MAX || ans*10 < INT_MIN)) {
            cout<<0;
        }
        ans = (ans * 10) + digit;
        n /= 10;
        i++;
    }
    cout<<ans;
}

// Practice Question 2 : Complement of an Integer!
// Approach : You are given a decimal number, example : 5
//          : Find the 32-bit Negation : Convert the number to a 32-bit binary representation. For 5, it's 00000000 00000000 00000000 00000101.
//                                     : Apply the negation (~) to flip all bits (0 becomes 1 and 1 becomes 0). For 5, the negation (~5) is 11111111 11111111 11111111 11111010.
//          : Create a mask : To create the mask, we need to determine the number of bits that are 1 in the result.
//                          : Right shift the number repeatedly until it becomes 0. This will help us identify the number of relevant bits (i.e., how many bits were 1 in the original number).
//                          : For 5 (which is 00000000 00000000 00000000 00000101), after 3 right shifts, it becomes 0, and we know that there are 3 bits involved.
//                          : Build the mask by left shifting 1 a number of times equal to the number of bits (3 in this case). Then, OR (|) the result with 1 to set the bits to 1. After 3 left shifts, the mask will be 00000000 00000000 00000000 00000111.
//          : Apply the mask : Now, apply the bitwise AND ( & ) operation between the negated number (~5) and the mask. The negated number (~5) is 11111111 11111111 11111111 11111010. The mask is 00000000 00000000 00000000 00000111. Perform ~5 & mask, which gives 00000000 00000000 00000000 00000010.
//          : Final Result : The result after applying the mask is 00000000 00000000 00000000 00000010, which is 2 in decimal.

// Implementations :
#include<iostream>
using namespace std;

int main() {
    int n;
    cin>>n;
    int num = n;
    int mask = 0;
    // Boundary condition! this is that one condition jo humne upar poore approach me discuss nhi ki hai kyunki isko alag se likhna hoga as an exceptional condition!
    if(n==0) {
        cout<<1;
    }
    while(num!=0) {
        mask = (mask << 1) | 1;
        num = num >> 1;
    }
    int ans = (~n) & (mask);
    cout<<ans<<endl;
}

// Practice Question 3 : Power of two, display yes if a number can be represented in form of power of 2, and if no then print no!
// Approach : Simple bss yhi ki harr 2 ki power ko jo int me possible hai usko check krke dekh liya input vaale number se and then uske according print krdiya Yes or No!
#include<iostream>
#include<math.h>
using namespace std;

int main() {
    int n;
    cin>>n;
    bool flag = false;
    for(int i = 0; i<31; i++) {
        int ans = pow(2,i);
        if(n == ans) {
            cout<<"Yes";
            flag = true;
        }
    }
    if(flag == false) {
        cout<<"No";
    }
}

// More efficient approach (Using previous use case of Decimal to Binary conversion) :
// Logic : Power of Two Check (A number is a power of two if it has exactly one 1 in its binary representation.)
#include<iostream>
using namespace std;

int main() {
    int n;
    cin>>n;
    int count = 0;
    while(n!=0) {
        if(n&1) {
            count++;
        }
        n = n>>1;
    }
    if(count == 1) {
        cout<<"Power of 2";
    }
    else {
        cout<<"Not a power of 2";
    }
}

// ---------------------------------------------------------- LECTURE 8 - Switch Case and Functions! --------------------------------------------------------------------------------------------------------->
// A demo example for switch case!
#include<iostream>
using namespace std;

int main() {
    int num = 1;
    switch (num) {
    case 1:
        cout<<"First case"<<endl;
        break;
    case 2:
        cout<<"Second case"<<endl;
        break;
    default:
        cout<<"Default case"<<endl;
        break;
    }
}

#include<iostream>
using namespace std;

int main() {
    int num = 1;
    switch (num) {
    case 1:
        cout<<"First case"<<endl;
        // break;
    case 2:
        cout<<"Second case"<<endl;
        break;
    default:
        cout<<"Default case"<<endl;
        break;
    }
}

#include<iostream>
using namespace std;

int main() {
    int num = 2;
    switch (num) {
    case 1:
        cout<<"First case"<<endl;
        break;
    case 2:
        cout<<"Second case"<<endl;
        // break;
    default:
        cout<<"Default case"<<endl;
        break;
    }
}
// In the first example, the switch-case works normally where each case ends with a break statement, exiting the switch once the condition is matched.
// In the second and third examples, if a break statement is omitted, the switch continues to the next case and executes its code until a break is encountered. Therefore, the break statement is essential to control the flow within a switch case.
// The default case is optional but should be used when none of the cases match. Additionally, nested loops and switch cases can be inter-converted.

// Suppose you have a infinite loop of while, and you have a switch statement inside it, so how will you exit both switch statement and while loop providing you can only use break statement onlyy inside of SWITCH statement...
#include<iostream>
#include<cstdlib>
using namespace std;

int main() {
    int num = 1;
    while(1) {
        switch (num) {
        case 1:
            cout<<"First case"<<endl;
            // break;
            exit(0);
        case 2:
            cout<<"Second case"<<endl;
            // break;
            exit(0);
        default:
            cout<<"Default case"<<endl;
            // break;
            exit(0);
        }
    }
}
// Using a break in the loop can cause an infinite loop where only the "First Case" is printed repeatedly.
// To exit such a loop and terminate the entire program, we use the exit() statement, which is defined in <cstdlib>. The exit() function terminates the program after performing some cleanup tasks.
// However, it's best to use exit() cautiously, as in complex programs, you might prefer using return or throwing exceptions to handle program termination more gracefully.

// The continue statement is used to skip the current iteration in loops, but it cannot be used within a switch statement. In a switch, the break statement already controls the flow by exiting the current case.
// Since continue is meant for loops, it doesn't apply to switch statements. To skip the rest of a case, you can use break.

// Functions :
// Lets just do one question to understand function!
// Print the nCr values of the number input by the user!
#include<iostream>
using namespace std;

// Function Definition
int fact(int num) {
    // Function Body
    int fact = 1;
    for(int i = 1; i <=num; i++) {
        fact *= i;
    }
    return fact;
}

int nCr(int n, int r) {
    return fact(n)/(fact(r)*fact(n-r));
}

int main() {
    int n, r;
    cin>>n>>r;
    cout<<"nCr value is "<<nCr(n,r)<<endl; // Function Call
}
// We used function and function calls!
// Function Call Stack : And the flow of function calls are, In int main() we called the function nCr(n,r) then in nCr(n,r) we called the function fact() then in fact() we returned the value of fact, then we returned another value, then we used that value in int main()!
// Return was a statement we were using to get out of the function!

// Some questions on this lecture!
#include<iostream>
using namespace std;

void update(int x) {
    x = x/2;
}

int update2(int x) {
    x -= 5;
    return x;
}

int update3(int x) {
    int ans = x*x;
    return ans;
}

int main() {
    {
        int a = 2;
        update(a);
        cout<<a<<endl; // Here there will be no updates!
    }
    {
        int a = 15;
        update2(a);
        cout<<a<<endl; // Here again there will be no updates!
    }
    {
        int a = 4;
        a = update3(a);
        cout<<a<<endl; // Here update will happen! as kyunki jo update kiya gya hai function me usko store krke return kiya gya! upar ke do cases me ek me toh kuch return nhi kiya gya and ek me return kiya gya but print local variable vaala hi a karaya gya! isliye dono cases me koi bhi updates nhi aaye! agar isme reference kiya hota tab values change hoti! tab return krne ki bhi zarurat nhi hoti kyunki uss case me original value me hi changes ho jaate hai! these things we will study further!
    }
}

// ---------------------------------------------------------- LECTURE 9 - Arrays --------------------------------------------------------------------------------------------------------->
// Arrays : Can store multiple values/data in a single variable, similar type of data, data stored at contigous memory location, and can be stored using indexes!
// Declaring Arrays : int dost[10]; -> Here we have created an array with the name dost which has 10 contigous memory locations and where the name dost is refering to the first element of the array or can say is pointing at the 0th index of the array!
// Also maan lo agar int dost[10]; ek array banaya, toh ye memory me kaise dikhega, it will like suppose the first element is at memory address 100, now the 2nd element (means 1st index) will be at 104 becoz its data type is int and int has 4 byte, so one memory location (which will contain 32 bits) will be able to store a value of the int range which we know already! so means, dost[10] ka mtlb ki aisi 10 memory locations alot hojayengi dost naam ke variable ko jahaa pr hum 10 different (or same) values of same data type (here it is int) daal sakte hai and harr ek memory location (which is of 4 bytes = 32 bits) will be able to store value of the int range, which is -2^31 -> 2^31-1.

// Initiallization of Arrays : int dost[5] = {1,2,3,4,5}; Isse memory me 5 block bane and unn sab blocks me harr ek index ke according value store hogyi!
//                           : int dost[5] = {0}; isse kya hua ki jitne memory blocks allocate hue iss array ko unn sab me 0 store hogya!
//                           : int dost[10]; isse kya hua ki 10 memory locations ke according memory allocate hui and sab jagah garbage value store hogyi! means agar array ko declared but un-initiallized rakhenge tab saare locations pr garbage value store hojayegi!
// So that's how memory allocations works, unlike this case : int dost[5] = {1}; isse sirf first index pr hi store hota hai 1 and baaki remaining 4 memory locations pr 0 value store hojaati hai!
// But agar hum chahte hai ki 0 ki tarah sirf int dost[5] = {1}; likhne se harr index pr 1 store hojaye, toh iske liye what we have to do? so answer is : this will be done by using vectors! and it is demonstrated below...
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int size = 5; // Replace 5 with the desired size of the array
    vector<int> array(size, 1);
    cout<<array[0]<<endl;
    cout<<array[1]<<endl;
    cout<<array[2]<<endl;
    cout<<array[3]<<endl;
    cout<<array[4]<<endl;

    // If you want to use a regular array in C++
    // int array[5];
    // std::fill(array, array + size, 1);

    // Another way of doing the above thing...
    int arr[5];
    fill(arr, arr + 5, 1);
    cout<<arr[0]<<endl;
    cout<<arr[1]<<endl;
    cout<<arr[2]<<endl;
    cout<<arr[3]<<endl;
    cout<<arr[4]<<endl;
    return 0;
}

// Implementation of Array!
#include<iostream>
using namespace std;

int main() {
    int arr[10] = {1,2,3,4,5};
    // One way to print all the values is to use the cout again n again, but that is not very feasible, so we will use the loop!
    for(int i = 0; i<10; i++) {
        cout<<arr[i]<<endl;
    }
    // Isse humari problem toh solve hogyi ki hume baar baar cout nhi likhna padega jab index ki values print karwayenge toh, but iske saath saath ek aur cheez hui ki like humari array toh 10 size ki thi, but humne enter toh sirf 5 hi values ki hai toh after doing this baaki saari remaining indexes pr 0 store ho jayega! This is becoz of the C++ Standards!
}

// Arrays with Functions! : Using the arrays with functions has the same reason as of the using normal functions and that is code ki readability and usability badhti hai!
#include<iostream>
using namespace std;

// Creating function to print every value in the array!
int printArray(int arr[], int size) {
    for(int i=0; i<size; i++) {
        cout<<"Value at "<<i<<" of "<<" is : "<<arr[i]<<endl;
    }
}
// In the above function, jab array humne declare kiya brackets me tab hum chaahe toh arr[], iske andar hum size ki value daal sakte hai like, int arr[10], but that is not advisable becoz vo fir specific case hojayega!
// If you also want ki arrays ki values ke saath unn arrays ke naam bhi print ho toh uske liye ek alag parameter add krna hoga function declaration me arrayName naam se taaki array ka naam bhi print ho taaki pta chale ki vo jo value hai vo kis array se belong krti hai!

int main() {
    int arr1[5] = {0,1,2,3,4};
    int arr2[10] = {10,11,12,13,14};
    int arr3[15] = {20,21,22,23,24};

    // Now one way we have to print all the indexes is by using cout statement for all the entries!
    // But we will use the array with functions to print all the entries/indexes of the three arrays!

    // But lets start with the very lame method, that is using the cout statements for every indexes of array arr1...
    // cout<<arr1[0]<<endl;
    // cout<<arr1[1]<<endl;
    // cout<<arr1[2]<<endl;
    // cout<<arr1[3]<<endl;
    // cout<<arr1[4]<<endl;
    // Here we have printed every value at every index using the cout statement! also above we have seen that we have used the for loop to print all the values, but still like we dont neither want to write cout statements again and again for every array nor we want to write for loop for every arrays again n again!
    // so now we will use the array with function, we will create a function and write the for loop inside it and then we will just do the function calls!
    // Now using function calls for every array!
    printArray(arr1, 5);
    printArray(arr2, 10);
    printArray(arr3, 15);
    // Now these function call will print all the values of the array! isse kya hua ki humare code ki readability and reusability badh gyi!

    // Now suppose we want to find the size of an array, then we will do this...
    int arr1size = sizeof(arr1)/sizeof(int);
    cout<<"Size of arr1 : "<<arr1size; // It will print 5, which is the size of the array arr1.
    // But maanlo like humare array 10 size ka hai and usme 5 hi element pade hue hai then hume uska actual size nikalna possible nhi hai toh uss case me hi hum int size naam se ek parameter daalte hai function declaration me!

    int arr2size = sizeof(arr2)/sizeof(int);
    cout<<"Size of arr2 : "<<arr2size; // It will print 10

    int arr3size = sizeof(arr3)/sizeof(int);
    cout<<"Size of arr3 : "<<arr3size; // It will print 15
} // Arrays character and baaki data types ke bhi bante hai, we can do the same above thing with them also! but upar me jo printArray function hai vo sirf int data type vaale arrays ke liye kaam krega!

// Question 1: Finding the maximum/minimum value among all the values in an array!
#include<iostream>
#include<climits>
using namespace std;

// Declaring a array function, ye array or uska size leke poore array me iterate krega and find krega sabse badaa number konsa hai, and that will be done with the INT_MIN value!
int getMax(int arr[], int n) {
    int maximum = INT_MIN;
    for(int i=0; i<n; i++) {
        // We have inbuilt function also to find the maximum value of the array!
        // maximum = max(maximum, arr[i]); // Ye line vahi same kaam krega jo neeche ki 3 lines ne kiya hai!
        if(arr[i]>maximum) {
            maximum = arr[i];
        }
    }
    return maximum;
}

// Declaring a array function, ye array or uska size leke poore array me iterate krega and find krega sabse chhota number konsa hai, and that will be done with the INT_MAX value!
int getMin(int arr[], int n) {
    int minimum = INT_MAX;
    for(int i=0; i<n; i++) {
        // We have inbuilt function also to find the minimum value of the array!
        // minimum = min(minimum, arr[i]); // Ye line vahi same kaam krega jo neeche ki 3 lines ne kiya hai!
        if(arr[i]<minimum) {
            minimum = arr[i];
        }
    }
    return minimum;
}

int main() {
    int size;
    cin>>size;
    // int arr[size]; // This is not at all a good practice as here we are trying to make the size of the array a variable, but this is not how you do it!, that we will learn later on, but for now lets keep its size static!
    int arr1[100];

    // The below for loop is used to take input for an array, also humne pehle array ka ek fixed size rakh diya, then humne ek size naam ka variable banaya jisse kya hoga ki hum pehle size input krenge and then uss size ke hisaab se hi input jayega!
    for(int i = 0; i<size; i++) {
        cin>>arr1[i];
    }

    // Function call while printing the values!
    cout<<getMax(arr1, size)<<endl;
    cout<<getMin(arr1, size)<<endl;
}

// Addressing and Updation and function call in Arrays!
#include<iostream>
using namespace std;

int update(int arr[], int size) {
    cout<<"Inside the Update Function"<<endl;
    arr[1] = 100;
    for(int i=0; i<3; i++) {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    cout<<"Going back to the Main Function"<<endl;
}

int main() {
    // Declared an array inside the main function!
    int arr1[3] = {1,2,3};

    // Here we have called the update function, now the point is, that jab pehle humne jab aise updates kiye the pehle ke questions me toh main me jo function call me jo paramter pass krte the unki ek copy ban jaati thi and fir uss code pr jo bhi updation hona hota tha vo hota tha, pr yahaa aisa nhi hua, why?...
    // This is becoz it is an array, yahaa hum array ko function call me pass nhi krte, balki array ke base element ke address ko pass krte hai function call me, toh jab update function ke paas arr1 ka address gya, toh usne saari updation seedha arr1 me krdi rather than koi ek alag copy banaye bagair!
    // Tab hi main function me arr1 jo hai usme bhi updation hogyi! kyunki humne array ke 0th index ke element ka address hi pass krdiya tha! as the name of an array maps with the address of the base element of that array!
    update(arr1, 3);
    for(int i=0; i<3; i++) {
        cout<<arr1[i]<<" ";
    }
}

// Question 2 : Take input in an array and then find the sum of all of its elements!
#include<iostream>
using namespace std;

int arraySum(int arr[], int n) {
    int sum = 0;
    for(int i=0; i<n; i++) {
        // sum = arr[i] + sum;
        sum += arr[i];
    }
    return sum;
}

int main() {
    int size;
    cin>>size;
    int arr1[20]; // You can input any number of elements up to 20. and You cannot input more than 20 elements because the array only has 20 slots available.
    for(int i = 0; i<size; i++) {
        cin>>arr1[i];
    }
    cout<<"Sum of all the values of the array "<<arraySum(arr1, size)<<endl;
}

// Question 3 : Linear Search! : This is used to seach an element in an array! and that element for which we are searching for is called a key!
#include<iostream>
using namespace std;

// Linearly harr element pr iterate kraa ke check kiya ki kya vo key ke equal hai, agar hai toh return true krdo otherwise false!
int linearSearch(int arr[], int n, int key) {
    for(int i=0; i<n; i++) {
        if(arr[i]==key) {
            return 1;
            // return true; // Can also write this
        }
    }
    return 0;
    // return false; // Can also write this
}

int main() {
    cout<<"Enter the size of the array : ";
    int size;
    cin>>size;

    // Declaring and Input in Array!
    int arr1[50];
    for(int i=0; i<size; i++) {
        cin>>arr1[i];
    }

    bool found = linearSearch(arr1, size, 5); // Called the function and key = 5. and kept the data type boolean for the output

    // Final Answer!
    if(found) {
        cout<<"Key is present!";
    }
    else {
        cout<<"Key is absent";
    }
}

// Question 3 : Reverse an Array!
// Approach : We will take a starting point jo 0th index of array ko represent krega and then ek end point jo last index of array ko represent krega, now what we will do is, vaise toh hum ek swap function use krenge pr vo swap function krta kya that is explained here,
// so, kya hota hai ki jaise agar ek array hai 6 elements ka, toh pehle start point 0th index pr hoga and end vaala last index pr (which is 5 here) toh pehle inn dono ko hum swap krdenge, now we will do start++ and end-- and now will again swap, now will continue this,
// jab tak start end se aage na badh jaye or in other words ki start>end, this will be our terminating condition!
#include<iostream>
using namespace std;

void reverseArray(int arr[], int n) {
    int start = 0;
    int end = n-1;

    while(start<=end) {
        swap(arr[start], arr[end]);
        start++;
        end--;
    }
}

void PrintArray(int arr[], /* int n (Ye nhi likh sakte, vrna function overload ke chakkar me printArray ke neeche redline ayegi!) */ int size) { // Yahaa agar multiple functions void type ke hai dono ke parameter list ekdum same hai even with the variable declarations are same! then in that case IDE shows a function overload error! to resolve that just make sure when you have multiple functions with same return type and their parameter list is also same in that case,
    for(int i=0; i<size; i++) {  // change the name of the variable declaration names in the function declaration brackets! Even tho code execute successfully hojayega! bss jo do functions hai jinke function declaration and return type dono same hai, bhale hi vo kaam alag alag kr rhe ho, unn dono me se kisi ek ke neeche red line aayegi! so just to resolve that make sure you keep this thing in mind! Also iss poori file multiple times same hi function and cheeze repeatative bani hui hai! isliye bhi isme error aa rha hai!
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main() {
    cout<<"Enter the size of the array : ";
    int size;
    cin>>size;

    // Declaring and Input in Array!
    int arr1[50];
    for(int i=0; i<size; i++) {
        cin>>arr1[i];
    }

    reverseArray(arr1, size);
    printArray(arr1, size);
} // Solved the above problem with 2 function calls! ek hi me bhi kr sakte the like printArray() vaala function ka code reverseArray() ke saath rakh sakte the, but okay thori readability and reusability badhaane ke liye theek hai for now!

// ---------------------------------------------------------- LECTURE 10 - Arrays Question (Leetcode/CodeStudio) --------------------------------------------------------------------------------------------------------->
// Problems in Arrays!
// Leetcode Question 1 : Swap all the alternate numbers in the array! like if array is 1,2,3,4,5 then output will be 2,1,4,3,5 in case of odd number, baaki you get it what will be in even number!
#include<iostream>
using namespace std;

int swapAlter(int arr[], int n) {
    for(int i=0; i<n; i+=2) {
        if(i+1<n) { // i+1<n likhna is important coz it make sure the i will be within range!
            swap(arr[i], arr[i+1]);
        }
    }
}

int printArray(int arr[], int n) {
    for(int i=0; i<n; i++) {
        cout<<arr[i]<<" ";
    }
}

int main() {
    cout<<"Enter the size of the Array : ";
    int size;
    cin>>size;

    int arr1[30];
    for(int i=0; i<size; i++) {
        cin>>arr1[i];
    }
    swapAlter(arr1, size);
    printArray(arr1, size);
}
// Lets breakdown the above swap function that we made in the some of the above questions!
// So what actually happens is : swap(arr[i], arr[i+1]), now we make a temp variable jisme hum ek index ki value ko temporary store krenge taaki uss index ki jagah kisi aur index ki value daal sake and then uss temp me jo value store this usko dusre vaale index me daal de!
// swap(arr[i], arr[i+1]);
// int temp = arr[i+1];
// arr[i+1] = arr[i];
// arr[i] = arr[i+1];
// So that is how we swap!

// Another Solution :
#include<iostream>
using namespace std;

void swapAlternate(int arr[], int size) {
    for (int i = 0; i < size - 1; i += 2) {
        int temp = arr[i];
        arr[i] = arr[i + 1];
        arr[i + 1] = temp;
    }
}

void printarray(int arrInput[], int size) {
    for(int i = 0; i<size; i++) {
        cout<<arrInput[i];
    }
}

int main() {
    int arr1[30];
    int size;
    cin>>size;
    for(int i = 0; i<size; i++) {
        cin>>arr1[i];
    }
    swapAlternate(arr1,size);
    printArray(arr1,size);
}

// Leetcode Question 2 : Check whether an array contains any unique element or not! and print that unique element!
// 1st (Optimized solution) :
#include <iostream>
#include<climits>
using namespace std;

int main() {
    int n; cin>>n;
    int *arr = new int[n];
    int max_element = INT_MIN;
    bool flag = false;
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
        max_element = max(max_element, arr[i]);
    }
    int *freq = (int*)calloc(max_element+1,sizeof(int));
    for(int i=0;i<n;i++)
    {
        freq[arr[i]]++;
    }
    for(int i=0;i<=max_element;i++)
    {
        if(freq[i]==1)
        {
            n = i;
            flag = true;
            break;
        }
    }
    if(flag==true)
            cout<<"Found a distinct element:"<<n<<endl;
    else{
        cout<<"No distinct element found"<<endl;
    }
    delete[] arr;
    delete[] freq;
    return 0;
}

// Same logic just a different approach...
#include<iostream>
#include<climits>
using namespace std;

int main() {
    int n;
    cin>>n;
    int* arr = new int[n];
    int max_element = INT_MIN;
    for(int i = 0; i<n; i++) {
        cin>>arr[i];
        if(arr[i] > max_element) {
            max_element = arr[i];
        }
    }

    int* count = new int[max_element+1](); // adding parenthesis at the end makes it works like calloc, as it initiallize the array with 0!
    for(int i = 0; i<n; i++) {
        count[arr[i]]++;
    }
    for(int i = 0; i<=max_element; i++) {
        if(count[i] == 1) {
            cout<<"There is atleast one unique element, that is : "<<i;
        }
    }
    delete[] arr;
    delete[] count;
}

// 2nd (Using STL library map) : This we will study further going in... so for now you can ignore this solution but once you understand STL then you can check it again!
#include<iostream>
#include<map>
using namespace std;

int main() {
    int n;
    cin>>n;
    map<int,int> mp;
    int num;
    for(int i = 0; i<n; i++) {
        cin>>num;
        mp[num]++; // Incrementing value by 1 at that index!
    }
    for(auto it:mp) {
        cout<<"Element "<<it.first<<" has "<<it.second<<" occurence!"<<endl;
    }
}

// 3rd (Normal Solution) :
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int arr[10000];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    bool flag = false;
    for(int i=0; i<n; i++) {
        flag = true;
        for(int j=0; j<n; j++) {
            if(i!=j && arr[i]==arr[j])
                flag = false;
        }
        if(flag==true) {
            cout<<"Unique Element found: "<<arr[i]<<endl;
            // break;
        }
    }
    if(flag==false) {
        cout<<"No Unique Element found!";
    }
}

// 4th (Love Babbar Solution) : Finding the Unique Element
// This approach works under the constraint that there is exactly one unique element in the array. Also it is not applicable if any number appears an odd number of times as a duplicate.
// Approach : A straightforward but inefficient method would be to count the occurrences of each element and find the one with a count of 1. However, this is not an optimal solution.
// A more efficient approach utilizes the XOR operation, which follows a key property : XOR of two identical numbers is always 0 (i.e., x ^ x = 0).
//                                                                                    : XOR with 0 returns the number itself (i.e., x ^ 0 = x).
// How XOR helps : Given an array {1,1,2,2,3}, performing XOR on all elements will cancel out the duplicate values (since 1^1 = 0 and 2^2 = 0).
//               : What remains is 0 ^ 3 ^ 0, which results in 3, the unique element.
//               : Since all duplicate elements cancel out, the remaining number is the unique one.
// This method efficiently finds the unique element in O(N) time and O(1) space.
#include<iostream>
using namespace std;

// Function to find the unique element in an array
int findUnique(int arr[], int n) {
    int ans = 0;
    for(int i = 0; i < n; i++) {
        ans ^= arr[i];  // XOR operation to cancel out duplicate elements
    }
    return ans;
}

int main() {
    int size;
    cin >> size;

    int arr1[10000]; // Static array declaration, though dynamic allocation is more optimized
    for(int i = 0; i < size; i++) {
        cin >> arr1[i];
    }

    cout << "The Unique Element is: " << findUnique(arr1, size);
}
// Explanation : A naive approach is to count occurrences of each element and find the one with a count of 1, but this is inefficient.
//             : Instead, we use the XOR property : XOR of two same numbers results in 0 (e.g., 1 ^ 1 = 0).
//                                                : XOR of any number with 0 remains unchanged (e.g., 0 ^ 3 = 3).
//                                                : XORing all elements cancels out duplicates, leaving only the unique element.
//             : This approach is valid only when there is exactly one unique element in the array.
//             : It does not work correctly if an element appears an odd number of times.
//             : If you need to check the frequency of elements, using a **map** would be a better choice.

// Leetcode Question 3 : Given an array containing integers in the range 1 to (n-1), where each number appears at least once, one integer is duplicated in the array. Your task is to find the duplicate integer.
// Approach : The simplest method is to count the occurrences of each element. The number that appears twice is the duplicate.
//          : This brute-force approach is straightforward and provides a correct solution.
//          : While it is fairly optimized, it still falls under brute-force techniques, meaning there is room for further optimization.
//          : That being said, it is still an effective starting solution—so kudos for that!
#include<iostream>
#include<climits>
#include<cstdlib>
using namespace std;

int countTwo(int arr[], int size, int max_element) {
    int *count = (int*)calloc(max_element+1,sizeof(int));
    for(int i = 0; i<size; i++) {
        count[arr[i]]++;
    }
    for(int i = 0; i<=max_element; i++) {
        if(count[i] == 2) {
            return i;
        }
    }
    free(count);
    return 0;
}

int main() {
    int arr1[50];
    int size;
    cin>>size;
    int max_element = INT_MIN;
    for(int i = 0; i<size; i++) {
        cin>>arr1[i];
        max_element = max(max_element,arr1[i]);
    }
    int countTwoIndex = countTwo(arr1,size,max_element);
    cout<<"Elements whose index is count 2 is : "<<countTwoIndex;
}

// Let's try to find a better solution...
// Approach : Using XOR to Find the Duplicate Element
// Concept Behind XOR : XOR Property : a ^ a = 0 (XOR of the same number cancels out)
//                                   : a ^ 0 = a (XOR with 0 gives the same number)
//                    : XOR is associative and commutative, meaning order doesn't matter.
//                    : How XOR Helps Find the Duplicate? If we XOR all elements of the array, duplicates will cancel out.
//                    : If we also XOR numbers from 1 to n-1, all numbers except the duplicate will cancel out, leaving just the duplicate.
#include<iostream>
using namespace std;

int findDuplicate(int arr[], int n) {
    int ans = 0;
    for(int i=0; i<n; i++) {
        ans = ans^arr[i];
    }
    for(int i=1; i<n; i++) {
        ans = ans^i;
    }
    return ans;
}

int main() {
    int size;
    cin>>size;
    int arr1[50];
    for(int i=0; i<size; i++) {
        cin>>arr1[i];
    }
    cout<<"Duplicate Element is : "<<findDuplicate(arr1, size)<<endl;
}

// Another approach is to take the sum of all elements in the array, then calculate the sum of numbers from 1 to n-1, and finally subtract the two sums to find the duplicate number!
// Let's implement this approach:
#include<iostream>
using namespace std;

int findDuplicate(int arr[], int n) {
    int sum1 = 0, sum2 = 0;
    for(int i=0; i<n; i++) {
        sum1 = sum1 + arr[i];
    }
    for(int i=0; i<n; i++) {
        sum2 = sum2 + i;
    }
    int ans = sum1 - sum2;
    return ans;
}

int main() {
    int size;
    cin>>size;
    int arr1[50];
    for(int i=0; i<size; i++) {
        cin>>arr1[i];
    }
    cout<<"Duplicate Element is : "<<findDuplicate(arr1, size)<<endl;
}

// Leetcode Question 4 : Find the Intersection of Two Arrays, If no intersection exists, print -1. The arrays are sorted in non-decreasing (increasing) order. Time Limit: 1 sec and Constraints: 1 < size1 & size2 <= 10000, 0 < arr1[i] & arr2[i] <= 100000
// Approach : Given two arrays : arr1 = [1,2,3,3], arr2 = [3,4]
//                             : Compare each element of arr1 with all elements of arr2.
//                             : If a match is found, add it to the result and mark the matched element in arr2 with an arbitrary value (e.g., INT_MIN) to prevent duplicate matches.
//                             : Example walkthrough : 1 and 2 don’t match with any elements in arr2, 3 matches with the first 3 in arr2, so we store it and mark that 3 in arr2 as visited (INT_MIN).
//                                                   : The next 3 in arr1 does not match the same 3 in arr2 again, ensuring uniqueness.
// Why use vectors? Since we don’t know the array size beforehand, vectors dynamically allocate memory. We'll cover vectors in detail in STL, but for now, focus on the logic.
#include<iostream>
#include<vector>
#include<climits>
using namespace std;

// Function to find the intersection of two sorted arrays
vector<int> findIntersection(vector<int> &arr1, int size1, vector<int> &arr2, int size2) {
    vector<int> result;
    for(int i = 0; i < size1; i++) {
        int element = arr1[i];
        for(int j = 0; j < size2; j++) {
            if(element == arr2[j]) {
                result.push_back(element); // Add to result if there's a match
                arr2[j] = INT_MIN; // Mark the matched element as visited using a placeholder value
                break; // Ensure a single occurrence is matched only once
            }
        }
    }
    return result;
}

int main() {
    int size1, size2;
    cin >> size1 >> size2;
    
    vector<int> arr1(size1);
    vector<int> arr2(size2);

    for(int i = 0; i < size1; i++) {
        cin >> arr1[i];
    }
    for(int i = 0; i < size2; i++) {
        cin >> arr2[i];
    }
    
    vector<int> result = findIntersection(arr1, size1, arr2, size2);
    cout << "Intersection: ";
    for (int i : result) { 
        cout << i << " ";  
    } 
}

// The previous solution is not optimized and results in a Time Limit Exceeded (TLE) warning. To optimize it, we need to utilize the fact that both arrays are sorted in non-decreasing order (increasing order).
// Instead of comparing every element of arr1 with all elements of arr2, we can skip unnecessary comparisons. If arr2[j] becomes greater than arr1[i], there's no point in checking further elements of arr2, as they will all be greater than arr1[i].
// Example : Let’s say arr1 = [1, 4, 5] and arr2 = [4, 5].
//         : When arr1[0] = 1 is compared with arr2[0] = 4, we notice that 4 > 1, meaning all further elements in arr2 will also be greater than 1.
//         : So, we skip checking further elements in arr2 and move to the next element in arr1.
#include<iostream>
#include<vector>
#include<climits>
using namespace std;

vector<int> findIntersection(vector<int> &arr1, int size1, vector<int> &arr2, int size2) {
    vector<int> ans;
    for(int i=0; i<size1; i++) {
        int element = arr1[i];
        for(int j=0; j<size2; j++) {
            if(element < arr2[j]) { // Here we are considering that the arrays are sorted already tab hi toh comparisons kr paa rhe hai! ki agar element < arr[j], then we won't proceed further!
                break;
            }
            if(element == arr2[j]) {
                ans.push_back(element);
                arr2[j] = INT_MIN;
                break;
            }
        }
    }
    return ans;
}

int main() {
    int size1, size2;
    cin>>size1>>size2;
    vector<int> arr1(size1);
    vector<int> arr2(size2);
    for(int i=0; i<size1; i++) {
        cin>>arr1[i];
    }
    for(int i=0; i<size2; i++) {
        cin>>arr2[i];
    }
    vector<int> result = findIntersection(arr1, size1, arr2, size2);
    cout << "Intersection: ";
    for (int i : result) {
        cout << i << " ";
    }
}

// The previous approach still results in a TLE warning because it uses two nested loops. To optimize further, we will reduce the number of loops.
// Let's use a more efficient method called the two-pointer approach.
// How does the two-pointer approach work...
// Suppose we have two sorted arrays : arr1 = [1,2,2,2,3,4] and arr2 = [2,2,3,3]
// - We place one pointer (i) at the beginning of arr1 and another pointer (j) at the beginning of arr2.
// - We compare arr1[i] and arr2[j]:
// - If arr1[i] < arr2[j], move pointer i forward (i++) since the smaller element cannot be in the intersection.
// - If arr1[i] == arr2[j], we store the element in the result and move both pointers forward (i++ and j++).
// - If arr1[i] > arr2[j], move pointer j forward (j++).
// - The loop runs until one of the arrays is completely traversed.
// This approach significantly reduces time complexity to O(N + M) compared to the previous O(N × M).
// Let's implement this optimized approach:
#include<iostream>
#include<vector>
using namespace std;

void printArray(vector<int> arr) {
    for(int i = 0; i<arr.size(); i++) {
        cout<<arr[i]<<" ";
    }
}

void intersectArrays(vector<int> arr1, vector<int> arr2) {
    vector<int> ansArray;
    int i = 0;
    int j = 0;
    bool commonPresent = false;
    while(i<arr1.size() && j<arr2.size()) {
        if(arr1[i] == arr2[j]) {
            commonPresent = true;
            ansArray.push_back(arr1[i]);
            i++;
            j++;
        }
        if(arr1[i] > arr2[j]) {
            j++;
        }
        else {
            i++;
        }
    }
    if(commonPresent) {
        printArray(ansArray);
    }
    else {
        cout<<-1;
    }
}

int main() {
    int n1,n2;
    cin>>n1>>n2;
    vector<int> arr1(n1);
    vector<int> arr2(n2);
    for(int i = 0; i<n1; i++) {
        cin>>arr1[i];
    }
    for(int i = 0; i<n2; i++) {
        cin>>arr2[i];
    }
    intersectArrays(arr1,arr2);
}

// Leetcode Question 5 : You are given an integer array of size n, and your task is to return a list of all pairs of elements whose sum equals a given value S.
// The pairs must follow these constraints : Each pair should be sorted in ascending order. The list of pairs should be sorted in non-decreasing order based on the first value of the pair. If two pairs have the same first value, then the pair with the smaller second value should come first.
// Approach (Two-Pointer Method) : We'll iterate through the array using two nested loops : The outer loop will run from i = 0 to n - 1.
//                                                                                        : The inner loop will run from j = i + 1 to n - 1. Whenever the sum of arr[i] + arr[j] equals S, we will store the pair in a 2D vector because we need to return a list of pairs.
// Why Use a 2D Vector : A 2D vector (i.e., vector<vector<int>>) allows us to store multiple pairs. Think of it like a dynamic array that stores vectors, similar to how a 1D vector stores individual integer values.
// For example : Initially, ans = [[]] (empty list).
//             : If we find a valid pair (a, b), the list updates to ans = [[a, b]].
//             : If we find another pair (c, d), the list updates again: ans = [[a, b], [c, d]], and so on...
//             : Finally, we use sort(ans.begin(), ans.end()) to ensure that pairs are sorted based on their first value, and in case of a tie, the second value is considered. The sort function automatically handles this requirement.
#include<iostream>
#include<vector>
#include<algorithm> // To use the sort function
using namespace std;

vector<vector<int>> pairSum(vector<int> &arr1, int n) {
    vector<vector<int>> ans;
    for(int i=0; i<arr1.size(); i++) {
        for(int j=i+1; j<arr1.size(); j++) {
            if(arr1[i] + arr1[j] == n) {
                vector<int> temp;
                temp.push_back(min(arr1[i], arr1[j]));
                temp.push_back(max(arr1[i], arr1[j]));
                ans.push_back(temp); // isme agar tum ye socho ki 1D vector ko 2D vector me kaise input kiya, toh iska answer ye hai ki, ans is vector of vectors, toh ye input me 1D vectors ko hi store krega! isko aise samajh lo ki jaise normal 1D vector me atomic int values store hoti hai! vaise hi 2D vector me linear vectors store hote hai! toh agar initially ans = [[]] aise tha, toh jab first time temp input hua hoga, toh iske andar ek vector gya hoga! toh ab ye update hoke ans = [[a,b]] ban jayega! and then jab dusri iteration me firse pair of values temp me store hoke ek vector ke form me and vaale 2D vector me store hone ayengi toh firse ans vector update hojayega with ans = [[a,b],[c,d]] and so on... 
            }
        }
    }
    sort(ans.begin(), ans.end()); // ye dusri vaali condition ki, list of pairs should be sorted primarily by the first value of the pairs, and if two pairs have the same first value, they should be sorted by the second value ye cheez sort function khud hi handle kr le rha hai! we dont need to do something else more!
    return ans;
}

int main() {
    int value;
    cin>>value;
    int size1;
    cin>>size1;
    vector<int> arr1(size1);
    for(int i=0; i<size1; i++) {
        cin>>arr1[i];
    }
    vector<vector<int>> result = pairSum(arr1, value);
    cout << "Intersection: ";
    for (vector<int> pair : result) {
        cout << "(" << pair[0] << ", " << pair[1] << ") ";
    }
}

// Leetcode Question 7 : Sort 0, 1 in an array!
#include<iostream>
using namespace std;

void sortOne(int arr[], int n) {
    int left = 0, right = n-1;
    while(left<right) {
        while(arr[left] == 0 && left<right) {
            left++;
        }
        while(arr[right] == 1 && left<right) {
            right--;
        }
        if(left<right) {
            swap(arr[left], arr[right]);
            left++;
            right--;
        }
    }
}

void PrintArray(int arr[], int n) {
    for(int i = 0; i<n; i++) {
        cout<<arr[i]<<" ";
    }
}

int main() {
    int size;
    cin>>size;
    int arr1[10000];
    for(int i=0; i<size; i++) {
        cin>>arr1[i];
    }
    sortOne(arr1, size);
    PrintArray(arr1, size);
}

// ---------------------------------------------------------- Some Extras --------------------------------------------------------------------------------------------------------->
// Note : Writing printf(0) in C is not right! and will give the runtime error! but cout<<0; will not throw any error, reason is, printf() function is made to print strings, if you see we put all our output in a string format and then we use format specifiers to print our own values! but eventually it is printing a string!
// But "cout" can print all other types of datatype it can print number, string, bool, float or any other... so in that way "cout" is more flexible to print values! but it is said that in terms of optimization, printf() is more optimized than cout... but that is not always true, it depends on cases when you are using what!
// Hence, printf() can be faster for basic output tasks, especially in performance-sensitive applications.
// But, cout is more versatile, type-safe, and easier to use, but it might be slower due to synchronization and extra overhead. However, disabling synchronization (std::ios::sync_with_stdio(false);) can speed up cout.
// So, yes it depends on your use case!

// Dynamic Memory Allocation! in C/C++.
// It is a way of allocating the memory to the data structure during the runtime! and we do this using some functions like, calloc(), malloc(), realloc() and free().
// malloc() : Malloc() ek function hai jo C programming language mein dynamic memory allocate karne ke kaam aata hai. Iska full form hai "memory allocation". Isko use karke hum runtime par memory allocate kar sakte hain, jo humein flexibility aur efficiency deta hai.
//          : Takes the number of bytes to allocate & return a pointer of the type void!
//          : Syntax : int *ptr; ptr = (int*)malloc(10*sizeof(int)); Here we have allocated 10 int size of uninitiallized memory and returned the address of first index of that memory to the pointer ptr, so that it can be accessed easily! and while returning we have type casted it into int, kyunki vrna bina typecast ke krte toh ek void pointer return hota 1st index ka! so that is why we have type casted it into int!
// Example :
#include <stdio.h>
#include <stdlib.h>

int main() {
    int *ptr;
    
    // 10 integers ke liye memory allocate karte hain
    ptr = (int*)malloc(10 * sizeof(int));
    
    if (ptr == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }
    
    // Memory ko initialize karte hain
    for (int i = 0; i < 10; i++) {
        ptr[i] = i + 1;  // Ya phir ptr[i] = 0; se initialize kar sakte hain
    }
    
    // Values ko print karte hain
    for (int i = 0; i < 10; i++) {
        printf("%d ", ptr[i]);
    }
    printf("\n");
    
    // Memory free karna zaroori hai
    free(ptr);
    
    return 0;
}

// calloc() : calloc ek function hai jo C programming language mein dynamic memory allocate karne ke kaam aata hai, lekin yeh malloc se thoda different hai. calloc memory allocate karne ke sath-saath us memory ko zero se initialize bhi karta hai.
//          : Takes the number of bytes to allocate and unn sab ko 0 se initiallize krdeta hai, which is an extra feature as compare to malloc()
//          : syntax : int *ptr; ptr = (int*)calloc(num, sizeof(int)); isme ye num me hum jo size daalenge utne block ye sizeof() operator ko use krke utne blocks allocate krdega! and then again vhi 0th index ka index int me type caste krke return krdega! agar type caste nhi krenge toh ye bhi void pointer return krta hai! hum kisi aur data type me bhi type cast kr sakte hai! ya sizeof() me int ke jagah koi aur data type bhi daal sakte hai! agar hume kisi aur size ke hisaab se memory allocate krni hai toh!
// Example :
#include <stdio.h>
#include <stdlib.h>

int main() {
    int *arr;
    int n = 5; // 5 integers ka array
    
    // 5 integers ke liye memory allocate karte hain
    arr = (int*)calloc(n, sizeof(int));
    
    if (arr == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }
    
    // Array ko initialize karna zaroori nahi hai, kyunki calloc ne already zero se initialize kiya hua hai
    // Lekin hum fir bhi use karke initialize kar sakte hain, jaise...
    for (int i = 0; i < n; i++) {
        arr[i] = i + 1;
    }
    
    // Array ko print karte hain
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    // Memory free karna zaroori hai
    free(arr);
    
    return 0;
}

// realloc() : Agar maanlo humne kisi ek program me 30 students ki info ke liye memory allocate ki thi pr ab 30 se zyada bache aagye toh hume memory badhani padegi! so in that case we use realloc()
//           : realloc ek function hai jo dynamically allocated memory ki size ko adjust karne ke kaam aata hai. Iska use tab hota hai jab aapko pehle se allocated memory block ko chhota ya bada karna ho. Yeh malloc aur calloc se allocated memory ko resize karta hai.
//           : If we take reference syntax like this, void* realloc(void* ptr, size_t new_size); so, jab realloc function call hota hai, yeh existing memory block (pointed by ptr) ko new_size bytes ka banane ki koshish karta hai. Agar successful hota hai, to wahi memory block resize ho jata hai aur same pointer return hota hai. Agar existing memory block ko resize karna possible nahi hota, to nayi memory allocate karta hai, purani values ko copy karta hai, aur nayi memory block ka address return karta hai. Purani memory block free kar di jaati hai.
//           : syntax : int* ptr; realloc(ptr, new size); isme almost sab cheeze same hai malloc calloc ka jo basic logic hai ki dynamically memory allocate ho rhi hai! bss isme ye hai ki ye new size ke hisaab se already allocated memory ko increase ya decrease krta hai! like, agar pehle 5 size of int ki memory allocated hai! and agar hum 8 size of int ki memory all allocate krte hai realloc ke through! so yaa toh jo already allocated memory hai vo 5 size ki hai toh usme hi 3 bytes aur add hojayenge size of int ke! otherwise ek poora nayaa memory series of memory block banega of size 8, and usme pehle toh saara data copy hoga unn poorani 5 bytes and then uske baad 3 bytes ki memory aur allocate hogi! mtlb ki poorani bytes rehti hai and usme aur add on hoti hai new add on bytes!
//           : Its like, pehle se 5 thi, size badhai humne 8 ki, toh agar vhi ke vhi allocate hogyi toh bss 3 bytes aur add hongi kyunki pehle se 5 thi and new allocated memory 8 ki hai! in other case, ek new 8 bytes ki size allocate hogi! and then usme pehle toh vo 5 bytes copy hongi! and then uske baad 3 bytes bachi rahengi! toh yahaa bhi size badh gyi! and pehli vaali 5 bytes vaali memory free krdi jaati hai!
// Example :
#include <stdio.h>
#include <stdlib.h>

int main() {
    int *arr = 0;
    
    // Initial size ke liye memory allocate karte hain
    arr = (int*) malloc(5 * sizeof(int));
    
    if (arr == NULL) {
        printf("Initial memory allocation failed\n");
        return 1;
    }
    
    // Array ko initialize karte hain
    for (int i = 0; i < 5; i++) {
        arr[i] = i + 1;
    }
    
    // Initial array ko print karte hain
    printf("Initial array:\n");
    for (int i = 0; i < 5; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    // Array ki size ko resize karte hain
    arr = (int*)realloc(arr, 8 * sizeof(int));
    
    if (arr == NULL) {
        printf("Memory reallocation failed\n");
        return 1;
    }
    
    // Nayi memory ko initialize karte hain
    for (int i = 5; i < 8; i++) {
        arr[i] = i + 1;
    }
    
    // Resized array ko print karte hain
    printf("Resized array:\n");
    for (int i = 0; i < 8; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    // Memory free karte hain
    free(arr);
    
    return 0;
}

// free() : free ek function hai jo C programming language mein dynamically allocated memory ko deallocate karne ke kaam aata hai. Jab hum malloc, calloc, ya realloc se memory allocate karte hain, toh us memory ko manually free karna padta hai, taaki memory leak na ho. Yeh memory ko free karke usse wapas heap memory mein available banata hai.
//        : Jab free function call hota hai, toh yeh memory block ko deallocate karta hai jo ptr pointer point kar raha hota hai. Yeh memory ko release karke wapas system ko available kar deta hai. Agar ptr NULL hai, toh free kuch nahi karta.
//        : Syntax : int *ptr; free(ptr); Isne seedha uss dynamically allocated memory ko free/deallocate krdiya jispe ptr pointer point kr rha tha!
// Example :
#include <stdio.h>
#include <stdlib.h>

int main() {
    int *ptr;
    
    // Memory allocate karte hain 5 integers ke liye
    ptr = (int*) malloc(5 * sizeof(int));
    
    if (ptr == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }
    
    // Memory ko use karte hain
    for (int i = 0; i < 5; i++) {
        ptr[i] = i + 1;
    }
    
    // Values ko print karte hain
    printf("Values in allocated memory:\n");
    for (int i = 0; i < 5; i++) {
        printf("%d ", ptr[i]);
    }
    printf("\n");
    
    // Memory ko free karte hain
    free(ptr);
    
    // ptr ko NULL set karna, taaki accidentally use na ho
    ptr = NULL;
    return 0;
}
// All these 4 functions are found in "stdlib.h" header file! so use krne se pehle include krna padega isko!

// Goto Statements : The goto statement in C and C++ provides an unconditional jump to another point in the program. It allows the control to be transferred to a labeled statement within the same function. This can be useful for breaking out of deeply nested loops or for implementing certain kinds of error handling.
// Syntax : First we define a label, by just writing "label_name : ", after this we write "goto label_name;"
// Example Syntax : label_name:
//                : [Code to be executed when the goto statement jumps here]
//                : goto label_name;
// Example 1 :
#include <stdio.h>

int main() {
    int num = 0;

    // Define a label
    start:
    printf("num: %d\n", num);
    num++;

    // Conditional jump using goto
    if (num < 5) {
        goto start;  // Jump back to the label 'start'
    }

    printf("Loop finished.\n");

    return 0;
} // This will behave as a loop! everytime when num exceeds 5!

// Example 2 :
#include<stdio.h>

int main() {
    int num;
    for(int i = 0; i<8; i++) {
        printf("%d ",i);
        for(int j = 0; j<8; j++) {
            printf("Enter number & enter 0 to exit ");
            scanf("%d",&num);
            if(num == 0) {
                // break; // Ye sirf ek loop se exit kraa dega! but goto seedha uss end label pr leke chale jayega!
                goto end;
            }
        }
    }
    end :
    printf("Loop end");
}

// Unions vs Structures!
// Structures (struct) : A structure is a user-defined data type that groups related data elements of different types under a single name! Each element in a structure is called a member/field, Members can be accessed using the dot (.) operator
// Unions : A union is a special data type that allows storing different data types in the same memory location. Only one member can hold a value at a time since all members share the same memory space. The size of a union is determined by its largest member
// Key Differences : Memory : Structures allocate separate memory for each member, while unions share memory among members
//                 : Size : Structure size ≥ sum of member sizes; union size = size of largest member.
//                 : Access : In structures, all members can hold values simultaneously; in unions, only one member can hold a valid value at a time
#include <stdio.h>
#include <string.h>

// Structure: Each data member gets separate memory allocation
struct Student {
    int id;
    float cgpa;
    char name[30];
};

// Union: All data members share the same memory, allocated as per the largest member
union StudentUnion {
    int id;
    float cgpa;
    char name[30];
};

int main() {
    printf("Using Structure:\n");
    struct Student s1;
    s1.id = 365;
    s1.cgpa = 9.5;
    strcpy(s1.name, "Utkarsh");
    printf("ID: %d\nCGPA: %.2f\nName: %s\n", s1.id, s1.cgpa, s1.name);
    // Memory allocated: 4 + 4 + 30 = 38 bytes (Each member has its own space)
    
    printf("\nUsing Union:\n");
    union StudentUnion u1;
    u1.id = 365;
    u1.cgpa = 9.5;
    strcpy(u1.name, "Utkarsh");
    // Only the last assigned value remains valid, previous ones get overwritten
    printf("ID: %d\n", u1.id); // May print garbage due to memory overwrite
    printf("CGPA: %.2f\n", u1.cgpa); // May print garbage
    printf("Name: %s\n", u1.name); // Prints "Utkarsh"
    // Memory allocated: max(4, 4, 30) = 30 bytes (Shared memory for all members)
    
    return 0;
}

// Enums : Enums are user-defined data types that give names to integral constants. By default, first value = 0, then auto-increments by 1
//       : Values can be explicitly assigned, All enum values are integers internally.
// Main Use Cases : Representing States/Options : Perfect for fixed sets of choices like days of week, months, or game states
//                : Better Code Readability : Using names instead of cryptic numbers makes code self-documenting.
//                : Type Safety : Like in enum Gender {Male, Female}, it prevents invalid values being used.
//                : Clean Switch Statements : Makes switch-case blocks more intuitive.
//                : Replacing Magic Numbers : Instead of using raw numbers like 404 for HTTP errors, you can use descriptive names:
#include <stdio.h>

int main() {
    // Enum Declaration - Creating a custom data type that maps names to integers
    enum Meal {
        Breakfast,  // = 0 (automatically assigned)
        Lunch,      // = 1 (automatically assigned) 
        Dinner      // = 2 (automatically assigned)
    };

    // You can also explicitly assign values
    enum HTTPStatus {
        OK = 200,
        NotFound = 404,
        ServerError = 500
    };

    // Example showing different use cases
    enum DaysOfWeek {
        Monday,     // = 0
        Tuesday,    // = 1
        Wednesday,  // = 2
        Thursday,   // = 3
        Friday      // = 4
    };

    // Using enums instead of "magic numbers" makes code more readable
    enum LogLevel {
        DEBUG,      // Better than using 0
        INFO,       // Better than using 1
        WARNING,    // Better than using 2
        ERROR       // Better than using 3
    };

    // Printing enum values shows their underlying integer representation
    printf("Meal times:\n");
    printf("Breakfast: %d\n", Breakfast);  // Prints 0
    printf("Lunch: %d\n", Lunch);          // Prints 1
    printf("Dinner: %d\n", Dinner);        // Prints 2

    // Using enum in a variable
    enum Meal currentMeal = Lunch;
    printf("\nCurrent meal value: %d\n", currentMeal);  // Prints 1

    // Using enum in conditions
    if (currentMeal == Lunch) {
        printf("It's lunch time!\n");
    }

    // Using enum with switch
    enum LogLevel level = WARNING;
    switch (level) {
        case DEBUG:
            printf("Debug message\n");
            break;
        case INFO:
            printf("Info message\n");
            break;
        case WARNING:
            printf("Warning message\n");
            break;
        case ERROR:
            printf("Error message\n");
            break;
    }
    return 0;
}

// ------------------------------------------------------------------- Some basics of exclusive C++ from CWH! ------------------------------------------------------------------------------------------------------------------------------>
// With namespace std;
#include<iostream>
using namespace std;
int main() {
    cout<<"Hello World";
    return 0;
}

// Without namespace std;
#include<iostream>
int main() {
    std::cout<<"Hello World";
    return 0;                 
}

// Use of Scope resolution operator
#include<iostream>
using namespace std;

int c = 65;

int main() {
    int a,b,c;
    cout<<"Enter the number :"<<endl;
    cin>>a>>b;
    c = a + b;
    cout<<"The sum of two numbers :"<<c<<endl; 
    cout<<"Value of global C :"<<::c; // Here we used scope resolution operator to access the c outside the main function, as "scope" resolution operator is the name itself enough to understand.
    return 0;
}

#include<iostream>
#include<typeinfo> // To check type related info
using namespace std;

int main() {
    float x = 34.4f; // "f" or "F" is used to specify float number
    long double y = 34.4l; // "l" or "L" is used to specify long double number

    // By default in C++ floating point numbers are treated as double, to convert them into float we have to use type casting
    // 34.4 -> its a double, to convert it into float we will write f after it
    // 34.4f now its a floating point number
    cout<<"the value of x is : "<<x<<endl<<"the value of y is : "<<y<<endl;

    float i = 3.14;
    cout<<sizeof(i)<<endl;
    cout<<typeid(i).name()<<endl; // It will print float! as it was already declared and initiallized using float! so it will print float!
    cout<<typeid(3.14).name()<<endl; // It will print double! as decimals are treated as double by default in C++
    return 0;
}

// Sizeof() Operator
#include<iostream>
using namespace std;

int main() {
    float x = 34.4f; // "f" or "F" is used to specify float number
    long double y = 34.4l; // "l" or "L" is used to specify long double number

    cout<<"the size of 34.4 is :"<<sizeof(34.4)<<endl;
    cout<<"the size of 34.4f is :"<<sizeof(34.4f)<<endl;
    cout<<"the size of 34.4F is :"<<sizeof(34.4F)<<endl;
    cout<<"the size of 34.4l is :"<<sizeof(34.4l)<<endl;
    cout<<"the size of 34.4L is :"<<sizeof(34.4L)<<endl;
}

// Refrence Variables
#include<iostream>
using namespace std;

int main() {
    int a = 65;
    int& b = a; // Refrence variable b, here the memory location where 5 is stored with the name 'a' similary here we added another name for the memory location where 65 is stored!
    cout<<"Value of a : "<<a<<endl;
    cout<<"value of b : "<<b<<endl;
    return 0;
}

#include<iostream>
using namespace std;

// Pass by Value
void updateFunc1(int n) { // Here the value of x is copied that's why it won't affect the x value in main()
    n++;
    cout<<"Update1 value : "<<n<<endl;
}

// Pass by Reference
void updateFunc2(int &y) { // Here we used refrence variable hence "y" became another name for the "x" variable where 65 is stored and hence on changing value in y changes the value in x too
    y++;
}

int main() {
    int x = 65;
    cout<<"Before : "<<x<<endl;
    updateFunc1(x);
    cout<<"After : "<<x<<endl;
    updateFunc2(x);
    cout<<"Update2 Value : "<<x<<endl;
    return 0;
}

// Type casting
#include<iostream>
#include<iomanip>
using namespace std;

int main() {
   float a = 45.66666;
   float b = 65.50;
   cout<<"The value of a is : "<<a<<endl;
   cout<<"The value of b is : "<<b<<endl;
   cout<<"The value of b in int type (using typecasting) : "<<int(b)<<endl;
   cout<<"The value of b in int type (using typecasting) : "<<(int)b<<endl; 
   cout<<"The value of a in float type (using typecasting) : "<<float(a)<<endl;
   cout<<"The value of a in float type (using typecasting) : "<<setprecision(4)<<(float)a<<endl; // In type casting we just write that data type in which we want to print the number with parentheses ().
   printf("The value of a in float type (using typecasting) : %.5f\n", (float)a);
   return 0; 
}

// Constants in C++ : In C++, constants are values that do not change during the execution of a program. They are useful for defining fixed values that have semantic meaning within your code. There are several ways to define constants in C++ :
//                  : Constants can be defined using 4 keywords, 1) "Const" 2) "Constexpr" 3) "Enum" 4) "#define".
//                  : Const : The const keyword is used to declare constants. A constant variable must be initialized at the time of its declaration.
//                  : Constexpr : The constexpr keyword is used to define constants that can be evaluated at compile time. This is more powerful than const because it guarantees that the value is a compile-time constant.
//                  : Enum : Enumerations are a way to define a set of named integer constants. They are often used to represent a collection of related values.
//                  : Macros (#define) : Macros are a preprocessor feature that defines constants. However, they are generally discouraged in modern C++ due to their lack of type safety and scope control.
// There values cannot be changed!
// Example 1 :
#include<iostream>
using namespace std;

int main() {
    const int a = 65;
    cout<<"Before changing value : "<<a<<endl;
    // a = 45; // Here you will get an error because "a" is a constant.
    cout<<"After changing value : "<<a<<endl; // Here after writting "const" before "int a", now we can't change the value because of the constant keyword.
    return 0;
}

// Example 2 :
#include <iostream>
using namespace std;

constexpr int factorial(int n) {
    return (n <= 1) ? 1 : (n * factorial(n - 1));
}

int main() {
    constexpr int result = factorial(5);
    cout << "Factorial of 5 is: " << result << endl;
    // result = 25; // This cannot be done!
    return 0;
}

// Example 3 :
#include <iostream>
using namespace std;

enum Colors { RED, GREEN, BLUE };

int main() {
    Colors myColor = GREEN;
    if (myColor == GREEN) {
        cout << "The color is green." << endl;
    }
    return 0;
}

// Example 4 :
#include <iostream>
using namespace std;

#define MAX_SIZE 100

int main() {
    cout << "Max Size: " << MAX_SIZE << endl;
    return 0;
}

// Manipulators : Setw() and Setfill().
// Detailed Explaination of Setw : In C++, setw is a manipulator used with output streams (such as cout) to set the width of the next output field. This is part of the <iomanip> library, which provides a set of stream manipulators that can be used to control the formatting of output.
//                               : Ye outputs ko format krne me kaam aata hai! jaise agar setw(5) likh diya and jo humara output hai vo 5 characters se kam ka hai toh ye left me kuch spaces chhor dega unn characters ke hisaab se!
//                               : If the output is longer than n characters, it will not be truncated; instead, it will be displayed in full, ignoring the width setting. here we use setfill function!
// Example :
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
    cout << setw(10) << setfill('*') << num << endl; // Outputs "*******123", means ki pehle humne set krdiya ki 10 characters ka jagah output lega! and then agar output usse chhota hai toh humare paas choice hai ki yaa toh usko hum khaali chhor de, yaa toh setfill ka use krke unn spaces ko fill krde! and agar output more than 10 characters hota toh simply vo jo limit hai uski koi value nhi rehti!
}

// ------------------------------------------------------------ Summary Questions Lists -------------------------------------------------------------------------------------------------------------------------------------------------------------->
// Basic Maths Questions :
// Practice Question 1 : Write a Program to Display Fibonacci Series upto certain number n (n is entered by user) Example: n = 100, Output : Fibonacci Series: 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89
// Practice Question 2 : Find the GCD of 2 numbers input by the user!
// Practice Question 3 : Find the LCM of 2 numbers input by the user!

// Pattern Making Questions :
// Practice Question 4 : Draw a pattern with 4 rows and 4 columns!
// Practice Question 5 : Print 1 three times in 1st row, 2 three times in 2nd row, 3 three times in 3rd row!
// Practice Question 6 : Create a pattern like there are 4 rows and 1st column contains only 1, 2nd column contains only 2, 3rd column contains only 3, 4th column contains only 4!
// Practice Question 7 : Create a pattern where it has three rows and 1 2 3 in first row, 4 5 6 in 2nd row and 7 8 9 in 3rd row!
// Practice Question 8 : Print the star pattern, where 1st row has 1 star, 2nd row has 2 stars and so on..
// Practice Question 9 : Print 1 one time in 1st row, 2 two times in 2nd row and so on....
// Practice Question 10 : Print 1 in 1st row, 2 3 in 2nd, 4 5 6 in 3rd and so on...
// Practice Question 11 : 1 in 1st row, 2 3 in 2nd row, 3 4 5 in 3rd row, 4 5 6 7 in 4th row and so on...
// Practice Question 12 : Print 1 in 1st row, 2 1 in 2nd row, 3 2 1 in 3rd row and so on...
// Practice Question 13 : Print ABCDE in each row as input by the user.
// Practice Question 14 : Print A three times in 1st row, B three times in 2nd row, C three times in 3rd row and so on...
// Practice Question 15 : Print A B C in every row as input by the user!
// Practice Question 16 : Print A B C and then D E F in the next line and so on...
// Practice Question 17 : Print A B C, B C D in next row, C D E in next row and so on...
// Practice Question 18 : Print A, B B then C C C and so on...
// Practice Question 19 : Print A, B C, D E F, G H I J and so on...
// Practice Question 20 : Print A, B C, D E F, G H I J and so on...
// Practice Question 21 : Print a pattern like D, C D, B C D, A B C D and so on...
// Practice Question 22 : Print this ___* in first row, __** in 2nd row, _***, in 3rd row and so on...
// Practice Question 23 : Print this **** in 1st row, ***_ in 2nd row, **__ in 3rd row and so on...
// Practice Question 24 : Print this ****, _***, __**, ___* and so on...

// Basic Maths, Bit-Manipulation + Logic Questions :
// Practice Question 25 : Subtract the product and sum of all the digits of an Integer!
// Practice Question 26 : Number of 1 Bits, find the number of 1 bits in the unsigned integer input by the user!
// Practice Question 27 : Decimal to Binary Conversion
// Practice Question 28 : Print all 32-bits of a binary number! (also applicable for converting a -ve number into a binary!)
// Practice Question 29 : Binary to Decimal Conversion
// Practice Question 30 : Reverse an Integer! but if it goes out of the range of int them print 0!
// Practice Question 31 : Complement of an Integer!
// Practice Question 32 : Power of 2, display yes if a number can be represented in form of power of 2, and if no then print no!
// Practice Question 33 : Power of 3, display yes if a number can be represented in form of power of 3, and if no then print no!
// Practice Question 34 : Power of 4, display yes if a number can be represented in form of power of 4, and if no then print no!

// Arrays basic to not-so-basic Questions :
// Practice Question 35 : Standard input/output using arrays!
// Practice Question 36 : Finding maximum and minimum elements in an Array!
// Practice Question 37 : Take input in an array and then find the sum of all of its elements!
// Practice Question 38 : Linear Search in an array! and return the index of the key!
// Practice Question 39 : Reverse an Array!
// Practice Question 40 : Swap Alternatively in an Array!
// Practice Question 41 : Check whether an array contains any unique element or not! and print that unique element!
// Practice Question 42 : Check whether an array contains any unique element or not! and print that unique element! (using maps)
// Practice Question 43 : Check whether an array contains 1 unique element or not, and print that unique element! or contains any odd duplicates (focus on 1 unique element)
// Practice Question 44 : You are given an array, and it contains each element between 1 -> n-1 at least once, there is a single integer value that present in the array twice, Your task is to find the duplicate value integer value present in the array! (2 methods)
// Practice Question 45 : Find intersection of two arrays!
// Practice Question 46 : Find all pairs of elements in an array such that the sum of each pair equals a given value S. The pairs should satisfy the following conditions : 1) Each pair should be sorted in ascending order. 2) The list of pairs should be sorted primarily by the first value of the pairs, and if two pairs have the same first value, they should be sorted by the second value.
// Practice Question 47 : Sort 0,1