#include <stdio.h>

void sum(void);

int main(void){
    int T;
    scanf("%d",&T);
    for (int i=0;i<T;i++){
        sum();
    }
}

void sum(void){
    int A,B;
    scanf("%d %d",&A,&B);
    printf("%d\n",A+B);
}