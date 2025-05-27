// --------------------------------------------------------- Pattern based questions! ----------------------------------------------------------------->
// Question 1 : Draw a pattern with 4 rows and 4 columns!
// Thinking : Pattern printing is typically done using nested loops. The outer loop controls the rows. The inner loop controls the columns (i.e., what gets printed in each row). After printing all columns in a row, we move to the next line using cout << endl.
//          : Start from the first row. In that row, start from the first column and print a *. Repeat step 2 until all 4 columns are printed in that row. Move to the next row, and repeat the above steps. Stop once all 4 rows are printed.
#include<iostream>
using namespace std;

int main() {
    int nr, nc;
    cin>>nr>>nc;
    for(int i = 0; i<nr; i++) {
        for(int j = 0; j<nc; j++) {
            cout<<"*"<<" ";
        }
        cout<<endl;
    }
}

// Question 2 : Print 1 three times in 1st row, 2 three times in 2nd row, 3 three times in 3rd row!
// Thinking : The outer loop is used to move through the rows. The inner loop is used to print the required numbers in each row.
//          : Since we are required to print : 1 in the 1st row, 2 in the 2nd row, 3 in the 3rd row, and it means we need to print the row number multiple times in each row.
//                                           : The number of times each number should be printed is 3 times, as mentioned.
#include<iostream>
using namespace std;

int main() {
    int nr, nc;
    cin>>nr>>nc;
    for(int i = 1; i<=nr; i++) {
        for(int j = 1; j<=nc; j++) {
            cout<<i<<" ";
        }
        cout<<endl;
    }
}

// Question 3 : Create a pattern like there are 4 rows and 1st column contains only 1, 2nd column contains only 2, 3rd column contains only 3, 4th column contains only 4!
// Thinking : It is same as previous question, just that here we will be printing columns!
#include<iostream>
using namespace std;

int main() {
    int nr, nc;
    cin>>nr>>nc;
    for(int i = 1; i<=nr; i++) {
        for(int j = 1; j<=nc; j++) {
            cout<<j<<" ";
        }
        cout<<endl;
    }
}

// Question 4 : Create a pattern where it has three rows and 1 2 3 in first row, 4 5 6 in 2nd row and 7 8 9 in 3rd row!
// Thinking : Most of the logic here is same just that here we need to print counting starting with 1 to nr*nc, so you can just print i*j everytime!
#include<iostream>
using namespace std;

int main() {
    int nr, nc;
    cin>>nr>>nc;
    for(int i = 1; i<=nr; i++) {
        for(int j = 1; j<=nc; j++) {
            cout<<i*j<<" ";
        }
        cout<<endl;
    }
}

// Question 5 : Print the star pattern, where 1st row has 1 star, 2nd row has 2 stars and so on..
// Thinking : Here, almost all the logic is same as of first question, just that here as we need to print as much star as the number of rows! so we will limit the printing loop (inner loop) condition only!
#include<iostream>
using namespace std;

int main() {
    int nr, nc;
    cin>>nr>>nc;
    for(int i = 1; i<=nr; i++) {
        for(int j = 1; j<=i; j++) {
            cout<<"*"<<" ";
        }
        cout<<endl;
    }
}

// Question 6 : Print 1 one time in 1st row, 2 two times in 2nd row and so on...
// Thinking : Here, the logic is the combination of question 4 and 5. But this time to print in the inner loop we need to think of a strategy like rather we can simply use a count starting with 1 and incrementing it at every iteration!
#include<iostream>
using namespace std;

int main() {
    int nr, nc;
    cin>>nr>>nc;
    int count = 1;
    for(int i = 1; i<=nr; i++) {
        for(int j = 1; j<=i; j++) {
            cout<<count<<" ";
            count++;
        }
        cout<<endl;
    }
}

// Question 7 : 1 in 1st row, 2 3 in 2nd row, 3 4 5 in 3rd row, 4 5 6 7 in 4th row and so on...
// Thinking : Here, use the inner loop to print values, and from the analysis we can see that every row's first number is the row number and after that it is incrementing by 1 and so on...
#include<iostream>
using namespace std;

int main() {
    int nr, nc;
    cin>>nr>>nc;
    for(int i = 1; i<=nr; i++) {
        int count = i;
        for(int j = 1; j<=i; j++) {
            cout<<count<<" ";
            count++;
        }
        cout<<endl;
    }
}

// Question 8 : Print 1 in 1st row, 2 1 in 2nd row, 3 2 1 in 3rd row and so on...
// Thinking : Here, use the inner loop to print values, and from the analysis we can see that every row's first number is the row number and after that it is decrementing by 1 and so on...
#include<iostream>
using namespace std;

int main() {
    int nr, nc;
    cin>>nr>>nc;
    for(int i = 1; i<=nr; i++) {
        int count = i;
        for(int j = 1; j<=i; j++) {
            cout<<count<<" ";
            count--;
        }
        cout<<endl;
    }
}

// Question 9 : Print ABCDE in each row as input by the user.
// Thinking : Here, we will use the simple printig logic till now, just that we will do one thing that is, convert the integer values into characters!
#include<iostream>
using namespace std;

int main() {
    int nr, nc;
    cin>>nr>>nc;
    for(int i = 0; i<nr; i++) {
        for(int j = 0; j<nc; j++) {
            cout<<char('A' + j)<<" ";
        }
        cout<<endl;
    }
}

// Question 10 : Print A three times in 1st row, B three times in 2nd row, C three times in 3rd row and so on...
// Thinking : Logic is pretty much same as of above, just that here we will add row number with the character! rather than column number!
#include<iostream>
using namespace std;

int main() {
    int nr, nc;
    cin>>nr>>nc;
    for(int i = 0; i<nr; i++) {
        for(int j = 0; j<nc; j++) {
            cout<<char('A' + i)<<" ";
        }
        cout<<endl;
    }
}

// Question 11 : Print A B C and then D E F in the next line and so on...
// Thinking : Here our approach will be similar to the counting in integers! so we will just use that approach of i*j and will convert it into character!
#include<iostream>
using namespace std;

int main() {
    int nr, nc;
    cin>>nr>>nc;
    int count = 0;
    for(int i = 1; i<=nr; i++) {
        for(int j = 0; j<nc; j++) {
            cout<<char('A' + count)<<" ";
            count++;
        }
        cout<<endl;
    }
}

// Question 12 : Print A B C, B C D in next row, C D E in next row and so on...
// Thinking : Here our