#include <stdio.h>

int main(void){
    int x,y;
    scanf("%d",&x);
    scanf("%d",&y);
    if(x<0){
        if (y<0){
            printf("3");
        }
        else{
            printf("2");
        }
    }
    else{
        if (y<0){
            printf("4");
        }
        else{
            printf("1");
        }
    }
}