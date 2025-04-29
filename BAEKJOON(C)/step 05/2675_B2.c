#include <stdio.h>

void sub(int R);

int main(void){
    int T,R;
    scanf("%d", &T);
    for(int i=0;i<T;i++){
        scanf("%d",&R);
        sub(R);
    }
}

void sub(int R){
    char S[20];
    scanf("%s",&S);
    for (int i=0;i<20;i++){
        if (S[i]=='\0'){
            break;
        }
        for (int j=0;j<R;j++){
            printf("%c",S[i]);
        }
    }
    printf("\n");
}