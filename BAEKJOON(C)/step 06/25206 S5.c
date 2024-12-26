#include <stdio.h>

int main(void){
    double grade,ts=0,tg=0;
    char subject[51];
    char score[2];
    for (int i=0;i<20;i++){
        scanf("%s %lf %s",&subject,&grade,&score);
        tg += grade;
        if (score[0] == 'A' && score[1] == '+') ts += grade*4.5;
        else if(score[0] == 'A' && score[1] == '0') ts += grade*4.0;
        else if(score[0] == 'B' && score[1] == '+') ts += grade*3.5;
        else if(score[0] == 'B' && score[1] == '0') ts += grade*3.0;
        else if(score[0] == 'C' && score[1] == '+') ts += grade*2.5;
        else if(score[0] == 'C' && score[1] == '0') ts += grade*2.0;
        else if(score[0] == 'D' && score[1] == '+') ts += grade*1.5;
        else if(score[0] == 'D' && score[1] == '0') ts += grade*1.0;
        else if(score[0] == 'P') tg -= grade;
    }
    printf("%lf",ts/tg);
    return 0;
}