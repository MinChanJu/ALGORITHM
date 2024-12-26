#include <stdio.h>

int main(void){
    int A,count=0;
    int student[42] = {0};
    for (int i=0;i<10;i++){
        scanf("%d",&A);
        student[A%42]=1;
    }
    for (int i=0;i<=41;i++){
        if (student[i] == 1){
            count++;
        }
    }
    printf("%d",count);
}