#include <stdio.h>

int main(void){
    int i;
    char sentence[1000]="";
    scanf("%s",&sentence);
    scanf("%d",&i);
    printf("%c",sentence[i-1]);
    return 0;
}