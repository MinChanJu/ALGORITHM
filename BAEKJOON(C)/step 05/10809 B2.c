#include <stdio.h>

int main(void){
    char S[101];
    scanf("%s",&S);
    int N[26]={0};
    for (int i=0;i<26;i++){
        N[i] = -1;
    }
    for (int i=0;i<101;i++){
        if (S[i] == '\0'){
            break;
        }
        if (N[S[i]-97] == -1){
            N[S[i]-97] = i;
        }
    }
    for (int i=0;i<26;i++){
        printf("%d ", N[i]);
    }
    return 0;
}