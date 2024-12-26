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
        int R;
        string S;
        cin >> R >> S;

        for (int i = 0; i < S.size(); i++) {
            for (int _ = 0; _ < R; _++) {
                output << S[i];
            }
            
        }
        output << "\n";
    }

    cout << output.str();
}