#include <stdio.h>

void insertion_sort(int array[], int size);

int main() {
    int num[5];
    for (int i = 0; i < 5; i++) scanf("%d", &num[i]);
    
    insertion_sort(num, 5);

    int sum = 0;
    for (int i = 0; i < 5; i++) sum += num[i];

    printf("%d\n%d\n", sum/5, num[2]);
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