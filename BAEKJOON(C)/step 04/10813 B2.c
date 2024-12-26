#include <stdio.h>

int main(void){
    int N,M,a,b,tmp;
    scanf("%d %d",&N,&M);
    int ls[N];
    for(int i=0;i<N;i++){
        ls[i]=i+1;
    }
    for(int i=0;i<M;i++){
        scanf("%d %d",&a,&b);
        tmp = ls[a-1];
        ls[a-1] = ls[b-1];
        ls[b-1] = tmp;
    }
    for(int i=0;i<N;i++){
        printf("%d ",ls[i]);
    }
    return 0;
}