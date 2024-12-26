#include <stdio.h>

int main(void){
    int a,b,c;
    int award;
    scanf("%d %d %d",&a,&b,&c);
    if (a==b && b==c && a==c){
        award = 10000+a*1000;
    }
    else if (a==b){
        award = 1000+a*100;
    }
    else if (c==b){
        award = 1000+b*100;
    }
    else if (a==c){
        award = 1000+a*100;
    }
    else{
        if (a>b && a>c){
            award = a*100;
        }
        else if (c>b && a<c){
            award = c*100;
        }
        else if (c<b && a<b){
            award = b*100;
        }
    }
    printf("%d",award);
}