// File Handling in C/C++ (File Input/Output in C/C++)!
// File is a container in storage device to store data!
// There are multiple files types : Text file : .txt files, .cpp files, .c files, .java files and similarly! These files we can understand!
//                                : Binary files : .jpg files, .jpeg files, .mp3 files and similarly! These files we can't understand!
// Operations on Files : Open, Create, Read, Write and Close!
// Through C language we can edit binary files and & text files both! but we will focus on only Text files!

// ---------------------------------------------------------------------------------------------------------------------------------->
// Starting with...
// File Pointers : File is hidden structure that needs to be created for opening a file! A file pointers that points to this structure & is used to access the file!
//               : And now as we dont know the structure, so we have to create it! Then there is a speacial type of pointer FILE *fptr which points to that structure!
//               : File Structure : Internally, the C standard library uses a structure to keep track of information about the file, such as its current position, the mode in which it's opened (read, write, etc.), and other details. This structure is defined in the C standard library, and you, as a programmer, don't need to know the exact details of this structure.
//               : To interact with a file, you use a file pointer. The type FILE is a special type provided by the C standard library that represents this internal file structure. A file pointer (FILE *) is a pointer to this structure.
//               : So first we create the file pointer : FILE* fptr;

// Opening a File : fptr = fopen("File Name",'Mode');
//                : File opening modes : 'r' is open to read
//                                     : 'w' is open to write
//                                     : 'rb' is open to read in binary
//                                     : 'wb' is open to write in binary
//                                     : 'a' is open to append

// Closing a File : fclose(fptr);

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

// Reading from a file : [Data type of the variable] [variable to store data]; fscanf('File pointer',"Access specifier of the type of data we want to read",variable where all the readings will store); This is done when we have to read character from a file!
//                     : Example : char ch; fscanf('fptr',"%c",&ch);

// Lets code the above : Using text2.txt
#include<iostream>
using namespace std;

int main() {
    FILE* fptr;
    fptr = fopen("text2.txt","r");
    if(fptr == NULL) {
        cout<<"File cannot be open!";
    }
    else {
        char ch;
        fscanf(fptr,"%c",&ch);
        printf("Character of the text2.txt file : %c",ch);
        // Jitni baar scan krke print kroge utne characters print honge! mtlb agar saare characters read krne hai toh multiple times scan kro and then multiple times usko output kro!
        // But iska ek aur optimized approach ye hota hai ki loop chalaa do EOF tak ka! ye hum aage dekhenge!
        fclose(fptr);
    }
}

// ---------------------------------------------------------------------------------------------------------------------------------->

// Writing in a File using "write" "w" : Jo character input karana hai usko yaa toh char ch = 'A' krke vo character hi initialize krdo! ya toh scanf ya cin se input lelo! and then iske baad use the fprintf() function!
//                                     : fscanf("File name", "Access specifier for the input you want to read", variable where you want to store the value); example : fprintf(fptr,"%c",ch);
//                                     : Write krne pr jo pehle likha hota hai uss file me vo poora re-write hoke change ho jaata hai!
//                                     : But isme hume file 'w' mode me pehle kholni hoti hai!
//                                     : Agar jiss file me write krna chah rhe hai agar vo exist nhi krti toh vo file create hojayegi and then usme vo humara character(s) write hojayenge!

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


// Writing in a file using "Append" "a" : Its all same as of above! bss yahaa ye hota hai ki isme agar kuch pehle se likha hua hai toh uske aage se write hona shuru hojaata hai!
//                                      : Append me bhi agar file exist nhi krti toh vo create hojaati hai and then usme write hojaata hai!

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

// fgetc() and fputc() functions :
// Now read write krne ke liye fprintf and fscanf ke alawa fgetc(fptr) and fputc('character you want to print',fptr) functions bhi hai!
// fgetc and fputc are indeed alternatives to fscanf and fprintf for reading and writing characters in C. They are specifically designed for reading and writing single characters, and they can be more straightforward for such purposes.
// fgetc: Reads a single character from a file.
// fputc: Writes a single character to a file.

// fgetc vs. fscanf : fgetc reads a single character from the file and returns it as an int. but fscanf is more complex and can read formatted input, including strings, integers, etc.
// fputc vs. fprintf : fputc writes a single character to the file. but fprintf can write formatted output, including strings, integers, etc.

// Use cases : Use fgetc and fputc when you need to read or write one character at a time.
//           : Use fscanf and fprintf when you need to read or write formatted data.

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

// EOF (End of File)
// fgetc return EOF to show that the file has ended!
// Suppose we want to read a string from a file "This is a random series of words", then we need to proceed with reading characters until the EOF!

// Lets code this : using the file text6.txt
#include<iostream>
using namespace std;

int main() {
    FILE* fptr;
    fptr = fopen("text6.txt","r");
    if(fptr == NULL) {
        cout<<"Error in opening the file";
    }
    else {
        char ch;
        ch = fgetc(fptr);
        while(ch != EOF) {
            printf("%c",ch);
            ch = fgetc(fptr);
        }
        fclose(fptr);
    }
} // So this we use when we want to print a whole string of characters! we use the EOF!

// So overall summary is....
// FILE* fptr;
// fptr = fopen(fptr,mode);
// fclose(fptr);
// if (fptr == NULL) condition for error in opening the file
// fscanf(fptr,"access specifier","variable where you want to store the readings!");
// fprintf(fptr,"access specifier","variable whose value you want to print");
// fgetc(fptr) to read single characters
// fputc("variable/character you want to print",fptr) to write single character into a file
// printf() this is the normal printf fuction of c.
// You can also use the cin and cout functions of C++!


// Practice Questions :
// Question 1 : Write a code to take input of name from user and then write it into the file!
// File text7.txt used!
#include <stdio.h>
#include <stdlib.h>

int main() {
    char name[100];

    // Get student's name from the user
    printf("Enter student's name: ");
    fgets(name, sizeof(name), stdin);

    // Open file for writing
    FILE* file = fopen("text7.txt", "w");
    if (file == NULL) {
        printf("Error in opening the file\n");
        return 1;
    }

    // Write the student's name to the file
    fputs(name, file);

    // Close the file
    fclose(file);

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
// This sums up the File Handling in C/C++ for now!