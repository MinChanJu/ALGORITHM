#include <stdio.h>

void insertion_sort(int array[], int size);

int main() {
    int N, k;
    scanf("%d %d", &N, &k);

    int num[N];
    for (int i = 0; i < N; i++) scanf("%d", &num[i]);

    insertion_sort(num, N);

    printf("%d\n", num[N-k]);
}

void insertion_sort(int array[], int size) {
    for (int i = 0; i < size; i++) {
        int min = i;
        for (int j = i+1; j < size; j++) {
            if (array[j] < array[min]) min = j;
        }
        int tmp = array[i];
        array[i] = array[min];
        array[min] = tmp;
    }
}