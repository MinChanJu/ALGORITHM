#include <stdio.h>

int main() {
    int N, i = 6, sum = 1;
    scanf("%d", &N);

    while (sum < N) {
        sum = sum +i;
        i = i+6;
    }
    
    printf("%d\n", i/6);
}