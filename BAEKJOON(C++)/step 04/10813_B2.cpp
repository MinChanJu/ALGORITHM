#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;
    int basket[N];

    for (int i = 0; i < N; i++) {
        basket[i] = i+1;
    }

    for (int _ = 0; _ < M; _++) {
        int i, j, tmp;
        cin >> i >> j;

        tmp = basket[i-1];
        basket[i-1] = basket[j-1];
        basket[j-1] = tmp;
    }

    for (int i = 0; i < N; i++) {
        cout << basket[i] << " ";
    }
    cout << "\n";
}