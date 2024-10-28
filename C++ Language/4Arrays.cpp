// Creating and initiallizing arrays! and printing the values manually using indexes!
#include<iostream>
using namespace std;

int main() {
    // Arrays are the collection of data of same data type. and the collection of data is stored in a contigous manner.
    int marks[4] = {23, 25, 28, 65};
    cout<<"Marks of subject 1 : "<<marks[0]<<endl;
    cout<<"Marks of subject 2 : "<<marks[1]<<endl;
    cout<<"Marks of subject 3 : "<<marks[2]<<endl;
    cout<<"Marks of subject 4 : "<<marks[3]<<endl;

    marks[2] = 45;
    cout<<"Updated marks : "<<marks[2]<<endl;
    return 0;
}

// Printing values using loop!
#include<iostream>
using namespace std;

int main() {
    int marks[4] = {23, 25, 28, 65};
    for( int i = 0; i < 4; i++) {
    cout<<"Marks of subject "<<i<<" is : "<<marks[i]<<endl;
    }
    return 0;
}

// Name of an array is a pointer itself.
#include<iostream>
using namespace std;

int main() {
    int marks[4] = {59,65,56,95};
    int* a = marks;
    cout<<*(a)<<endl;
    cout<<*(a+1)<<endl;
    cout<<*(a+2)<<endl;
    cout<<*(a+3)<<endl;

    // Printing values using for loop
    for(int i = 0;i < 4; i++) {
        cout<<"The value at marks["<<i<<"] is : "<<*(a+i)<<endl;
        }

    // Printing values using while loop
    int j = 0;
    while(j < 4) {
        cout<<"The value at marks ["<<j<<"] is : "<<*(a+j)<<endl;
        j++;
        }

    // Printing values using do while loop
    int k = 0;
    do {
        cout<<"The value at marks ["<<k<<"] is : "<<*(a+k)<<endl;
        k++;
    }while(k<4);
    return 0;
}