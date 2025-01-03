#include <iostream>
#include <sstream>

using namespace std;

inline int fib(int n);

int cnt = 1;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    stringstream output;

    int N;
    cin >> N;

    fib(N);
    output << cnt << " " << N-2 << "\n";
    
    cout << output.str();
}

inline int fib(int n) {
    if (n == 1 || n == 2) return 1;
    cnt++;
    return (fib(n - 1) + fib(n - 2));
}