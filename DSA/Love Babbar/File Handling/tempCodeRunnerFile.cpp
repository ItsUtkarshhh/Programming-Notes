#include<iostream>
using namespace std;

int main() {
    FILE* fptr1;
    fptr1 = fopen("text10.txt","r");
    int n1,n2;
    if(fptr1 == NULL) {
        cout<<"Error in opening the file";
    }
    else {
        fscanf(fptr1,"%d%d",&n1,&n2);
        fclose(fptr1);
    }

    // int sum = n1 + n2;

    FILE* fptr2;
    fptr2 = fopen("text10.txt","w");
    if(fptr2 == NULL) {
        cout<<"Error in opening the file";
    }
    else {
        // fprintf(fptr2,"%d",sum);
        fprintf(fptr2,"%d",n1 + n2);
        fclose(fptr2);
    }
}