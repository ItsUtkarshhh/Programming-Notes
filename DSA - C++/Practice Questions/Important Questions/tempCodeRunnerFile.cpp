#include<iostream>
#include<vector>
using namespace std;

// vector<int> moveZeroesLeft(vector<int> &v) {
//     int i = 0;
//     int j = v.size() - 1;
//     while(i < j) {
//         while(i < v.size() && v[i] == 0) i++;
//         while(j >= 0 && v[j] != 0) j--;

//         if(i < j) {
//             swap(v[i], v[j]);
//             i++; j--;
//         }
//     }
//     return v;
// }

vector<int> moveZeroesLeft(vector<int> &v) {
    int i = 0;
    int j = v.size() - 1;
    while(i < j) {
        if(v[i] == 0 && v[j] != 0) {
            i++; j--;
        }
        else if(v[i] == 0 && v[j] == 0) {
            i++;
        }
        else if(v[i] != 0 && v[j] == 0) {
            swap(v[i], v[j]);
            i++; j--;
        }
        else {
            j--;
        }
    }
    return v;
}

int main() {
    int n;
    cin>>n;
    vector<int> v(n);
    int zeroFound = false;
    for(int i = 0; i < n; i++) {
        cin>>v[i];
        if(v[i] == 0) {
            zeroFound = true;
        }
    }
    if(zeroFound) {
        moveZeroesLeft(v);
        for(int i = 0; i < n; i++) {
            cout<<v[i]<<" ";
        }
    }
    else {
        for(int i = 0; i < n; i++) {
            cout<<v[i]<<" ";
        }
    }
}