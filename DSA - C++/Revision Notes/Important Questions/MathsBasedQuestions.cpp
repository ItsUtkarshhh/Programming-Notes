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
// Thinking : First we need to analyse how actually a complement of an integer works (Its not how a number is stored in the memory its simple complement)! suppose a number 5 and you want its complement (~5), so first we will write it in binary form : 00000000 00000000 00000000 00000101.
//          : Then, its complement will be : 111111111 111111111 111111111 111111010 (which is also a complement), but by complement we mean 010, so to obtain this we need to eliminate all the 1's, for that we will use a bitwise "&" operator
//          : What we will do we will simply use "&0" with all the 1's and "&1" with the number we want! so first we need to create a number/mask which will we will apply & with!
#include<iostream>
using namespace std;

int main() {
    int num;
    cin>>num;
    int val = num;
    int count = 0;
    int mask = 0;
    while(val != 0) {
        mask = (mask << 1) | 1;
        val = val >> 1;
    }
    cout<<((~num) & (val));
}