#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string word;
    cin >> word;

    int alpha[26] = {};
    
    for (int i = 0; i < word.length(); i++) {
        if (word[i] >= 97) alpha[word[i]-97]++;
        else alpha[word[i]- 65]++;
    }
    
    int max = 0;
    bool isPos = true;
    
    for (int i = 1; i < 26; i++) {
        if (alpha[i] > alpha[max]) {
            max = i;
            isPos = true;
        } else if (alpha[i] == alpha[max]) {
            isPos = false;
        }
    }

    if (isPos) cout << (char) (max + 65) << "\n";
    else cout << "?\n";
    
}