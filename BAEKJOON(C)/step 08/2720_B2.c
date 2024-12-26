#include <stdio.h>

int main() {
    int T, C;
    scanf("%d", &T);
    for (int i=0; i < T; i++) {
        scanf("%d", &C);
        printf("%d", C/25);
        C = C%25;
        printf(" %d", C/10);
        C = C%10;
        printf(" %d", C/5);
        C = C%5;
        printf(" %d\n", C);
    }
}