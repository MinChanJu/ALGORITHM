#include <stdio.h>

int main(void){
    int A,B;
    double C;
    scanf("%d %d",&A,&B);
    C = (double)A/(double)B;
    printf("%21.20f",C);
}