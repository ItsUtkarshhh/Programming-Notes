// --------------------------------------------------------------- Lec 2 : Patterns ---------------------------------------------------------------------------------------------------------------------------------------------->
// Pattern 1 : Simple square/rectangle * pattern! * * * * * -> * * * * * -> * * * * * -> * * * * * ...
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

// Pattern 2 : One sided * triangle pattern! * -> * * -> * * * -> * * * * ...
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

// Pattern 3 : One sided triangle number pattern! 1 -> 1 2 -> 1 2 3 -> 1 2 3 4 ...
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

// Pattern 4 : One sided triangle number pattern! 1 -> 2 2 -> 3 3 3 -> 4 4 4 4 ...
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

// Pattern 5 : Horizontally Reverse * traingle pattern! * * * * -> * * * -> * * -> * ...
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

// Pattern 6 : Horizontally Reverse counting traingle pattern! 1 2 3 4 -> 1 2 3 -> 1 2 -> 1 ...
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

// Pattern 7 : * pyramid!
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

// Pattern 8 : Reverse * pyramid!
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

// Pattern 9 : Mixture of reverse and un-reverse * pyramid! - Diamond Shape!
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

// Pattern 10 : 90 deg rotated Pyramid!
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

// Pattern 11 : Print pattern like 1 -> 0 1 -> 1 0 1 -> 0 1 0 1...
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

// Pattern 12 : Print a pattern like 1 _ _ _ _ 1 -> 1 2 _ _ 2 1 -> 1 2 3 3 2 1 and similarly!
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

// Pattern 13 : Print a pattern counting 1 to n.
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

// Pattern 14 : Print a pattern A -> A B -> A B C -> A B C D and so on
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

// Pattern 15 : Print a pattern A B C D E -> A B C D -> A B C -> A B -> A.
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

// Pattern 16 : Print a pattern A -> B B  -> C C C and so on...
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

// Pattern 17 : Print a pattern pytramid A -> A B A -> A B C B A and so on...
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

// Pattern 18 : Print a pattern right angled pytramid E -> D E -> C D E and so on...
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

// Pattern 19 : Print a pattern Anti-diamond!
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

// Pattern 20 : Print a butterfly pattern!
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

// Pattern 21 : Print square stroke patterns!
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

// Pattern 22 : Print a unique numerical pattern, go to sheet to see the pattern!
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

// --------------------------------------------------------------- Lec 5 : Know Basic Recursion ---------------------------------------------------------------------------------------------------------------------------------------------->