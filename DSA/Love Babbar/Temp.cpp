#include<iostream>
#include<string>
using namespace std;

string removeDuplicates(string str) {
    int i = 0;
    while(i<str.length()) {
        if(str[i] == str[i+1]) {
            str.erase(i,2);
            if(i > 0) {
                i--
            }
        }
        else {
            i++;
        }
        if(str.empty()) {
            break;
        }
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
    cout<<permutation(str,substr);
}