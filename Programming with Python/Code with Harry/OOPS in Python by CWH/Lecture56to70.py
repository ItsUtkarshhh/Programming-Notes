# -------------------------------------------------------- Lecture 56 - OOPS in Python ----------------------------------------------------------------------------------------------------------------------------------------------->
# Introduction to Object-Oriented Programming (OOP) in Python
# Programming can be done in different ways. Two main approaches are:

# Procedural Programming: Focuses on procedures or routines.
# Object-Oriented Programming (OOP): Focuses on using objects and classes.
# In this guide, we'll explore OOP, which is a way to design your code using classes and objects.

# Key Concepts in OOP:
# Class: Think of it as a blueprint or template. It defines what properties (data) and methods (actions) an object will have. For example, a Person class might define properties like name and age, and methods like speak() and walk().
# Object: An instance of a class. Each object can have its own data and can use the methods defined by its class. For instance, if Person is the class, an object might be a specific person with a unique name and age.

# Features of OOP in Python:
# Encapsulation: This means hiding the internal details of an object. You interact with an object through its methods, keeping its data safe and protected from accidental changes.
# Inheritance: This allows one class to inherit properties and methods from another. For example, you could create a Student class that inherits from the Person class, adding student-specific details like student_id.
# Polymorphism: This means that different classes can be used interchangeably if they share common methods. It allows you to write flexible code that works with various types of objects.
# Data Abstraction : Data abstraction is a concept in OOP that focuses on hiding the internal details of an object and exposing only the necessary parts to the user. This means that an object’s internal state and the complexity of its implementation are hidden from the outside world.

# -------------------------------------------------------- Lecture 57 - Classes and Objects in Python ----------------------------------------------------------------------------------------------------------------------------------------------->
# We already know the basics of classes and objects! we will just focus on the syntax and new things python has to offer!
# Class creation :
class Student :
    name = "Utkarsh"
    occupation = "CSE Student"
    age = 21
    def info(self) :
        print(f"{self.name} is a {self.occupation} and his age is {self.age}!") # here "self" is a keyword which refers to the current instance of the class! like it is similar to the "this" keyword in C++!
# you can also create class without actually initiallizing variables, you can directly initiallize variables in the setter and getter functions also!

# Object Creation :
st1 = Student() # st1 is a object now! of type student!
print(st1.name) # aise bhi print kr sakte hai names and all!
st1.info()

st2 = Student()
st2.name = "Aditya"
st2.info()

# -------------------------------------------------------- Lecture 58 - Constructors in Python ----------------------------------------------------------------------------------------------------------------------------------------------->
# We know what constructors are, they are functions which helps in creation of objects! they are of different type, it depends on how we create them!
# Abhi upar hume name and variable create krne pad rhe the class me taaki class ko kuch data members de sake! ye cheez C++ me toh krni goti hai but Python me zarurai nhi! This you can do simply with constructors!
class Student2 :
    def __init__(self) : # constructor is created and jab bhi object create hoga tab ye call hoga! and yahaa pr bhi ye self likhna hota hai! this comes under a default constructor!
        print("Constructor is called!")

st3 = Student2() # will print "Constructor is called!"
st4 = Student2() # will print "Constructor is called!"

# Making a paramterized constructor :
class Student3 :
    def __init__(self) :
        print("Default Constructor is called!")
    def __init__(self,n,a) :
        print("Parameterized Constructor is called!")
        self.name = n
        self.age = a
    def info(self) :
        print(f"{self.name} is {self.age} years old!")

st5 = Student3("Utkarsh",21)
st5.info()

st6 = Student3() # Will throw error if runned!
st6.info()
# here in python, you cannot access two constructors, jaise C++ me tha, but yahaa nhi hota aisa, yahaa pr jo baad me likha hua constructor hai sirf vhi call hoga! kyunki python does not support method overloading!
# Also, when you pass somethin in class's functions/methods or constructor, then yaad rakhna ek parameter already hota hai that is "self" and ye khud hi dal jaata hai kyunki object ka use krke hi call krte hai! haa iske alawa arguments pass krne hote hai!
# In Python, constructors return none!

# -------------------------------------------------------- Lecture 59 - Decorators in Python ----------------------------------------------------------------------------------------------------------------------------------------------->
# Decorators : A decorator is a function that takes another function (or method) as an argument, adds some functionality to it, and returns a new function with the added behavior.
# How to do it : We need two things for this... A decorator function and then a decorator application using "@"
# Lets take a simple example :

# Without Decorators
# Here's a function that prints a message :
def greet():
    print("Hello!")

greet()  # Output: Hello!

# Suppose you want to modify this function to add a message before and after calling greet. You can do it manually like this :
def greet():
    print("Hello!")

def greet_with_logging():
    print("Before greeting...")
    greet()
    print("After greeting...")

greet_with_logging()

# Now lets use decorators for the same...
# Defining decorator :
def log_decorator(func):
    def wrapper():
        print("Before greeting...")
        func()
        print("After greeting...")
    return wrapper

# Applying decorator :
@log_decorator # used "@" to apply decorator!
def greet():
    print("Hello!")

greet()

# Scope of Decorator : The @decorator syntax directly affects the function or method immediately following it. The decorator is applied to this function or method, modifying its behavior.
# If you dont want to applying decorator, then you do this without it like... just write..
log_decorator(greet) # It will also do the job, but using decorator is more better... you will get to know as you do more practice and development!

# Now lets see...
# Practical Use-case of Decorator :
# First lets take a quick meaning of logging : Logging is a process of recording information about a program’s execution to help monitor and debug its behavior. It provides a way to track events, errors, warnings, and informational messages that occur during the execution of a program.
# Purpose of Logging : Debugging : Helps developers identify and fix issues by providing insights into the program's execution flow and errors.
#                    : Monitoring : Tracks the program's behavior and performance, allowing you to monitor its health and usage.
#                    : Audit Trails : Maintains records of important events or changes, which can be useful for security and compliance purposes.
# Log Levels : Logging frameworks often support different log levels to categorize the severity or importance of messages.
#            : DEBUG : Detailed information, typically used for diagnosing issues. Example: variable values, detailed processing steps.
#            : INFO : General information about the program's execution. Example: system status updates, significant milestones.
#            : WARNING : Indicates a potential problem or unusual situation that is not necessarily an error but might need attention. Example: deprecated function usage.
#            : ERROR : Represents an error that has occurred and needs attention. Example: exception handling, failed operations.
#            : CRITICAL : Severe errors that might prevent the program from continuing. Example: system crashes, critical failures.
# To do logging you need to "import logging" module!

# And now before moving ahead, lets also understand, *args & **kwargs
# *args : *args ka use karte hain jab hume function ko ek saath multiple arguments pass karne hote hain, lekin hume pehle se nahi pata hota ki kitne arguments pass karenge. Yeh arguments ek tuple me store hote hain.
# Example :
def sum_numbers(*args):
    return sum(args)
print(sum_numbers(1, 2, 3))  # Output: 6
print(sum_numbers(5, 10, 15, 20))  # Output: 50

# **kwargs : **kwargs ka use tab hota hai jab hume function ko keyword arguments pass karne hote hain. Yeh ek dictionary me store hote hain jaha key hoti hai argument ka naam aur value hoti hai us argument ki value.
# Example :
def print_info(**kwargs):
    for key, value in kwargs.items():
        print(f"{key} : {value}")
print_info(name="Amit", age=30, city="Delhi")
# Jab hum print_info(name="Amit", age=30, city="Delhi") call karte hain, toh **kwargs me ek dictionary store ho jati hai { "name": "Amit", "age": 30, "city": "Delhi" }.
# Function print_info is dictionary ke sabhi key-value pairs ko print karta hai.

# Overall : *args aur **kwargs Python me functions ko zyada flexible banate hain kyunki inki madad se hum ek hi function me multiple aur varying number of arguments handle kar sakte hain. Ye function ko generalize karne me madad karte hain aur code ko clean aur readable banate hain.
# Aap *args aur **kwargs ki jagah kuch bhi naam rakh sakte hain, jaise *values aur **options, bas * aur ** notation ka dhyaan rakhna hai. Lekin commonly used *args aur **kwargs ko use karna behtar hota hai taaki code aur developers ke liye readable aur samajhne me easy ho.

# Now understand decorators in simple language :
# Is example me hum ek logging decorator banayenge jo kisi function ke pehle aur baad me messages print karega. Ye decorator function ko kis tarah se wrap karta hai aur arguments kaise handle karta hai, is sabko step-by-step samjhenge.

# Suppose aap ek aisa function banana chahte hain jo kisi bhi function ko call karne se pehle aur baad me logging kare. Logging se hume ye pata chalega ki kaunsa function kab call hua aur kab khatam hua.
# Example code : Defining Decorator Function
def log_decorator(level="INFO"):
    def decorator(func):
        def wrapper(*args, **kwargs):
            print(f"[{level}] Starting function '{func.__name__}' with arguments: {args} and keyword arguments: {kwargs}")
            result = func(*args, **kwargs)
            print(f"[{level}] Finished function '{func.__name__}'")
            return result
        return wrapper
    return decorator
# Explaination :
# Understanding Decorator factory : "decorator factory" ek actual term hai jo commonly use hoti hai Python programming me. Ye term use hoti hai jab hum ek aisa function banate hain jo ek decorator create aur return karta hai. Iska matlab hota hai ki humara function ek "factory" ke roop me kaam karta hai, jo decorators "manufacture" karta hai.
# Function Definition with log_decorator(level="INFO") : Ye ek decorator factory hai jo ek logging level accept karti hai. Default value "INFO" hai.
#                                                      : Iska matlab hai ki ye ek aisa function hai jo ek decorator return karta hai. Yaha level specify karta hai ki kis tarah ki logging hogi, jaise "DEBUG", "INFO", "ERROR", etc.
#                                                      : "INFO," "DEBUG," "ERROR," etc., jo logging levels hain, ye actual me standard keywords hain jo logging systems me use hote hain. Inhe commonly logging systems aur frameworks me messages ki severity ya importance ko indicate karne ke liye use kiya jata hai. Python ka logging module bhi inhi standard logging levels ka use karta hai.
# Inside log_decorator, decorator(func) Function : decorator(func) ek actual decorator hai jo function func ko as argument accept karta hai.
#                                                : Ye ek wrapper function wrapper(*args, **kwargs) return karta hai jo original function ko wrap karta hai.
# Inside decorator, wrapper(*args, **kwargs) Function : *args aur **kwargs ka matlab hai ki wrapper function kisi bhi number of positional aur keyword arguments accept kar sakta hai.
#                                                     : Pehle ye ek message print karta hai jo function ke shuru hone ki information deta hai, including function ka naam aur arguments.
#                                                     : Phir ye original function func(*args, **kwargs) ko call karta hai aur uska result store karta hai.
#                                                     : Function call hone ke baad ek aur message print hota hai jo function ke khatam hone ki information deta hai.
#                                                     : Aakhir me wrapper function result return karta hai.

# Follow-Up Code : Applying Decorator
@log_decorator(level="DEBUG")
def add(a, b):
    return a + b
# Iss func me debug ki imformation dena chahte hai, toh isliye yahaa pr level of logging me debug likha hai! likhne ko yahaa pr kuch bhi likh sakte hai! that will work, pr logging is specially used to provide information to the end user or some other coder! toh isliye yahaa humne level me "DEBUG" likha hua hai, becoz yhi hum chahte hai print krna jab ye function execute ho decorators ki help se!
# Logging ka primary purpose hota hai ki run-time pe ho rahe events ka record rakha jaye, taaki end users ya developers ko useful information mil sake.
# Same for the function below...

@log_decorator(level="ERROR") # Here level is a keyword, baaki error and all toh bss ek message dene ke liye humne ye likha huai hai!
def divide(a, b):
    if b == 0:
        raise ValueError("Cannot divide by zero.")
    return a / b

# Function call for add()
result1 = add(5, 3)
print(f"Result of add: {result1}")

# Function call for divide()
try:
    result2 = divide(10, 2)
    print(f"Result of divide: {result2}")
except ValueError as e:
    print(f"Error: {e}")

# 2nd Function call for divide()
try:
    result3 = divide(10, 0)
    print(f"Result of divide: {result3}")
except ValueError as e:
    print(f"Error: {e}")
# Explaination :
# Decorator Application with @log_decorator(level="DEBUG") : @log_decorator(level="DEBUG") ka use add function ko decorate karne ke liye kiya gaya hai. Iska matlab hai ki jab bhi add function call hoga, pehle log_decorator ka wrapper function execute hoga!
# Function Calls : add(5, 3) call karne se pehle [DEBUG] level ka message print hota hai. Function execute hone ke baad [DEBUG] level ka end message print hota hai.
#                : divide(10, 2) ke case me, [ERROR] level ka message print hota hai kyunki humne decorator me level="ERROR" pass kiya tha. Function call hone ke baad, ek aur message print hota hai.
#                : divide(10, 0) ke case me, exception raise hota hai kyunki 0 se divide nahi kar sakte. Ye error bhi handle kiya gaya hai try-except block me.

# Overall, Decorators are a way to modify or extend the behavior of functions or methods in Python. They are like wrappers that you put around a function to add some extra functionality. Here we have used for the purpose of logging...
# They can be used for more purposes... like Authorization, Caching, validation and Measurements! These we will understand going further for more use cases and projects...

# -------------------------------------------------------- Lecture 60 - Getters and Setters in Python ----------------------------------------------------------------------------------------------------------------------------------------------->
# As we already know, Getters and setters are methods used to access and modify private attributes of a class. They provide a way to control how attributes are accessed and modified, and they help enforce encapsulation and validation.
# Setter : A method used to set or modify the value of a private attribute. It’s used to validate or adjust the value before assigning it.
# Getter : A method used to access the value of a private attribute. It’s typically used to retrieve or return the value of an attribute.

# How to Define Getters and Setters : In Python, you typically use the @property decorator to define a getter method and the @attribute_name.setter decorator to define a setter method.
# We can ask a question, that why we need setter function, when we already are doing it with the help of constructors! Reasons...
# 1) The constructor is used for initial setting of values when an object is created. However, in real-world applications, an object's attributes might need to be updated later on. Setters allow you to control how these updates are made.
# 2) Setters ensure that any changes to the attribute values are validated and consistent. Even if an attribute is initially set correctly, future changes might need validation or other processing.
# 3) Setters can include logic to validate new values before they are assigned. For example, if you want to ensure that an age value is always positive, you can enforce this with a setter. This validation might not be relevant or possible at the time of object creation but becomes necessary later.
# 4) If the internal representation of an attribute changes, you can update the setter logic without affecting the rest of the code. For example, you might decide to change how the name is stored or processed internally, and the setter can handle this change seamlessly.

# Example :
class Person:
    def __init__(self, name, age): # Parameterized constructor initiallizes the objects with the name and age values!
        self._name = name # Here _name and _age are protected data members! and in python it is by convention that protected members names are initialized with single underscore, it is not enforced by python, but by developers convention! 
        self._age = age

    @property # It helps in creating a getter function!
    def name(self):
        """Getter for name""" # Doc created for name getter function!
        return self._name

    @name.setter # It helps in creating a setter function!
    def name(self, value):
        """Setter for name""" # Doc created for name setter function!
        if not value:
            raise ValueError("Name cannot be empty.")
        self._name = value

    @property # getter function creation for age!
    def age(self):
        """Getter for age""" # Another doc!
        return self._age

    @age.setter # setter function creation for age!
    def age(self, value):
        """Setter for age""" # yet another doc!
        if value < 0:
            raise ValueError("Age cannot be negative.")
        self._age = value

person = Person("Alice", 30) # These parameters just initializes the objects attributes and iske baad agar values change krni hoti hai toh vo setter function vo kaam sambhaalta hai!
print(person.name)  # Output: Alice
print(person.age)   # Output: 30

person.name = "Bob" # Valid
print(person.name)  # Output: Bob
# here we are able to use "name" and "age" rather than the whole function name becoz of setter function! kyunki setter function ne hi ye capability di hai name() and age() ko unke sirf naam se call krne ki and jo values pass kroge vo seedha jaake _name and _age me set krdenge! this is becoz of setter function!

# person.age = -5   # Raises ValueError: Age cannot be negative.

# -------------------------------------------------------- Lecture 61 - Inheritance in Python ----------------------------------------------------------------------------------------------------------------------------------------------->
class Employee :
    def __init__(self,name,id) :
        self._name = name
        self._id = id
    def showDetails(self) :
        print(f"{self._name} is a Employee and their ID is {self._id}")

e1 = Employee("Utkarsh",1)
e1.showDetails()
e2 = Employee("Aditya",2)
e2.showDetails()
e3 = Employee("Vishal",3)
e3.showDetails()

# Now lets do inheritance of the above class, for that we just write...
class Programmer(Employee) :
    def showLanguage(self):
        print(f"{self._name} is a programmer and their default Language is Python")
e4 = Programmer("Palak",4)
e4.showLanguage()
# So this is the syntax of inheritance in Python, we can also do more things as we have done in C++...
# There are more types of inheritance : Single, Multiple, Multi-Level, Hierarchial, Hybrid!

# -------------------------------------------------------- Lecture 62 - Access Specifier in Python ----------------------------------------------------------------------------------------------------------------------------------------------->
# In Python there are no public, private and protected things in python...  but okay lets see aage...
# By default python me saare variables public hote hai, bss naming convention ke through hum kisi ko protected ya private show kr sakte hai! using "_" or "__"
# But jaise baaki languages me hota hai ki hum private data members ko access nhi kr paate hai objects ke through, yahaa pr hum kr sakte hai directly to nhi, but through using Name mangling! but protected ko hum aise directly bhi access kr sakte hai bina, bss haa we use "_" to show ki isko protected rakhna hai!
# Lets see example...
class Employee:
    def __init__(self,name) :
        self.__Ename = name # Now here we have made "Ename" a private data member conventionally using "__", ab isko hum directly toh nhi but haa name mangling ke though kr sakte hai!
    def display(self) :
        print(f"{self.__Ename} is an Employee")

e5 = Employee("Utkarsh")
# print(e5.__Ename) # It will throw error!
print(e5._Employee__Ename) # It will print the correct output! so this is how we can access private data members indirectly in python!

# Protected Access Specifiers...
# Isme hum jo convention ke according kisi data member ko protected dikhane ke liye we add a single underscore before it! it just shows that ki ye data member protected ki tarah use hoga! Again ye cheez python enforce nhi krta!
# Even python private bhi enforce nhi krta, it just says ki agar kisi variable ke aage double underscore lgaa diya toh bss vahaa mangling hojayegi and then hum uss data member ko directly access nhi kr sakte!
# In object-oriented programming (OOP), the term "protected" is used to describe a member (i.e., a method or attribute) of a class that is intended to be accessed only by the class itself and its subclasses. In Python, the convention for indicating that a member is protected is to prefix its name with a single underscore (_). For example, if a class has a method called _my_method, it is indicating that the method should only be accessed by the class itself and its subclasses.
# It's important to note that the single underscore is just a naming convention, and does not actually provide any protection or restrict access to the member. The syntax we follow to make any variable protected is to write variable name followed by a single underscore (_) ie. _varName.
class Student:
    def __init__(self):
        self._name = "Harry" # _name is protected data member

    def _funName(self):      # protected method
        return "CodeWithHarry"

class Subject(Student):       #inherited class
    pass

obj = Student()
obj1 = Subject()

# calling by object of Student class
print(obj._name)      
print(obj._funName())     
# calling by object of Subject class
print(obj1._name)    
print(obj1._funName())
# Now ab aisa bhi nhi hai ki ye koi bhot strict rule hai, haa __ lgaa doge tab toh vo data member private ki tarah act krne lag jayega, kyunki usko directly access nhi kr payenge! name mangling ke through hi kr payenge!
# So yes, we should keep that thing in mind!

# Public: Default in Python, accessible everywhere without restrictions.
# Protected: Indicated by a single underscore (_), meant for internal use within the class and its subclasses. This is a convention, not an enforcement.
# Private: Indicated by double underscores (__), intended to prevent accidental access and modification. Access is still possible through name mangling.

# Now lets, see a more systematic Explaintion...
# In Python, the concept of private, public, and protected access specifiers, as seen in other languages like C++ or Java, isn't enforced by the language syntax. Instead, Python relies on naming conventions and a philosophy often summarized as "we are all consenting adults here," meaning that it trusts developers to behave responsibly with their code. Here's how Python handles these concepts:
# Public Members: By default, all class members (attributes and methods) are public. This means they can be accessed from outside the class without any special syntax.
# Protected Members : Python uses a convention of a single underscore prefix (_) to indicate that a member is intended for internal use within the class or subclass. This is merely a convention and does not prevent access from outside the class.
#                   : Example : self._name suggests that name is intended to be a protected member, but it can still be accessed as object._name.
# Private Members : To indicate a member is private, Python uses double underscores (__) at the beginning of the attribute or method name. This triggers name mangling, which changes the attribute's name to _ClassName__AttributeName. This makes it more challenging to access accidentally, but it doesn't make the attribute truly private.
#                 : Example: self.__name can be accessed as object._ClassName__name (where ClassName is the name of the class).
#                 : This mechanism is mainly to avoid name clashes in subclasses and not to enforce strict access control.

# Overall : Python's approach to access control is more about convention and intent rather than strict enforcement. The use of single and double underscores provides a way to indicate the intended use and access level of attributes and methods, but it does not enforce access restrictions. This allows for flexibility and is in line with Python's design philosophy of simplicity and readability.

# -------------------------------------------------------- Lecture 63 & 64 - Exercises ----------------------------------------------------------------------------------------------------------------------------------------------->
# Practice them later on...

# -------------------------------------------------------- Lecture 65 - Static Method in Python ----------------------------------------------------------------------------------------------------------------------------------------------->
# Abhi tak hum class me methods jo bnaa rhe hai vo unn objects/instances ke liye the and unme hume uss instance ko pass krna pad rha tha "self" use krke! and ye methods class and instance ko hum ye power de sakte the ki ye class ke data members ko bhi change kr sakte hai!
# But, the static methods are those, jinko kisi object ya instance ki need nhi hai iske arguments me, inko hum bina self ke bhi call kr sakte hai! but also these methods acn not change or update the data members of the class inse ye power cheen li gyi hai static method ke badle me!
# Lets see an example :
class Maths :
    def __init__(self,num) :
        self.num = num
    
    def addtoNum(self,n): # This is a instance method which needs the instance as first argument, but also jin methods me hum self daalte hai as argument me vo instance ke properties/values ko change kr sakte hai! (yahaa nhi kr rhe but hum dekha hai pehle kr sakte hai)
        self.num = self.num + n

    @staticmethod # This is a static method, it does not need any instance as argument! but ye ek class ke under aata hai toh isko call krne ke liye objects ya class ka name use krna hoga! but unn objects ko as a parameter pass krne ki need nhi hai!
    def add(a,b):
        return a+b
m1 = Maths(5)
print(m1.addtoNum(10)) # it will print 15, kyunki ek toh pehle object ke "num" ko 5 value diya and then addtonum me 10 pass krdiya and dono add hue toh ans is 15

m2 = Maths(5)
m2.add(4,5) # it will print 9, isme m2 ko kya value pass ki gyi hai usse koi mtlb nhi, kyunki static method objects/instance ki values pr kaam nhi krte inka unse koi mtlb nhi!
# Can also write like this...
print(Maths.add(2,3)) # Kyunki as we said, a static method is a method that belongs to a class rather than an instance of a class!

# Overall, It doesn't modify the state of the class or instances and doesn't access class or instance-specific data. Static methods are defined using the @staticmethod decorator and can be called on the class itself without needing an instance.
# No Access to Instance or Class Data: Static methods do not have access to instance (self) or class (cls) data. They operate independently of class and instance attributes.
# Utility Functions: They are often used to group utility functions within a class that have a logical connection to the class but don't require access to its data.

# -------------------------------------------------------- Lecture 66 - Instance Variable and Class Variable in Python ----------------------------------------------------------------------------------------------------------------------------------------------->
# Instance Variables :
# Definition : Instance variables are attributes that are specific to an instance of a class. Each instance of the class has its own copy of these variables.
# Scope : They are accessible only through the instance of the class and can be different for each instance.
# Usage : Used to store data that is unique to each instance.
# Example :
class Dog:
    def __init__(self, name, age):
        self.name = name  # Instance variable
        self.age = age    # Instance variable

# Creating instances
dog1 = Dog("Buddy", 3)
dog2 = Dog("Max", 5)

print(dog1.name)  # Output: Buddy
print(dog2.name)  # Output: Max

# Class Variable :
# Definition: Class variables are attributes that are shared across all instances of a class. They belong to the class itself rather than any specific instance.
# Scope : They are accessible through the class and all its instances. They have the same value for all instances unless modified by the class.
# Usage : Used to store data that should be consistent across all instances of the class.
# Example :
class Dog:
    species = "Canis familiaris"  # Class variable

    def __init__(self, name, age):
        self.name = name  # Instance variable
        self.age = age    # Instance variable

# Creating instances
dog1 = Dog("Buddy", 3)
dog2 = Dog("Max", 5)

print(dog1.species)  # Output: Canis familiaris
print(dog2.species)  # Output: Canis familiaris

# Accessing via class
print(Dog.species)   # Output: Canis familiaris

# Means like, instance variables can be access by only instances/objects but class variables can be access by both class and objects!
# Now, one interesting thing, agar kisi class variable ko kisi instance ka use krke change kroge toh, toh vo class variable change nhi hoga, balki it will make that class variable an instance variable for that instance!
# agar jo class variable hai vo ek instance variable bhi hai tab toh uss instance variable ki value change hojayegi uss istance ke liye, agar nhi hai toh vo class variable ek instance variable ban jayega uss istance ke liye

# -------------------------------------------------------- Lecture 67 & 68 - Exercises ----------------------------------------------------------------------------------------------------------------------------------------------->
# Solve them later on...

# -------------------------------------------------------- Lecture 69 - Class Methods in Python ----------------------------------------------------------------------------------------------------------------------------------------------->
# Class methods are methods that are bound to the class rather than an instance of the class. They operate on the class itself and are defined using the @classmethod decorator.
# Defining : Class Method: A method that is called on the class itself rather than on an instance of the class. It receives the class (cls) as its first argument instead of the instance (self).
# Class methods can access and modify class-level attributes but cannot directly modify instance-level attributes.
# Example :
class Dog:
    species = "Canis familiaris"  # Class variable

    def __init__(self, name, age):
        self.name = name
        self.age = age

    @classmethod
    def make_puppy(cls, name): # "cls" used
        return cls(name, 0)  # Create and return a new instance with age 0

# Create an instance using the class method
puppy = Dog.make_puppy("Buddy")

print(puppy.name)  # Output: Buddy
print(puppy.age)   # Output: 0
print(Dog.species)  # Output: Canis familiaris (Class variable, unaffected by instance methods)

# Interesting examples....
# Example 1 :
class Employee:
    company = "Apple" # Class variable created!
    def show(self):
        print(f"The name is {self.name} and company is {self.company}")
        
    # @classmethod
    def changeCompany(cls, newCompany): # right now, without @classmethod decorator, it is a normal method, which will be used by instances to change the class variable value for specific to that instance!
        cls.company = newCompany


e1 = Employee()
e1.name = "Harry"
e1.show()
e1.changeCompany("Tesla") # Currently it will have no effect on class variable!
e1.show()
print(Employee.company)

# Example : follow up of example 1...
class Employee:
    company = "Apple" # Class variable created!
    def show(self):
        print(f"The name is {self.name} and company is {self.company}")
        
    @classmethod
    def changeCompany(cls, newCompany): # Now due to the presence of the @classmethod decorator, now the "cls" will represent the class and now that clas variable can be changed using instances! abhi kyunki @classmethod nhi likha hai, toh by defauly python methods me pehla argument as a instance deta hai class ka! but jab @classmethod lgaa denge upar, then pehla argument as a class milega!
        cls.company = newCompany


e1 = Employee()
e1.name = "Harry"
e1.show()
e1.changeCompany("Tesla") # Now it can change the class variable!
e1.show()
print(Employee.company)

# -------------------------------------------------------- Lecture 70 - Class Methods Alternative to Constructors ----------------------------------------------------------------------------------------------------------------------------------------------->
# Now suppose a class...
class Employee:
    def __init__(self,name,salary) :
        self.name = name
        self.salary = salary
    def showDetails(self):
        print(f"{self.name} has a salary of {self.salary} Rupees!")
e1 = Employee("Utkarsh",20000)
e1.showDetails()
# This is a simple example jahaa ek constructor simply values ko le rha hai unko instance variable me daalde rha hai and then vo values print ho jaa rhi hai!
# but now, what if kisi ne aisi value pass krdi jisme name and salary alag alag nhi ek hi string me likhe hai! in that case, hum ek aur constructor toh bnaa nhi sakte python me, kyunki python me toh bss ek hi constructor kaam krta hai, toh uss case ko solve krne ke liye we will use @classmethod, lets see how...
class Employee:
    def __init__(self,name,salary) :
        self.name = name
        self.salary = salary
    @classmethod
    def fromString(cls,string):
        return cls(string.split('-')[0],int(string.split('-')[1])) # Isse kya hoga ki agar koi string aisi type ki aati hai "Utkarsh-20000" toh ye class method simply uss string ko "-" ke hisaab se tod ke list bnaa ke class me pass krdega! and then class ka original constructor unn values ko uss class ke liye initiallize krdega!
    def showDetails(self):
        print(f"{self.name} has a salary of {self.salary} Rupees!")

e1 = Employee("Utkarsh",20000)
e1.showDetails()

stringe1 = "Utkarsh-40000"
# e2 = Employee(stringe1) # aise it will throw attribute error! and also ye class attribute hai toh isko instance ki tarah call nhi krna hai!, so we will write...
e2 = Employee.fromString(stringe1) # Correct way of doing this...
e2.showDetails() # it will print the values of the instance e2

# Hum aur alag tareeke ke strings ke liye bhi aise class methods cum constructors bnaa sakte hai, taaki different types ke strings bhi haandle hojaye!

# ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------->