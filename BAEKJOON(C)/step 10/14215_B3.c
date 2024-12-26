#include <stdio.h>

int main() {
    int a,b,c;
    scanf("%d %d %d", &a, &b, &c);
    if (a > b && a > c && a >= b+c) printf("%d\n", 2*(b+c)-1);
    else if (b > a && b > c && b >= a+c) printf("%d\n", 2*(a+c)-1);
    else if (c > a && c > b && c >= a+b) printf("%d\n", 2*(a+b)-1);
    else printf("%d\n", a+b+c);
}