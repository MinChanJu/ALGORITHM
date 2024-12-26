#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N);
    while (N > 1) {
        for (int i=2; i < N+1; i++) {
            if (N%i == 0) {
                printf("%d\n",i);
                N /= i;
                break;
            }
        }
    }
}


// #include <stdio.h>
// #include <stdlib.h>

// int* addPrime(int* prime, int* size, int value);

// int main() {
//     int N, size = 0;
//     scanf("%d", &N);

//     int* number = (int*)malloc((N+1)*sizeof(int));
//     for (int i=0; i < N+1; i++) number[i] = 1;

//     int* prime = (int*)malloc(size*sizeof(int));
//     for (int i=2; i < N+1; i++) {
//         if (number[i]) {
//             prime = addPrime(prime, &size, i);
//             for (int j=2*i; j < N+1; j += i) {
//                 number[j] = 0;
//             }
//         }
//     }

//     int i = 0;
//     while (N != 1) {
//         if (N%prime[i] == 0) {
//             printf("%d\n",prime[i]);
//             N /= prime[i];
//         }
//         else i++;
//     }

//     free(number);
//     free(prime);

// }

// int* addPrime(int* prime, int* size, int value) {
//     int* temp = (int*)realloc(prime, (*size + 1) * sizeof(int));

//     if (temp == NULL) {
//         printf("메모리 재할당 실패!\n");
//         free(prime);  // 기존 메모리 해제
//         exit(1);  // 메모리 할당 실패 시 프로그램 종료
//     }

//     prime = temp;  // 성공 시 prime에 새 메모리 할당
//     prime[*size] = value;
//     (*size)++;

//     return prime;
// }