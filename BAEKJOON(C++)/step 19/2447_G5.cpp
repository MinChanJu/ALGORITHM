#include <iostream>
#include <sstream>

using namespace std;

void canto(char** star, int x1, int y1, int x2, int y2);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    stringstream output;

    int N;
    cin >> N;

    char ** star = new char*[N];
    for (int i = 0; i < N; i++) {
        star[i] = new char[N];
        for (int j = 0; j < N; j++) {
            star[i][j] = '*';
        }
    }

    canto(star, 0, 0, N-1, N-1);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            output << star[i][j];
        }
        output << "\n";
    }

    cout << output.str();
}

void canto(char** star, int x1, int y1, int x2, int y2) {
    if (x1 == x2 && y1 == y2) return;

    int dx = (x2-x1+1)/3, dy = (y2-y1+1)/3;
    for (int i = x1+dx; i < x1+dx+dx; i++) {
        for (int j = y1+dy; j < y1+dy+dy; j++) {
            star[i][j] = ' ';
        }
    }

    canto(star, x1, y1, x1+dx-1, y1+dy-1);
    canto(star, x1+dx, y1, x1+dx+dx-1, y1+dy-1);
    canto(star, x1+dx+dx, y1, x2, y1+dy-1);

    canto(star, x1, y1+dy, x1+dx-1, y1+dy+dy-1);
    canto(star, x1+dx+dx, y1+dy, x2, y1+dy+dy-1);

    canto(star, x1, y1+dy+dy, x1+dx-1, y2);
    canto(star, x1+dx, y1+dy+dy, x1+dx+dx-1, y2);
    canto(star, x1+dx+dx, y1+dy+dy, x2, y2);
}