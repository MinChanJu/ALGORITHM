#include <stdio.h>
#include <stdlib.h>

void addPrime(int* prime, int* size, int value);
void perpectNum(int* prime, int size, int n);


int main() {
    int n;
    while (1) {
        int size = 0, sum = 0;
        int* prime = (int*)malloc(size*sizeof(int));
        scanf("%d", &n);
        if (n == -1) break;
        for (int i=1; i < n; i++) {
            if (n%i == 0) {
                addPrime(prime, &size, i);
                sum = sum + i;
            }
        }
        if (sum == n) perpectNum(prime, size, n);
        else printf("%d is NOT perfect.\n", n);
    }
}

void addPrime(int* prime, int* size, int value) {
    prime = (int*)realloc(prime,(*size+1)*sizeof(int));
    prime[*size] = value;
    (*size)++;
}

void perpectNum(int* prime, int size, int n) {
    printf("%d = %d", n, prime[0]);
    for (int i=1; i < size; i++) printf(" + %d", prime[i]);
    printf("\n");
}