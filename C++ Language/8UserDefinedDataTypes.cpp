// Structures :
// Example 1 :
#include<iostream>
using namespace std;

struct student { // Structure is a user defined data type.
    int roll_no;
    char name_initials;
    float cgpa;
};

int main() {
    student utkarsh;
    utkarsh.roll_no = 65;
    utkarsh.name_initials = 'U';
    utkarsh.cgpa = 9.25;
    cout<<"Role number of Utkarsh : "<<utkarsh.roll_no<<endl;
    cout<<"Name initials of Utkarsh : "<<utkarsh.name_initials<<endl;
    cout<<"CGPA of Utkarsh : "<<utkarsh.cgpa<<endl;
    return 0;

}

// Example 2 :
#include<iostream>
using namespace std;

typedef struct student { // Typedef keyword is used to give a short name to the user defined data type, or can say nick name.
    int roll_no;
    char name_initials;
    float cgpa;
} st;

int main() {
    st utkarsh;
    utkarsh.roll_no = 65;
    utkarsh.name_initials = 'U';
    utkarsh.cgpa = 9.25;
    cout<<"Role number of Utkarsh : "<<utkarsh.roll_no<<endl;
    cout<<"Name initials of Utkarsh : "<<utkarsh.name_initials<<endl;
    cout<<"CGPA of Utkarsh : "<<utkarsh.cgpa<<endl;
    return 0;
} // We can make arrays also of structures! and then we can make pointers also! like we can do more things with structures! but they are not very widely in use yet! but whenever you need it you know the basics so you can learn that also!

// Unions :
// Example :
#include<iostream>
using namespace std;

union human { // union is a type of structure where we have to manage the memory used. it can contain different data types, each time the new variable is initialized from the union it over writes the previous one.
    int age;
    char initials;
    float weight; // Here if we replace float with int it won't give garbage value in h1.age even though we have over we have initialized it again with another value.
};

int main() {
    human h1;
    h1.age = 20;
    h1.weight = 50;
    cout<<h1.age<<endl;
    cout<<h1.weight<<endl;
    return 0;
}

// Enum :
// Example :
#include<iostream>
using namespace std;

int main() {
    enum Money{rupees, dollar, yen}; // Explore enum more!
    cout<<rupees<<endl;
    cout<<dollar<<endl;
    cout<<yen<<endl;
    return 0;
}