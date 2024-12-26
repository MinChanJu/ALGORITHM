#include <stdio.h>
#include <stdlib.h>

int main() {
    int N;
    scanf("%d", &N);
    int minX = 10000, minY = 10000, maxX = -10000, maxY = -10000;
    int X,Y;
    for (int i=0; i<N; i++) {
        scanf("%d %d", &X, &Y);
        if (X < minX) minX = X;
        if (X > maxX) maxX = X;
        if (Y < minY) minY = Y;
        if (Y > maxY) maxY = Y;
    }
    printf("%d\n", (maxX-minX)*(maxY-minY));
}