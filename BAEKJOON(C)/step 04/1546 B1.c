#include <stdio.h>

int main(void){
    int N,A,max=0;
    double average=0.0;
    scanf("%d",&N);
    double exam[N];
    for (int i=0;i<N;i++){
        scanf("%d",&A);
        exam[i]=A;
        if (A > max){
            max = A;
        }
    }
    for (int i=0;i<N;i++){
        exam[i] = exam[i]/max*100;
        average = average + exam[i];
    }
    printf("%lf",average/N);
}