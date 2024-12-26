#include <stdio.h>
#include <stdlib.h>

int* insert(int* array, int* size, int value);

int main() {
    int N, B;
    scanf("%d %d", &N, &B);
    int size = 1;
    int* array = (int*)malloc(size*sizeof(int));
    array[0] = -1;
    while (N != 0) {
        int num = N%B;
        array = insert(array, &size, num);
        N = N/B;
    }
    for (int i=0; i < size-1; i++) {
        if (array[i] >= 10) printf("%c", array[i]+55);
        else printf("%d", array[i]);
    }
    printf("\n");
}

int* insert(int* array, int* size, int value) {

    int* newArray = (int*)malloc((*size+1)*sizeof(int));
    newArray[0] = value;

    for (int i=0; i < *size; i++) {
        newArray[i+1] = array[i];
    }

    *size = *size + 1;

    free(array);

    return newArray;
}