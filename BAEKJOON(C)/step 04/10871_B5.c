#include <stdio.h>

int main(void){
    int N,X;
    scanf("%d %d",&N,&X);
    int ls[N];
    for(int i=0;i<N;i++){
        scanf("%d",&ls[i]);
    }
    for(int i=0;i<N;i++){
        if (ls[i] < X){
            printf("%d ",ls[i]);
        }
    }
    return 0;
}