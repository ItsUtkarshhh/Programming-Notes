#include<iostream>
using namespace std;

int main() {
    float x = 34.4f; // "f" or "F" is used to specify float number
    long double y = 34.4l; // "l" or "L" is used to specify long double number

    cout<<"the size of 34.4 is :"<<sizeof(34.4)<<endl;
    cout<<"the size of 34.4f is :"<<sizeof(34.4f)<<endl;
    cout<<"the size of 34.4F is :"<<sizeof(34.4F)<<endl;
    cout<<"the size of 34.4l is :"<<sizeof(34.4l)<<endl;
    cout<<"the size of 34.4L is :"<<sizeof(34.4L)<<endl;
}