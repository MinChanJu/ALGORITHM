#include <stdio.h>

int count[2001];

int main() {
    int N;
    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        int x;
        scanf("%d", &x);
        count[x+1000] = 1;
    }

    for (int i = 0; i < 2001; i++) {
        if (count[i] == 1) printf("%d\n", i-1000);
    }
    
    return 0;
}