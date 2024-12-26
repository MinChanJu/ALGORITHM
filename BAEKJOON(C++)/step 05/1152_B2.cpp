#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string S;
    getline(cin, S);

    int cnt = 0;
    for (int i = 0; i < S.size(); i++) {
        if (S[i] == 32 && i != 0 && i != S.size()-1) cnt++;
    }
    
    if (S.size() == 1 && S[0] == 32) cout << "0\n";
    else cout << cnt+1 << "\n";
}