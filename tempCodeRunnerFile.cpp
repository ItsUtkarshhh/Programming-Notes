// Merge 2 sorted arrays!
#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
#include<map>
#include<unordered_map> // For better!
#include<set>
#include<unordered_set> // For better!
using namespace std;

int sqroot(int n) {
    int s = 0;
    int e = n;
    int mid = s + (e-s)/2;
    int ans = 0;
    while(s <= e) {
        int square = mid * mid;
        if(square == n) {
            return mid;
        }
        else if(square < n) {
            ans = mid;
            s = mid + 1;
        }
        else {
            e = mid - 1;
        }
        mid = s + (e-s)/2;
    }
    return ans;
}

double sqrootPrecise(int n, int k) {
    int integerVal = sqroot(n);
    double factor = 1;
    double ans = -1;
    for(int i = 0; i < k; i++) {
        factor = factor/10;
        for(double root = integerVal; root * root <= n; root = root + factor) {
            ans = root;
        }
    }
    return ans;
}

int main() {
    int n;
    cin>>n;
    cout<<sqroot(n)<<endl;
    cout<<sqrootPrecise(n, 3);
}