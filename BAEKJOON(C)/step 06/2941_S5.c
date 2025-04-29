#include <stdio.h>

int main(void){
    int i=0,cnt=0;
    char S[101];
    scanf("%s",S);

    while (S[i]){
        if (S[i] == '=' || S[i] == '-'){
            ++i;
        }
        else if ((S[i] == 'n' || S[i] == 'l') && S[i+1] == 'j'){
            ++cnt;
            i += 2;
        }
        else if (S[i] == 'd' && S[i+1] == 'z' && S[i+2] == '='){
            ++cnt;
            i += 3;
        }
        else{
            ++cnt;
            ++i;
        }
    }
    printf("%d",cnt);
    return 0;
}