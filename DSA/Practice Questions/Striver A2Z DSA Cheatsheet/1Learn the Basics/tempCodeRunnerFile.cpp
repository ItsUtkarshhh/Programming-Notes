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