#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N, X;
    cin >> N >> X;

    int A[N];
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    for (int i = 0;i < N;i++) {
        if (A[i] < X) cout << A[i] << " ";
    }
    cout << "\n";
}