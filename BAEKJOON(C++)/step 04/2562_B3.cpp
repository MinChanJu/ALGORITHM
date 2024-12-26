#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int X, last;
    int max = 0;
    for (int i = 1; i < 10; i++) {
        cin >> X;
        if (X > max) {
            max = X;
            last = i;
        }
    }

    cout << max << "\n" << last << "\n";
}