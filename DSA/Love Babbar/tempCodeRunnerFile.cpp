#include<iostream>
#include<string>
using namespace std;

string removeSubstr(string str, string substr) {
    while(str.length() != 0 && str.find(substr) < str.length()) {
        str.erase(str.find(substr), substr.length());
    }
    return str;
} 

int main() {
    string str;
    string substr;
    cout<<"Enter your string : ";
    cin>>str;
    cout<<"String 1 : "<<str<<endl;

    cout<<"Enter your sub-string : ";
    cin>>substr;
    cout<<"String 2 : "<<substr<<endl;
    cout<<removeSubstr(str,substr);
}