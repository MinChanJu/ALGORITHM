#include <stdio.h>

int main() {
    long n;
    scanf("%ld", &n);

    printf("%ld\n3\n", n*(n-1)*(n-2)/6);
}