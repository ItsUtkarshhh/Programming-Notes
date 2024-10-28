#include<iostream>
using namespace std;

int main() {
    cout<<"Hello World!";
}

#include<iostream>
using namespace std;

int main() {
    int n;
    cin>>n;
    cout<<n;
}

#include<iostream>
using namespace std;

int main() {
    int a,b;
    cin>>a>>b;
    cout<<a+b;
}

#include<iostream>
using namespace std;

int main() {
    int dividend,divisor;
    cin>>dividend>>divisor;
    cout<<"Remainder : "<<dividend%divisor;
    cout<<"Quotient : "<<dividend/divisor;
}


#include<iostream>
using namespace std;

int main() {
    cout<<sizeof(int)<<endl;
    cout<<sizeof(float)<<endl;
    cout<<sizeof(char)<<endl;
    cout<<sizeof(double)<<endl;
}

#include<iostream>
using namespace std;

int main() {
    int num1, num2;
    cin>>num1>>num2;

    cout<<"num1 : "<<num1<<endl;
    cout<<"num2 : "<<num2<<endl;

    int temp = num2;
    num2 = num1;
    num1 = temp;

    cout<<"num1 : "<<num1<<endl;
    cout<<"num2 : "<<num2<<endl;
}

#include<iostream>
using namespace std;

int main() {
    int n = 'a';
    cout<<n<<endl;
    cout<<(int)'b'<<endl;
}

#include<iostream>
using namespace std;

int main() {
    int n,m;
    cin>>n>>m;
    cout<<n*m;
}