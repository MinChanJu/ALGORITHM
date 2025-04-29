#include <stdio.h>

int main(void){
    char A[5][15]={{0}};
    for (int i=0;i<5;i++){
        scanf("%s",&A[i]);
    }
    for (int i=0;i<15;i++){
        for (int j=0;j<5;j++){
            if (A[j][i] == 0) continue;
            else printf("%c",A[j][i]);
        }
    }
    return 0;
}