# ------------------------------------------------------------------- Lecture 31 & 32 - Sets and Introduction and Its methods! -------------------------------------------------------------------------------------------------------------->
# Sets are an un-ordered collection of data items! they store multiple items in a single variable! Sets are mutable, meaning you can change items of the sets after creation!
# Set items are enclosed in curly brackets "{}"! and seperated with commas! and set do not contain duplicate elements! also sets me different data types ki value bhi aa sakti hai!
s1 = {1,1,2,3}
print(s1) # It will print 1,2,3 only!
# also order maintain krne ki koi gurantee nhi hai!

# Printing the type!
set1 = {}
print(type(set1)) # It will print dictionary! and not set! kyunki python me sets and dictionaries ke liye curly brackets hi use hote hai! so we agar aise type print kroge toh <class 'dict'> print krega! so to print the type we need to use function "set()"

set2 = set()
print(type(set2)) # It will accurately print the type!

# Accessing items in sets!
data1 = {"Utkarsh", 365, 'O', True}
for items in data1 :
    print(items) # here it will print values with random order!

# Sets methods :
# .union() : Combines two sets! it returns a new set after combining sets!
set3 = {1,2,3,4,4}
set4 = {5,5,6,7,8}
print(set3.union(set4))

# .update() : Updates sets
set3.update(set4)
print(set3) # It only updates the values in the set3! this do the changes in the original set only!

# .intersection() : It returns a new set which contain common items of both the sets!
set5 = {"India", "Australia", "Japan", "Russia"}
set6 = {"America", "United Kingdom", "Australia", "Japan"}
print(set5.intersection(set6))

# .intersection_update() : it also does the same thing as intersection() the only difference is that it updates the original set only! it do not return a new set!
set7 = {"India", "Australia", "Japan", "Russia"}
set8 = {"America", "United Kingdom", "Australia", "Japan"}
set7.intersection_update(set8)
print(set7)

# .symmetric_difference() : It mathematically calculates the symmetric difference and returns a new set!
set9 = {1,2,3,4,5}
set10 = {3,4,5,6,7,8,9}
print(set9.symmetric_difference(set10))

# .symmetric_difference_update() : It mathematically calculates the symmetric difference and updates the original set!
set11 = {1,2,3,4,5}
set12 = {3,4,5,6,7,8,9}
set11.symmetric_difference_update(set12)
print(set11)

# .difference() : return a new set where it calculates the set difference between the two sets!
set13 = {1,2,3,4,5}
set14 = {3,4,5,6,7,8,9}
print(set13.difference(set14))

# .difference_update() : Calculates the set difference between the two sets! and updates the original set!
set15 = {1,2,3,4,5}
set16 = {3,4,5,6,7,8,9}
set15.difference_update(set16)
print(set15)

# .isdisjoint() : return true if the two sets involved are completely un equal from each other!
set17 = {1,2,3,4}
set18 = {5,6,7,8}
print(set17.isdisjoint(set18)) # True
print(set17.isdisjoint(set17)) # False

# .issuperset() : return true if the set in the bracket is superset of the original set! and similarly we have .subset()
set19 = {1,2,3,4,5,6,7,8}
set20 = {4,5,6}
print(set19.issuperset(set20)) # True
print(set20.issuperset(set19)) # False

# .issubset() : return true if the set in the bracket is subset of another set!
set21 = {1,2,3,4,5,6,7,8}
set22 = {4,5,6}
print(set22.issubset(set21)) # True
print(set21.issubset(set22)) # False 

# .add() : Adds an element to the set!
set22 = {1,2,3,4}
set22.add(5)
print(set22)

# .update() : if you want to add more than one values into a set!
set23 = {1,2,3,4,5}
set24 = {5,6,7}
set23.update(set24)
print(set23)

# .remove()/.discard() : Used to remove/discard items from the list! difference between the two is ki agar koi element present nhi hai set me and we try to remove/discard that element, then remove will raise error but discard won't!
set25 = {1,2,3,4}
set25.remove(1)
set25.discard(2)
print(set25)

set25.remove(5) # It will raise error
set25.discard(5) # it will not raise error
print(set25)

# .pop() : pops last element of the set, but catch is that we dont know which element will get pop, as becoz sets are unordered! but we can store which element gets pop
set26 = {1,2,3,4}
item = set26.pop()
print(item)

# del : It is a keyword, which deletes an entire set!
set27 = {1,2,3}
del set27
print(set27) # This will show error as becoz set27 now does not exist!

# .clear() : It deletes all the content of the list!
set28 = {1,2,3}
set28.clear()
print(set28) # will print set()

# If we want to check whether an element exist in the set or not, then...
set29 = {"Utkarsh", "Palak", "Kinshuk", "Paresh"}
if "Utkarsh" in set29 :
    print("Yes he is present!")
else :
    print("No, not present!")

# ------------------------------------------------------------------- Lecture 33 & 34 - Dictionary Introduction and its methods! -------------------------------------------------------------------------------------------------------------->
# Dictionaries are collection of data items, they store multiple data items in a single variable! They are key value pairs which are separated by commas and enclosed within curly brackets!
# Note : your dictionary will be ordered or unordered will depend on the version of Dictionary you are using, Python 2.7 onwards dictionary are ordered, and before that dictionary were unordered! Mine is Python 3.11, so here Dictionary will be ordered!

# Basic syntax :
students = {
    "First_name" : "Utkarsh",
    "Middle_Name" : "None",
    "Last_Name" : "Verma"
}
print(students["First_name"])
print(students.get("First_name"))
# Both ways of printing seems same, but they are not, first way will show error if the key is not found in the dictionary! but the second way will not throw error, it will just simply print none!

print(students.keys()) # It will print all the keys of the dictionary
print(students.values()) # It will print all the values of the dictionary

# to print values we can also use this!
for keys in students.keys() :
    print(students[keys])

for keys in students.keys() :
    print(f"The value corresponding to the key {keys} is {students[keys]}") # f-string is used to print values!

print(students.items()) # It will the whole dictionary!
for key,value in students.items() :
    print(f"The value corresponding to the key {keys} is {value}")

# Dictionary methods :
# .update() : It updates the dictionary, agar jo key-value pair add krna chah rhe hai uska key already exist krta hai toh uska value update hojayega but agar key exist nhi krta toh ek nayaa key-value pair add hojayega!
example1 = {
    "name" : "Utkarsh",
    "age" : "22",
    "DOB" : "14th Feb"
}
example1.update({"DOB" : "14th Feb 2003"})
example1.update({"Profession" : "Student"})
print(example1.items())
# We can update another dictionary also withing the previous one!

# .clear() : It will delete all the items from the dictionary!
example1.clear()
print(example1) # will print {}
print(example1.items()) # will print dict_items([])

# .pop() : will remove that item jiska key as a parameter pass hua tha!
example2 = {"name" : "Utkarsh", "age" : "22", "DOB" : "14th Feb", "Profession" : "Student"}
example2.pop("Profession")
print(example2.items())

# .popitem() : deleted the last items of the dictionary!
example3 = {"name" : "Utkarsh", "age" : "22", "DOB" : "14th Feb", "Profession" : "Student"}
example3.popitem()
print(example3.items())

# del : this keyword will delete the whole dictionary if any key is not passed! otherwise it will only delete that key-value pair!
example4 = {"name" : "Utkarsh", "age" : "22", "DOB" : "14th Feb", "Profession" : "Student"}
del example4["Profession"]
print(example4.items()) # Deleted the key profession!

del example4
print(example4.items()) # deleted the whole dictionary!

# ------------------------------------------------------------------- Lecture 35 - For-Loop with else in python! -------------------------------------------------------------------------------------------------------------->
# Abhi tak humne "else" ko sirf if" ya "else if" ke saath hi dekha tha codes me, whether its C/C++ or Python, but in Python hum else ko for and while ke saath bhi use kr sakte hai!
for i in range(5) :
    print(i)
else :
    print("Loop ended!")
# in the above case, else humne for loop ke saath use kiya, else vaali statement tab execute hogi jab for loop "end" hojayega!

for i in range(5) :
    print(i)
    if i== 4 :
        break
else :
    print("Loop ended!")
# in the above case, humne if condition bhi lgaa di hai sirf for loop ke andar, and iss case me for loop "break" hua hai naa hi ki "end" isliye yahaa else execute nhi hoga!
# else vaali condition sirf tab hi execute hogi jab loop successfully "end" hoga, jab uski saari iterations complete hogi tab! agar loop "break" se end hota hai toh else condition execute nhi hogi!
 
# ------------------------------------------------------------------- Lecture 36 - Exceptional Handling in Python -------------------------------------------------------------------------------------------------------------->
# Exception handling in Python is a mechanism that allows a program to deal with unexpected errors or situations gracefully, without crashing. It involves the use of specific keywords and constructs to catch and handle exceptions. Here’s a detailed explanation of the key concepts and syntax involved in Python exception handling:
# Its more or less same as C++, bss thora syntax ka antar hai! baaki sab same hai and kuch cheeze aur addition me hai!
# Starting with the most basic exceptional handling in Python : Simple try-except block!
try :
    a = int(input("Enter any number :"))
    print(a)
except :
    print("Enter a valid input!")

# Lets move a step forward with...
# Handling some pre-defined exceptions, these pre-defined exceptions are called exception objects in python!
# Exception Object #1 : ZeroDivisionError : It is used as the name suggests!
try :
    a = int(input("Enter dividend : "))
    b = int(input("Enter divisor : "))
    result = a/b
    print(result)
except ZeroDivisionError :
    print("Dividing with zero!")

# Exception Object #2 : ValueError : It is used when a function receives an argument of the right type but inappropriate value.
try :
    a = int(input("Enter value : "))
    print(a)
except ValueError :
    print("Value Error")

# Exception Object #3 : TypeError : Raised when an operation or function is applied to an object of inappropriate type.
try :
    a = int(input("Enter value : "))
    print(a)
except TypeError :
    print("Type Error")

# Exception Object #4 : ArithematicError : Base class for all arithmetic-related errors. Includes ZeroDivisionError, OverflowError, and FloatingPointError.
try:
    result = 10 / 0
except ArithmeticError :
    print("Arithmetic error")

# Exception Object #5 : IndexError : Raised when trying to access an index that is out of range.
try:
    lst = [1, 2, 3]
    print(lst[5])
except IndexError :
    print(f"Index error")

# Exception Object #6 : It is more general type of exception, agar koi type ka exception match nhi hota toh ye vaala exception execute hojayega!
try:
    lst = [1, 2, 3]
    print(lst[5])
except Exception :
    print("Exception Occured!")
# There are more different types of exception objects more, but we will learn more of them according to usage!

# Else Statement : If try block does not raise any exception, then else statement will execute!
try:
    result = 10 / 2
except ZeroDivisionError:
    print("Cannot divide by zero.")
else:
    print(f"Result is {result}")

# ------------------------------------------------------------------- Lecture 37 - Finally block in Exceptional Handling -------------------------------------------------------------------------------------------------------------->
# The finally block is used for cleanup code that should run regardless of whether an exception occurred or not.
# Else block tha ki agar try block exception throw nhi krta toh else block execute hoga! but yahaa finally is regardless try exception throw krta hai ya nhi, finally block execute hoga hi!
# So lets understand "finally" keyword!
try :
    a = int(input("Enter the value : ")) # Yahaa input pr depend krega ki error ayega ki nhi
    print(a)
except :
    print("Error occured!") # yahaa pr execption throw and print hoga agar koi error ayaa!
else :
    print("No error occured!") # Agar koi error nhi aaya, toh else statement bhi print hojayega along with the execution of code in the try block!
finally :
    print("This line of code will always execute!") # This line of code will always execute, regardless error aaya ya nhi!

# but now the question is ye toh aise bhi hojaata...
try :
    a = int(input("Enter the value : "))
    print(a)
except :
    print("Error occured!")
else :
    print("No error occured!")
print("This line of code will always execute!") # ye toh abhi bhi always execute hoga regardless error aaye ya nhi, kyunki error handle toh hogya execption block me!
# toh now question toh kaam kya rhaa finally keyword ka!

# Toh now see, the actual work and fayeda of finally block! suppose you have a function...
def func() :
    try :
        a = int(input("Enter the value : "))
        print(a)
        return 1
    except :
        print("Error occured!")
        return 0
    else :
        print("No error occured!") # This part of the code is not reachable! agar "finally:" keyword hataa doge toh uske andar ka code bhi reachable nhi hoga!
    finally :
        print("This line of code will always execute!")
# Toh here is the thing, in this function try block execute hojaye successfully and return 1 hojaye ya koi exeption throw hojaye except block se, but still the finally block will execute!
# As we know, func() jab koi value return krdeta hai toh uske baad ka code execute nhi hota, but iss case me finally block fir bhi execute hoga! so this is the actual strength of finally block!

# ------------------------------------------------------------------- Lecture 38 - Raising custom error in Exceptional Handling -------------------------------------------------------------------------------------------------------------->
# Lets raise a basic custom error :
a = int(input("Enter value between 1-9 : "))
if(a<1 or a>10) :
    raise ValueError("Enter number between 1-9") # This line will actually throw an error! pehle kya ho rha tha ki hum koi error aata tha toh hum koi cheez print krdete the! but yahaa hum seedha error hi raise krde rhe hai!
else :
    print(a)

# So Lecture 37 me hum error agar aaye toh usko hum handle kr rhe hai, taaki hum aage badh sake! this was called : Handling Errors!
# But yahaa hum apne side se error throw kr rhe hai, ki agar kuch humare according galat hota hai toh hum vhi ke vhi error se code ko rok denge! this is called : Raising custom errors!
# We can create more custom error, using classes! but that you have already studied in C++ but abhi tak python me classes padha nhi hai toh for now we can leave it!

# ------------------------------------------------------------------- Lecture 39 - Exercise 3 : KBC Game -------------------------------------------------------------------------------------------------------------->
# Create KBC Game!

# ------------------------------------------------------------------- Lecture 40 - Exercise 4 : Secret Code -------------------------------------------------------------------------------------------------------------->
# Perform this exercise!