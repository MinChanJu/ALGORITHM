#include <stdio.h>

int main(void){
    int j,max=0;
    int ls[9];
    for(int i=0;i<9;i++){
        scanf("%d",&ls[i]);
    }
    for(int i=0;i<9;i++){
        if (ls[i] > max){
            max = ls[i];
            j=i;
        }
    }
    printf("%d\n%d",max,j+1);
    return 0;
}