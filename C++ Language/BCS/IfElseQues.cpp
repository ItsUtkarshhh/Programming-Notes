#include<iostream>
using namespace std;

int main() {
    int n;
    cin>>n;
    if(n%2 == 0) {
        cout<<"Even";
    }
    else {
        cout<<"Odd";
    }
}

#include<iostream>
using namespace std;

int main() {
    char ch;
    cin>>ch;
    if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
        cout<<"Vowel";
    }
    else {
        cout<<"Consonant";
    }
}

#include<iostream>
using namespace std;

int main() {
    int x1, x2, x3;
    cin>>x1>>x2>>x3;
    if(x1>x2 && x1>x3) {
        cout<<"x1 is largest";
    }
    else if(x2>x1 && x2>x3) {
        cout<<"x1 is largest";
    }
    else {
        cout<<"x3 is largest";
    }
}

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