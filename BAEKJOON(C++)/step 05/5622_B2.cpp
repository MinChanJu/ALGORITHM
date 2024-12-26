#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string S;
    cin >> S;

    int time = 0;
    for (int i = 0; i < S.size(); i++) {
        if (65 <= S[i] && S[i] <= 67) time += 3;
        if (68 <= S[i] && S[i] <= 70) time += 4;
        if (71 <= S[i] && S[i] <= 73) time += 5;
        if (74 <= S[i] && S[i] <= 76) time += 6;
        if (77 <= S[i] && S[i] <= 79) time += 7;
        if (80 <= S[i] && S[i] <= 83) time += 8;
        if (84 <= S[i] && S[i] <= 86) time += 9;
        if (87 <= S[i] && S[i] <= 90) time += 10;
    }
    cout << time << "\n";
}