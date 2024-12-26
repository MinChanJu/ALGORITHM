#include <stdio.h>

int main() {
    int X, i = 1,j = 1, k = 0;
    scanf("%d", &X);
    for (int p=1; p < X; p++) {
        if (i == 1 && j == 1) j++;
        else if (i == 1 && k == 1) {
            j++;
            k = 0;
        } else if (j == 1 && k == 0) {
            i++;
            k = 1;
        } else if (k == 0) {
            i++;
            j--;
        } else if (k == 1) {
            i--;
            j++;
        }
    }
    printf("%d/%d\n",i,j);
}