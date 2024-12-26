#include <stdio.h>
#include <string.h>

int main(void){
    int len,count=0;
    char S[30];
    scanf("%s",S);
    len = strlen(S);
    for (int i=0;i<len;i++){
        if (S[i]==83){
            count = count + 8;
        }
        else if (S[i]==84 || S[i]==85 || S[i]==86){
            count = count + 9;
        }
        else if (S[i]==87 || S[i]==88 || S[i]==89 || S[i]==90){
            count = count + 10;
        }
        else{
            count = count + ((S[i]-65)/3)+3;
        }
    }
    printf("%d",count);
}