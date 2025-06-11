// ------------------------------------------------------------- Mathematical Problem Solving Questions ------------------------------------------------------------------------------------------------------------------------->
// Question 1 : Display all the prime numbers in interval of a to b!
#include <iostream>
using namespace std;

bool isPrime(int num) {
    if (num <= 1) return false;
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) return false;
    }
    return true;
}

void displayPrimesInInterval(int start, int end) {
    cout << "Prime numbers between " << start << " and " << end << " are:\n";
    for (int i = start; i <= end; i++) {
        if (isPrime(i)) {
            cout << i << " ";
        }
    }
    cout << endl;
}

int main() {
    int start, end;
    cout << "Enter the starting interval: ";
    cin >> start;
    cout << "Enter the ending interval: ";
    cin >> end;
    displayPrimesInInterval(start, end);
}

// Question 2 : Find all the prime numbers from a to b where their sum is equal to a particular number!
#include <iostream>
#include <vector>
using namespace std;

// Function to check if a number is prime
bool isPrime(int num) {
    if (num <= 1) return false;
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) return false;
    }
    return true;
}

// Function to find all pairs of prime numbers that sum to the given number
void findPrimePairs(int n) {
    vector<int> primes;
    // Find all prime numbers up to n
    for (int i = 2; i <= n; i++) {
        if (isPrime(i)) {
            primes.push_back(i);
        }
    }
    // Check for pairs
    for (int i = 0; i < primes.size(); i++) {
        for (int j = i; j < primes.size(); j++) {
            if (primes[i] + primes[j] == n) {
                cout << n << " = " << primes[i] << " + " << primes[j] << endl;
            }
        }
    }
}

int main() {
    int n;
    cout << "Enter a positive integer: ";
    cin >> n;
    cout << "Possible combinations:\n";
    findPrimePairs(n);
    return 0;
}

// Question 3 : Check if an year is a leap year or not!
#include <iostream>
using namespace std;

bool isLeapYear(int year) {
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
        return true;
    } else {
        return false;
    }
}

int main() {
    int year;
    cout << "Enter year: ";
    cin >> year;

    if (isLeapYear(year)) {
        cout << year << " is a leap year." << endl;
    } else {
        cout << year << " is not a leap year." << endl;
    }
}

// Questions 4 : Find roots of a quadratic equation!
#include<iostream>
#include<math.h>
using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;

    int discriminant = pow(b, 2) - (4 * a * c);

    if (discriminant >= 0) {
        double root1 = (-b + sqrt(discriminant)) / (2.0 * a);
        double root2 = (-b - sqrt(discriminant)) / (2.0 * a);

        cout << "Roots are real and distinct." << endl;
        cout << "Root 1: " << root1 << endl;
        cout << "Root 2: " << root2 << endl;
    } else {
        double realPart = -b / (2.0 * a);
        double imaginaryPart = sqrt(-discriminant) / (2.0 * a);

        cout << "Roots are complex." << endl;
        cout << "Root 1: " << realPart << " + " << imaginaryPart << "i" << endl;
        cout << "Root 2: " << realPart << " - " << imaginaryPart << "i" << endl;
    }
}

// Question 5 : Finding average!
#include<iostream>
using namespace std;

double average(int* arr, int n) {
    int sum = 0;
    for(int i = 0; i<n; i++) {
        sum += arr[i];
    }
    return static_cast<double>(sum)/n; // Here, static_cast is a C++ type casting operator used for safe and well-defined type conversions.
    // It is preferred over C-style casts ((double)sum) because : It is more explicit and type-safe. And, It helps catch unintended or unsafe casts during compilation.
}

int main() {
    int n;
    cin>>n;
    int* arr = new int[n];
    for(int i = 0; i<n; i++) {
        cin>>arr[i];
    }
    cout<<average(arr,n);
}

// Question 6 (College Bootcamp Question) : Write a program to display the sum of the series: 1 + 22 + 333 + 4444 + ... where the number of terms in the series is provided by the user.
#include <iostream>
using namespace std;

int calculateSeriesSum(int size) {
    int sum = 0;
    for (int i = 1; i <= size; i++) {
        int term = 0;
        for (int j = 0; j < i; j++) {
            term = term * 10 + i; // Create the term 1, 22, 333, etc.
        }
        sum += term; // Add the term to the sum
    }
    return sum;
}

int main() {
    int size;
    cout << "Enter the number of terms in the series: ";
    cin >> size;
    int ans = calculateSeriesSum(size);
    cout << "Sum of the series: " << ans << endl;
    return 0;
}

// ------------------------------------------------------------- 2D Array Questions ------------------------------------------------------------------------------------------------------------------------->
// Question 1 : Addition of two matrices!
#include<iostream>
using namespace std;

int** Addition(int** m1, int** m2, int rows, int cols) {
    int** result = new int*[rows];
    for(int i = 0; i<rows; i++) {
        result[i] = new int[cols];
        for(int j = 0; j<cols; j++) {
            result[i][j] = m1[i][j] + m2[i][j];
        }
    }
    return result;
    delete[] result;
}

int main() {
    int row;
    int col;
    cin>>row>>col;

    // Matrix1
    int** Matrix1 = new int*[row];
    for(int i = 0; i<row; i++) {
        Matrix1[i] = new int[col];
    }
    // Matrix1 input!
    for(int i = 0; i<row; i++) {
        for(int j = 0; j<col; j++) {
            cin>>Matrix1[i][j];
        }
        cout<<endl;
    }

    // Matrix2
    int** Matrix2 = new int*[row];
    for(int i = 0; i<row; i++) {
        Matrix2[i] = new int[col];
    }
    // Matrix2 input!
    for(int i = 0; i<row; i++) {
        for(int j = 0; j<col; j++) {
            cin>>Matrix2[i][j];
        }
        cout<<endl;
    }

    int** ans = Addition(Matrix1,Matrix2,row,col);

    for(int i = 0; i<row; i++) {
        for(int j = 0; j<col; j++) {
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }

    delete[] Matrix1;
    delete[] Matrix2;
}

// Question 2 : Multiplication of Two Matrix
#include<iostream>
using namespace std;

int** productOfMatrix(int** Matrix1, int rowM1, int colM1, int** Matrix2, int rowM2, int colM2) {
    // Resultant matrix created!
    int** result = new int*[rowM1];
    for(int i = 0; i < rowM1; i++) {
        result[i] = new int[colM2];
    }

    // Matrix multiplication logic
    for(int i = 0; i < rowM1; i++) {
        for(int j = 0; j < colM2; j++) {
            result[i][j] = 0;
            for(int k = 0; k < colM1; k++) {
                result[i][j] += Matrix1[i][k] * Matrix2[k][j];
            }
        }
    }

    return result;
}

int main() {
    int rowM1;
    int colM1;
    cout<<"Enter number of rows and cols for M1 ";
    cin>>rowM1>>colM1;

    int rowM2;
    int colM2;
    cout<<"Enter number of rows and cols for M2 ";
    cin>>rowM2>>colM2;

    if(colM1 != rowM2) {
        cout<<"Matrices can not be multiplied!";
        return 0;
    }

    int** Matrix1 = new int*[rowM1];
    for(int i = 0; i<rowM1; i++) {
        Matrix1[i] = new int[colM1];
    }
    
    int** Matrix2 = new int*[rowM2];
    for(int i = 0; i<rowM2; i++) {
        Matrix2[i] = new int[colM2];
    }

    // Input in M1
    for(int i = 0; i<rowM1; i++) {
        for(int j = 0; j<colM1; j++) {
            cin>>Matrix1[i][j];
        }
    }

    // Input in M2
    for(int i = 0; i<rowM2; i++) {
        for(int j = 0; j<colM2; j++) {
            cin>>Matrix2[i][j];
        }
    }

    int** result = productOfMatrix(Matrix1,rowM1,colM1,Matrix2,rowM2,colM2);;

    for(int i = 0; i<rowM1; i++) {
        for(int j = 0; j<colM2; j++) {
            cout<<result[i][j]<<" ";
        }
    }
}

// Question 3 : Transpose of a matrix
#include<iostream>
using namespace std;

int** transpose(int** Matrix, int row, int col) {
    int** result = new int*[col];
    for(int i = 0; i<col; i++) {
        result[i] = new int[row];
    }

    for(int i = 0; i<row; i++) {
        for(int j = 0; j<col; j++) {
            result[j][i] = Matrix[i][j];
        }
    }
    return result;
}

int main() {
    int row;
    int col;
    cout<<"Enter number of rows and cols ";
    cin>>row>>col;

    int** Matrix = new int*[row];
    for(int i = 0; i<row; i++) {
        Matrix[i] = new int[col];
    }

    for(int i = 0; i<row; i++) {
        for(int j = 0; j<col; j++) {
            cin>>Matrix[i][j];
        }
        cout<<endl;
    }

    int** result = transpose(Matrix,row,col);

    for(int i = 0; i<col; i++) {
        for(int j = 0; j<row; j++) {
            cout<<result[i][j]<<" ";
        }
        cout<<endl;
    }

    // Freeing allocated memory!
    for(int i = 0; i < row; i++) {
        delete[] Matrix[i];
    }
    delete[] Matrix;

    for(int i = 0; i < col; i++) {
        delete[] result[i];
    }
    delete[] result;
}

// ------------------------------------------------------------- Strings Questions ------------------------------------------------------------------------------------------------------------------------->
// Question 1 : Remove all the non-alphabetical letters from the string!
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

// Question 2 : Concatenate two strings!
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

// Question 3 : Changing every letter from one letter ahead it!
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

// Question 4 : Counting words after just one spaces!
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

// Question 5 : Capitalize every word's first character!
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

// Question 6 : Largest word in the string!
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