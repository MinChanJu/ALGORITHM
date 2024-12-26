#include <iostream>

using namespace std;

int main() {
    int H, M, C;
    cin >> H >> M >> C;
    M += C;
    if (M >= 60) {
        H += M/60;
        M %= 60;
    }

    if (H >= 24) H -= 24;

    cout << H << " " << M << endl;
}