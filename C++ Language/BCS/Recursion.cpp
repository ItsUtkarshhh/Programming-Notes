// Sum of N natural number entered by user!
#include<iostream>
using namespace std;

int sumOfnumbers(int n) {
    if(n == 0) {
        return 0;
    }
    return n + sumOfnumbers(n-1);
}

int main() {
    int n;
    cin>>n;
    cout<<sumOfnumbers(n);
}

// Factorial using recursion!
#include<iostream>
using namespace std;

int factorial(int n) {
    if(n==0) {
        return 1;
    }
    return n*factorial(n-1);
}

int main() {
    int n;
    cin>>n;
    cout<<factorial(n);
}

// GCD Using recursion!
#include<iostream>
using namespace std;

int GCD(int n1, int n2) {
    if(n1==0) {
        return n2;
    }
    if(n2==0) {
        return n1;
    }
    if(n1==n2) {
        return n1;
    }
    else {
        if(n1>n2) {
            return GCD(n1-n2,n2);
        }
        else {
            return GCD(n1,n2-n1);
        }
    }
}

int main() {
    int n1,n2;
    cin>>n1>>n2;

    cout<<GCD(n1,n2);
}

// Power of a number entered by the user and power also!
#include<iostream>
using namespace std;

int power(int base, int exponent) {
    if(exponent == 0) {
        return 1;
    }
    return base * power(base,exponent-1);
}

int main() {
    int base,exponent;
    cin>>base>>exponent;

    cout<<power(base,exponent);
}

// Improved method :
#include<iostream>
using namespace std;

int power2(int base, int exponent) {
    if(exponent == 0) {
        return 1;
    }
    if(exponent == 1) {
        return base;
    }
    int ans = power2(base,exponent/2);

    if(exponent%2 == 0) {
        return ans*ans;
    }
    else {
        return base*ans*ans;
    }
}

int main() {
    int base,exponent;
    cin>>base>>exponent;

    cout<<power2(base,exponent);
}