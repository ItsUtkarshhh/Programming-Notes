// Question 1 : Display all the prime numbers in interval of a to b
#include <iostream>
using namespace std;

bool isPrime(int num) {
    if (num <= 1) return false;
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) return false;
    }
    return true;
}

void displayPrimesInInterval(int start, int end) {
    cout << "Prime numbers between " << start << " and " << end << " are:\n";
    for (int i = start; i <= end; i++) {
        if (isPrime(i)) {
            cout << i << " ";
        }
    }
    cout << endl;
}

int main() {
    int start, end;
    cout << "Enter the starting interval: ";
    cin >> start;
    cout << "Enter the ending interval: ";
    cin >> end;
    displayPrimesInInterval(start, end);
}

// Question 2 : Find all the prime numbers from a to b where their sum is equal to a particular number!
#include <iostream>
#include <vector>
using namespace std;

// Function to check if a number is prime
bool isPrime(int num) {
    if (num <= 1) return false;
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) return false;
    }
    return true;
}

// Function to find all pairs of prime numbers that sum to the given number
void findPrimePairs(int n) {
    vector<int> primes;
    
    // Find all prime numbers up to n
    for (int i = 2; i <= n; i++) {
        if (isPrime(i)) {
            primes.push_back(i);
        }
    }

    // Check for pairs
    for (int i = 0; i < primes.size(); i++) {
        for (int j = i; j < primes.size(); j++) {
            if (primes[i] + primes[j] == n) {
                cout << n << " = " << primes[i] << " + " << primes[j] << endl;
            }
        }
    }
}

int main() {
    int n;

    cout << "Enter a positive integer: ";
    cin >> n;

    cout << "Possible combinations:\n";
    findPrimePairs(n);

    return 0;
}

// Question 3 : Decimal to Binary!
#include<iostream>
using namespace std;

int DecimalToBinary(int n) {
    int number = n;
    int ans = 0;
    int i = 0;
    while(number!=0) {
        int digits = number&1;
        ans = (ans * 10) + digits;
        number = number >> 1;
        i++;
    }
    cout<<ans;
}

int main() {
    int num;
    cin>>num;
    DecimalToBinary(num);
}