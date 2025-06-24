#include<iostream>
#include<vector>
using namespace std;

vector<int> sort01(vector<int> &v) {
    int i = 0; int j = v.size() - 1;
    while(i < j) {
        while(v[i] == 0 & i < j) {
            i++;
        }
        while(v[j] == 1 & i < j) {
            j--;
        }
        if(i < j) {
            swap(v[i], v[j]);
            i++; j--;
        }
    }
}

int main() {
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i = 0; i < n; i++) {
        cin>>v[i];
        if(v[i] != 0 && v[i] != 1) {
            cout<<"Restart the program and enter value 0/1";
            exit(0);
        }
    }
    sort01(v);
    for(int i = 0; i< v.size(); i++) {
        cout<<v[i]<<" ";
    }
}