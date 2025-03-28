#include <iostream>

using namespace std;

int fib(int n);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    cout << fib(N) << "\n";
}

int fib(int n) {
    if (n <= 1) return n;
    return fib(n-1) + fib(n-2);
}