#include <iostream>
#include <cmath>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string S;
    int B;
    cin >> S >> B;

    int decimal = 0;
    for (int i = S.length()-1; i >= 0; i--) {
        int a;
        if (S[i] >= 65) a = S[i]-55;
        else a = S[i]-48;

        decimal += a*pow(B, S.length()-1-i);
    }
    cout << decimal << "\n";
}