#include <stdio.h>

int main() {
    int x,y,w,h;
    scanf("%d %d %d %d", &x, &y, &w, &h);
    if (y < h-y) {
        if (x < w-x) {
            if (x < y) printf("%d\n", x);
            else printf("%d\n",y);
        } else {
            if (w-x < y) printf("%d\n", w-x);
            else printf("%d\n",y);
        }
    } else {
        if (x < w-x) {
            if (x < h-y) printf("%d\n", x);
            else printf("%d\n",h-y);
        } else {
            if (w-x < h-y) printf("%d\n", w-x);
            else printf("%d\n",h-y);
        }
    }
}