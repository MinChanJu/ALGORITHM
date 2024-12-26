#include <stdio.h>

int num[10000];

int main() {
    int N;
    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        int x;
        scanf("%d", &x);
        num[x-1]++;
    }

    for (int i = 0; i < 10000; i++) {
        while (num[i]) {
            printf("%d\n", i+1);
            num[i]--;
        }
    }
}