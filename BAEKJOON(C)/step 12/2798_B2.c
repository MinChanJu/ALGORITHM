
int main() {
    int N, M;
    scanf("%d %d", &N, &M);

    int card[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &card[i]);
    }

    int max = 0;
    for (int i = 0; i < N; i++) {
        for (int j = i+1; j < N; j++) {
            for (int k = j+1; k < N; k++) {
                int num = card[i] + card[j] + card[k];
                if (num > max && num <= M) max = num;
            }
        }
    }
    
    printf("%d\n", max);
}