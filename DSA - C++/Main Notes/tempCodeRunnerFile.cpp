#include<iostream>
using namespace std;

int lengthString(char input[]) {
    int count = 0;
    for(int i = 0; input[i]!='\0'; i++) {
        count++;
    }
    return count;
}

// First Method of reversing
char* reverse(char* input) { // Here we have used a * over the char keyword! kyunki bina star ki agar iss function ko create krenge toh ye ek single character return krega sirf but hum chahte hai ki ye ek string return kre and in that case we need to make the data type of the function also a character array! and that's why we have used the *. integer me bhi ye dikkat aa sakti thi pr usme hum pehle se hi size input lete the, pr iss function me humne size input nhi liya hai toh that's why hume kuch toh btaana padega ki isko ek character array return krna hai, toh yaa toh hum star lgaye yaa toh hum isko input me isko size dede!
    int i = 0, j = lengthString(input)-1;
    while(i<=j) {
        swap(input[i], input[j]);
        i++;
        j--;
    }
    return input;
}

// Second method of reversing
void reverse2(char input[], int n) {
    int i = 0, j = n-1;
    while(i<=j) {
        swap(input[i], input[j]);
        i++;
        j--;
    }
}

int main() {
    // From first method through reverse function
    char input[50];
    cin>>input;
    cout<<"Reversed character array is : "<<reverse(input);
    cout<<endl;

    // From second method through reverse2 function
    char input2[50];
    cin>>input2;
    reverse2(input2, lengthString(input2)); // Yaa toh length function ki value kisi variable me store kraa ke input me dedo function ke yaa toh directly baat ek hi hai!
    cout<<"Reversed character array is : "<<input2;
}