# ----------------------------------------------------------- Lecture 49 : File Handling in Python ------------------------------------------------------------------------------------------------------------------->
# Firstly to understand this, you should be opening VS Code in this File Handling Folder, to run the commands!
f = open('File101.txt','r') # Opens the file!, here 'r' mode is default, likho na likho r mode hi khulega file! haa baaki ke liye specify krna padega!
print(f) # It will print the file content! but that will not be our actual content! to actually print the content, use the read() func!

text = f.read()
print(text)

f.close() # you can close the file after use!

# Write mode : It opens the file and you can write in it and if the file is not there then it will be created!
f = open('File102.txt','w') # It created anoother file File102.txt

# Create mode : It creates a file and if the file already exist, it will throw error!
f2 = open('File103.txt','x') # It will create the file
f2 = open('File102.txt','x') # It will throw error!

# Different modes : 'r', 'w', 'b', 'x', 't', 'a', 'r+' (allows you to do reading and writing both!)
# Writing in a file : You open a file, you write something, and then your string or text will get printed in the file!
f3 = open('File102.txt','w')
f3.write("Hello, its a new file I have created!")
f3.close() # After writing, you should close your file!

# Use of "with" keyword :
with open('File103.txt','w') as f : # Isse, file open krke usme likh sakte hai and then vo apne aap close ho jaati hai!
    f.write("Hello, yet another writing in the file!")

# ----------------------------------------------------------- Lecture 50 : read() and readline() in Python ------------------------------------------------------------------------------------------------------------------->
# readlines() : this is a method in file handling which read different lines from a file!, jaise agar kisi file me lines ke form me data likha hai toh ye function usko lines ke form me hi read krke dedega! readline() se sirf ek line read hogi and readlines() se saari lines as per your need!
# Lets use File103.txt for this...
f4 = open('File103.txt')
first_line = f4.readline() # The readline() method reads a single line from the file. It returns the line as a string, including the newline character (\n) at the end, if present. If the end of the file is reached, readline() returns an empty string ('').
print(first_line)
f4.close()

f5 = open('File103.txt')
lines = f5.readlines() # Agar aise hi likh denge toh saari lines ek list ke form me return hojayengi! and then usko hum print kr sakte hai uss string ko! ab kyunki ye ek list hai toh iss list ko hum iterate krke bhi print kr sakte hai!
print(lines)

for line in lines :
    print(line) # It printed all the lines!
f5.close()

# Example 2 :
# Lets first create a file "File104.txt" for this
f6 = open('File104.txt', 'r')
i = 0
while True :
    i = i + 1
    line = f6.readline() # The readline() method reads a single line from the file. It returns the line as a string, including the newline character (\n) at the end, if present.
    if not line: # This condition checks if line is an empty string. If it is, it means the end of the file has been reached, and the break statement terminates the loop. if readline() return an empty string it is considered false! and it is written "not line" now this condition will get true and the loop will break!
        break
    m1 = int(line.split(",")[0])
    m2 = int(line.split(",")[1])
    m3 = int(line.split(",")[2])
    print(f"Marks of student {i} in Maths is: {m1*2}")
    print(f"Marks of student {i} in English is: {m2*2}")
    print(f"Marks of student {i} in SST is: {m3*2}")

    print(line)

# writelines() : It write lines in the file
f7 = open('File105.txt', 'w')
lines = ['line 1\n', 'line 2\n', 'line 3\n'] # Writelines() func do not include newline character between string, you have to do it on your own!
f7.writelines(lines) # Here there is not func like writeline() there is only writelines() make sense, kyunki write line se ek line write kr sakte ho ya usse zyada!
f7.close()

# ----------------------------------------------------------- Lecture 51 : seek() and tell() functions in Python ------------------------------------------------------------------------------------------------------------------->
# In Python, the seek() and tell() methods are used to work with file objects, allowing you to manipulate and understand the position within a file when reading or writing. These methods are especially useful when dealing with large files, binary files, or when you need to read or write data at specific positions in the file.

# seek() method :
# The seek() method is used to change the file object's position, also known as the file pointer, to a specific location. The syntax is:
# file_object(offset,whence) : offset : The number of bytes to move the file pointer. This can be positive or negative, depending on the direction of the movement.
# Overall seek() will make the file pointer move to the specified location according to the value jo humne pass ki hai! and vo jo bhi value hogi vo file pointer me store hojayegi and then hum vahaa se read kr sakte hai!
f8 = open("File106.txt",'r')
f8.seek(5) # Here if we put 5, it will return a pointer and that pointer will be pointing at the 5 location from the starting of the string!
print(f8.read(5)) # Iska mtlb hai ki jo file pointer ne pointer return kiya hai uske "baad se" 5 positions read kro and print krdo! default me hum read me koi paramter daalte nhi hai, kyunki by default file pointer starting me hi rehta hai! but if we put value in this, it means ki hum kitni next characters read krna chahte hai! like here input is 5, means we want to read 5 characters (by default from starting!) but when you use seek(5) then the file pointer moves to the 5th position and then jab ab read(5) kroge toh uss file pointer se read hona shuru hoga!
# read(5) just reads the next 5 values according to the location of file pointer! jahaa pr file pointer ki location hai uske aage se characters read krta hai read() and keeps increasing file pointer after it reads the character! and seek() file pointer ko hi move krdeta hai according to the values passed as paramters!

# tell() method : The tell() method returns the current position of the file pointer within the file. That is ki abhi file pointer kahaa hai! The syntax is: 
print(f8.tell()) # It will print 10, kyunki seek() pehle toh 5 position aage laya and then read ne characters read krke 5 aur aage le aaya! and hence it prints 10!

# truncate(size) or truncate() : it resizes the file! according to the size passed and if no size is passed, then it will resize the file to the current position of file pointer!
# Lets understand this with example :
with open("File107.txt",'r+') as f9 :
    f9.write("Hello World!")
    f9.truncate() # isne kya kiya ki, pehle toh file khuli, then usme ek string write ki maine, and then truncate(5) krne se iss function ne starting ke 5 characters ko chhor ke uske aage se saare characters remove/erase hogye! and agar bina kisi prameter ke pass use krte truncate, toh jitna humne write kiya hai, vahaa tak pointer jaata and then uske aage jo bhi hai vo erase hojaata chahe vo dusri line hi kyu na ho!!
    f9.close()
# means, its like agar truncate me value pass kroge toh starting se utne characters count honge and then uske aage ke erase hojayenge! but agar bina kisi file pointer ke use kroge truncate ko, then file pointer apne end tak jayega read and write operations ke according and then uske aage ke saare erase hojayenge!

# ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------->