# -------------------------------------------------------- Lecture 71 - dir() __dict__ and help() in Python  ----------------------------------------------------------------------------------------------------------------------------------------------->
# In Python, dir(), __dict__, and help() are built-in functions and attributes that are often used for introspection and help with understanding and debugging code.
# dir() : The dir() function is used to list the names in the current local scope, or it can list the attributes and methods of an object. It returns an alphabetically sorted list of strings.
# Example :
l1 = [1,2,3,4]
print(dir(l1)) # It will print all the methods that are present in this list object! similarly we can do this with other objects also!

# __dict__ : The __dict__ attribute is a dictionary or other mapping object that stores the object's (writable) attributes. For a class, it contains the class's attributes; for an instance, it contains the instance's attributes.
class Student :
    def __init__(self,name,age):
        self.name = name
        self.age = age
    def show(self) :
        print(f"{self.name}'s age is {self.age}")
st1 = Student("Utkarsh",21)
# Not this method will show all the keys (class attributes in case of class and object attributes in case of objects!) and their values!
print(st1.__dict__)
print(Student.__dict__)

# help() : The help() function is used to display the documentation of modules, functions, classes, keywords, etc. It provides a simple way to access the docstrings and metadata of objects.
print(help(Student)) # It will print all the useful information related to that object which is passed in it!

# -------------------------------------------------------- Lecture 72 - super() keyword in Python  ----------------------------------------------------------------------------------------------------------------------------------------------->
# The super() function in Python is a built-in function used to call methods from a parent class. It is commonly used in the context of class inheritance to ensure that parent class methods are correctly called and that method resolution order (MRO) is respected, especially in cases involving multiple inheritance.
# Lets see an exmple of single inheritance :
class Employee:
    def __init__(self,name,id):
        self.name = name
        self.id = id
    def show(self):
        print(f"{self.name}'s id is {self.id}")

class Programmer(Employee):
    def __init__(self,name,id,lang):
        super().__init__(name,id) # Now this super() will call the constructor of the base class!
        self.lang = lang
    def show(self):
        print(f"{self.name}'s id is {self.id} and they used {self.lang}")

e1 = Employee("Aditya",21)
p1 = Programmer("Utkarsh",22,"C++")
p1.show()
e1.show()

# Lets see an example of Multiple Inheritance :
class A:
    def method(self):
        print("Method in A")

class B:
    def method(self):
        print("Method in B")

class C(A, B):
    def method(self):
        print("Method in C")
        super().method()  # Super() method used for calling in the base class!

# Create an instance of C and call method
c = C()
c.method()
# But here the thing is konsa base class call hoga? A ya B, toh ye determine hoga MRO (Method Resolution Order) se
# MRO ek sequence ya order hai jisme Python classes ko check karta hai methods ya attributes ke liye, jab bhi unhe call kiya jata hai
# Agar aap ek class me super() function ka use karte hain, toh yeh function MRO ko follow karta hai aur next class ka method call karta hai.

# Jaise in the above example :  class C inherit kar rahi hai class A aur class B se.
# MRO Calculation: Jab class C ko define kiya jata hai class C(A, B):, toh Python C3 Linearization algorithm ka use karta hai MRO determine karne ke liye. Isme parent classes ko us order me consider kiya jata hai jisme wo declare hui hain.
# MRO Order: MRO ka order C ke liye kuch is tarah se hoga : C > A > B > Object, Is order ka matlab yeh hai ki C class ka koi bhi method call hote waqt pehle C me search hoga, phir A me, phir B me, aur sabse aakhri me object me. (Yahaa jo object ki baat kr rhe hai vo kisi class ka instance nhi hai, vo python ka jo built in base class hai uske object ki baat ho rhi hai!)

# Working of super() : Jab C class me super().method() likha jata hai, toh Python C se next class ko check karega MRO me. Is case me, A next class hai C ke baad. Isiliye, A.method() call hoga.
# Agar B ka method call karna ho toh? Agar aap chahein ki specifically B ka method call ho, toh super() function se directly wo possible nahi hoga kyunki super() MRO ko follow karta hai.
# Solution? Here it is...
# 1) Direct Call : Aap directly B.method(self) likh kar B ka method call kar sakte hain. like this...
class C(A, B):
    def method(self):
        print("Method in C")
        B.method(self)  # Directly calling B's method

# 2) Inheritance Order Change : Aap inheritance order change kar sakte hain agar possible ho, like this...
class C(B, A):
    def method(self):
        print("Method in C")
        super().method()  # Yeh ab B ka method call karega
# 3) Baaki toh explicitly call bhi kr sakte hai! jiske method ko call krna hai!

# Now lets see example of multi-level inheritance :
class A:
    def method(self):
        print("Method in A")

class B(A):
    def method(self):
        print("Method in B")
        super().method()

class C(B):
    def method(self):
        print("Method in C")
        super().method()

a1 = A()
b1 = B()
c1 = C()
print(a1.method())
print("\n")
print(b1.method()) 
print("\n")
print(c1.method())
print("\n")
# Here C se A tak ke methods print hogye super() ka use krke, becoz of MRO! MRO ke sequence ke according super() method kaam krta hai, MRO ke sequence me C > B > A > Object, tak jaana tha iss inheitance tree ke liye isliye gya hai A tak, vrna nhi jaata!
print(C.__mro__)
# MRO : Method Resolution Order (MRO): It is a linearization of the classes in the inheritance hierarchy. Python uses the MRO to decide which method or attribute to use when multiple classes might provide it.

# Overall, to ensure ki sahi tarah se super() keyword utilize ho sahi jagah! toh pehle apna inheritance tree bnaa lo and then MRO ka kya sequence hai vo check krlo and then uske baad uske according super() keyword ko use kro! agar koi aisa class jo call krna hai but vo super() keyword ke through call nhi ho paa rha hai toh usko koi aur way ya explicitly call krlo!
# Chote mote cases me MRO ka sequence already hum guess kr sakte hai, but for complex cases you should use the MRO and then go for the use of super() keyword!

# -------------------------------------------------------- Lecture 73 - Magic/Dunder in Python  ----------------------------------------------------------------------------------------------------------------------------------------------->
# Magic methods, also known as dunder methods (short for "double underscore" methods), are special methods in Python that have double underscores before and after their names. They are used to define the behavior of objects for built-in operations and functions.
# These methods allow you to customize how your objects interact with Python's syntax and built-in functions.
# They are called Dunder methods, Dunder here means “Double Under (Underscores)”

# Python Object Model and Magic Methods :
# 1) Python Object Model : Python mein sab kuch ek object hota hai, aur ye sab objects kisi na kisi class ke instance hote hain. Sabse basic class hai object, jo sab classes ka parent hota hai. Is base class ke through hi Python ka fundamental behavior aur methods define kiye gaye hain.
# 2) Built-In Classes aur Functions : Python mein kuch built-in classes hain jaise int, str, list, aur dict, jo pehle se hi methods aur behaviors ke saath aati hain. For example :
#                                : int class integers handle karne ke liye design ki gayi hai, jisme integer values aur operations define hain.
#                                : print() function aise objects ke saath kaam karta hai jo string representation provide karte hain.
#                                : + operator numerical values ko add karne ke liye use hota hai, aur iska behavior int aur float classes mein define hota hai.
# 3) User-Defined Classes : Jab aap apni custom classes banate hain, toh in classes ke objects automatically Python ke built-in types ke jaise behave nahi karte. Agar aap chahte hain ki aapke objects bhi Python ke built-in functions aur operators ke saath interact kar sakein, toh aapko unka behavior customize karna padta hai.
# 4) Magic/Dunder Methods : Magic methods, yaani dunder methods, wo special methods hain jo double underscores (__) se surrounded hote hain (jaise __init__, __str__, __add__). Ye methods aapko ye define karne ka mauka dete hain ki aapke objects Python ke built-in syntax aur functions ke saath kaise interact karenge. Examples hain :
#                         : __init__() : Ye method new objects ko initialize karne ke liye use hota hai.
#                         : __str__() : Ye define karta hai ki object ko string mein kaise represent kiya jayega, jo print() aur str() functions ke liye important hai.
#                         : __add__() : Ye operator + ka behavior customize karta hai, jo aapke objects ke saath addition ko handle karta hai.
# 5) Purpose and Use : Magic methods aapke user-defined classes ko Python ke built-in operations ke saath seamlessly integrate karne ki facility dete hain. In methods ko define karke, aap apne objects ko built-in types ke saath operate karne ke liye customize kar sakte hain.

# lets see examples now...
# __init__ : This method initializes a new object. It is called when a new instance of a class is created.
class Person:
    def __init__(self, name, age): # Here init is used to initiallize a constructor!
        self.name = name
        self.age = age

p = Person("Alice", 30)
print(p.name)  # Output: Alice
print(p.age)   # Output: 30

# __str__ : This method returns a human-readable string representation of an object. It is used by the print() function and str().
class Person:
    def __init__(self, name, age):
        self.name = name
        self.age = age

    def __str__(self):
        return f"{self.name}, {self.age} years old"

p = Person("Alice", 30)
print(p)  # Output: Alice, 30 years old
# agar bina __str__ define kiye class me print(p), toh ye string print nhi hoti!

# __repr__ : This method returns a string that represents the object in a way that could be used to recreate it. It is used by the repr() function and in interactive sessions.
class Person:
    def __init__(self, name, age):
        self.name = name
        self.age = age

    def __repr__(self):
        return f"Person(name='{self.name}', age={self.age})"

p = Person("Alice", 30)
print(repr(p))  # Output: Person(name='Alice', age=30)
# repr() is a built-in function for strings python objects, but isko user-defined class objects ke saath use krne ke liye hume __repr__ ko use krke class me define krna padega! taaki hum uss string pr repr() func use kr paye ek normal string ki tarah!

# __add__ : This method defines how the + operator works for the class. It is used to handle addition operations.
class Point:
    def __init__(self, x, y):
        self.x = x
        self.y = y

    def __add__(self, other):
        return Point(self.x + other.x, self.y + other.y)

    def __repr__(self):
        return f"Point({self.x}, {self.y})"

p1 = Point(1, 2)
p2 = Point(3, 4)
p3 = p1 + p2
print(p3)  # Output: Point(4, 6)
# agar bina __add__ define kiye + operator use krte class ke objects pr tab error aata!

# __len__ : This method returns the length of the object. It is used by the len() function.
class MyList:
    def __init__(self, items): # here, what happened is, ki yahaa pr "items" bss ek object ko input lega, abhi at this moment koi type specified nhi hai uss input ka! but as we know jab hum l1 ko initiallize and l2 declare krte hai and jab l2 = l1 krte hai, tab l2 me l1 copy nhi hota, balki ek aur refrence ban jaata hai l1 ke liye....
        self.items = items # Toh yahaa kya hua ki jab __init__() me jab items daala gya, tab uska koi type specified nhi tha, but jaise hi object bnaa ke usme list pass ki gyi tab uska type specify hogya (python me aisa hi toh hota hai!)! and then humne self.list = list likh ke bss ek aur reference pass krdiya list ke liye! and that is how items list iss class ke liye ek variable ban gyaa, isliye ab usko access kr payenge normally!

    def __len__(self): # And iske through uska length bhi nikal payenge!
        return len(self.items)

ml = MyList([1, 2, 3, 4])
print(len(ml))  # Output: 4

# __getitem__ : This method defines how to access elements in a class instance using indexing (e.g., obj[index]).
class MyList:
    def __init__(self, items):
        self.items = items

    def __getitem__(self, index):
        return self.items[index]

ml = MyList([10, 20, 30])
print(ml[1])  # Output: 20
# Now as you can see, now we are able to use object of the class as normally as a normal list variable, this is what the use of dunder methods!

# __setitem__ : This method allows for setting items using indexing (e.g., obj[index] = value).
class MyList:
    def __init__(self, items):
        self.items = items

    def __setitem__(self, index, value):
        self.items[index] = value

ml = MyList([10, 20, 30])
ml[1] = 25
print(ml.items)  # Output: [10, 25, 30]

# __del__ : This method is called when an object is about to be destroyed. It is used for cleanup.
class MyClass:
    def __init__(self, name):
        self.name = name

    def __del__(self):
        print(f"{self.name} is being deleted")

obj = MyClass("Example")
del obj  # Output: Example is being deleted
# If this was the last reference to the object, Python's garbage collector will call the __del__ method to perform any necessary cleanup.
# What happens is... When you use the del keyword on an object reference (e.g., del obj), it removes that reference. If obj was the only reference to the instance of MyClass, deleting obj reduces the reference count of that instance to zero. When the reference count of an object drops to zero, the object becomes eligible for garbage collection.
# Garbage Collection and __del__ Method : Python has a garbage collector that automatically deallocates memory by destroying objects that are no longer referenced. If the object is eligible for garbage collection and has a __del__ method, Python calls this method before destroying the object. The __del__ method allows you to define custom cleanup behavior, such as printing a message, closing files, or releasing resources.

# __call__ : Make objects callable, This method allows an instance of a class to be called as if it were a function.
class Multiplier:
    def __init__(self, factor):
        self.factor = factor

    def __call__(self, value):
        return value * self.factor

m = Multiplier(3)
print(m(10))  # Output: 30
# this makes "m" object callable!

# -------------------------------------------------------- Lecture 74 - Method Overiding in Python  ----------------------------------------------------------------------------------------------------------------------------------------------->
# It is a way to over write a function/method of the parent class in the child class!
# Lets see an example (this is not an example of method overriding!):
class Square:
    def __init__(self,x,y):
        self.side1 = x
        self.side2 = y
    def area(self):
        return self.side1 * self.side2
    
class Circle:
    def __init__(self,r):
        self.radius = r
    def area(self):
        return 3.14 * self.radius**2

sq1 = Square(4,5)
print(sq1.area())

c1 = Circle
print(c1.area())

# A good example of method overriding :
class Shape:
    def area(self):
        pass  # Define a generic method that will be overridden

class Square(Shape):
    def __init__(self, x, y):
        self.side1 = x
        self.side2 = y
    
    def area(self):
        return self.side1 * self.side2  # Overriding the area method of Shape

class Circle(Shape):
    def __init__(self, r):
        self.radius = r
    
    def area(self):
        return 3.14 * self.radius ** 2  # Overriding the area method of Shape

# Creating instances
sq1 = Square(4, 5)
print(sq1.area())  # Output: 20

c1 = Circle(3)
print(c1.area())  # Output: 28.26 (approximately)

# Overall, in simple words agar inherit krne ke baad kisi child class me kisi already implemented function ko re-implement krte hai toh usko method overriding kehte hai!

# -------------------------------------------------------- Lecture 75 & 76 - Exercises  ----------------------------------------------------------------------------------------------------------------------------------------------->
# Practice them later on...

# -------------------------------------------------------- Lecture 77 - Operator Overloading in Python ----------------------------------------------------------------------------------------------------------------------------------------------->
# It helps in overloading some operators, like jaise pehle dekha tha na ki humne user defined objects ke liye "+" operator ka behaviour define kiya tha __add__ dunder use krke! bss vhi krna hota hai!
# alag alag dunder methods se alag alag type ke operators ko hum define kr sakte hai ek user-defined class ke liye!
# Lets create vectors and add them! and as becoz hum jo class banayenge uske instances add khud toh honge nhi toh hume ek dunder method use krna hoga uss operation ko perform krne ke liye!
class vectors:
    def __init__ (self,x,y,z):
        self.x = x
        self.y = y
        self.z = z
    def __str__(self) :
        return f"{self.x}i + {self.y}j + {self.z}k"
    def __add__(self,v2):
        return vectors(self.x + v2.x, self.y + v2.y, self.z + v2.z)
    
v1 = vectors(2,3,4)
print(v1)

v2 = vectors(5,6,2)
print(v2)

v3 = v1 + v2
print(v3)

# -------------------------------------------------------- Lecture 78 - Single Inheritance in Python ----------------------------------------------------------------------------------------------------------------------------------------------->
# When one class inherits from a single base class!
# Example :
# Parent class
class Animal:
    def __init__(self, name):
        self.name = name

    def speak(self):
        return "Some generic sound"

# Child class
class Dog(Animal):
    def __init__(self, name, breed):
        super().__init__(name)  # Initialize the parent class
        self.breed = breed

    def speak(self):
        return "Woof!"

# Creating an instance of Dog
my_dog = Dog("Buddy", "Golden Retriever")

# Using methods from both the parent and child classes
print(my_dog.name)  # Output: Buddy (inherited from Animal)
print(my_dog.breed)  # Output: Golden Retriever (specific to Dog)
print(my_dog.speak())  # Output: Woof! (overridden in Dog)

# -------------------------------------------------------- Lecture 79 - Multiple Inheritance in Python ----------------------------------------------------------------------------------------------------------------------------------------------->
# When one class inherits from more than one base class!
# Although out of curiosity I have discussed all of the things related to multiple inheritance in the above lecture of super() keyword!
# But letss just take an example :
# Parent class 1
class Animal:
    def __init__(self, name):
        self.name = name

    def speak(self):
        return "Some generic sound"

# Parent class 2
class Vehicle:
    def __init__(self, model):
        self.model = model

    def start(self):
        return "Vehicle started"

# Child class inheriting from both Animal and Vehicle
class Car(Animal, Vehicle):
    def __init__(self, name, model):
        Animal.__init__(self, name)  # Initialize the Animal part, here you can use super() keyword, kyunki usse MRO ke according seedha ye Animal class pr jayega and name attribute vahaa se lelega, but it will not make sense, name toh store hojayega, but ek Car ke liye animal class kyun call krni! so yess yahaa yhi sahi hai!
        Vehicle.__init__(self, model)  # Initialize the Vehicle part

    def drive(self):
        return "Car is driving"

# Creating an instance of Car
my_car = Car("Buddy", "Sedan")

# Using methods from both parent classes and the child class
print(my_car.name)      # Output: Buddy (inherited from Animal)
print(my_car.model)     # Output: Sedan (inherited from Vehicle)
print(my_car.speak())   # Output: Some generic sound (inherited from Animal)
print(my_car.start())   # Output: Vehicle started (inherited from Vehicle)
print(my_car.drive())   # Output: Car is driving (specific to Car)

# -------------------------------------------------------- Lecture 80 - Multi-Level Inheritance in Python ----------------------------------------------------------------------------------------------------------------------------------------------->
# Its like, Parent Class > Child Class > Child-Child Class
# Example :
# Base class
class Animal:
    def __init__(self, name):
        self.name = name

    def speak(self):
        return "Some generic sound"

# Intermediate class inheriting from Animal
class Mammal(Animal):
    def __init__(self, name, hair_color):
        super().__init__(name)  # Initialize the Animal part
        self.hair_color = hair_color

    def has_fur(self):
        return True

# Derived class inheriting from Mammal
class Dog(Mammal):
    def __init__(self, name, hair_color, breed):
        super().__init__(name, hair_color)  # Initialize both Animal and Mammal parts
        self.breed = breed

    def speak(self):
        return "Woof!"

    def describe(self):
        return f"{self.name} is a {self.breed} with {self.hair_color} fur."

# Creating an instance of Dog
my_dog = Dog("Buddy", "golden", "Golden Retriever")

# Using methods from all parent classes
print(my_dog.name)        # Output: Buddy (inherited from Animal)
print(my_dog.hair_color)  # Output: golden (inherited from Mammal)
print(my_dog.breed)       # Output: Golden Retriever (specific to Dog)
print(my_dog.speak())     # Output: Woof! (overridden in Dog)
print(my_dog.describe())  # Output: Buddy is a Golden Retriever with golden fur.


# -------------------------------------------------------- Lecture 81 - Hierarchial Inheritance and Hybrid in Python ----------------------------------------------------------------------------------------------------------------------------------------------->
# Hierarchial Inheritance : When multiple child classes inherits from single base class!
# Example :
class Animal:
    def __init__(self, name):
        self.name = name

    def speak(self):
        return "Some sound"

class Dog(Animal):
    def __init__(self, name, breed):
        super().__init__(name)
        self.breed = breed

    def speak(self):
        return "Woof!"

class Cat(Animal):
    def __init__(self, name, color):
        super().__init__(name)
        self.color = color

    def speak(self):
        return "Meow!"

# Creating instances
dog = Dog("Buddy", "Golden Retriever")
cat = Cat("Whiskers", "Tabby")

print(f"{dog.name} says: {dog.speak()}")  # Output: Buddy says: Woof!
print(f"{cat.name} says: {cat.speak()}")  # Output: Whiskers says: Meow!

# Hybrid Inheritance : Hybrid inheritance occurs when a class is derived from more than one base class, and those base classes themselves may have multiple levels of inheritance. It combines multiple types of inheritance (e.g., single, multiple, hierarchical) in a single inheritance hierarchy.
# Example :
# Base class for single inheritance
class Animal:
    def __init__(self, name):
        self.name = name

    def speak(self):
        return "Some sound"

# Base class for multiple inheritance
class Swimmer:
    def swim(self):
        return "Swimming"

# Derived class for hierarchical inheritance
class Mammal(Animal):
    def __init__(self, name, has_fur):
        super().__init__(name)
        self.has_fur = has_fur

    def describe(self):
        return f"{self.name} has {'fur' if self.has_fur else 'no fur'}"

# Derived class for hybrid inheritance
class Dolphin(Mammal, Swimmer):
    def __init__(self, name, has_fur, age):
        Mammal.__init__(self, name, has_fur)
        self.age = age

    def describe(self):
        return f"{self.name} is a {self.age}-year-old dolphin with {'fur' if self.has_fur else 'no fur'}"

# Creating an instance
dolphin = Dolphin("Flipper", False, 5)

# Accessing methods
print(dolphin.describe())  # Output: Flipper is a 5-year-old dolphin with no fur
print(dolphin.speak())     # Output: Some sound (from Animal)
print(dolphin.swim())      # Output: Swimming (from Swimmer)

# ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------->