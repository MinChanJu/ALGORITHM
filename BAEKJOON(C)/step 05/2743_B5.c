#include <stdio.h>

int main(void){
    char sentence[101];
    scanf("%s",&sentence);
    for(int i=0;i<101;i++){
        if (sentence[i]=='\0'){
            printf("%d", i);
            return 0;
        }
    }
    return 0;
}