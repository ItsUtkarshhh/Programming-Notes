# ----------------------------------------------------- Lecture 91 - Generators in Python -------------------------------------------------------------------------------------------------------------->
# Generators in Python are a type of iterable, like lists or tuples or sets, but they are more memory-efficient. They allow you to iterate over a sequence of values without storing the entire sequence in memory at once. This makes them particularly useful when working with large data sets or streams of data.
# Also, Generators in Python are a way to create iterators in a simpler and more memory-efficient way. Instead of generating all the values at once and storing them in memory (like lists, sets or tuples), generators produce values one at a time as you iterate over them.

# How it works : Generators are defined like regular functions, but instead of using return to return a value and exit, they use yield. The yield statement pauses the function, saving its state so it can be resumed later. When the generator is resumed, it picks up right after the yield statement.
#              : When a generator function is called, it returns a generator object without starting execution immediately.
#              : Each time the generator’s __next__() method is called (or next() in Python 3), the function resumes execution from where it left off, until it hits a yield statement again or completes.

# Memory Efficient : Generators produce values one at a time and only when required. This means they do not need to store the entire sequence in memory, which can save a lot of space.
# Use of "yield" : The yield statement allows the function to return a value and pause its execution. When next() is called again, the function resumes from where it was paused.

# Lets understand through code...
# Suppose you want numbers from 0-5000000, in that case tum list toh banaoge nhi unn saare numbers ko store krne ke liye, generators ka sabse imp kaam hota hai jab big data ki baad ho, uss case me hum utne bade data ako list me store krke rakh nhi sakte, so hum kya krte hai ki ek generator bnaa lete hai jo ek ek krke iterate krta rahega harr ek value pr bina kis bhi value ko store kre!
# Aisa krke memory bhi bachegi and zyada efficient bhi hoga and speed bhi sahi hogi...
# Generator Fucntion Created!
def my_generator() :
    for i in range(500000):
        yield i # Here i is an integer, jo ek ek krke value return (more specifically yield krega) krega, jab bhi iss function ko call kiya jayega! Generators ka jo ye iteration pause krne vaala behavious hai vo "yield" keyword ke kaaran hai!
gen = my_generator() # And now yahaa pr "gen" ab ek generator object ban gya hai jo generator func() ke through return hua hai! that is again due to yield keyword, you don't need to get deep into that kaise generator object return hua and all! bss itna samajh lo ki yield ke kaaran pause vaala behaviour aata hai + ek generator object return krta hai! and i ek integer hai!
# This object is an iterator that you can use to iterate over the sequence of values produced by the generator. The generator object does not execute the code in the function immediately. Instead, it waits until you start iterating over it or explicitly call next() on it.
# It doesn't execute the generator function immediately. Instead, it creates a generator object that can be used to fetch values lazily, one at a time.

# You can use next() to print every next iteration...
print(next(gen)) # 0
print(next(gen)) # 1
print(next(gen)) # 2
print(next(gen)) # 3
# So here what happens is, next() function ko jab ek generator object ke saath use kiya jata hai, toh ye generator ko ek step aage le jata hai aur us waqt yield statement se jo value milti hai, usko return karta hai.
# How it iterates over gen object : Pehli baar next(gen) call hone par, my_generator() function start hota hai aur i = 0 hota hai.
#                                 : Generator yield i par aata hai, jo 0 hota hai, aur function pause ho jata hai. next(gen) is 0 ko return karta hai.
#                                 : Jab aap phir se next(gen) call karte ho, generator wahi se resume hota hai jahan se usne last yield kiya tha, aur ab i = 1 hota hai.
#                                 : Ye process har next() call par repeat hota hai, aur i ki next value yield hoti hai.

# next() function basically generator object se current value of i ko extract karta hai, jo integer hota hai, aur usko return karta hai.
# Yeh saari processing yield keyword ke kaaran hoti hai, jahan generator pause hota hai, value return karta hai, aur phir se resume hota hai agle next() call par.

for j in gen :
    print(j)
# for loop ko jab generator object (gen) milta hai, toh yeh internally iter() function call karta hai. Generator objects already iterable hote hain, toh iter(gen) wahi generator object (gen) return karta hai.
# Loop automatically next() function ka use karta hai generator se agle value ko retrieve karne ke liye. Jaise hi next() function call hota hai, generator apne current position se agla value yield karta hai.
# Jo value yield hoti hai, usko loop variable j mein assign kiya jata hai.
#  Loop ke body mein jo code hota hai, usko execute kiya jata hai. Is case mein, print(j) statement execute hoti hai, jo j ki value print karti hai. and then loop continues!

# So isko tab hi use krte hai inko jab large data pr kaam krna ho! and jab memory bachaani ho, kyunki itne bade data ko list me store krke rakhne se bhot memory jayegi, isliye its better to use generators in that case, also ye tab use krna jab elements store nhi krne ho!
# iska tab bhi kaam aata hai jab kuch large number of data pr complex calculations krni ho, agar list me krte toh ek toh space bhot lgta + memory bhot jaati agar large number of data ko store kiya hota list me! isliye we use generators! abhi yahaa toh bss hum print kr rhe hai.

# ----------------------------------------------------- Lecture 92 - Function Caching in Python -------------------------------------------------------------------------------------------------------------->
# Function caching in Python is a technique used to store the results of expensive function calls and reuse the cached results when the same inputs occur again. This helps in improving the performance of a program, especially when dealing with computationally intensive functions.
# There are two types of function caching : Manual and using functools module!
# Manual Function Caching : You can manually implement caching using dictionaries.
# Example :
cache = {}

def expensive_function(n):
    if n in cache:
        return cache[n]
    
    # Simulate an expensive computation
    result = n * n  # Just an example, imagine it's more complex
    cache[n] = result
    return result

# First call with 10, result is calculated
print(expensive_function(10))  # 100

# Second call with 10, result is fetched from the cache
print(expensive_function(10))  # 100 (cached result)

# Using functools module : Python provides a built-in way to cache function results using functools.lru_cache, which stands for "Least Recently Used" cache.
# Example :
from functools import lru_cache
import time  # using it to see kitna time lag raha hai!

@lru_cache(maxsize=128)
def expensive_function(n):
    # Simulate an expensive computation
    return n * n

# Measure time for the first call
t1 = time.time()
print(expensive_function(10000))  # 100
t2 = time.time()
print(f"Time taken at first: {t2-t1} seconds") # Here you can see, the operation took 0.0010554790496826172 seconds

# Measure time for the second call (should be faster due to caching)
t3 = time.time()
print(expensive_function(10000))  # 100 (cached result)
t4 = time.time()
print(f"Time taken after caching: {t4-t3} seconds") # But here the operation took 0.0 second, becoz this time value was already stored using the lru_cache() function!

# ----------------------------------------------------- Lecture 93 & 94 : Exercises -------------------------------------------------------------------------------------------------------------->
# Practice all of them later...

# ----------------------------------------------------- Lecture 95 : Regular Expressions in Python -------------------------------------------------------------------------------------------------------------->
# Regular expressions (regex) in Python are a powerful tool for searching, matching, and manipulating text. They are used to specify patterns in strings and perform operations like searching, splitting, and replacing based on those patterns.
# You can say ye kaam toh hum "in" keyword ke help se bhi kr sakte the, like koi logic lgaa lgaa ke hum kr toh lete hi, toh iski kay need? toh thing is ye regular expression iss cheez ko easy bnata hai, isliye we should be using this!

# Basics of Regular Expression : A regular expression is a sequence of characters that defines a search pattern. Here’s a breakdown of the fundamental components and syntax used in regex :
# Basic Patterns : Literal Characters : Match the exact characters in the string.
#                                     : Example : r'abc' matches the substring "abc".
#                : Special Characters : . (dot) : Matches any single character except newline. Example : r'a.c' matches "abc", "a-c", etc.
#                                     : \d : Matches any digit (equivalent to [0-9]). Example: r'\d' matches "1", "2", etc.
#                                     : \D : Matches any non-digit character. Example : r'\D' matches "a", "!", etc.
#                                     : \w : Matches any alphanumeric character (equivalent to [a-zA-Z0-9_]). Example : r'\w' matches "a", "1", "_", etc.
#                                     : \W : Matches any non-word character. Example : r'\W' matches "!", "@", etc.
#                                     : \s : Matches any whitespace character (spaces, tabs, newlines). Example : r'\s' matches " ", "\t", etc.
#                                     : \S : Matches any non-whitespace character. Example : r'\S' matches "a", "1", etc.
#                : Quantifiers : Quantifiers specify the number of times a pattern should occur
#                              : * : Matches 0 or more times. Example : r'a*' matches "a", "aa", "", etc.
#                              : + : Matches 1 or more times. Example : r'a+' matches "a", "aa", but not "".
#                              : ? : Matches 0 or 1 time. Example : r'a?' matches "a", "".
#                              : {n} : Matches exactly n times. Example : r'a{3}' matches "aaa".
#                              : {n,} : Matches n or more times. Example : r'a{2,} matches "aa", "aaa", etc.
#                              : {n,m} : Matches between n and m times. Example : r'a{2,4}' matches "aa", "aaa", "aaaa".
#                : Anchors : Anchors are used to specify the position in the string:
#                          : ^ : Matches the start of the string. Example: r'^abc' matches "abc" at the beginning of the string.
#                          : $ : Matches the end of the string. Example : r'abc$' matches "abc" at the end of the string.
#                : Character Classes : [abc] : Matches any one of the characters a, b, or c. Example : r'[abc]' matches "a", "b", "c".
#                                    : [^abc] : Matches any character except a, b, or c. Example : r'[^abc]' matches "d", "1", etc.
#                : Groups and Alternation : () : Groups patterns. Example : r'(abc)+' matches "abc", "abcabc", etc.
#                                         : | : Alternation (logical OR). Example : r'a|b' matches "a" or "b".

# So, now we can implement them... lets code them now,
# Now some commonly used function in regex are : .match() : Checks for a match only at the beginning of the string.
# Example :
import re
result = re.match(r'\d+', '123abc')
print(result.group())  # Output: 123
#                                              : .search() : Searches for a match anywhere in the string.
# Example :
import re
result = re.search(r'\d+', 'abc123xyz')
print(result.group())  # Output: 123
#                                              : .findall() : Finds all matches and returns them as a list.
# Example :
import re
result = re.search(r'\d+', 'abc123xyz')
print(result.group())  # Output: 123
#                                              : .finditer() : Finds all matches and returns them as an iterator of match objects.
# Example :
import re
for match in re.finditer(r'\d+', 'abc123def456'):
    print(match.group())  # Output: 123 456
#                                              : .sub() : Replaces matches with a specified string.
# Example :
import re
result = re.sub(r'\d+', 'number', 'abc123def456')
print(result)  # Output: abcnumberdefnumber
#                                              : .split() : Splits the string by the matches of the pattern.
import re
result = re.split(r'\d+', 'abc123def456')
print(result)  # Output: ['abc', 'def', '']

# Practical Example 1 :
import re
text = 'The event will be held on 2024-08-15 and 2024-09-01.'
dates = re.findall(r'\d{4}-\d{2}-\d{2}', text)
print(dates)  # Output: ['2024-08-15', '2024-09-01']

# Practical Example 2 :
import re
email = 'example@example.com'
pattern = r'^[\w\.-]+@[\w\.-]+\.\w+$'
if re.match(pattern, email):
    print("Valid email")
else:
    print("Invalid email")

# Practical Example 3 :
import re
text = 'This is a sample text with numbers 123 and 456.'
words = re.split(r'\s+', text)
print(words)  # Output: ['This', 'is', 'a', 'sample', 'text', 'with', 'numbers', '123', 'and', '456.']

# There will be more examples you can make, you can match more variety of regular expressions! dont learn it, practice them by using them in projects, you will learn them gradually!
# ratta nhi maarna hai kisi ko saare yaad  nhi hote! bss ptaa hona chahiye kya exist krta hai jo use kr sakte hai apne kaam ke liye and vo cheez kaise use hoti hai and kis jagah use hoti hai bss itna ptaa hona chahiye, and for that this lecture is enough, rest apply in projects and learn!

# ----------------------------------------------------- Lecture 96 : AsyncIO in Python -------------------------------------------------------------------------------------------------------------->
# It is neither multi-threading or neither it is multi-processing, it is a typical way of perform concurrent execution of tasks!
# "asyncio" module Python mein asynchronous programming ke liye use hota hai. Iska matlab hai ki aap ek time par kai tasks ko handle kar sakte hain bina ek dusre ko wait kiye. Yeh bahut useful hota hai jab aapko multiple operations ek saath karne hote hain, jaise ki web servers, real-time data processing, etc.
# Key Concepts : Event Loop : Yeh manage karta hai aur schedule karta hai asynchronous tasks ko.
#              : Coroutines : Special functions jo pause aur resume ho sakte hain
#              : Tasks : Coroutines jo scheduled hain run hone ke liye.
#              : Futures : Result jo future mein available hoga

# Important methods and classes :
# 1) asyncio.run() : Yeh top-level coroutine ko run karta hai aur event loop ko manage karta hai.
# 2) asyncio.create_task() : Yeh coroutine ko concurrently run karne ke liye schedule karta hai.
# 3) asyncio.sleep() : Yeh asynchronously execution ko pause karta hai specified duration ke liye.
# 4) asyncio.gather() : Multiple coroutines ko concurrently run karta hai aur unke results ko gather karta hai.
# 5) asyncio.ensure_future() : Yeh ensure karta hai ki coroutine ko Task object mein wrap kiya jaye.
# 6) asyncio.wait() : Yeh coroutines ya tasks ke complete hone ka wait karta hai.

# Basic Example :
import asyncio

async def say_hello():
    print("Hello")
    await asyncio.sleep(1) # 1 second ke liye wait karta hai
    print("World")

# Event loop ko run karna
asyncio.run(say_hello())
# Explaination : say_hello() ek coroutine hai jo "Hello" print karta hai, 1 second wait karta hai, aur phir "World" print karta hai.
#              : asyncio.run(say_hello()) coroutine ko run karta hai aur event loop ko manage karta hai.

# Example 2 :
import asyncio

async def task(name, delay):
    print(f"Task {name} started")
    await asyncio.sleep(delay)
    print(f"Task {name} finished")

async def main():
    # Tasks create karna
    task1 = asyncio.create_task(task('A', 2))
    task2 = asyncio.create_task(task('B', 1))
    task3 = asyncio.create_task(task('C', 3))
    
    # Sabhi tasks ke complete hone ka wait karna
    await task1
    await task2
    await task3

# Event loop ko run karna
asyncio.run(main())
# Explaination : asyncio.create_task() coroutines ko concurrently run karne ke liye schedule karta hai.
#              : main() multiple tasks create karta hai aur unke complete hone ka wait karta hai.

# Example 3 :
import asyncio

async def fetch_data(name):
    print(f"Fetching data for {name}")
    await asyncio.sleep(2)
    return f"Data for {name}"

async def main():
    results = await asyncio.gather(
        fetch_data('Alice'),
        fetch_data('Bob'),
        fetch_data('Charlie')
    )
    print(results)

# Event loop ko run karna
asyncio.run(main())
# Explaination : asyncio.gather() multiple coroutines ko concurrently run karta hai aur unke results ko gather karta hai.
#              : main() sabhi coroutines ke results ko collect karta hai aur print karta hai.

# Baaki study it when you are actually working on it, right now its enough to get starting with.. baaki you can explore and learn more when actual kaam pade iska! web dev me ye bhi kaafi use hota hai jaise FastAPI me!

# ----------------------------------------------------- Lecture 97 : Multi-Threading in Python -------------------------------------------------------------------------------------------------------------->
# Multithreading in Python is a technique that allows a program to run multiple threads (smaller units of a process) concurrently. This can improve the performance of programs that perform many tasks that can be done in parallel, such as handling I/O operations or managing multiple tasks simultaneously.
# Key Concepts : Thread : A thread is the smallest unit of execution in a process. Multiple threads within a process share the same memory space but execute independently.
#              : Threading : Threading allows for concurrent execution of code. Each thread can run its own code, and multiple threads can work together to complete tasks more efficiently.
#              : Global Interpretor Lock : Python has a Global Interpreter Lock (GIL) that prevents multiple native threads from executing Python bytecodes simultaneously. This means Python threads are not truly parallel in CPU-bound tasks. However, they can still be useful for I/O-bound tasks where threads spend time waiting for I/O operations to complete.

# In Python, we have a python’s standard library includes the threading module to work with threads.
# Lets see with example...
# Suppose we are going to call a function three times, toh agar ek toh bina threading ke kre toh pehle ek execute hoga, fir dusra fir teesra, toh aise toh ek ek krke execute hongi teeno function calls!
# But agar hum teeno function call ke liye alag alag thread bnaa de toh vo saari function calls apne apne hisaab se individually and saath me execute hojyenge!
# Lets see with example :
import threading
import time

# So this function basically is like, function me jo input ayega uske according ye utne utne time me execute hote rahega!
def func(seconds):
    print(f"Done after {seconds} seconds")
    time.sleep(seconds)

# Calling functions without threading :
time1 = time.perf_counter()
func(4)
func(2)
func(1)
time2 = time.perf_counter()
print(f"Time taken for functions to execute : {time2-time1}") # Output : 7.002942600054666 -> Total time is 4+2+1 = 7 and some time minor processing! kyunki saare ek ek krke execute hue!
# Output : Isse ye hoga ki saare function normally execute honge, ek ek krke kyunki python by default nhi krta threading and next function ko previous ke completly execute hone ke baad execute krta hai!
# hence the output will print the strings after the seconds interval passed in the parameter

# now lets use threading for the same thing :
import threading
import time

def func(seconds):
    print(f"Done after {seconds} seconds")
    time.sleep(seconds)

# Here we have created threads for all the function calls, taaki har function ko ek alag alag threads mil jaye!
# Mtlb ek tarah se aise samjho, ki iss threading ke krne se pehle, humare paas ek single line of execution tha, but jaise hi humne threading ki vo ek single line of execution se 3 different lines of execution bangye!...
thread1 = threading.Thread(target=func,args=[4])
thread2 = threading.Thread(target=func,args=[2])
thread3 = threading.Thread(target=func,args=[1])

# Starting all the threads...
# Yahaa ye hua hai ki humne uss threads me execution begin krdi! abhi sirf begin ki hai end nhi ki!
time1 = time.perf_counter()
thread1.start()
thread2.start()
thread3.start()
time2 = time.perf_counter()
print(f"Time taken for functions to execute : {time2-time1}") # Here, time is 0.001894199987873435, but dekha jaye toh ye homa nhi chahiye, kyuki agar teen processes saath me execute ho rhe hai toh total time should be equal to the highest time taken by the slowest process! (this we lso have studied in the chemistry!)
# So this is becoz, When you call thread.start(), you’re initiating the threads, but the threads are running concurrently. The time you measure immediately after starting the threads captures how long it took to initiate them, not how long they actually take to complete.

# Measuring time before joining and why it prints 0 : The overhead of starting threads and scheduling them is usually very small. This overhead includes the time it takes to create thread objects and initiate their execution. This doesn’t include the time the threads take to complete their tasks.
#                                                   : Concurrent Execution : When you start threads, they run concurrently with the main thread. The main thread measures the elapsed time while the threads are being started, but the threads haven’t finished their work yet. Hence, this time measurement doesn’t reflect the actual execution time of the threads.
#                                                   : The time difference measured (time2 - time1) is so small because it only includes the time taken to start the threads, which is typically less than a millisecond.
# Before .join(): The time measured is very small because it only includes the overhead of starting the threads, not their actual execution time.

# Ending threads...
# See ek toh hai ki agar hum chahte hai ki in threads ko vapis ek single line ko execution me le aana! and taaki hum threads ko end kr sake! and next baaki executions me ye threads interupt na kre isliye inko hume join krdena chahiye! for that "thread.join()" use krna hota hai!
time1 = time.perf_counter()
thread1.join()
thread2.join()
thread3.join()
time2 = time.perf_counter()
print(f"Time taken for functions to execute : {time2-time1}") # Will print 4 seconds!
# Isme sahi time lagega! kyunki yahaa pr humne threads join krdiye hai!
# After calling .join(), the time measured will be closer to the actual time taken by the longest-running thread because the main thread waits for all threads to complete. This is why you see the total time as being close to the time taken by the slowest thread.


# Normal execution line...
print("Threads ended!")

# Practical case : Agar kisine hume 5 files di download krne ke liye, toh hum 5 ki 5 lgaa denge download ke liye na ki ek ek krke! ab kuch log ko aisa lgta hai ki agar 5 ki 5 lgaa denge download ke liye toh jo sabse pehli file hai uspr hi kaafi bandwidth use ho jayegi! but aisa nhi hota... becoz...
# Do cheeze hoti hai ek server ki speed and ek internet ki speed, internet ki speed is jitni speed se hum le rhe hai! and server ki speed is ki jitni speed se vo de rha hai! agar server itni speed se de hi nhi rha hai toh humari speed zyada hone pr bhi koi fark nhi padega!
# Baaki these things we will study more in web dev!

# ----------------------------------------------------- Lecture 98 : Multi-Processing in Python -------------------------------------------------------------------------------------------------------------->
# Multiprocessing is a technique that allows a Python program to run multiple processes simultaneously. Unlike multithreading, which involves threads within a single process, multiprocessing involves multiple processes, each with its own memory space. This is particularly useful for CPU-bound tasks where you want to take full advantage of multiple CPU cores.
# Why use it : Multiprocessing allows you to perform parallel processing, which means running multiple tasks at the same time. This is useful for tasks that are computationally intensive and can be divided into smaller, independent tasks.
#            : Python’s Global Interpreter Lock (GIL) can limit the effectiveness of multithreading in CPU-bound tasks. Multiprocessing avoids the GIL because each process has its own Python interpreter and memory space.
#            : For CPU-bound operations, using multiprocessing can lead to significant performance improvements by utilizing multiple CPU cores.

# Process : A process is an instance of a program in execution. Each process has its own memory space and runs independently.
# Process Pool : A process pool is a collection of worker processes that can be used to execute tasks concurrently.
# Inter-Communication Processes : Mechanisms such as queues or pipes are used for communication between processes.

# Basic example of Multiple Processing :
import multiprocessing
import time

def worker(num):
    """Function to be run in a separate process."""
    print(f"Worker {num} started")
    time.sleep(2)
    print(f"Worker {num} finished")

if __name__ == '__main__':
    # Creating a list of processes
    processes = []
    
    # Creating and starting multiple processes
    for i in range(3):
        process = multiprocessing.Process(target=worker, args=(i,))
        process.start()
        processes.append(process)
    
    # Waiting for all processes to complete
    for process in processes:
        process.join()

    print("All workers have finished.")

# Explaination :
# Defining Worker Function : worker(num) : This function simulates a task that takes time to complete (2 seconds in this case).
# Creating multiple process : multiprocessing.Process(target=worker, args=(i,)) : Creates a new process that will run the worker function with the argument i. using for loop! and "args" is a tuple with a single value!
#                                                                               : In case of multi-threading, "args" was a list but here it is a tuple, in "threading.Thread" "args" parameter Can be a list or tuple. The module converts the list to a tuple internally if necessary.
#                                                                               : but in, "multiprocessing.Process" "args" parameter must be a tuple. This design choice ensures that arguments are immutable and can be safely passed to separate processes.
# Starting Process : process.start() : Starts the execution of the process.
# Joining Process : process.join() : Waits for the process to complete before proceeding.
# Main Program : The main program waits for all worker processes to finish before printing "All workers have finished."

# I will prefer to learn rest of the things during working with it, right now its not needed! these things are more required for projects and other works, as of learning these basics are enough! further learn when you will be actually working on them!

# ----------------------------------------------------- Lecture 99 & 100 : Exercise -------------------------------------------------------------------------------------------------------------->
# ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------>