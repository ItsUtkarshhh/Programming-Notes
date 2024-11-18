# ------------------------------------------------------------------- Lecture 41 - If-Else Shorthand -------------------------------------------------------------------------------------------------------------->
# Way 1 of using shorthand :
a = 30
b = 25
print("A") if a>b else print("=") if a==b else print("B") # It is a shorthand, which we can use in case of some simplistic and one line conditions and shortcuts!

# Way 2 :
c = 10 if a>b else 0
c = 10 if b>a else print("0")
# there can be more varieties!

# ------------------------------------------------------------------- Lecture 42 - Enumerate in Python -------------------------------------------------------------------------------------------------------------->
# Enumerate : It is a built-in function in python, that allows you to loop over a sequence (such as list, tuple, string) and get index, value of each element at the same time!
fruits = ["Apple", "Banana", "Orange", "Grapes"]
for index, value in enumerate(fruits) : # iss function ne just simply index ke saath print krdiya saare list elements ko!
    print(index,value)

# but agar hum individual index and values na likhe and sirf ek variable likhe... in that case ek tuple return hojayega!
fruits1 = ["Apple", "Banana", "Orange", "Grapes"]
for v in enumerate(fruits1) :
    print(v)
# Aise krne se ek tuple return hojayega, upar jab hum kr rhe the toh hum individually index and value variables bnaa rhe the isliye jo tuple tha vo khul ke print hua, but yahaa kyunki ek hi variable use kr rhe hai toh sirf tuple banke print hua!

# by default indexing in the enumerate functions start from 0, but we can change it as well! we just need to add another parameter inside the enumerate function "start" like...
fruits2 = ["Apple", "Banana", "Orange", "Grapes"]
for index,value in enumerate(fruits2,start=1) :
    print(index,value)

# ------------------------------------------------------------------- Lecture 43 - Virtual Environment in Python -------------------------------------------------------------------------------------------------------------->
# understanding the use case : Maanlo hum ek py program likh rhe hai and maine ek package install kiya and jo mera dost hai usne bhi same package install kiya, but maine apna package update krdiya but vo mera friend uss program pr vhi purana version use kr rha hai uss package ka, then in that case we use virtual environment, taaki jo log uss environment me kaam kr rhe hai vo sab same versions and functions and packages pr kaam kr rhe hai!
# Formal defintion : A virtual environment in the context of software development, particularly in Python, is an isolated runtime environment that allows you to install and manage dependencies (libraries and packages) for a specific project without affecting the global system installation or other projects. This isolation ensures that each project can have its own dependencies, including different versions of the same libraries, without conflict. Virtual environments facilitate reproducibility, consistency, and isolation, making it easier to manage and deploy applications across different systems.
# One can think, ki agar different versions pr kaam hi krna hai toh alag alag PC and khud ke isolated devices pr hi krlo na, virtual environment ki kya zarurat? toh the thing is, harr PC ya device capable nhi hota sometimes heavy packages install krne ke! toh yhi cheez virtual environment solve krta hai! ki ek virtually ek jagah bnaa deta hai jispe koi bhi kitne bhi multiple projects pr kaam kr sakta hai and different project me different versions of same/different packages install bhi kr sakta hai bina kisi conflict ke! isse cost bhi bachti hai heavy hardwares and all ki! that is why it used!

# Before creating virtual environment, it will be a good thing we will have a good knowledge of command line interfaces like command prompt and powershell! and run as administrator option!
# Command Prompt : It is a command line interface, that allows you to execute commands in Windows. Mac/Linux has terminal in contrary.
#                : Usage : Useful for basic command-line tasks and managing files and directories.
#                : How to open : Search for "Command Prompt" or "cmd" in the Start menu.

# Powershell : An advanced command-line interface with more features than Command Prompt, including scripting capabilities.
#            : Usage : Useful for more complex tasks and scripting.
#            : How to Open : Search for "PowerShell" in the Start menu.

# VS Code Terminal : It is an integrated command line interface, which can behave as command prompt or powershell both!
#                  : Shell Selection : VS Code Terminal can be configured to use different shells, including Command Prompt, PowerShell, Bash, Zsh, or any other installed shell. This flexibility allows you to choose the environment that best fits your workflow.
#                  : Opening and Managing Multiple Terminals : You can open multiple terminal tabs within VS Code to run different commands or scripts simultaneously. This can be done using the + icon in the terminal panel.
#                  : Integration with Extensions : The VS Code terminal works seamlessly with extensions, such as those for Python or Git, enhancing its functionality and integration with your development workflow.
#                                                : Now, Powershell kisi bhi extension ke saath ache se perform krleta hai, but command prompt bhi krta hai but ye kuch advance features me lack krta hai powershell se!

# Which to use : The choice between PowerShell and Command Prompt largely depends on your needs and preferences!
#              : For Basic Tasks and Familiarity: If you’re doing basic file management or working with legacy systems and scripts, Command Prompt might be sufficient and more straightforward.
#              : For Advanced Scripting and Automation : If you need advanced scripting capabilities, automation, or integration with modern tools, PowerShell is the better choice. It’s particularly useful for tasks that involve system administration, data manipulation, and working with various APIs and services.

# Run as administrator : "Run as Administrator" is a feature in Windows that allows a program to be executed with elevated privileges
#                      : When you run a program as an administrator, it is granted higher-level permissions than a standard user account. This means it can perform tasks that require administrative rights, such as modifying system files, installing software, or changing system settings.
#                      : On Windows, User Account Control (UAC) will prompt you to confirm if you want to allow the program to make changes to your system. This is a security measure to prevent unauthorized changes.
#                      : It can be used with command prompt or powershell both!
#                      : Dekho thing is, cmd and powershell ke paas apne apne level ke hisaab se features hai! powershell me zyada complex features bhi hai where cmd me thore limited cheeze krne ke features! dono me se kisi ko bhi run as admin krne se dono ke user permissions bhi mil jaate hai!
#                      : Like for example : Command Prompt without run as admin, files management kr pa rha tha and packages install and uninstall kr paa rha hai and some basic features handle kr paa rha tha! but with run as admin, now it can also install and uninstall softwares too and similarly kuch aur features add hojaate hai jo iss run as admin ke saath aate hai cmd ke liye!
#                      : Similarly, powershell ke paas already bhot features hai complex tasks ko handle krne ke liye bhi, but run as admin krne se uske paas kuch aur zyada features and privilleges mil jaate hai! like agar without run as admin, powershell pehle sirf softwares ko install kr paa rha tha toh ab with run as admin vo kuch aur modifications bhi kr payega!

# Ab like harr cheez ki detail me ghusne ki need nhi hai, vrna its very lengthy to cater right now, main point being what are command line interfaces and how and why they are used!
# Ye sab yaad krne ki zarurat nhi hai, all this you will learn as your learn more and more in development! these are all just some basics for you to begin with command line interfaces!

# Now lets finally learn some commands used to create virtual environment!
# 1) Creating virtual Environment!
# "python -m venv [virtual_environment_name]" to write this commands you need to create a folder and then right click on the folder and open command prompt and then write this command! and isse ye hoga, jo naam specify kiya hai usko lekar ek virtual environment create hojayega is folder ke andar! pr abhi virtual environment poori tarah se nhi create hua hai, abhi sirf folder bnaa hai! ab isko activate krna hoga!

# 2) Activating Virtual Environment! (for command prompt)
# "[virtual_environment_name]\Scripts\activate.bat" or "[virtual_environment_name]\Scripts\activate" Ab isse virtual environment activate hojayega ab iske andar hum kuch bhi kre usse bahar ke system ko fark nhi padega! ab ye ek alag se hi pc ke andar ek alag pc ban gya hai aisa maanlo! jisme hum apni development kr sakte hai! we can install any version of any package inside this (kr toh external pc me sakte hai) like ek venv me koi aur package dusre me koi aur package!
# for that you just need write things like, vaise commands you can google anytime, bss tareeka and flow and logic ptaa hona chaiye cheez krne ka ki koi cheez kaise ho rhi hai and kyu ho rhi hai!, code toh internet se mil hi jaata hai! so like suppose just for example you want to install pandas version 1.5.2 on one venv and on another I want to install 1.4.4, then for that you have to write this in cmd : pip install pandas==1.5.2 on one venv and on another pip install pandas==1.4.4 

# 2.2) Activating Virtual Environment! (for powershell)
# ".\[virtual_environment_name]\Scripts\activate.ps1" or ".\[virtual_environment_name]\Scripts\activate" Ab baaki jab krenge tab dekhenge, for now itna knowldge kaafi hai!
# Now if your work is done and now, you want to deactivate your venv, then...

# 3) Deactivating Virtual Environment!
# "deactivate" just write this in cmd and venv is deactivated!
# Suppose if you are working on a project and now when you are done for today and want to continue work tomorrow, then you can deactivate your venv, its a good practice also! all your install packages will remain intact within the directory itself! and when you deactivate your venv, then you simply returns to the global environment.
# When you are working on the venv, then it uses all the python interpreter and libraries! and its a single environment task at one time! kyunki python interpretor toh ek hi hai! isliye! if you want to work globally then you can deactivate and then reactivate! only one environment can be present a single terminal session!
# If you want to open multiple environments, then you need to open multiple terminals! python interpretor ek hi hai pr vo ek hi terminal ke liye ek hi hai!
# Ab ofc si baat hai ek instance of time me toh ek hi jagah kaam kr rhe hoge na! toh jab jahaa kaam kroge toh uss time vahaa python interpretor kaam krega!

# 4) Now, maanlo humne apne venv me kaafi saare packages install krliye, and now hume vo saare packages and versions dekhne hai ya unko ek file bnaa ke store krna hai, so for that hum yaad krke likhenge thori, so for that we use a command, which is...
# "pip freeze" this command, lists all the packages and their version on the cmd/powershell, but we want to list them and store in file, then we write...
# "pip freeze > [filename.txt]" this command will list all the packages in this file! generally for packages, the filename more oftenly used is "pip freeze > requirements.txt", isse ek requirements.txt file create hoti hai jisme saare packages jo uss venv me hai unn sabke naam and version likhe hote hai, and ye file hum documentation ki tarah rakh sakte hai, ya kisi ko chahiye toh bhej sakte hai!
# And now agar aapke friend ko vo files chahiye toh bss usko ye file download krke sahi folder me rakhni hai and then he/she has to run this command, "pip install -r requirements.txt"

# ------------------------------------------------------------------- Lecture 44 - Import in Python -------------------------------------------------------------------------------------------------------------->
# Importing in python is the process of loading code from module into the current scipt, this allows you to use the functions and variables defined in the module in your current script! as well as the additional modules that the imported module may depend upon!
# To import a module in python, you use the import statement followed by the module name which you want to import! for example to import math module, which will contain some important mathematical functions we will write... "import math"
# Example 1 :
import math
result = math.sqrt(9)
print(result)

# Example 2 : if you want to import only a single function into the script from a module
from math import floor
result2 = floor(3.421)
print(result2)
# if you import the entire module, then you need to use the module_name. (with . operator), but if you import particular function from a module, then you do not need to use the . operator!
# you can import multiple functions and variable separated by commas, using "from ... import ..., ... and so on..."

# Example 3 :
from math import sqrt, pi
result3 = sqrt(9) * pi
print(result3)

# Example 4 : importing all the the functions using import using * wildcard
from math import * # Jab bhot necessary ho tab hi krna chahiye ye! vrn nhi! kyunki it will create more confusion when you will use multiple module and functions! agar do modules me kisi do function ke naam same hogye toh dikkat hojayegi, isliye it is not recommended!

# Example 5 : Use of "as" keyword, ye kisi bhi keyword ya function ko alias deta hai simply!
from math import sqrt as s # alias for sqrt func() is "s"
import math as m # alias for math module is "m"
from math import pi as p, sqrt as s # alias for pi variable is "p", sqrt func() is "s"

# Example 6 : Use of "dir" func(), if you want to see and print all the func() of a module then you write...
import math
print(dir(math))
# We can also print particular type of a func() or variable in the module... write...
print("\n")
print(math.sin, type(math.sin))

# Example 7 : you can create another file and create func() and variables there also, then the module name will become your file name, then you can import and use those methods or func() or variables you have created in that file!

# ------------------------------------------------------------------- Lecture 45 - if __name__ = "__main__" in Python -------------------------------------------------------------------------------------------------------------->
# Visit the Folder for Lecture 45 to understand this concept!

# ------------------------------------------------------------------- Lecture 46 - os module in Python -------------------------------------------------------------------------------------------------------------->
# The os module in Python provides a way of using operating system-dependent functionality like reading or writing to the file system. It is part of Python's standard utility modules and allows you to interact with the underlying operating system in a portable manner.

# Lets first understand some terminologies :
# 1) Directory : A directory (also called a folder) is a file system structure that contains references to other computer files, and possibly other directories. Directories help organize files in a hierarchical system.
#              : Root Directory : The top-level directory in a file system, from which all other directories branch.
#              : Subdirectory : A directory contained within another directory.

# 2) File : A file is a collection of data stored on a disk. It can contain text, images, videos, executables, or any other type of data

# 3) Repositories : A repository (often abbreviated as repo) is a storage location for software packages or code. It is commonly used in the context of version control systems (VCS) like Git. Repositories store the complete history of changes to files and directories, along with metadata such as commit messages.
#                 : Local Repository: A repository stored on your local machine.
#                 : Remote Repository: A repository stored on a remote server (e.g., GitHub, GitLab, Bitbucket).

# 4) Path : A path is a string that represents the location of a file or directory in the file system. Paths can be absolute or relative.
#         : Absolute path : Specifies the location of a file or directory from the root directory. Example: /home/user/documents/file.txt.
#         : Relative Path : Specifies the location of a file or directory relative to the current directory. Example: documents/file.txt.

# 5) Branch : In version control systems, a branch is a parallel version of a repository. It allows multiple development lines to exist simultaneously. Each branch can have its own history and changes.
#           : Main Branch : Often called main or master, this is the default branch where the source code is typically considered stable and deployable.
#           : Feature Branch : A branch created to work on a new feature or bug fix.

# 6) Commit : A commit is a record of changes made to a repository. It contains a snapshot of the project’s files at a certain point in time, along with metadata such as the author, timestamp, and commit message.

# 7) Clone : To clone a repository means to create a copy of a remote repository on your local machine. This operation copies the entire history of the repository.

# 8) Push: The action of sending your local commits to a remote repository.

# 9) Pull: The action of fetching changes from a remote repository and merging them into your local repository.

# 10) Merge : Merge is the process of combining changes from different branches. If changes do not conflict, they are automatically combined. If there are conflicts, they need to be resolved manually.

# Fork : A fork is a copy of a repository that allows you to freely experiment with changes without affecting the original project. Forks are commonly used in open source projects to contribute changes back to the main repository.

# Now, if you are confused between the terms Fork, Clone and Branches are similar things, then take this example and workflow :
# Step 1 : Building a Project and Branching : Create Different Branches for Different Features: As the project maintainer, you can create multiple branches to handle different features, bug fixes, or experiments. Each branch is a separate line of development that allows you to work independently from the main branch (often called main or master).
# Step 2 : Forking the Repository : Forking by Contributors: If someone else (a contributor) wants to work on your project, they can fork your repository to their own GitHub (or another Git hosting service) account. This forked repository is their personal copy of your repository.
#                                 : Forking Includes All Branches: When they fork the repository, it includes all the branches that exist in your original repository at the time of the fork.
# Step 3 : Cloning the Repository : Cloning by Contributors : After forking your repository, the contributor can clone their forked repository to their local machine. This cloning operation brings the entire repository (including all branches) to their local machine.
#                                 : Cloning Includes All Branches : When they clone the repository, they get all the branches that are present in the forked repository.
# Step 4 : Working and Performing Operations : Work on Specific Branches Locally : The contributor can then check out the specific branch they are interested in working on. For example, they might check out a feature branch to add new functionality or a bug-fix branch to address an issue.
#                                            : Make Changes and Commit : They can make changes in their local repository, commit those changes to the branch they are working on, and push those changes back to their forked repository on GitHub.
# Step 5 : Submitting Changes Back to the Original Project : Create Pull Requests : Once the contributor is satisfied with their changes, they can create a pull request from their branch in their forked repository to the corresponding branch in your original repository. This pull request is a proposal to merge their changes into your project.

# Now lets begin understand this os module!
# Suppose I want to create a folder and in that folder I want to create multiple files, so yaa toh baith ke harr file banao yaa fir simply ye commands run krdo!
import os
if(not os.path.exists("Data")) : # This command in os module checks, ki agar pehle se directory(folder) nhi hai toh bnaa do nhi toh rehne do!
        os.mkdir("Data") # Running this code will create a folder in your current folder!
# and now if you want to create some files, like Day1, Day2 and.... then write...
for i in range(1,6) :
    os.mkdir(f"Data/Day{i}") # This creates Day1-Day5 folders in the Data folder!

# Now suppose I want to rename all the folders!, so for that just write
import os
for i in range(1,6) :
     os.rename(f"Data/Day{i}",f"Data/Tutorial {i}") # It will rename all the directory(folders)!

# Now I can also print and see all the folders that are present in a directory!
import os
folders = os.listdir("Data") # it will return a list to folder variable and folder variable will become of list type.
print(folders) # Will print all the folders
print(type(folders)) # Will print the type of folder, <class 'list'>

for folder in folders :
    print(os.listdir(f"Data/{folder}")) # It will print all the content inside all the folders present in the Data folder! abhi kuch nhi hai kisi me toh isliye [] show kr rha hai... ek folder me randomly kuch likh ke ya koi file bnaa ke daal do Data folder ke andar, tab jo uske andar file hogi uska naam print hojayega vo jis folder ke andar hai! # Do it you will get it!

# You can also do thing with command line! using os.system() method
import os
text = "date"
os.system(text) # So it will show you the today's date!

# You can also check your current working directory (cwd)!
import os
print(os.getcwd()) # It will print the cwd
# There are similar more commands like this, .rmdir(), .remove() .chdir() and more....

# Now you can explore more of its commands and methods unpr work krne se yaad honge aise koi ratt nhi sakta hai! jo project pe work kr kr ke seekho commands ke baare me!
# Note : I will delete all the files for now, jab test krna ho toh firse create krlena! yahaa bhi and vo virtual environment create kiya tha vahaa bhi and aage bhi kabhi need ho tab bhi aise hi krunga!

# ------------------------------------------------------------------- Lecture 48 - Local and Global Variables in Python -------------------------------------------------------------------------------------------------------------->
# We know what are Local and Global variables! here we will learn the use of global keyword!
# Jaise we know humne agar ek global variable banaya toh usko hum poore program me kahin bhi use kr sakte hai, but agar ek local banaya toh usko ek scope tak hi use kr paate hai! but still it is recommended to avoid using global variables in your program as they are less maintainable and can cause un-necessary confusion!
# But here what we will do is, as we know ek baar global variable bnaa diya toh poore program me same rehta hai! usko kahin bhi use kro same value hoti hai! but maanlo hum ek scope me hai and ab hum yaa toh hum ek alag variable bnaa le uss scope ke liye! yaa toh uss globa variable ki value ko hi change krke use krle! but ye krenge kaise? kyunki agar simply "x = 10" (global variable) ko "x = 5" krdenge toh change thori hojayega global variable isse toh bss ek aur variable create hoga iss scope ke liye! global x ki value thori change hogi toh yahaa kaam aata hai "global" keyword ka!
x = 10
def my_function() :
    global x
    x = 5 # Value of global variable changed!
print(x) # Will print the original value of global value
my_function() # Updated the value
print(x) # Updated value of global variable
    
# ------------------------------------------------------------------- Lecture 49 - File Handling in Python -------------------------------------------------------------------------------------------------------------->
# Visit the File handling folder!