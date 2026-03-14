// --------------------------------------------------------------- Weekly Contest - 490 --------------------------------------------------------------->
// Question 1 : Visit the question on @leetcode
#include<iostream>
#include<vector>
using namespace std;

int scoreDifference(vector<int>& nums) {
    if(nums.size() == 0) return 0;

    bool activeP1 = true;
    bool activeP2 = false;

    int scoreP1 = 0;
    int scoreP2 = 0;

    int i = 0;
    while(i <= nums.size() - 1) {
        if(i % 6 == 5) swap(activeP1, activeP2);
        if(nums[i]%2 != 0) swap(activeP1, activeP2);
        cout<<"i : "<<i<<"| activeP1 : "<<activeP1<<endl;
        cout<<"i : "<<i<<"| activeP2 : "<<activeP2<<endl;
        if(activeP1 == true) scoreP1 = scoreP1 + nums[i];
        if(activeP2 == true) scoreP2 = scoreP2 + nums[i];
        cout<<"scoreP1 = "<<scoreP1<<endl;
        cout<<"scoreP2 = "<<scoreP2<<endl;
        cout<<endl;
        i++;
    }
    return scoreP1 - scoreP2;
}

int main() {
    vector<int> v = {57,47,98,35,14,17,12,24,56,58,72,72,66,53,14,4,12,46,71,12,77,77,42,50,2,38,53,50,100,11,93,72,32,74,67,22,88,49,22,18,35,39,35,64,19,9,22,56,36};
    cout<<scoreDifference(v);
}