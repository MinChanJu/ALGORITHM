#include <iostream>
#include <sstream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    stringstream output;

    int T;
    cin >> T;

    for (int i = 0; i < T; i++) {
        string S;
        cin >> S;
        output << S[0] << S[S.size()-1] << "\n";
    }

    cout << output.str();
}