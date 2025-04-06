#include <iostream>
#include <sstream>

using namespace std;

inline int W(int a, int b, int c);

int dp[101][101][101];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    stringstream output;

    while(true) {
        int a, b, c;
        cin >> a >> b >> c;
        if (a == -1 && b == -1 && c == -1) break;
        output << "w(" << a << ", " << b << ", " << c << ") = " << W(a, b, c) << "\n";
    }

    cout << output.str();
}

inline int W(int a, int b, int c) {
    int A = a+50, B = b+50, C = c+50;
    if (dp[A][B][C] != 0) return dp[A][B][C];

    if (a <= 0 || b <= 0 || c <= 0) dp[A][B][C] = 1;
    else if (a > 20 || b > 20 || c > 20) dp[A][B][C] = W(20, 20, 20);
    else if (a < b && b < c) dp[A][B][C] = W(a, b, c-1) + W(a, b-1, c-1) - W(a, b-1, c);
    else dp[A][B][C] = W(a-1, b, c) + W(a-1, b-1, c) + W(a-1, b, c-1) - W(a-1, b-1, c-1);

    return dp[A][B][C];
}