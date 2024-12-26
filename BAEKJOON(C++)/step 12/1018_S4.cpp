#include <iostream>
#include <sstream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    stringstream output;

    int N, M;
    cin >> N >> M;

    char board[N][M];

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            char ch;
            while ((ch = cin.get()) < 65);
            board[i][j] = ch;
        }
    }
    
    int MIN = 64;
    for (int i = 0; i < N-7; i++) {
        for (int j = 0; j < M-7; j++) {
            int B = 0, W = 0;
            for (int ci = i; ci < i+8; ci++) {
                for (int cj = j; cj < j+8; cj++) {
                    if ((ci+cj)%2 == 0 && board[ci][cj] == 'B') B++;
                    else if ((ci+cj)%2 == 1 && board[ci][cj] == 'W') W++;
                }
            }
            MIN = min(MIN, min(64-B-W, B+W));
        }
    }

    output << MIN << "\n";

    cout << output.str();
    
}