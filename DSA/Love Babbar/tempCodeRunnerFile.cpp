#include<iostream>
using namespace std;

int countDigits(int n) {
    // Write your code here.
	int totalNumbers = 0;
	while(n!=0) {
		totalNumbers++;
		n = n / 10;
	}
    int count = 1;
	while(count <= totalNumbers) {
		int num = n;
		int digit = num % 10;
		if(num % digit == 0) {
			count++;
		}
		num = num / 10;
	}
	return count;
}

int main() {
    int n;
    cin>>n;
    cout<<countDigits(n);
}