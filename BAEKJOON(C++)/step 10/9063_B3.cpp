#include <iostream>
#include <sstream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    stringstream output;

    int N, minX = 10000, maxX = -10000, minY = 10000, maxY = -10000;
    cin >> N;
    for (int _ = 0; _ < N; _++) {
        int x, y;
        cin >> x >> y;

        if (x < minX) minX = x;
        if (x > maxX) maxX = x;
        if (y < minY) minY = y;
        if (y > maxY) maxY = y;
    }
    
    output << (maxX-minX)*(maxY-minY) << "\n";

    cout << output.str();
}