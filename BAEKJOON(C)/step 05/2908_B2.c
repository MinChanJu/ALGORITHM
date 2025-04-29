#include <stdio.h>

int main(void){
    int A,B,inA,inB;
    scanf("%d %d",&A,&B);
    inA = A/100 + ((A%100)/10)*10 + (A%10)*100;
    inB = B/100 + ((B%100)/10)*10 + (B%10)*100;
    if(inA > inB) printf("%d",inA);
    else printf("%d",inB);
}