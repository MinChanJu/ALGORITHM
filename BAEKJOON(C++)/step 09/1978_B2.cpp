#include <iostream>
#include <sstream>

using namespace std;

bool isPrime(int n);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    stringstream output;

    int N, x, cnt = 0;
    cin >> N;

    for (int _ = 0; _ < N; _++) {
        cin >> x;
        if (isPrime(x)) cnt++;
    }
    
    output << cnt << "\n";

    cout << output.str();
}

bool isPrime(int n) {
    if (n == 1) return false;
    for (int i = 2; i < n; i++) {
        if (n%i == 0) return false;
    }
    return true;
}