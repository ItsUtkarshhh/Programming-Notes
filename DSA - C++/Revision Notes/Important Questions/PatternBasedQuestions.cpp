// --------------------------------------------------------- Pattern based questions! ----------------------------------------------------------------->
// Pattern 1 : * * * * *
//           : * * * * *
//           : * * * * *
//           : * * * * *
//           : * * * * *
// Thinking : Pattern printing is typically done using nested loops. The outer loop controls the rows. The inner loop controls the columns (i.e., what gets printed in each row). After printing all columns in a row, we move to the next line using cout << endl.
//          : Start from the first row. In that row, start from the first column and print a *. Repeat step 2 until all 5 columns are printed in that row. Move to the next row, and repeat the above steps. Stop once all 5 rows are printed.
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

// Pattern 2 : 1 1 1 1 1
//           : 2 2 2 2 2
//           : 3 3 3 3 3
//           : 4 4 4 4 4
//           : 5 5 5 5 5
// Thinking : The outer loop is used to move through the rows. The inner loop is used to print the required numbers in each row.
//          : Since we are required to print : 1 in the 1st row, 2 in the 2nd row, 3 in the 3rd row, and so on, and it means we need to print the row number multiple times in each row.
//                                           : The number of times each number should be printed is five times, as mentioned.
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

// Pattern 3 : 1 2 3 4 5
//           : 1 2 3 4 5
//           : 1 2 3 4 5
//           : 1 2 3 4 5
//           : 1 2 3 4 5
// Thinking : It is same as previous question, just that here we will be printing columns.
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

// Pattern 4 : 1 2 3 4 5
//           : 6 7 8 9 10
//           : 11 12 13 14 15
//           : 16 17 18 19 20
//           : 21 22 23 24 25
// Thinking : Printing logic is same here as we will be using outer loop to change the rows and inner loop to actually print the character or wtvr!
//          : Just we need to think about the printing logic we need to use the print the required pattern! Here first we can think of simply using count variable starting with 1, and will increament it at every iteration inner loop!
#include<iostream>
using namespace std;

int main() {
    int nr, nc;
    cin>>nr>>nc;
    int count = 1;
    for(int i = 1; i<=nr; i++) {
        for(int j = 1; j<=nc; j++) {
            cout<<count<<" ";
            count++;
        }
        cout<<endl;
    }
} // Note : You can try eliminate the count variable by using rows and columns relationships! And these relationships we can form by analysing each element of the matrix and then can create a formula!

// Pattern 5 : *
//           : * *
//           : * * *
//           : * * * *
//           : * * * * *
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

// Pattern 6 : 1
//           : 2 2
//           : 3 3 3
//           : 4 4 4 4
//           : 5 5 5 5 5
// Thinking : Again, the loop printing and iterating logic will be same, just that here we need to adapt the inner loop condition of question 5, and this time we just need to print the row number at every iteration of inner loop!
#include<iostream>
using namespace std;

int main() {
    int nr, nc;
    cin>>nr>>nc;
    for(int i = 1; i<=nr; i++) {
        for(int j = 1; j<=i; j++) {
            cout<<i<<" ";
        }
        cout<<endl;
    }
}

// Pattern 7 : 1
//           : 2 3
//           : 3 4 5
//           : 4 5 6 7
//           : 5 6 7 8 9
// Thinking : Again the loop logic will be same as previous ones, just that we need to adapt the inner loop condition of question 5, and just need to start printing with the row number and increamenting it one by one!
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
} // Note : You can try eliminate the count variable by using rows and columns relationships! And these relationships we can form by analysing each element of the matrix and then can create a formula!

// Pattern 8 : 1
//           : 2 1
//           : 3 2 1
//           : 4 3 2 1
//           : 5 4 3 2 1
// Thinking : This question is similar to the question 7, the only change is here we need to decreament the count one by one!
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
} // Note : You can try eliminate the count variable by using rows and columns relationships! And these relationships we can form by analysing each element of the matrix and then can create a formula!

// Pattern 9 : A B C D E
//           : A B C D E
//           : A B C D E
//           : A B C D E
//           : A B C D E
// Thinking : Here, printing logic will be same, just that here we need to print characters! And this question is resembles with the question 3, just that here we need to print characters! So we will do the same and will just convert the integers into characters with adding 'A'.
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

// Pattern 10 : A A A A A
//            : B B B B B
//            : C C C C C
//            : D D D D D
//            : E E E E E
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

// Pattern 11 : A B C D E
//            : F G H I J
//            : K L M N O
//            : P Q R S T
//            : U V W X Y
// Thinking : Here our approach will be similar to the counting in integers! so we will just use that approach of count variable and will simply increamenet using count!
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
} // Note : You can try eliminate the count variable by using rows and columns relationships! And these relationships we can form by analysing each element of the matrix and then can create a formula!

// Pattern 12 : A B C D E
//            : B C D E F
//            : C D E F G
//            : D E F G H
//            : E F G H I
// Thinking : Here our