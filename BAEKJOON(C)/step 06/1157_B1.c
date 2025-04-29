#include <stdio.h>
#include <string.h>

int main(void){
    int len,k=0,s=0;
    int alpha[26]={0};
    char S[1000000];
    scanf("%s",S);
    len = strlen(S);
    for (int i=0;i<len;i++){
        if (S[i]<95){
            alpha[S[i]-65]++;
        }
        else{
            alpha[S[i]-97]++;
        }
    }
    for (int i=1;i<26;i++){
        if (alpha[i] > alpha[k]){
            s = 0;
            k = i;
        }
        else if (alpha[i]==alpha[k]){
            s = 1;
        }
    }
    if (s==0){
        printf("%c",k+65);
    }
    else{
        printf("?");
    }
}