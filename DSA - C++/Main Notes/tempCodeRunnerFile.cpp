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