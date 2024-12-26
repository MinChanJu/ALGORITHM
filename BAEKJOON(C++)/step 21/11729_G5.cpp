#include <iostream>
#include <sstream>

using namespace std;

void hanoi(int n, int a, int b, int c);

stringstream output;
int cnt = 0;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N;
    cin >> N;

    hanoi(N, 1, 2, 3);

    cout << cnt << "\n";
    cout << output.str();
}

void hanoi(int n, int a, int b, int c) {
    cnt++;
    if (n == 1) {
        output << a << " " << c << "\n";
        return;
    } else {
        hanoi(n-1, a, c, b);
        output << a << " " << c << "\n";
        hanoi(n-1, b, a, c);
    }
}