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

// --------------------------------------------------------- Part 2 : LCM/HCF Based Questions! ----------------------------------------------------------------->
// Question 1 : Find Greatest Common Divisor (GCD)/ Highest Common Factor (HCF) of two numbers!
// Thinking : The Greatest Common Divisor (GCD) or Highest Common Factor (HCF) of two numbers is the largest number that divides both numbers without leaving a remainder.
//          : To find the GCD, we know that it cannot be greater than the smaller of the two numbers, otherwise it wont be able to divide one of them or both of them. So, we first find the minimum of the two input numbers.
//          : Then, we start checking from that number down to 1. For each number in this decreasing loop, we check if it divides both numbers exactly (i.e., remainder is 0).
//          : As soon as we find such a number, we break the loop and return it as the GCD.
//          : Note : This is a brute-force approach and works fine for small numbers. However, for larger numbers, a more efficient method is the Euclidean algorithm.
#include<iostream>
using namespace std;

int main() {
    int n1, n2;
    cin>>n1>>n2;
    int potentialDiv = min(n1, n2);
    int finalDiv = -1;
    while(potentialDiv > 0) {
        if(n1 % potentialDiv == 0 && n2 % potentialDiv == 0) {
            finalDiv = potentialDiv;
            break;
        }
        potentialDiv--;
    }
    cout<<finalDiv<<endl;
}

// Better Approach : Euclidean Algorithm : The Euclidean Algorithm efficiently finds the GCD (Greatest Common Divisor) of two numbers using the division method.
//                 : In the long division method, we work with two numbers : the dividend and the divisor. We repeatedly divide the dividend by the divisor and take the remainder. Then we replace : The dividend with the current divisor. The divisor with the current remainder.
//                                                                         : This process continues until the remainder becomes 0. At that point, the current divisor is the GCD of the original two numbers.
//                 : Note: There's no need to manually find the minimum of the two numbers at the beginning, because the modulo operator (%) naturally adjusts for it.
//                 : Another approach can be recursion also, but will go through it later once we reach there!
#include<iostream>
using namespace std;

int main() {
    int n1, n2;
    cin>>n1>>n2;
    while(n2 != 0) {
        int temp = n2;
        n2 = n1 % n2;
        n1 = temp;
    }
    cout<<n1;
}

// Question 2 : Find Least Common Multiple (LCM) of two numbers!
// Thinking : We can solve this in two ways : Method 1 : Using the formula with GCD (Euclidean Algorithm)
//                                                     : First, calculate the GCD (Greatest Common Divisor) of the two numbers. Then use the formula: LCM = (a * b) / GCD. This method is efficient and widely used.
//                                          : Method 2 : Brute-force approach using LCM logic
//                                                     : The LCM is the smallest number that is a multiple of both given numbers. It must be divisible by both numbers without leaving a remainder. Start checking from max(a, b) (since LCM cannot be smaller than this). In each iteration, increment the number by 1 and check divisibility.The first number that is divisible by both is the LCM.
//          : Note : The first method is preferred for performance. The second method is conceptually simple and helps understand the meaning of LCM. Make sure to handle edge cases like zero or negative input gracefully.
#include<iostream>
using namespace std;

int main() {
    int n1, n2;
    cin>>n1>>n2;
    int potentialLCM = max(n1, n2);
    int finalLCM = -1;
    while(true) {
        if(potentialLCM % n1 == 0 && potentialLCM % n2 == 0) {
            finalLCM = potentialLCM;
            break;
        }
        potentialLCM++;
    }
    cout<<finalLCM;
}

// --------------------------------------------------------- Part 3 : Mathematical Questions and Bit Manipulation! ----------------------------------------------------------------->
// Question 1 : Subtract the product and sum of all the digits of an Integer!
// Thinking : We can do it without creating function and also with functions, and creating function will increase the code readability so we will use it!
//          : One function to find the sum of all the digits of the number and one to find the product of all the digits of the number! and then simply call them and subtract them!
#include<iostream>
using namespace std;

int sumofNum(int n) {
    int sum = 0;
    while(n != 0) {
        int digits = n % 10;
        sum = sum + digits;
        n = n / 10;
    }
    return sum;
}

int prodofNum(int n) {
    int prod = 1;
    while(n != 0) {
        int digits = n % 10;
        prod = prod * digits;
        n = n / 10;
    }
    return prod;
}

int main() {
    int num;
    cin>>num;
    int sum = sumofNum(num);
    int prod = prodofNum(num);
    cout<<"Final Answer : "<<max(sum, prod) - min(sum, prod)<<endl;
}

// Question 2 : Number of 1 Bits, find the number of 1 bits in the unsigned integer input by the user!
// Thinking : Every number in memory is stored in binary (0s and 1s). So, the task is to go through each bit and count how many are set to 1
//          : To work at the bit level, we need : & (bitwise AND): Used to check whether the least significant bit (LSB) is 1 or 0. >> (right shift): Used to move to the next bit by discarding the current LSB.
//          : Initialize a counter variable (e.g. count = 0).
//          : Loop until the number becomes 0 : Perform n & 1 : If result is 1, it means the current bit is set → increment count. If result is 0, do nothing.
//                                            : Perform n = n >> 1 to shift all bits right by 1, removing the current bit.
//          : Repeat the process until all bits are checked. Output the final count.
#include<iostream>
using namespace std;

int main() {
    int num;
    cin>>num;
    int val = num;
    int count = 0;
    while(val != 0) {
        if(val & 1) {
            count++
        }
        val = val >> 1;
    }
    cout<<count;
}

// Question 3 : Decimal to Binary Conversion!
// Thinking : We have two approaches to solve this...
//          : Approach 1 : Every number in binary is represented as a sum of powers of 2 (like 1, 2, 4, 8...).
//                       : When you divide a number by 2 : The remainder is either 0 or 1. -> This remainder is the current least significant bit (LSB). -> Keep dividing by 2 and storing the remainders until the number becomes 0. -> Reverse the stored remainders to get the binary number.
//                       : We will extract digits using "n % 2" and will form a number using those extracted digits and then finally will reverse it! But in our case we can use a formula which takes the extracted digits and will reverse it step by step on its own!
//          : Approach 2 : At bit level, we can extract the last bit using n & 1 : If n is odd → n & 1 = 1 , If n is even → n & 1 = 0
//                       : Then shift the bits to the right using n >> 1 to remove the last bit.
// Approach 1 :
#include<iostream>
#include<math.h>
using namespace std;

int main() {
    int num;
    cin>>num;
    int ans = 0;
    int i = 0;
    while(num != 0) {
        int lsb = num % 2;
        ans = (ceil(pow(10,i++)) * lsb) + ans;
        num = num / 2;
    }
    cout<<ans;
}

// Approach 2 :
#include<iostream>
#include<math.h>
using namespace std;

int main() {
    int num;
    cin>>num;
    int ans = 0;
    int i = 0;
    while(num != 0) {
        int lsb = num & 1;
        ans = (ceil(pow(10,i++)) * lsb) + ans;
        num = num >> 1;
    }
    cout<<ans;
}

// Question 4 : Print all 32-bits of a binary number! (also applicable for converting a -ve number into a binary!)
// Thinking : We know how the numbers are stored in memory in 32 bits format! so we will simply print all the bits starting the MSB (leftmost bit) for that we need to start right shift the bit representation of the number 31 times towards right and then & it with 1 to get the bit at that place!
//          : And then starting i with 31 we will decrease it one by one! to print all the bits till LSB.
#include<iostream>
using namespace std;

int main() {
    int32_t num;
    cin>>num;
    for(int i = (sizeof(num)*8) - 1; i >= 0; i--) {
        cout<<((num >> i) & 1);
    }
}

// Question 5 : Binary to Decimal Conversion!
// Thinking : To convert binary to decimal, we utilize the fact that each bit in a binary number represents a power of 2, starting from the right (least significant bit). So, we take the binary number as input (typically in integer form), and in each step, extract the last digit using % 10. This digit (which is either 0 or 1) is then multiplied by 2^power, where power starts from 0 and increases with each digit processed.
//          : We keep adding these values to a running total (ans). The number is then updated using / 10 to remove the last digit, and the process continues until the number becomes 0. This way, each binary digit is correctly converted and added to form the equivalent decimal number.
#include<iostream>
#include<math.h>
using namespace std;

int main() {
    int num;
    cin>>num;
    int ans = 0;
    int i = 0;
    while(num != 0) {
        int digit = num % 10;
        ans = (ceil(pow(2,i++)) * digit) + ans;
        num = num / 10;
    }
    cout<<ans;
}

// Thinking 2 : Here, we will learn a new technique...
//            : In any number system (binary, decimal, etc.), numbers are constructed using place values, where each position represents a power of the base. In decimal (base 10), it's powers of 10. In binary (base 2), it's powers of 2.
//            : In decimal : For example, the number 347 is calculated as 3×100 + 4×10 + 7×1.
//                         : But we can build it iteratively like : 0 * 10 + 3 = 3, → 3 * 10 + 4 = 34, → 34 * 10 + 7 = 347.
//            : Similarly, in binary : Let’s say the binary string is 1011 → we process from left to right :
//                                   : 0 * 2 + 1 = 1, → 1 * 2 + 0 = 2, → 2 * 2 + 1 = 5, → 5 * 2 + 1 = 11.
//            : So, this method takes each digit (or bit), multiplies the result so far by the base (2 or 10), and adds the current digit — this is equivalent to how we build numbers using positional values.
//            : This works because multiplying by the base shifts digits left in their place value, and adding the digit inserts the current one at the lowest place. It mirrors how our brain naturally builds numbers in everyday decimal usage.
//            : It avoids using pow() or precomputing powers like 2^0, 2^1,..., making it more efficient and cleaner, especially in programming logic.
#include<iostream>
#include<string>
using namespace std;

int main() {
    string num;
    cin>>num;
    int res = 0;
    for(char bit : num) {
        res = res * 2 + (bit - '0');
    }
    cout<<res;
}

// Question 6 : Reverse an Integer! but if it goes out of the range of int them print 0!
// Thinking : Its same as like you first extract the last digit from the number and then you combine them using a formula ans = (10 * ans) + digit.
//          : As this formula merges the number in the order it was extracted and we can get our final answer!
//          :  Just one thing that we need to add a check of "ans * 10 > INT_MAX || ans * 10 < INT_MIN" so that it can simply print 0 in overflow condition! 
#include<iostream>
#include<climits>
using namespace std;

int main() {
    int num;
    cin>>num;
    int ans = 0;
    while(num != 0) {
        int digit = num % 10;
        if(ans * 10 > INT_MAX || ans * 10 < INT_MIN) {
            cout<<0;
        }
        ans = (10 * ans) + digit;
        num = num / 10;
    }
    cout<<ans;
}

// Question 7 : Complement of an Integer!
// Concept : First, let's understand complement! A complement simply means flipping the digits: if 0 then 1, and if 1 then 0.
//         : Now, if we are asked for the complement, why can't we just do cout << ~5; and get it done? The problem is, when we say "complement of an integer", we mean ~5 (which is 101) should give us 2 (which is 010). But if we simply do cout << ~5; (where 5 is 101), it prints -6 (which is 110).
//         : The reason is: we need to think in 32-bit format, as that's the format in which any number is stored in memory.
//         : Let's understand it : We can either store and print the stored number, or we can just perform operations and print directly using cout.
//                               : In the first case : If the number is positive, it simply gets converted into the 32-bit binary representation of that decimal number. While printing, it gets converted back into decimal and is printed as is.
//                                                   : If the number is negative, it goes through a process of complements : First, a 1's complement is applied (flipping all 32 bits), then 1 is added to make it a 2's complement. This new binary (with MSB = 1) is stored, indicating it's a negative number.
//                                                   : While printing, the compiler checks the MSB. If it's 0, the number is printed directly. If it's 1, it's interpreted as a negative number and is printed after applying two’s complement logic.
//                               : In the second case : If we are not storing any number and are just doing operations and printing, the final bit pattern is again checked. If the MSB is 0, it's printed directly. If MSB is 1, then again, two’s complement logic is used and the output is a negative number.
//         : In such problems, "complement of an integer" means flipping only the meaningful bits (the bits used to represent the number), not the full 32-bit computational form.
//         : That’s why we can’t use ~5 directly — we need to handle the number carefully to get the mathematical complement, not the computational (bitwise) one.
// Thinking : We take a number num as input. We want the mathematical complement (only the relevant bits flipped). Simply doing ~num flips all 32 bits → unwanted result.
//          : So we create a mask that has 1s only where num has meaningful bits. We then do ~num & mask → gives us only the flipped part of original number. Return the result and print it.
#include<iostream>
using namespace std;

int complementOfInteger(int num) {
    int val = num;
    int mask = 0;
    while(val != 0) {
        mask = (mask << 1) | 1;
        val = val >> 1;
    }
    return (mask & (~num));
}

int main() {
    int num;
    cin>>num;
    cout<<"Complement of num : "<<complementOfInteger(num);
}

// Question 8 : Power of 2, display yes if a number can be represented in form of power of 2, and if no then print no!
// Thinking : Take input of the number num. Initialize a variable powerOf2 = 1 to represent 2^0. Use a loop to multiply powerOf2 by 2 in each iteration.
//          : At every step : If powerOf2 == num, then it's a power of 2 → print "Yes" and stop.
//                          : If powerOf2 > num, then num is not a power of 2 → print "No" and stop.
//                          : Continue until either condition is met.
#include<iostream>
using namespace std;

void checkPowerOf2(int num) {
    int powerOf2 = 1;
    while(powerOf2 <= num) {
        if(powerOf2 == num) {
            cout<<"Yes "<<num<<" is a power of 2";
            return;
        }
        powerOf2 *= 2;
    }
    cout<<"No "<<num<<" is not a power of 2";
    return;
}

int main() {
    int num;
    cin>>num;
    checkPowerOf2(num);
}

// Thinking 2 : A number is a power of 2 if it has exactly one 1 in its binary representation. Examples : 1 → 01, 2 → 10, 4 → 100, 8 → 1000 and so on. So, we count how many 1s are present in the binary form of the number. If only one 1, then it's a power of 2. Otherwise, it's not.
//            : Take input num. Create a variable val = num to process. Use a loop to right shift val until it becomes 0. In each iteration, use (val & 1) to check if the last bit is 1. If yes, increment countOf1bit. After the loop, if countOf1bit == 1, it's a power of 2, else not.
#include<iostream>
using namespace std;

void checkPowerOf2(int num) {
    int countOf1bit = 0;
    int val = num;
    while(val != 0) {
        if((val & 1) == 1) {
            countOf1bit++;
        }
        val = val >> 1;
    }
    if(countOf1bit == 1) {
        cout<<"Yes "<<num<<" is a power of 2";
        return;
    }
    cout<<"No "<<num<<" is not a power of 2";
    return;   
}

int main() {
    int num;
    cin>>num;
    checkPowerOf2(num);
}

// Thinking 3 : Binary Counting and Bit Flipping Observation : While counting in binary, each new number is formed by flipping the rightmost bits starting from 0.
//                                                           : 0 (0000), 1 (0001), 2 (0010), 3 (0011), 4 (0100), 5 (0101), 6 (0110), 7 (0111), 8 (1000), 9 (1001), 10 (1010) and so on... You can see the rightmost bits flipping to generate the next number.
//            : Property of Powers of 2 : In binary, every power of 2 has only one 1 bit, and all other bits are 0. Like : 1 (0001), 2 (0010), 4 (0100), 8 (1000), 16 (10000) and so on...
//                                      : So, for any power of 2, if you do : "n & (n - 1)" it will always be 0. Because, Subtracting 1 from a power of 2 flips the only set bit and sets all bits to 1 after it. Doing AND clears all bits → result is 0.
//                                      : Example : 8 (1000) & 7 (0111) = 0000, 4 (100) & 3 (011) = 000 and similary for others! So we will use the same logic to check if the number is a power of or not!
#include<iostream>
using namespace std;

bool checkPowerOf2(int num) {
    return num > 0 && (num & (num - 1)) == 0;
}

int main() {
    int num;
    cin>>num;
    if(checkPowerOf2(num)) {
        cout<<"Yes "<<num<<" is a power of 2";
    }
    else {
        cout<<"No "<<num<<" is not a power of 2";
    }
}
// Key Insight (Not relevant to question) : The bitwise NOT operator ~ in C++ inverts all the bits of a number. This means every 1 becomes 0 and every 0 becomes 1. However, the final result also depends on how integers are stored in memory, specifically two's complement representation.
//                                        : Mathematical Intuition (High-Level) : When you apply bitwise NOT to a power of 2, you often get : ~(2^n) = -(2^n - 1). Examples : 	~8 = -7, ~4 = -3, ~2 = -1, ~1 = -2.
//                                        : Computational Perspective (Two's Complement) : In C++, integers are stored in two’s complement form, which causes this pattern : ~(2^n) = -(2^n) - 1. Examples : ~8 = -9, ~4 = -5, ~2 = -3, ~1 = -2.
//                                        : Special Case : ~1, as ~1 = -2 (in full bit width). The uniqueness lies in how small the number is : If you consider only 1 bit, ~1 would technically be 0 (since 1 becomes 0). But in real systems, integers are stored in at least 8, 16, 32, or 64 bits, so the actual NOT operation flips all bits, not just one.

// Question 9 : Power of 3, display yes if a number can be represented in form of power of 3, and if no then print no!
// Thinking : Same logic as of powerOf2 will be applied in this problem also! Just replace the calculation from 2 to 3.
#include<iostream>
using namespace std;

void checkPowerOf3(int num) {
    int powerOf3 = 1;
    while(powerOf3 <= num) {
        if(powerOf3 == num) {
            cout<<"Yes "<<num<<" is a power of 3";
            return;
        }
        powerOf3 *= 3;
    }
    cout<<"No "<<num<<" is not a power of 3";
    return;
}

int main() {
    int num;
    cin>>num;
    checkPowerOf3(num);
}

// Question 10 : Power of 4, display yes if a number can be represented in form of power of 4, and if no then print no!
// Thinking : Same logic as of powerOf2 will be applied in this problem also! Just replace the calculation from 3 to 4.
#include<iostream>
using namespace std;

void checkPowerOf4(int num) {
    int powerOf4 = 1;
    while(powerOf4 <= num) {
        if(powerOf4 == num) {
            cout<<"Yes "<<num<<" is a power of 4";
            return;
        }
        powerOf4 *= 4;
    }
    cout<<"No "<<num<<" is not a power of 4";
    return;
}

int main() {
    int num;
    cin>>num;
    checkPowerOf4(num);
}