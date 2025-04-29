#include <stdio.h>

int main(void){
    int N,v,count=0;
    scanf("%d",&N);
    int ls[N];
    for(int i=0;i<N;i++){
        scanf("%d",&ls[i]);
    }
    scanf("%d",&v);
    for(int i=0;i<N;i++){
        if (ls[i] == v){
            count++;
        }
    }
    printf("%d",count);
    return 0;
}