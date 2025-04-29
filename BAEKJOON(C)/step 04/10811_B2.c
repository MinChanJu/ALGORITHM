#include <stdio.h>

int main(void){
    int N,M,A,B,tmp;
    scanf("%d %d",&N,&M);
    int basket[N];
    for (int i=0;i<N;i++){
        basket[i]=i+1;
    }
    for (int i=0;i<M;i++){
        scanf("%d %d",&A,&B);
        for (int j=A-1;j<=(B-A)/2+A-1;j++){
            tmp = basket[j];
            basket[j] = basket[B+A-j-2];
            basket[B+A-j-2] = tmp;
        }
    }
    for (int i=0;i<N;i++){
        printf("%d ",basket[i]);
    }
}