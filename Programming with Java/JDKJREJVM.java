// -------------------------------------------------------------- JDK, JRE & JVM ------------------------------------------------------------------>
// The High-Level Relationship: JDK vs. JRE vs. JVM
// Think of them as a set of Russian nesting dolls : JVM (Java Virtual Machine): The engine. It executes Java bytecode and translates it into machine-specific instructions for your CPU. It is platform-dependent (Windows, Linux, and macOS each have their own specific JVM implementation). Contains Class Loaders, Interpreter, Compiler & Runtime Data Areas  
//                                                 : JRE (Java Runtime Environment): The car. It bundles the JVM together with standard class libraries (java.lang, java.util, etc.) and supporting files needed to run compiled applications.   
//                                                 : JDK (Java Development Kit): The full workshop/toolbox. It bundles the JRE along with developer tools like the compiler (javac), debugger (jdb), and archiver (jar) to write and build code.   

// JVM Internal Architecture
// When interviewers ask about JVM internals, they expect you to break down its architecture into three core subsystems:
// 1. Class Loader Subsystem
// 2. Runtime Data Areas (Memory Management)
// 3. Execution Engine

// -------------------------------------------------------------- Class Loader Subsystem ----------------------------------------------------------------->
// It involves three sub parts : Loading : Bootstrap Loader (CEO) | Platform Loader (Manager) | Application Loader (Clerk)
//                             : Linking : Verification (Structural check) | Preparation (Memory allocation for static) | Resolution (Symbolic -> Direct links)
//                             : Initialization : Executes static blocks | Assigns static variable values

// Loading :
// To understand the Java Class Loader, it helps to step away from the code for a moment. Think of the Java Virtual Machine (JVM) as a secured corporate office, and Class Loaders as the office assistants responsible for fetching files (your .class files) whenever a manager (the JVM) needs to execute a task
// The JVM doesn't load all your code into memory at once when a program starts. It loads classes dynamically on demand, only when they are first called. To do this without crashing, loading duplicates, or letting hackers inject malicious code, Java uses a strict hierarchy of built-in assistant loaders:
// The Chain of Command (The Hierarchy) : Before looking at the principles, you must understand who these loaders are. They are organized in a strict parent-child chain of command:
//                                      : Bootstrap Class Loader (The CEO) : The root loader. It is built directly into the JVM (written in C/C++). Its sole job is to load core, trusted Java files (like java.lang.Object or java.lang.String)
//                                      : Platform / Extension Class Loader (The Manager) : The child of the Bootstrap loader. It loads platform extension features and modules
//                                      : Application / System Class Loader (The Clerk) : The child of the Platform loader. This is the loader that actually looks at your code—the files you wrote and the external library JARs you added to your project's classpath

// Principle 1 : The Delegation Model (Passing the Buck) - Means "Always check with the boss before you do any work yourself."
//             : How It Works : When the JVM suddenly encounters a class in your code (e.g., UserService), it tells the Application Class Loader to fetch it. Instead of searching your folders, the Application loader immediately hands the request up to its parent, the Platform Class Loader. The Platform loader does the same thing and hands it up to the Bootstrap Class Loader.
//                            : The request goes all the way to the top before anyone actually looks for the file.
//             : The Bootstrap loader looks in the core Java files. If it finds it, it loads it. If not, it passes the request back down to the Platform loader.
//             : If the Platform loader can't find it, it passes it down to the Application loader.
//             : If the Application loader also can't find it in your project, the program crashes with a ClassNotFoundException.
//             : Why It Matters : Imagine a hacker writes a malicious class named java.lang.String designed to steal passwords, and includes it in your project's folders. When your code calls String, the Application loader asks the parent, which asks the Bootstrap loader. The Bootstrap loader says, "Oh, I have the official java.lang.String right here in the core Java libraries!" and loads the safe version. The hacker's malicious file is ignored entirely, keeping the application safe.

// Principle 2 : The Visibility Principle (One-Way Mirrors) - The Visibility Principle dictates that visibility only goes upwards, never downwards. A child loader can see what its parent has loaded, but a parent loader has absolutely no idea what its children have loaded.
//             : Detailed Scenario : If the Bootstrap Loader loads java.util.ArrayList, your custom application code (handled by the Application Loader) can easily use it because the child can see the parent's inventory.
//                                 : However, if the Application Loader loads a class you wrote called MyCustomReport, the Bootstrap Loader cannot see it. If you tried to force a core Java class loaded by the Bootstrap loader to directly call MyCustomReport, the JVM would throw an error because the parent cannot look down into the child's inventory.

// Principle 3 : The Uniqueness Principle (No Duplicates)
//             : The Uniqueness Principle ensures that a single class file is loaded exactly once within a given loader chain.
//             : Let's say your program uses java.util.HashMap in 50 different files. The very first time it is called, the request travels up to the Bootstrap Loader, which reads the file and loads it into the JVM's memory.
//             : The next 49 times your program uses a HashMap, the JVM doesn't waste time refetching or rebuilding it. Because of the Delegation Model, the loader checks the hierarchy first. The parent instantly says, "I already loaded that earlier, here is the existing class blueprint." This prevents the JVM from clogging up memory with duplicate blueprints of the exact same class.

// Solving Misconceptions & Thought Process :
// 1. Are these class loaders are classes? : Are they classes? Yes, the Platform and Application loaders are written in Java (BuiltinClassLoader subclasses). The Bootstrap loader is the only exception—it is native C/C++ code baked into the JVM core.
// 2. Do they follow Inheritance? : No. This is a massive interview trap. They do not use object-oriented inheritance (e.g., Application does not extend Platform). Instead, they use Composition (Delegation).
// 3. When you create an instance of the Application Loader, it holds a reference to the Platform Loader in a variable called parent. It is a logical parent-child chain, not class inheritance.
// 4. You mentioned that loading is 1/3rd of the job, and then we move on to linking and initialization. This is partially correct, but remember that this happens class by class, on-demand (lazily).
// 5. The JVM does not load, link, and initialize all classes in your project when the program starts. It does it dynamically. If your code calls UserService on line 10, the JVM runs UserService through the entire Loading -> Linking -> Initialization pipeline right then and there. If your code never hits line 50 which calls PaymentService, then PaymentService is never loaded, linked, or initialized at all.

// Linking :
// In the Loading phase, the loader simply grabs the raw binary data of the .class file and brings it into the JVM. At this point, it is just a raw stream of bytes sitting in memory. The JVM doesn't trust it yet, doesn't know how much memory it needs, and doesn't know how it connects to other classes.
// Linking is the intermediate factory phase that transforms this raw byte data into a secure, structured, and fully wired component ready for execution. It happens in three strict, sequential steps: Verification, Preparation, and Resolution.
// Step 1 : Verification (The Security Guard & Quality Check)
//        : This is the most critical step for JVM security. Java ensures that the binary data of the class file adheres strictly to the specifications of the Java Virtual Machine. It prevents poorly compiled or maliciously altered code from crashing the system.
//        : What It Checks : The Magic Number : Every valid Java class file must begin with the 4-byte hexadecimal magic number 0xCAFEBABE. If you open a .class file in a text editor and change even one character, the verifier reads the first 4 bytes, realizes it isn't 0xCAFEBABE, and rejects it immediately.
//                         : Structural Correctness : It ensures that loops have proper exit points, methods match their declarations, and variables are always initialized before they are read.
//                         : Stack Map & Type Safety : It checks that code doesn't attempt illegal type casting (e.g., trying to treat an int as an object reference or accessing memory directly like in C++).
//                         : If Verification fails : The JVM throws a java.lang.VerifyError and halts.

// Step 2 : Preparation (The Memory Allocator)
//        : Once the JVM knows the class file is safe, it looks at the static fields (class-level variables) defined inside that class. During Preparation, the JVM allocates memory space in the Method Area for these static variables and assigns them their default values based on their data type, not the values you wrote in the code.

// Step 3 : Resolution (The Linker / Wireman)
//        : When a class is compiled, it doesn't contain hardcoded memory addresses pointing to other classes or methods. Instead, it contains Symbolic References (basically text strings that state the name of the class, method, or variable it wants to interact with).
//        : Resolution is the process where the JVM navigates the Runtime Constant Pool and replaces these logical symbolic text names with Direct References (actual, physical memory pointers).
//        : Once Linking wraps up, the JVM moves to the final phase of the Subsystem: Initialization, where those static variables (0, false, null) finally get their real values (5000, true, "Google").

// Initialization :
// How It Works : During this phase, the JVM executes all static initializers. This includes two things - 1. The explicit assignment of values to your static variables. 
//                                                                                                      - 2. The execution of any code inside static { ... } blocks.
//              : Under the hood, the Java compiler automatically collects all static variable assignments and static initialization blocks from your code and merges them into a single, hidden system method called <clinit> (short for Class Initialization). During this phase, the JVM simply executes this hidden <clinit> method exactly once.

// The Strict Rules of Initialization : Interviewers love testing candidates on when and how initialization triggers because it operates on a strict lazy on-demand schedule.
//                                    : Rule 1 : It Only Triggers on "Active Use" - A class will never be initialized unless your application actively interacts with it for the first time.
//                                             : Active use is strictly defined as : Creating a new instance of the class.
//                                                                                 : Invoking a static method defined inside that class.
//                                                                                 : Accessing or assigning a static field (except for compile-time constants).
//                                                                                 : Running the class as the main entry point of the program.
//                                             : If you merely declare a variable blueprint like SetupConfig myConfig; without assigning anything to it, or if you reference SetupConfig.class, it counts as Passive Use. The class will be loaded and linked, but Initialization will be skipped entirely.
//                                    : Rule 2 : Parents Initialize First : If a child class triggers initialization, the JVM stops and checks if its parent class has been initialized yet. If not, the parent class initializes first.
//                                    : Rule 3 : It is Thread-Safe and Runs Exactly Once
//                                             : If 50 threads simultaneously attempt to access a class for the very first time, the JVM uses internal locks to ensure that only one thread executes the <clinit> initialization phase. The other 49 threads wait patiently until initialization wraps up, and then they safely share the initialized class structure.

// -------------------------------------------------------------- Runtime Data Areas (Memory Management) ----------------------------------------------------------------->
// Once the Class Loader Subsystem finishes loading, linking, and initializing a class, it needs a place to store those blueprints, variables, and code instructions. The JVM allocates a large block of memory from your computer's RAM and divides it into five distinct zones.
// The Architecture Breakdown : The JVM divides these five areas into two categories: Shared Areas (accessible by all threads in your application) and Thread-Private Areas (allocated fresh for every single individual thread and destroyed when that thread stops).
//                            : Shared (App Wide) : Method Area & Heap Area
//                            : Thread Private Area (Per Thread) : JVM Stack, PC Register Area & Mative Method Stack

// Category 1 : Shared Memory Areas (The Common Areas)
//            : These areas are created when the JVM starts up and are destroyed only when the application completely shuts down. Every thread running in your program shares this space.
//            : Method Area : The Method Area is a global repository that stores all the class-level blueprints. When a class passes through the Class Loader Subsystem, its structure is permanently written here.
//                          : What it stores : Class structural metadata (field names, method names, modifiers), the Runtime Constant Pool (literal strings, method references), and all static variables (like the maxConnections = 100 we initialized earlier).
//            : Heap Area : The Heap Area is the largest memory zone in the JVM. It is the central storage location where all objects and arrays live. Every time you write the keyword new in Java, memory is instantly carved out of the Heap.
//                        : What it stores : Actual instances of classes (UserService user = new UserService()). Even if an object is created inside a short method, the object itself sits in the Heap. The Garbage Collector (GC) constantly patrols this area to clear out objects that are no longer being used.

// Category 2 : Thread-Private Memory Areas (The Personal Workspace)
//            : Every time a new thread is spawned (like a background worker or a new user request hitting a server), the JVM builds a brand-new set of these three areas exclusively for that thread. No other thread can look inside or access them.
//            : JVM Stack : The JVM Stack controls method execution. It tracks exactly which methods are currently running and stores temporary data. Every single time a thread calls a method, a new Stack Frame (a temporary memory block) is pushed onto the top of the stack. When the method completes, its frame is popped off and destroyed.
//                        : What it stores : Local variables (variables declared inside methods, like int primitiveCount = 5) and references pointing to objects sitting in the Heap.
//            : Program Counter (PC) Register (The Bookmark) : A thread can only execute one machine instruction at a time. The PC Register is a tiny memory slot that stores the memory address of the current JVM bytecode instruction being executed by that thread.
//                                                           : Why it matters: If the CPU decides to pause Thread A to let Thread B do some work (Context Switching), the PC Register acts as a bookmark. When the CPU returns to Thread A, it reads the PC Register to know exactly which line of bytecode to execute next.
//            : Native Method Stack : Java code is compiled into bytecode, but sometimes Java needs to interact with low-level operating system code written in C, C++, or Assembly (using Java Native Interface or JNI). The Native Method Stack functions exactly like the standard JVM Stack, but it is reserved exclusively for tracking these low-level native OS methods.

// -------------------------------------------------------------- Execution Engine ----------------------------------------------------------------->
// Once the Class Loader Subsystem has successfully loaded your classes, and the Runtime Data Areas have mapped out space in the RAM, your application is ready to run. However, there is a fundamental problem: Your computer's CPU does not understand Java bytecode. CPUs only understand native machine code (binary 0s and 1s specific to your operating system, like Windows x64 or Mac Apple Silicon).
// The Execution Engine is the engine room of the JVM. Its sole job is to take the compiled bytecode sitting in the memory areas, read it instruction by instruction, execute it, and translate it into native machine code that your computer's CPU can run at lightning speed.

// The Three Core Components : Interpreter, JIT Compiler & Garbage Collector
// The Interpreter (The Instant Translator) : The Interpreter reads the bytecode line by line and executes it on the fly.
//                                          : How It Works : Think of the Interpreter like a live human translator at a global conference. As soon as a bytecode instruction arrives, it instantly translates it to machine code and hands it to the CPU.
//                                          : Pros & Cons : It starts up instantly because it doesn't need to preprocess anything. However, if a specific loop runs 10,000 times, the interpreter will waste time translating the exact same lines of code 10,000 times. This makes it slow for heavy repetitive processing.

// The JIT Compiler : To fix the interpreter's speed bottleneck, Java introduces the JIT Compiler.
//                  : How it works : While the Interpreter is running the code, a sub-component called the Profiler monitors the application looking for "Hot Spots" (blocks of code, loops, or methods that are executed frequently).
//                  : The Optimization : Once a method crosses a certain execution threshold, the JIT compiler steps in. It takes that entire "hot" method, compiles it all at once into optimized native machine code, and saves it directly in a special memory area called the Code Cache. The next time that method is called, the JVM completely bypasses the interpreter and runs the high-speed native code directly.

// The Garbage Collector (The Cleanup Crew) : Though it's a massive topic on its own, the Garbage Collector (GC) is officially a part of the Execution Engine. It constantly runs in the background to track objects sitting inside the Heap Area. When it detects that an object no longer has any active references pointing to it from the JVM Stack, it deletes the object and frees up that RAM for future allocations.

// -------------------------------------------------------------- End to End Flow of JVM ----------------------------------------------------------------->
// You have now completely mapped the entire internal universe of Java. Here is exactly what happens when you hit "Run" on a program:
// The Class Loader Subsystem : Grabs your .class file, verifies its safety structure (0xCAFEBABE), allocates space for static variables, and resolves symbolic links.
// The Runtime Data Areas : Organizes the computer's RAM. The Method Area holds the class blueprints, the Heap holds your objects, and the JVM Stack opens up individual execution channels for your running threads.
// The Execution Engine : The Interpreter jumps into action executing code instantly line-by-line, the JIT Compiler accelerates your heavy loops into native computer code, and the Garbage Collector keeps the memory clean.