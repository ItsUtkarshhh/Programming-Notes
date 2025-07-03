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
//          : And to limit the inner loop we need to think of how many times the inner loop is actually iterating or executing, so it depends on the row number! so that will be the condition!
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
// Thinking : Again, the loop printing and iterating logic will be same, just that here we need to adapt the inner loop condition of pattern 3, and this time we just need to print the row number at every iteration of inner loop!
//          : And for the inner loop condition we can take inspiration from the pattern 5. 
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
//           : 4 5 6
//           : 7 8 9 10
//           : 11 12 13 14 15
// Thinking : Here we just need to print counting starting with 1 and going till the end! we will be using a count variable to print the counting and increament it in every iteration of inner loop!
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
} // Note : You can try eliminate the count variable by using rows and columns relationships! And these relationships we can form by analysing each element of the matrix and then can create a formula!

// Pattern 8 : 1
//           : 2 3
//           : 3 4 5
//           : 4 5 6 7
//           : 5 6 7 8 9
// Thinking : Again the loop logic will be same as previous one, just that we need to adapt the inner loop condition as pyramidical structure, and just need to start printing with the row number and increamenting it one by one!
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

// Pattern 9 : 1
//           : 2 1
//           : 3 2 1
//           : 4 3 2 1
//           : 5 4 3 2 1
// Thinking : This question is similar to the pattern 8, the only change is here we need to decreament the count one by one!
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

// Pattern 10 : A B C D E
//            : A B C D E
//            : A B C D E
//            : A B C D E
//            : A B C D E
// Thinking : Here, printing logic will be same, just that here we need to print characters! And this question is resembles with the pattern 3, just that here we need to print characters! So we will do the same and will just convert the integers into characters with adding 'A'.
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

// Pattern 11 : A A A A A
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

// Pattern 12 : A B C D E
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

// Pattern 13 : A B C D E
//            : B C D E F
//            : C D E F G
//            : D E F G H
//            : E F G H I
// Thinking : Here, we can see that it is similar to the pattern 8, that printing at every row start with the character counter part of the integers! and one difference here is that we are not making pyriamidical structure this time! means this time we won't restrict the inner loop condition and it will iterate till whole nc.
#include<iostream>
using namespace std;

int main() {
    int nr, nc;
    cin>>nr>>nc;
    for(int i = 0; i<nr; i++) {
        int count = i;
        for(int j = 0; j<nc; j++) {
            cout<<char('A' + count)<<" ";
            count++;
        }
        cout<<endl;
    }
} // Note : You can try eliminate the count variable by using rows and columns relationships! And these relationships we can form by analysing each element of the matrix and then can create a formula!

// Pattern 14 : A
//            : B B
//            : C C C
//            : D D D D
//            : E E E E E
// Thinking : Here, it is similar to pattern 11, just that here we need to restrict the inner loop condition of iterating till row number only, to form the pyramidical structure!
#include<iostream>
using namespace std;

int main() {
    int nr, nc;
    cin>>nr>>nc;
    for(int i = 0; i<nr; i++) {
        for(int j = 0; j<=i; j++) {
            cout<<char('A' + i)<<" ";
        }
        cout<<endl;
    }
}

// Pattern 15 : A
//            : B C
//            : D E F
//            : G H I J
//            : K L M N O
// Thinking : Here, it is similar to pattern 12, just that here we need to restrict the inner loop condition of iterating till row number only, to form the pyramidical structure!
#include<iostream>
using namespace std;

int main() {
    int nr, nc;
    cin>>nr>>nc;
    int count = 0;
    for(int i = 0; i<nr; i++) {
        for(int j = 0; j<=i; j++) {
            cout<<char('A' + count)<<" ";
            count++;
        }
        cout<<endl;
    }
} // Note : You can try eliminate the count variable by using rows and columns relationships! And these relationships we can form by analysing each element of the matrix and then can create a formula!

// Pattern 16 : E
//            : D E
//            : C D E
//            : B C D E
//            : A B C D E
// Thinking : Here, the pattern is somewhat similar to pattern 9, just in character format, also in reverse order! We can solve this in two ways, either using a variable or without it, with variable is very simple, so we will try to formulate a formula and use it this time, and we have got this "(n - i - 1) + j".
#include<iostream>
using namespace std;

int main() {
    int nr, nc;
    cin>>nr>>nc;
    for(int i = 0; i<nr; i++) {
        for(int j = 0; j<=i; j++) {
            cout<<char('A' + (nr - i - 1) + j)<<" ";
        }
        cout<<endl;
    }
}

// Pattern 17 :         *
//            :       * *
//            :     * * *
//            :   * * * *
//            : * * * * *
// Thinking : Here, in these type of patterns, where there are spaces first, here we need to start thinking to print the spaces first and then the stars! Again back to basics, the outer loop is for changing rows! and the inner loop is actually for printing!
//          : Hence, we can see that for a 5x5 matrix, first row contains 4 spaces and 1 star, second row contains 3 spaces and 2 stars, third row contains 2 spaces and 3 stars and so on, means the number of spaces in each row is "n - i" and number of stars are "i"... now we can star to code!
#include<iostream>
using namespace std;

int main() {
    int nr, nc;
    cin>>nr>>nc;
    for(int i = 1; i<=nr; i++) {
        int spaces = nr - i;
        while(spaces) {
            cout<<" "<<" ";
            spaces--;
        }

        int stars = i;
        while(stars) {
            cout<<"*"<<" ";
            stars--;
        }
        cout<<endl;
    }
}

// Pattern 18 : * * * * *
//            : * * * *
//            : * * *
//            : * *
//            : *
// Thinking : Here, these are not spaces first questions, so it will be done pretty simply, just here we need to analyse that how many stars are printing in each row and on which factors it depends!
//          : So, we can see that, first row contains 5 stars, second row contains 4 stars, third row contains 3 stars and so on, means each row contains "n - i + 1" stars if i is starting with 1 and "n - i" stars if i starting with 0.
//          : And here the inner loop condition will change slightly! so to find out that, we should not think like what would be the restriction on the inner loop, we need ask different questions like how many times the inner loop will execute, that will determine it! and we can see that in every row inner loop is executing "n - i" times if i starting 0 and extra minus 1 if i starting with 1.
#include<iostream>
using namespace std;

int main() {
    int nr, nc;
    cin>>nr>>nc;
    for(int i = 0; i < nr; i++) {
        for(int j = 0; j < (nr - i); j++) {
            cout<<"*"<<" ";
        }
        cout<<endl;
    }
}

// Pattern 19 : * * * * *
//            :   * * * *
//            :     * * *
//            :       * *
//            :         *
// Thinking : Here, this is a space first pattern, so based on that, we will use the same logic, that we will analyse how many stars and spaces are getting printed in every row and what will be the inner loop condition! and what we will need to print!
//          : Identifying how many spaces we need to print in every row, first row contains 0 spaces, second row contains 1 space, third row contains 2 spaces and so on, means each row contains "i" spaces if i starting with 0 and "i - 1" spaces if i starting with 1.
//          : Identifying how many stars are getting printed in each row, first row contains 5 stars, second row contains 4 stars, third row contains 3 stars and so on, means each row contains "n - i + 1" if i starting with 1 and "n - i" stars if i starting with 0.
//          : Now finally, what will be the condition to print, so we again think in the same way, that is how many times the inner loop should run to print, in first row it should print something (that something we will find out later) 5 times, second row 4 times, third row 3 times and so on. means, inner loop will execute "n - i" times if i is starting with 0 and "n - i - 1" times of i starting with 1.
#include<iostream>
using namespace std;

int main() {
    int nr, nc;
    cin>>nr>>nc;
    for(int i = 0; i < nr; i++) {
        int spaces = i;
        while(spaces) {
            cout<<" "<<" ";
            spaces--;
        }

        int stars = nr - i;
        while(stars) {
            cout<<"*"<<" ";
            stars--;
        }
        cout<<endl;
    }
}