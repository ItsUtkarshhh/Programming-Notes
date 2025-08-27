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
    string result = removeOcc(str, substr);
    if(result != "") cout<<"The final string is : "<<result;
    else cout<<"Empty string";
}