#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string S;
    cin >> S;

    int alpha[26];
    for (int i = 0; i < 26; i++) {
        alpha[i] = -1;
    }
    
    for (int i = 0; i < S.size(); i++) {
        if (alpha[S[i]-97] == -1) alpha[S[i]-97] = i;
    }
    
    for (int i = 0; i < 26; i++) {
        cout << alpha[i];
        if (i != 25) cout << " ";
    }
    
    cout << "\n";
}