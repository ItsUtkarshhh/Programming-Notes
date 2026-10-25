# ------------------------------------------------------------------- Lecture 1-5 - Python Basics -------------------------------------------------------------------------------------------------------------->
# Python!
# Python is simple and easy to understand!
# It is interpreted and platform-interpreted which makes debugging very easy!
# Python is open-source programming language!
# Python provides very big library support! some popular libraries include numpy, tensorflow, selenium and openCV!
# It is possible to integrate other programming languages with python!
# Python can be used for : Data Visuallization to create plots and graphical representation!
#                        : Data Analysis to analyse and understand raw and unstructured data!
#                        : AI/ML to stimulate human behavior!
#                        : It can also be used to handle databases!
#                        : It is used in business and accounting to perform complex mathematical operations along with with quantitative and qualitative analysis!

# Starting with Python :
print("Hello World")

# Modules and Pip
# Modules basically is used for borrowing code, like kisi aur ke dwara likhe gye code ko hum apne liye use kr sakte hai! and now there are two types of modules!
# 1) External Modules : Modules which are created by someone else and we can use someone else codes in our program! means, these modules are imported from a third party file or can be installed using a package manager like pip or conda, since this code is written by someone else, we can install different versions of same modules with time!
# 2) Built-In Modules : Modules which are already available in Python language! means these modules are ready to import and ships with python interpreter, there is no need to install such modules explicitly!

# pip or conda are package managers! like jab python install krte hai toh kaafi saare modules hote hai jo hum alag alag type ke task le liye use krte hai! toh pip is a package manager, ki hum pip ke saath jo command likhenge pip vo command execute krdega! like if we write, pip install pandas, then pip will install pandas on our PC! isko aise lelo ki jaise mummy jab hume bahar se koi samaan laane ke liye bolti hai toh bss hum pip ka kaam hi kr rhe hote hai!
# bss vaise hi jaise jo cheeze ghar me already hote hai unko bahar se laane ki zarurat nhi hoti! like jaise ghar me refrigerator hota hai usko laane ki zarurat nhi hai! so bss vhi pip jo already existing modules hai vo unko nhi, jo external modules hai unko laane ke kaam krta hai, jaise upar humne pandas install kiya! as pandas is an external module!

# Some more programs
print("Hi") # Its a string value
print(5) # Its a integer value
print(3*2) # It will calculate product and print it!
# Some basic things we won't elaborate here!

# Escape Sequence :
# Example :
# print("My name is
#       Utkarsh") -> Agar koi cheez next line me likhni hai uske liye \n lagana padega, aisa nhi ki bss seedha new line me likhdo! jaise cout me tha! yahaa pr escapte sequence use honge, which is \n here! also becoz python me indentations matter krte hai bhot! hence correct way of writing this is...
print("My name is\nUtkarsh")

# More examples of escape sequence : lets understand them with example...
print("My name is Utkarsh, I am in my \"4th\" year!") # We know ki agar hume koi aisi cheez print krni hai jisme hume double quote use krna hai to uss case me hum seedha double quotes me confuse hojayega ki konsa double quote print() me string pass krne ke liye hai and konsa "double quotes" lgane ke liye! so for that we use \" (Back Slash Double Quote) and same thing goes with single quoted string & backslash single quotes!
print("Hey!",5,10) # in python we can do this also ki print me multiple cheeze pass and print kr sakte hai! and then there is separator, which separates the output with the value in the separator! example in the next line...
print("Hello",5,10,sep="~") # Iske saath saath ek aur parameter hota hai print me that is end, which says ki next line se pehle and iss line ke execution ke baad kya print krna hai!, example is in the next line...
print("Hello",5,10,sep="~",end="001\n") # Iska ye mtlb ki iss line ke end me ye end me jo likha hai vo append krdena! and along with end humne yahaa pr \n bhi use kiya hai toh iske baad next line hojayegi! vaise vo toh by default bhi ho rhi thi!
# See, default sep blank space hota hai and default end \n hota hai! agar hum sep ko explicitly define krte hai jaise humne upar kiya then in that case jo humne sep me value pass ki hai vo sep banega! and similarly agar humne end ko specify krdiya then \n jo default tha vo hatt jayega and ab jo hum end me value pass krenge vo cheez hogi current line ke execuition ke baad! means...
print("Hello",5,10,sep="~",end="001") # Kyunki humne yahaa pr \n specify nhi kri isliye yahaa pr next line me cursor nhi gya current line ke execution ke baad! and isliye ye line and iski next line dono saath me print hue same line me!
print("Huh")

# Comments : You are already doing it!, there are multiple ways : #, ''' ''' or """ """.

# ------------------------------------------------------------------- Lecture 6 - Variables & Datatypes -------------------------------------------------------------------------------------------------------------->
# Variable :
a = 1 # It means meri jo computer ki memory hai usme 1 store krdo and then uska address print me dedo taaki vo print krde vo value!
print(a)

b = "Utkarsh"
print(b)
# Python me data types jo value hum assign krte hai variable ko uss hisaab se automatically assign hojaate hai! hume isme alag se int likhne ki zarurat nhi! until unless type casting krni ho...

# but lets see ki hum string me double quotes kyu lgaate hai! so vo isliye... kyunki agar naa lagaye toh dekho kya hoga...
Utkarsh1 = 5
c = Utkarsh1
print(c) # Toh isme mai chah toh rha ki "Utkarsh1" print ho pr kyunki humne double quotes lgaa diya hai usme, toh "Utkarsh1" ek variable ki tarah treat hoga! and ab koi "Utkarsh1" ki bhi value set kr sakta hai! hence isliye hume strings me double quotes lgaana hota hai! taaki btaa sake interpreter ko ki kis cheez ko as a string understand krna hai!

# There are mainly these data types in python... and further we will study more...
# Integer
a1 = 1
print(type(a1)) # <class 'int'>

# Float
b1 = 3.14
print(type(b1)) # <class 'float'>

# String
c = "Hi"
print(type(c)) # <class 'str'>

# Boolean
d = True
print(type(d)) # <class 'bool'>

# Complex
e1 = 2 + 3j
print(type(e1)) # <class 'complex'>
# or we can also make complex numbers like this...
e2 = complex(2,3)
print(type(e2)) # <class 'complex'>

f1 = None
print(type(f1)) # <class 'NoneType'>

# Apart from these there are more data types, like...
# Sequenced Datatypes : list & tuples!
# Mapped Datatypes : dictionary
# And some more...

# Note : For now just remember this thing for future concepts, that in python, everything is an object!

# Lecture 7 & 8 are for making calculator! and different operators, so those different operators are : + (Addition) - (Subtraction) * (Multiplication) / (Division) % (Modulus) // (Floor Division : Divides the two numbers whether int or float and returns the nearest integer! and the resultant integer is always the floor one not the ceil one!) ** (Exponential)
# ------------------------------------------------------------------- Lecture 9 - Typecasting -------------------------------------------------------------------------------------------------------------->
# Typecasting : Explicit converting a datatype into another!
# Some functions for typecasting is : int() float() str() hex() oct() set() list() tuple() dict()!
# Strings ko add krne ki koshish kroge toh vo concatenate hojayegi! kyunki mathematical addition ka koi sense nhi hai strings ke case me! also aisa nhi kisi ko bhi kisi me convert kr sakte hai, jaise agar ek string me name = "Utkarsh" likha hai and agar hum ye likhde ki print(int(name)), toh here it will show error, becoz this just does not make sense! and has no meaning!

# Explicit Conversion & Implicit Conversion! : We know both of them!

# ------------------------------------------------------------------- Lecture 10 - Taking Input -------------------------------------------------------------------------------------------------------------->
# User input in python is taken with the help of input() function! and ye input function humesha ek string input me leta hai! and then uss input ko hume apne hisaab and use case ke accoring type caste krke use krna hota hai!
name = input("Enter your name : ")
print("My name is",name) # It will simply print the input name which will be simply a string!

num1 = input("Enter 1st number : ")
num2 = input("Enter 2nd number : ")
print(num1 + num2) # It will just concatenate the two numbers, so we need to typecaste the num1 and 2
print(int(num1) + int(num2)) # or we can also do is, ki jo final output aaya hai usko hi sirf type caste kre...like...
print(int(num1 + num2)) # Isme dono num1 and 2 concatenate toh string ki tarah hi hue honge! but jab unko use kiya jayega kahin toh vo int ki tarah behave krega iska ouptut! as you can see below...
f1 = int(num1 + num2)
f2 = 3
print(f1 + f2)

# And agar integer me hi input lena toh seedha input ko hi int me typecaste krdo!
new_num = int(input("Enter the number : "))
print(new_num)
print(new_num + 3) # This proves that the input is an integer this time, kyunki input func ne toh string ki tarah hi input liya, vo toh maine baad usko int me typecaste krdiya!

# ------------------------------------------------------------------- Lecture 11 - Strings in Python -------------------------------------------------------------------------------------------------------------->
name = "Utkarsh" # One way to define string in python
name2 = 'Verma' # another way to define string
name3 = "Utkarsh said, \"He don't way to eat the dinner\"" # Another way of define some strings with double quotes
name4 = 'Utkarsh said, \'He don\'t want to eat the dinner\'' # Another way of defining strings with single quotes
# If we want to print strings as it is jaise hum likhe usko, so for that, we can use ''' ''' or """ """, iski help se bhi strings ko define kr sakte hai! isse string hum jis form me likhenge uss hi form me rahegi! and also iske through hum next line bhi add krenge toh vaise ka vaise print ho jayegi next line, and ye cheez hum \n se bhi kiye hai upar!
name5 = '''Utkarsh is 
        happy!'''
name6 = """Utkarsh is
        happy!"""

# Printing all the strings
print(name)
print(name2)
print(name3)
print(name4)
print(name5)
print(name6)

# Also we can access individual characters of the strings also! using "[]"
print(name[0])
# Strings are "like" an array of characters, but not exactly array of characters!

# If we want to print all the characters of a string, we will use loop, for now just have quick look... and further we will study more...
for ch in name4 :
    print(ch)
# In python keep this thing in mind while running commands ki yahaa pr line by line execute hote hai commands, toh yaahaa pr thora dhyaan se commands run krna... and uske according hi samjhne ka try krna!

# ------------------------------------------------------------------- Lecture 12 - Strings Slicing and Operations on Strings -------------------------------------------------------------------------------------------------------------->
full_name = "Utkarsh Verma"
# Length Function
print(len(full_name)) # Will print length of the string, len() return the length of the string, we can keep that value in a variable and then print the value of that variable also! dono tareeke valid hai iss case me ki directly print krdo ya variable me daal ke print krdo!

# Slicing in Python with +ve indexing
print(full_name[0:5]) # Will print all the values from 0th index to 4th index
print(full_name[:5]) # Will print the same as above!
print(full_name[1:]) # Will print all the indexes from 1 to end
print(full_name[:]) # Will print the full string

# Slicing in Python with -ve indexing
print(full_name[0:-6]) # Here, in case of negative indexing, python khud hi -ve index se pehle len(full_name) lgaa lega, and fir uske hisaab se output dega!
print(full_name[0:len(full_name)-6]) # Here it will print the same as just above!
print(full_name[-3:-2]) # Again yahaa pr bhi python len(full_name) lgaa lega!
print(full_name[len(full_name)-3:len(full_name)-2]) # It will print the same as just above!
print(full_name[-1:-5]) # It will return an empty string! kyunki agar dhyan se dekho tab ptaa chalega ki yahaa toh hum higher index to lower index jaa rhe hai!
print(full_name[-1:-1])
print(full_name[1:1]) # Both of the above lines will print empty string! as becoz start index is 1 and end index is also 1, when both indexes are same, then we know basically kya hua hoga logically, 1->1-1 = 1->0 and here end index is greater than start index, hence it will again print empty string! ya isko lame bhasha me aise dekhlo ki jiss index se shuru kiya uss hi index ko slice bhi krdiya.

# Note : What we understood from all this, is that in case of slicing, if it is written like this, full_name[x:y], here slicing will be done from x->y-1, and -ve indexing ke case me pehle len(string) se subtract hota hai and uske baad fir yhi same cheez hoti hai!

# ------------------------------------------------------------------- Lecture 13 - Strings Methods in Python -------------------------------------------------------------------------------------------------------------->
# First remember! strings are immutable! means strings ko ek baar declare krdiya toh usko aage kisi operation me jaake uss hi string ko change nhi kr sakte! haa uss hi string ki copy pr operations perform krke changes kr sakte ho! but original string me koi change nhi ayega!
# Lets understand with examples...
college = "SRM Institute of Science and Technology"
# Lets apply some string methods on this string... so what string methods do? kyunki original string me toh koi changes nhi kr sakte! toh ye original string pr operate krte hai and then ek nayi string return krte hai!

# .upper() :
print(college.upper()) # Makes a copy of the original string and then comverts it to uppercase! ab yaa toh hum ek variable me store krke print kre ya seedha seedha hi print krde! that is upto us!

# .lower() :
print(college.lower()) # Same as of above about uppercase!

# .strip() :
college2 = "SRM Institute of Science and Technology!?!"
print(college2.rstrip('!')) # It only removes or strips the trailing characters! here output will be "SRM Institute of Science and Technology!?"

# .replace() :
college3 = "Kya baat hai Kya baat hai Kya baat hai"
print(college3.replace("Kya","Huh")) # It replaces all the occurence of a particular string or character! mtlb individual characters ko bhi replace kr sakta hai and poori strings ko bhi
print(college3.replace("Kya","Huh")[0]) # Aise bhi likh ke string ke elements print kr sakte hai!

# .split() : ye input ke hisaab se string ki different lists bnaa deta hai!
print(college.split(' ')) # here maine input me space daala hai, mtlb ki ab interpretor spaces count krega! and jitne spaces input me hai utne spaces jaha jahaa string me hai uske according lists create krdega!

# .capitalize() : Capitalizes the first character of the string! and remaining all characters are converted into lowercase!
college4 = "srm institutE of sciencE and Technnology"
print(college4.capitalize())

# .center() : Provides spaces on the left according to the input!
print(college.center(50)) # It will calculate the len of the string and then input me jo aaya hai unn dono ke hisaab se calculate krke spaces add krega, for examle in this case, ye nhi hua hai i seedha 50 spaces add krdiye! balki yahaa toh ye hua hai ki |len(string) - input_value| iske according spaces add kiye jaate hai! hence iss case me 11 spaces add hue hai!
print(len(college.center(50))) # Will print 50
print(len(college)) # Will print 39

# .count() : counts the input in the string!
print(college.count("e"))

# .endswith() : It checks that whether the string is ending with a particular string or not?
college5 = "SRM institute of science and technology"
print(college5.endswith('y')) # Will print true
print(college5.endswith("y")) # Will print true
print(college5.endswith('x')) # Will print false
# Also we can check ki kisi ek range me kya kisi ek value se end ho rhi hai ki nhi! upar vaale case me default me values 0th index to end-1 index ki hoti hai! but we can also customize this...
print(college5.endswith("In",0,6)) # It means, ki hum is range "SRM In" me check kr rhe hai ki kya "In" se ho rha hai ki nhi! ofc range is again including 0 and excluding 6, means 0-5

# .find() : return the first occurence of a input string or character! if not found returns -1
print(college5.find("te"))

# .index() : Almost similar to .find() just the difference is isko agar nhi milta vo char ya string tab ye error throw krta hai!
print(college5.index("te"))
# print(college5.index("ts")) Will return an error!

# .isalnum() : Checks whether the string is alpha numeric or not! alphnumeric are those strings which consists only A-Z or a-z or 0-9
name6 = "UtkarshVerma"
print(name6.isalnum()) # It will return true! even agar name6 spaces contain krta tab bhi false aajaata!

# .isalpha() : Return true if the string contains A-Z or a-z otherwise return false!
name7 = "Utkarsh14"
print(name7.isalpha()) # returns false
print(name7.isalnum()) # return true

# .islower() : return true if all the characters are in lowercase! otherwise false
print(name7.islower()) # return false

# .isprintable() : returns true if the string does not contain any non-printable characters! non-printable characters are like \n and similar characters are non-printable, kyunki ye print nhi hote!
name8 = "Utkarsh\nVerma"
print(name8.isprintable()) # It will print false, kyunki isme ek non-printable character hai which is \n
name8 = "Utkarsh\'Verma"
print(name8.isprintable()) # It will print true, kyunki isme koi non-printable character nhi hai! \' ye ek non-printable character nhi hai!

# .isspace() : return true if the string contains only spaces or tabs otherwise false
print(college5.isspace()) # returns false
print(name7.isspace()) # returns false
space = "   "
print(space.isspace()) # returns true

# .istitle() : return true if only the first letter of each word in the string is capital! otherwise false!
name9 = "Utkarsh Verma"
name10 = "utkarsh Verma"
print(name9.istitle()) # return true
print(name10.istitle()) # return false

# .startswith() : does the same work as endswith() but in opposite sense!
print(name9.startswith("Ut"))
print(name9.startswith("Ve",8,10))

# .swapcase() : switch capital to small and small to capital
print(name9.swapcase())

# .title() : converts all the first characters of each word into capital!
print(name10.title())

# ------------------------------------------------------------------- Lecture 14 - If-Else Statements -------------------------------------------------------------------------------------------------------------->
# If-else statement!
age = int(input("Enter your age : "))
print("Your age is : ",age)
# Conditional Operators! > < >= <= == !=
if(age>18) :
    print("you can drive!")
else :
    print("You can not drive!")
# In if-else statements indentation matters!

# If-elif-else stataments
age1 = int(input("Enter your age : "))
if(age1>18) :
    print("you can drive!")
elif (age1 == 18) :
    print("Get a license!")
else :
    print("You can not drive!")
# Now we also have nested if-else, that we already have studied syntax is also same like above! and logic is same as of we have done in C/C++!
# Lecture 15 is normal practice!

# ------------------------------------------------------------------- Lecture 16 - Match-Case -------------------------------------------------------------------------------------------------------------->\
# it is all same as switch case, just one difference is that instead of switch write match!
# Another difference here is from C++ is that, yahaa pr break statement nhi hota hai! kyunki yahaa pr sirf vhi case run hota hai jiska case match hota hai! aur baaki fir nhi hote hai!
# Another difference here is, default case ko _ se represent krte hai!
# Lets see an example :
week = int(input("Enter number 1-7 : "))
match week :
    case 1 :
        print("Sunday")
    case 2 :
        print("Monday")
    case 3 :
        print("Tuesday")
    case 4 :
        print("Wednesday")
    case 5 :
        print("Thursday")
    case 6 :
        print("Friday")
    case 7 :
        print("Saturday")
    case _ : # Default case!
        print("Invalid Week")

# Now if we want to check the same thing age and whether the person can drive or not! for that hume default cases me if-else lgaake use krna hota hai! so it will be like...
age2 = int(input("Enter your age : "))
match age2:
    case _ if age2 < 18:
        print("Too young to drive.")
    case _ if age2 == 18:
        print("Just eligible to drive.")
    case _ if age2 > 18:
        print("Old enough to drive.")
    case _:
        print("Invalid age.")

# ------------------------------------------------------------------- Lecture 17 - For-Loops! -------------------------------------------------------------------------------------------------------------->\
# For-Loop in Python!
# For Loops can iterate over a sequence of iterable objects in python! Iterating over a sequence is nothing just iterating over strings, lists, tuples, sets and dictionary!
# Iterating over strings :
my_name = "Utkarsh"
for i in my_name :
    print(i,end=", ") # end is just used taaki ek line me dikhe output and naa ki next line me!

colors = ["red", "yellow", "blue", "green", "pink"]
for color in colors :
    print(color,end=", ")

# We can further create loop also for individual strings also!
for color in colors :
    print(color,end=", ")
    for i in color :
        print(i,end=", ")

# range() function! : Here if we write range(6) it means from 0-5, and we will use this in loop!
for i in range(5) :
    print(i+1)

for i in range(1,11) : # Here we have used range function with two parameters, one will denote the start and other will denote the end (which will actually end at end-1)
    print(i,end=" ")

for i in range(1,11,2) : # Here the 3rd argument is the step argument, which means it skips the next iteration and prints the third one!
    print(i,end=" ")

# ------------------------------------------------------------------- Lecture 18 - While-Loops! -------------------------------------------------------------------------------------------------------------->\
# While-Loops in Python!
i = 0
while(i<10) :
    print(i)
    i = i + 1
print("Out of the while loop!")
# And variety of while loops we already know!

# now the thing is in python, there is no syntax do-while loop! but to use its functionalties in python we may need to create it on our own!
# Initial setup
condition = True
while condition:
    # Loop body: put your code here
    print("This will always execute at least once.")
    
    # Update the condition based on some logic
    condition = False  # Set this condition to False to break the loop
# Here the print statement will execute atleasy once! so to create do while loop, we need follow the similar fashion!

# ------------------------------------------------------------------- Lecture 19 - Break & Continue in Python -------------------------------------------------------------------------------------------------------------->\
# We know what they do!
# Break : Exit from the immediate loop
# Continue : Skips the immediate next iteration!
for i in range(12) :
    print("5 x",i+1,"=",5*(i+1))
    if(i==9) :
        break
# It will print the table of 5 from 1-10

for i in range(15) :
    if(i==9) : # 5*10 is skipped! becoz of continue!
        continue
    print("5 x",i+1,"=",5*(i+1))

# Creating Do-While-Loop in Python : In python the most commonly it is done with the help of infinite while loop!
i = 0
while True : # created an infinite loop!
    print(i) # Executed the task one time!
    i = i + 1
    if(i%100 == 0) : # And after that, checked the condition for every next iteration! vrna while loop me tha ki pehle condition check hogi uske baad hi execute hoga while loop! pr yahaa humne ek baar toh execute kraa hi liya uske baad se iterations check krne lage!
        break

# ------------------------------------------------------------------- Lecture 20 - Functions in Python -------------------------------------------------------------------------------------------------------------->\
# There are two types of functions : Built-In and User-Defined, we already know what are these!
# This is how we define user-defined functions! using "def" keyword!
def calculateMean(a,b) :
    ans = (a+b)/2
    return ans # Here we have used the return statament, hum print bhi kra sakte hai!

a = 2
b = 3
print(calculateMean(a,b)) # return karaya hai isliye directly print bhi kr sakte hai ya kisi variable me store krke bhi print kr sakte hai! agar print kraya hota function me toh bss function ka naam likhna kaafi hota!

# If we want to declare a function but don't want to define it right now, then we use "pass" keyword!
def sum(a,b) :
    pass

# ------------------------------------------------------------------- Lecture 21 - Functions Arguments in Python -------------------------------------------------------------------------------------------------------------->\
# There are 4 types of function arguments :
# Default Arguments
# Keyword Arguments
# Variable Length Arguments
# Required Arguments

# Required Arguments : Jo chahiye hi hote hai function ko apna kaam krne ke liye!
# Default Arguments : Agar koi argument pass nhi kiya jaaye toh default vaale se kaam chlaa lete hai!
# Keyword Arguments : Now maanlo function define kiya gya hai, ab vo chaahe default arguments ya required arguments ko use krke kiya gya hai! that does not matter! keyword arguments are known from its function call! agar function call me hum vhi exactly same arguments ke naam use kr rhe hai jo function ke defintion me use kiya gya hai! then we call it a keyword argument!
# Variable Length Arguments : Isme jo function iss tarah se defined hota hai ki vo multiple number of arguments le sakta hai!

# Example : Function using Required Arguments
def sum(a,b) :
    print(a+b)

sum(4,5) # Here 4 and 5 were required arguments, kyunki inke bina function call nhi hota!

# Example : Function using Default Arguments
def sum(a=5,b=6) :
    print(a+b)

sum() # here it has used the default arguments
sum(3,2) # here we have provided our own arguments

# Example : Function using Keyword Arguments
def greet(name,message) :
    print(message + " " + name)

greet("Hi","Utkarsh") # here it will print Utkarsh Hi, but we want Hi Utkarsh, so for that we need to specify ki konsi value kahaa jaani hai! so for that we will use keyword arguments!
greet(name="Utkarsh", message="Hi")
# Ab isme hum required and default ko bhi add krke bhi example bnaa sakte hai...

# Example : Function using Variable Length Arguments
def average(*numbers) : # Aisa krne se ye input ko ek tuple ke form me leleta hai! iske baare me aage aur detail me padhenge!
    sum = 0
    for i in numbers :
        sum = sum + i
    print("Average is : ",sum/len(numbers))

average(1,2,3)
average(1,2,3,4,5,6)
average(1,2,3,4,5,6,7,8,9,10)

# ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------>