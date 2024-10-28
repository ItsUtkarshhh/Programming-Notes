// Control statements are of three types in CPP : Sequence Structure, Selection Structure, Loop Structure

// If-alse statements
#include<iostream>
using namespace std;

int main() {
    int age;
    cout<<"Enter age ";
    cin>>age;
    if(age<=0) {
        cout<<"You are not yet born"<<endl;
    }
    else if((age>0) && (age<18)) {
        cout<<"You can not come to the party"<<endl;
    }
    else if(age == 18) {
        cout<<"You will get a kid pass for the party"<<endl;
    }
    else if(age>18) {
        cout<<"You can come to the party"<<endl;
    }
    else {
        cout<<"Kuch bhi????"<<endl;
    }
    return 0;
} // Normally jab hum use krte hai if-else statements tab hum if else and else-f use krte hai, inn sab me kya hota hai ki jaise hi ki agar ek condition true hogyi toh bss baaki saari condtions null and void declare hojaati hai and if-else statements vhi pr end hojaati hai, and agar koi stataments false hogyi tab hi next condition check hoti hai!
// But agar hum harr jagah sirf if likh de, toh compiler saare conditions ko check krega! whether they are correct or not!

// Switch case statements
#include<iostream>
using namespace std;

int main () {
    int age;
    cout<<"Enter your age : ";
    cin>>age;
    switch (age) {
        case 18 :
        cout<<"You are 18"<<endl;
        break;
        
        case 20 :
        cout<<"You are 20"<<endl;
        break;

        case 22 :
        cout<<"You are 22"<<endl;
        break;

        default :
        cout<<"No special cases"<<endl;
        break;
    }
    cout<<"Done with switch case";
    return 0;
} // Break statements are used in loops and switch statements!
// Loops me break statements generally loops se bahar aane ke liye krte hai, and switch me toh we have seen already!
// C language me kya hota hai ki agar hum if else ya loop me agar 1 likh de toh compiler usko true samajh ke execute krdega! and agar uss hi jagah 0 likh de false samajh ke uss statement ko ignore krke next statement pr jump kr jayega!

// Loops
// For Loops!
#include<iostream>
using namespace std;

int main() {
    for(int i = 0; i < 10; i++) {
        cout<<i<<endl;
    }
    return 0;
}

// While Loops!
#include<iostream>
using namespace std;

int main() {
    int i = 0;
    while(i<40) {
        cout<<i<<endl;
        i++;
    }
    return 0;
}

// Do While Loops!
#include<iostream>
using namespace std;

int main() {
    int i = 1;
    do{
        cout<<i<<endl;
        i++;
    }while(i<=50);
    return 0;
}

// Printing Table using for loop!
#include<iostream>
using namespace std;

int main() {
    int n;
    cout<<"Enter the number : ";
    cin>>n;
    for(int i = 1; i<=10; i++) {
        cout<<n<<" * "<<i<<" = "<<n*i<<endl;
    }
    return 0;
}

// Break & Continue Statements
#include<iostream>
using namespace std;

int main() {
    for(int i = 1; i<10; i++) {
        if(i==3)
        break; // It breaks the loops then and there and no further execution will happen.
        cout<<i<<endl;
    }
    return 0;
}

#include<iostream>
using namespace std;

int main() {
    for(int i = 1; i<10; i++) {
        if(i==3)
        continue; // It drops the execution at that point only and skips that point and then executes further program.
        cout<<i<<endl;
    }
    return 0;
}