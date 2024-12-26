#include <stdio.h>

int main(void){
    int A,a,b,val=-1;
    for (int i=0;i<9;i++){
        for (int j=0;j<9;j++){
            scanf("%d",&A);
            if (A > val){
                val =A;
                a = i;
                b = j;
            }
        }
    }
    printf("%d\n",val);
    printf("%d %d",a+1,b+1);
}