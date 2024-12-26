#include <stdio.h>

int main(void){
    int N,sum=0;
    scanf("%d",&N);
    char S[N];
    scanf("%s",&S);
    for (int i=0;i<N;i++){
        sum = sum + S[i]-48;
    }
    printf("%d",sum);
    return 0;
}