# ------------------------------------------------------------------- Lecture 52 - Lamda Function in Python -------------------------------------------------------------------------------------------------------------->
# A lambda function is a quick and simple way to create a small function in Python without giving it a name. you can give it a name also
# Isse kya hoga jo small functions hai unko hum normally ek varaible ke form me bhi likh sakte hai!
# And through this we can also pass functions as arguments in another function!
# Lets try this...

# Lambda functions created using keyword "lambda" :
square = lambda x : x*x
cube = lambda x : x*x*x
add = lambda x,y : x+y
avg = lambda x,y,z : (x+y+z)/3

# All of them called :
print(square(2))
print(cube(2))
print(add(2,3))
print(avg(2,3,4))

# Now lets pass these functions as an argument into some other functions!
def addition(value,fx) :
    return 6 + fx(value) # yahaa pr kyunki humne isko return iss tarah se karaya hai isliye ab fx ki jagah hume ek function bhejna hoga vrna it will show error!
i = 5
# addition(5,i) # it will give error!
ans = addition(5,cube)
print(ans)

def addition2(value,fx) :
    return 10 + fx(value)
print(addition2(3,lambda x : x*x)) # Here we have used lambda functions without any name, that is why they are also called anonymous functions!
# Here we can use small functions as variables
# Note : Kinda works on a similar goal as of inline functions in C++, but ofc they are not same!

# ------------------------------------------------------------------- Lecture 53 - Map, Filter and Reduce in Python -------------------------------------------------------------------------------------------------------------->
# Map, Filter and Reduce are not only limited to python! and it can not only be used with lists!
# lets first see, what is Map, Filter and Reduce!

# Suppose a function :
def cube(x) :
    return x*x*x
# and now I have lists of integers :
l1 = [1,2,3,4,5,6] # And now I want to find the cube of all the items in the list l1!
# so one thing that we can do is... use for loop...
newl = []
for item in l1 :
    newl.append(cube(item)) # it will return a newl which will contain the cube of all the original list items! also yahaa hum cube ki jagah lambda function bhi use kr sakte hai!
print(newl)

# But now lets do the same thing with "map()"...
# map() : map is used to apply a function to every item in a list (or any iterable) and returns a new list with the results. its syntax is : "map(function,iterable)" ek jagah hum koi function daalte hai dusre jagah hum ek iterable cheez daalte hai jiske harr item pr automatically vo function apply hojayega!
newl = list(map(cube,l1)) # l1 ke sab items pr cube vaala function chlaa do! but yahaa kaam over nhi hua, kyunki map ek iterator return krta hai map ke saare element pr chalaane ke liye, humare upar hai ki hum uss iterator ka kya krte hai, generaly hum map ko list me typecast krdete hai! jo humne yahaa bhi kiya hai!
print(newl)

# filter() : filter is used to create a list of elements for which a function returns True. so means hum ek function banaate hai jo ek iterable object ko filter krdeta hai kuch conditions ke basis pr! lets call it filter function! (ye filter function agar chhota hai toh isko hum lambda functions ke through bhi likh sakte hai)
l2 = [1,2,3,4,5,6,7,8,9,10]
def filter_function1(x) :
    return x%2==0
newl2 = list(filter(filter_function1,l2)) # it will filter the list items based on the filter function condition and then will return an iterator jisko hum list me again type cast kr sakte hai!
print(newl2) # will print all the even numbers of the list! by the way list is mutable so you can do changes in the original list also, but okay yahaa concept is more imp!
# jo function dusre function ko as a argument lele ya return me ek function return kre usko hum higher order function boldete hai! high order functions hum lamda ka use krke bnaa sakte hai! yahaa map, reduce and filter and jaise humne upar ek function banaya tha addition, vo bhi ek higher order function tha!

# reduce() : A single value that results from applying the given function cumulatively to the items of the provided iterable. ek tarah se ye ek single value return krta hai isko hum ek list (or any iterable object) ke saare items ka avg ya sum ya aisa kuch nikalne ke liye use kr sakte hai!
# Isko import krna padta hai, aise hi nhi available hota ye!
from functools import reduce
numbers1 = [1,2,3,4,5,6,7,8,9,10]
# sum = reduce(lambda x : x>5, numbers1) # if we write this, it will throw the type error! kyunki isme kya ho rha hai ki reduce ke andar koi bhi function hoga toh usko do arguments lene honge taaki vo list ya kisi bhi iterable object ke items pr iterate krke ko ek single value nikal sake! kyunki yhi kaam hai reduce ka! isliye type error aa rha hai! which is : <lambda>() takes 1 positional argument but 2 were given
sum = reduce(lambda x,y : x+y, numbers1) # This is fine!
print(sum)

# ------------------------------------------------------------------- Lecture 54 - Difference between "is" and "==" in Python -------------------------------------------------------------------------------------------------------------->
# General Concepts
# is : Compares the identity of two objects, i.e., whether they refer to the exact same object in memory.
# == : Compares the values of two objects, i.e., whether they have the same contents.

# Memory Allocation in Python : Python manages memory based on the mutability of objects :
# Immutable Objects : Objects like integers, strings, and tuples cannot be changed after creation. Python often reuses memory for these objects to optimize memory usage.
# Mutable Objects : Objects like lists, dictionaries, and sets can be changed after creation. Python allocates separate memory locations for different instances, even if their contents are initially the same.

# "is" and "==" with Mutable Objects :
# Mutable objects are objects whose state or contents can change after they are created. When two variables are assigned mutable objects, they generally refer to different memory locations, even if their contents are identical.
# Example 1: Identical Lists
a = [1, 2, 3]
b = [1, 2, 3]
print(a is b)  # False (different objects in memory)
print(a == b)  # True (same contents)

# Example 2: Different Lists
a1 = [1, 2, 3, 4]
b1 = [5, 6, 7, 8]
print(a1 is b1)  # False (different objects in memory)
print(a1 == b1)  # False (different contents)

# Example 3 :
c1 = a1
print(a1 == c1)  # True (values are the same)
print(a1 is c1)  # True (same object in memory)

# "is" and "==" with Immutable Objects :
# Immutable objects cannot change after they are created. Python often reuses memory for identical immutable objects (like small integers and interned strings) to save space, but this behavior is not guaranteed for all cases, especially with larger objects or dynamically created objects.
# Example 1: Identical Tuples
a2 = (1, 2, 3)
b2 = (1, 2, 3)
print(a2 is b2)  # False (not necessarily the same object in memory)
print(a2 == b2)  # True (same contents)

# Example 2: Small Integers
c2 = 100
d2 = 100
print(c2 is d2)  # True (small integers are cached and reused)
print(c2 == d2)  # True (same contents)

# Example 3: Large Integers
e2 = 1000000000
f2 = 1000000000
print(e2 is f2)  # True (small integers are cached and reused)
print(e2 == f2)  # True (same contents)
# Typically: For large integers, Python does not guarantee that the same value will have the same memory address. Therefore, is usually returns False.
# In This Case: If e2 is f2 returns True, it suggests that Python has optimized memory usage in this instance and is reusing the same memory location for both e2 and f2. This can happen due to specific optimizations or caching in the Python interpreter or version you are using.

# Example 4: Strings
g2 = "hello"
h2 = "hello"
print(e2 is f2)  # True (string interning for small strings)
print(e2 == f2)  # True (same contents)

# ------------------------------------------------------------------- Lecture 55 - Snake Water Gun Game! -------------------------------------------------------------------------------------------------------------->
# This was a exercise lecture!

# ------------------------------------------------------------------- Lecture 56 - OOPS in Python -------------------------------------------------------------------------------------------------------------->
# This will continue in the OOPS in Python by CWH Folder!

# --------------------------------------------------------------------------------------------------------------------------------------------------------------------------------->