#include<iostream>
using namespace std;

int main() {
    int first = 6;
    int *p = &first;
    int *q = p; // aise pointers copy krte hai! p and q are pointing at the same memory location!
    (*q)++;
    cout<<first<<endl;

    cout<<endl;

    // int *p1 = 0; // NULL Pointer!
    // int first1 = 110;
    // *p1 = first1; // this is wrong, it will generate segmentation fault hence the correct syntax to do this will be p = &first, agar null pointer ko baad me update krke kisi aur jagah point karana hai toh vo aise krte hai! p = &first.. yahaa p ek NULL pointer tha!
    // cout<<*p1<<endl;

    cout<<endl;

    int arr1[5] = {11,12,13,14,15};
    cout<<*(arr1)<<" "<<*(arr1+1)<<endl; // Will print 11 and then 12
    
    cout<<endl;

    int arr2[5] = {11,12,13,14,15};
    cout<<arr2<<" "<<&(arr2)<<endl; // Same address do baar print hojayega!
    
    cout<<endl;

    // int arr3[5] = {11,12,13,14,15};
    // // int *ptr3 = arr++; // Here it will throw error kyunki here we are trying to update the symbol table!
    // cout<<*ptr3<<endl;
    
    cout<<endl;

    char arr4[] = "abcde"; // C/C++ me string ke case me compiler khud hi char array ka size samajh leta hai null character ki help se! aur yahaa humne double quotes use kiya hai jo strings ki notation hoti hai toh automatically ek null character last me lag jaata hai jahaa se size calculate hojaata hai!
    char* p3 = &arr4[0];
    cout<<(void*)arr4<<endl;
    cout<<p3<<endl; // Here we know char arrays ke case me cout behaves differently so yahaa poori string print hojayegi!
    
    cout<<endl;

    char arr5[] = "abcde";
    char* p4 = &arr5[0];
    p4++;
    cout<<p4<<endl; // Isme bcde print hojayega kyunki first index se humne increment krdiya hai!
}