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
        
        fgetc(fptr, "%c", &ch); // Reading and printing one character at a time using fscanf
        printf("Character from the text2.txt file: %c\n", ch);
        
        fgetc(fptr, "%c", &ch); // Repeat the process if you want to print more characters manually
        printf("Character from the text2.txt file: %c\n", ch);
        
        fgetc(fptr, "%c", &ch);
        printf("Character from the text2.txt file: %c\n", ch);
        
        // Optimized approach : Read characters in a loop until the end of the file (EOF)
        // fscanf returns the number of items successfully read, so we check it instead of EOF directly
        
        while (fgetc(fptr, "%c", &ch) != EOF) { // Keep reading until EOF is reached
            printf("Character from the text2.txt file: %c\n", ch); // Print the character read
        }
        
        fclose(fptr); // Close the file when done
    }
    return 0;
}