#include<iostream>
using namespace std;

class TwoStack {
    int *arr;
    int top1;
    int top2;
    int size;

    public:
    TwoStack(int s) {
        this->size = s;
        top1 = -1;
        top2 = s;
        arr = new int[s];
    }

    void Push1(int element) {
        if(top2 - top1 > 1) {
            top1++;
            arr[top1] = element;
        }
        else {
            cout<<"Stack Overflow!"<<endl;
        }
    }

    void Push2(int element) {
        if(top2-top1 > 1) {
            top2--;
            arr[top2] = element;
        }
        else {
            cout<<"Stack overflow!"<<endl;
        }
    }

    int pop1() {
        if(top1 >= 0) {
            int ans = arr[top1];
            top1--;
            return ans;
        }
        else {
            return -1;
        }
    }

    int pop2() {
        if(top2 < size) {
            int ans = arr[top2];
            top2++;
            return ans;
        }
        else {
            return -1;
        }
    }
}; // Also, yahaa hum ye bhi kr sakte the ki array ko n/2 n/2 parts me tod ke fir dono stacks ko daalte raho usme! but ye ek acha tareeka nhi hota! kyunki kyunki maanlo agar ek stack ne poori n/2 space leli hai but ek ne sirf lets suppose bss n/4 hi space li hai toh in that case n/4 space waste hojaati! so this is not the optimal usage of space!

int main() {
    TwoStack s1(10); // using this we have created a common array for both the stack with memory space = 10.
    s1.Push1(1);
    s1.Push1(2);
    s1.Push1(3);
    s1.Push1(4);
    s1.Push1(5);
    s1.Push1(6); // Here these operations pushed 6 elements inside the array! means now for stack2 only 4 elements ke liye size bacha hai!

    s1.Push2(10);
    s1.Push2(20);
    s1.Push2(30);
    s1.Push2(40); // Here we have filled the entire array with 10 elements inside it!

    s1.Push1(10); // Here it will print Stack Overflow!
}