#include <stdio.h>
#include <math.h>

int main() {
    int N, sub;
    int cur[3] = {4,1,4};
    scanf("%d", &N);
    for (int i=1; i < N+1; i++) {
        cur[0] = cur[0]+cur[1]+cur[2];
        cur[1] = cur[1]*4;
        sub = (int) pow(2,i);
        cur[2] = sub*(sub+1)*2;
    }
    printf("%d\n",cur[0]);
}