#include <stdio.h>

int isPrime(int n);

int main() {
    int M, N, sum=0, min=0;
    scanf("%d %d", &M, &N);
    for (int i=M; i < N+1; i++) {
        if (isPrime(i)) {
            if (min == 0) min = i;
            sum += i;
        }
    }
    if (min == 0) printf("-1\n");
    else printf("%d\n%d\n",sum,min);
}

int isPrime(int n) {
    if (n == 1) return 0;
    for (int i=2; i < n; i++) {
        if (n%i == 0) return 0;
    }
    return 1;
}