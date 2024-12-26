#include <stdio.h>
#include <stdlib.h>

int isPrime(int n);

int main() {
    int N, n, cnt = 0;
    scanf("%d", &N);
    for (int i=0; i < N; i++) {
        scanf("%d", &n);
        if (isPrime(n)) cnt++;
    }
    printf("%d\n", cnt);
}

int isPrime(int n) {
    if (n == 1) return 0;
    for (int i=2; i < n; i++) {
        if (n%i == 0) return 0;
    }
    return 1;
}