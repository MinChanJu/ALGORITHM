#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int A[100][100];
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            A[i][j] = 0;
        }
    }

    int T;
    cin >> T;

    for (int i = 0; i < T; i++) {
        int X, Y;
        cin >> X >> Y;

        for (int x = X; x < X+10; x++) {
            for (int y = Y; y < Y+10; y++) {
                A[x][y] = 1;
            }
        }
    }

    int sum = 0;
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            sum += A[i][j];
        }
    }

    cout << sum << "\n";
}