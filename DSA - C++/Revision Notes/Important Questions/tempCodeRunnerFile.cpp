#include<iostream>
#include<vector>
using namespace std;

int FibBetweenAandB(int lowerB, int upperB) {
    int first = 0; int second = 1;
    int count = 0;
    bool oneCounted = false;
    while(first <= upperB) {
        if(first >= lowerB) {
            if (first == 1 && oneCounted) {
                // Skip duplicate '1'
            }
            else {
                count++;
                if (first == 1) oneCounted = true;
            }
        }
        int next = first + second;
        first = second;
        second = next;
    }
    return count;
}

int main() {
    int lowerB, upperB;
    cin>>lowerB>>upperB;
    cout<<FibBetweenAandB(min(lowerB, upperB), max(lowerB, upperB));
}