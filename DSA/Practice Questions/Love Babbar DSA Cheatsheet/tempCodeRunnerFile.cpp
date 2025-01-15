#include<iostream>
#include<climits>
#include<utility> // For pair
using namespace std;

pair<int,int> MaxMin(int* arr, int n) {
    pair<int,int> ans(0,0); // pair constructor to initialise values.
    // pair<int,int> ans = make_pair(0,0); // Or can use make_pair() method.
    if(n == 0) {
        cout<<"Empty array!";
        return ans;
    }
    int max = INT_MIN;
    int min = INT_MAX;
    for(int i = 0; i<n; i++) {
        if(arr[i] > max) {
            max = arr[i];
        }
    }
    for(int i = 0; i<n; i++) {
        if(arr[i] < min) {
            min = arr[i];
        }
    }
    ans.first = min;
    ans.second = max;
    return ans;
}

int main() {
    int n;
    cin>>n;
    int* arr1 = new int[n]();
    for(int i = 0; i<n; i++) {
        cin>>arr1[i];
    }
    pair<int,int> res = MaxMin(arr1,n);
    cout<<"Minimum Value : "<<res.first<<endl;
    cout<<"Maximum Value : "<<res.second<<endl;
    delete[] arr1;
}