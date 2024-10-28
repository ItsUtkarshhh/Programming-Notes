#include<iostream>
using namespace std;

int main() {
    int n;
    cin>>n;
    int sum = 0;
    for(int i = 1; i<=n; i++) {
        sum += i;
    }
    cout<<sum;
}

#include<iostream>
using namespace std;

int main() {
    int n;
    cin>>n;
    int fact = 1;
    for(int i = n; i>=1; i--) {
        fact *= i;
    }
    cout<<fact;
}

#include<iostream>
using namespace std;

int main() {
    int n;
    cin>>n;
    for(int i = 1; i<=10; i++) {
        cout<<n*i<<endl;
    }
}

#include<iostream>
using namespace std;

int main() {
    int n;
    cin>>n;
    int first = 0, second = 1;
    if(n == first) {
        cout<<first<<endl;
    }
    else if(n == second) {
        cout<<first<<" "<<second<<endl;
    }
    else {
        int next = first + second;
        cout<<first<<" "<<second<<" ";
        while(next<n) {
            cout<<next<<" ";
            first = second;
            second = next;
            next = first + second;
        }
    }
}

#include<iostream>
using namespace std;

int main() {
    int a,b;
    cin>>a>>b;

    int result = min(a,b);
    while(result>0) {
        if(a%result == 0 && b%result == 0) {
            break;
        }
        result--;
    }
    cout<<result;
}

#include<iostream>
using namespace std;

int main() {
    int a,b;
    cin>>a>>b;

    int result = max(a,b);
    while(true) {
        if(result%a == 0 && result%b == 0) {
            break;
        }
        result++;
    }
    cout<<result;
}

#include<iostream>
using namespace std;

int main() {
    int n;
    cin>>n;
    int ans = 0;
    while(n!=0) {
        int digit = n%10;
        ans = (ans*10) + digit;
        n /= 10;
    }
    cout<<ans;
}

#include<iostream>
using namespace std;

int main() {
    int n;
    cin>>n;
    int sum = 0;
    while(n!=0) {
        int digit = n%10;
        sum += digit;
        n /= 10;
    }
    cout<<sum;
}

#include<iostream>
#include<math.h>
using namespace std;

int main() {
    int n,i;
    cin>>n>>i;
    cout<<pow(n,i);
}

#include<iostream>
using namespace std;

int main() {
    int n,exp;
    cin>>n>>exp;
    int ans = 1;
    for(int i = 1; i<=exp; i++) {
        ans *= n;
    }
    cout<<ans;
}

#include<iostream>
using namespace std;

int main() {
    int n;
    cin>>n;
    int num = n;
    int ans = 0;
    while(num!=0) {
        int digits = num%10;
        ans = (ans*10) + digits;
        num /= 10;
    }
    if(ans == n) {
        cout<<"They are palindrom!";
    }
    else {
        cout<<"They are not!";
    }
}

#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int n;
    cin >> n;

    if (n <= 1) {
        cout << "Not a prime!" << endl;
    } else {
        bool isPrime = true;
        for (int i = 2; i <= sqrt(n); i++) {
            if (n % i == 0) {
                isPrime = false;
                break;
            }
        }
        if (isPrime) {
            cout << "Prime!" << endl;
        } else {
            cout << "Not a prime!" << endl;
        }
    }
}

#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int number, originalNum, remainder, n = 0;
    double result = 0.0;
    cout << "Enter a number: ";
    cin >> number;

    originalNum = number;

    // Number of digits calculation
    while (originalNum != 0) {
        originalNum /= 10;
        ++n;
    }

    originalNum = number;

    // Result calculation
    while (originalNum != 0) {
        remainder = originalNum % 10;
        result += pow(remainder, n);
        originalNum /= 10;
    }

    // Checking if the number is an Armstrong number
    if ((int)result == number) {
        cout << number << " is an Armstrong number." << endl;
    } else {
        cout << number << " is not an Armstrong number." << endl;
    }
}

#include<iostream>
using namespace std;

int main() {
    int n;
    cin>>n;
    for(int i = n; i>=1; i--) {
        if(n%i == 0) {
            cout<<i<<" ";
        }
    }
}

#include<iostream>
using namespace std;

int main() {
    int a,b;
    cin>>a>>b;
    char op;
    cin>>op;
    switch (op) {
    case '+' :
        cout<<a+b;
        break;
    case '-' :
        cout<<a-b;
        break;
    case '/' :
        cout<<a/b;
        break;
    case '*' :
        cout<<a*b;
        break;
    default :
        cout<<"Enter a valid operator!";
    }
}