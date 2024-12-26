#include <stdio.h>

int main() {
    int x[3][2] = {0};

    for (int i=0; i<3; i++) {
        scanf("%d %d", &x[i][0], &x[i][1]);
    }

    if (x[0][0] == x[1][0]) {
        if (x[0][1] == x[2][1]) printf("%d %d\n", x[2][0], x[1][1]);
        else if (x[1][1] == x[2][1]) printf("%d %d\n", x[2][0], x[0][1]);
    } else if (x[0][0] == x[2][0]) {
        if (x[0][1] == x[1][1]) printf("%d %d\n", x[1][0], x[2][1]);
        else if (x[2][1] == x[1][1]) printf("%d %d\n", x[1][0], x[0][1]);
    } else if (x[1][0] == x[2][0]) {
        if (x[1][1] == x[0][1]) printf("%d %d\n", x[0][0], x[2][1]);
        else if (x[2][1] == x[0][1]) printf("%d %d\n", x[0][0], x[1][1]);
    }
}