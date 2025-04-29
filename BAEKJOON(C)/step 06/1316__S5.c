#include <stdio.h>
#include <string.h>

int main(void){
    int N,len,K,count = 0;
    scanf("%d",&N);
    char S[101]="";
    for (int i=0;i<N;i++){
        scanf("%s",S);
        len = strlen(S);
        int alpha[26]={0};
        K=0;
        for(int j=0;j<len;j++){
            if(alpha[S[j]-97]==0){
                K = S[j]-97;
                alpha[S[j]-97] = 1;
            }
            else{
                if(S[j]-97 != K){
                    count--;
                    break;
                }
            }
        }
        count++;
    }
    printf("%d",count);
    return 0;
}