#include <iostream>

using namespace std;

void change(int arr[], int s, int e);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;

    int basket[N+1];
    for (int i = 0; i <= N; i++) {
        basket[i] = i;
    }
    
    for (int _ = 0; _ < M; _++) {
        int i, j;
        cin >> i >> j;
        change(basket, i, j);
    }
    
    for (int i = 1; i <= N; i++) {
        cout << basket[i] << " ";
    }
    cout << "\n";
}

void change(int arr[], int s, int e) {
    int mid = (e-s+1)/2;
    for (int i = 0; i < mid; i++) {
        int tmp = arr[s+i];
        arr[s+i] = arr[e-i];
        arr[e-i] = tmp;
    }
}