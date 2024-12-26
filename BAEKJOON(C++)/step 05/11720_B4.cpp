#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    string S;
    cin >> S;

    int sum = 0;
    for (int i = 0; i < N; i++) {
        sum += S[i]-48;
    }
    
    cout << sum << "\n";
}