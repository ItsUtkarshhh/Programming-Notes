// --------------------------------------------------------- Part 1 : Fibonacci Series based questions! ----------------------------------------------------------------->
// Question 1 : Print the first n Fibonacci numbers!
// Thinking : Start from position 1 : If n == 1, print 0 → because 0 is the 1st Fibonacci number.
//          : If n == 2 : Print 0 1 → because 0 is the 1st and 1 is the 2nd Fibonacci number.
//          : For n > 2 : Print the first two numbers: 0 and 1 to start the sequence.
//                      : Use a loop to calculate the remaining Fibonacci numbers.
//                      : Every new number is the sum of the previous two → next = first + second.
//                      : Update first and second after every step to move forward in the sequence.
//          : Loop Condition : Since the first two numbers are already printed, loop should run n - 2 times to complete the sequence up to the nth number.
#include<iostream>
using namespace std;

void printFib(int n) {
    if(n <= 0) {
        cout<<"Invalid Position!";
        return;
    }
    if(n == 1) {
        cout<<0<<endl;
        return;
    }
    else if(n == 2) {
        cout<<0<<" "<<1<<endl;
        return;
    }
    else {
        cout<<0<<" "<<1<<" ";
        int first = 0;
        int second = 1;
        while(n - 2 != 0) {
            int next = first + second;
            cout<<next<<" ";
            first = second;
            second = next;
            n--;
        }
    }
    return;
}

int main() {
    int n;
    cin>>n;
    printFib(n);
}
// Drawback : There is redundancy in the printing logic — you're printing 0 and 1 separately using if and else if blocks, even though they can be easily handled within the loop itself.
//          : It's important to clearly distinguish whether n refers to the position in the Fibonacci sequence or the number of terms to print. Mixing both concepts leads to confusion, unnecessary condition checks, and harder-to-maintain code.
//          : A cleaner approach is to treat n as the number of terms, and start from index 0 in a loop, letting the loop generate each term — this simplifies both logic and readability.

// Improved On Drawbacks!
#include<iostream>
using namespace std;

void printFib(int n) {
    if(n <= 0) {
        cout<<"Invalid Position!";
        return;
    }
    int first = 0; int second = 1;
    for(int i = 1; i <= n; i++) {
        cout<<first<<" ";
        int next = first + second;
        first = second;
        second = next;
    }
    return;
}

int main() {
    int n;
    cin>>n;
    printFib(n);
}

// Question 2 : Find the nth Fibonacci number!
// Thinking : Similar as previous one! Just that this time we wont print all the values in the loop, we will only calculate using the loop, and after calculating nth number we will print it at the end!
#include<iostream>
using namespace std;

int printNthFib(int n) {
    if(n <= 0) {
        cout<<"Invalid Position!";
        return -1;
    }
    int first = 0; int second = 1;
    for(int i = 1; i < n; i++) {
        int next = first + second;
        first = second;
        second = next;
    }
    return first;
}

int main() {
    int n;
    cin>>n;
    cout<<printNthFib(n);
}

// Question 3 : Sum of the first n fibonacci numbers!
// Thinking : We simply keep adding the first value in every loop iteration before updating it — the rest of the logic (calculating next and updating values) remains the same as the standard Fibonacci generation.
#include<iostream>
using namespace std;

int printFibSum(int n) {
    if(n <= 0) {
        cout<<"Invalid Position!";
        return -1;
    }
    int first = 0; int second = 1;
    int sum = 0;
    for(int i = 1; i <= n; i++) {
        int next = first + second;
        sum = sum + first;
        first = second;
        second = next;
    }
    return sum;
}

int main() {
    int n;
    cin>>n;
    cout<<printFibSum(n);
}

// Question 4 : Check if a given number is a Fibonacci number!
// Thinking : Start with Generating Fibonacci Numbers : Begin with two initial Fibonacci numbers: 0 and 1.
//                                                    : Use a loop to continue generating the next Fibonacci numbers by summing the previous two (next = first + second).
//          : Compare with the Input Number : In every iteration, check if the current Fibonacci number is equal to the input number. If it matches, return true (or print that the number is a Fibonacci number).
//                                          : If the generated Fibonacci number exceeds the input number : We can stop the loop and return false, as we’ve passed the number and it doesn't exist in the Fibonacci sequence.
//          : Why This Works : Fibonacci numbers grow rapidly, so we don’t need many iterations. Since we're generating the sequence in order, we never miss any valid Fibonacci number.
//                           : This makes the approach reliable, intuitive, and a good starting point for beginners.
#include<iostream>
using namespace std;

bool CheckFibNum(int val) {
    if(val < 0) {
        cout<<"Invalid Position!";
        return -1;
    }
    int first = 0; int second = 1;
    while(first <= val) {
        int next = first + second;
        if(first == val) {
            return true;
        }
        first = second;
        second = next;
    }
    return false;
}

int main() {
    int n;
    cin>>n;
    if(CheckFibNum(n)) {
        cout<<"Yes its a fibonacci number!";
    }
    else {
        cout<<"Not its not a fibonacci number!";
    }
}
// Drawback : While this method is intuitive and can be developed through basic logic building, it isn't the most efficient. It involves looping through Fibonacci numbers until we reach or exceed the target number, which takes O(log n) time.
//          : However, there exists an alternate mathematical approach using a formula, which is not as intuitive but significantly more efficient. This formula-based method checks for perfect squares using the expressions 5n² + 4 or 5n² - 4 and operates in constant time O(1), making it far more optimal for larger values or performance-critical applications.

// Improved on Drawbacks!
// Concept : If the put the input number in the formula 5n² + 4 or 5n² - 4, and it turns out to be a perfect square! then the input number is a fibonacci number!
#include<iostream>
#include<math.h>
using namespace std;

bool checkPerfectSquare(int val) {
    int x = sqrt(val);
    return (x * x) == val;
}

bool checkFib(int n) {
    return checkPerfectSquare((5 * n * n) - 4) || checkPerfectSquare((5 * n * n) + 4);
}

int main() {
    int n;
    cin>>n;
    if(checkFib(n)) {
        cout<<"Its a Fibonacci Number!";
    }
    else {
        cout<<"Not a Fibonacci Number!";
    }
}

// Question 5 : Last digit of the nth Fibonacci number!
// Thinking : The input n is treated as the position in the Fibonacci sequence (not the index). That means : If n == 1, the Fibonacci number is 0. If n == 2, it's 1, and so on.
//          : We generate Fibonacci numbers iteratively up to the nth position and then return the last digit of the nth Fibonacci number using % 10.
//          : Possible optimizations : Currently, the modulo operation (% 10) is applied after the loop to get the last digit of the result.
//                                   : However, there's a smarter improvement : Apply % 10 during the calculation itself — when you compute the next Fibonacci number using : next = (first + second) % 10;
//                                   : This prevents the values from growing unnecessarily large, avoiding potential overflow and keeping the logic efficient.
//          : In Summary : Instead of calculating the full Fibonacci number and then extracting its last digit, It's better to keep only the last digits throughout the calculation by using modulo % 10 in every step. This keeps the numbers small and the program fast, especially for large n.
#include<iostream>
using namespace std;

int FibLastDigit(int n) {
    if(n <= 0) {
        cout<<"Invalid Position!";
        return -1;
    }
    if(n == 1) {
        return 0;
    }
    int first = 0; int second = 1;
    for(int i = 1; i < n; i++) {
        int next = first + second;
        first = second;
        second = next;
    }
    return first % 10;
}

int main() {
    int n;
    cin>>n;
    cout<<FibLastDigit(n);
}

// Question 6 : Print Fibonacci till value <= N
// Thinking : Previously, we generated Fibonacci numbers based on position (e.g., print first n terms or the nth term). Now, the task is to print all Fibonacci numbers whose values are strictly less than N.
//          : Core Idea : Instead of counting how many numbers we print (as in position-based), we keep printing until the value of the current Fibonacci number reaches or exceeds N.
//          : Initialization : Start with the first two Fibonacci numbers: first = 0, second = 1.
//          : Condition Update : Use a loop that continues as long as the current value being printed is < N.
//                             : This value can be either first, second, or next — depending on how you design your loop.
//                             : Most efficient way: print first in every iteration and update the next number accordingly.
//          : Printing Logic : Print the current value (e.g., first) only if it is less than N. Then compute the next Fibonacci number: next = first + second. Update first = second, second = next.
#include<iostream>
using namespace std;

void FibSeriesBasedOnValue(int n) {
    if(n < 0) {
        cout<<"No fibonacci value less than 0";
        return;
    }
    int first = 0; int second = 1;
    while(first <= n) {
        int next = first + second;
        cout<<first<<" ";
        first = second;
        second = next;
    }
    return;
}

int main() {
    int n;
    cin>>n;
    FibSeriesBasedOnValue(n);
}

// Question 7 : Print first n terms of fibonacci series in reverse!
// Thinking : We can use a vector to store the generated Fibonacci numbers one by one. Once all the n Fibonacci numbers are stored, we can simply print the vector in reverse order.
//          : The input asks for the number of terms of the Fibonacci series. This is a position-based input — meaning : If n = 1, output should be 0. and If n = 2, output should be 1 0. And so on.
//          : Note on Indexing : Fibonacci indexing can sometimes create confusion : Some define F(0) = 0, F(1) = 1 (0-based indexing), Others define F(1) = 0, F(2) = 1 (1-based positioning).
//                             : But since we are taking number of terms as input (not a specific index or value), it’s safe and clear to just start from 0 and generate n terms.
//          : Although position-based terminology can vary, for clean code and clarity, prefer to treat the input n strictly as the count of terms rather than relying on index semantics — especially in larger or more complex programs.
#include<iostream>
#include<vector>
using namespace std;

void reverseFib(int n) {
    if(n <= 0) {
        cout<<"Enter number of terms required!";
        return;
    }
    int zeroth = 0;
    int first = 1;
    vector<int> fib(n);
    for(int i = 0; i < n; i++) {
        int next = zeroth + first;
        fib[i] = zeroth;
        zeroth = first;
        first = next;
    }
    for(int i = n-1; i >= 0; i--) {
        cout<<fib[i]<<" ";
    }
    return;
}

int main() {
    int n;
    cin>>n;
    reverseFib(n);
}

// Question 8 : A) print all even Fibonacci numbers among the first n terms
//            : B) print all even Fibonacci numbers less than or equal to n
// Thinking : This is similar to the previous Fibonacci problems. We will keep generating Fibonacci numbers in the usual way! During generation, for each number (whether it's first, second, or next, depending on how you're iterating)
//          : We will : Check if the number is even using number % 2 == 0. If it’s even, we print it.
//                    : Otherwise, we simply continue generating the next Fibonacci numbers.
//          : We can set a limit on how many Fibonacci numbers to generate (e.g., first n terms or up to a maximum value like n).
//          : Make sure to decide whether you're generating based on : Position (count of terms) : e.g., print all even Fibonacci numbers among the first n terms, or
//                                                                   : Value (up to a maximum number) : e.g., print all even Fibonacci numbers less than or equal to n.
// A)
#include<iostream>
#include<vector>
using namespace std;

void FirstEvenFib1(int n) {
    if(n <= 0) {
        cout<<"Enter valid position!";
        return;
    }
    int first = 0; int second = 1;
    for(int i = 1; i <= n; i++) {
        int next = first + second;
        if(first%2 == 0) {
            cout<<first<<" ";
        }
        first = second;
        second = next;
    }
}

int main() {
    int n;
    cin>>n;
    FirstEvenFib1(n);
}

// B)
#include<iostream>
#include<vector>
using namespace std;

void FirstEvenFib2(int n) {
    if(n < 0) {
        cout<<"No Fibonacci value less than 0";
        return;
    }
    int first = 0; int second = 1;
    while(first <= n) {
        int next = first + second;
        if(first%2 == 0) {
            cout<<first<<" ";
        }
        first = second;
        second = next;
    }
}

int main() {
    int n;
    cin>>n;
    FirstEvenFib2(n);
}

// Question 9 : Find the first Fibonacci number with exactly k digits among the first n terms.
// Thinking : We will generate Fibonacci numbers using the first and second technique. During generation, we'll check the number of digits in the current Fibonacci number (first). As soon as we find a number with exactly k digits, we return it. If no such number is found within n terms (if limited), we return -1.
#include<iostream>
using namespace std;

int numDigits(int n) {
    if (n == 0) return 1; // Special case: 0 has 1 digit
    int count = 0;
    while (n != 0) {
        count++;
        n = n / 10;
    }
    return count;
}

int FirstKDigitsFib(int n, int k) {
    if (n <= 0) {
        cout << "Enter valid position!";
        return -1;
    }
    int first = 0, second = 1;
    for (int i = 1; i <= n; i++) {
        if (numDigits(first) == k) {
            return first;
        }
        int next = first + second;
        first = second;
        second = next;
    }
    return -1;
}

int main() {
    int n, k;
    cin >> n >> k;
    int result = FirstKDigitsFib(n, k);
    if (result != -1) {
        cout << result;
    }
    else {
        cout << "No Fibonacci number with " << k << " digits found in first " << n << " terms.";
    }
}

// Question 10 : Find how many Fibonacci numbers lie between a and b
// Thinking : Generate Fibonacci numbers starting from 0. For each number, check whether it lies within the range [a, b]. If it does, increment a counter. Stop generating when the number exceeds b, and return the final count.
#include<iostream>
#include<vector>
using namespace std;

int FibBetweenAandB(int lowerB, int upperB) {
    int first = 0; int second = 1;
    int count = 0;
    bool oneCounted = false;
    while(first <= upperB) {
        if(first >= lowerB) {
            if (first == 1 && oneCounted) {
                // Skip duplicate '1'
            }
            else {
                count++;
                if (first == 1) oneCounted = true;
            }
        }
        int next = first + second;
        first = second;
        second = next;
    }
    return count;
}

int main() {
    int lowerB, upperB;
    cin>>lowerB>>upperB;
    cout<<FibBetweenAandB(min(lowerB, upperB), max(lowerB, upperB));
}