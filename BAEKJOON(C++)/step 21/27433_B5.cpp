#include <iostream>

using namespace std;

long fact(long n);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    cout << fact(N) << "\n";
}

long fact(long n) {
    if (n == 0) return 1;
    return n*fact(n-1);
}