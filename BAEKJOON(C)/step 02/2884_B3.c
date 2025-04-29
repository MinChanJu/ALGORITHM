#include <stdio.h>

int main(void){
    int H,M;
    scanf("%d %d",&H,&M);
    M = M-45;
    if(M<0){
        H = H-1;
        M = M+60;
        if (H<0){
            H = H+24;
        }
    }
    printf("%d %d",H,M);
}