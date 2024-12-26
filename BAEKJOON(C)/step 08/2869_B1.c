#include <stdio.h>

int main() {
    int A,B,V,cnt=1,day=1,cur = 0;
    scanf("%d %d %d", &A, &B, &V);
    printf("%d\n", (V-B-1)/(A-B)+1);
}