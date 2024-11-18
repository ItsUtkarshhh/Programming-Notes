# ------------------------------------------------------------------- Lecture 22 - Introduction to Lists -------------------------------------------------------------------------------------------------------------->
# Ordered collection of data items
# Here we store multiple items in a single variable
# Lists items are separated by commas and enclosed within square brackets!
# Lists are mutable, we can alter them after creation!
# Lists can contains data items od different data types also!

Data = [1,2,3,4,"Utkarsh",True]
print(Data)
print(Data[:]) # The above two print statements will print the same thing!
print(Data[0])
print(Data[1])
print(Data[2])
print(Data[3])
print(Data[4])
print(Data[5])

# Negative Indexing in Lists! It is first we convert in +ve indexes! and then we print the output! It is same as we have done in strings!
print(Data[-2]) # It will print the value at index 4

# Checking whether an item is in the list or not! for that we use the "in" keyword!
if "Utkarsh" in Data :
    print("Yes")
else :
    print("No")

if 6 in Data :
    print("Yes")
else :
    print("No")
# This "in" keyword can also be used in string as well! lets see an example...
if "ars" in "Utkarsh" :
    print("Yes")
else :
    print("No")

# jump index in lists!
Data2 = [1,2,3,4,5,6,7,8,9,10]
print(Data2[0:10]) # Now in this if we add one more value in ":", then, it will be the jump index, means next element print krne se pehle kitne baar jump krega!
print(Data2[0:10:2]) # It will print 1, then will jump 2 times, then will print 3, then will jump 2 times and will print 5... and similarly!

# List Comprehension : It is a little complex way of initiallizing lists!
Data3 = [i+1 for i in range(10)]
print(Data3)

Data4 = [i+1 for i in range(20) if (i%2 == 0)] # Yahaa pehle kya hua ki, pehle i me 0-19 tak ke saare values add hogye! and then if condition check hui, jisse saare even numbers select hogye! and then i+1 krke saare even numbers odd banke print hogye! agar iss hi condition me agar even numbers print krne hai toh if (i%2 != 0) use kro, yaa toh same previous condition ke saath i print krdo, naa ki i+1
print(Data4)

Data4 = [i+1 for i in range(20) if (i%2 != 0)] # Printed all the even numbers from 1-20
print(Data4)

Data4 = [i for i in range(20) if (i%2 == 0)] # Printed all the even numbers from 0-18
print(Data4)
# And similarly this list comprehension can be more complex!

# ------------------------------------------------------------------- Lecture 23 - List Methods -------------------------------------------------------------------------------------------------------------->
# .sort() : Sort list in ascending order
colors = ["violet", "orange", "white", "red", "pink", "yellow"]
colors.sort() # Here the sorting is done within the same list!
print(colors)

# .append() : Adds an element in the end of the list!
num = [1,2,3,4,5]
print(num)
num.append(6)
print(num)

# .reverse() : Reverses the list!
num = [1,9,3,6,5]
num.reverse()
print(num)

# .index() : Returns the index of the first occurence of the list item!
num = [1,9,1,3,6,5]
print(num.index(1))

# .count() : counts the number of occurences of the list items!
num = [1,9,1,3,1,6,5]
print(num.count(1))

# .copy() : It copies one list to another!
# Lets see this in depth! agar hum simply ek list ko "=" operator ko use krke dusri list me daalde! toh isse list copy nhi hoti, balki bss ek aur reference ban jaata hai uss same list ka! isse jo changes dusre list me honge vhi original list me bhi hojayenge! so "=" operator use krke nhi krna hai! we will use .copy() function for this!
num = [1,9,1,3,1,6,5]
num2 = num.copy()
num2[2] = 100
print(num)
print(num2)

# .insert() : Inserting new item into the list! using indexes!
num.insert(3,1000)
print(num)

# .extend() : This method adds an entire list or any other collection datatype (set, tuple, dictionary) to the existing list!
pre_exiting_list = [1,2,3,4,5,6,7,8,9,10]
new_list = [1000,2000,3000]
pre_exiting_list.extend(new_list) # Isme jo pre existing list hai usko extend krte hai and jo new list hai usko pre existing list me append krdete hai!
print(pre_exiting_list)

# concatenation of lists!
L1 = [1,2,3,4]
L2 = [5,6,7,8]
New_L = L1 + L2 # Concatenation!
print(New_L)

# ------------------------------------------------------------------- Lecture 24 - Introduction to Tuples -------------------------------------------------------------------------------------------------------------->
# Tuples are ordered collection of Data Items! They also store mutliple items in a single variable! They are also separated by commas, but they are enclosed within round brackets (parenthesis)
# Isme bhi multiple data types ki value aa sakti hai!
# Also Tuples are immutable, means they are unchangeble once they are created!
DataTup1 = (1,2,3,4)
print(type(DataTup1)) # It will print class <type 'tuple'>
print(DataTup1) # It will print the whole tuple!

DataTup2 = (1)
print(type(DataTup2)) # Here it will print class <type 'int'> , kyunki humne sirf ek hi element daala hua hai tuple me! and iske kaaran ye ek int ki tarah identify hoga! na ki ek tuple ki tarah! to identify it as tuple, you should add a comma in it
DataTup3 = (1,)
print(type(DataTup3)) # Here it will print class <type 'tuple'>

# DataTup3[0] = 30 # But if we write this, it will show error, as becoz after we create tuple, uske baad tuple ke elements ko change nhi kiya jaa sakta!
# Yahaa bhi tuples ko indexes ko use krke access kr sakte hai plus yahaa bhi positive and negative indexing vaise hi hoti hai jaise strings ya lists me! also isme bhi same way se length function use kr sakte hai!

if 1 in DataTup1 :
    print("Yes")
else :
    print("No")

# Here also we can do slicing of the tuple! in the same way as of list or strings!
# But as we have said earlier, ki tuples ko change nhi kiya jaa sakta toh haa vo baat sach hai, toh yahaa pr original tuple me koi changes nhi hote balki ek new tuple return hota hai!
print(DataTup1[0:3])
print(DataTup1[0:])
print(DataTup1[:2])
print(DataTup1[:-2])
print(DataTup1[-4:-1])
print(DataTup1[:])
# You already know how they work!
# So means, tuple is almost as same as list, bss ek yhi difference hai ki tuple immutable hote hai and ye round brackets se banta hai and list square brackets se!

# ------------------------------------------------------------------- Lecture 25 - Tuples Operations! -------------------------------------------------------------------------------------------------------------->
# Tuple pr hume koi operations perform krne hai toh iska tareeka thora alag hota hai as we know, ki tuples pr direct operations nhi ho sakte! kyunki vo toh immutable hoti hai!
# Toh Tuples pr operations krne ke liye pehle usko list me convert kiya jaata hai and then uspr operations hote hai and then vapis ek copy of that original tuple me convert krdiya jaata hai!

# Lets do this...
tuple1 = ("India", "New Zealand", "South Africa", "Australia", "England") # We will change this tuple...
print(tuple1)
temp = list(tuple1) # Converting to list
temp.append("Afghanistan") # Adding an element into the temp list
print(temp)
temp.pop(3) # Removing an element from the temp list
print(temp)
temp[3] = "Scotland" # Changing an element from the temp list
print(temp)
tuple1 = tuple(temp) # Converting back to tuple
print(tuple1)

# Now, adding two tuples is valid, as it creates a new tuple!
tuple2 = (1,2,3,4)
tuple3 = (5,6,7,8,9,10,10,10,11)
print(tuple2 + tuple3)
# print(tuple2 + tuple3 + tuple1) # Ye bhi kr sakte hai
# In sabko hum alag se kisi aur variable me store krke bhi print kr sakte hai aur aise bhi print kr sakte hai!

# .count() : counts number of occurences in tuples
print(tuple3.count(10))

# .index() : First occurence of an element in tuples
print(tuple3.index(10)) # it will print 5
# We can also check index within a particular slice of the tuple... for that after the element whose index we want to check, we will add two more paramters which will denote the start and end of the slice!
print(tuple3.index(10,6,9)) # it will print 6
# The method call tuple3.index(10, 6, 9) is attempting to find the index of the value 10 in the tuple tuple3, but only within the specified range of indices [6, 9).

# Lectures 26 and 27 were exercise, you can try it on your own! and their answers are in the playlist videos only!

# ------------------------------------------------------------------- Lecture 28 - String Formatting -------------------------------------------------------------------------------------------------------------->
# String formatting can be achieved in 3 ways :
# 1) Very old school C language type formating :
name = "Utkarsh"
age = 21
Message = "Hello, %s! You are %d years old." % (name, age)
print(Message)

# 2) String formatting using "{}" :
name1 = "Utkarsh"
age1 = 21
Message = "Hello, {}! You are {} years old.".format(name1, age1)
print(Message)

# 3) Now, modern method for creating formatted strings are, it is called fstrings! :
name2 = "Utkarsh"
age2 = 21
Message = f"Hello, {name2}! You are {age2} years old." # fstrings generated! using "f"string""
print(Message)

# Another Example :
name3 = "Utkarsh"
age3 = 21
Message = "Hello, {0}! You are {1} years old.".format(name3, age3) # Here, {0} & {1} refers the position of variables in the format method! and it places the values of the variable according to the format specified! so jahaa pr 0 hai vahaa format ka pehla variable ki value jayegi and jahaa 1 hai vahaa dusre ki!
print(Message)

# Another Example :
price = 99.9999
txt = f"For only {price:.2f} rupees!"
print(txt.format(price))
# So this is how we can use these fstrings!

# Now if we actually want to show those curly brackets in the output! aisa kab krna pad sakta hai? jab like maanlo apne code ko show krna chah rhe ho yaa like apna syntax dikhana chah rhe ho tab! kyunki aise toh simply variables ko replace krdega! so for that what we do is, we add one more pair of curly brackets around those variable!
message = f"Hey, my name is {{name3}}, and I am {{age3}} years old!"
print(message)

message = "Hey, my name is {{name3}}, and I am {{age3}} years old!"
print(message)
# Dono hi way me likh sakte hai!

# ------------------------------------------------------------------- Lecture 29 - DocStrings & PEP 8 -------------------------------------------------------------------------------------------------------------->
# Python docstrings are the string literals, that appear right after the definition of the function, method, class or module!
# A docstring, or documentation string, is a special type of string used in Python to document modules, classes, methods, and functions. It is a convenient way to associate documentation with Python code.
# Does it affect the functionality of the code : No, changing a docstring does not change the functionality of the code. A docstring is purely for documentation purposes and is ignored by the Python interpreter during execution. It does not affect the logic, behavior, or performance of the code in any way.
# Ek tarah se aise samajhlo ki comments hi hai, bss ye thora more documentation purpose ke liye use hota hai industries me! jaise tum jo iss VS Code pr krte ho bss vhi cheez in a more professional manner doc string krta hai! also comments ko print nhi kiya jaa sakta, but doc strings ko print kiya jaa sakta hai!
def add(a,b) :
    """This function takes input a and b, and prints their sum"""
    print(a+b)

add(4,5)
print(add.__doc__) # this statement actually prints the whole docstring!
# But to make a string a doc string, usko function, method, class ke name ke just baad likhna hoga! agar uss string ke pehle ek bhi line of code hai (comments ho sakte hai kyunki unko toh interpreter poori tarah se ignore krta hai!) then it won't be considered a docstring!

def add(a,b) :
    print("Hi")
    """This function takes input a and b, and prints their sum""" # Now it is not a doc string!
    print(a+b)

add(4,5)
print(add.__doc__) # now it will print none!

# PEP 8 : PEP 8, also known as Python Enhancement Proposal 8, is the style guide for writing Python code. It provides guidelines and best practices on how to write clean, readable, and consistent Python code. PEP 8 is widely accepted and used by the Python community to ensure that code adheres to a consistent style, making it easier to read, understand, and maintain.
# If you want you can go and give it a read to all the guidelines for PEP 8, which includes guidelines for : Indentations, Line Lengths, Blank Lines, Imports, Whitespaces, Comments, DocStrings, Naming Conventions, Avoid Trailing WHitespaces, encapsulation!

# Zen of Python : It is again a guidelines which are in form of a poem, you can write "import this", to read the whole!
#               : The Zen of Python is a collection of guiding principles for writing computer programs in the Python language. It was written by Tim Peters and can be accessed directly in the Python interpreter by running import this. The Zen of Python provides a set of aphorisms that capture the philosophy and design principles of Python.
import this # will print the zen of python! which we just talked about above!

# ------------------------------------------------------------------- Lecture 30 - Recursion -------------------------------------------------------------------------------------------------------------->
# We already know what is recursion, so lets just solve some questions using recursion!
# Find Factorial :
num = int(input("Enter number : "))
def fact(num) :
    if (num==0 or num==1) :
        return 1
    else :
        return num*fact(num-1)

print(fact(num))

# Fibonacci Value :
num = int(input("Enter number : "))
def fib(num) :
    if(num == 0 or num == 1) :
        return num
    else :
        return fib(num-1) + fib(num-2)

print(fib(num))
# Similarly you can solve more questions for understanding and practicing recursion using python!

# ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------>