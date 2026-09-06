// Data Structures and Algorithms
// Data Structures : Data structures are systematic ways to organize and store data in a computer's main memory.
//                 : So that it can be used efficiently. They are the building blocks for designing efficient algorithms. Examples: Arrays, Stacks, Linked Lists, Queues, Trees, Graphs, Hash Tables.

// Algorithms : An algorithm is a finite sequence of well-defined instructions to solve a specific problem.
//            : Algorithms are designed using data structures. Example: Sorting an array using Bubble Sort or Merge Sort.

// Database : A database is an organized collection of structured information stored electronically, usually in permanent storage (like a hard drive), designed for efficient retrieval, modification, and management.
//          : It allows CRUD operations: Create, Read, Update, Delete. Example: MySQL, PostgreSQL, MongoDB.

// Data Warehouse : A data warehouse is a central repository designed to store **large volumes of historical and analytical data**.
//                : It helps in decision-making and business intelligence. The data often comes from multiple sources (including operational databases).
//                : Legacy data refers to historical data that is not used in day-to-day operations but is valuable for analytics. Example: Facebook may store data such as how many times a user viewed a particular profile or liked a post.
//                : While not useful immediately, this data helps in trend analysis, building recommendation engines, and A/B testing.

// Big Data : Big Data refers to extremely large and complex datasets that cannot be processed or analyzed using traditional tools or software. It is characterized by the **3 V's**: Volume (massive size), Velocity (fast generation), and Variety (structured, semi-structured, unstructured).
//          : Example : Building a search engine like Google involves storing and processing petabytes of data from websites, user behavior, etc.
//          : Big Data tools and frameworks: Hadoop, Spark, Kafka, Hive.

// ---------------------------------------------------------- LECTURE 1 - Basics --------------------------------------------------------------------------------------------------------->
// You can learn about Fllowcharts, Pseudocode, and Algorithms as per the needs later.

// C++ Essentials & Compiler Basics : Namespace (using namespace std) : What it is : C++ uses namespaces to group related functions, classes, and variables to avoid naming conflicts.
//                                                                    : Why use it : By declaring using namespace std, you tell the compiler to look into the standard (std) namespace by default.
//                                                                    : Difference : With it - You can directly write cout << "Hello"; 
//                                                                                 : Without it - You must explicitly specify the namespace using the scope resolution operator: std::cout << "Hello";
//                                  : Understanding Errors : The compiler translates code into machine language and acts as your first line of defense against bugs:
//                                                         : Compile-Time Errors : Syntax mistakes caught during compilation (e.g., missing semicolons, type mismatches).
//                                                         : Runtime Errors : Logical errors or crashes that happen during execution (e.g., division by zero, segmentation faults).

// Compilation Pipeline, From .cpp to .exe : When you hit run, your C++ source code goes through four distinct stages to become an executable machine-level file:
//                                         : Preprocessor : Processes directives starting with # (e.g., #include fetches header files, #define expands macros).
//                                                        : Output : Generates a preprocessed source file (.i or .ii).
//                                         : Compilation : Checks for syntax errors and translates the high-level preprocessed code into assembly instructions specific to the target architecture.
//                                                       : Output : Generates an assembly code file (.s).
//                                         : Assembler : Translates the assembly code into binary machine language instructions (machine code).
//                                                     : Output : Generates an object file (.o or .obj).
//                                         : Linker : Combines your object file with standard library object files and any other external dependencies to produce the final executable.
//                                                  : Output : Generates the final executable file (.exe on Windows).

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

// All the base data types : int, float, char, bool, double, void, short (internally "short int"), long (internally "long int"), long long (internally "long long int") & long double.
// Other than these data types, there are some type modifiers : signed, unsigned, short, long, long long.
//                                                            : Modifiers cannot work stand alone, they internally uses int data type by default!
//                                                            : Base types which can use type modifiers : int, char & double.
// Overall, C++ has base data types like int, char, float, double and all. It also has some type modifiers like signed, unsigned and all, Some modifeirs like short and long can be used without specifying "int", which makes them seem like standalone types, but internally they still refer to modified integer types.

// "const" keyword in C++ : The const keyword is used to express that something should not be modified through a particular name/reference/pointer.
//                        : The exact meaning depends on where const is placed.

// Use case 1 : Constant Variable 
const int MAX_VALUE = 100;
int main() {
    // MAX_VALUE = 200; // Error
    std::cout << MAX_VALUE << std::endl;
}

// Use case 2 : Pointer to Constant Data
//            : const char* means : message is a pointer to const char data.
void printMessage(const char* message) {
    message = "New message"; // Allowed
    // message[0] = "Random" // Not Allowed
    printf("%s\n", message);
}

// Use case 3 : Constant Pointer
//            : pointer itself is constant. It cannot be changed to point somewhere else.
void printMessage(char* const message) {
    // message = "New message"; // Not Allowed
    message[0] = "Random" // Allowed
    printf("%s\n", message);
}

// Use case 4 : Const member function
//            : A non-const member function generally cannot be called on a const object
class MyClass {
private:
    int value;

public:
    MyClass(int val) : value(val) {}

    void print() const {
        // value = 100 // Not Allowed
        std::cout << "Value: " << value << std::endl;
    }
};

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

// ---------------------------------------------------------- LECTURE 3 - Basic Maths --------------------------------------------------------------------------------------------------------->
// Refer Maths Based Questions CPP File for all maths based problems.

// ---------------------------------------------------------- LECTURE 4 - Pattern Making --------------------------------------------------------------------------------------------------------->
// Refer Pattern Based Questions CPP File for all Pattern based problems.

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
        for (int i = 0; i <= 5; ++i) {
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

// ---------------------------------------------------------- LECTURE 6 - Decimal to Binary & Binary to Decimal --------------------------------------------------------------------------------------------------------->
// All the problems and solutions are tranferred to the Maths Based Questions CPP File, refer it.

// ---------------------------------------------------------- LECTURE 7 - Leetcode Questions --------------------------------------------------------------------------------------------------------->
// All the problems and solutions are tranferred to the Maths Based Questions CPP File, refer it.

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

// All the problems and solutions are tranferred to the Maths Based Questions CPP File, refer it. 

// ---------------------------------------------------------- LECTURE 10 - Arrays Question (Leetcode/CodeStudio) --------------------------------------------------------------------------------------------------------->
// All the problems and solutions are tranferred to the Maths Based Questions CPP File, refer it. 

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
//                : Replacing Magic Numbers : Instead of using raw numbers like 404 for HTTP errors, you can use descriptive names
#include <stdio.h>

enum Day {
    Monday,
    Tuesday,
    Wednesday,
    Thursday,
    Friday,
    Saturday,
    Sunday
}; // Has a global scope!

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

// ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------>