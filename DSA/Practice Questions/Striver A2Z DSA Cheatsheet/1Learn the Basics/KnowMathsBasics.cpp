// Question 1 : Count Digits!
// Approach 1 : Normal!
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

// Approach 2 : Using Log10()!
#include<iostream>
#include<math.h>
using namespace std;

int countDigits(int n) {
	int count = (int)(log10(n)+1);
	return count;
}

int main() {
    int n;
    cout<<"Enter number : ";
    cin>>n;
    cout<<"Output : "<<countDigits(n);
}

// Question 1 (Complementry) : You are given a number ’n’. Find the number of digits of ‘n’ that evenly divide ‘n’.
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

// Question 2 : You are given a number ’n’. Find the number of digits of ‘n’ that evenly divide ‘n’.