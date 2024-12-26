#include <stdio.h>

int sub(void);

int main(void){
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++){
        sub();
        printf("\n");
    }
}

int sub(void){
    char sentence[1001];
    scanf("%s",&sentence);
    printf("%c",sentence[0]);
    for(int i=0;i<1001;i++){
        if (sentence[i]=='\0'){
            printf("%c", sentence[i-1]);
            return 0;
        }
    }
    return 0;
}