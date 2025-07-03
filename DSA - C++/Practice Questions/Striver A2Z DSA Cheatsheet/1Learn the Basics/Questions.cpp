// --------------------------------------------------------------- Lec 2 : Patterns ---------------------------------------------------------------------------------------------------------------------------------------------->
// Pattern 1 : * * * * *
//           : * * * * *
//           : * * * * *
//           : * * * * *
//           : * * * * *
#include<iostream>
using namespace std;

int main() {
    int n;
    cin>>n;
    for(int i = 1; i<=n; i++) {
        for(int j = 1; j<=n; j++) {
            cout<<"*"<<" ";
        }
        cout<<endl;
    }
}

// Pattern 2 : *
//           : * *
//           : * * *
//           : * * * *
//           : * * * * *
#include<iostream>
using namespace std;

int main() {
    int n;
    cin>>n;
    for(int i = 1; i<=n; i++) {
        for(int j = 1; j<=i; j++) {
            cout<<"*"<<" ";
        }
        cout<<endl;
    }
}

// Pattern 3 : 1
//           : 1 2
//           : 1 2 3
//           : 1 2 3 4
//           : 1 2 3 4 5
#include<iostream>
using namespace std;

int main() {
    int n;
    cin>>n;
    for(int i = 1; i<=n; i++) {
        for(int j = 1; j<=i; j++) {
            cout<<j<<" ";
        }
        cout<<endl;
    }
}

// Pattern 4 : 1
//           : 2 2
//           : 3 3 3
//           : 4 4 4 4
//           : 5 5 5 5 5
#include<iostream>
using namespace std;

int main() {
    int n;
    cin>>n;
    for(int i = 1; i<=n; i++) {
        for(int j = 1; j<=i; j++) {
            cout<<i<<" ";
        }
        cout<<endl;
    }
}

// Pattern 5 : * * * * *
//           : * * * *
//           : * * *
//           : * *
//           : *
#include<iostream>
using namespace std;

int main() {
    int n;
    cin>>n;
    for(int i = 1; i<=n; i++) {
        for(int j = 1; j<=n+1-i; j++) {
            cout<<"*"<<" ";
        }
        cout<<endl;
    }
}

// Pattern 6 : 1 2 3 4 5
//           : 1 2 3 4
//           : 1 2 3
//           : 1 2
//           : 1
#include<iostream>
using namespace std;

int main() {
    int n;
    cin>>n;
    for(int i = 1; i<=n; i++) {
        for(int j = 1; j<=n+1-i; j++) {
            cout<<j<<" ";
        }
        cout<<endl;
    }
}

// Pattern 7 : 1
//           : 2 3
//           : 4 5 6
//           : 7 8 9 10
//           : 11 12 13 14 15
#include<iostream>
using namespace std;

int main() {
    int n;
    cin>>n;
    int count = 1;
    for(int i = 1; i<=n; i++) {
        for(int j = 1; j<=i; j++) {
            cout<<count<<" ";
            count++;
        }
        cout<<endl;
    }
}

// Pattern 8 : A
//           : A B
//           : A B C
//           : A B C D
//           : A B C D E
#include<iostream>
using namespace std;

int main() {
    int n;
    cin>>n;
    for(int i = 1; i<=n; i++) {
        for(int j = 0; j<i; j++) {
            cout<<char('A'+j)<<" ";
        }
        cout<<endl;
    }
}

// Pattern 9 : A B C D E
//           : A B C D
//           : A B C
//           : A B
//           : A
#include<iostream>
using namespace std;

int main() {
    int n;
    cin>>n;
    for(int i = 1; i<=n; i++) {
        for(int j = 0; j<=(n-i); j++) {
            cout<<char('A'+j)<<" ";
        }
        cout<<endl;
    }
}

// Pattern 10 : A
//            : B B
//            : C C C
//            : D D D D
//            : E E E E E
#include<iostream>
using namespace std;

int main() {
    int n;
    cin>>n;
    for(int i = 0; i<n; i++) {
        for(int j = 0; j<=i; j++) {
            cout<<char('A'+i)<<" ";
        }
        cout<<endl;
    }
}

// Pattern 11 : E
//            : D E
//            : C D E
//            : B C D E
//            : A B C D E
#include<iostream>
using namespace std;

int main() {
    int n;
    cin>>n;
    for(int i = 1; i<=n; i++) {
        char ch = 'A'+(n-i);
        for(int j = 1; j<=i; j++) {
            cout<<ch<<" ";
            ch++;
        }
        cout<<endl;
    }
}

// Pattern 12 :         *
//            :       * * *
//            :     * * * * *
//            :   * * * * * * *
//            : * * * * * * * * *
// Thought Process : To solve any pattern-related question in programming, the first step is to understand the relationship between rows and columns. But for pyramid patterns, things are a bit special — you need to understand three important components : Rows (Size), Spaces & Stars
//                 : Star Logic : In a pyramid pattern, stars are printed in the center of each row and their count increases as we go down.
//                              : One common observation is : Number of stars in any row "i" is = (2 * i) - 1. This means the number of stars depends only on the row number, not on the total size n.
//                 : Space Logic : Before the stars, we print spaces to push the stars to the center, creating the pyramid shape. The spaces depend on both the current row number i and the total number of rows n. Two simple ways to calculate spaces...
//                               : Method 1 : Spaces in row "i" : n - i
//                                          : This is the easiest and most intuitive — as the row increases, the number of leading spaces decreases.
//                               : Method 2 (alternative perspective) : Spaces in row "i" : (2 * (n - i + 1)) - 2)/2 (which is eqla to "n - i" but okay nvm)
//                                                                    : This formula comes from total characters in a line and evenly splitting the remaining spaces. But this is more complex — use only if needed.
#include<iostream>
using namespace std;

int main() {
    int n;
    cin>>n;
    for(int i = 1; i<=n; i++) {
        for(int space = 0; space<n-i; space++) {
            cout<<" "<<" ";
        }

        for(int j = 1; j<=(2*i)-1; j++) {
            cout<<"*"<<" ";
        }

        for(int space = 0; space<n-i; space++) {
            cout<<" "<<" ";
        }
        cout<<endl;
    }
}

// Pattern 13 : * * * * * * * * *
//            :   * * * * * * *
//            :     * * * * *
//            :       * * *
//            :         *
// Thought Process : Its mostly similar to previous logic, just in reverse!
#include<iostream>
using namespace std;

int main() {
    int n;
    cin>>n;
    for(int i = n; i>=1; i--) {
        for(int space = 0; space<n-i; space++) {
            cout<<" "<<" ";
        }

        for(int j = (2*i)-1; j>=1; j--) {
            cout<<"*"<<" ";
        }

        for(int space = 0; space<n-i; space++) {
            cout<<" "<<" ";
        }
        cout<<endl;
    }
}

// Alternate Approach! As this time stars are depending upon both "n & i" but spaces are only depending upon "i".
#include<iostream>
using namespace std;

int main() {
    int nr;
    cin>>nr;
    for(int i = 1; i <= nr; i++) {
        int spaces = i - 1;
        while(spaces) {
            cout<<" "<<" ";
            spaces--;
        }

        int stars = 2*nr - (2*i - 1);
        while(stars) {
            cout<<"*"<<" ";
            stars--;
        }

        spaces = i - 1;
        while(spaces) {
            cout<<" "<<" ";
            spaces--;
        }
        cout<<endl;
    }
}

// Pattern 14 :         *
//            :       * * *
//            :     * * * * *
//            :   * * * * * * *
//            : * * * * * * * * *
//            : * * * * * * * * *
//            :   * * * * * * *
//            :     * * * * *
//            :       * * *
//            :         *
// // Thought Process : Here again you can just simply combine the logic of inverted & non-inverted pyramids!
#include<iostream>
using namespace std;

int main() {
    int n;
    cin>>n;
    for(int i = 1; i<=n; i++) {
        for(int space = 0; space<n-i; space++) {
            cout<<" "<<" ";
        }

        for(int j = 1; j<=(2*i)-1; j++) {
            cout<<"*"<<" ";
        }

        for(int space = 0; space<n-i; space++) {
            cout<<" "<<" ";
        }
        cout<<endl;
    }
    for(int i = n; i>=1; i--) {
        for(int space = 0; space<n-i; space++) {
            cout<<" "<<" ";
        }

        for(int j = (2*i)-1; j>=1; j--) {
            cout<<"*"<<" ";
        }

        for(int space = 0; space<n-i; space++) {
            cout<<" "<<" ";
        }
        cout<<endl;
    }
}

// Pattern 15 : *
//            : * *
//            : * * *
//            : * * * *
//            : * * *
//            : * *
//            : *
// Thought Process : Here, what we can simply do is, just use the combination of previous patterns and modify them according to the output rows!
#include<iostream>
using namespace std;

int main() {
    int n;
    cout<<"Enter an odd number : ";
    cin>>n;
    for(int i = 1; i <= n; i++) {
        if(i < (n/2 + 1)) {
            for(int j = 1; j <= i; j++) {
                cout<<"*"<<" ";
            }
            cout<<endl;
        }
        else {
            for(int j = 1; j <= (n - i + 1); j++) {
                cout<<"*"<<" ";
            }
            cout<<endl;
        }
    }
}

#include<iostream>
using namespace std;

int main() {
    int n;
    cin>>n;
    for(int i = 1; 2*i <= n; i++) {
        for(int j = 1; j <= i; j++) {
            cout<<"*"<<" ";
        }
        cout<<endl;
    }
    for(int i = n - 1; i >= 1; i--) {
        for(int j = i; j >= 1; j--) {
            cout<<"*"<<" ";
        }
        cout<<endl;
    }
}

#include<iostream>
using namespace std;

int main() {
    int n;
    cin>>n;
    for(int i = 1; i<=n; i++) {
        for(int j = 1; j<=i; j++) {
            cout<<"*"<<" ";
        }
        cout<<endl;
    }
    for(int i = 1; i<=n; i++) {
        for(int j = 1; j<=(n-i); j++) {
            cout<<"*"<<" ";
        }
        cout<<endl;
    }    
}

// Pattern 16 : 1
//            : 0 1
//            : 1 0 1
//            : 0 1 0 1
//            : 1 0 1 0 1
#include<iostream>
using namespace std;

int main() {
    int n;
    cin>>n;
    for(int i = 1; i<=n; i++) {
        if(i%2 != 0) {
            int start = 1;
            for(int j = 1; j<=i; j++) {
                cout<<start<<" ";
                start = 1 - start;
            }
        }
        if(i%2 == 0) {
            int start = 0;
            for(int j = 1; j<=i; j++) {
                cout<<start<<" ";
                start = 1 - start;
            }
        }
        cout<<endl;
    }
}

// Pattern 17 : 1                 1
//            : 1 2             2 1
//            : 1 2 3         3 2 1
//            : 1 2 3 4     4 3 2 1
//            : 1 2 3 4 5 5 4 3 2 1
#include<iostream>
using namespace std;

int main() {
    int n;
    cin>>n;
    for(int i = 1; i<=n; i++) {
        int num = 1;
        while(num <= i) {
            cout<<num<<" ";
            num++;
        }

        int spaces = 2*(n - i);
        while(spaces) {
            cout<<" "<<" ";
            spaces--;
        } 

        num = i;
        while(num >= 1) {
            cout<<num<<" ";
            num--;
        }
        cout<<endl;
    }
}

#include<iostream>
using namespace std;

int main() {
    int n;
    cin>>n;
    for(int i = 1; i<=n; i++) {
        for(int j = 1; j<=i; j++) {
            cout<<j<<" ";
        }
        int space = 2*n - 2*i;
        while(space) {
            cout<<" "<<" ";
            space = space - 1;
        }
        for(int j = i; j>=1; j--) {
            cout<<j<<" ";
        }
        cout<<endl;
    }
}

// Pattern 18 : _ _ _ A _ _ _
//            : _ _ A B A _ _
//            : _ A B C B A _
//            : A B C D C B A
#include<iostream>
using namespace std;

int main() {
    int n;
    cin>>n;
    for(int i = 1; i <= n; i++) {
        int spaces = n - i;
        while(spaces) {
            cout<<" "<<" ";
            spaces--;
        }

        char ch = 'A';
        for(int j = 0; j <= (2*i - 1)/2; j++) {
            cout<<ch<<" ";
            ch++;
        }

        ch = 'A' + i - 2;
        for(int j = 0; j < i-1; j++) {
            cout<<ch<<" ";
            ch--;
        }

        spaces = n - i;
        while(spaces) {
            cout<<" "<<" ";
            spaces--;
        }
        cout<<endl;
    }
}

#include<iostream>
using namespace std;

int main() {
    int n;
    cin>>n;
    for(int i = 1; i<=n; i++) {
        int space = n-i;
        while(space) {
            cout<<" "<<" ";
            space--;
        }

        char ch = 'A';
        for(int j = 1; j<=(2*i)-1; j++) {
            cout<<ch<<" ";
            if(j <= i-1) ch++;
            else ch--;
        }

        space = n-i;
        while(space) {
            cout<<" "<<" ";
            space--;
        }
        cout<<endl;
    }
}

// Pattern 19 : * * * * * * * * * * 
//            : * * * *     * * * * 
//            : * * *         * * * 
//            : * *             * * 
//            : *                 * 
//            : *                 * 
//            : * *             * * 
//            : * * *         * * * 
//            : * * * *     * * * * 
//            : * * * * * * * * * *
#include<iostream>
using namespace std;

int main() {
    int n;
    cin>>n;
    for(int i = 1; i<=n; i++) {
        for(int star = 0; star<=n-i; star++) {
            cout<<"*"<<" ";
        }

        for(int space = 1; space<(2*i)-1; space++) {
            cout<<" "<<" ";
        }

        for(int star = 0; star<=n-i; star++) {
            cout<<"*"<<" ";
        }
        cout<<endl;
    }
    for(int i = n; i>=1; i--) {
        for(int star = 0; star<=n-i; star++) {
            cout<<"*"<<" ";
        }

        for(int space = (2*i)-1; space>1; space--) {
            cout<<" "<<" ";
        }

        for(int star = 0; star<=n-i; star++) {
            cout<<"*"<<" ";
        }
        cout<<endl;
    }
}

// Pattern 20 : *                 *
//            : * *             * *
//            : * * *         * * *
//            : * * * *     * * * *
//            : * * * * * * * * * *
//            : * * * *     * * * *
//            : * * *         * * *
//            : * *             * *
//            : *                 *
#include<iostream>
using namespace std;

int main() {
    int n;
    cin>>n;
    for(int i = 1; i<=n; i++) {
        int star = i;
        while(star) {
            cout<<"*"<<" ";
            star--;
        }

        int space = (2*n) - (2*i);
        while(space) {
            cout<<" "<<" ";
            space--;
        }

        star = i;
        while(star) {
            cout<<"*"<<" ";
            star--;
        }
        cout<<endl;
    }
    for(int i = 0; i<n; i++) {
        int star = (n-i)-1;
        while(star) {
            cout<<"*"<<" ";
            star--;
        }

        int space = 2*i+2;
        while(space) {
            cout<<" "<<" ";
            space--;
        }

        star = (n-i)-1;
        while(star) {
            cout<<"*"<<" ";
            star--;
        }
        cout<<endl;
    }
}

// Pattern 21 : * * * *
//            : *     *
//            : *     *
//            : * * * *
#include<iostream>
using namespace std;

int main() {
    int n;
    cin>>n;
    for(int i = 1; i<=n; i++) {
        if(i == 1) {
            int stars = n;
            while(stars) {
                cout<<"*"<<" ";
                stars--;
            }
        }

        if(i > 1 && i < n) {
            cout<<"*"<<" ";
            int spaces = n - 2;
            while(spaces) {
                cout<<" "<<" ";
                spaces--;
            }
            cout<<"*"<<" ";
        }

        if(i == n) {
            int stars = n;
            while(stars) {
                cout<<"*"<<" ";
                stars--;
            }
        }
        cout<<endl;
    }
}

// Better Approach!
#include<iostream>
using namespace std;

int main() {
    int n;
    cin>>n;
    for(int i = 1; i<=n; i++) {
        for(int j = 1; j<=n; j++) {
            if(i == 1 || i == n || j == 1 || j == n) {
                cout<<"*"<<" ";
            }
            else cout<<" "<<" ";
        }
        cout<<endl;
    }
}

// Pattern 22 : 5 5 5 5 5 5 5 5 5
//            : 5 4 4 4 4 4 4 4 5 
//            : 5 4 3 3 3 3 3 4 5 
//            : 5 4 3 2 2 2 3 4 5 
//            : 5 4 3 2 1 2 3 4 5 
//            : 5 4 3 2 2 2 3 4 5 
//            : 5 4 3 3 3 3 3 4 5 
//            : 5 4 4 4 4 4 4 4 5 
//            : 5 5 5 5 5 5 5 5 5
#include<iostream>
using namespace std;

int main() {
    int n;
    cin>>n;
    for(int i = 0; i<(2*n-1); i++) {
        for(int j = 0; j<(2*n-1); j++) {
            int top = i;
            int left = j;
            int bottom = (2*n - 2) - i;
            int right = (2*n - 2) - j;
            cout<<(n - min(min(top,bottom), min(right,left)))<<" ";
        }
        cout<<endl;
    }
} // Re-solve this again, after sometime!

// Extra Patterns :
// Pattern 23 : ___*___
//            : __*_*__
//            : _*_*_*_
//            : *_*_*_*
#include<iostream>
using namespace std;

int main() {
    int n;
    cin>>n;
    for(int i = 1; i<=n; i++) {
        for(int space = 0; space<n-i; space++) {
            cout<<" "<<" ";
        }

        for(int j = 1; j<=i; j++) {
            cout<<"*"<<" ";
        }

        for(int space = 0; space<n-i; space++) {
            cout<<" "<<" ";
        }
        cout<<endl;
    }
}

// --------------------------------------------------------------- Lec 4 : Know Basic Maths ---------------------------------------------------------------------------------------------------------------------------------------------->
// Question 1 : Count Digits!
// Approach 1 : Normal! TC : O(Log10(x)) and SC : O(1)
#include<iostream>
using namespace std;

int countDigits(int n) {
    // Write your code here.
	int count = 0;
	while(n!=0) {
		count++;
		n = n / 10;
	}
	return count;
}

int main() {
    int n;
    cin>>n;
    cout<<countDigits(n);
}

// Approach 2 : Using Log10()! TC : O(1) and SC : O(1)
#include<iostream>
#include<math.h>
using namespace std;

int countDigits(int n) {
    if (n == 0) return 1;
	int count = (int)(log10(n)+1);
	return count;
}

int main() {
    int n;
    cout<<"Enter number : ";
    cin>>n;
    cout<<"Output : "<<countDigits(n);
}

// Question 1 (Complementry) : You are given a number ’n’. Find the number of digits of ‘n’ that evenly divide ‘n’. TC : O(Log10(x)) and SC : O(1)
#include <iostream>
using namespace std;

int countDivisibleDigits(int n) {
    int original = n;
    int count = 0;
    while (n > 0) {
        int digit = n % 10;
        if (digit != 0 && original % digit == 0) {
            count++;
        }
        n /= 10;
    }
    return count;
}

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;
    cout << "Output: " << countDivisibleDigits(n) << endl;
    return 0;
}

// Question 2 : Reverse a number! TC : O(Log10(x)) and SC : O(1)
#include<iostream>
#include<climits>
using namespace std;

int reverseNum(int x) {
    int ans = 0;
    while(x != 0) {
        int digit = x%10;
        if (ans > INT_MAX/10 || (ans == INT_MAX/10 && digit > 7)) return 0;
        if (ans < INT_MIN/10 || (ans == INT_MIN/10 && digit < -8)) return 0;
        ans = (ans * 10) + digit;
        x = x/10;
    }
    return ans;
}

int main() {
    int n;
    cin>>n;
    cout<<reverseNum(n);
}

// Question 3 : Check whether a number is palindrome or not!
// Approach 1 : If number is given in form of a vector, then we can solve it using two methods : Either reverse the vector and then compare original vector and reversed. Or, use two pointer approach with one at starting and another at last!
//            : TC : O(n) and SC : O(n)
#include<iostream>
#include<vector>
using namespace std;

bool checkPalindromeNum(vector<int> v) {
    // Negative number check...
    for(int i = 0; i<v.size(); i++) {
        if(v[i] < 0) {
            cout<<"Not a valid number!"<<endl;
            return false;
        }
    }
    int i = 0;
    int j = v.size()-1;
    while(i<=j) {
        if(v[i] != v[j]) {
            return false;
        }
        i++;
        j--;
    }
    return true;
}

int main() {
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i = 0; i<n; i++) {
        cin>>v[i];
    }
    cout<<checkPalindromeNum(v);
}

// Approach 2 : If the number given is a simple integer, in that case you can just reverse the number and compare the reversed and original.
//            : TC : O(Log10(x)) and SC : O(1)
#include<iostream>
#include<climits>
using namespace std;

bool isPalindrome(int x) {
    // Negative numbers and numbers ending in 0 (except 0) are not palindromes
    if (x < 0 || (x % 10 == 0 && x != 0)) {
        return false;
    }
    int original = x;
    int reversed = 0;
    while (x > 0) {
        int digit = x % 10;
        if(reversed > INT_MAX/10 || (reversed == INT_MAX/10 && digit > 7)) return 0;
        reversed = reversed * 10 + digit;
        x /= 10;
    }
    return original == reversed;
}

int main() {
    int n;
    cin>>n;
    cout<<isPalindrome(n);
}

// Approach 3 : Reverse half of the number and then compare! Advantages : No risk of overflow and reduced space complexity!
//            : TC : O(Log10(x/2)) and SC : O(1)
#include<iostream>
using namespace std;

int main() {
    int n;
    cin>>n;
    int reversedHalf = 0;
    int originalHalf = n;
    if (n < 0 || (n % 10 == 0 && n != 0)) {
        cout<<"Not a palindrome!";
        return 0;
    };
    while(originalHalf > reversedHalf) {
        int digit = originalHalf%10;
        reversedHalf = (reversedHalf * 10) + digit;
        originalHalf = originalHalf/10;
    }
    if(reversedHalf == originalHalf) { // Even number of digits
        cout<<"Palidrome!";
    }
    else if(reversedHalf == originalHalf/10) { // Odd number of digits
        cout<<"Palidrome!";
    }
    else {
        cout<<"Not a palindrome!";
    }
} // Even though approach 2 and 3 are having almost same TC, still the 3rd is better because : Reversing fewer digits = fewer iterations, No need to handle overflow = cleaner and safer logic, when x has many digits (e.g., 10^9), half-reverse performs noticeably better.

// Question 4 : Find the LCM and GCD/HCF of two numbers, and return it in form of an array!
#include<iostream>
#include<vector>
using namespace std;

vector<int> LCMnHCF(int a, int b) {
    vector<int> v;
    int A = a; int B = b;

    // HCF
    int hcf = 0;
    while(a != 0) {
        int temp = a;
        a = b % a;
        b = temp;
    }
    hcf = b;
    
    int lcm = A*B/hcf; // If you will calculate lcm from that brute force approach it will take longer time! with TC : O(a*b)
    v.push_back(lcm);
    v.push_back(hcf);
    return v;
}

int main() {
    int a, b;
    cin>>a>>b;
    vector<int> ans = LCMnHCF(a, b);
    cout<<"{"<<ans[0]<<", "<<ans[1]<<"}"<<endl;
}

// Question 5 : Check whether the given number is armstrong or not! TC : O(log10(x)) and SC : O(1)
#include<iostream>
#include<math.h>
using namespace std;

bool isArmstrong(int n) {
    int ogNum = n;
    int sum = 0;
    int digitCount = log10(n) + 1;
    while(n != 0) {
        int digit = n % 10;

        int val = 1;
        for(int i = 0; i < digitCount; i++) {
            val = val * digit;
        }

        sum = sum + val;
        n = n / 10;
    }
    if(ogNum == sum) {
        return true;
    }
    else {
        return false;
    }
}

int main() {
    int n;
    cin>>n;
    if(isArmstrong(n)) {
        cout<<"Yes it is!";
    }
    else {
        cout<<"Nope!";
    }
}

#include<iostream>
#include<math.h>
using namespace std;

bool isArmstrong(int n, int numCount) {
    int sum = 0;
    int ogNum = n;
    while(n != 0) {
        int digit = n%10;
        sum = sum + round(pow(digit,numCount));
        n /= 10;
    }
    if(ogNum == sum) return true;
    else return false;
}

int main() {
    int n;
    cin>>n;
    int numCount = (int)(log10(n)+1);
    cout<<isArmstrong(n, numCount);
}

// Question 6 : You are given an integer n. You need to find all the divisors of n. Return all the divisors of n as an array or list in a sorted order.
// Approach 1 : TC : O(n) and SC : O(n)
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> printDivisors(int n) {
    int divisor = 0;
    int ogNum = n;
    vector<int> divisors;
    while(n > 0) {
        if(ogNum % n == 0) {
            divisor = n;
            divisors.push_back(divisor);
        }
        n--;
    }
    sort(divisors.begin(), divisors.end());
    return divisors;
}

int main() {
    int n;
    cin>>n;
    vector<int> ans = printDivisors(n);
    for(int i = 0; i<ans.size(); i++) {
        cout<<ans[i]<<" ";
    }
}

// Better Approach : Instead of checking all numbers from 1 to n to find the divisors, we can reduce the number of iterations by only going up to root(n).
//                 : Why? : Any number n can be expressed as the product of two numbers: n = a × b, where both a and b are divisors of n. Now, if we iterate from 1 to √n and find a divisor a such that n % a == 0, we can directly find its corresponding pair b as b = n / a.
//                        : This way, we get both a and b without iterating all the way up to n. So, instead of wasting time checking after √n, we can generate all the remaining divisors using this division logic — making the algorithm much more efficient.
#include<iostream>
#include<vector>
#include<math.h>
#include<algorithm>
using namespace std;

vector<int> printDivisors2(int n) {
    vector<int> divisors;
    int divisor = 0;
    for(int i = 1; i <= sqrt(n); i++) {
        if(n % i == 0) {
            divisor = i;
            divisors.push_back(divisor);
            if(i != n/i) {
                divisors.push_back(n/divisor);
            }
        }
    }
    sort(divisors.begin(), divisors.end());
    return divisors;
}

int main() {
    int n;
    cin>>n;
    vector<int> ans = printDivisors2(n);
    for(int i = 0; i < ans.size(); i++) {
        cout<<ans[i]<<" ";
    }
}

// Question 7 : You are given an integer n. You need to check if the number is prime or not. Return true if it is a prime number, otherwise return false.
//            : TC : O(root(n)) and SC : O(1)
#include<iostream>
#include<math.h>
using namespace std;

int main() {
    int n;
    cin>>n;
    if(n <= 1) {
        cout<<"Not prime!";
        return 0;
    } 
    for(int i = 2; i<sqrt(n); i++) {
        if(n % i == 0) {
            cout<<"Not prime!";
            return 0;
        }
    }
    cout<<"prime!";
    return 0;
}

// Alternative : If you want a series of prime numbers which are less than a particular number n. Then in that case you can use Sieve of Eratosthenes!
//             : TC : O(log(log n)) and SC : O(n)
#include<iostream>
#include<vector>
using namespace std;

vector<int> primeSeries(int n) {
    vector<bool> isPrime(n+1, true);
    vector<int> ans;
    isPrime[0] = false;
    isPrime[1] = false;
    for(int i = 2; i*i <= n; i++) { // If you see carefully, here also we are going till only i <= root(n)
        if(isPrime[i]) {
            for(int j = i*i; j<=n; j = j + i) {
                isPrime[j] = false;
            }
        }
    }
    for(int i = 2; i<=n; i++) {
        if(isPrime[i] == true) {
            ans.push_back(i);
        }
    }
    return ans;
}

int main() {
    int n;
    cin>>n;
    vector<int> result = primeSeries(n);
    for(int i = 0; i<result.size(); i++) {
        cout<<result[i]<<" ";
    }
}

// --------------------------------------------------------------- Lec 5 : Know Basic Recursion ---------------------------------------------------------------------------------------------------------------------------------------------->
// Question 1 : Print a name n times using recursion!
#include<iostream>
#include<string>
using namespace std;

void printName(int n, string name) {
    if(n == 0) return;
    cout<<name<<" ";
    n--;
    printName(n, name);
}

int main() {
    int n;
    cout<<"Enter times : ";
    cin>>n;
    string name;
    cout<<"Enter name : ";
    cin>>name;
    cout<<"Execution : ";
    printName(n, name);
}

// Question 2 and 3 : Print 1 to N and N to 1 using recursion!
#include<iostream>
using namespace std;

void printCounting1toN(int n) {
    if(n == 0) return;
    printCounting1toN(n-1);
    cout<<n<<" ";
}

void printCountingNto1(int n) {
    if(n == 0) return;
    cout<<n<<" ";
    printCountingNto1(n-1);
}

int main() {
    int n;
    cout<<"Enter n : ";
    cin>>n;
    printCounting1toN(n);
    cout<<endl;
    printCountingNto1(n);
}

// Question 4 : Sum of first N numbers! TC : O(n) and SC : O(n) - Not always recursion is the best approach, like here SC is O(n), instead if you just simply return n*(n+1)/2, then the SC : O(1).
#include<iostream>
using namespace std;

int printSum(int n) {
    if(n == 0) return 0;
    return n + printSum(n-1);   
}

int main() {
    int n;
    cout<<"Enter n : ";
    cin>>n;
    cout<<printSum(n);
}

// Question 5 : Factorial of N! TC : O(n) and SC : O(n) - Again without recursion using a for loop it would have saved alot of space! where the SC : O(1).
#include<iostream>
using namespace std;

int printFact(int n) {
    if(n == 0) return 1;
    return n * printFact(n-1);   
}

int main() {
    int n;
    cout<<"Enter n : ";
    cin>>n;
    cout<<printFact(n);
}

// Question 6 : Reverse and Array!
#include<iostream>
#include<vector>
using namespace std;

void reverseArray(vector<int> &v, int start, int end) {
    if(start < end) {
        swap(v[start], v[end]);
        reverseArray(v, start + 1, end - 1);
    }
}

int main() {
    int n;
    cout<<"Enter size of array : ";
    cin>>n;
    vector<int> arr(n);
    for(int i = 0; i<n; i++) {
        cin>>arr[i];
    }
    reverseArray(arr, 0, n-1);
    for(int i = 0; i<n; i++) {
        cout<<arr[i]<<" ";
    }
}

// Question 7 : Check if the given String is Palindrome or not!
#include<iostream>
#include<string>
using namespace std;

bool checkPalindrome(string str, int start, int end) {
    if(start >= end) {
        return true;
    }
    if(str[start] != str[end]) {
        return false;
    }
    return checkPalindrome(str, start + 1, end - 1);
}

int main() {
    string str;
    cin>>str;
    if(checkPalindrome(str, 0, str.length() - 1)) {
        cout<<"Palindome!";
    }
    else {
        cout<<"Not a palindrome!";
    }
}

// Question 7 : Print Fibonacci Series up to Nth term, 0 1 1 2 3 5 8 13 21 34...
// Using Position!
#include<iostream>
using namespace std;

int printFib1(int pos) {
    int Pos1 = 0;
    int Pos2 = 1;
    if(pos == 1) {
        return 0;
    }
    if(pos == 2) {
        return 1;
    }
    return printFib1(pos - 1) + printFib1(pos - 2);
}

int main() {
    int pos;
    cin>>pos;
    cout<<printFib1(pos);
}

// Using Index!
#include<iostream>
using namespace std;

int printFib2(int index) {
    int index0 = 0;
    int index1 = 1;
    if(index == 0 || index == 1) {
        return index;
    }
    return printFib2(index - 1) + printFib2(index - 2);
}

int main() {
    int index;
    cin>>index;
    cout<<printFib2(index);
}

// Printing the series till Nth term!
#include <iostream>
using namespace std;

int printFib3(int pos) {
    if (pos == 0) {
        return 0;
    }
    if (pos == 1) {
        return 1;
    }
    return printFib3(pos - 1) + printFib3(pos - 2);
}

int main() {
    int N;
    cout << "Enter N: ";
    cin >> N;

    cout << "Fibonacci Series up to " << N << " terms: ";
    for (int i = 0; i < N; ++i) {
        cout << printFib3(i) << " ";
    }
    return 0;
}

// Printing the series till a particular value!
#include <iostream>
using namespace std;

void printFib4(int a, int b, int X) {
    if (a > X) return; // base condition: stop when a crosses X

    cout << a << " "; // print current Fibonacci number
    printFib4(b, a + b, X); // move to next
}

int main() {
    int X;
    cout << "Enter value X: ";
    cin >> X;

    cout << "Fibonacci series till " << X << " is: ";
    printFib4(0, 1, X); // start with 0 and 1
    return 0;
}

// --------------------------------------------------------------- Lec 6 : Learn Hashing Basics ---------------------------------------------------------------------------------------------------------------------------------------------->
// Related Learnings!
// Problem Statement : Imagine you are given an array like : [1, 2, 1, 3, 2] and Now, someone asks : "How many times does 1 appear?" or "How many times does 2, 3, 4, or even 10 appear?"
//                   : The brute-force way would be : Use a count variable. Loop through the whole array every time you want to count how many times a number appears.
//                   : So if : Array size = n, You want to check frequency of q numbers. Then the Time Complexity becomes : O(n) for each number → Total = O(q * n)
//                   : Now Think : If both n and q are large (like 10⁵), then: Total operations = 10^5 * 10^5 = 10^10 But we know: 10^8 operations ≈ 1 second, So, 10¹⁰ operations ≈ 100 seconds (Too slow!)
//                   : Solution : Hashing (PreStore and Fetch)
//                              : Let’s say the maximum number in the array is 12.
//                              : Step 1 : Create a new array called hash of size 13 (to include index 0 to 12).
//                              : Step 2 : Initialize it with zeros: hash = [0, 0, 0, ..., 0] (13 times)
//                              : Step 3 : Loop through the original array. For every element, do: hash[element]++, This means you're counting how many times each number appears and storing it in the hash array.
//                              : Now, whenever someone asks : "How many times does 1 appear?" → Just check hash[1], "How many times does 4 appear?" → Just check hash[4]
//                              : Its Super fast! Just O(n) time for pre-processing and after that, each query takes O(1) time.
// Question 1 : Count frequency of each element in the array
// Using array hashing!
#include <iostream>
#include <vector>
using namespace std;

// Brute-force function
void bruteForceFrequency(vector<int>& arr, vector<int>& queries) {
    cout << "Brute Force Method:\n";
    for (int q : queries) {
        int count = 0;
        for (int num : arr) {
            if (num == q) count++;
        }
        cout << "Frequency of " << q << " is: " << count << endl;
    }
}

// Hashing function
void hashingFrequency(vector<int>& arr, vector<int>& queries, int maxVal) {
    cout << "\nHashing Method:\n";
    vector<int> hash(maxVal + 1, 0); // Step 1: Create hash array of size maxVal+1
    for (int num : arr) { // Step 2: Preprocessing - count frequency
        hash[num]++;
    }
    for (int q : queries) { // Step 3: Answering queries in O(1)
        cout << "Frequency of " << q << " is: " << hash[q] << endl;
    }
}

int main() {
    vector<int> arr = {1, 2, 1, 3, 2};
    vector<int> queries = {1, 2, 3, 4, 10};
    int maxVal = 12; // Given or assumed max element value

    bruteForceFrequency(arr, queries); // Brute Force

    hashingFrequency(arr, queries, maxVal); // Hashing

    return 0;
}
// Here we did, number hashing, same way we can do character hashing! like we could be given a string and then we may be asked to print the frequency of certain characters that also we can do just by character - 'a' or character - 'A', this all we have already done!

// Problem with hash-array : Let’s say you are given an array like: arr[] = {1, 2, 3, 2, 1, 12}; Now if you want to count the frequency of each element, a simple way is to create a hash-array of size 13 (because max element = 12), and store the counts at respective indices.
//                         : hash[1] = 2, hash[2] = 2, hash[3] = 1, hash[12] = 1. So later, if someone asks how many times 1 occurs, just do hash[1] and you get the answer 2. This method is fast — time complexity is O(N) — but the space required can be a problem.
//                         : What if elements are large? Now suppose an element in your array is as big as 10^9. Then you’d need a hash-array of size 10^9 + 1. This is not possible, because: Maximum size of an integer array inside main() is around 10^6, In global scope, you can go up to 10^7. For boolean arrays, you can go up to 10^7 (in main) or 10^8 (in global scope)
//                         : So clearly, creating a large hash-array for values like 10^9 is not feasible.

// Solution : Use Maps or Unordered Maps (Hash Maps)
//          : To solve this, we use: map / unordered_map in C++ STL, HashMap in Java
//          : With maps, you don’t need to store all values from 0 to max number. You only store the numbers that actually exist in the array — which saves a lot of space!
//          : For example, for array {1, 2, 3, 2, 1, 12}, map will store: 1->2, 2->2, 3->1, 12->1, Only 4 keys instead of using size 13.
//          : Time Complexity : For map (ordered map): Insertion: O(log N) and Fetching: O(log N). Internally uses: Red-Black Tree
//                            : For unordered_map: Insertion: Average case O(1), Worst case O(N) and Fetching: Average case O(1), Worst case O(N). Internally uses: Hash Table
//                            : In most cases, unordered_map is preferred because of its average case speed O(1), which is much faster than O(log N) of map.
//                            : Only use map if: You need sorted order or unordered_map is giving Time Limit Exceeded (TLE) (rare, but possible due to collisions)
//          : Why do collisions happen in unordered_map? Let’s understand with a small example using the Division Method of hashing : array = {2, 5, 16, 28, 139} and hash size = 10 (just for example, you can scale it for larger values and sizes)
//                                                                                                                                  : Doing ar[i]%10 for each element, the hash-array will be [_, _, 2, _, _, 5, 16, _, 28, 139]. Now, if you want to find frequency of 139, you just do 139 % 10 = 9, and check index 9. and you will get the start of the LL, and then you can use any optimal sorting or searching algo to find the count of it!
//                                                                                                                                  : Problem with Collisions : Let’s take a case where many elements give the same modulo result : array = {8, 18, 28, 38, 48, 58, 68, 78, 88, 98, 1008, 10008, 1000008}
//                                                                                                                                  : In this case, everything gets stored at index 8 of the hash-array like this: hash[8] = 8 → 18 → 28 → 38 → ... → 1000008. Index 8 becomes a long linked list, and searching in that becomes linear (O(N)) instead of O(1). This is what causes the worst-case time complexity of O(N) in unordered_map.
// Using Maps!
#include <iostream>
#include <map>
using namespace std;

int main() {
    int arr[] = {1, 2, 3, 2, 1, 12};
    int n = 6;
    map<int, int> mpp; // Ordered map
    for (int i = 0; i < n; i++) {
        mpp[arr[i]]++; // Count frequency
    }
    for (auto it : mpp) {
        cout << "Element: " << it.first << " -> Frequency: " << it.second << endl;
    }
    return 0;
}

// Using Unordered-Maps!
#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    int arr[] = {1, 2, 3, 2, 1, 12};
    int n = 6;
    unordered_map<int, int> mpp; // Unordered map
    for (int i = 0; i < n; i++) {
        mpp[arr[i]]++; // Count frequency
    }
    for (auto it : mpp) {
        cout << "Element: " << it.first << " -> Frequency: " << it.second << endl;
    }
    return 0;
}

// Question 2 : Find the highest/lowest frequency element
#include<iostream>
#include<map>
#include<climits>
#include<vector>
using namespace std;

int main() {
    int arr[] = {10, 5, 10, 15, 10, 5};
    map<int,int> freq;
    for(int i = 0; i<6; i++) {
        freq[arr[i]]++;
    }

    for(auto i : freq) {
        cout<<i.first<<" -> "<<i.second<<endl;
    }

    vector<int> maxFE;
    int maxF = INT_MIN;
    vector<int> minFE;
    int minF = INT_MAX;
    
    for(auto i : freq) {
        if(i.second > maxF) {
            maxF = i.second;
            maxFE.clear(); // clear old elements
            maxFE.push_back(i.first);
        }
        else if(i.second == maxF) {
            maxFE.push_back(i.first);
        }

        if(i.second < minF) {
            minF = i.second;
            minFE.clear();
            minFE.push_back(i.first);
        }
        else if(i.second == minF) {
            minFE.push_back(i.first);
        }
    }
    cout << "Max frequency element(s): ";
    for(auto val : maxFE) cout << val << " ";
    cout << "\n";

    cout << "Min frequency element(s): ";
    for(auto val : minFE) cout << val << " ";
    cout << "\n";
}