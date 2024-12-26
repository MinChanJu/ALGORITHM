#include <stdio.h>

int main(void){
    int N,M,a,b,c;
    scanf("%d %d",&N,&M);
    int ls[N];
    for(int i=0;i<N;i++){
        ls[i]=0;
    }
    for(int i=0;i<M;i++){
        scanf("%d %d %d",&a,&b,&c);
        for (int j=a-1;j<b;j++){
            ls[j] = c;
        }
    }
    for(int i=0;i<N;i++){
        printf("%d ",ls[i]);
    }
    return 0;
}