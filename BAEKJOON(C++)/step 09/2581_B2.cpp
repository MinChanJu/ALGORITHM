#include <iostream>
#include <sstream>

using namespace std;

bool isPrime(int n);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    stringstream output;

    int M, N, min = -1, sum = 0;
    cin >> M >> N;

    for (int i = M; i <= N; i++) {
        if (isPrime(i)) {
            sum += i;
            if (min == -1) min = i;
        }
    }
    
    if (sum == 0) output << "-1\n";
    else output << sum << "\n" << min << "\n";

    cout << output.str();
}

bool isPrime(int n) {
    if (n == 1) return false;
    for (int i = 2; i < n; i++) {
        if (n%i == 0) return false;
    }
    return true;
}