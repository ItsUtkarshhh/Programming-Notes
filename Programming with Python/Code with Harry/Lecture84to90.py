# ------------------------------------------------------------------- Lecture 84 - Time Module in Python -------------------------------------------------------------------------------------------------------------->
# The time module helps you work with time in Python. It allows you to get the current time, measure time intervals, and work with time in various formats.
# Functions :
# time.time() : Returns the current time in seconds since the Epoch (January 1, 1970, 00:00:00 UTC).
import time
current_time = time.time() # It will return that how many seconds have been passed since the epoch!
print(current_time)

# time.sleep(seconds) : Pauses the program for the specified number of seconds.
import time
print("Hey")
time.sleep(3)
print("This is printed after 3 seconds")

# time.strftime( ,t) : Formats a time tuple or struct_time (like the one returned by time.localtime()) into a string according to a specified format.
import time
current_time = time.localtime()
formatted_time = time.strftime("%Y-%m-%d %H:%M:%S", current_time)
print(formatted_time)

# time.perf_counter() : Returns the value (in fractional seconds) of a performance counter, which is a clock with the highest available resolution to measure a short duration.
import time
start = time.perf_counter()
for i in range(10000) :
    print(i)
end = time.perf_counter()
print(f"Operation took {end - start} seconds")

# Interesting use of time.time() func : You can use it for to check ki for loop zyada fast ha ya while loop!
# For loop :
import time

def forLoop():
    for i in range(4000):
        print(i)

def whileLoop():
    i = 0
    while i < 4000:
        print(i)
        i += 1

# Measure time taken by forLoop
t1 = time.time()
forLoop()
t2 = time.time()

# Measure time taken by whileLoop
t3 = time.time()
whileLoop()
t4 = time.time()
print("Time taken by whileLoop:", t4 - t3)
print("Time taken by forLoop:", t2 - t1)
# They are almost same.. for loop is little bit fast, but still both are very fast!!
# also here time.perf_counter() can also be used!

# Struct_time : struct_time is a named tuple type in the time module that represents time in a more readable and structured form. It has nine attributes : tm_year, tm_mon, tm_mday, tm_hour, tm_min, tm_sec, tm_wday, tm_yday, tm_isdst
# Example :
import time

# Get the current local time as a struct_time
current_time = time.localtime()

print("struct_time:", current_time)
# struct_time: time.struct_time(tm_year=2024, tm_mon=8, tm_mday=7, tm_hour=12, tm_min=34, tm_sec=56, tm_wday=2, tm_yday=220, tm_isdst=1)

# Accessing attributes of struct_time
print("Year:", current_time.tm_year)
print("Month:", current_time.tm_mon)
print("Day:", current_time.tm_mday)

# Converting struct_time to a formatted string
formatted_time = time.strftime("%Y-%m-%d %H:%M:%S", current_time)
print("Formatted time:", formatted_time)
# Formatted time: 2024-08-07 12:34:56

# Convert struct_time to a time tuple
time_tuple = tuple(current_time)
print("Time tuple:", time_tuple)
# Time tuple: (2024, 8, 7, 12, 34, 56, 2, 220, 1)

# ------------------------------------------------------------------- Lecture 85 - Creating Command Line Utility in Python -------------------------------------------------------------------------------------------------------------->
# Open the Lecture 85 Folder!

# ------------------------------------------------------------------- Lecture 85 - Walrus Operator in Python -------------------------------------------------------------------------------------------------------------->
# The walrus operator (:=), introduced in Python 3.8, allows you to assign a value to a variable as part of an expression. It's called the walrus operator because the := symbol looks like the eyes and tusks of a walrus.
# Why use walrus : Before the walrus operator, you had to separate the assignment of a variable and the use of that variable into two steps. The walrus operator allows you to do this in a single step, making your code more concise.
# Basic Example :
a = True
print(a = False) # It will show error! kyunki python me hum ye nhi kr paate the ki value ko saath hi saath expression me daalke uski value print krdo!
# This was made possible through walrus operator!
print(a:=False) # This made the code more readable!

# Example 2 :
# Without Walrus :
foods = list()
while True:
    food = input("What you like to eat? : ")
    if food == "quit" :
        break
    foods.append(food)

# With Walrus Operator :
foods = list()
while (food := input("What is like to eat? : ")) != "quit":
    foods.append(food)
# So overall walrus operator is used to make your code small and more readable!

# ------------------------------------------------------------------- Lecture 86 - Exercise -------------------------------------------------------------------------------------------------------------->
# Complete this exercise later on!

# ------------------------------------------------------------------- Lecture 87 - Shutil Module in Python -------------------------------------------------------------------------------------------------------------->
# The shutil module in Python provides a set of high-level operations for file and directory manipulation. It is part of the standard library and offers functions for copying, moving, and deleting files and directories, as well as some utilities for handling file system operations.
# Key Functions in "shutil" :
# 1) File and Directory Operations : "shutil.copy(src, dst)" : Copies a file from src to dst.
import shutil
shutil.copy('source.txt', 'destination.txt')
#                                  : "shutil.copy2(src, dst)" : Similar to copy(), but also preserves metadata (such as timestamps). timestamps means like kab vo file create hui and all!
shutil.copy2('source.txt', 'destination.txt')
#                                  : "shutil.copyfile(src, dst)" : Copies the contents of src to dst. dst must be a file name. but does not preserve meta data!
shutil.copyfile('source.txt', 'destination.txt')
#                                  : "shutil.move(src,dst)" : Moves a file or directory from src to dst. If dst is a directory, the file or directory is moved into it.
shutil.move('source.txt', 'new_location/source.txt')
#                                  : "shutil.rmtree(path)" : Recursively deletes a directory tree.
shutil.rmtree('unwanted_directory')
# 2) Directory Operations : "shutil.make_archive(base_name, format, root_dir=None, base_dir=None)" : Creates an archive (e.g., zip or tar) from a directory. base_name is Name of the archive file (without extension). root_dir is Directory to archive (default is the current directory). base_dir is Directory inside the archive (default is the root directory).
shutil.make_archive('archive_name', 'zip', 'directory_to_archive')
#                         : "shutil.unpack_archive(filename, extract_dir=None, format=None)" : Extracts an archive into a directory. filename is Name of the archive file. extract_dir is Directory to extract into (default is the current directory). format is Format of the archive ('zip', 'tar', etc.).
shutil.unpack_archive('archive_name.zip', 'extracted_dir')
# 3) File System Utilities : "shutil.disk_usage(path)" : Returns disk usage statistics about the given path. which consists a named tuple with total, used, and free attributes.usage = shutil.disk_usage('/')
usage = shutil.disk_usage('path')
print(f"Total: {usage.total}, Used: {usage.used}, Free: {usage.free}")

# ------------------------------------------------------------------- Lecture 88 - Exercise -------------------------------------------------------------------------------------------------------------->
# Practice later on...

# ------------------------------------------------------------------- Lecture 89 - Request Module in Python -------------------------------------------------------------------------------------------------------------->
# The requests module in Python is a popular library used to make HTTP requests, which allows your Python programs to interact with web services and APIs. It's widely used because it simplifies many tasks that would otherwise require a lot more code.
# HTTP Request : An HTTP request is how your web browser or a program communicates with a web server to get information or send data. It's a fundamental part of how the internet works
#              : HTTP stands for Hypertext Transfer Protocol. It's a set of rules that define how data is exchanged between devices on the web (like between your browser and a website's server).

# How HTTP works : When you visit a website, your browser sends an HTTP request to the server where the website is hosted. The server then processes the request and sends back an HTTP response, which contains the data your browser needs to display the website.
# Components of HTTP Requests : Method : This tells the server what action to perform. The most common methods are :
#                                      : GET : Asks the server to send back data (like a web page).
#                                      : POST : Sends data to the server (like filling out a form).
#                                      : PUT : Updates existing data on the server.
#                                      : DELETE : Removes data from the server.
#                             : URL (Uniform Resource Locator) : This is the web address you're trying to access (like https://example.com).
#                             : Headers : These are additional pieces of information sent with the request, like who is making the request (user-agent), what type of data can be accepted (content-type), and more.
#                             : Body : This is where the data is sent in the request (mainly used in POST or PUT requests). For example, when you submit a form, the data you entered goes into the body.

# Example of HTTP GET Request : When you type a web address into your browser and hit enter, your browser sends a GET request. Here's a simplified example :
# GET /index.html HTTP/1.1 -> Requests the homepage (index.html).
# Host : www.example.com -> Specifies the website.
# User-Agent : Mozilla/5.0 ->  Identifies the browser.
# Accept : text/html ->  Indicates that the browser expects HTML content in return.

# HTTP Response :
# After the server receives the HTTP request, it processes it and sends back an HTTP response. The response includes :
# Status Code : A number that tells whether the request was successful (e.g., 200 means success, 404 means not found).
# Headers : Additional information like content type (e.g., text/html).
# Body : The actual content you requested (like the HTML of the web page).

# Why HTTP Requests are Important :
# HTTP requests are the foundation of web communication. Every time you browse a website, fill out a form, or interact with an online service, your actions are translated into HTTP requests and responses behind the scenes. Understanding how they work helps in web development, debugging, and using web APIs.

# Now, this we will study further in web dev! but now lets continue with request module! installed request module coz it was not a built-in module!
# Lets see the basic working of request module... and try to fetch info from a website...
# 1) get() request : Retrieve data from a server.
import requests
text1 = requests.get("https://www.google.com/")
print(text1) # it will just simple print a response object which will be returned by get().. you need to use .text to convert it to textual format!
print(text1.text) # What you're seeing is the raw HTML content of the Google homepage. When you made the HTTP request using requests.get("https://www.google.com/") and printed text1.text, it returned the HTML code that structures and styles the Google homepage. This is what a web browser would receive and then render visually as the page you see when you visit Google.
# This is the foundation of how websites work. When you request a webpage, the server sends back HTML (and possibly other resources like CSS and JavaScript), which the browser interprets to display the page. Understanding this is crucial in web development, as you’ll be working with HTML, CSS, and JavaScript to create and manipulate webpages.

# 2) post() request : Send data to a server, typically to submit a form or upload a file.
data = {'username': 'user', 'password': 'pass'}
response = requests.post('https://api.example.com/login', data=data)
# The above code is just for example, but haa aise hi post request krte hai

# And similarly jab kaam ho toh aur baaki methods bhi use krna seekhna! it is used very well in web scrapping...
# Lets try web scraping... for it we use request along with "bs4" module!
# Web Scraping : Web scraping is a technique used to extract data from websites. You can automate the process of accessing websites, downloading their content, and then extracting specific data from the HTML. In Python, the requests and BeautifulSoup (bs4) modules are commonly used together to perform web scraping.
# Here’s how they work together in a basic web scraping process :
# Steps for Basic Web Scraping :
# 1) Make an HTTP Request : First, you need to access the webpage you want to scrape. You use the requests module to send a GET request to the webpage's URL.
#                         : The server responds with the HTML content of the page.
# 2) Parse the HTML : Once you have the HTML content, you need to parse it so you can extract specific data. This is where the BeautifulSoup module comes in.
#                   : BeautifulSoup parses the HTML and creates a parse tree, which allows you to navigate through the HTML and extract the data you need.
# 3) Extract Data : After parsing the HTML, you can use BeautifulSoup's methods to find the specific HTML elements (like <div>, <p>, <a>, etc.) that contain the data you’re interested in.
#                 : You can extract text, attributes (like href in <a> tags), and more.
# 4) Save or Process the Data : Once you’ve extracted the data, you can save it to a file, process it further, or use it in your application.

# Basic Example :
import requests
from bs4 import BeautifulSoup

# Step 1: Send a GET request to the website
url = "https://example.com"
response = requests.get(url)

# Step 2: Parse the HTML content
soup = BeautifulSoup(response.text, 'html.parser')

# Step 3: Extract data
# Let's say we want to extract all the <h1> tags
h1_tags = soup.find_all('h1')

# Print the text inside each <h1> tag
for tag in h1_tags:
    print(tag.text)

# Step 4: Save or process the data as needed
# Further you will understand thorugh projects and all... so work on projects and start learning more...

# ------------------------------------------------------------------- Lecture 90 - Exercise -------------------------------------------------------------------------------------------------------------->
# Practice it later on...