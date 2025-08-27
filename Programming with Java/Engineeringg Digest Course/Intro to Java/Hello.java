// ------------------------------------------------------- Basics & Introduction of Java --------------------------------------------------------->
// Basics of Java : Java is a high-level, object-oriented programming language created by Sun Microsystems in the mid-1990s (now owned by Oracle). Its famous slogan is : “Write once, run anywhere.”
//                : 

// Why Study Java?
// Java isn’t just a language—it’s a platform.
// Here’s why it’s worth your time : Platform Independence : Java code runs on any device with a Java Virtual Machine (JVM). Write once, run anywhere.
//                                 : Strong Community & Ecosystem : Tons of libraries, frameworks (like Spring), and tools (like VS Code, IntelliJ) make development easier.
//                                 : Used Everywhere : From Android apps and enterprise systems to web servers and embedded devices.
//                                 : Object-Oriented : Java teaches you to think in terms of objects and classes—great for building scalable, modular software.
//                                 : Robust & Secure : Java has built-in features to handle errors gracefully and protect against vulnerabilities.

// How Java Works : Java’s magic lies in its two-phase process: compilation and execution. Unlike C/C++, Java doesn’t compile directly to machine code. Instead, it compiles to bytecode, which runs on the Java Virtual Machine (JVM). This is what makes Java platform-independent.
//                : Full Workflow : Suppose, you write a simple Hello World! code in Java. Now lets understanding what happens behind the scenes.
//                                : Step 1 : Writing the Code : You write your code in a .java file.
//                                                            : The filename must match the public class name. So if your class is Hello, the file must be Hello.java.
//                                : Step 2 : Compilation (javac) : You run "javac Hello.java"
//                                                               : This uses the Java compiler to convert your human-readable code into bytecode.
//                                                               : Output : "Hello.class", a file containing platform-independent bytecode.
//                                : Step 3 : Execution (java) : You run "java Hello"
//                                                            : This launches the Java Virtual Machine (JVM).
//                                                            : The JVM loads Hello.class, verifies the bytecode, and executes it.
//                : What Makes Java Platform-Independent : The .class file (bytecode) is not tied to any OS.
//                                                       : The JVM acts as a translator between the bytecode & the underlying machine.
//                                                       : As long as a system has a JVM, it can run your Java program - whether it's windows, linux, macOS, or even android.

// Java Components : Java isn’t just a language—it’s an entire ecosystem. Here are the most important components, grouped by their role in development and execution.
//                 : JDK (Java Development Kit) : The JDK is the full toolkit for Java developers. It includes everything you need to write, compile, debug, and package Java programs.
//                                              : What’s Inside : javac – The Java compiler that converts .java files into .class bytecode.
//                                                              : java – The launcher that runs .class files using the JVM
//                                                              : javadoc – Generates documentation from comments in your code
//                                                              : jar – Packages compiled classes into .jar files (Java Archives)
//                                                              : jshell – An interactive REPL for testing Java snippets (introduced in Java 9)
//                                              : How It Works : You write code → use javac to compile → use java to run → optionally use jar to bundle your app.
//                 : JRE (Java Runtime Environment) : The JRE is the minimum required to run Java programs. It includes the JVM and core libraries but not the compiler.
//                                                  : What’s Inside : JVM – Executes bytecode
//                                                                  : Java Class Libraries – Prebuilt classes for I/O, networking, data structures, etc.
//                                                  : How It Works : When you run java Hello, the JRE loads Hello.class, starts the JVM, and executes your code.
//                 : JVM (Java Virtual Machine) : The JVM is the heart of Java’s platform independence. It’s a virtual machine that runs bytecode on any OS.
//                                              : What It Does : Loads classes from the classpath
//                                                             : Verifies bytecode for safety
//                                                             : Interprets or JIT-compiles bytecode into native machine code
//                                                             : Manages memory via garbage collection
//                                                             : Handles exceptions and threading
//                                              : How It Works : You run java Hello → JVM loads Hello.class → executes main() → manages everything behind the scenes.
//                 : Bytecode : What It Is : Bytecode is the intermediate code generated by javac. It’s not human-readable, but it’s portable across platforms.
//                            : What It Looks Like : Stored in .class files. You don’t write bytecode directly—it’s generated from your .java source.
//                            : How It Works : The JVM reads bytecode and either interprets it line-by-line or compiles it to native code using a JIT compiler.
//                 : Java API (Standard Library) : What It Is : A massive collection of prebuilt classes and interfaces for common tasks.
//                                               : Key Packages : java.lang – Core language features (String, Math, Object)
//                                                              : java.util – Collections, dates, random numbers
//                                                              : java.io – File and stream I/O
//                                                              : java.net – Networking
//                                                              : java.sql – Database access
//                                                              : java.time – Modern date/time API
//                                               : How It Works : You import these packages and use them directly in your code : "import java.util.ArrayList; ArrayList<String> names = new ArrayList<>();"
//                 : Java Packages : What It Is : Packages are like folders—they organize your classes and prevent naming conflicts.
//                                 : How They’re Used : "package com.utkarsh.myapp; public class Hello { }"
//                                                    : The file must be in a folder structure matching the package name: com/utkarsh/myapp/Hello.java
//                                 : How It Works : Packages help modularize your code. You can import other packages using import.
//                 : JAR Files (Java Archives) : What They Are : JAR files bundle multiple .class files and resources into a single compressed file.
//                                             : How They’re Used : "jar cfe MyApp.jar com.utkarsh.Main com/utkarsh/*.class"
//                                                                : "java -jar MyApp.jar"
//                                             : How It Works : JARs simplify distribution and deployment. You can also include libraries inside them.
//                 : JShell (Java Shell) : What It Is : An interactive tool introduced in Java 9 for testing Java code snippets without writing full classes.
//                                       : Example : Go in the command prompt and write "jshell".
//                                                 : jshell
//                                                 : jshell> int x = 5;
//                                                 : jshell> System.out.println(x * 2);
//                                       : How It Works : Great for learning, experimenting, and debugging small pieces of logic.

// Java Naming Conventions : Naming conventions make your code readable, consistent, and professional. Java has well-defined rules for naming different elements:
//                         : Package Names : All lowercase
//                                         : Often use reverse domain names (e.g., com.utkarsh.myapp)
//                                         : Helps organize classes and avoid conflicts
//                                         : Example : package com.utkarsh.myapp;
//                         : Class and Interface Names : PascalCase (each word starts with a capital letter)
//                                                     : Should be nouns (e.g., Student, BankAccount, DataProcessor)
//                         : Method Names : camelCase (first word lowercase, subsequent words capitalized)
//                                        : Should be verbs (e.g., calculateTotal, printReport)
//                         : Variable Names : camelCase
//                                          : Should be descriptive and meaningful
//                         : Constant Names : ALL_CAPS_WITH_UNDERSCORES
//                                          : Used for static final variables. Example : "public static final int MAX_USERS = 100;"
//                         : File Names : Must match the public class name exactly
//                                      : Case-sensitive on Linux/macOS

// First code in Java!
class Hello {
    public static void main(String[] args) {
        System.out.println("Hello World!");
    }
}
// Understanding the code : "class Hello {}" : class : This keyword is used to define a class, which is a blueprint for objects. Think of it like a container that holds your code.
//                                           : Hello : This is the name of the class. You can name it anything (following naming rules), but it's common to use something meaningful.
//                                           : {} : This curly brace opens & close the body of the class. Everything inside belongs to the Hello class.
//                                           : Note : In Java, every program must have at least one class. Even the simplest program like this needs a class to run.
//                        : "public static void main(String[] args) {}" : This is the entry point of any Java program (like int main() in C/C++). Let’s break it down word by word.
//                                                                      : public : This means the method is accessible from anywhere. The JVM needs to access this method to start your program.
//                                                                      : static : This means the method belongs to the class itself, not to an object. So you don’t need to create an object to run it.
//                                                                               : Like to compile & execute the code, we can simple use the class_name.main to execute, we don't need to create objects of the class if we have static keyword attached.
//                                                                      : void : This means the method doesn’t return any value. It just runs the code inside it.
//                                                                      : main : This is the name of the method. The JVM looks for this exact name to start execution.
//                                                                      : (String[] args) : This is a way to pass command-line arguments to your program. You can ignore it for now, but it’s useful later.
//                                                                                        : Example : After compilation, you can simply write "java class_name arg1 arg2".
//                        : "System.out.println("Hello World!");" : This line prints the text inside it, to the console.
//                                                                : System : A built-in class that gives access to system-level stuff like input/output.
//                                                                : out : A static member of System that represents the standard output stream (usually your console).
//                                                                : println() : A method that prints a line of text and then moves to the next line.
//                                                                : "Hello World!" : The actual text you want to print. This is called a string literal.
//                                                                : Note : This is the classic first message every programmer prints when learning a new language. It’s like saying “Hi, I’m here!”

// Case Studies!
// Case 1 : Scenario : You can write "class Hello { public static void main(String[] args) { System.out.println("Hello, Utkarsh!"); } }".
//                   : And save it as Hello.java, it will compile and run just fine, even though the class is not marked public.
//        : So Why Do We Say “Public Class Must Match Filename”? : Here’s the actual rule - If a class is declared public, then the filename must match the class name exactly (case-sensitive).
//        : Why Does This Rule Exist? : Java uses the filename to locate the public class during compilation. It’s a way to enforce clarity and consistency in large projects.
//                                    : In a file with multiple classes, only one can be public, and it must match the filename.
//                                    : If no class is public, the compiler doesn’t care what the filename is.
//        : Best Practice : Even though Java allows non-public classes to live in any file, it’s strongly recommended to : Use public for your main class
//                                                                                                                       : Match the filename to the public class name
//                                                                                                                       : Keep one top-level class per file for clarity and maintainability.

// Case 2 : Scenario : Multiple Classes in One File: What Happens? : Yes, you can absolutely avoid using public for all classes in a file—even if there are multiple classes. But there are rules and best practices you should understand.
//        : Rules : Rule #1 : Only One public Class Allowed Per File.
//                          : If you declare a class as public, then : The filename must match the public class name exactly (case-sensitive).
//                                                                   : You cannot have more than one public class in the same .java file.
//                : Rule #2 : No public Class? Filename Can Be Anything : If none of the classes are declared public, then the filename can be anything (e.g., Zoo.java, Test.java, Main.java).
//                                                                      : You can still compile and run the file, but you must run the class that contains main().
//        : How Java Handles This Internally : When you compile a .java file, the Java compiler creates a separate .class file for each class inside it.
//                                           : Zoo.java → Lion.class, Tiger.class. And you can run any class that has a main() method, regardless of filename.
//        : Why Use public at All? : Declaring a class public makes it accessible from other packages. It’s essential when you’re building reusable libraries, you want the class to be the entry point (main() method) & You’re following clean architecture in larger projects.

// Case 3 : Scenario : How Java Handles main() Methods in a File with Multiple Classes
//                   : Unlike C/C++, Java allows multiple classes in a single file, and each class can have its own main() method. But here's the key difference : Java does not automatically choose which main() to run. You must explicitly tell it which class to execute.
//        : How to Run the Correct main() Method : Suppose you have this file : File name : MultiMain.java
//                                                                            : "class Alpha { public static void main(String[] args) { System.out.println("Alpha main"); } }"
//                                                                            : "class Beta { public static void main(String[] args) { System.out.println("Beta main"); } }"
//                                               : After compiling : "javac MultiMain.java"
//                                                                 : You get two .class files, Alpha.class & Beta.class.
//                                                                 : To run Alpha's main method : Write : java Alpha
//                                                                 : To run Beta's main method : Write : java Beta
//                                                                 : Note : You choose which class to run by specifying its name.
//        : Is Only One main() Allowed per File? : Nope! Java allows multiple main() methods in the same file, each inside a different class. This is unlike C/C++, where :
//                                               : You can only have one int main() per translation unit (i.e., .c or .cpp file)
//                                               : The compiler and linker expect a single entry point
//                                               : Java, being object-oriented and class-based, treats each class as a potential entry point.
//        : Best Practices : While Java allows multiple main() methods, here’s what developers usually do : One main() per file	- Keeps things simple and predictable
//                                                                                                        : Use public class for the main class - Ensures filename matches and improves clarity
//                                                                                                        : Use helper classes without main() - Keeps logic modular and reusable
//                                                                                                        : Avoid multiple main() methods unless testing	Prevents confusion during execution
//        : Testing Multiple main()s : Having multiple main() methods is sometimes useful for testing individual components. But in production code, you'd typically have : One main() method as the entry point & Other classes with methods that are called from main().

// Case 4 : Scenario : Clearing some confusion between javac, java, and how Code Runner fits into the picture.
//        : Important commands : javac ClassName.java → compiles the .java file into .class bytecode
//                             : java ClassName → runs the compiled .class file (must contain main())
//                             : But here's the twist : You don’t compile a specific class using javac ClassName—you compile the file, not the class inside it.
//        : Now, If your file is MultiMain.java and contains multiple classes (Alpha, Beta, etc.), you run : "javac MultiMain.java"
//        : Then run the class you want : "java Alpha" & "java Beta"
//                                      : You don’t use javac Alpha or javac Beta—that would be incorrect unless those are filenames.
//        : Now, About VS Code and Code Runner : Code Runner is super convenient, but it has limitations when dealing with multiple classes with main() methods.
//                                             : Here's how it behaves by default : It compiles and runs the entire file
//                                                                                : Then it tries to run the class whose name matches the filename (if it's public)
//                                                                                : If no class is public, it may default to the first class with a main() method it finds
//                                                                                : This means : If you have multiple classes with main() methods, Code Runner might not run the one you expect.
//                                                                                             : You can’t choose which class to run unless you configure it.
//        : Option with VS Code : Option 1 : Use Terminal Manually : You can open the integrated terminal and do it the classic way : "javac MultiMain.java" & "java Beta"
//                                                                : This gives you full control over which class runs.
//                              : Option 2 : Customize Code Runner : You can tweak Code Runner’s behavior in settings.json : ""code-runner.executorMap": { "java": "cd $dir && javac $fileName && java ClassNameYouWant" }"
//                                                                 : Replace ClassNameYouWant with the actual class name you want to run. But this is static—you’d have to change it every time you want to run a different class.
//                              : Option 3 : Use VS Code’s Java Extension Pack : If you install the Java Extension Pack, you get : Better project structure, IntelliSense, Right-click → “Run Java” on the specific class file & No need to rely on Code Runner
//                                         : This is the recommended way for serious Java development in VS Code.

// Overall, The execution of Java programs happens as follows :
// During Compilation (javac) : Java looks for : A Public class (if any) - If your file contains a public class, the filename must match that class name exactly. If it doesn’t match, the compiler throws an error.
//                            : Other classes (non-public) : You can have multiple classes in one file. If none are public, the filename can be anything. All classes will be compiled into separate .class files.
// During Execution (java ClassName) : Java doesn’t care about the filename or whether the class is public.
//                                   : It only looks for : A class with a valid main() method : "public static void main(String[] args)" - This is the entry point of your program.
//                                                       : So when you run : "java Hello" - Java looks for a compiled file named Hello.class, and inside it, a method named main() with the exact signature above.

// ------------------------------------------------------- Keep updating as per Knowledge --------------------------------------------------------->