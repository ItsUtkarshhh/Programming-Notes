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