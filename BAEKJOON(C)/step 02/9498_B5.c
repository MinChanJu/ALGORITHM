#include <stdio.h>

int main(void){
    int A;
    scanf("%d",&A);
    if(A>=90){
        printf("A");
    }
    else if(A>=80){
        printf("B");
    }
    else if(A>=70){
        printf("C");
    }
    else if(A>=60){
        printf("D");
    }
    else{
        printf("F");
    }
}