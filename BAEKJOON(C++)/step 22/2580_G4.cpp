#include <iostream>
#include <sstream>

using namespace std;

inline int check(int a[][9], int u, int v);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    stringstream output;

    int A[9][9];
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cin >> A[i][j];
        }
    }

    bool flag = true;
    while(flag) {
        flag = false;
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (A[i][j] == 0) {
                    A[i][j] = check(A, i, j);
                    if (A[i][j] == 0) flag = true;
                }
            }
        }
    }

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            output << A[i][j] << " ";
        }
        output << "\n";
    }

    cout << output.str();
}

inline int check(int a[][9], int u, int v) {
    int cnt = 0, sum = 0;
    for (int i = 0; i < 9; i++) {
        if (a[i][v] != 0) {
            cnt += 1;
            sum += a[i][v];
        }
    }
    if (cnt == 8) return 45-sum;

    cnt = 0; sum = 0;
    for (int i = 0; i < 9; i++) {
        if (a[u][i] != 0) {
            cnt += 1;
            sum += a[u][i];
        }
    }
    if (cnt == 8) return 45-sum;

    cnt = 0; sum = 0;
    int o = u/3*3, p = v/3*3;
    for (int i = u/3*3; i < u/3*3+3; i++) {
        for (int j = v/3*3; j < v/3*3+3; j++) {
            if (a[i][j] != 0) {
                cnt += 1;
                sum += a[i][j];
            }
        }
    }
    if (cnt == 8) return 45-sum;

    return 0;
}