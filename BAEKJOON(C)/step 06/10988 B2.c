#include <stdio.h>
#include <string.h>

int main(void){
    int len,k=0;
    char S[100];
    scanf("%s",S);
    len = strlen(S);
    for (int i=0;i<len/2;i++){
        if (S[i] != S[len-i-1]){
            k = 1;
        }
    }
    if (k==0){
        printf("1");
    }
    else{
        printf("0");
    }
}