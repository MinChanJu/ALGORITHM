#include <stdio.h>

int main(void){
    int N;
    long min=1000000,max=-1000000;
    scanf("%d",&N);
    int ls[N];
    for(int i=0;i<N;i++){
        scanf("%d",&ls[i]);
    }
    for(int i=0;i<N;i++){
        if (ls[i] < min){
            min = ls[i];
        }
        if (ls[i] > max){
            max = ls[i];
        }
    }
    printf("%d %d",min,max);
    return 0;
}