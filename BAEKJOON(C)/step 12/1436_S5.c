#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N);

    long n = 666, cnt = 0;
    while (1) {
        int i = 1;
        while (i*100 < n) {
            if (n%(i*1000)/i == 666) {
                cnt++;
                break;
            }
            i *= 10;
        }
        if (cnt == N) break;
        n++;
    }

    printf("%ld\n", n);
    return 0;
}