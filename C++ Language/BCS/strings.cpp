// Finding the frequency of a character in a string!
#include<iostream>
#include<string>
using namespace std;

int main() {
    string s1;
    cout<<"Enter the string : ";
    getline(cin,s1);

    char ch;
    cout<<"Enter the character : ";
    cin>>ch;

    if(s1.empty()) {
        cout<<"String is empty!";
        return 0;
    }

    int count = 0;
    for(int i = 0; i<s1.length(); i++) {
        if(s1[i] == ch) {
            count++;
        }
    }
    cout<<count;
}

// Vowels, Consonants, Spaces counts!
#include<iostream>
#include<string>
using namespace std;

char lowercase(char ch) {
    if(ch>='a' && ch<='z') {
        return ch;
    }
    else {
        return ch-'A'+'a';
    }
}

int main() {
    string s1;
    getline(cin,s1);

    int spaceCount = 0;
    int VowelCount = 0;
    int ConsoCount = 0;
    int NumCount = 0;

    if(s1.empty()) {
        cout<<"Empty string!";
    }

    for(int i = 0; i<s1.length(); i++) {
        if(s1[i] == ' ') {
            spaceCount++;
        }
        else if(lowercase(s1[i]) == 'a' || lowercase(s1[i]) == 'e' || lowercase(s1[i]) == 'i' || lowercase(s1[i]) == 'o' || lowercase(s1[i]) == 'u') {
            VowelCount++;
        }
        else if (s1[i]>='0' && s1[i]<='9') {
            NumCount++;
        }
        else {
            ConsoCount++;
        }
    }
    cout<<"Spaces : "<<spaceCount<<" Vowels : "<<VowelCount<<" Consonants : "<<ConsoCount<<" Numbers : "<<NumCount;
}

// Remove non-alphabets from a string!
#include<iostream>
#include<string>
using namespace std;

void removeNonAlphabets(string s1) {
    string temp = "";
    for(int i = 0; i<s1.length(); i++) {
        if(s1[i] >= 'a' && s1[i] <= 'z') {
            temp.push_back(s1[i]);
        }
        else if(s1[i] >= 'A' && s1[i] <= 'Z') {
            temp.push_back(s1[i]);
        }
    }

    s1 = temp;
    cout<<s1;
}

int main() {
    string s1;
    getline(cin,s1);

    removeNonAlphabets(s1);
}

// Length of the string entered by the user!
#include<iostream>
using namespace std;

int lengthOfString(string s1) {
    int i = 0;
    int count = 0;
    while(s1[i] != '\0') {
        count++;
        i++;
    }
    return count;
}

int main() {
    string s1;
    getline(cin,s1);

    int len = lengthOfString(s1);
    cout<<len;
}

// Concatenate Two String
#include<iostream>
#include<string>
using namespace std;

void concatenatingStrings(string s1, string s2) {
    string temp = "";
    int i = 0;
    while(i<s1.length()) {
        temp.push_back(s1[i]);
        i++;
    }
    i = 0;
    while(i<s2.length()) {
        temp.push_back(s2[i]);
        i++;
    }
    cout<<temp;
}

int main() {
    string s1;
    getline(cin,s1);

    string s2;
    getline(cin,s2);

    concatenatingStrings(s1,s2);
}

// Changing every letter with one letter ahead it
#include<iostream>
#include<string>
using namespace std;

void increamentingCharacters(string s1) {
    for (int i = 0; i < s1.length(); i++) {
        if (s1[i] >= 'a' && s1[i] <= 'z') {
            if (s1[i] == 'z') {
                s1[i] = 'a';
            }
            else {
                s1[i] = s1[i] + 1;
            }
        }
    }
    cout << s1 << endl;
}

int main() {
    string s1;
    getline(cin,s1);

    increamentingCharacters(s1);
}

// Check Palidrome!
#include<iostream>
#include<string>
using namespace std;

bool isValid(char ch) {
    if((ch>='A' && ch<='Z') || (ch>='a' && ch<='z') | (ch>='0' && ch<='9')) {
        return true;
    }
    else {
        return false;
    }
}

char lowercase3(char ch) {
    if (ch>='A' && ch<='Z') {
        return ch-'A'+'a';
    }
    else {
        return ch;
    }
}

bool checkPalindrome(string s1) {
    int s = 0;
    int e = s1.length()-1;
    while(s<=e) {
        if(s1[s] != s1[e]) {
            return false;
        }
        else {
            swap(s1[s],s1[e]);
            s++;
            e--;
        }
    }
    return true;
}

bool isPalidrome(string s1) {
    string temp = "";
    for(int i = 0; i<s1.length(); i++) {
        if(isValid(s1[i])) {
            temp.push_back(s1[i]);
        }
    }

    for(int i = 0; i<temp.length(); i++) {
        temp[i] = lowercase3(temp[i]);
    }

    return checkPalindrome(temp);
}

int main() {
    string s1;
    getline(cin,s1);

    if(isPalidrome(s1)) {
        cout<<"Yes it is!";
    }
    else {
        cout<<"No!";
    }
}

// Counting words after just one spaces!
#include<iostream>
#include<string>
#include <sstream> // For stringstream
using namespace std;

int countingWords(string s1) {
    int wordCount = 0;
    bool inWord = false;

    for (char ch : s1) {
        if (ch == ' ') {
            if (inWord) {
                // End of a word
                inWord = false;
            }
        }
        else {
            if (!inWord) {
                // Start of a new word
                inWord = true;
                wordCount++;
            }
        }
    }

    cout<<wordCount;
}

// Here, we are using string streams! which helps in dealing with spaces within a string!, ye words and spaces ko alag alag identify kr paata hai naturally from its base class "stringstream" functionalities!, and it is made that way! hoti ye normal string hi hai bss of type stringstream, bss isliye iske paas spaces handle krna aasaan hai! an unn words pr hum iterate kr sakte hai ">>" use krke!
int countingWords2(string s1) {
    if (s1.empty()) {
        return 0; // Return 0 for empty string
    }

    stringstream ss(s1);
    string word;
    int wordCount = 0;

    string str1 = ss.str(); // It will store the content of "ss" string stream
    cout<<str1; // It is not very different from a normal string, it will print the same thing which is stored in s1, bss difference is ki isme functionalities hai, spaces ko handle krne ki becoz it is of time stringstream!

    while (ss >> word) { // Here hum ">>" use krke ss jo humne string stream banai hai (usme sirf words stored hai jo humne copy kiya hai string s1 me se), usme se saare words ko hum word vaali string me store kr rhe hai! and word count krte jaa rhe hai!
        wordCount++;
    }
    cout<<word; // If your string input is such as "Utkarsh Verma is good boy", then here "boy" will get printed at this line!

    return wordCount;
}

int main() {
    string s1;
    getline(cin,s1);

    countingWords(s1);
    cout<<countingWords2(s1);
}

// Capitalize every word's first character!
#include<iostream>
#include<string>
using namespace std;

char upperCase(char ch) {
    if (ch>='a' && ch<='z') {
        return ch-'a'+'A';
    }
    else {
        return ch;
    }
}

void CapitalizeFirstCharacter(string s1) {
    bool inWord = false;

    for (int i = 0; i < s1.length(); i++) {
        if (s1[i] == ' ') {
            inWord = false;
        }
        else {
            if (!inWord) {
                // Capitalize the first character of the word
                s1[i] = upperCase(s1[i]);
                inWord = true;
            }
        }
    }
    
    cout << s1 << endl;
}

int main() {
    string s1;
    getline(cin,s1);

    CapitalizeFirstCharacter(s1);
}

// Largest word in the string!
#include<iostream>
#include<string>
#include<climits>
#include<sstream>
using namespace std;

int countingWords3(string s1) {
    if (s1.empty()) {
        return 0;
    }

    stringstream ss(s1);
    string word;
    int wordCount = 0;

    while (ss >> word) {
        wordCount++;
    }

    return wordCount;
}

int indexOflargestWord(string &s) {
    stringstream ss(s);
    string word;
    int maxLength = 0;
    int currentIndex = 0;
    int largestWordIndex = 0;
    int index = 0;

    while (ss >> word) {
        int wordLength = word.length();
        if (wordLength > maxLength) {
            maxLength = wordLength;
            largestWordIndex = index;
        }
        index++;
    }

    return largestWordIndex;
}

string largestword(string s1) {
    stringstream ss(s1);
    string word;
    int index = indexOflargestWord(s1);
    int currentIndex = 0;
    string largestWord;

    while (ss >> word) {
        if (currentIndex == index) {
            largestWord = word;
            break;
        }
        currentIndex++;
    }

    return largestWord;
}

int main() {
    string s;
    getline(cin,s);

    string ans = largestword(s);
    cout<<ans;
}