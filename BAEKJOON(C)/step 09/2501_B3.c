#include <stdio.h>

int main() {
    int N, K, cnt = 0;
    scanf("%d %d", &N, &K);
    for (int i=1; i < N+1; i++) {
        if (N%i == 0) cnt++;
        if (cnt == K) {
            printf("%d\n",i);
            break;
        }
    }
    if (cnt < K) printf("0\n");
}