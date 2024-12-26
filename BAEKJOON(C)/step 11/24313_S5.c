#include <stdio.h>

int main() {
    int a1, a0, c, n0;
    scanf("%d %d\n%d\n%d", &a1, &a0, &c, &n0);

    if (a1 <= c && a1*n0+a0 <= c*n0) printf("1\n");
    else printf("0\n");
}