#include <stdio.h>

void merge_sort(int array[], int s, int e);

int main() {
    int N;
    scanf("%d", &N);

    int array[N];
    for (int i = 0; i < N; i++) scanf("%d", &array[i]);

    merge_sort(array, 0, N-1);

    for (int i = 0; i < N; i++) printf("%d\n", array[i]);
}

void merge_sort(int array[], int s, int e) {
    if (s == e) return;

    int mid = (s+e)/2;
    merge_sort(array, s, mid);
    merge_sort(array, mid+1, e);

    int sub[e-s+1];
    int i = s, j = mid+1, k = 0;

    while (i <= mid && j <= e) {
        if (array[i] < array[j]) sub[k++] = array[i++];
        else sub[k++] = array[j++];
    }

    while (i <= mid) sub[k++] = array[i++];
    while (j <= e) sub[k++] = array[j++];

    for (int i = 0; i <= e-s; i++) array[i+s] = sub[i];
}