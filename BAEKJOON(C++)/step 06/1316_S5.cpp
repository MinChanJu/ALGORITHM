#include <iostream>

using namespace std;

bool checkGroupWord(string word);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;

    int cnt = 0;

    for (int _ = 0; _ < T; _++) {
        string word;
        cin >> word;
        
        if(checkGroupWord(word)) cnt++;
    }
    
    cout << cnt << "\n";
}

bool checkGroupWord(string word) {
    int alpha[26] = {};
    int last = -1;
    for (int i = 0; i < word.length(); i++) {
        if (alpha[word[i]-97] == 0) {
            alpha[word[i]-97] = 1;
            last = word[i]-97;
        } else if (last != word[i]-97) return false;
    }
    return true;
}