#include<iostream>
#include<map>
#include<climits>
#include<vector>
using namespace std;

int main() {
    int arr[] = {10, 5, 10, 15, 10, 5};
    map<int,int> freq;
    for(int i = 0; i<6; i++) {
        freq[arr[i]]++;
    }

    for(auto i : freq) {
        cout<<i.first<<" -> "<<i.second<<endl;
    }

    vector<int> maxFE;
    int maxF = INT_MIN;
    vector<int> minFE;
    int minF = INT_MAX;
    for(auto i : freq) {
        if(i.second > maxF) {
            maxF = i.second;
            maxFE.clear(); // clear old elements
            maxFE.push_back(i.first);
        }
        else if(i.second == maxF) {
            maxFE.push_back(i.first);
        }

        if(i.second < minF) {
            minF = i.second;
            minFE.clear();
            minFE.push_back(i.first);
        }
        else if(i.second == minF) {
            minFE.push_back(i.first);
        }
    }
    cout << "Max frequency element(s): ";
    for(auto val : maxFE) cout << val << " ";
    cout << "\n";

    cout << "Min frequency element(s): ";
    for(auto val : minFE) cout << val << " ";
    cout << "\n";
}