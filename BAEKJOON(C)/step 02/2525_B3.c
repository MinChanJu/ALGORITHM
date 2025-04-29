#include <stdio.h>

int main(void){
    int H,M;
    int C;
    scanf("%d %d",&H,&M);
    scanf("%d",&C);
    M = M+C;
    while (M>=60){
        H = H+1;
        M = M-60;
        if (H>23){
            H = H-24;
        }
    }
    printf("%d %d",H,M);
}