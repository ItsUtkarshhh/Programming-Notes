// ---------------------------------------------------------- LECTURE 21 - LeetCode/CodeStudio Questions --------------------------------------------------------------------------------------------------------->
// Question : Rotating an Array!
// Approach : Understanding Rotation: Rotating an array n places means shifting each element forward by n positions. If the array is {1, 2, 3, 4} and we rotate it 2 places, the result is {3, 4, 1, 2}.
//          : Modulus Operation : The modulus operator helps in wrapping indices around the array bounds. For example : If an element is at index i, its new position after rotating k places is calculated as (i + k) % n, where n is the size of the array.
#include<iostream>
#include<vector>
using namespace std;

int printVector1(vector<int>& nums) {
    cout<<"Vector after rotation : ";
    for(int i:nums) {
        cout<<i<<" ";
    }
}

void rotate(vector<int>& nums, int k) {
    vector<int> temp(nums.size());
    for(int i = 0; i<nums.size(); i++) {
        temp[(i+k)%nums.size()] = nums[i];
    }
    // copying temp into the num vector
    nums = temp;
    printVector1(nums);
}

int main() {
    int k;
    cin>>k;
    vector<int> v1;
    v1.push_back(1);
    v1.push_back(2);
    v1.push_back(3);
    v1.push_back(4);
    v1.push_back(5);
    cout<<"Vector before rotation : ";
    for(int i : v1) {
        cout<<i<<" ";
    }
    cout<<endl;
    rotate(v1, k);
} // Isme humne temp vaala array isliye create kiya kyunki uske bina krte toh nums me hi copy hote chale jaata array, if you want to understand this try a dry run, you will get it!

// Question 2 : Check if an array is sorted and rotated or not!
// We have done questions with similar logic previously you can go and learn from there! For reference, here is the logic below :
// Steps : 1) Pivot Point Dhundhna: Pivot wo point hai jahan pe ek element apne next element se bada hota hai. Ye wo jagah hai jahan array rotate kiya gaya hai.
//       : 2) Do Segments ka Sorted Hona: Pivot point ke baad aur uske pehle wale do segments check karo ki wo sorted hain.
//       : 3) Boundary Condition: Array ke last element aur first element ko check karo. agar last element first element se badaa hai toh array sorted hai rotated nhi!
// Iss given order me hi code krna hai! to check that the array is sorted and rotated or not!
// Implementation!
#include<iostream>
using namespace std;

bool isSortedAndRotated(int arr[], int size) {
    if (size == 0) return true;

    int pivot = -1;

    // Pivot point dhundhna, this process will find the point jiske baad se high to low me transition hogya!
    for (int i = 0; i < size - 1; i++) {
        if (arr[i] > arr[i + 1]) {
            pivot = i;
            break;
        }
    }

    // Agar pivot nahi mila, matlab array sorted nahi hai
    if (pivot == -1) return false;

    // Pivot point ke pehle wala part sorted hona chahiye
    for (int i = 0; i < pivot; i++) { // This loop checks if the portion of the array before the pivot is sorted in ascending order.
        if (arr[i] > arr[i + 1]) return false;
    }

    // Pivot point ke baad wala part sorted hona chahiye
    for (int i = pivot + 1; i < size - 1; i++) { // This loop checks if the portion of the array after the pivot is sorted in ascending order.
        if (arr[i] > arr[i + 1]) return false;
    }

    // Last element aur first element ko check karna
    if (arr[size - 1] > arr[0]) return false;

    return true;
}

int main() {
    int arr1[] = {4, 5, 6, 1, 2, 3};
    int arr2[] = {2, 1, 3, 4, 5};
    int arr3[] = {3, 4, 5, 1, 2};
    int arr4[] = {1, 2, 3, 4, 5};
    int arr5[] = {2, 3, 4, 5, 1};

    cout << "Array 1 " << (isSortedAndRotated(arr1, 6) ? "sorted aur rotated hai" : "sorted aur rotated nahi hai") << endl;
    cout << "Array 2 " << (isSortedAndRotated(arr2, 5) ? "sorted aur rotated hai" : "sorted aur rotated nahi hai") << endl;
    cout << "Array 3 " << (isSortedAndRotated(arr3, 5) ? "sorted aur rotated hai" : "sorted aur rotated nahi hai") << endl;
    cout << "Array 4 " << (isSortedAndRotated(arr4, 5) ? "sorted aur rotated hai" : "sorted aur rotated nahi hai") << endl;
    cout << "Array 5 " << (isSortedAndRotated(arr5, 5) ? "sorted aur rotated hai" : "sorted aur rotated nahi hai") << endl;

    return 0;
}

// Unique Approach :
#include <iostream>
using namespace std;

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

bool isSortednRotated(int arr[], int n) {
    if (n <= 1) return false; // Single element or empty array can't be sorted and rotated.
    
    int countBreaks = 0
    for (int i = 0; i < n; i++) { // Check the number of places where the array "breaks" sorting order.
        if (arr[i] > arr[(i + 1) % n]) { // Use modulus to handle wrap-around.
            countBreaks++;
        }
    }
    return countBreaks == 1; // If the array breaks sorting order exactly once, it's sorted and rotated.
}

int main() {
    int n;
    cin >> n;
    int arr[100];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << (isSortednRotated(arr, n) ? "True" : "False") << endl;
} // This approach can also be used when we need to check whether the array is sorted or not! when if the countBreaks == 0, means the array is sorted but not rotated!

// Question 3 : Addition of 2 Arrays, When adding two arrays, you are essentially adding two numbers digit by digit, just like normal mathematical addition. There are two ways to handle the result :
// First : Return the Final Sum as a Number, where Add all digits starting from the end (units place) and calculate the total sum. and Simply return the sum as a single number.
// Second : Return the Result as an Array, where Add the digits starting from the end (units place), storing each digit in reverse order in a new array. and At the end, reverse the array to get the final result in correct order.
// Approach : Start from the End : Addition begins with the last digits (units place) of both arrays.
//          : Case 1 : Arrays of Different Lengths (Ex : 1234 + 6 or 6 + 1234)
//                   : Add digits of both arrays while they overlap. And add remaining digits of the longer array with the carry.
//          : Case 2 : Arrays of Equal Lengths (e.g., 1234 + 1234)
//                   : Add corresponding digits, managing the carry after each addition.
//          : Handle Carry : Compute : Digit to store : sum % 10 (ones place of the sum). And Carry to forward : sum / 10 (tens place of the sum).
//          : Store Result : Store each computed digit in reverse order. If returning as an array, reverse the result at the end.

// Normal Solution : More easy to understand
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void printVector(vector<int> v) {
    for(int i = 0; i<v.size(); i++) {
        cout<<v[i]<<" ";
    }
}

void reverseVector(vector<int>& v) {
    int s = 0;
    int e = v.size()-1;
    while(s<e) {
        swap(v[s],v[e]);
        s++;
        e--;
    }
}

void addTwoArrays(vector<int> v1, vector<int> v2) {
    int i = v1.size()-1;
    int j = v2.size()-1;
    int carry = 0;
    // int sum = 0;
    vector<int> ans;
    while(i>=0 && j>=0) {
        int val1 = v1[i];
        int val2 = v2[j];
        int sum = val1 + val2 + carry;
        carry = sum/10;
        sum = sum%10;
        ans.push_back(sum);
        i--;
        j--;
    }
    while(i>=0) {
        int val1 = v1[i];
        int sum = val1 + carry;
        carry = sum/10;
        sum = sum%10;
        ans.push_back(sum);
        i--;
    }
    while(j>=0) {
        int val2 = v2[j];
        int sum = val2 + carry;
        carry = sum/10;
        sum = sum%10;
        ans.push_back(sum);
        j--;
    }
    while(carry!=0) {
        ans.push_back(carry%10);
        carry = carry/10;
    }
    reverseVector(ans);
    printVector(ans);
}

int main() {
    int size1,size2;
    cin>>size1>>size2;
    vector<int> v1(size1);
    vector<int> v2(size2);
    for(int i = 0; i<size1; i++) {
        cin>>v1[i];
    }
    for(int i = 0; i<size2; i++) {
        cin>>v2[i];
    }
    addTwoArrays(v1,v2);
}

// More optimized solution : Here we have just reduced some operations into one line
#include<iostream>
#include<vector>
using namespace std;

vector<int> reverse(vector<int> v) {
    int s = 0;
    int e = v.size()-1;
    while(s<e) {
        swap(v[s++], v[e--]);
    }
    return v;
}

vector<int> findArraySum(vector<int>& a, int n, vector<int>& b, int m) {
    int i = n-1;
    int j = m-1;
    vector<int> ans;
    int carry = 0;
    while(i >= 0 || j >= 0 || carry != 0) {
        int val1 = (i >= 0) ? a[i] : 0;
        int val2 = (j >= 0) ? b[j] : 0;
        int sum = val1 + val2 + carry;   
        carry = sum / 10;
        ans.push_back(sum % 10);
        if (i >= 0) i--;
        if (j >= 0) j--;
    }
    return reverse(ans);
}

int main() {
    vector<int> v1;
    v1.push_back(1);
    v1.push_back(2);
    v1.push_back(3);
    v1.push_back(4);

    vector<int> v2;
    v2.push_back(5);
    v2.push_back(5);
    v2.push_back(5);

    vector<int> result = findArraySum(v1, v1.size(), v2, v2.size());

    // Print the result
    for (int i = 0; i < result.size(); i++) {
        cout << result[i];
    }
}

// ---------------------------------------------------------- LECTURE 22 - Character Arrays and Strings --------------------------------------------------------------------------------------------------------->
// In C, there are two ways to handle strings :
// Character Arrays : A simple array of characters without any special handling for string operations. It can store individual characters, but if you want to use it as a string, you need to manually add a null character ('\0') at the end to mark the end of the string.
// C-Type Strings : These are character arrays with a null character ('\0') at the end. This is important because it allows you to use string functions like strlen(str), strcmp(str1,str2), strcat(str1,str2), strcpy(newStr,oldStr) and strrev(str) etc. which require the null character to know where the string ends. To use these methods you need to include a "string.h" library!
//                : In C, a character array is simply an array that holds individual characters. It does not automatically recognize itself as a string unless a null-terminator ('\0') is explicitly added at the end. For example:
//                : In C, the size of a character array must be sufficient to hold all the characters plus the null terminator. If you forget to include the null terminator, functions designed to work with strings will behave incorrectly. means It is also important to remember that the null character takes up space in the array. So, when you define an array with 5 characters, you need to allocate space for the null terminator as well, which means an array of 6 elements.
//                : String Literals in C : When you initialize a string in C using a string literal, the compiler automatically adds the null terminator for you.

// In C++, you can use character arrays similarly to C, but C++ also provides the string type, which handles strings more conveniently. You don't need to explicitly add a null character when using the string type. However, you can still use character arrays as strings if needed, but it's not necessary as string in C++ is more flexible.

// Note : Buffer Overflow : When using C-style strings, be careful about buffer overflow. If you copy or concatenate strings without checking the size of the array, you may accidentally overwrite memory, leading to bugs or crashes.
//                        : Example : char str[10]; strcpy(str, "Hello, world!"); Buffer overflow : "Hello, world!" is too large

// char[] (Character Array) : Mutable : It stores a sequence of characters, with the size defined at compile time. It includes a null terminator (\0) to mark the end of the string, ensuring the string functions properly when processed.
// char* (Character Pointer) : A pointer to a sequence of characters in memory. It can point to modifiable or read-only memory, depending on where it points. Can be used to traverse a string or manage memory dynamically.
// const char* (Constant Character Pointer) : A pointer to a read-only sequence of characters. Commonly used for string literals (like "Hello"), ensuring that the contents of the string cannot be modified accidentally.
// std::string (C++ Standard Library) : A class in the C++ Standard Library for handling strings. Dynamic size : Memory is managed automatically as the string grows or shrinks. Offers built-in functions (like length(), substr(), find()) and operators (like + for concatenation) for easier and safer string manipulation. No need to manually handle memory or null terminators.
// Double Quotes (" ") : Used to represent string literals in C/C++ and many other languages. A string literal is an array of characters ending with the null terminator (\0). Example : "Hello".
// Single Quotes (' ') : Used to represent single characters (not strings) in C/C++. Example : 'A', which is a single character, not a string.
// Null Character ('\0') : A special character used to indicate the end of a C-style string. Marks where a string terminates in memory, ensuring functions like strlen() know where the string ends. Every C-style string ends with this character, but it's invisible and not part of the visible content.

// Lets understand further thru code...
#include<iostream>
using namespace std;

int main() {
    char name[20];
    cout<<"Enter you name : "<<endl;
    cin>>name;

    cout<<"Your name is "<<name<<endl;
    // Now here what happened is Utkarsh input dene pr vo toh as it is print hogya but jab "Utkarsh Verma" input diya tab poori string print nhi hui, aisa isliye kyunki space, new line character and tab inn sab se input band ho jaata hai!
} // cin is designed the way that will read the input until it do not encounters a new line, space or tab! and toh cin se hum characters bhi read kraa sakte hai and read kraa ke uss char variable me store kr sakte hai! and hum strings bhi read kraa sakte hai! but in C, read operations ke liye we use scanf, so ye scanf character read krega ya string, ye iss baat pr depend krega ki humne format specifiers %c use kiya hai ya %s, agar %c toh sirf ek character read krega chaahe kaisi bhi string ho! but %s ek string read krega jab tak koi space, tab ya new line na aajaye!

#include<iostream>
using namespace std;

int main() {
    char name[20];
    cout<<"Enter you name : "<<endl;
    cin>>name;
    name[2] = '\0'; // Humne bss name ke 2nd index pr ek null character daal diya ab as our logic says ki pehle user input krega and then uss input ke 2nd index pr \0 humne daal diya and toh jab cout hoga name, tab pooraa name nhi print hoga sirf index 0,1 print honge kyunki 2nd pr execution ruk gya! toh like agar Utkarsh input doge toh iss naam ke 2nd index pr \0 ajayega and it will look like Ut\0karsh and then print sirf Ut hoga!
    cout<<"Your name is "<<name<<endl;
}

// Question 1 : Find the length of the character array!
#include<iostream>
using namespace std;

int lengthString(char input[]) {
    int count = 0;
    for(int i = 0; input[i]!='\0'; i++) {
        count++;
    }
    return count;
}

int main() {
    char input[30];
    cin>>input;
    cout<<"Length of the char array is : "<<lengthString(input)<<endl;
}

// Question 2 : Reverse a string
#include<iostream>
using namespace std;

int lengthString(char input[]) {
    int count = 0;
    for(int i = 0; input[i]!='\0'; i++) {
        count++;
    }
    return count;
}

// First Method of reversing
char* reverse(char* input) { // Here we have used a * over the char keyword! kyunki bina star ki agar iss function ko create krenge toh ye ek single character return krega sirf but hum chahte hai ki ye ek string return kre and in that case we need to make the data type of the function also a character array! and that's why we have used the *. integer me bhi ye dikkat aa sakti thi pr usme hum pehle se hi size input lete the, pr iss function me humne size input nhi liya hai toh that's why hume kuch toh btaana padega ki isko ek character array return krna hai, toh yaa toh hum star lgaye yaa toh hum isko input me isko size dede!
    int i = 0, j = lengthString(input)-1;
    while(i<=j) {
        swap(input[i], input[j]);
        i++;
        j--;
    }
    return input;
}

// Second method of reversing
void reverse2(char input[], int n) {
    int i = 0, j = n-1;
    while(i<=j) {
        swap(input[i], input[j]);
        i++;
        j--;
    }
}

int main() {
    // From first method through reverse function
    char input[50];
    cin>>input;
    cout<<"Reversed character array is : "<<reverse(input);
    cout<<endl;

    // From second method through reverse2 function
    char input2[50];
    cin>>input2;
    reverse2(input2, lengthString(input2)); // Yaa toh length function ki value kisi variable me store kraa ke input me dedo function ke yaa toh directly baat ek hi hai!
    cout<<"Reversed character array is : "<<input2;
}

// Question 3 : Check for a palindrome
// Approach 1 (Reverse and Compare) : Reverse the string and store the reversed string in a separate variable. Compare the original string with the reversed one. If both are the same, it's a palindrome; otherwise, it's not.
//                                  : Drawback : This approach uses extra space for storing the reversed string, resulting in higher space complexity.
// Approach 2 (End-to-End Comparison) : Compare characters from both ends of the string. If all corresponding characters match, it's a palindrome.
//                                    : Case Sensitivity: By default, it will be case-sensitive, meaning 'A' and 'a' will be treated as different characters. For example, "Noon" won't be considered a palindrome because "Noon" reversed is "nooN".
//                                    : Solution for Case Sensitivity : If case doesn't matter, convert both the string and its reverse to either lowercase or uppercase before comparing.
//                                    : Drawback : This approach uses extra space for storing the reversed string, resulting in higher space complexity.
// Approach 1 (Reverse and Compare) :
#include<iostream>
#include<cstring>
using namespace std;

int lengthString(char input[]) {
    int count = 0;
    for(int i = 0; input[i]!='\0'; i++) {
        count++;
    }
    return count;
}

char* reverse1(char input[]) {
    int i = 0, j = lengthString(input)-1;
    while(i<=j) {
        swap(input[i], input[j]);
        i++;
        j--;
    }
    return input;
}

int main() {
    char s1[50] = "Noon";
    char s1_reversed[50];
    strcpy(s1_reversed, reverse1(s1)); // Copy the reversed string into s1_reversed
    
    // Compare the reversed string with the original string
    if (strcmp(s1, s1_reversed) == 0) {
        cout << "The string is a palindrome." << endl;
    } else {
        cout << "The string is not a palindrome." << endl;
    }
    return 0;
} // But yes as we have discussed we have a problem with this approach ki yahaa pr ek extra space le rha hai s1_reversed! so we will move forward with another method!

// Approach 1 (Reverse and Compare) :
#include<iostream>
#include<cstring>
using namespace std;

bool checkPalindrome(char input[], int n) {
    int s = 0;
    int e = n-1;
    while(s<=e) {
        if(input[s] != input[e]) {
            return false;
        }
        else {
            s++;
            e--;
        }
    }
    return true;
}

int main() {
    char s1[50];
    cout<<"Enter s1 : ";
    cin>>s1;
    bool result = checkPalindrome(s1, strlen(s1));
    if(result) {
        cout<<"Its a palindrome!";
    }
    else {
        cout<<"Its not a palindrome!";
    }
} // But still as discussed above there is still a problem and that is about the case sensitivity! so for that we will add one more function to it to convert all the UPPERCASE alphabets to lowercase! and the logic will be like, suppose we have a upper case character ch and we want to convert it into lower case so what we will do is, we will write ch - 'A' + 'a', isse kya hoga jaise, suppose koi upper case character hai B toh B - A + a will be be 'b', how? kyunki B - A will give 1 and then a me 1 jab add hoga toh vo b ban jayega! Now we will code it!

// A little modifications in the approach 2 :
#include<iostream>
#include<cstring>
using namespace std;

// So this is how we have managed case sensitivity here! So overall yahaa we have used the ASCII values to convert the Uppercase into lower case!
char tolowercase(char ch) {
    if(ch >= 'a' && ch <= 'z') {
        return ch;
    }
    else {
        return ch - 'A' + 'a';
    }
}

// Applied those case sensitivity modifications to it!
bool checkPalindrome2(char input[], int n) {
    int s = 0;
    int e = n-1;

    while(s<=e) {
        if(tolowercase(input[s]) != tolowercase(input[e])) {
            return false;
        }
        else {
            s++;
            e--;
        }
    }
    return true;
}

int main() {
    char s1[50];
    cout<<"Enter s1 : ";
    cin>>s1;
    bool result = checkPalindrome2(s1, strlen(s1));
    if(result) {
        cout<<"Its a palindrome!";
    }
    else {
        cout<<"Its not a palindrome!";
    }
} // In the above code, the checkPalindrome vaala function Noon ko palindrome nhi maanega kyunki isme N and n are considered different! but after those case sensitivity modifications in the checkPalindrome2 function, now the Noon will be considered palindrome kyunki ab N and n are same for that function!

// What are strings! They are character arrays only! but in cpp we have a keyword also for the strings!
#include<iostream>
using namespace std;

int main() {
    string s1 = "Utkarsh";
    cout<<s1<<endl;
    s1.push_back('V');
    cout<<s1<<endl;
    s1.pop_back();
    cout<<s1<<endl;
    cout<<s1.length();
}

// Question 4 : Check for a valid palindrome!
// Approach : First we will remove all the faaltu ke characters, then saare characters ko lowercase me convert krenge and then finally we will check that is it a palindrome or not! and jaise jaise hum faaltu characters remove krte jayenge vaise vaise hum unn valid characters ko hum naye string me push krte jayenge!
#include<iostream>
using namespace std;

bool isValid(char ch) {
    int i = 0;
    if(ch >= 'a' && ch <= 'z' || ch >= 'A' && ch <= 'Z' || ch >= '0' && ch <= '9') {
        return true;
    }
    else {
        return false;
    }
}

char lowercase(char ch) {
    if(ch >= 'a' && ch <= 'z' || ch >= '0' && ch <= '9') {
        return ch;
    }
    else {
        return ch - 'A' + 'a';
    }
}

bool validPalindrome(string s) {
    string temp = "";
    for(int i = 0; i<s.length(); i++) {
        if(isValid(s[i])) {
            temp.push_back(lowercase(s[i]));
        }
    }
    int i = 0;
    int j = temp.length() - 1;
    while(i<j) {
        if(temp[i] != temp[j]) {
            return false;
        }
        i++;
        j--;
    }
    return true;
}

int main() {
    string str = "utka&%$$%&aktk";
    if(validPalindrome(str)) {
        cout<<"it is a Palindrome!";
    }
    else {
        cout<<"Not a palindrome!";
    }
}

// Question 5 : Find the maximum occuring characters in a string!
// Approach : Here we are going to consider only lowercase characters and both the uppercase and lower case characters both will be considered same and if a string has a and A both, then count of 'a' will be 2, becoz a and A both are considered same!
// Now lets code and then will discuss the approach...
#include<iostream>
using namespace std;

char maxOccCharacter(string s) {
    int arr[26] = {0};

    // Upar humne ek array create kiya jisme jo bhi string hum input krenge uske characters ka count unke alphabetical position ke according store hojayega arr vaale array me!
    for(int i = 0; i<s.length(); i++) {
        char ch = s[i];
        int number = 0;
        if(ch >= 'a' && ch <= 'z') {
            number = ch - 'a';
        }
        else {
            number = ch - 'A';
        }
        arr[number]++;
    }

    // Yahaa humne uss arr vaale array ki sabse maximum value nikali!
    int maxi = -1, ans = 0;
    for(int i = 0; i<26; i++) {
        if(maxi<arr[i]) {
            ans = i; // Yahaa pr jiss index pr maximum value hai vo ans me store ki! kyunki in the end yhi toh vo final alphabet batayega jo maximum number of time occur hua hai!
            maxi = arr[i]; // Yahaa pr humne vo sabse zyada occurence kitni thi vo store kiya!
        }
    }

    // Then yahaa humne finally a me ans add krke vo konsa character hai jo sabse zyada baar occur hua hai vo nikal liya!
    char finalAnswer = 'a' + ans;
    return finalAnswer;
}

int main() {
    string s;
    cin>>s;
    cout<<maxOccCharacter(s);
} // Now lets understand upar humne actually kiya kya hai! so maanlo humne ek string enter kiya "moon", now ye moon string function ke pehle for loop me jayegi, and then uske saare characters scan honge and uske saath saath unn sab ka alphabetical order ke according kya kya position hai uske according arr[26] vaale array me uss character ka count increament krdiya jayega!
// So like if moon is there, then 'm' gya pehle for loop me and now ch - 'a' vaale if statement me gya ye 'm' and usme isko number mila 13 according to ch - 'm' and now, arr[26] me 13th position pr ek count add krdiya gya using arr[number]++ and aise hi baaki characters of that string ke saath hua and then finally, next for loop me uss arr[26] ko hi traverse krke jo maximum value tha uska jo index tha vo nikala gya and then uss index ko 'a' ke saath add krdiya gya and then we got the final character jo sabse maximum times occur hua hai!

// cin.getline() function : This is a function which is used to take input a string with spaces, like we know a normal cin will stop input whenever a space, newline or tab is encountered! but using this cin.getline() here we can specify that from where the input will be stored and what will be the maximum size of input and what will be the delimiter, like in normal cin delimiters are newline, tab or space, but here we can specify the delimter if we let that parameter vacant then newline will be considered as delimiter by default!
#include<iostream>
#include<string>
using namespace std;

int main() {
    const int max_size = 50;
    char ch[max_size];
    cin.getline(ch, max_size); // Here we have'nt use the delimiter so by default it will be \n which is the newline!
    cout<<ch;
}

#include<iostream>
#include<string>
using namespace std;

int main() {
    const int max_size = 50;
    char ch[max_size];
    cin.getline(ch, max_size, '7'); // Here we have used a delimter so while inputting a string kahin pr bhi input me agar 7 dikh gya toh vhi pr execution stop hojayega! and jab print karaoge toh bss uss delimiter tak hi print hoga! and similarly we can use any delimiter!
    cout<<ch;
}

#include<iostream>
#include<string>
using namespace std;

int main() {
    const int max_size = 50;
    string str;
    getline(cin, str, '7'); // This function does the same as of the cin.getline function as in character arrays! here also we can use delimiter the only thing is that here the parameters are a little different!
    cout<<str;
}

// Question 6 : You have a line of text and you have to replace all the spaces with the @40
#include<iostream>
#include<string>
using namespace std;

string replaceSpaces(string &str) {
    string temp = "";
    for(int i = 0; i<str.length(); i++) {
        if(str[i] == ' ') {
            temp.push_back('@');
            temp.push_back('4');
            temp.push_back('0');
        }
        else {
            temp.push_back(str[i]);
        }
    }
    return temp;
}

int main() {
    string input;

    cout<<"Enter the string : ";
    getline(cin, input);

    cout<<replaceSpaces(input);
}

// Question 7 : Remove all the occurences of a sub string in a parent string!
// Aim : The task is to remove all occurrences of a given substring (abc) from a parent string repeatedly until no such substring remains.
// Steps : Start with the parent string (daabcbaabcbc).
//       : Remove the first occurrence of abc as you traverse the string : da"abc"baabcbc → dabaabcbc
//       : Repeat the process : daba"abc"bc → dababc
//                            : dab"abc" → dab
//       : The final string, after all removals, is dab.
// Now we will code the logic!
#include<iostream>
#include<string>
using namespace std;

string removeOcc(string str, string substr) {
    while(str.length()!=0 && str.find(substr) < str.length()) {
        str.erase(str.find(substr), substr.length());
        // .erase() : string str = "Hello, World!"; str.erase(7); // Erases characters from position 7 to the end. output : "Hello, "
        //          : string str = "Hello, World!"; str.erase(5, 7); // Erases 7 characters starting from position 5. output: "Hello!"
    }
    return str;
}

int main() {
    string str;
    string substr;
    getline(cin, str);
    getline(cin, substr);
    cout<<"The final string is : "<<removeOcc(str, substr);
}

// Question 8 : Permutation in string! agar s1 vaali string ka koi bhi permutation (arrangement) agar s2 me exist krta hai toh hum uss case me true return krenge!
// Like suppose, s1 : ab and s2 : eibaooo, now we know s1 permutations can be "ab" and "ba", so ab agar s2 me ab ya ba me se koi bhi exist krta hai toh hum true return krdenge!
#include<iostream>
#include<string>
using namespace std;

bool checkEqual(int a[26], int b[26]) {
    for(int i = 0; i<26; i++) {
        if(a[i] != b[i]) {
            return 0;
        }
    }
    return 1;
}

bool checkInclusion(string s1, string s2) {
    // character count array
    int count1[26] = {0};

    for(int i = 0; i<s1.length(); i++) {
        int index = s1[i] - 'a';
        count1[index]++;
    }

    // Traverse s2 in window of size of s1 length and compare
    int i = 0;
    int windowSize = s1.length();
    int count2[26] = {0};

    // Running for first window
    while(i<windowSize && i<s2.length()) {
        int index = s2[i] - 'a';
        count2[index]++;
        i++;
    }

    if (checkEqual(count1, count2)) {
        return 1;
    }

    while(i<s2.length()) {
        char newChar = s2[i];
        int newIndex = newChar - 'a';
        count2[newIndex]++;

        char oldChar = s2[i - windowSize]; // Getting the character going out of the window
        int oldIndex = oldChar - 'a';
        count2[oldIndex]--; // Decrementing its count since it's going out of the window

        i++;
        
        if (checkEqual(count1, count2)) {
            return 1;
        }
    }

    return 0;
}

int main() {
    string s2 = "eibbabo";
    string s1 = "ab";
    cout<<checkInclusion(s1, s2);
}

// Question 9 : Removing all adjacent duplicates! Actual question number 1047 on LeetCode! Solve this on your own!
// Solution :
#include <iostream>
#include <string>
using namespace std;

string removeDuplicates(string s) {
    int i = 0;
    while (i < s.size() - 1) {
        if (s[i] == s[i + 1]) {
            s.erase(i, 2); // Erase both duplicate characters
            if (i > 0) {
                i--; // Move one step back to recheck for new duplicates
            }
        }
        else {
            i++; // Only move to the next character if no duplicate was found
        }
        // Check if the string is empty after erasing
        if (s.empty()) {
            break;
            // return s // You can also write this... and this becomes more safe becoz, By using return s, you exit the function directly with the result, so there's no risk of unnecessary operations. But okay its upto you, what you want to choose, both are fine!
        }
    }
    return s;
}

int main() {
    string s = "aabbccddeeff";
    cout << "Original string: " << s << endl;
    string result = removeDuplicates(s);
    cout << "String after removing adjacent duplicates: " << result << endl;
    return 0;
}

// Question 10 : String Compression! Ques number 443 on Leetcode
#include<iostream>
#include<string>
#include<vector>
using namespace std;

int compress(vector<char>& chars) {
    int i = 0;
    int ansIndex = 0;
    int n = chars.size();
    while(i<n) {
        int j = i+1;
        while(j<n && chars[i] == chars[j]) {
            j++;
        }
        // Yahaa kab aoge? ya toh jab vector poora traverse krdiya, ya toh jab new/different character encounter kiya! but bhi toh j me yaa toh poora array traverse krne ke baad ka index hoga ya toh jaha pr usko different character mila uska index!

        // Old Character store krliya!
        chars[ansIndex++] = chars[i];
        int count = j-i;

        if(count>1) {
            // converting counting into single digits and saving the answer...
            string cnt = to_string(count);
            for(char ch : cnt) {
                chars[ansIndex++] = ch;
            }
        }
        // Moving to new different character, till now what we did is upar ki first character kitni baar aaya hai usko count kiya and usko encode kiya and agar count more than 1 hai toh usko string ke form me convert krke usko string me hi daal diya!
        i = j;
    }
    return ansIndex;
}

int main() {
    vector<char> str = {'a','b','b','c','c','d','d'};
    compress(str);

    for (int i = 0; i < compress(str); i++) {
        cout << str[i];
    }
}

// Note 1 : If you write something like this, char* canChange = "Hello World"; and updates canChange to canChange = "Hello"; then it will have no issue! because This is valid because canChange is a pointer. It stores the address of the string literal "Hello World". You can reassign the pointer canChange to point to another string literal (Ex: "Hello"). 
//        : String literals are stored in read-only memory in most compilers. Modifying the content of the string literal via the pointer (*canChange) is undefined behavior. The pointer canChange points to the memory location where the string literal "Hello World" is stored. This memory is read-only.
//        : If you attempt to modify the string literal directly through the pointer, it will have some undefined behaviour!
//        : Why is it undefined behaviour : The behavior depends on the compiler and system. Some compilers protect the memory where string literals are stored to prevent accidental modification. Other compilers might not, but modifying string literals is never guaranteed to work correctly.
//        : Safe alternatives : If you need a modifiable string, you should declare it as an array, char canChange[] = "Hello World"; It Creates a copy in writable memory, canChange[0] = 'h'; This is valid
//        : Why does it happen : Its an optimization choice! Storing string literals in read-only memory saves space since multiple instances of the same string literal can share the same memory.

// Note 2 : If you write something like this, char canChange[] = "Hello World"; canChange[] = "Hello"; It shows Error! This is invalid because canChange[] is an array. When you write char canChange[] = "Hello World";, the array is initialized with the string's contents, and its size is fixed (in this case, 12 including the null character \0).\
//        : You cannot reassign the entire array using = after initialization.
//        : char canChange[] = "Hello World"; canChange[0] = 'H'; Works, modifies individual elements. strcpy(canChange, "Hello"); Works, modifies the content using a function like strcpy.

// Input/Output methods with Spaces in C Strings : Using scanf : char str[100]; scanf("%s", str); Input: "Hello World" and Output in str: "Hello" (scanf stops at the first space)
//                                               : Using fgets : char str[100]; fgets(str, 100, stdin); Input: "Hello World" and Output in str: "Hello World" (including spaces, up to a newline or size limit)
//                                                             : scanf cannot read strings with spaces; use fgets() for input with spaces. 
//                                                             : Reads the entire line, including spaces, until a newline (\n) or the specified character limit (n). Appends a null character (\0) at the end.
//                                                             : If you press Enter, the newline (\n) is stored in the string. To remove it : str[strcspn(str, "\n")] = '\0'; Removes '\n' safely
//                                               : Using puts : puts outputs a string with a newline added at the end. char str[] = "Hello World"; puts(str); Outputs: Hello World\n... So as you can see puts is adding another extra \n at the end of the string!
//Hence, to get a proper input/output of strings with spaces in C, one should use fgets for input and printf for output!

// Note 3 : gets() is unsafe and should not be used because it does not check for buffer overflow, which can cause security vulnerabilities. For safer alternatives use fgets()!
//        : It has been deprecated in C99 and removed in C11.

// ---------------------------------------------------------- LECTURE 23 - 2D Arrays --------------------------------------------------------------------------------------------------------->
// To create a matrix with n rows and m columns, you would initially think of making n separate arrays. However, this approach becomes impractical for large matrices like 1000x1000. Instead, we use 2D arrays.
// Syntax of 2D array : int arr[rows][columns];
// Memory Storage of 2D Arrays : Although 2D arrays are visualized as grids, they are stored linearly in memory. Elements are placed in contiguous memory locations, row by row (in row-major order).
// Mapping 2D Indices to Linear Memory : Memory index = (column_count * row_index) + column_index
//                                     : Example : To access the element at arr[1][2] (2nd row, 3rd column) in a 3x3 matrix : Memory index = 3 * 1 + 2 = 5 (6th element in linear memory, as indexing starts from 0).

// Note : Arrays in C/C++ are static, meaning their size must be known at compile time. For dynamic-sized matrices, use dynamic memory allocation with pointers.
//      : Dynamic 2D arrays in C++ : int** arr = new int*[rows]; for (int i = 0; i < rows; i++) { arr[i] = new int[columns]; }
//      : Always deallocate dynamic arrays to avoid memory leaks.

// Creating 2D array! int arr[row][column];
// Taking input! cin>>arr[i][j];
// Output! cout<<arr[i][j];

// Now lets code!
#include<iostream>
using namespace std;

int main() {
    int twoDarray1[3][4];
    for(int i = 0; i<3; i++) {
        for(int j = 0; j<4; j++) {
            cin>>twoDarray1[i][j];
        }
    }
    cout<<"Our 2D array :"<<endl;
    for(int i = 0; i<3; i++) {
        for(int j = 0; j<4; j++) {
            cout<<twoDarray1[i][j]<<" ";
        }
        cout<<endl;
    }
    // So this is a way of taking input of the array and then printing it! hum alag alag way se print kr sakte hai bss i and j positions ko shift krke!
    // Ye matrix pattern me print ho rha hai kyunki endl lagaya hai humne for loop ke andar, vrna aise normal ye linearly hi store ho rhi hai values!
}

// Intiallizing 2D arrays!
#include<iostream>
using namespace std;

int main() {
    int twoDarray1[3][4] = {1,2,3,4,5,6,7,8,9,10,11,12}; // Isme toh humne saare elements daal diye ab jo bhi jaise jaise i and j ke hisaab se store hote jayenge array me!
    int twoDarray2[3][4] = {{1,2,3,4}, {5,6,7,8}, {9,10,11,12}}; // Isme hume kis row me konsa element daalna hai vo hum pehle hi btaa sakte hai!
}

// Linear Search in 2D Array!
#include<iostream>
using namespace std;

// When passing a 2D array to a function, the column size must be specified. This is because, unlike a 1D array where the size is implicit, the compiler needs to know the number of columns to correctly calculate memory offsets and access elements.
// Without the column size, the compiler would not know how many elements to skip when moving from one row to the next in memory. For example, when defining a 2D array like arr[][3], the column size must be included in the function signature to ensure proper access to the array elements.
bool isPresent(int arr[][4], int target /*, int m, int n */) {
    for(int i = 0; i<3; i++) {
        for(int j = 0; j<4; j++) {
            if(arr[i][j] == target) {
                return 1;
            }
        }
    }
    return 0;

    // Alternative...
    // for(m = 0; m<3; m++) {
    //     for(n = 0; n<4; n++) {
    //         if(arr[m][n] == target) {
    //             return 1;
    //         }
    //     }
    // }
    // return 0;
}

int main() {
    int arr[3][4];
    for(int i = 0; i<3; i++) {
        for(int j = 0; j<4; j++) {
            cin>>arr[i][j];
        }
    }
    int target;
    cout<<"Enter your target element : ";
    cin>>target;

    if(isPresent(arr, target, 3, 4)) {
        cout<<"Element Present!";
    }
    else {
        cout<<"Not Present!";
    }
}

// Question : Row sum! printing sum of all the rows in the 2D array!
#include<iostream>
using namespace std;

void rowSum(int arr[][4], int m, int n) {
    for(int i = 0; i<3; i++) {
        int sum = 0;
        for(int j = 0; j<4; j++) {
            sum += arr[i][j];
        }
        cout<<sum<<" ";
    }
}

int main() {
    int arr[3][4];
    for(int i = 0; i<3; i++) {
        for(int j = 0; j<4; j++) {
            cin>>arr[i][j];
        }
    }

    rowSum(arr, 3, 4);
} // Above example was for row wise sum, column wise krna ho toh bss function me jaake i and j ko interchange krdo!

// Question : Find the largest rowsum and which row has it!
#include<iostream>
#include<climits>
using namespace std;

int largestRowsum(int arr[][4], int m, int n) {
    int maxi = INT_MIN;
    int rowNum = -1;
    for(int i = 0; i<3; i++) {
        int sum = 0;
        for(int j = 0; j<4; j++) {
            sum += arr[i][j];
        }
       if(sum > maxi) {
        maxi = sum;
        rowNum = i;
       }
    }
    cout<<"Maximum sum is : "<<maxi<<endl;
    return rowNum;
}

int main() {
    int arr[3][4];
    for(int i = 0; i<3; i++) {
        for(int j = 0; j<4; j++) {
            cin>>arr[i][j];
        }
    }
    cout<<largestRowsum(arr, 3, 4);
}

// Question : Wave print problem! Here we have to print the array elements like a wave, means suppose you have a 2D array as, {{1,2,3,4}, {5,6,7,8}, {9,10,11,12}}, so here print aise hoga ki like, 1,5,9,10,6,2,3,7,11,12,8,4
// Toh aise hume print krna hai ki like 1st column me upar se neeche print krenge then 2nd column ko neeche se upar then 3rd column ko upar se neeche and so on...
// So what we will do is, we can see that jahaa pr column ka index odd hai vahaa pr hum top se bottom jaa rhe hai and even index ke liye hum bottom se top jaa rhe hai!
// So according to the above approach, what we will do is hum column ke naam se loop chalaa lenge and then usme jahaa pr column odd hoga vahaa top se bottom jayenge and jahaa even hoga vahaa bottom se top jayenge!
#include<iostream>
using namespace std;

void wavePrint(int arr[][4], int m, int n) {
    for(int col = 0; col<n; col++) {
        if(col&1) {
            // Odd Index -> bottom se top!
            for(int row = m-1; row>=0; row--) {
                cout<<arr[row][col]<<" ";
            }
        }
        else {
            // Even index -> top to bottom!
            for(int row = 0; row<m; row++) {
                cout<<arr[row][col]<<" ";
            }
        }
    }
}

int main() {
    int arr[3][4];
    for(int i = 0; i<3; i++) {
        for(int j = 0; j<4; j++) {
            cin>>arr[i][j];
        }
    }
    wavePrint(arr, 3, 4);
} // and hence the above code will print the 2D array in waveform!
// Time Complexity : Isme hum upar se neeche and neeche se upar jaa rhe hai, mtlb hum harr element ko ek baar traverse kr rhe hai! means total number of element jo humne traverse kiya that is n*m means, the time complexity will be O(nm)!

// Question : Spiral Print! Here hume saare elements circular order me print krne hai! like pehle poori row, then poora column, then again poori row in reverse order and so on... Question 54 at LeetCode!
// Approach : Hum pehle starting row print krenge then ending column print krenge then ending row print krenge then starting column print krenge!... jab bhi koi row ya column print hojaye then hum starting ya ending row ya column ko update krdenge! isme duplicates handle hojayenge!
#include<iostream>
#include<vector>
using namespace std;

vector<int> spiralOrder(vector<vector<int>>& matrix) {
    vector<int> ans;
    int row = matrix.size(); // It return row size!
    int col = matrix[0].size(); // it returns col size!

    int count = 0;
    int total = row*col;

    // index intiallization...
    int startingRow = 0;
    int startingCol = 0;
    int endingRow = row-1;
    int endingCol = col-1;

    while(count<total) {
        // printing starting row...
        for(int index = startingCol; count<total && index<=endingCol; index++) {
            ans.push_back(matrix[startingRow][index]);
            count++;
        }
        startingRow++;

        // printing ending column...
        for(int index = startingRow; count<total && index<=endingRow; index++) {
            ans.push_back(matrix[index][endingCol]);
            count++;
        }
        endingCol--;

        // printing ending row...
        for(int index = endingCol; count<total && index>=startingCol; index--) {
            ans.push_back(matrix[endingRow][index]);
            count++;
        }
        endingRow--;

        // printing starting row...
        for(int index = endingRow; count<total && index>=startingRow; index--) {
            ans.push_back(matrix[index][startingCol]);
            count++;
        }
        startingCol++;
    }
    return ans;
}

int main() {
    vector<vector<int>> arr1 = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    // To take input in vector, you can write like this... vector<vector<int>> arr(row, vector<int>(col));
    vector<int> spiral = spiralOrder(arr1);
    cout << "Spiral order of the matrix: ";
    for(int i = 0; i < spiral.size(); i++) {
        cout << spiral[i] << " ";
    }
    cout << endl;
} // Time Complexity will be O(n*m) and it can't be decreased further!

// Binary search in 2D arrays!
// Binary search in a 2D array is similar to binary search in a 1D array, with the key difference being how we calculate the mid element. 2D array structure: Even though it's a 2D matrix, it is stored linearly in memory (row-major order). If the array is sorted, we can apply binary search.
// Steps : Initialize start, end, and mid : start = 0, end = row * col - 1 (total number of elements - 1), mid = start + (end - start) / 2
//       : Accessing the mid element : To map the linear mid index back to a 2D matrix element, Row : "row = mid / number of columns" and Column : "col = mid % number of columns"!
//       : Binary search logic : If the mid element is equal to the target, return the mid.
//                             : If the mid element is greater than the target, search in the left half.
//                             : If the mid element is less than the target, search in the right half.
// Implementation!
#include<iostream>
#include<vector>
using namespace std;

bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int row = matrix.size();
    int col = matrix[0].size();

    int start = 0;
    int end = row*col - 1;
    int mid = start + (end-start)/2;

    while(start<=end) {
        int midElement = matrix[mid/col][mid%col];
        if(midElement == target) {
            return 1;
        }
        if(midElement > target) {
            end = mid-1;
        }
        else {
            start = mid+1;
        }
        mid = start + (end-start)/2;
    }
    return 0;
}

int main() {
    vector<vector<int>> arr1 = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    if(searchMatrix(arr1, 10)) {
        cout<<"Element present!";
    }
    else {
        cout<<"Element absent!";
    }
} // Time complexity : O(log(nm))


// ---------------------------------------------------------- LECTURE 24 - Maths for DSA --------------------------------------------------------------------------------------------------------->
// Prime Numbers : Normally what we used to do is if we get an input n and then hum 1 to n tak ke saare numbers se n ko divide krke check krte the agar kahin bhi output 0 aajaye then vo prime nhi hai otherwise vo prime hai! lets write a small code for it...
#include<iostream>
using namespace std;

bool isPrime(int n) {
    if(n<=1) {
        return false;
    }

    for(int i=2; i<n; i++) {
        if(n%i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int n;
    cin>>n;
    cout<<isPrime(n);
}

// Question : Count the number of primes! Leetcode question : 204
// Isme hum upar vaala approach use nhi kr sakte kyunki uski TC bhot khrab ajayegi, as becoz isme har n ke liye n number of comparisions kr rhe honge! hence iski TC n^2 ajayegi! which will be very bad! so isliye we need to use some other approach!
// And for that we will introduce another method which will be called "Sieve of Eratosthenes"!
// Method says : Start by assuming that all numbers up to n are prime. Then, iteratively mark multiples of each prime number as non-prime.
// Steps : Initialization : Assume all numbers from 2 to n are prime.
//       : Start from 2 : Mark multiples of 2 (i.e., 4, 6, 8, etc.) as non-prime.
//       : Move to next unmarked number (which is prime) : For example, 3 and mark its multiples (i.e., 6, 9, 12, etc.) as non-prime.
//       : Repeat for each successive number (5, 7, 11, etc.), marking all multiples as non-prime. Final Result: After processing all numbers, the remaining unmarked numbers are primes.
// Benefits : Efficiency : Instead of checking each number individually, we mark the multiples of primes as non-prime, which reduces the number of comparisons and results in a time complexity of O(n log log n), much better than a brute force approach.
// lets code it!
#include<iostream>
#include<vector>
using namespace std;

int countPrime(int n) {
    int count = 0;
    vector<bool> prime(n+1, true);
    prime[0] = prime[1] = false;
    for(int i = 2; i<=n; i++) {
        if(prime[i]) {
            count++;
            for(int j = 2*i; j<=n; j=j+i) {
                prime[j] = 0;
            }
        }
    }
    return count;
}

int main() {
    int n;
    cin>>n;
    cout<<countPrime(n);
}
// Time Complexity : Isme humne harr iteration pr n/i number of comparisons kiye hai, like pehle n/2 then n/3 then n/5 and so on...
// So on adding all of them by taking n common... n(1/2 + 1/3 + 1/5 + 1/7 + ....) it will give... n*(log(logn))...
// So our time complexity will be "O(n*log(log(n)))"

// Modulo Arithematic!
// 1) (a+b)%m = a%m + b%m
// 2) a%m - b%m = (a-b)%m
// 3) a%m * b%m = (a*b)%m

// Fast Exponentiation!
// Fast Exponentiation is a method to calculate powers of a number efficiently, significantly reducing the time complexity compared to the straightforward approach of multiplying the base repeatedly.
// Normal Approach : To calculate a^b we multiply a by itself b times, a^b = a*a*a*a*a.... b times! and which creates the TC = O(b)
// Fast Exponentiation : The idea is to reduce the number of multiplications by breaking the problem into smaller parts using the properties of exponents. This can achieve a time complexity of O(logb).

// How does Fast Exponentiation work?
// The core idea behind fast exponentiation is to break down the power problem into smaller sub-problems and take advantage of properties of exponents.
// Key Property of Exponents : a^2n = (a^n)2, If the exponent is even, we square the result of the smaller exponent
//                           : a^2n+! = (a^2n)*a, If the exponent is odd, we square the result of the smaller exponent and multiply it by the base

// Algorithm : Start with an initial result res = 1.
//           : While the exponent b>0 : If b is even, square the base a and halve b
//                                    : If b is odd, multiple the result by a, then square the base a and halve b
//           : return the result!

// The most basic Fast Exponentiation!
#include<iostream>
using namespace std;

int moduloExponentiation(int x, int n) {
    int res = 1;
    while(n>0) {
        if(n&1) {
            res = res * x;
        }
        x = x*x;
        n = n>>1;
    }
    return res;
}

int main() {
    int x1,n1;
    cin>>x1>>n1;
    cout<<moduloExponentiation(x1,n1);
}
// This is a form of fast exponentiation, but it's not the most optimal version. Let's break down the key points and how you could optimize it further.
// The function moduloExponentiation(int x, int n) implements exponentiation by squaring, which is a technique to calculate x^n more efficiently than performing n multiplications!
// In the loop : If n is odd (n & 1), we multiply the current result res by x.
//             : Then we square x and halve n by right shifting it (n = n >> 1).
// What's Missing? Your code calculates x^n, but there's no modulo operation in your current code. In many situations, especially for large numbers, you would need to compute the result modulo a number m to prevent overflow and keep the result manageable.
// Key Optimization : In modular arithmetic, especially with large numbers, it’s common to compute x^n mod m (instead just x^n)
//                  : The reason for using modulo at each step is to keep the result within the bounds of the modulo which is 1->m-1 and avoid overflow. Without modulo, your results could become too large.
//                  : Avoiding overflow : To handle large values properly, you'd usually use the long long data type to avoid overflow, especially when dealing with numbers as large as 10^n or more!
//                  : Efficiency : The current code does exponentiation by squaring, which is already logarithmic in time complexity (that is : O(logn)). which is a great improvement over the naive O(n) approach.

// Modulo operation (% m) : We now take the result modulo m at every step to prevent overflow and ensure that the values are kept within manageable limits.
//                        : 1LL (long long) : This ensures that the intermediate multiplication does not overflow 32-bit integers.
// The logic in the code is correct for fast exponentiation (exponentiation by squaring), but adding the modulo operation is important for handling large numbers.

// Optimized solution! and along with a question!
// Question : Find the value of (x^n)%m isme hume x,n,m diya hua hai...here agar humne pehle vaali appproach follow kri toh TC kaafi badh jayega, so here we will use Fast Exponentiation! as becoz isme humari TC O(logn) ayegi!
#include<iostream>
using namespace std;

int moduloExponentiation(int x, int n, int m) {
    int res = 1;
    while (n > 0) {
        if (n & 1) {
            res = (1LL * res * x) % m;  // Multiply and take modulo
        }
        x = (1LL * x * x) % m;  // Square the base and take modulo
        n = n >> 1;  // Divide exponent by 2
    }
    return res;
}

int main() {
    int x1, n1, m1;
    cin >> x1 >> n1 >> m1;
    cout << moduloExponentiation(x1, n1, m1);
}

// ---------------------------------------------------------- LECTURE 25 - Pointers in C++ Part-1 --------------------------------------------------------------------------------------------------------->
// Basic logic of pointers you already know very well, if confused maybe see the vdos again or refer the C notes!
#include<iostream>
using namespace std;

int main() {
    int a = 5;
    int *ptr = &a; // yahaa humne a variable ka address store kiya jisme 5 rakhaa hua hai
    cout<<*ptr<<endl; // Yahaa humne * ko use kiya dereference krne ke liye, and upar kiya tha reference krne ke liye (pointer declare krne ke liye)
    // Never write like this int *ptr; kyunki isme humne iss pointer ko kahin point nhi kiya, ab ye memory ke kisi bhi jagah point kr rha ho sakta hai, agar kahin reference nhi krna hai toh usko 0 se initialize krdo and make it a NULL pointer! but dont leave it like this! Its a very bad practice!
}

// Jiss type ka memory space refer krana hai uss type ka hi pointer bhi banega! agar aise kisi variable ko point kraa rhe ho jo ek char type ka hai toh pointer bhi char type ka banega!
#include<iostream>
using namespace std;

int main() {
    int a = 5;
    int *ptr = &a;
    cout<<"Size of integer : "<<sizeof(a)<<endl; // Here it will be 4 bytes, as usual!
    cout<<"Size of pointer : "<<sizeof(ptr)<<endl; // Here it will give 8 becoz chaahe kisi bhi data type ka pointer ho store toh vo address hi krega and address will be a hexadecimal number due to which it will always be of 8 bytes! but the problem is ki yahaa pr jo compiler I'm using is of 32 bits and that is why it will still show 4 bytes! and that is why the output will be 4 bytes!

    int *ptr2 = 0;
    // int *ptr2 = NULL;
    cout<<*ptr2<<endl; // It will give output as "Segmentation Fault" kyunki yahaa pr hum ek NULL pointer ki value nikalne ka try kr rhe hai! or maybe not always sometimes it shows a very undefined behaviour or the program may crash! also maybe it can show no visible effect or any other unexpected behaviour! but it is not neccessary that it will always lead to segmentation fault!
} // This is it for this lecture, most of the topics and logic are already covered in C lectures notes or you may again visit the lecture here!

// ---------------------------------------------------------- LECTURE 26 - Pointers in C++ Part-2 --------------------------------------------------------------------------------------------------------->
// Suppose we have created an array int arr[10]; and now in memory there will be 10 int size memory blocks will form and the array name here it is arr will be pointing towards the first memory block of the array!
#include<iostream>
using namespace std;

int main() {
    int arr[10] = {1,2,3,4,5,6,7,8,9,10};
    cout<<"Address of first memory block is : "<<arr<<endl;
}

// using & operator : agar hum chahte hai & operator ka use krke first location ka address nikalna hai then we can do this... &arr[0] it will mean address of first location of the array arr.
#include<iostream>
using namespace std;

int main() {
    int arr[10] = {10,20,30,40,50,60,70,80,90,100};
    cout<<"Address of first memory block is : "<<arr<<endl;
    cout<<"Address of first memory block is : "<<&arr[0]<<endl;

    int *ptr = &arr[0];
    cout<<"Address of first memory block is : "<<ptr<<endl;
    cout<<"Value at first index of the array : "<<*arr<<endl; // It will print the value at the first index of the array arr!
    cout<<*arr + 1<<endl; // It will add 1 to the value in *arr, hence it will print 11 here!
    cout<<*(arr+1)<<endl; // it will print the value at second index of the array!
} // So this is another way of finding the address of firs location of array arr... thru three methods!

// How actually compiler evaluate arr[i] : So, arr[i] = *(arr + i), and that is how it is actually evaluated!
// even we can write the above arr[i] = *(arr + i) or i[arr] = *(i + arr)!
#include<iostream>
using namespace std;

int main() {
    int arr[10] = {10,20,30};
    cout<<arr[2]<<endl;
    cout<<*(arr + 2)<<endl;
    cout<<2[arr]<<endl;
    cout<<*(2 + arr)<<endl;
    // All the above will give the same answer!
}

#include<iostream>
using namespace std;

int main() {
    int temp[10] = {1,2,3,4};
    cout<<sizeof(temp)<<endl; // Isme bhale hi temp first location ka address batata ho but here hum size nikal rhe hai naa ki address toh it will print 40 as 40 is the entire size of the array!
    cout<<(*temp)<<endl; // It will print the value which is present at the first location of the array temp!
    cout<<(&temp)<<endl;
    cout<<sizeof(*temp)<<endl;
    cout<<sizeof(&temp)<<endl;
    cout<<&temp[0]<<endl; // it will print the address of the first location of the array!
}

#include<iostream>
using namespace std;

int main() {
    int a[10] = {1,2,3,4,5};
    cout<<&a[0]<<endl;
    cout<<&a<<endl;
    cout<<a<<endl;
    // All the above will print the exact same output!

    int *p = &a[0];
    cout<<p<<endl;
    cout<<*p<<endl;
    cout<<&p<<endl; // It will print the address of the block which is storing the address of the first location of the array!
}
// Note : Content of symbol table cannot be changed!
// Symbol table : Jaise jo humne array banai thi uske first location ka address uske naam se represent hota hai and vo naam kisi ek memory address se map hoga and hum uss address ko change nhi kr sakte hai! this is what we mean by saying symbol table content cannot be changed!
// Means we cannot do arr = arr+1;
#include<iostream>
using namespace std;

int main() {
    int arr[10];
    // arr = arr + 1; // This will show error as it cannot be done!
    cout<<arr<<endl;

    // Meanwhile this wont show error, this is all becoz of the C++ implementation of array name and a regular pointer is different! pointers are made to move, whereas the array name is made a constant pointer at the first element! that is why it cannot be changed!
    int a = 6;
    int* ptr = &a;
    ptr = ptr+1;
    // You can also achieve that, by using the const keyword on regular pointers!
}

// Character Arrays!
#include<iostream>
using namespace std;

int main() {
    int arr[5] =  {1,2,3,4,5};
    char ch[6] = "abcde"; // Here hume iska size 6 krna hoga, kyunki character arrays me ek last me null character hota hai and uske liye bhi space chahiye hoti hai! so that is why we have made it 6!
    cout<<arr<<endl; // Isme toh as we know ki address of the first location of the array print hojayega!
    cout<<ch<<endl; // Isme hum expect krenge ki first location of the char array ka address print ho pr vo nhi hoga, balki vo char array as it is print hojayega!
    
    char ch1[6] = {'a','b','c','d','e','\0'};
    cout<<ch1<<endl; // Here, we have made the ch1 a string using a \0, so now printing it will print all the characters in th string until it encounters \0. 

    char ch2[5] = {'a','b','c','d','e'};
    cout<<ch2<<endl; // Here, it is a normal character array! but even then just using the variable name of the character array it is printing all the characters, but apart from that it exceeds and continues printing some garbage values after "abcde" until it encounters a \0!
    // This all is becoz of the cout's implementation in C++ for character arrays and strings!
 
    // Even if agar hum ye tareeka soche address of the first location of the char array print krne ka tab bhi kuch nhi hoga! kyunki C++ me cout ki implementation hi different hai!
    char *c = &ch[0];
    cout<<c<<endl; // Iss case me bhi ye poora string hi print krdega, kyunki c++ me cout ka implementation hi different way se hai! yahaa pr jab bhi cout ko null character dikh jayega tab hi ye print krna band krdega!
    // Lets see kya hota hai agar isko null character nhi milta toh!
    char temp = 'a';
    char *p = &temp;
    cout<<p<<endl; // Iss case me ye iss time abcde print kr rha hai jisme se "bcde" are some random garbage values! aur aisa isliye hua kyunki isko a ke baad null character seedha bcde ke baad mila!
    // Iss case me ye "p" ye weird behaviour isliye dikha rha hai kyunki ye ek char type ka pointer hai! agar int type ka hota toh simply address print hojata! but yahaa kyunki ye ek char type ka pointer hai isliye yahaa ye NULL character dhundega and jab tak nhi milta tab tak print krta rahega!
}
// Now lets see the difference between, char ch[6] = "abcde"; and char *c = "abcde";
// In the first case kya hoga ki pehle ek temporary memory banegi usme abcde jaake store hoga with null character in the end! and then ek ch naam se memory create hogi and vahaa pr ye temp vaali memory copy hojayegi!
// And in the second case ye ho rha hai ki ek temporary memory ban rhi hai and then us naam se jo pointer hai vo uss temporary memory ke first element ko point kr de rha hai (mtlb uska address store krde rha hai)! but this process is very risky!

// Functions using Pointers!
#include<iostream>
using namespace std;

void print(int *p) {
    cout<<p<<endl;
}

void update(int *p) {
    p = p+1;
}

int main() {
    int value = 5;
    int *p = &value;
    print(p);

    cout<<"Before : "<<p<<endl;
    update(p);
    cout<<"After : "<<p<<endl; // Here we can see even after using the update function we are not able to update the value of the p!
} // So what happened is ki isme pass by value hoti hai! mtlb jo function me pass krte hai value hum int main ke andar uss value ki ek copy jaati hai function defintion ke andar and then vo value sirf uss scope ke andar me update hoti hai! toh agar hum uss scope ke andar me print karayenge value tab value update hojayegi!
// Pr agar hum iss hi function me *p ko update krne ki koshish kre tab easily hojayegi!
#include<iostream>
using namespace std;

void update(int *p) {
    *p = *p+1;
}

int main() {
    int value = 5;
    int *p = &value;
    // print(p);

    cout<<"Before : "<<*p<<endl;
    update(p);
    cout<<"After : "<<*p<<endl;
} // Is case me value update hogyi! aisa isliye kyunki jab pehle humne *p print kiya toh jo uss time value thi *p vo print hogyi! but iss baar jab humne update function call maara tab seedha jaake p pe jo address stored hai uspe jo value hai vhi change hogyi! and in this case vo value hi from the root update hogyi and that is why After me updated value print hui!

// Pointers with arrays and functions!
#include<iostream>
using namespace std;

int getSum(int arr[], int n) { // Isme hum int arr[] ko "int *arr" bhi likh sakte hai! baat ek hi hai!
    int sum = 0;
    for(int i = 0; i<n; i++) {
        sum += arr[i];
    }
    return sum;
}

int main() {
    int arr[5] = {1,2,3,4,5};
    cout<<"Sum is : "<<getSum(arr,5)<<endl; // Isme hum poori array nhi paas kr rhe hai balki array ka sirf first location ka address pass kr rhe hai!
} // Lets understand the code in more depth! jab hum int *p naam se ek pointer create krte hai tab ek pointer create hota hai jo array ke first element pr point kr rha hota hai! and then uske baad se poora array continue ho rha hota hai!
// Jab humne arr pass kiya function call me tab vo array ki first location ko represent kr rha tha but like agar hum chahte hai ki array ki kuch ek particular location se hi element pass kre toh hum aise likh sakte hai...getSum(arr+3, 5) isse kya hoga ki array ki 3rd location se saare elements pass hojayenge array function me! and them hum apne hisaab se specific set of index ki values ka sum nikal sakte hai!
// lets try this....

#include<iostream>
using namespace std;

int getSum(int *arr, int n) {
    int sum = 0;
    for(int i = 0; i<n; i++) {
        sum += arr[i];
    }
    return sum;
}

int main() {
    int arr[5] = {1,2,3,4,5};
    cout<<"Sum is : "<<getSum(arr+2,3)<<endl; // Is case me humne jo array ki index badhane ke baad jo nayi size aayi hai vo bhi likhna hota hai!
} // So we are done here right now!

// Adding two pointers does not make sense! hence it is invalid!
// But subtracting two pointers is valid and it makes sense! like suppose we subtract ptr1 which points to 0th index of an array! and ptr2 which points at the 4th index of the array! then if we subtract ptr2-ptr1 we will get the difference between the two blocks of the array! and isse hume 0th index se 4th index ke beech me kitne blocks hai vo ptaa chal jayega! that is why subtracting makes sense but adding will not kyunki uska output meaning less hai!
// But while doing subtraction, acha rahega agar hum "ptrdiff_t" datatype use kre subraction ke outcome ko store krne ke liye! rather than normal int datatype!
// Means, int diff = ptr2-ptr1; -> isme koi dikkat nhi hai but ye utna safe nhi hota hai!
// but, ptrdiff_t = ptr2-ptr1; -> It is not strictly required, but it is recommended for pointer subtraction to ensure portability, readability, and correctness. "ptrdiff_t" is guaranteed to be large enough to hold the difference between any two pointers to elements of the same array. Including <stddef.h> and using ptrdiff_t in your pointer arithmetic is a good practice for writing reliable and maintainable C code.
// vaise pointer subtraction hum aise bhi do values ka kr sakte hai jo array me na ho! but ofc it will make sense agar dono pointer ek same array ke hi different blocks ko point kr rhe ho! ye zyada make sense krega!

// NULL Pointer : A pointer that is not assigned any value but NULL is known as NULL pointer! It is a pointer that does not point to any value or object or function!
//              : We can use it to initiallize the pointer variable when that pointer variable isn't assigned valid memory address yet! int* ptr = NULL;

// In pointers, %x is used to print the hexadecimal!

// ---------------------------------------------------------- LECTURE 27 - Double Pointers in C++ --------------------------------------------------------------------------------------------------------->
// lets see why we did'nt use the pointer keywords in C++ and why use * along with the type of pointer we want to create!
// Reason is ki agar hum data types ko use krke define krenge pointer toh isse 2 cheez pehle se hi confirm hojayegi ki jo pointer hai vo kis type ka data type store krne vaala hai! and another is ki kitne bytes ke memory location ko vo pointer point krne vaala hai!

// And double pointers are nothing but just that they points towards another pointers! and similarly triple pointers are just another pointers which are pointing towards the double pointer and this things goes on....
#include<iostream>
using namespace std;

int main() {
    int i = 5;
    int* p1 = &i;
    int** p2 = &p1;
    // int*** p3 = &p2;
    // int**** p4 = &p3;
    // int***** p5 = &p4; // All these things are also valid, but it all depends on use cases, jo abhi toh koi use nhi hai iska!

    cout<<"Value in i : "<<i<<endl;
    cout<<"Address of i : "<<&i<<endl; // this will print the address of i
    cout<<"Value in p1 : "<<p1<<endl; // this will print the address of i
    cout<<"Address of p1 : "<<&p1<<endl; // this will print the address of p1
    cout<<"Value at address store in p1 : "<<*p1<<endl; // this will print the value at that memory block whose address is stored in the pointer p1, in this case it is i's address stored in p1 so it will print the value which is stored in i which is 5!
    cout<<"Value in p2 : "<<p2<<endl; // this will print the address of p1 as it is the double pointer which is pointing towards another pointer p1
    cout<<"Address of p2 : "<<&p2<<endl; // this will print the address of p2
    cout<<"Value at address stored in p2 : "<<*p2<<endl; // this will print the value of that memory address whose address is stored in the pointer p2, in this case it is p1's address stored in p2 so it will print the value which is stored in p1 which is the address of i!

    cout<<"Value in i : "<<**p2<<endl; // Printing the value of i directly from p2!
}

#include<iostream>
using namespace std;

void update(int **p) {
    // p = p+1;
    // Will it change anything? Nothing changed! reason we already discussed above! kyunki overall isme pass by value hota hai toh values copy krke aati hai function me!

    *p = *p + 1;
    // Will it change anything? yes!

    // **p = **p + 1;
    // Will it change anything? yess!
}

int main() {
    int i = 5;
    int *p1 = &i;
    int **p2 = &p1;

    cout<<"Before : "<<i<<endl;
    cout<<"Before : "<<p1<<endl;
    cout<<"Before : "<<p2<<endl;
    update(p2);
    cout<<"After : "<<i<<endl;
    cout<<"After : "<<&i<<endl;
    cout<<"After : "<<p1<<endl;
    cout<<"After : "<<p2<<endl;
}
// Lets understand what we just did above! so pehle humne 3 memory blocks banai jisme se ek normal variable hai aur do pointers hai ek single pointer and double pointer!
// Now we created a function jisme hum double pointers ki value function call ke thru pass kr sakte hai! and humne uss function ke andar 3 alag alag increament operations likhe hue hai jinko hum ek ek krke check krenge ki kis operation se koi fark padta hai ya nhi!
// Now first lets create 3 blocks... i = 5 and address is 510, p1 = 510 and address is 610, p2 = 610 and address is 710!
// Now in the first case... hum is function me sirf double pointer hi pass kr sakte hai kyunki humne iski declaration hi aise ki hai! so humne int main ke function call me p2 ko pass krdiya and now update function me ek alag se p2 memory block ban jayega jisme store toh 610 hi hoga but iss p2 block ka address kuch aur hoga kyunki ye toh int main vaale p2 ki ek copy hai! and now humne try kiya p = p+1 mtlb ki p2 me jo value hai usko increment krne ki, so p2 ki value increment hoke 610 se 614 hojayegi (kyunki integer ke size ke hisaab se addition hota hai), but ye increment sirf update function ke andar me hi hua hai iska int main se koi link nhi isliye update krne ke baad bhi after vaale couts ki value me koi change nhi ayega!
// Now in the 2nd case... this time we will check whether *p = *p + 1 works or not, so int main ke p2 ki ek copy pehle toh ban gyi update function me jiska address kuch aur hoga, so update function has p2 = 610 and address some other lets suppose 810, so now this time operation is *p = *p+1, so it means p2 block me jo value padi hai uss address pr jo value hai usko increment krdo by 1, so p2 me toh address p1 ka padaa hua hai, and vahaa pr jo value hai vo toh i ka address hai toh iss function ke according p1 me jo value hai uska increment hona hai! toh vo jayega means 510+1 which will be 514, and iss time kya alag hua ki iss update function ne iss baar int main ke p1 ki values me changes krdiye so this time the changes will reflect in not only in update function but also in int main! and hence in this case i ki value and uska address same rahega, p1 ki change hojayegi and p2 ki same rahegi! bss p1 jahaa pehle point kr rha tha usse ek block aage point kr rha hai ab!
// Now in the 3rd case... this time we will check whether **p = **p + 1 works or not, so int main ke p2 ki again ek copy banegi and all, let this copy be as p2 = 610 and its address is 810, now the operation suggests **p = **p + 1, so now p2 me jo address stored hai uss address pr jo address stored hai uski values me changes krne hai, mtlb simply i ki value me changes krne hai! so yahaa again update function apne scope ke bahar ke ek variable me changes kr rha hai toh ye changes iske scope ke bahar bhi reflect honge! and i ki value +1 hojayegi! and this time p1 and p1 same rahenge bss i change hojayega!

// Practice Question on Pointers!
#include<iostream>
using namespace std;

int main() {
    int first = 6;
    int *p = &first;
    int *q = p; // aise pointers copy krte hai! p and q are pointing at the same memory location!
    (*q)++;
    cout<<first<<endl;

    cout<<endl;

    // int *p1 = 0; // NULL Pointer!
    // int first1 = 110;
    // *p1 = first1; // this is wrong, it will generate segmentation fault hence the correct syntax to do this will be p = &first, agar null pointer ko baad me update krke kisi aur jagah point karana hai toh vo aise krte hai! p = &first.. yahaa p ek NULL pointer tha!
    // cout<<*p1<<endl;

    cout<<endl;

    int arr1[5] = {11,12,13,14,15};
    cout<<*(arr1)<<" "<<*(arr1+1)<<endl; // Will print 11 and then 12
    
    cout<<endl;

    int arr2[5] = {11,12,13,14,15};
    cout<<arr2<<" "<<&(arr2)<<endl; // Same address do baar print hojayega!
    
    cout<<endl;

    // int arr3[5] = {11,12,13,14,15};
    // // int *ptr3 = arr++; // Here it will throw error kyunki here we are trying to update the symbol table!
    // cout<<*ptr3<<endl;
    
    cout<<endl;

    char arr4[] = "abcde"; // C/C++ me string ke case me compiler khud hi char array ka size samajh leta hai null character ki help se! aur yahaa humne double quotes use kiya hai jo strings ki notation hoti hai toh automatically ek null character last me lag jaata hai jahaa se size calculate hojaata hai!
    char* p3 = &arr4[0];
    cout<<(void*)arr4<<endl; // If you want to print the address of the first element or any element of the character array or string in C/C++ then just use this (void*)!
    cout<<p3<<endl; // Here we know char arrays ke case me cout behaves differently so yahaa poori string print hojayegi!
    
    cout<<endl;

    char arr5[] = "abcde";
    char* p4 = &arr5[0];
    p4++;
    cout<<p4<<endl; // Isme bcde print hojayega kyunki first index se humne increment krdiya hai!
}

// Hence, Note : By default, cout prints character arrays as strings. If you directly pass a character array or string literal to cout, it will print the contents of the array rather than its address.
//             : To explicitly print the address, we need to cast the pointer to void*. This tells cout that we want to print the memory location (pointer) instead of the string contents.
//             : Ofcourse there are ways like, using &ch[0] and all... but yes (void*) is overall solution to it!

// ---------------------------------------------------------- LECTURE 28 - Reference Variable and Static vs Dynamic Memory --------------------------------------------------------------------------------------------------------->
// Similar to that we have different names for a same person!
// Reference variable are those jab hum ek hi memory location ko do ya usse zyada alag alag names se bulate hai, like agar ek memory location ya block ko i se bulaya jaa rha hai and uss same ko hi hum j se bhi bula rhe hai then j is the reference variable!
// Reference variable is created like this...
#include<iostream>
using namespace std;

int main() {
    int i = 5;
    int &j = i; // This is how we create a reference variable! so yahaa pr do different names hai same memory block ke, i and j!
    cout<<i<<endl;
    i++;
    cout<<i<<endl;
    j++;
    cout<<j<<endl;
}

// Why we need it...remember we have studied about the pass by value and all...vahaa copy ban rhi thi jo variable pass ho rha tha function call me so we will create reference variable so that vo copy na bane and jo jisme change krna chahte hai changes uss hi me changes hojaye! which is called pass by reference!
#include<iostream>
using namespace std;

void update(int n) { // Here it is pass by value so yahaa ek copy ban jayegi!
    n++;
}

void update2(int &n) { // Here it is pass by reference so yahaa copy nhi banegi and changes original variable me hi honge!
    n++;
}

int main() {
    int n = 5;
    cout<<"After : "<<n<<endl;
    update(n);
    cout<<"Before : "<<n<<endl; // Iss case me koi changes nhi ayega! kyunki this is pass by value!

    cout<<"After : "<<n<<endl;
    update2(n);
    cout<<"Before : "<<n<<endl;
} // So isme kya hua ki jo variable humne function call me pass kiya vo ek reference ki tarah pass hua function defintion ke kaaran! isse what actually happened is &n uss hi variable ko refer kr rha hai jo function call me pass hua hai isse jo changes honge vo uss original vaale me hi hojayenge!

// What if we want to return a reference variable from a function? is it right thing to do? lets see...
#include<iostream>
using namespace std;

int& func1(int n) {
    int num = n;
    int& ref = num;
    ref++;
    return ref;
} // Doing this does not make sense! kyunki dekha jaaye toh humne ek function ke scope me hi ek variable create kiya num and then uska hi ek reference variable create kiya so uss ref variable ka bhi scope function ke scope tak hi hai! so isko return kraane ka koi sense nhi hai kyunki ye dono hi variables are local variables so inn dono ka existence iss scope tak hi hai uske baad they will be dead, so what are we returning? thats why this is not right to do!
// Also kyunki ek baar vo function end hua toh vo saare local variables and jo function ka stack frame tha execution ka vo vo sab destroy ho jayega, toh means function ke baad kisi bhi local cheez ka koi existence nhi goa, toh what are we returning? that is why it does not make sense! and here this reference variable has a name called "dangling reference variable"!
// If you really want to return a reference variable, then firstly the the variable which you are refering to, should be "static" as because static variable dont vanish even when the function exits!

int* func2(int n) {
    int* ptr = &n;
    return ptr;
} // Doing this is also wrong coz of the same reason! ki iska scope is function ke scope tak hi valid hai toh return kya kr rhe hai!

int main() {
    int n = 5;
    cout<<func1(n)<<endl;
} // So overall doing this is not good!

// Now lets talk about arrays!
// Remember? writing this throws errors, int n; cin>>n; int arr[n]; isme hum chah rhe hai ki program ke runtime me array ko uska size allocate ho! and ye nhi hota hai! aisa kyu? becoz see..
// There are two types of memory while compile time, one is stack and another is heap! stack is that memory jo compiler allocate krta hai ek program ko and heap is large memory which is allocated to that program but stack is small! so maanlo agar humne ye code likh ke execute krdiya and size of array pehle specify nhi kiya toh pehle toh compiler ek stack and ek heap memory program ko allocate krdega apne hisaab se but agar runtime me humne jo size of array daala vo size of stack allocate to the array during the compile time se zyada hogya toh? in that case program will crash and that is why doing this is BAD practice!
// Isliye agar size ptaa na ho toh pehle se hi array ka size badaa leke chalo... but ye vaala kaam mtt kro!

// So can't we create variable size array? yes we can...
// So agar hume ye krna hai toh pehle toh stack ki memory toh static rahegi, toh dynamic memory allocate krne ke liye ki like runtime pr hum btaa sake ki hume kitni memory chahiye for that we will use that Heap memory! and for that we have to use the "new" keyword!
// so we will write "new char;" isse heap me ek char type ki memory allocate hojayegi bss uska koi naam nhi hoga, name and all ye sab stack memory me hota hai heap me nhi! and ye "new char;" keyword ek address return krega! jisko hum use krenge uss heap memory ko access krne ke liye!
// so we will write "char* ch = new char;" isse ye hua ki jo memory heap me create hui thi uska address humne ek pointer ki help se store krliya in the stack memory! and now we can access it! toh stack me ek pointer hai ch naam se jo heap ki ek memory ko point kr rha hai!

// Creating a dynamic array using heap and dynamic memory allocation! so we will write...
#include<iostream>
using namespace std;

int getSum(int *arr, int n) { // int arr[] bhi likh sakte hai int *arr ki jagah... but lets play with pointer which is more dynamic!
    int sum = 0;
    for(int i = 0; i<n; i++) {
        sum += arr[i];
    }
    return sum;
}

int main() {
    // int *arr = new int[5]; // Isme int *arr se stack me ek pointer create hua jo heap me 5 size ke array ke first index ko point kr rha hai!
    // Now our main aim was to create a dynamic size ka array, mtlb runtime pr hum array ka size daale and runtime pr define ho ki array ka size kya hoga!
    int n;
    cin>>n;
    int *arr = new int[n]; // this makes total sense as, stack ki memory to limited hai isliye hum variable size stack ke case me daal nhi paa rhe the but ab new keyword se jo heap me memory allocate ho rhi hai vo toh badi hai kaafi toh vahaa toh hum variable size daal sakte hai kyunki yahaa pr enough space hai!
    for(int i = 0; i<n; i++) {
        cin>>arr[i];
    }
    cout<<"Sum of elements of the array : "<<getSum(arr, n); // Another variation if we want, we can also try (arr+2, n-2) isse hum jo bhi array input krenge jitne bhi size ka uske 2nd index se sum hona shuru hoga naa ki first index se and similarly we can do more things!
    
    delete[] arr; // Dont forget to also free the used memory after program execution!
} // So this is how we have allocated dynamic memory!
// lets calculate memory kitni jaa rhi hai static and dynamic me! agar hum normally aise likhte int arr[50]; isme 50*4 = 200 bytes of memory use ho rhi thi... agar hum iss hi ko dynamically kre toh int *arr = new int[50]; isme 50*4 + 4 (My compiler is of 32 bits isliye size of pointer is 4 bytes otherwise it can also be 8 bytes!) = 204 bytes are being used! here it is more than the static memory!

// Lets see some interesting stuff!
#include<iostream>
using namespace std;

int main() {
    while(true) {
        int i = 5;
    } // Isme kya ho rha hai ki stack me baar baar i naam se ek memory create hote jaa rhi hai but jaise hi scope khatam ho rha hai vaise hi vo khud hi delete bhi ho jaa rhi hai! toh means harr ek instant of time me ek hi i variable hai stack me!

    while(true) {
        int *p = new int;
    } // In this case ek pointer create ho rha hai p naam se stack me and heap me int size ki ek memory allocate ho rhi hai, but jab scope end ho rha hai toh stack vaali memory toh khud delete ho jaa rhi hai but heap vaali aise hi khud delete nhi hoti! toh harr baar heap me memory bharte jaa rhi hai int size ki and ek time ke baad heap full hojayega and program crash kr jayega!
    // Static aur Dynamic me yhi antar hai ek toh ki static me khud hi memory use hone ke baad delete ho jaati hai pr Dynamic me aise nhi hoti! to delete that memory we use "delete" keyword!
}

#include<iostream>
using namespace std;

int main() {
    int *i = new int; // dynamically allocated memory for i
    delete i; // we will write this to delete i from heap as well!

    int *p = new int[50];
    delete []p; // we will write this to delete the array from the heap!
}

// Void Pointers : Void pointers, also known as generic pointers, are pointers that point to data of unspecified type! declared as void *ptr;
int main() {
    int num = 10;
    float fnum = 3.14;

    void *ptr;

    // Assigning an int type memory to a void pointer
    ptr = &num;
    // Dereferencing a void pointer after casting it to an int pointer
    printf("Value of num: %d\n", *((int*)ptr));

    // Assigning a float type memory to a void pointer
    ptr = &fnum;
    // Dereferencing a void pointer after casting it to a float pointer
    printf("Value of fnum: %f\n", *((float*)ptr));

    return 0;
}
// You can assign any type of pointer to a void pointer without explicit casting, but you need to cast it back to its original type before dereferencing it.

// ---------------------------------------------------------- LECTURE 29 - Dynamic Memory Allocation in 2D arrays! --------------------------------------------------------------------------------------------------------->
// 1D array ko dynamically kaise banaate the that you get it! so in case of 2D arrays we need to think like this...
// 1D ke liye we use to write, int *arr = new int[5]; here humne 1D array ke liye multiple int blocks banaye heap me! and sabse pehle int block ka address humne store krdiya arr pointer me jo stack me hai!
// So for this case, we will do this... int **arr = new int*[n]; isme what we did is ki humne jaise pehle 1D array banane ke liye multiple int blocks banaye the heap me vaise hi 2D array banane ke liye humne pehle multiple n arrays ke rows banaa liye heap me and then we will create columns for each row of arrays, like...
// for(int i = 0; i<n; i++) {
//     arr[i] = new int[n];
// }

// int **arr = new int*[n]; Lets understand the main function...
// int **arr : Declares a pointer to a pointer to an integer. This means arr will point to a memory location that stores the address of another memory location, which in turn stores integers.
// new int*[n]; : Dynamically allocates an array of pointers to integers. Here, n specifies the number of pointers in the array. Each element of this array will hold the address of a dynamically allocated array of integers.
// After this statement, arr points to the first element of the array of pointers, which are not yet initialized.
// and then vo loop vaala kaam!
// lets try this once...
#include<iostream>
using namespace std;

int main() {
    int n;
    cin>>n;
    int **arr = new int*[n]; // yahaa humne stack me arr naam se pointer banaya, jo heap me jo array of arrays bnaa hai uske sabse first array sabse first pointer (jo sabse first array ke 0th index element ko point kr rha hoga) ko point krega ye arr! 
    for(int i = 0; i<n; i++) { // Yahaa pr humne vo saare array of arrays initialize kiye hai heap me!
        arr[i] = new int[n];
    } // 2D array creation done! so its like "Stack [ arrPtr-]"----"Heap--[->arr1, arr2, arr3, arr4, arr5......]" 

    // taking input into the 2D array!
    for(int i = 0; i<n; i++) {
        for(int j = 0; j<n; j++) {
            cin>>arr[i][j];
        }
    }

    // priting output
    for(int i = 0; i<n; i++) {
        for(int j = 0; j<n; j++) {
            cout<<arr[i][j];
        }
        cout<<endl;
    }
} // That is how 2D array is created using dynamic memory allocation and printing it! for same number of rows and columns
// lets do it once also for different row and column size!
#include<iostream>
using namespace std;

int main() {
    int r;
    cin>>r;

    int c;
    cin>>c;
    int **arr = new int*[r];
    for(int i = 0; i<r; i++) {
        arr[i] = new int[c];
    } // 2D array creation done!

    // taking input into the 2D array!
    for(int i = 0; i<r; i++) {
        for(int j = 0; j<c; j++) {
            cin>>arr[i][j];
        }
    }

    // priting output
    for(int i = 0; i<r; i++) {
        for(int j = 0; j<c; j++) {
            cout<<arr[i][j];
        }
        cout<<endl;
    }
} // that is how 2D array is created using dynamic memory allocation and printing it! for different number of rows and columns!
// And jab bhi hum heap me memory create krte hai toh we should keep in mind ki we should also delete it after it is used!

// 2D array dynamic visuallization : isme kya hua hai ki heap me pehle toh n pointer bane hai and unn n pointers ke corresponding arrays create ho rakhi hai!
// so agar hum pehle unn pointers ko delete krdenge toh heap me jo create ho rakhi arrays hai vo toh reh jayengi! so pehle we will delete the arrays and then the pointers in the stack!
#include<iostream>
using namespace std;

int main() {
    int r;
    cin>>r;

    int c;
    cin>>c;
    int **arr = new int*[r];
    for(int i = 0; i<r; i++) {
        arr[i] = new int[c];
    }
    // 2D array creation done!

    // taking input into the 2D array!
    for(int i = 0; i<r; i++) {
        for(int j = 0; j<c; j++) {
            cin>>arr[i][j];
        }
    }

    // priting output
    for(int i = 0; i<r; i++) {
        for(int j = 0; j<c; j++) {
            cout<<arr[i][j];
        }
        cout<<endl;
    }

    for(int i = 0; i<r; i++) {
        delete []arr[i];
    }
    // heap memory deleted!

    delete []arr;
    // stack arrays deleted!
}

// ---------------------------------------------------------- LECTURE 30 - Macros, Global Variable, Inline Functions and Default Args --------------------------------------------------------------------------------------------------------->
// We will learn some techniques jisse we can optimize our code!
// Macros : A piece of code in a program that is replaced by the value of macro! Macro is defined by #define directive
// Lets understand macro with this context, suppose you are making a program jisme hum bhot baar PI ki value 3.14 use kr rhe hai, but kabhi maanlo future me jaake PI ki value 3.15 hojaati hai toh ab kya hum harr jagah jaake program me PI ki value change krenge? Nhi! for that we will just write #define PI 3.14... ab future me jab bhi PI ki values change hoti hai toh hum PI ki value sirf macro me jaake change krdenge and humara kaam hojayega!
// You can argue ki ek aur solution ho sakta tha and that is ek global variable declare krdo! double PI = 3.14.. isme ye dikkat hai ki isme hum ek extra space le rhe hai... itni si space lene se zyada fark toh nhi padega but still agar bina space liye macro se kaam ho jaa rha hai toh kyu space le!
// lets see thru code...
#include<iostream>
using namespace std;

#define PI 3.14

int main() {
    int r = 5;
    // double area1 = 3.14 * r * r;
    // cout<<"Area of circle : "<<area1<<endl;
    // Is way se krne pr hume kabhi agar 3.14 jo PI ki value hai usko change krna pad gya toh bhot dikkat hojayegi, yahaa toh chalo bss ek baar use hui hai but agar kabhi 100 baar use hogyi toh harr 100 jagah jaake change krna feasible nhi hai! so another solution could be declaring local/global variable

    // double PI = 3.14;
    // double area2 = PI * r * r;
    // cout<<"Area of circle : "<<area2<<endl;
    // Isme dikkat ye hai ki ye extra space le rha hai PI ki value store krne ke liye! also yahaa koi easily program me PI ki value PI = PI + 1 krke update kr sakta hai! jo ofc hum nhi chahenge! so that is why in these cases we use define macro!

    double area3 = PI * r * r;
    cout<<"Area of circle : "<<area3<<endl;
    // Isme koi space bhi nhi li PI ne and ye PI updatable bhi nhi hai!
    // PI = PI + 1; // Not possible!
    // Agar kabhi value change hoti hai toh compile hone se pehle hi macros program me sab jagah values update krdega!
}

// Another example of macro #define
#include<iostream>
using namespace std;

#define Area(l,b) (l*b) // yahaa that is how we have used macros!

int main() {
    int l = 3, b = 5;
    cout<<"Area of rectangle : "<<Area(l,b);
}

// Types of Macros : Object Like Macros, Chain Like Macros, Multiline Macros, Function Like Macros!
// Object Like Macros : Ye upar jo hum kr rhe the ye vhi Object like macros ka hi example the!
#include <iostream>
using namespace std;

#define DATE 31

// Driver Code
int main() {
	cout<<"Lockdown will bve extended upto "<<DATE<<"-MAY-2020."<<endl;
}

// Chain Like Macros : Macros inside macros are termed chain macros. In chain macros first of all parent macro is expanded then the child macro is expanded.
#include <iostream>
using namespace std;

#define INSTAGRAM FOLLOWERS
#define FOLLOWERS 138

int main() {
	cout<<"I have "<<INSTAGRAM<<"K followers on Instagram!"<<endl;
}

// Multiline Macros : An object-like macro could have a multi-line. So to create a multi-line macro you have to use backslash-newline.
#include <iostream>
using namespace std;

#define ELE 1, \
            2, \
            3
            // Yahaa ye macro likhne ka tareeka aise hi hoga! iss hi format me!

int main() {
	int arr[] = { ELE };
    cout<<"Printing array : ";
    for(int i = 0; i<3; i++) {
        cout<<arr[i];
    }
}

// Function Like Macros : These macros are the same as a function call. It replaces the entire code instead of a function name. Pair of parentheses immediately after the macro name is necessary. If we put a space between the macro name and the parentheses in the macro definition, then the macro will not work.
// A function-like macro is only lengthened if and only if its name appears with a pair of parentheses after it. If we don’t do this, the function pointer will get the address of the real function and lead to a syntax error.
#include<iostream>
using namespace std;

#define min(a, b) ((a < b) ? a : b)

int main() {
    int a = 20, b = 40;
    cout<<"Out of "<<a<<" and "<<b<<", "<<min(a,b)<<" is smaller value.";
}

// Global Variables!!
// They are used when we want to share some variables between functions! Ye sharing variable vaala kaam hum ref variable se bhi kr sakte hai, kyunki agar int main me koi variable hai usko hum chahte hai ki usko multiple functions access kr sake toh vo toh hum ref variable se bhi kr sakte hai sab func me int main vaale variable ka ref pass krke! but also ek tareeka hai variable share krne ka and that is global variable bnaa ke! usme bhi memory block ek hi hota hai and multiple functions access kr paate hai!
#include<iostream>
using namespace std;

int i = 10; // Global variable i, this can be accessed any where!

void a(int& x1) {
    cout<<"Value of x1 referenced from i of int main outer block : "<<x1<<endl;
    cout<<"Address of x1 referenced from i of int main outer block : "<<&x1<<endl;
    cout<<"Value of Global i : "<<i<<endl;
}

void b(int& x2) {
    cout<<"Value of x2 referenced from i of int main outer block : "<<x2<<endl;
    cout<<"Address of x2 referenced from i of int main outer block : "<<&x2<<endl;
    cout<<"Value of Global i : "<<i<<endl;
}

int main() {
    int i = 5;
    {
        int i = 3;
        cout<<"Value of int main inner block i : "<<i<<endl; // It will print 3
        cout<<"Address of int main inner block i : "<<&i<<endl;
    }
    cout<<"Value of int main outer block i : "<<i<<endl; // It will print 5
    cout<<"Address of int main outer block i : "<<&i<<endl;
    // Local variable toh we know what are they!

    a(i);
    b(i);
}
// Lets understand certain things, yahaa 3 memory blocks hai i naam se jinme sabka scope alag alag hai hence inn sabko alag alag memory location alot ki gyi hai memory me, isliye inn teeno i's ka address ek dusre se different hoga!
// and int main me just baad jo i hai (i=5 vaala) and jo functions me jo x1 and x2 hai inn teeno ka address same hoga kyunki ye sab same jagah point kr rhe hai! which is i = 5 vaale memory block pe!
// Also the global i is not affecting the values of local i and the functions the local i is referencing to, this is becoz hume dekhne se lag rha hai ki local i and global i same hai kyunki unke naam same hai, pr they are two different memory locations! and hum jo function call me pass kr rhe hai vo local i variable hai isliye functions output bhi uss hi ke hisaab se de rhe hai!
// So abhi tak we get it, ki teeno i's are different and have different memory locations kyunki sabka alag alag scope hai! and i = 5 vaala i and x1, x2 are just different names of the same memory block i = 5! isliye inn teeno ka address same hai and teeno i ka different hai!

// Hum chahe toh global i variable bhi pass kr sakte hai a and b ke function call me, like this...its bit extra to know, but okay...
#include<iostream>
using namespace std;

int i = 10; // Global variable i, accessible anywhere

void a(int& x1, int& global_i) {
    cout<<"Value of x1 referenced from i of int main outer block : "<<x1<<endl;
    cout<<"Address of x1 referenced from i of int main outer block : "<<&x1<<endl;
    cout<<"Value of Global i : "<<global_i<<endl;
}

void b(int& x2, int& global_i) {
    cout<<"Value of x2 referenced from i of int main outer block : "<<x2<<endl;
    cout<<"Address of x2 referenced from i of int main outer block : "<<&x2<<endl;
    cout<<"Value of Global i : "<<global_i<<endl;
}

int main() {
    int i = 5; // Local variable i in main
    {
        int i = 3; // Local variable i in inner block
        cout<<"Value of int main inner block i : "<<i<<endl; // It will print 3
        cout<<"Address of int main inner block i : "<<&i<<endl;
    }
    cout<<"Value of int main outer block i : "<<i<<endl; // It will print 5
    cout<<"Address of int main outer block i : "<<&i<<endl;

    // Passing global variable i into the function calls
    a(i, ::i); // Pass local i and global i to function a
    b(i, ::i); // Pass local i and global i to function b
    // Here we need to use :: (scope resolution operator) to explicitly specify the global scope. In your code, ::i is used to refer to the global variable i.
    // Inside the main function, you have a local variable i, and outside of any function, you have a global variable i. When you want to specifically refer to the global variable i within the main function or any other function, you use the scope resolution operator :: followed by the variable name (::i).
    // To avoid ambiguity : Since there's a local variable i within the main function, if you simply use i within the function calls to a and b, it will refer to the local i variable, not the global one. To differentiate between the local and global variables named i, you use ::i to explicitly refer to the global variable.
}

// But using Global variables is not good, its a bad practice, kyunki agar maanlo humne koi ek program likha jisme hume ek hi variable bhot baar use krna ho rha hai, toh humne usko global bnaa diya, but problem is isko koi bhi update kr sakta hai and agar ek baar update hogya toh kaam khraab hojayega! jabki aisa define ke case me nhi tha!
// Jaise define me pta hai hume ki agar koi change krega bhi toh vo sirf define me macro ki value me hi change krega toh usko toh baad me undo kiya jaa sakta hai! but agar kisi ne global variable me koi change krdiya within the program me kahin bhi, toh uss change ko dhundna mushkil hojayega! jabki we know define ke thru macro bnaa ke value use krne pr vo program me kahin bhi aur update nhi ho sakta except the define itself, but global variables intiallize krne ke baad bhi program me kahin bhi change ya update kiye jaa sakte hai!

// Inline Functions!
// The thing is jab hum koi program likhte hai, toh uss poore program ki ek stack banti hai as we have talked earlier! and sabse pehle uss stack me int main function aata hai and then int main ke jo variable hote hai vo apni apni memory space lelete hai! then int main me koi function call ho rhi hoti hai toh pehle vo function hoti hai then vahaa se return me jo bhi response aata hai (and isme processing lgti hai!) another thing is ek function call me jo variable hote hai function defintion me unki copy ban jaati hai and iske kaaran aur memory use ho rhi hai!
// Ab optimize krna hai hume code ko toh function call krna hataa bhi nhi sakte kyunki usse readility badhti hai code ki, toh kya kre? ki sab cheeze settle hojaye!
// lets see...
#include<iostream>
using namespace std;

int main() {
    int a = 1, b = 3;
    int ans = 0;
    // if(a>b) {
    //     cout<<a<<endl;
    // }
    // else {
    //     cout<<b<<endl;
    // }
    // iss cheez ko hum ek line me bhi likh sakte hai jisse readabilitybadhegi code ki... using ternary operator!
    ans = (a>b) ? a : b; // ye ek line me aagya and isse readibilty badh gyi!
} // but suppose now ab ye same cheez baar baar likhi ho agar! like...

#include<iostream>
using namespace std;

int main() {
    int a = 1, b = 3;
    int ans = 0;
    a = a + 2;
    b = b + 4;
    ans = (a>b) ? a : b;

    a = a + 10;
    b = b + 20;
    ans = (a>b) ? a : b;

    a = a + 20;
    b = b + 30;
    ans = (a>b) ? a : b;
    // Ab isse harr baar hume calculate krna pad rha hai, toh isse better hai isko ek functon me likhdo and function call maardo, but usme bhi function call me variable pass krne pr vo copy hojaate hai function defintion me jisse extra memory jayegi, toh usse bachne ke liye pass by refernce krdo!
}

#include<iostream>
using namespace std;

int getMax(int& a, int& b) {
    return (a>b) ? a : b;
}

int main() {
    int a = 1, b = 3;
    int ans = 0;
    a = a + 2;
    b = b + 4;
    cout<<getMax(a,b)<<endl;

    a = a + 10;
    b = b + 20;
    cout<<getMax(a,b)<<endl;

    a = a + 20;
    b = b + 30;
    cout<<getMax(a,b)<<endl;
}
// So abhi tak humne almost saari problems solve krdi bss ek bachi hai and that is of function call krna pad rha hai baar baar jisse processing pr zor pad rha hoga (bhale hi zyada nhi, but still we are talking about optimization!)
// So for that we will use Inline keyword, ab ye kya krta hai ki jiss tarah define keyword compile hone se pehle sab jagah se values ko macro ke according replace krdeta hai vhi similar cheez inline keyword krta hai functions ke liye! but remember ye one line functions ke liye easily krdeta hai! 2-3 lines functions ke liye ye cheez work krna depends on compiler and usse zyada lines ke functions ke liye this keyword does not work!

#include<iostream>
using namespace std;

inline int getMax(int& a, int& b) {
    return (a>b) ? a : b;
}

int main() {
    int a = 1, b = 3;
    int ans = 0;
    a = a + 2;
    b = b + 4;
    cout<<getMax(a,b)<<endl;

    a = a + 10;
    b = b + 20;
    cout<<getMax(a,b)<<endl;

    a = a + 20;
    b = b + 30;
    cout<<getMax(a,b)<<endl;
}
// Isme sab jagah se getMax ki jagah jo function definition hai vo aajayega just before compiling... isse humari code readability bhi affect nhi hui, baar baar function call krne vaali prblms bhi solve hogyi, and jo extra space ban rha tha vo bhi ref variable ki help se solve hogya!
// Overall this code is optimized!

// Default Argumnents!
#include<iostream>
using namespace std;

void printArr(int arr[], int size, int start = 0) { // Start is the default argument!
    for(int i = start; i<size; i++) {
        cout<<arr[i]<<" ";
    }
}

int main() {
    int arr[5] = {1,2,3,4,5};
    int size = 5;
    printArr(arr, size, 2); // Iss case me array 2 index se print hojayega end tak!
    // Ab now what we want is maanlo kabhi humne agar start parameter dene ka mann nhi kiya, toh hum chahte hai by default jo printArr function hai vo array ko starting se print krde by default! so for that hum function ke defintion me int start = 0; likh denge jisse ye start ek default argument bangya! means agar koi parameter pass nhi krenge start ke liye toh automatically the start ko 0 value assign hojayegi!
    printArr(arr, size); // Iss case me array start to end poora print hojayega!
    printArr(arr, size, 3); // Iss case me array 3 index se print hojayega end tak!
} // But remember default arguments sirf right to left hi bante hai, mtlb pehle sabse right vaala argument banega uske baad hi koi left vaala argument default ban sakta hai, mtlb ki agar aisa hota, printArr(int arr[], int size, int start, int end), toh pehle end ko default banaate then start ko and so on...agar size ko default banana hai toh pehle start and end ko default hona zaruri hai!

// ------------------------------------------------------------ Summary Questions Lists -------------------------------------------------------------------------------------------------------------------------------------------------------------->
// Question 1 : Rotating an Array!
// Question 2 : Check if an array is sorted and rotated or not!
// Question 3 : Addition of 2 Arrays

// Question 4 : Find the length of the character array!
// Question 5 : Reverse a string
// Question 6 : Check for a palindrome
// Question 7 : Find the maximum occuring characters in a string!
// Question 8 : You have a line of text and you have to replace all the spaces with the @40
// Question 9 : Remove all the occurences of a sub string in a parent string!
// Question 10 : Permutation in string!
// Question 11 : Removing all adjacent duplicates! Actual question number 1047 on LeetCode!
// Question 12 : String Compression! Ques number 443 on Leetcode

// Question 13 : Linear Search in 2D Array!
// Question 14 : Row sum! printing sum of all the rows in the 2D array!
// Question 15 : Find the largest rowsum and which row has it!
// Question 16 : Wave Print Problem
// Question 17 : Spiral Print Problem!
// Question 18 : Binary Search in 2D arrays!

// Question 19 : Check prime!
// Question 20 : Count primes in a range! (Sieve of Eratosthenes)
// Question 21 : Fast Exponentitation!