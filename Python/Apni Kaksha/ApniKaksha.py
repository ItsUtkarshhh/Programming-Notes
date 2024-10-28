# print("Hello World")
# This statement is enuf in python to print the "Hello World"
# Python is used becoz it reduce the number of lines of code, Pyhton is also used in AI/ML and Backend of Web Dev and it also has other different uses
# Python is a case sensitive language

# This is a single line comment
# '''This is a multi line comment'''
# We can also code in python, in the powershell using REPL (Read Evaluate Print Loop), where we just have to write python and the powershell will accept all the python instructions and commands and will also give the output.

# name = "Utkarsh"
# age = 20 # Here the number is integer
# print(name)
# print(age)

# name = "Palak" #Here we updated the values of name and age
# age = 19.0 #Here the updated number is floating number, it can also be integer we just used to demonstrate the updation from integer to float
# print(name)
# print(age)
#Here we don't need to specify data types.

# #Taking input from the user.
# input("Enter your name : ") #Iss statement ne bss name input leliya pr usko kahin store nhi kiya, so for that we write...
# name = input("Enter your name : ") #Here the input will get stored in the name variable.
# print(name)
# print("Hello " + name) #Here we did concatination of the name input with the word Hello

# In python for there we have two syntax for division, one is "Single Slash Division" and another is "Double Slash Division" and Double Slash division is used to divide the first number with the second number and then rounding of it to nearest integer and single slash division divides the first number with second number and give the exact answer along with decimals.
# Single Slash Division : float(a/b) or a/b gives the same answer
# Double Slash Division : int(a/b) or a//b gives the same answer



#Python by default considers every input as a string format, Whatever we write in input, it considers it as a string, so for that we need tyoe conversion.
# old_age = input("Enter your old age : ")
# new_age = old_age + 2 #Here the old_age is a string type, so we have to do type casting to convert it from string to int and that will be done as...
# new_age = int(old_age) + 2 #This will work becoz we did typecasting of the string to integer
# print(new_age)
#There are other type conversions also, float() conversion, str() conversion, bool() conversion to convert the value from one to another.

# first = input("Enter the first number : ")
# second = input("Enter the second number : ")
# # sum = first + second
# # print(sum) #if we enter the first and second numbers 2 and 3 it will print 23, becoz it is a string so it will concatinate the two numbers, so to get the sum we need to use type conversion and then wehave to do the sum.
# sum = int(first) + int(second) #Type conversion from string to int.
# print(sum) #This will add the numbers mathematically
# print("The sum is : " + str(sum)) #Here also to print the whole sentence as a output we need to do the type conversion of sum from int to string so that we can print the output as the statement whose shpwing an outcome of the sum

#Strings in Python!!!
# name = "Tony Stark"
# print(name)
# print(name.upper()) #Here the on writing name. it opens different methods or can say actions we can do with the string name, so here we are using the method "Upper" which is used to convert all the letters and alphabets in the string into upper case.
# print(name.lower()) #Here we are using method name "lower" which is used to convert all the characters to lower case.
# print(name.find('T')) #Here we used another metgod of strings in python where it find the given character and if that character is in the string then it returns the index of the string otherwise it returns -1.
# print(name.find('M')) #Here it printed -1 becoz the -1 is not in the string.
# print(name.replace("Tony", "Robert Downey Jr")) #Here this method of the strings in python helps us to replace the items from the string, lik,e here it replaced the word tony with Robert downey Jr.
# print('tony' in name) #Here "in" is a keyword in python which tells us about whether the given character or string is present in the given string or not. Even if we write the wrong uppercases or lowercases, it will print false because it is case sensitive.
# print(name)


# #Some Arithematic Operators in Python.
# print(5+2) #Simple Addition
# print(5-2) #Simple Substraction
# print(5*2) #Simple Multiplication
# print(5/2) #Simple division
# print(5//2) #If the answer will be in decimals it will remove the values after decimals
# print(5%2) #It gives you the remainder
# print(5**2) #It is a power operator, it says 5^2 and NOT 2^5!!!

#Some shortcuts to do calculations in Python
# i = 5
# i = i + 2
# i += 2
# i *= 2
# i -= 2

#Operator Precedence in Python
# Result = 5 + 2 * 4 #here which one will be calculated first depends upon the operator precedence, so here in python multiplication and division have higher precendence than other + and -, so it will give answer 13.
# Result = (5 + 2) * 4 #Here if we want to add first then we have to put brackets before hand to tell the interpreter!

#Comparison Operators
# print(3>2) #They will return the boolean value, if the answer is true it will return 1 and if not then 0. 
# print(3<2) #Will print false
# print(3>=2) #Will print True
# print(3<=2) #Will print False
# print(3==2) #This operator checks whether the two operands are equal or not and here it will print False
# print(3==3) 
# print(3!=3)
# print(3!=2)

#Logical Operators
# print(3>2 or 2>3) #Unlike C++ and C here we directly write the words OR and AND to use logical operators
# print(3>2 and 2>3)
# print(not 3>2)

#Conditional Statements : If Else
# age = 19
# if age>=18 :
#     print("You are an Adult")
#     print("You can vote")

# elif age<18 and age>=3 :
#     print("You are in School")

# else :
#     print("You are a Child")

# print("This statement is out of Else If Statements")

#Range in Python
# range(5) #It means we are telling interepreter to return values from 0 1 2 3 4 but not the last number that us 5.
# numbers = range(5)
# print(numbers)

#Loops in Python : While
# i = 1
# while i<5 :
#     print(i) #Here it will print simple 5 numbers one after another 
#     i = i + 1

# i = 1
# while i<=5 :
#     print('*') #Here it will print 5 stars one after another 
#     i = i + 1

# i = 1
# while i<=5 :
#     print(i * '*') #Here the star will concatenate with the help of i and it will get printed and will print a triangle of stars
#     i = i + 1

# i = 5
# while i>=0 :
#     print(i * '*') #Here it will print the triangle of stars in reverse order 
#     i = i - 1

#Loops in Python : For
# for item in range(5) : #Here we used three keywords for and in and range, where for keyword is used to intialize the loop and then in keywords to tell that from where we have to get the range and then range range keyword to tell the range.
#     print(item)


#Lists in Python!
# Marks = [97, 98, 99, "Maths", "Physics", "Chemistry"] #List can contain different data types also, like here it contains int and string.
# print(Marks) #Will print all the items in the list Marks
# print(Marks[0]) #Will print the item at the 1st position
# print(Marks[3]) #Will print the item at the 4th position
# print(Marks[-1]) #Will start the counting backwards and will print the item at the last position
# print(Marks[-2]) #Will print the item at the second last position
# print(Marks[2:5]) #Will print the item from the 3rd position to 6th position

# Marks = [98, 99, 100]
# for score in Marks :
#     print(score) #It will print all the scores one by one, here we printed the items in the list using the for loop

#Now like in string there were different operations then similarly in List there are different operations too, like...
# marks = [90, 91, 92]
# marks.append(94)
# print(marks)

# marks.insert(0, 89)
# print(marks)

# print(93 in marks) #they are to check whether the item 92 or 90 exist in the list or not and as per the answer it will print true or false.
# print(90 in marks)

# print(len(marks))

# marks.clear() #here the clear operation is used to clear the list
# print(marks)

#Operating List using While loop
# marks = [90, 91, 92]
# i = 0
# while i < len(marks) :
#     print(marks[i])
#     i = i + 1

#Break & Continue Statements
# Students = ["Ram", "Shyam", "Khushi", "Abhimanyu", "Vishal", "Aditya"]
# for Student in Students :
    # if Student == "Khushi" :
    #     break
    # print(Student)
    # if Student == "Shyam" :
    #     continue
    # print(Student)


#Tupple in Python!!
#Once we have made a tupple it can't be modified or changed
# Marks = (98, 97, 96, 95, 95, 95, 95) #In tupple paranthesis are not mandatory we can write a tupple without the paranthesis also
# # Marks = 98, 97, 96, 95, 95, 95, 95 #It is also by default a tupple!
# #We can perform two operations on tupple that is first we can count and another we can get the index of that tupple
# print(Marks.count(97)) #It counts 1
# print(Marks.count(95)) #It counts 4

# print(Marks.index(98)) #It gives 0
# print(Marks.index(95)) #It gives the index of the first 95 that is 3


#Sets in Python!!
#They are intialized using curly braces {}
# marks = {90, 91, 92, 93, 94, 95, 95, 95, 95, 95, 95} #In these repeated values wont get printed!
# print(marks)
# for score in marks :
#     print(score)
# print(marks[0]) #We can do this as becoz sets me koi index nhi hota becoz they are un ordered unlike tupple and list where they were ordered



#Dictionary in Python!!
#Dictionary is used to store values in pairs, like for example kisi student ki info store krni hai toh vo hum student ke name ke saath pair bnaa ke uska birthday, father name mother name sab saath me ek pair me store kr sakte hai!
# marks = {"Maths" : 95, "Chemistry" : 96} #Here it is like a dictionary which contains info of some particular thing like here it is subject marks.
# print(marks["Maths"]) #Here we printed marks by directly writing the subject, yahaa index nhi use krna padaa
# marks["Physics"] = 94 #here we inserted another subject marks into the dictionary
# print(marks) #Here we have printed those marks
# marks["Physics"] = 98 #Here we updated those marks
# print(marks) #Here we have printed updated marks


#There are 3 types of Function in Python!
# In build Functions : The functions like we have used for type conversion like int() str() to convert from one type to another so they are inbuild function!
# Module Functions : There are different modules in Python like in C++ there were Libraries so here are modules which contains different pre defined functions, one of the moduke is Math, which contians all the mathematical functions
# User Defined Functions : These are the functions which we define by ourselves

#Module Functions
#To include that module we need to write...
# import math
# print(dir(math)) #It will print all the predefined functions Math module contains! for example we want to use square root function only from math module then we write...
# from math import sqrt
# print(sqrt(4))
# print(sqrt(10))
# print(sqrt(16)) #so here we were using sqrt function from math module

# from math import * #This line says, from math module import all the functions! unlike above we have just imported sqrt function of math module!


#User Defined Functions
# def function_name (pramters) :
#     do something
# def print_sum (first, second) : #Here we wrote the functions defintion! Now we need to call it...
#     print(first + second)

# #Calling the above function
# print_sum(1,5) #Here it will print 6

# def print_sum (first, second = 4) : #Here we wrote the functions defintion! but here we already intialized one of its paramter, so this time we need to give just one more paramter in the function call and now we need to call it...
#     print(first + second)
# #Calling the above function
# print_sum(6) #Yahaa humne bss ek hi parameter pass kiya, to ye upar me defintion me jo value likhi hai usse add krke output dedega!
# print_sum(6, 10) #Pr yahaa humne do paramters de diye toh yahaa ye defintion ko chhor ke yahaa jo do paramters me jo values likhi hai unko according output dega!
#In short if we intialize the parameter in defintion then that becomes by default that if in function call no second paramter wil be paased THEN it will proceed with the value intialized for the second paramter in the funtion defintion! 