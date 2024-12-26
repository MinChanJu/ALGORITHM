#include <stdio.h>

int main() {
    int a,b,c;
    while (1) {
        scanf("%d %d %d", &a, &b, &c);
        if (a == 0 && b == 0 && c == 0) break;

        if(a > b && a > c && a >= b+c) printf("Invalid\n"); 
        else if(b > a && b > c && b >= a+c) printf("Invalid\n"); 
        else if(c > a && c > b && c >= a+b) printf("Invalid\n");
        else if (a == b && b == c) printf("Equilateral\n");
        else if (a == b || b == c || c == a) printf("Isosceles\n");
        else printf("Scalene\n");
    }
    
}