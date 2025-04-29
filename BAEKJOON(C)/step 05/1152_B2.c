#include <stdio.h>
#include <string.h>

int main(void){
    int len,count=0;
    char S[1000000];
    scanf("%[^\n]",S);
    len = strlen(S);
    if (len==1 && S[0]==' '){
        printf("0");
        return 0;
    }
    for (int i=1;i<len-1;i++){
        if (S[i] == ' '){
            count++;
        }
    }
    printf("%d",count+1);
}