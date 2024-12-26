#include <iostream>

using namespace std;

int main() {
    int X, N, a, b;
    cin >> X >> N;

    int sum = 0;
    for (int i = 0; i < N; i++) {
        cin >> a >> b;
        sum += a*b;
    }
    if (sum == X) cout << "Yes" << endl;
    else cout << "No" << endl;
}