#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

inline void dfs(int s);
inline bool checkRow(int r, int c, int num);
inline bool checkColumn(int r, int c, int num);
inline bool checkSquare(int r, int c, int num);

stringstream output;
vector<vector<int>> zero;
int sudoku[9][9];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cin >> sudoku[i][j];
            if (sudoku[i][j] == 0) zero.push_back({i,j});
        }
    }

    dfs(0);
}

inline void dfs(int s) {
    if (s == zero.size()) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                output << sudoku[i][j] << " ";
            }
            output << "\n";
        }
        cout << output.str();
        exit(0);
    }

    vector<int> row = zero[s];
    int r = row[0], c = row[1];

    for (int num = 1; num < 10; num++) {
        if (checkRow(r, c, num) && checkColumn(r, c, num) && checkSquare(r, c, num)){
            sudoku[r][c] = num;
            dfs(s+1);
            sudoku[r][c] = 0;
        }
    }
    
}

inline bool checkRow(int r, int c, int num) {
    for (int j = 0; j < 9; j++) {
        if (j == c) continue;
        if (sudoku[r][j] == num) return false;
    }
    return true;
}

inline bool checkColumn(int r, int c, int num) {
    for (int i = 0; i < 9; i++) {
        if (i == r) continue;
        if (sudoku[i][c] == num) return false;
    }
    return true;
}

inline bool checkSquare(int r, int c, int num) {
    int x = r/3*3, y = c/3*3;
    for (int i = x; i < x+3; i++) {
        for (int j = y; j < y+3; j++) {
            if (sudoku[i][j] == num) return false;
        }
    }
    return true;
}