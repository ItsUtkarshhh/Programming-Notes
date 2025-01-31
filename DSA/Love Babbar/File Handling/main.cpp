// File Handling in C/C++ (File Input/Output)
// A file is a storage container used to store data on a storage device.
// In C/C++, files can be classified into two main types : Text files : These include .txt, .cpp, .c, .java files. These files store data in a human-readable format.
//                                                       : Binary files : These include .jpg, .jpeg, .mp3, and similar files, which store data in a format not directly readable by humans.

// Common Operations on Files : Open : To access a file for reading or writing.
//                            : Create : To generate a new file.
//                            : Read : To read data from a file.
//                            : Write : To write data to a file.
//                            : Close : To close the file after operations are completed.
// Note : C/C++ allows us to work with both text and binary files, but we will primarily focus on handling text files in this context.

// ---------------------------------------------------------------------------------------------------------------------------------->
// Starting with...
// File Pointers : A file pointer is used to access and manage files. Internally, files are represented by a hidden structure that tracks information such as the file's current position, access mode (read, write, etc.), and other details. While the exact structure is managed by the C standard library, programmers don't need to understand it in detail.
//               : To interact with a file, we use a FILE pointer, which points to this internal file structure. The FILE type is provided by the C standard library to handle file-related operations.
//               : To start, we declare a file pointer like this : FILE* fptr;

// Opening a File : Use fptr = fptr = fopen("filename", "mode");
//                : File opening modes : 'r' is open to read
//                                     : 'w' is open to write
//                                     : 'rb' is open to read in binary
//                                     : 'wb' is open to write in binary
//                                     : 'a' is open to append

// Closing a File : Use fclose(fptr);

// Lets code the above : Using the text1.txt
#include<iostream>
using namespace std;

int main() {
    FILE* fptr; // Created the file pointer!
    fptr = fopen("text1.txt","r"); // Opened the file!
    fclose(fptr);
}

// This is a better way opening and closing a file
#include<iostream>
using namespace std;

int main() {
    FILE* fptr; // Created the file pointer!
    fptr = fopen("text1.txt","r"); // Opened the file!
    if(fptr == NULL) { // agar file exist nhi krti hogi toh fptr me fopen krne pr NULL pointer return hojayega, toh bss hum yahaa vhi check kr rhe hai ki fptr me NULL hai ya nhi!
        cout<<"Files does not exist"<<endl;
    }
    else {
        fclose(fptr);
    }
    fclose(fptr);
} // And agar yaahaan humne 'w' me file ko open kiya hota! then in that case agar file exist nhi krti toh new file create hojaati uss naam se!

// ---------------------------------------------------------------------------------------------------------------------------------->
// Reading from a File in C!
// First create a variable to store all the readings from the file!
// Syntax : fscanf(fptr, "format_specifier", &variable);

// Lets code the above : Using text2.txt
#include<iostream>
using namespace std;

int main() {
    FILE* fptr;
    fptr = fopen("text2.txt", "r"); // Opening the file in read mode ("r")
    
    if (fptr == NULL) { // Check if the file is successfully opened
        cout << "File cannot be opened!" << endl;
    }
    else {
        char ch;
        
        fscanf(fptr, "%c", &ch); // Reading and printing one character at a time using fscanf
        printf("Character from the text2.txt file: %c\n", ch);
        
        fscanf(fptr, "%c", &ch); // Repeat the process if you want to print more characters manually
        printf("Character from the text2.txt file: %c\n", ch);
        
        fscanf(fptr, "%c", &ch);
        printf("Character from the text2.txt file: %c\n", ch);
        
        // Optimized approach : Read characters in a loop until the end of the file (EOF)
        // fscanf returns the number of items successfully read, so we check it instead of EOF directly
        
        while (fscanf(fptr, "%c", &ch) != EOF) { // Keep reading until EOF is reached
            printf("Character from the text2.txt file: %c\n", ch); // Print the character read
        }
        
        fclose(fptr); // Close the file when done
    }
    return 0;
}
// Note : Here you cannot use fgetc(), because fgetc() is designed to read a single character from a file, but it doesn't take a format string like "%c" (which is used for fscanf()).
//      : The file pointer is implicitly managed by the fgetc() function and other file operations (like fscanf(), fputc(), etc.). You don't need to manually move the pointer after each read — it happens automatically as part of the read operation.

// EOF : EOF stands for End of File. It is a special marker used to indicate that there is no more data to read from a file. When reading from a file, the program needs a way to know when it has reached the end of the file, and EOF is used to signify that point.
//     : How it is determined : Return value from reading functions : When you use functions like fscanf(), fgetc(), or fread() to read from a file, they return a special value to indicate that the end of the file has been reached.
//                                                                  : For functions like fscanf() or fgetc(), they return EOF when they can no longer read data from the file (i.e., when the file pointer reaches the end).
//                            : EOF constant : In C/C++, EOF is a constant defined in the stdio.h library (or <cstdio> in C++).
//                                           : It is typically represented by the value -1. It is not a character but an integer that indicates that the end of the file has been reached.
//                            : EOF in fscanf() : When you use fscanf() to read from a file, if it successfully reads a value, it returns the number of items read. If the function encounters the end of the file or any error, it returns EOF.
//                            : EOF in fgetc() : When using fgetc(), it returns a character as an unsigned char cast to int. If the end of the file is reached, it returns EOF.

// ---------------------------------------------------------------------------------------------------------------------------------->
// Writing to a File!
// Opening a file in 'w' mode : Use the fopen() function with "w" mode to open a file for writing. If the file doesn't exist, it will be created. If the file already exists, its content will be overwritten.
//                            : FILE* fptr = fopen("file.txt", "w"); The "w" mode indicates that the file will be opened for writing and the content will be replaced with new data.
//                            : Writing Data : To write data to the file, we use the fprintf() function. It works similarly to printf() but writes the data to a file instead of the console. Example : char ch = 'A'; // Can initialize character or take input fprintf(fptr, "%c", ch);  // Writes character 'A' to the file
//                                           : You can also take input using cin or scanf() and write it to the file in the same manner : char ch; scanf("%c", &ch);  // Take input from user fprintf(fptr, "%c", ch); // Write to file
//                            : File Overwriting : When opening a file in "w" mode, the previous content of the file is erased and replaced by the new content. If the file already has data, it will be overwritten completely.
//                            : File Creation : If the file specified does not exist, the "w" mode will create a new file and write to it.
//                            : File Closing : After writing to the file, always close the file using fclose() to release resources. Example : fclose(fptr);

// Lets try this : Using the text3.txt!
#include<iostream>
using namespace std;

int main() {
    FILE* fptr;
    fptr = fopen("text3.txt","w");
    if(fptr == NULL) {
        cout<<"Error in opening the file";
    }
    else {
        char ch = 'M';
        fprintf(fptr,"%c",ch);
        fprintf(fptr,"%c",'A');
        fprintf(fptr,"%c",'N');
        fprintf(fptr,"%c",'G');
        fprintf(fptr,"%c",'O');
        fclose(fptr);
    }
} // Ab isme hum input leke bhi kr sakte hai ya statically and manually bhi kr sakte hai! abhi humne yahaa manually kiya hai! isme humne jo kiya hai vo ye hai ki humne ek file simply write kiya hai! agar file text3.txt me pehle se kuch likha hota toh ye write krne pr jo pehle likha hua tha vo re-write hojaata!

// Writing to a File using "Append" Mode (a)!
// Opening File in Append Mode (a) : Use fopen() with "a" mode to open a file for appending data. If the file exists, new data will be written at the end without modifying existing content. If the file doesn’t exist, it will be created, and the data will be written to it.
//                                 : Appending Data : Similar to writing, we use fprintf() to append data to the file. The file pointer moves to the end of the file before writing the new content.
//                                 : Key Points : The content is added to the end of the file, preserving existing data. The file is created if it does not exist.

// Lets code this : using text4.txt
#include<iostream>
using namespace std;

int main() {
    FILE* fptr;
    fptr = fopen("text4.txt","a");
    if(fptr == NULL) {
        cout<<"Error in opening the file";
    }
    else {
        // Mango is pre written currently
        fprintf(fptr,"%c",'W');
        fprintf(fptr,"%c",'A');
        fprintf(fptr,"%c",'T');
        fprintf(fptr,"%c",'E');
        fprintf(fptr,"%c",'R');
        fprintf(fptr,"%c",'M');
        fprintf(fptr,"%c",'E');
        fprintf(fptr,"%c",'L');
        fprintf(fptr,"%c",'O');
        fprintf(fptr,"%c",'N');
    }
}

// ---------------------------------------------------------------------------------------------------------------------------------->
// fgetc() and fputc() Functions!
// fgetc() : Reads one character at a time from a file. It returns the character as an int (which is used to handle EOF properly). Suitable for reading files character by character.
// fputc() : Writes one character at a time to a file. It is used when you need to append or write a single character.

// Comparison : fgetc() vs fscanf() : fgetc() reads a single character from the file, while fscanf() can read formatted data like strings, integers, etc.
//                                  : fgetc() is simpler when you need just one character, while fscanf() is more flexible for formatted input.
//            : fputc() vs fprintf() : fputc() writes one character to the file, while fprintf() writes formatted output (strings, integers, etc.).
//                                   : fputc() is simpler for single characters, while fprintf() is ideal for formatted data.

// Use Cases : Use fgetc() and fputc() when working with single characters (e.g., reading/writing one character at a time).
//           : Use fscanf() and fprintf() when you need to handle more complex data (e.g., strings, integers, etc.).

// Lets code the above : Using text5.txt.
// fgetc() function :
#include<iostream>
using namespace std;

int main() {
    FILE* fptr;
    fptr = fopen("text5.txt","r");
    if(fptr == NULL) {
        cout<<"Error in opening the file";
    }
    else {
        printf("%c",fgetc(fptr));
        printf("%c",fgetc(fptr));
        printf("%c",fgetc(fptr));
        printf("%c",fgetc(fptr));
        printf("%c",fgetc(fptr));
        fclose(fptr);
        // It will print water kyunki humne sirf pehle ke 5 characters hi read kiye the fgetc() se! and then sirf unko hi print kiya printf se!
    }
}

// fputc() function :
#include<iostream>
using namespace std;

int main() {
    FILE* fptr;
    fptr = fopen("text5.txt","w");
    if(fptr == NULL) {
        cout<<"Error in opening the file";
    }
    else {
        fputc('M',fptr);
        fputc('u',fptr);
        fputc('s',fptr);
        fputc('k',fptr);
        fputc('m',fptr);
        fputc('e',fptr);
        fputc('l',fptr);
        fputc('o',fptr);
        fputc('n',fptr);
        fclose(fptr);
    }
}

// ---------------------------------------------------------------------------------------------------------------------------------->
// EOF (End of File) Handling in C!
// EOF : fgetc() returns EOF when the end of the file is reached. You can use this to read a file character by character until the end of the file.

// Lets code this : using the file text6.txt
#include<iostream>
using namespace std;

int main() {
    FILE* fptr;
    fptr = fopen("text6.txt", "r"); // Open the file in read mode
    if(fptr == NULL) { // Check if the file was successfully opened
        cout << "Error in opening the file";
    } else {
        char ch;
        ch = fgetc(fptr); // Read the first character
        while(ch != EOF) { // Continue reading until the end of the file
            printf("%c", ch); // Print the character
            ch = fgetc(fptr); // Read the next character
        }
        fclose(fptr);  // Close the file after reading
    }
}

// Summary of File Operations :
// Opening the file : fptr = fopen(filename, mode);
// Error Handling : Check if (fptr == NULL) to handle file opening errors.
// Reading : fgetc(fptr) for reading one character at a time.
// Writing : fputc(character, fptr) to write a single character to the file.
// Formatted Input/Output : Use fscanf(fptr, "%specifier", &variable) and fprintf(fptr, "%specifier", variable).
// File Closing : Always close the file using fclose(fptr) after completing the operations.

// Practice Questions :
// Question 1 : Write a code to take input of name from user and then write it into the file!
// File text7.txt used!
#include <stdio.h>
#include <stdlib.h>

int main() {
    char name[100];

    printf("Enter student's name: "); // Get student's name from the user
    fgets(name, sizeof(name), stdin);

    FILE* file = fopen("text7.txt", "w"); // Open file for writing
    if (file == NULL) {
        printf("Error in opening the file\n");
        return 1;
    }
    fputs(name, file); // Write the student's name to the file
    fclose(file); // Close the file

    printf("Student's name has been written to text7.txt\n");

    return 0;
}

// Question 2 : Write a program to read and print 5 integers from the file!
// File text8.txt used!
#include<iostream>
using namespace std;

int main() {
    FILE* fptr;
    fptr = fopen("text8.txt","r");
    if(fptr == NULL) {
        cout<<"Error in opening the file";
    }
    else {
        int n;
        // fscanf(fptr,"%d",&n);
        // printf("%d",n);

        // fscanf(fptr,"%d",&n);
        // printf("%d",n);

        // fscanf(fptr,"%d",&n);
        // printf("%d",n);

        // fscanf(fptr,"%d",&n);
        // printf("%d",n);

        // fscanf(fptr,"%d",&n);
        // printf("%d",n);

        // More optimized approach!
        int i = 0;
        while(i<5) {
            fscanf(fptr,"%d",&n);
            printf("%d",n);
            i++;
        }
        fclose(fptr);
    }
}

// Question 3 : Write a program to write all the odd numbers from 1-n in a file!
// File text9.txt used!
#include<iostream>
using namespace std;

int main() {
    FILE* fptr;
    fptr = fopen("text9.txt","w");
    if(fptr == NULL) {
        cout<<"Error in opening the file";
    }
    else {
        int n;
        cin>>n;
        for(int i = 1; i<=n; i++) {
            if(i%2 != 0) {
                fprintf(fptr,"%d ",i);
            }
        }

        // for(int i = 1; i<=n; i +=2) {
        //     fprintf(fptr,"%d ",i);
        // }

        // Both the above approaches are good!
        fclose(fptr);
    }
}

// Question 4 : Two numbers are written in a file, write a program to replace them with their sum!
// File text10.txt used!
#include<iostream>
using namespace std;

int main() {
    FILE* fptr1;
    fptr1 = fopen("text10.txt","r");
    int n1,n2;
    if(fptr1 == NULL) {
        cout<<"Error in opening the file";
    }
    else {
        fscanf(fptr1,"%d%d",&n1,&n2);
        fclose(fptr1);
    }

    // int sum = n1 + n2;

    FILE* fptr2;
    fptr2 = fopen("text10.txt","w");
    if(fptr2 == NULL) {
        cout<<"Error in opening the file";
    }
    else {
        // fprintf(fptr2,"%d",sum);
        fprintf(fptr2,"%d",n1 + n2);
        fclose(fptr2);
    }
}

// Input/Output Methods in File Operations!
// fgetc and fputc : fgetc : Does not skip whitespaces. It reads one character at a time, including spaces, tabs, and newlines.
//                         : Example : char ch = fgetc(fptr); // Reads the next character, whether it's a space, letter, or newline.
//                 : fputc : Writes one character at a time, including spaces and newlines, exactly as specified.
//                         : Example : fputc('A', fptr); // Writes 'A' and fputc(' ', fptr); // Writes a space

// fgets and fputs : fgets : Reads a string from a file, but does not skip whitespaces. It reads characters until a newline or the end of the specified buffer size is reached. It includes spaces and newlines as part of the string.
//                         : Example : char str[100]; fgets(str, sizeof(str), fptr); // Reads a line including spaces and the newline character.
//                 : fputs : Writes a string, including spaces, exactly as it is
//                         : Example : fputs("Hello World", fptr);  // Writes "Hello World"

// fscanf and fprintf : fscanf : When reading input with %s, %d, etc., it automatically skips leading whitespace (spaces, tabs, newlines). However, with %c, it does not skip whitespace and reads every character (including spaces, tabs, and newlines).
//                             : Example with "%s" or "%d" : int n; fscanf(fptr, "%d", &n); // Automatically skips spaces or newlines before reading the integer.
//                             : Exampe with "%c" : char ch; fscanf(fptr, "%c", &ch); // Reads every character, including spaces, tabs, and newlines.
//                    : fprintf : Writes formatted output to a file. It does not skip whitespace. It writes exactly what you specify.
//                              : Example : fprintf(fptr, "%d %s", num, str);  // Writes integer followed by string (with any spaces you include).

// This sums up the File Handling in C/C++ for now!

// ------------------------------------------------------------ Real World Example of File Handling ---------------------------------------------------------------------->
// Just an Example! Don't go deep into it until you have a important/specific reason! Just get a basic understanding and working!
// Implementation of File Handling!
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

// Structure to represent a student
struct Student {
    string name;
    int age;
    char grade;

    // Function to display student data
    void display() const {
        cout << "Name: " << name << ", Age: " << age << ", Grade: " << grade << endl;
    }

    // Function to input student data
    void input() {
        cout << "Enter name: ";
        cin >> name;
        cout << "Enter age: ";
        cin >> age;
        cout << "Enter grade: ";
        cin >> grade;
    }
};

// Function to save student data to file
void saveToFile(const vector<Student>& students) {
    ofstream outFile("students.txt", ios::out | ios::trunc);  // Open file in write mode (overwrite existing content)

    if (outFile.is_open()) {
        for (const auto& student : students) {
            outFile << student.name << " " << student.age << " " << student.grade << endl;
        }
        outFile.close();  // Close the file
        cout << "Student data saved to file." << endl;
    } else {
        cout << "Error opening file for writing!" << endl;
    }
}

// Function to load student data from file
void loadFromFile(vector<Student>& students) {
    ifstream inFile("students.txt");  // Open file in read mode

    if (inFile.is_open()) {
        Student student;
        while (inFile >> student.name >> student.age >> student.grade) {
            students.push_back(student);  // Read and store student data into vector
        }
        inFile.close();  // Close the file
        cout << "Student data loaded from file." << endl;
    } else {
        cout << "No previous records found." << endl;
    }
}

int main() {
    vector<Student> students;
    loadFromFile(students);  // Load existing student records from file

    int choice;
    do {
        cout << "\nStudent Management System\n";
        cout << "1. View All Students\n";
        cout << "2. Add New Student\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                // View all student records
                if (students.empty()) {
                    cout << "No student records available.\n";
                } else {
                    cout << "\nStudent Records:\n";
                    for (const auto& student : students) {
                        student.display();
                    }
                }
                break;
            }
            case 2: {
                // Add new student
                Student newStudent;
                newStudent.input();
                students.push_back(newStudent);

                // Save updated records to file
                saveToFile(students);
                break;
            }
            case 3:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
                break;
        }
    } while (choice != 3);

    return 0;
}

// And many more scenarios, where you need File handling!
// Rest just implement, practice and learn when needed!