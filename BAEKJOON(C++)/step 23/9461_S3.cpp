#include <iostream>
#include <sstream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    stringstream output;

    long dp[101];
    dp[1] = 1; dp[2] = 1; dp[3] = 1; dp[4] = 2; dp[5] = 2;
    for (int i = 6; i <= 100; i++) {
        dp[i] = dp[i-1]+dp[i-5];
    }
    
    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;
        output << dp[N] << "\n";
    }

    cout << output.str();
}