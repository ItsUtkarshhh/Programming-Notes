// ------------------------------------------------------- Data Types in Java --------------------------------------------------------->
// Data Types in Java : Primitive & Non-Primitive!
// Primitive Data Types : In Java, primitive data types are the most basic types of data. They are not objects, and they store simple values directly in memory. Java has 8 primitive types, each designed for a specific kind of data.
//                      : int – Integer : Stores whole numbers (positive, negative, or zero).
//                                      : Size : 4 bytes (32 bits)
//                                      : Range : –2,147,483,648 to 2,147,483,647
//                      : long – Large Integer : For very large whole numbers
//                                             : Size : 8 bytes (64 bits)
//                                             : Range : –9 quintillion to +9 quintillion
//                                             : Must add L at the end of the value
//                      : short – Small Integer : Smaller than int, used to save memory
//                                              : Size : 2 bytes (16 bits)
//                                              : Range : –32,768 to 32,767
//                      : byte – Tiny Integer : Smallest integer type
//                                            : Size : 1 byte (8 bits)
//                                            : Range : –128 to 127
//                                            : Often used for raw data (e.g., file streams)
//                      : float – Decimal Number (Single Precision) : Stores fractional numbers
//                                                                  : Size : 4 bytes (32 bits)
//                                                                  : Precision : ~6–7 decimal digits
//                                                                  : Must add f at the end of the value
//                      : double – Decimal Number (Double Precision) : More precise than float
//                                                                   : Size : 8 bytes (64 bits)
//                                                                   : Precision : ~15 decimal digits
//                                                                   : Default type for decimals
//                      : char – Single Character : Stores a single Unicode character
//                                                : Size : 2 bytes (16 bits)
//                                                : Enclosed in single quotes ' '
//                      : boolean – True or False : Stores logical values
//                                                : Size : 1 bit (conceptually)
//                                                : Only two values : true or false

// Type Casting : Typecasting means converting one data type into another.
//              : Java supports two kinds : Widening (Implicit) Casting : Automatically done by Java & converts smaller → larger type (no data loss)
//                                        : Narrowing (Explicit) Casting : Must be done manually & converts larger → smaller type (possible data loss)
//              : Key Consideration : Precision Loss : Narrowing can truncate decimals or overflow values.
//                                  : Syntax : Use parentheses for explicit casting: (targetType) value.
//                                  : Characters & Numbers : char can be cast to/from int (Unicode values)

// ------------------------------------------------------- Variables in Java --------------------------------------------------------->
// Naming Conventions for Variables!
// General Rules (Enforced by Java) : These are syntax rules—break them and your code won’t compile!
//                                  : Must start with a letter, $, or _
//                                  : Can contain letters, digits, $, and _
//                                  : Cannot start with a digit
//                                  : Cannot use Java reserved keywords (int, class, static, etc.)

// Best Practices (Recommended Conventions) : Use camelCase
//                                          : Be descriptive but concise
//                                          : Avoid underscores and dollar signs
//                                          : Use meaningful context
//                                          : Boolean variables should sound like yes/no questions

// ------------------------------------------------------- Operators in Java --------------------------------------------------------->
// Types of Operators : Arithmatic Operator
//                    : Assignment Operator
//                    : Relational Operator
//                    : Logical Operator
//                    : Bitwise Operator
//                    : Increament
//                    : Decreament
//                    : Ternary

// Rest, follow operator rrecedence & rules, while working and analysing

// ------------------------------------------------------- Println, Print, Printf in Java --------------------------------------------------------->
// Brief Description : These three are your go-to methods for displaying output in Java.
//                   : They all belong to the System.out class, and each has its own style and use case.

// "System.out.println()" : Prints text to the console and moves to a new line afterward.
// "System.out.print()" : Prints text to the console without moving to a new line.
// "System.out.printf()" : Prints formatted text using placeholders—great for numbers, dates, and alignment. Same as we used to do in C Language.
//                       : Format Specifier are needed : %d - Integer - Prints whole numbers - 42
//                                                     : %5d - Integer - Right-align in 5 spaces - 42
//                                                     : %-5d - Integer - Left-align in 5 spaces - 42
//                                                     : %x/%X - Integer - Hexadecimal (lower/upper case) - 2a / 2A
//                                                     : %o - Integer - Octal format - 52
//                                                     : %f - Float/Double - Default 6 decimal places - 3.141593
//                                                     : %.2f - Float/Double - Rounded to 2 decimal places - 3.14
//                                                     : %8.2f - Float/Double - Right-align, 8 spaces, 2 decimals - 123.46
//                                                     : %e / %E - Float/Double	Scientific notation - 1.23e+02 / 1.23E+02
//                                                     : %s	String - Prints text - Utkarsh
//                                                     : %10s - String - Right-align in 10 spaces - Utkarsh
//                                                     : %-10s - String - Left-align in 10 spaces - Utkarsh
//                                                     : %c - Character - Prints a single character - A
//                                                     : %b - Boolean - Prints true or false - true
//                                                     : %n - Line Break - Platform-independent new line - (moves to next line)
//                                                     : %% - Literal % - Prints a percent symbol - %

// Extras : "Locale" : A Locale object represents a specific geographical, political, or cultural region. It helps Java adapt its output to match local conventions.
//        : Common usage : Formatting numbers and currency
//                       : Formatting dates and times
//                       : Displaying language-specific messages
//                       : Sorting text based on local rules
//        : Can explore it further, when needed.

// ------------------------------------------------------- Println, Print, Printf in Java --------------------------------------------------------->