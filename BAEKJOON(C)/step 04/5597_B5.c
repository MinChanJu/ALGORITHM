#include <stdio.h>

int main(void){
    int A;
    int student[31] = {0};
    for (int i=0;i<28;i++){
        scanf("%d",&A);
        student[A]=1;
    }
    for (int i=1;i<=30;i++){
        if (student[i] == 0){
            printf("%d\n",i);
        }
    }
}