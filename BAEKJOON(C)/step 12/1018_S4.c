#include <stdio.h>

int min(int a, int b) {
    return (a < b) ? a : b;
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

int main() {
    int N, M;
    scanf("%d %d", &N, &M);

    char board[N][M];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            scanf(" %c", &board[i][j]);
        }
    }

    int minVal = 64;

    for (int i = 0; i < N-7; i++) {
        for (int j = 0; j < M-7; j++) {
            int cnt = 0;
            for (int ci = i; ci < i+8; ci++) {
                for (int cj = j; cj < j+8; cj++) {
                    if (board[ci][cj] == 'B' && (ci+cj)%2 == 0) cnt++;
                    if (board[ci][cj] == 'W' && (ci+cj)%2 == 1) cnt++;
                }
            }
            minVal = min(minVal, min(cnt, 64-cnt));
        }
    }

    printf("%d\n", minVal);
}