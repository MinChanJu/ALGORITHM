#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;
    int basket[N];

    for (int i = 0; i < N; i++) {
        basket[i] = 0;
    }

    for (int _ = 0; _ < M; _++) {
        int i, j, k;
        cin >> i >> j >> k;

        for (int p = i-1; p < j; p++) {
            basket[p] = k;
        }
    }
    
    for (int i = 0; i < N; i++) {
        cout << basket[i] << " ";
    }
    cout << "\n";
}